#include "StockOrderSearchTitleWidget.h"
#include <QPainter>
#include "constData.h"
#include <QMouseEvent>
#include <QDebug>

static const int c_nArrowWidth = 8;
static const int c_nArrowHeight = 7;

StockOrderSearchTitleWidget::StockOrderSearchTitleWidget(QWidget *parent)
    : QWidget(parent)
    , m_nFontSize(12)
    , m_nSixthColArrowStartXPos(-1)
    , m_nSeventhColArrowStartXPos(-1)
    , m_bSixthArrowDown(true)
    , m_bSeventhArrowDown(true)
{

}

void StockOrderSearchTitleWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.fillRect(this->rect(), QBrush("#fafafa"));

    QFont font;
    font.setPixelSize(m_nFontSize*g_heightRate);
    font.setFamily("微软雅黑");
    painter.setFont(font);
    QPen pen;
    pen.setColor("#666666");
    painter.setPen(pen);

    static const int c_nTextArrowSpace = 3*g_heightRate;
    static const int c_nFirstColWidth = 46*g_heightRate; // 序号
    static const int c_nSecondColWidth = 42*g_heightRate; // 商品
    static const int c_nThirdColWidth = 218*g_heightRate; // 类别
    static const int c_nFourthColWidth = 98*g_heightRate; // 账盘数量
    static const int c_nFifthColWidth = 98*g_heightRate; // 实盘数量
    static const int c_nSixthColWidth = 100*g_heightRate; // 差异数量
    static const int c_nSeventhColWidth = 118*g_heightRate; // 进价差异金额
    static const QString c_sFirstColTitle = QStringLiteral("序号");
    static const QString c_sSecondColTitle = QStringLiteral("商品");
    static const QString c_sThirdColTitle = QStringLiteral("类别");
    static const QString c_sFourthColTitle = QStringLiteral("账盘数量");
    static const QString c_sFifthColTitle = QStringLiteral("实盘数量");
    static const QString c_sSixColTitle = QStringLiteral("差异数量");
    static const QString c_sSevenColTitle = QStringLiteral("进价差异金额");

    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;
    // 序号
    QRect textRect1(xPos, yPos, c_nFirstColWidth, nHeight);
    painter.drawText(textRect1, Qt::AlignRight | Qt::AlignVCenter, c_sFirstColTitle);

    // 商品
    xPos += c_nFirstColWidth;
    QRect textRect2(xPos, yPos, c_nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignRight | Qt::AlignVCenter, c_sSecondColTitle);

    // 类别
    xPos += c_nSecondColWidth;
    QRect textRect3(xPos, yPos, c_nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);

    // 账盘数量
    xPos += c_nThirdColWidth;
    QRect textRect4(xPos, yPos, c_nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignRight | Qt::AlignVCenter, c_sFourthColTitle);

    // 实盘数量
    xPos += c_nFourthColWidth;
    QRect textRect5(xPos, yPos, c_nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFifthColTitle);

    // 差异数量
    xPos += c_nFifthColWidth;
    QRect textRect6(xPos, yPos, c_nSixthColWidth, nHeight);
    painter.drawText(textRect6, Qt::AlignRight | Qt::AlignVCenter, c_sSixColTitle);

    // 差异数量的箭头
    xPos += c_nSixthColWidth + c_nTextArrowSpace;
    m_nSixthColArrowStartXPos = xPos;
    int arrowYPos = (nHeight - c_nArrowHeight)/2;
    QRect sixthArrowRect(xPos, arrowYPos, c_nArrowWidth, c_nArrowHeight);
    QPixmap sixthArrowPixmap(m_bSixthArrowDown?":/orderGoodsImage/sortDownArrow.png":":/orderGoodsImage/sortUpArrow.png");
    painter.drawPixmap(sixthArrowRect, sixthArrowPixmap.scaled(c_nArrowWidth, c_nArrowHeight));

    // 进价差异金额
    xPos += c_nArrowWidth;
    QRect textRect7(xPos, yPos, c_nSeventhColWidth, nHeight);
    painter.drawText(textRect7, Qt::AlignRight | Qt::AlignVCenter, c_sSevenColTitle);

    // 进价差异金额的箭头
    xPos += c_nSeventhColWidth + c_nTextArrowSpace;
    m_nSeventhColArrowStartXPos = xPos;
    QRect seventhArrowRect(xPos, arrowYPos, c_nArrowWidth, c_nArrowHeight);
    QPixmap seventhArrowPixmap(m_bSeventhArrowDown ? ":/orderGoodsImage/sortDownArrow.png" : ":/orderGoodsImage/sortUpArrow.png");
    painter.drawPixmap(seventhArrowRect, seventhArrowPixmap.scaled(c_nArrowWidth, c_nArrowHeight));
}

void StockOrderSearchTitleWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    int x = event->pos().x();
    if ((x >= m_nSixthColArrowStartXPos)
            && (x <= (m_nSixthColArrowStartXPos + c_nArrowWidth)))
    {
        m_bSixthArrowDown = !m_bSixthArrowDown;
        update();
        emit sigSortSixthCol(m_bSixthArrowDown);
    }
    else if ((x >= m_nSeventhColArrowStartXPos)
             && (x <= (m_nSeventhColArrowStartXPos + c_nArrowWidth)))
    {
        m_bSeventhArrowDown = !m_bSeventhArrowDown;
        update();
        emit sigSortSeventhCol(m_bSeventhArrowDown);
    }
}

