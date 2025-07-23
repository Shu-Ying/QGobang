#ifndef QGOBANGRULE_H
#define QGOBANGRULE_H

/***************************************************************
 * @file        QGobangRule.h
 * @author      Art_Sakura
 * @date        2025-07-24
 * @brief       五子棋规则
 *              落子和胜利判读放置此处, 方便客户端和服务端调用
 ***************************************************************/

namespace NS_QGobangTool
{

class QGobangRule
{
public:
    QGobangRule();

    /**
     * @brief gameCheckWincheckWin  游戏胜利条件判断 每次落子后都应该调用该函数
     * @param player                用户uid
     * @param x                     X
     * @param y                     Y
     * @param board                 当前棋盘场景 其中 0:表示没有落子 1:表示黑子 2:表示白子
     * @return                      是否胜利
     */
    bool gameCheckWincheckWin(int player, int x, int y, const int board[15][15]);
};

}

#endif // QGOBANGRULE_H
