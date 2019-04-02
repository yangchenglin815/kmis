#include "SummaryChartsLeftTitleWidget.h"
#include <QPainter>

SummaryChartsLeftTitleWidget::SummaryChartsLeftTitleWidget(QWidget *parent) : QWidget(parent)
{

}

void SummaryChartsLeftTitleWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.fillRect(this->rect(), QBrush("#fafafa"));

    const int m_nFontSize = 12;
    QFont font;
    font.setPixelSize(m_nFontSize);
    font.setFamily("微软雅黑");
    painter.setFont(font);
    QPen pen;
    pen.setColor("#666666");
    painter.setPen(pen);

    int nFirstColWidth = 46; // 时段
    int nSecondColWidth = 128; // 销售额
    int nThirdColWidth = 111;  // 客流量
    int nFourthColWidth = 75; // 客单价
    static const QString c_sFirstColTitle = QStringLiteral("时段");
    static const QString c_sSecondColTitle = QStringLiteral("销售额");
    static const QString c_sThirdColTitle = QStringLiteral("客流量");
    static const QString c_sFourthColTitle = QStringLiteral("客单价");

    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;
    // 时段
    QRect textRect1(xPos, yPos, nFirstColWidth, nHeight);
    painter.drawText(textRect1, Qt::AlignRight | Qt::AlignVCenter, c_sFirstColTitle);

    // 销售额
    xPos += nFirstColWidth;
    QRect textRect2(xPos, yPos, nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignRight | Qt::AlignVCenter, c_sSecondColTitle);

    // 客流量
    xPos += nSecondColWidth;
    QRect textRect3(xPos, yPos, nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);

    // 客单价
    xPos += nThirdColWidth;
    QRect textRect4(xPos, yPos, nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignRight | Qt::AlignVCenter, c_sFourthColTitle);
}
