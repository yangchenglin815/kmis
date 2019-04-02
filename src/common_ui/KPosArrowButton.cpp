#include "KPosArrowButton.h"
#include <QPainter>

KPosArrowButton::KPosArrowButton(QWidget *parent)
    : QWidget(parent)
    , m_nArrowWidth(26)
    , m_nArrowHeight(18)
    , m_sArrowPath(":/pic/btn-down-nomal.png")
    , m_sArrowNormalPath(":/pic/btn-down-nomal.png") // 正常
    , m_sArrowPressedPath(":/pic/btn-down-pess.png") // 点击
    , m_sArrowDisablePath(":/pic/btn-down-disabled.png") // 不可用
    , m_sArrowText("2/3ye")
    , m_bEnAble(true)
{

}

void KPosArrowButton::initArrowPath(QString sArrowNormalPath, QString sArrowPressedPath, QString sArrowDisablePath)
{
    if (sArrowPressedPath.isEmpty())
    {
        sArrowPressedPath = sArrowNormalPath;
    }
    if (sArrowDisablePath.isEmpty())
    {
        sArrowDisablePath = sArrowNormalPath;
    }
    m_sArrowNormalPath = sArrowNormalPath;
    m_sArrowPressedPath = sArrowPressedPath;
    m_sArrowDisablePath = sArrowDisablePath;
    setArrowPath(m_sArrowNormalPath);
}

void KPosArrowButton::setArrowPath(QString sArrowPath)
{
    m_sArrowPath = sArrowPath;
    update();
}

void KPosArrowButton::setArrowText(QString sArrowText)
{
    m_sArrowText = sArrowText;
    update();
}

void KPosArrowButton::setArrowDisable()
{
    m_bEnAble = false;
    setArrowPath(m_sArrowDisablePath);
}

void KPosArrowButton::setArrowEnable()
{
    m_bEnAble = true;
    setArrowPath(m_sArrowNormalPath);
}

void KPosArrowButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    int nWidth = this->width();
    int nHeight = this->height();
    int nXPos = (nWidth - m_nArrowWidth) / 2;
    int nYPos = (nHeight - m_nArrowHeight) / 2;
    QPixmap selectedPixmap(m_sArrowPath);
    selectedPixmap = selectedPixmap.scaled(m_nArrowWidth, m_nArrowHeight);
    QRect selectedRect(nXPos, nYPos, m_nArrowWidth, m_nArrowHeight);
    painter.drawPixmap(selectedRect, selectedPixmap);

    if (!m_sArrowText.isEmpty())
    {
        QPen pen;
        pen.setColor("#999999");
        QFont font;
        font.setPixelSize(10);
        font.setFamily(QStringLiteral("微软雅黑"));
        painter.setPen(pen);
        painter.setFont(font);
        int nOffY = 3;
        QRect textRect(0, nOffY, nWidth, nHeight);
        painter.drawText(textRect, Qt::AlignRight | Qt::AlignVCenter, m_sArrowText);
    }
}

void KPosArrowButton::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    if (m_bEnAble)
    {
        setArrowPath(m_sArrowPressedPath);
        emit sigClick();
    }
    else
    {
        setArrowPath(m_sArrowDisablePath);
    }
}

void KPosArrowButton::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    if (m_bEnAble)
    {
        setArrowPath(m_sArrowNormalPath);
    }
}

KPosUpArrowButton::KPosUpArrowButton(QWidget *parent)
    : KPosArrowButton(parent)
{
    initArrowPath(":/saleImage/btn-up-nomal.png",
                  ":/saleImage/btn-up-pess.png",
                  ":/saleImage/btn-up-disable.png");
    setArrowText("");
}

KPosDownArrowButton::KPosDownArrowButton(QWidget *parent)
    : KPosArrowButton(parent)
{
    initArrowPath(":/saleImage/btn-down-nomal.png",
                  ":/saleImage/btn-down-pess.png",
                  ":/saleImage/btn-down-disabled.png");
    setArrowText(QStringLiteral("12/12页"));
}
