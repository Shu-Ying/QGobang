#ifndef CDBMANAGER_H
#define CDBMANAGER_H

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

#include "QGobangUser.h"

using namespace NS_QGobangTool;

namespace NS_QGobangServer
{

class CDBManager
{
public:
    static CDBManager *getInstance();

    /**
     * @brief isUserExist       判断用户是否存在
     * @param name              用户名
     * @return                  -1: 异常 0: 不存在 1: 存在
     */
    int isUserExist(const QString &name);

    /**
     * @brief addUserInfo       添加用户
     * @param name              用户名
     * @param pass              用户密码
     * @return                  -1: 异常 0: 用户已存在 1: 注册成功
     */
    int addUserInfo(const QString &name, const QString &pass);

    /**
     * @brief getUserInfoByName 获取用户信息
     * @param name              用户名
     * @param info
     * @return                  -1: 数据库未打开 0: 用户不存在 1: 获取成功
     */
    int getUserInfoByName(const QString &name, UserInfo &info);

    bool initDB();

    // 获取数据库路径
    inline QString getDBPath()
    { return m_sDBPath; }

private:
    CDBManager();

    // 创建DB文件
    bool createDBFile();

private:
    QString             m_sDBPath;              //数据库路径

    QSqlDatabase        m_pDB;                  //数据库


    static CDBManager   *m_pInstance;
};

}

#endif // CDBMANAGER_H
