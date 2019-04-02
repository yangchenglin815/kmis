#include "CheckDetialTitleWidget.h"
#include "constData.h"
#include <QPainter>
#include <QMouseEvent>

static const int c_nArrowWidth = 8;
static const int c_nArrowHeight = 7;

CheckDetialTitleWidget::CheckDetialTitleWidget(QWidget *parent)
    : QWidget(parent)
    , m_nFourthColArrowStartXPos(-1)
    , m_nFifthColArrowStartXPos(-1)
    , m_bFourthArrowDown(true)
    , m_bFifthArrowDown(true)
{

}

void CheckDetialTitleWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.fillRect(this->rect(), QBrush("#fafafa"));

    QFont font;
    font.setPixelSize(f_fontSizeMode2*g_widthRate);
    font.setFamily(f_fontStyle);
    painter.setFont(font);
    QPen pen;
    pen.setColor("#666666");
    painter.setPen(pen);

    //总计5个纵排
    static const int c_nFirstColWidth = 50*g_widthRate;
    static const int c_nSecondColWidth = 50*g_widthRate;
    static const int c_nThirdColWidth = 250*g_widthRate;
    static const int c_nFourthColWidth = 210*g_widthRate;
    static const int c_nFifthColWidth = 140*g_widthRate;

    static const int c_nTextArrowSpace = 3*g_heightRate;
    static const QString c_sFirstColTitle = QString::fromUtf8("序号");
    static const QString c_sSecondColTitle = QString::fromUtf8("商品");
    static const QString c_sThirdColTitle = QString::fromUtf8("类别");
    static const QString c_sFourthColTitle = QString::fromUtf8("报损数量");
    static const QString c_sFifthColTitle = QString::fromUtf8("报损金额");

    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;

    //
    QRect textRect1(xPos, yPos, c_nFirstColWidth, nHeight);
    painter.drawText(textRect1, Qt::AlignRight | Qt::AlignVCenter, c_sFirstColTitle);

    //
    xPos += c_nFirstColWidth;
    QRect textRect2(xPos, yPos, c_nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignRight | Qt::AlignVCenter, c_sSecondColTitle);

    //
    xPos += c_nSecondColWidth;
    QRect textRect3(xPos, yPos, c_nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);

    //
    xPos += c_nThirdColWidth;
    QRect textRect4(xPos, yPos, c_nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignRight | Qt::AlignVCenter, c_sFourthColTitle);

    // 报损数量的箭头
    xPos += c_nFourthColWidth + c_nTextArrowSpace;
    m_nFourthColArrowStartXPos = xPos;
    int arrowYPos = (nHeight - c_nArrowHeight)/2;
    QRect fourthArrowRect(xPos, arrowYPos, c_nArrowWidth, c_nArrowHeight);
    QPixmap fourthArrowPixmap(m_bFourthArrowDown?":/orderGoodsImage/sortDownArrow.png":":/orderGoodsImage/sortUpArrow.png");
    painter.drawPixmap(fourthArrowRect, fourthArrowPixmap.scaled(c_nArrowWidth, c_nArrowHeight));

    //
    xPos += c_nArrowWidth;
    QRect textRect5(xPos, yPos, c_nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFifthColTitle);

    // 报损金额的箭头
    xPos += c_nFifthColWidth + c_nTextArrowSpace;
    m_nFifthColArrowStartXPos = xPos;
    QRect fifthArrowRect(xPos, arrowYPos, c_nArrowWidth, c_nArrowHeight);
    QPixmap fifthArrowPixmap(m_bFifthArrowDown?":/orderGoodsImage/sortDownArrow.png":":/orderGoodsImage/sortUpArrow.png");
    painter.drawPixmap(fifthArrowRect, fifthArrowPixmap.scaled(c_nArrowWidth, c_nArrowHeight));
}

void CheckDetialTitleWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    int x = event->pos().x();
    if((x >= m_nFourthColArrowStartXPos)
            && (x <= (m_nFourthColArrowStartXPos + c_nArrowWidth))){
        m_bFourthArrowDown = !m_bFourthArrowDown;
        update();
        emit sigSortFoutthCol(m_bFourthArrowDown);
    }
    else if((x >= m_nFifthColArrowStartXPos)
            && (x <= (m_nFifthColArrowStartXPos + c_nArrowWidth))){
        m_bFifthArrowDown = !m_bFifthArrowDown;
        update();
        emit sigSortFifthCol(m_bFifthArrowDown);
    }
}
