#include <QCoreApplication>

#include "CDBManager.h"
#include "CHttpService.h"
#include "CServerManager.h"

using namespace NS_QGobangServer;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 1.初始数据库
    auto db = CDBManager::getInstance();
    db->initDB();

    // 2.初始化HttpServer
    auto httpService = CServerManager::getInstance()->getHttpService();

    // 3.监听指定端口
    if(!httpService->status())
    {
        if(!httpService->listen(QHostAddress::Any, 3221))
        {
            qFatal("无法在端口3221上监听");
        }
        else
        {
            qInfo() << "http服务运行在 http://localhost:3221/";
        }
    }

    return a.exec();
}
