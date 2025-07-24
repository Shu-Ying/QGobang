#include "CServerManager.h"

#include "CHttpService.h"

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

CHttpService *CServerManager::getHttpService()
{
    if(m_pHttpService == nullptr)
    {
        m_pHttpService = new CHttpService();
    }

    return m_pHttpService;
}

CServerManager::CServerManager()
{
    m_pHttpService = nullptr;
}
