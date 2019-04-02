#include "InquireTitleWidget.h"
#include <QPainter>
#include "constData.h"

InquireTitleWidget::InquireTitleWidget(QWidget *parent) : QWidget(parent)
{
}

void InquireTitleWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.fillRect(this->rect(), QBrush("#fafafa"));

    const int m_nFontSize = 12*g_widthRate;
    QFont font;
    font.setPixelSize(m_nFontSize);
    font.setFamily("微软雅黑");
    painter.setFont(font);
    QPen pen;
    pen.setColor("#666666");
    painter.setPen(pen);
    //总计7个纵排
    static const int c_nFirstColWidth = 44*g_widthRate;
    static const int c_nSecondColWidth = 38*g_widthRate;
    static const int c_nThirdColWidth = 244*g_widthRate;
    static const int c_nFourthColWidth = 106*g_widthRate;
    static const int c_nFiveColWidth = 98*g_widthRate;
    static const int c_nSixColWidth = 162*g_widthRate;
//    static const int c_nSevenColWidth = 86;

    static const QString c_sFirstColTitle = QString::fromUtf8("序号");
    static const QString c_sSecondColTitle = QString::fromUtf8("商品");
    static const QString c_sThirdColTitle = QString::fromUtf8("入库单价");
    static const QString c_sFourthColTitle = QString::fromUtf8("数量");
    static const QString c_sFiveColTitle = QString::fromUtf8("件数");
    static const QString c_sSixColTitle = QString::fromUtf8("小计金额");
//    static const QString c_sSevenColTitle = QString::fromUtf8("审核状态");

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

    xPos += c_nFourthColWidth;
    QRect textRect5(xPos, yPos, c_nFiveColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFiveColTitle);

    xPos += c_nFiveColWidth;
    QRect textRect6(xPos, yPos, c_nSixColWidth, nHeight);
    painter.drawText(textRect6, Qt::AlignRight | Qt::AlignVCenter, c_sSixColTitle);
//    xPos += c_nThirdColWidth;

//    QRect textRect7(xPos, yPos, c_nSevenColWidth, nHeight);
//    painter.drawText(textRect7, Qt::AlignRight | Qt::AlignVCenter, c_sSevenColTitle);

}

