#include "CUiManager.h"

#include "QGobangRule.h"

#include "Ui/widget.h"

using namespace NS_QGobangClient;

CUiManager* CUiManager::m_pInstance = nullptr;

CUiManager *CUiManager::getInstance()
{
    if(m_pInstance == nullptr)
    {
        m_pInstance = new CUiManager();
    }

    return m_pInstance;
}

Widget *CUiManager::getWidget()
{
    if(m_pWidget == nullptr)
    {
        m_pWidget = new Widget();
    }

    return m_pWidget;
}

CUiManager::CUiManager()
{
    //记得初始化成nullptr
    m_pWidget = nullptr;
}
