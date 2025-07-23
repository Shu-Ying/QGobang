#ifndef CSERVERMANAGER_H
#define CSERVERMANAGER_H

/***************************************************************
 * @file        CServerManager.h
 * @author      Art_Sakura
 * @date        2025-07-24
 * @brief       项目由单例设计模式控制, 该类是控制全部服务端父类的单例类
 *              所有父类都应创建声明在此处, 方便统一管理
 ***************************************************************/

namespace NS_QGobangServer
{

class CServerManager
{
public:
    static CServerManager *getInstance();

private:
    CServerManager();

private:
    static CServerManager  *m_pInstance;

};

}

#endif // CSERVERMANAGER_H
