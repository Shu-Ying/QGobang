#include <QApplication>

#include <QDebug>

#include "Ui/widget.h"
#include "CUiManager.h"

using namespace NS_QGobangClient;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 单例设计模式下, 引用比较过长, 长远的来看, 利大于弊
    Widget *w = CUiManager::getInstance()->getWidget();
    w->show();

    return a.exec();
}
