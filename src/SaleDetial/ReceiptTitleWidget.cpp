#include "ReceiptTitleWidget.h"
#include "constData.h"
#include <QMouseEvent>
#include <QPainter>

ReceiptTitleWidget::ReceiptTitleWidget(QWidget *parent) : QWidget(parent)
{

}

void ReceiptTitleWidget::paintEvent(QPaintEvent *event)
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

    //总计6个纵排
    static const int c_nFirstColWidth = 80*g_widthRate;
    static const int c_nSecondColWidth = 160*g_widthRate;
    static const int c_nThirdColWidth = 100*g_widthRate;
    static const int c_nFourthColWidth = 120*g_widthRate;
    static const int c_nFifthColWidth = 142*g_widthRate;
    static const int c_nSixthColWidth = 120*g_widthRate;

    static const QString c_sFirstColTitle = QString::fromUtf8("小票编号");
    static const QString c_sSecondColTitle = QString::fromUtf8("收银员");
    static const QString c_sThirdColTitle = QString::fromUtf8("导购员");
    static const QString c_sFourthColTitle = QString::fromUtf8("交易时间");
    static const QString c_sFifthColTitle = QString::fromUtf8("类型");
    static const QString c_sSixthColTitle = QString::fromUtf8("状态");

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

    //
    xPos += c_nFourthColWidth;
    QRect textRect5(xPos, yPos, c_nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFifthColTitle);

    //
    xPos += c_nFifthColWidth;
    QRect textRect6(xPos, yPos, c_nSixthColWidth, nHeight);
    painter.drawText(textRect6, Qt::AlignRight | Qt::AlignVCenter, c_sSixthColTitle);
}

