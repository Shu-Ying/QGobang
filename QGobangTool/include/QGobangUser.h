#ifndef QGOBANGUSER_H
#define QGOBANGUSER_H

#include <QString>

namespace NS_QGobangTool
{

struct UserInfo
{
    int         iUid;
    QString     sName;
    QString     sPassword;
    int         iLevel;
};

}

#endif // QGOBANGUSER_H
