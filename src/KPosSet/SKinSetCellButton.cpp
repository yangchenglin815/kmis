#include "SKinSetCellButton.h"
#include "../data/enumData.h"
#include "../util/GlobalSignal.h"
#include <QPainter>

SKinSetCellButton::SKinSetCellButton(QWidget *parent)
    : QPushButton(parent)
    , m_bSelected(false)
    , m_nSkinType(0)
    , m_sSkinPath(":/kPosSetImage/blackSkin.png")
{

}

void SKinSetCellButton::setSkinType(int nSkinType)
{
    if (nSkinType == e_blackSkin)
    {
        m_sSkinPath = ":/kPosSetImage/blackSkin.png";
    }
    else if (nSkinType == e_flatSkin)
    {
        m_sSkinPath = ":/kPosSetImage/flatSkin.png";
    }
    else if (nSkinType == e_smartSkin)
    {
        m_sSkinPath = ":/kPosSetImage/smartSkin.png";
    }
    else
    {
        m_sSkinPath = ":/kPosSetImage/blackSkin.png";
    }
}

void SKinSetCellButton::setSelectedState(bool bSelected)
{
    m_bSelected = bSelected;
    update();
}

void SKinSetCellButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);
    QPainter painter(this);
    int nWidth = this->width();
    int nHeight = this->height();
    QRect rect(0, 0, nWidth, nHeight);

    if (m_bSelected)
    {
        // 边框
        QPixmap outRectPixmap(":/kPosSetImage/outRect.png");
        outRectPixmap = outRectPixmap.scaled(nWidth, nHeight);
        painter.drawPixmap(rect, outRectPixmap);
        // 皮肤
        QPixmap skinPixmap(m_sSkinPath);
        skinPixmap = skinPixmap.scaled(nWidth, nHeight);
        painter.drawPixmap(rect, skinPixmap);
        // 勾选
        int nSelectedSideLen = 24; // 边长
        QPixmap selectedPixmap(":/kPosSetImage/selected.png");
        QRect selectedRect(6, nHeight - nSelectedSideLen - 6, nSelectedSideLen, nSelectedSideLen);
        painter.drawPixmap(selectedRect, selectedPixmap);
    }
    else
    {
        // 皮肤
        QPixmap skinPixmap(m_sSkinPath);
        skinPixmap = skinPixmap.scaled(nWidth, nHeight);
        painter.drawPixmap(rect, skinPixmap);
        // 蒙层
        QPixmap coveragePixmap(":/kPosSetImage/coverage.png");
        coveragePixmap =  coveragePixmap.scaled(nWidth, nHeight);
        painter.drawPixmap(rect, coveragePixmap);
    }
}
