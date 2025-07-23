#ifndef CUIMANAGER_H
#define CUIMANAGER_H

/***************************************************************
 * @file        CUiManager.h
 * @author      Art_Sakura
 * @date        2025-07-24
 * @brief       项目由单例设计模式控制, 该类是控制全部Ui单例类
 *              所有父类Ui都应创建声明在此处, 方便统一管理
 ***************************************************************/

namespace NS_QGobangClient
{

/*  应使用头文件声明 cpp引用方法
    防止相互包含 */
class Widget;
class CUiManager
{

public:
    static CUiManager  *getInstance();

    Widget *getWidget();

private:
    CUiManager();

private:
    static CUiManager  *m_pInstance;

    //示例
    Widget      *m_pWidget;
};

}

#endif // CUIMANAGER_H
