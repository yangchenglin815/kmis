#include "ScreenInfo.h"
#include "constData.h"
#include <QApplication>
#include <QDesktopWidget>

int ScreenInfo::m_nScreenWidth = 800; // 屏幕宽度
int ScreenInfo::m_nScreenHeight = 600; // 屏幕高度
float ScreenInfo::m_fWidthRate = 1.0f; // 宽度比率
float ScreenInfo::m_fHeightRate = 1.0f; // 高度比率
float ScreenInfo::m_fScreenRate = 1.33f; // 高度比率

void ScreenInfo::initScreenInfo(int nBaseWidth, int nBaseHeight)
{
    //    m_nScreenWidth = 1920;
    //    m_nScreenHeight = 1080;
//    m_nScreenWidth = 1280;
//    m_nScreenHeight = 720;
//    m_nScreenWidth = 1024;
//    m_nScreenHeight = 768;
    m_fWidthRate = m_nScreenWidth * 1.0f / nBaseWidth;
    m_fHeightRate = m_nScreenHeight * 1.0f / nBaseHeight;
    m_fScreenRate=m_nScreenWidth/m_nScreenHeight;
    if(m_fScreenRate>1.5)
    {
        isQHD=true;
    }else
        isQHD=false;

}

int ScreenInfo::width()
{
    return m_nScreenWidth;
}

int ScreenInfo::height()
{
    return m_nScreenHeight;
}

float ScreenInfo::screenRate()
{
    return m_fScreenRate;
}

float ScreenInfo::widthRate()
{
    return m_fWidthRate;
}

float ScreenInfo::heightRate()
{
    return m_fHeightRate;
}

void ScreenInfo::resetGrid(QWidget *widget)
{
    int widgetX = widget->x();
    int widgetY = widget->y();
    int widgetWid = widget->width();
    int widgetHei = widget->height();
    int nWidgetX = (int)(widgetX*m_fWidthRate);
    int nWidgetY = (int)(widgetY*m_fHeightRate);
    int nWidgetWid = (int)(widgetWid*m_fWidthRate);
     int nWidgetHei = (int)(widgetHei*m_fHeightRate);
   widget->setGeometry(nWidgetX,nWidgetY,nWidgetWid,nWidgetHei);
}

