#include "RankChartsLeftTitleWidget.h"
#include <QPainter>

RankChartsLeftTitleWidget::RankChartsLeftTitleWidget(QWidget *parent) : QWidget(parent)
{

}

void RankChartsLeftTitleWidget::paintEvent(QPaintEvent *event)
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

    int nFirstColWidth = 73; // 商品
    int nSecondColWidth = 134; // 销售额
    int nThirdColWidth = 47;  // 单价
    int nFourthColWidth = 58; // 销售量
    int nFifthColWidth = 45; // 客流
    static const QString c_sFirstColTitle = QStringLiteral("商品");
    static const QString c_sSecondColTitle = QStringLiteral("销售额");
    static const QString c_sThirdColTitle = QStringLiteral("单价");
    static const QString c_sFourthColTitle = QStringLiteral("销售量");
    static const QString c_sFifthColTitle = QStringLiteral("客流");

    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;
    // 商品
    QRect textRect1(xPos, yPos, nFirstColWidth, nHeight);
    painter.drawText(textRect1, Qt::AlignRight | Qt::AlignVCenter, c_sFirstColTitle);

    // 销售额
    xPos += nFirstColWidth;
    QRect textRect2(xPos, yPos, nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignRight | Qt::AlignVCenter, c_sSecondColTitle);

    // 单价
    xPos += nSecondColWidth;
    QRect textRect3(xPos, yPos, nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);

    // 销售量
    xPos += nThirdColWidth;
    QRect textRect4(xPos, yPos, nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignRight | Qt::AlignVCenter, c_sFourthColTitle);

    // 客流
    xPos += nFourthColWidth;
    QRect textRect5(xPos, yPos, nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFifthColTitle);
}
