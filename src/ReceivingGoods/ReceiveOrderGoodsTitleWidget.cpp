#include "ReceiveOrderGoodsTitleWidget.h"
#include <QPainter>

ReceiveOrderGoodsTitleWidget::ReceiveOrderGoodsTitleWidget(QWidget *parent)
    : QWidget(parent)
    , m_bFinished(false)
{

}

void ReceiveOrderGoodsTitleWidget::setFinishedFlag(bool bFinished)
{
    m_bFinished = bFinished;
}

void ReceiveOrderGoodsTitleWidget::paintEvent(QPaintEvent *event)
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

    int nFirstColWidth = 44; // 商品
    int nSecondColWidth = 282; // 应收件数/数量
    int nThirdColWidth = 116;  // 实收件数/数量
    int nFourthColWidth = 80; // 收货金额
    int nFifthColWidth = 82; // 状态
    int nSixthColWidth = 113; // 操作
    if (m_bFinished)
    {
        nFirstColWidth = 44; // 商品
        nSecondColWidth = 346; // 应收件数/数量
        nThirdColWidth = 136;  // 实收件数/数量
        nFourthColWidth = 88; // 收货金额
        nFifthColWidth = 82; // 状态
        nSixthColWidth = 105; // 操作
    }
    static const QString c_sFirstColTitle = QStringLiteral("商品");
    static const QString c_sSecondColTitle = QStringLiteral("应收件数/数量");
    static const QString c_sThirdColTitle = QStringLiteral("实收件数/数量");
    static const QString c_sFourthColTitle = QStringLiteral("收货金额");
    static const QString c_sFifthColTitle = QStringLiteral("状态");
    static const QString c_sSixthColTitle = QStringLiteral("操作");

    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;
    // 商品
    QRect textRect1(xPos, yPos, nFirstColWidth, nHeight);
    painter.drawText(textRect1, Qt::AlignRight | Qt::AlignVCenter, c_sFirstColTitle);

    // 应收件数/数量
    xPos += nFirstColWidth;
    QRect textRect2(xPos, yPos, nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignRight | Qt::AlignVCenter, c_sSecondColTitle);

    // 实收件数/数量
    xPos += nSecondColWidth;
    QRect textRect3(xPos, yPos, nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);

    // 收货金额
    xPos += nThirdColWidth;
    QRect textRect4(xPos, yPos, nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignRight | Qt::AlignVCenter, c_sFourthColTitle);

    // 状态
    xPos += nFourthColWidth;
    QRect textRect5(xPos, yPos, nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFifthColTitle);

    if (!m_bFinished)
    {
        // 操作
        xPos += nFifthColWidth;
        QRect textRect6(xPos, yPos, nSixthColWidth, nHeight);
        painter.drawText(textRect6, Qt::AlignRight | Qt::AlignVCenter, c_sSixthColTitle);
    }
}
