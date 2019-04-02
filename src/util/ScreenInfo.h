#ifndef SCREENINFO_H
#define SCREENINFO_H

#include <QWidget>

class ScreenInfo
{
public:
    static void initScreenInfo(int nBaseWidth = 800, int nBaseHeight = 600);
    static int width();
    static int height();
    static float screenRate();
    static float widthRate();
    static float heightRate();
    static void resetGrid(QWidget *widget);

private:
    static int m_nScreenWidth; // 屏幕宽度
    static int m_nScreenHeight; // 屏幕高度
    static float m_fWidthRate; // 宽度比率
    static float m_fHeightRate; // 高度比率
    static float m_fScreenRate; // 屏幕宽高比率 如16/9
};

#endif // SCREENINFO_H
