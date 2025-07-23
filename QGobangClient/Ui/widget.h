#ifndef WIDGET_H
#define WIDGET_H

/***************************************************************
 * @file        Widget.h
 * @author      Art_Sakura
 * @date        2025-07-24
 * @brief       该Ui为示例类, 后续会删除
 ***************************************************************/

#include <QWidget>

// 记得加命名空间 添加命名空间后 UI文件也得加
// 你也可以将UI的命名空间声明到外面, 这样就可以不用加命名空间了, 当然不推荐
namespace NS_QGobangClient
{

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
};

}
#endif // WIDGET_H
