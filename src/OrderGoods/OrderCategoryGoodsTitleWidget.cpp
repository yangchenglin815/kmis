#include "OrderCategoryGoodsTitleWidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

static const int c_nArrowWidth = 8;
static const int c_nArrowHeight = 7;

OrderCategoryGoodsTitleWidget::OrderCategoryGoodsTitleWidget(QWidget *parent)
    : QWidget(parent)
    , m_nFontSize(12)
    , m_nSecondColArrowStartXPos(-1)
    , m_nThirdColArrowStartXPos(-1)
    , m_bScondArrowDown(true)
    , m_bThirdArrowDown(true)
{

}

void OrderCategoryGoodsTitleWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.fillRect(this->rect(), QBrush("#fafafa"));

    QFont font;
    font.setPixelSize(m_nFontSize);
    font.setFamily("微软雅黑");
    painter.setFont(font);
    QPen pen;
    pen.setColor("#666666");
    painter.setPen(pen);

    static const int c_nTextArrowSpace = 3;
    static const int c_nFirstColWidth = 38;
    static const int c_nSecondColWidth = 216;
    static const int c_nThirdColWidth = 62;
    static const int c_nFourthColWidth = 62;
    static const int c_nFifthColWidth = 110;
    static const int c_nSixthColWidth = 32;
    static const QString c_sFirstColTitle = QStringLiteral("商品");
    static const QString c_sSecondColTitle = QStringLiteral("今日已订");
    static const QString c_sThirdColTitle = QStringLiteral("订销差率");
    static const QString c_sFourthColTitle = QStringLiteral("库存数量");
    static const QString c_sFifthColTitle = QStringLiteral("上日/周销售数量");
    static const QString c_sSixColTitle = QStringLiteral("单价");

    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;
    // 商品
    QRect textRect1(xPos, yPos, c_nFirstColWidth, nHeight);
    painter.drawText(textRect1, Qt::AlignRight | Qt::AlignVCenter, c_sFirstColTitle);

    // 今日已订
    xPos += c_nFirstColWidth;
    QRect textRect2(xPos, yPos, c_nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignRight | Qt::AlignVCenter, c_sSecondColTitle);

    // 今日已订的箭头
    xPos += c_nSecondColWidth + c_nTextArrowSpace;
    m_nSecondColArrowStartXPos = xPos;
    int arrowYPos = (nHeight - c_nArrowHeight)/2;
    QRect secondArrowRect(xPos, arrowYPos, c_nArrowWidth, c_nArrowHeight);
    QPixmap secondArrowPixmap(m_bScondArrowDown ? ":/orderGoodsImage/sortDownArrow.png" : ":/orderGoodsImage/sortUpArrow.png");
    painter.drawPixmap(secondArrowRect, secondArrowPixmap.scaled(c_nArrowWidth, c_nArrowHeight));

    // 订销差率
    xPos += c_nArrowWidth;
    QRect textRect3(xPos, yPos, c_nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);

    // 订销差率的箭头
    xPos += c_nThirdColWidth + c_nTextArrowSpace;
    m_nThirdColArrowStartXPos = xPos;
    QRect thirdArrowRect(xPos, arrowYPos, c_nArrowWidth, c_nArrowHeight);
    QPixmap thirdArrowPixmap(m_bThirdArrowDown ? ":/orderGoodsImage/sortDownArrow.png" : ":/orderGoodsImage/sortUpArrow.png");
    painter.drawPixmap(thirdArrowRect, thirdArrowPixmap.scaled(c_nArrowWidth, c_nArrowHeight));

    // 库存数量
    xPos += c_nArrowWidth;
    QRect textRect4(xPos, yPos, c_nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignRight | Qt::AlignVCenter, c_sFourthColTitle);

    // 上日/周销售数量
    xPos += c_nFourthColWidth;
    QRect textRect5(xPos, yPos, c_nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFifthColTitle);

    // 单价
    xPos += c_nFifthColWidth;
    QRect textRect6(xPos, yPos, c_nSixthColWidth, nHeight);
    painter.drawText(textRect6, Qt::AlignRight | Qt::AlignVCenter, c_sSixColTitle);
}

void OrderCategoryGoodsTitleWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    int x = event->pos().x();
    if ((x >= m_nSecondColArrowStartXPos)
            && (x <= (m_nSecondColArrowStartXPos + c_nArrowWidth)))
    {
        m_bScondArrowDown = !m_bScondArrowDown;
        update();
        emit sigSortSecondCol(m_bScondArrowDown);
    }
    else if ((x >= m_nThirdColArrowStartXPos)
             && (x <= (m_nThirdColArrowStartXPos + c_nArrowWidth)))
    {
        m_bThirdArrowDown = !m_bThirdArrowDown;
        update();
        emit sigSortThirdCol(m_bThirdArrowDown);
    }
}
