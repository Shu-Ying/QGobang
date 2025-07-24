#include "CHttpService.h"

#include <QDir>
#include <QFile>
#include <QApplication>

#include <QJsonObject>
#include <QJsonDocument>

#include "CDBManager.h"
#include "QGobangUser.h"

using namespace NS_QGobangTool;
using namespace NS_QGobangServer;

CHttpService::CHttpService(QObject *parent)
    : QObject(parent)
{
    m_pTcpServer = new QTcpServer(this);

    initService();

    m_bIsStrat = false;
}

// 停止Service
bool CHttpService::stop()
{
    for(auto &&tcpServer : m_pServer.servers())
    {
        if(tcpServer->isListening())
        {
            tcpServer->close();
        }
    }

    m_bIsStrat = false;

    return false;
}

// 监听
bool CHttpService::listen(const QHostAddress &address, quint16 port)
{
    if(!m_pTcpServer->listen(address, port))
        return false;

    if(!m_pServer.bind(m_pTcpServer))
        return false;

    m_bIsStrat = true;

    return true;
}

void CHttpService::initService()
{
    m_pServer.route("/", QHttpServerRequest::Method::Get, [this](const QHttpServerRequest &req)
                    {
                        return QHttpServerResponse("{\"info\":\"Hello QGobang Service\"}");
                    });

    m_pServer.route("/register", QHttpServerRequest::Method::Post,
                    [this](const QHttpServerRequest &req)
                    {
                        return this->registerUser(req);
                    });

    m_pServer.route("/login", QHttpServerRequest::Method::Post,
                    [this](const QHttpServerRequest &req)
                    {
                        return this->registerUser(req);
                    });
}

// 注册用户
QHttpServerResponse CHttpService::registerUser(const QHttpServerRequest &req)
{
    auto body = req.body();

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(body, &err);
    if(err.error != QJsonParseError::NoError || !doc.isObject())
        return QHttpServerResponse{QHttpServerResponse::StatusCode::BadRequest};

    QString name = doc.object().value("name").toString();
    QString password = doc.object().value("password").toString();

    int status = CDBManager::getInstance()->addUserInfo(name, password);

    QJsonObject json;
    json["code"] = status;

    return QHttpServerResponse(json);
}

// 登录
QHttpServerResponse CHttpService::login(const QHttpServerRequest &req)
{
    auto body = req.body();

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(body, &err);
    if(err.error != QJsonParseError::NoError || !doc.isObject())
        return QHttpServerResponse{QHttpServerResponse::StatusCode::BadRequest};

    QString name = doc.object().value("name").toString();
    QString password = doc.object().value("password").toString();

    UserInfo info;
    QJsonObject json;
    int status = CDBManager::getInstance()->getUserInfoByName(name, info);

    if(status != 1 || info.sPassword != password)
    {
        json["code"] = 0;
    }
    else
    {
        json["code"] = 1;
        json["uid"] = info.iUid;
        json["name"] = info.sName;
        json["level"] = info.iLevel;
    }

    return QHttpServerResponse(json);
}
