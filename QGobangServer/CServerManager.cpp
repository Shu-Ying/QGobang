#include "CServerManager.h"

using namespace NS_QGobangServer;

CServerManager* CServerManager::m_pInstance = nullptr;

CServerManager *CServerManager::getInstance()
{
    if(m_pInstance == nullptr)
    {
        m_pInstance = new CServerManager();
    }

    return m_pInstance;
}

CServerManager::CServerManager()
{

}
