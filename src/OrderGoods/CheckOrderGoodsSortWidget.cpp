#include "CheckOrderGoodsSortWidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include "../util/GlobalSignal.h"

CheckOrderGoodsSortWidget::CheckOrderGoodsSortWidget(QWidget *parent)
    : QWidget(parent)
    , m_eCheckOrderGoodsSortType(e_sortByPrice)
    , m_eShowText(QStringLiteral("按金额"))
    , m_bDownSort(true)
    , m_bSelected(false)
    , m_nSortArrowStartXPos(-1)
    , m_nSortArrowEndXPos(-1)
{
    connect(GlobalSignal::instance(), SIGNAL(sigClickCheckOrderGoodsSortWidget(int)),
            this, SLOT(slot_clickCheckOrderGoodsSortWidget(int)));
}

void CheckOrderGoodsSortWidget::setSortType(CheckOrderGoodsSortType eCheckOrderGoodsSortType)
{
    m_eCheckOrderGoodsSortType = eCheckOrderGoodsSortType;
    m_eShowText = getShowText();
}

void CheckOrderGoodsSortWidget::canncleSelectedState()
{
    m_bSelected = false;
    update();
}

void CheckOrderGoodsSortWidget::setSelectedState()
{
    m_bSelected = true;
    update();
}

void CheckOrderGoodsSortWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    const int nTextXPos = 0;
    const int nTextYPos = 14;
    const int m_nFontSize = 12;
    const int nHeight = this->height();
    // 文字
    QFont font;
    font.setPixelSize(m_nFontSize);
    font.setFamily("微软雅黑");
    painter.setFont(font);
    QPen pen;
    if (m_bSelected)
    {
        pen.setColor("#ffffff");
    }
    else
    {
        pen.setColor("#999999");
    }
    painter.setPen(pen);
    const int nTextWidth = 38;
    QRect textRect(nTextXPos, nTextYPos, nTextWidth, m_nFontSize);
    painter.drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, m_eShowText);

//    // 排序箭头 代码实现(缺点是箭头的那一点效果不好)
//    int nUpDownFactor = (m_bDownSort? 1 : 0); // 翻转因子
//    int nOffXSpace = 6;
//    const int nLocateArrowWidth = 10;
//    const int nLocateArrowHeight = 10;
//    const int nTopPosX = nTextXPos + nTextWidth + nOffXSpace + nLocateArrowWidth/2;
//    const int nTopPosY = nTextYPos + (m_nFontSize - nLocateArrowHeight) + (nLocateArrowHeight * nUpDownFactor);
//    const int nLeftPosX = nTopPosX - nLocateArrowWidth/2;
//    const int nLeftPosY = nTextYPos + (m_nFontSize - nLocateArrowHeight) + nLocateArrowHeight - (nLocateArrowHeight * nUpDownFactor);
//    const int nRightPosX = nTopPosX + nLocateArrowWidth - nLocateArrowWidth/2;
//    const int nRightPosY = nLeftPosY;
//    static const QPoint triangle[3]={QPoint(nTopPosX, nTopPosY), QPoint(nLeftPosX, nLeftPosY), QPoint(nRightPosX, nRightPosY)};
//    painter.setRenderHint(QPainter::Antialiasing,true);
//    painter.setPen(QPen(QBrush(QColor("#9a9a9a")), 1));
//    painter.setBrush(QBrush(QColor("#9a9a9a")));
//    painter.drawPolygon(triangle, 3);

    // 排序箭头，如果多分辨率，箭头需要变形，变形的效果不好，可以更换用上述代码实现
    QPixmap pixmap;
    if (m_bDownSort)
    {
        pixmap.load(":/orderGoodsImage/sortDownArrow11.png");
    }
    else
    {
        pixmap.load(":/orderGoodsImage/sortUpArrow11.png");
    }

    int nOffXSpace = 6;
    const int nSortArrowWidth = 11;
    const int nSortArrowHeight = 10;
    const int nSortArrowXPos = nTextXPos + nTextWidth + nOffXSpace;
    const int nSortArrowYPos = nTextYPos + (m_nFontSize - nSortArrowHeight);
    QRect sortArrowRect(nSortArrowXPos, nSortArrowYPos, nSortArrowWidth, nSortArrowHeight);
    painter.drawPixmap(sortArrowRect, pixmap);

    m_nSortArrowStartXPos = nSortArrowXPos;
    m_nSortArrowEndXPos = nSortArrowXPos + nSortArrowWidth;

    // 定位箭头
    if (m_bSelected)
    {
        const int nLocateArrowWidth = 10;
        const int nLocateArrowHeight = 10;
        const int nTopPosX = nTextWidth/2;
        const int nTopPosY = nHeight - nLocateArrowHeight;
        const int nLeftPosX = nTopPosX - nLocateArrowWidth/2;
        const int nLeftPosY = nHeight;
        const int nRightPosX = nTopPosX + nLocateArrowWidth - nLocateArrowWidth/2;
        const int nRightPosY = nLeftPosY;
        static const QPoint triangle[3]={QPoint(nTopPosX, nTopPosY), QPoint(nLeftPosX, nLeftPosY), QPoint(nRightPosX, nRightPosY)};
        painter.setRenderHint(QPainter::Antialiasing,true);
        painter.setPen(QPen(QColor("#ffffff")));
        painter.setBrush(QBrush(QColor("#ffffff")));
        painter.drawPolygon(triangle, 3);
    }
}

void CheckOrderGoodsSortWidget::mousePressEvent(QMouseEvent *event)
{
    setSelectedState();
    emit GlobalSignal::instance()->sigClickCheckOrderGoodsSortWidget(m_eCheckOrderGoodsSortType);
    int nXPos = event->pos().x();
    if (nXPos >= m_nSortArrowStartXPos && nXPos <= m_nSortArrowEndXPos)
    {
        m_bDownSort = !m_bDownSort;
        update();
        emit sigDownSort(m_bDownSort);
    }
    else
    {
        emit sigClickText();
    }

    QWidget::mousePressEvent(event);
}

QString CheckOrderGoodsSortWidget::getShowText()
{
    switch (m_eCheckOrderGoodsSortType) {
    case e_sortByPrice:
        return QStringLiteral("按金额");
    case e_sortByNumber:
        return QStringLiteral("按数量");
    default:
        return QStringLiteral("按金额");
    }
}

void CheckOrderGoodsSortWidget::slot_clickCheckOrderGoodsSortWidget(int nType)
{
    if (nType != m_eCheckOrderGoodsSortType)
    {
        this->canncleSelectedState();
    }
}
