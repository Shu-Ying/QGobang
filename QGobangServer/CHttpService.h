#ifndef CHTTPSERVICE_H
#define CHTTPSERVICE_H

#include <QTcpServer>
#include <QStringList>

#include <QHttpServer>
#include <QHttpServerRequest>
#include <QHttpServerResponse>

namespace NS_QGobangServer
{

class CHttpService : QObject
{
    Q_OBJECT

public:
    explicit CHttpService(QObject *parent = nullptr);

    /**
     * @brief status        获取Service状态
     * @return
     */
    inline bool status()
    { return m_bIsStrat; }

    /**
     * @brief stop          停止Service
     * @return
     */
    bool stop();

    /**
     * @brief listen        监听
     * @param address       IP
     * @param port          端口号
     * @return
     */
    bool listen(const QHostAddress &address, quint16 port);

private:
    void initService();

    // 注册用户
    QHttpServerResponse registerUser(const QHttpServerRequest &req);

    // 登录
    QHttpServerResponse login(const QHttpServerRequest &req);

private:
    QHttpServer                 m_pServer;          //Http服务
    QTcpServer                  *m_pTcpServer;      //Tcp服务

    bool                        m_bIsStrat;         //运行状态
};

}

#endif // CHTTPSERVICE_H
