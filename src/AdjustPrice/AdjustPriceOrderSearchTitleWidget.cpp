#include "AdjustPriceOrderSearchTitleWidget.h"
#include <QPainter>
#include "constData.h"

AdjustPriceOrderSearchTitleWidget::AdjustPriceOrderSearchTitleWidget(QWidget *parent)
    : QWidget(parent)
{

}

void AdjustPriceOrderSearchTitleWidget::paintEvent(QPaintEvent *event)
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
    static const int c_nSecondColWidth = 52 * g_heightRate;
    static const int c_nThirdColWidth = 244 * g_heightRate;
    static const int c_nFourthColWidth = 132 * g_heightRate;
    static const int c_nFifthColWidth = 132 * g_heightRate;
    static const int c_nSixthColWidth = 132 * g_heightRate;
    static const QString c_sFirstColTitle = QStringLiteral("序号");
    static const QString c_sSecondColTitle = QStringLiteral("商品");
    static const QString c_sThirdColTitle = QStringLiteral("原售价");
    static const QString c_sFourthColTitle = QStringLiteral("现售价");
    static const QString c_sFifthColTitle = QStringLiteral("原会员价");
    static const QString c_sSixthColTitle = QStringLiteral("现会员价");

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

    // 原售价
    xPos += c_nSecondColWidth;
    QRect textRect3(xPos, yPos, c_nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);

    // 现售价
    xPos += c_nThirdColWidth;
    QRect textRect4(xPos, yPos, c_nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignRight | Qt::AlignVCenter, c_sFourthColTitle);

    // 原会员价
    xPos += c_nFourthColWidth;
    QRect textRect5(xPos, yPos, c_nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFifthColTitle);

    // 现会员价
    xPos += c_nFifthColWidth;
    QRect textRect6(xPos, yPos, c_nSixthColWidth, nHeight);
    painter.drawText(textRect6, Qt::AlignRight | Qt::AlignVCenter, c_sSixthColTitle);
}

