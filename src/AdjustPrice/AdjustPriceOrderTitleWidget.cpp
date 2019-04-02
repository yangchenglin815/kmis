#include "AdjustPriceOrderTitleWidget.h"
#include <QPainter>
#include "../data/constData.h"

AdjustPriceOrderTitleWidget::AdjustPriceOrderTitleWidget(QWidget *parent)
    : QWidget(parent)
{

}

void AdjustPriceOrderTitleWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.fillRect(this->rect(), QBrush("#fafafa"));

    const int m_nFontSize = 12 * g_heightRate;
    QFont font;
    font.setPixelSize(m_nFontSize);
    font.setFamily("微软雅黑");
    painter.setFont(font);
    QPen pen;
    pen.setColor("#666666");
    painter.setPen(pen);

    static const int c_nFirstColWidth = 48 * g_heightRate;
    static const int c_nSecondColWidth = 286 * g_heightRate;
    static const int c_nThirdColWidth = 100 * g_heightRate;
    static const int c_nFourthColWidth = 148 * g_heightRate;
    static const int c_nFifthColWidth = 142 * g_heightRate;
    static const QString c_sFirstColTitle = QStringLiteral("单号");
    static const QString c_sSecondColTitle = QStringLiteral("制单人/审核人");
    static const QString c_sThirdColTitle = QStringLiteral("制单时间");
    static const QString c_sFourthColTitle = QStringLiteral("生效时间");
    static const QString c_sFifthColTitle = QStringLiteral("状态");

    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;
    // 单号
    QRect textRect1(xPos, yPos, c_nFirstColWidth, nHeight);
    painter.drawText(textRect1, Qt::AlignRight | Qt::AlignVCenter, c_sFirstColTitle);

    // 制单人/审核人
    xPos += c_nFirstColWidth;
    QRect textRect2(xPos, yPos, c_nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignRight | Qt::AlignVCenter, c_sSecondColTitle);

    // 修改时间
    xPos += c_nSecondColWidth;
    QRect textRect3(xPos, yPos, c_nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);

    // 生效时间
    xPos += c_nThirdColWidth;
    QRect textRect4(xPos, yPos, c_nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignRight | Qt::AlignVCenter, c_sFourthColTitle);

    // 状态
    xPos += c_nFourthColWidth;
    QRect textRect5(xPos, yPos, c_nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFifthColTitle);
}

