#include "CheckOrderGoodsTitleWidget.h"
#include <QPainter>

CheckOrderGoodsTitleWidget::CheckOrderGoodsTitleWidget(QWidget *parent) : QWidget(parent)
{

}

void CheckOrderGoodsTitleWidget::setCheckTitle(bool bFlag)
{
    m_bUploadFinished = bFlag;
}

void CheckOrderGoodsTitleWidget::paintEvent(QPaintEvent *event)
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

    int nFirstColWidth = 48;
    int nSecondColWidth = 226;
    int nThirdColWidth = 94;
    int nFourthColWidth = 54;
    int nFifthColWidth = 80;
    if (m_bUploadFinished)
    {
        nFirstColWidth = 48;
        nSecondColWidth = 240;
        nThirdColWidth = 120;
        nFourthColWidth = 78;
        nFifthColWidth = 105;
    }
    static const QString c_sFirstColTitle = QStringLiteral("商品");
    static const QString c_sSecondColTitle = QStringLiteral("要货件数/数量");
    static const QString c_sThirdColTitle = QStringLiteral("审核件数/数量");
    static const QString c_sFourthColTitle = QStringLiteral("单价");
    static const QString c_sFifthColTitle = QStringLiteral("金额");

    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;
    // 商品
    QRect textRect1(xPos, yPos, nFirstColWidth, nHeight);
    painter.drawText(textRect1, Qt::AlignRight | Qt::AlignVCenter, c_sFirstColTitle);

    // 要货件数/数量
    xPos += nFirstColWidth;
    QRect textRect2(xPos, yPos, nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignRight | Qt::AlignVCenter, c_sSecondColTitle);

    // 审核件数/数量
    xPos += nSecondColWidth;
    QRect textRect3(xPos, yPos, nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);

    // 单件单价
    xPos += nThirdColWidth;
    QRect textRect4(xPos, yPos, nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignRight | Qt::AlignVCenter, c_sFourthColTitle);

    // 金额
    xPos += nFourthColWidth;
    QRect textRect5(xPos, yPos, nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFifthColTitle);
}
