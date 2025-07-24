#include "CDBManager.h"

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QApplication>

using namespace NS_QGobangServer;
using namespace Qt::Literals::StringLiterals;

CDBManager* CDBManager::m_pInstance = nullptr;

CDBManager *CDBManager::getInstance()
{
    if(m_pInstance == nullptr)
    {
        m_pInstance = new CDBManager();
    }

    return m_pInstance;
}

// 判断用户是否存在
int CDBManager::isUserExist(const QString &name)
{
    QSqlQuery query;
    query.prepare(u"SELECT 1 FROM users WHERE name = :name LIMIT 1"_s);
    query.bindValue(":name", name);

    if(!query.exec())
    {
        qWarning() << "检查用户名是否存在时执行 SQL 出错：" << query.lastError().text();
        return -1;
    }

    if(query.next())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 添加用户
int CDBManager::addUserInfo(const QString &name, const QString &pass)
{
    if(!m_pDB.isOpen())
    {
        qWarning() << "数据库未打开！";
        return -1;
    }

    if(!m_pDB.transaction())
    {
        qWarning() << "开启事务失败：" << m_pDB.lastError().text();
        return -1;
    }

    // 1.检查用户名是否已存在
    auto exist = this->isUserExist(name);
    if(exist != 0)
    {
        return 0;
    }

    // 2.插入新用户
    QSqlQuery insert(m_pDB);
    insert.prepare(uR"(
        INSERT INTO users (name, password)
        VALUES (:name, :password)
    )"_s);
    insert.bindValue(u":name"_s,     name);
    insert.bindValue(u":password"_s, pass);

    if(!insert.exec())
    {
        qWarning() << "插入用户失败：" << insert.lastError().text();
        m_pDB.rollback();
        return -1;
    }

    if(!m_pDB.commit())
    {
        qWarning() << "执行SQL失败：" << m_pDB.lastError().text();
        return -1;
    }

    qDebug() << "成功添加用户：" << name;
    return 1;
}

// 获取用户信息
int CDBManager::getUserInfoByName(const QString &name, UserInfo &info)
{
    if(!m_pDB.isOpen())
    {
        qWarning() << "数据库未打开！";
        return -1;
    }

    QSqlQuery query(m_pDB);

    // 1.查询用户信息
    query.prepare(uR"(
        SELECT uid, name, password, level
        FROM users
        WHERE name = :name
        LIMIT 1
    )"_s);
    query.bindValue(u":name"_s, name);

    if(!query.exec())
    {
        qWarning() << "查询用户失败：" << query.lastError().text();
        return 0;
    }
    if(!query.next())
    {
        return 0;
    }

    // 2.取出字段
    info.iUid      = query.value(u"uid"_s).toInt();
    info.sName     = query.value(u"name"_s).toString();
    info.sPassword = query.value(u"password"_s).toString();
    info.iLevel    = query.value(u"level"_s).toInt();

    return 1;
}

bool CDBManager::initDB()
{
    this->createDBFile();

    qInfo() << "数据库初始化完成，文件路径：" << m_sDBPath;

    return true;
}

CDBManager::CDBManager()
{
    m_sDBPath = QCoreApplication::applicationDirPath() + "/data/users.db";
}

// 创建DB文件
bool CDBManager::createDBFile()
{
    // 1.判断文件夹是否存在 不存在则创建
    QFileInfo fi(m_sDBPath);
    QDir dir = fi.dir();
    if(!dir.exists())
    {
        if(!dir.mkpath("."))
        {
            qFatal("无法创建目录 %s", qPrintable(dir.absolutePath()));
            return false;
        }
    }

    // 2.判断文件是否存在 不存在则创建
    if(!QFile::exists(m_sDBPath))
    {
        QFile file(m_sDBPath);
        if(!file.open(QIODevice::WriteOnly))
        {
            qFatal("无法创建数据库文件 %s", qPrintable(m_sDBPath));
            return false;
        }
        file.close();
    }

    // 3.向Qt数据库连接池注册连接
    m_pDB = QSqlDatabase::addDatabase("QSQLITE");
    m_pDB.setDatabaseName(m_sDBPath);
    if(!m_pDB.open())
    {
        qFatal("打开数据库失败：%s", qPrintable(m_pDB.lastError().text()));
        return false;
    }

    // 4.初始化表字段
    QSqlQuery query;
    if(!query.exec(R"(
            CREATE TABLE if NOT EXISTS users (
                uid INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT UNIQUE NOT NULL,
                password TEXT NOT NULL,
                level INTEGER NOT NULL DEFAULT 1
            )
        )"))
    {
        qFatal("创建表失败：%s", qPrintable(query.lastError().text()));
        return false;
    }

    return true;
}
