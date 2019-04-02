#include "ReceiveOrdersTitleWidget.h"
#include <QPainter>

ReceiveOrdersTitleWidget::ReceiveOrdersTitleWidget(QWidget *parent)
    : QWidget(parent)
{

}

void ReceiveOrdersTitleWidget::paintEvent(QPaintEvent *event)
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

    int nFirstColWidth = 56; // 供应商
    int nSecondColWidth = 126; // 单号
    int nThirdColWidth = 172;  // 应收件数/数量
    int nFourthColWidth = 90; // 实收件数/数量
    int nFifthColWidth = 40; // 金额
    int nSixthColWidth = 89; // 上传时间
    int nSeventhColWidth = 66; // 状态
    int nEighthColWidth = 87; // 操作
    static const QString c_sFirstColTitle = QStringLiteral("供应商");
    static const QString c_sSecondColTitle = QStringLiteral("单号");
    static const QString c_sThirdColTitle = QStringLiteral("应收件数/数量");
    static const QString c_sFourthColTitle = QStringLiteral("实收件数/数量");
    static const QString c_sFifthColTitle = QStringLiteral("金额");
    static const QString c_sSixthColTitle = QStringLiteral("上传时间");
    static const QString c_sSeventhColTitle = QStringLiteral("状态");
    static const QString c_sEighthColTitle = QStringLiteral("操作");

    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;
    // 供应商
    QRect textRect1(xPos, yPos, nFirstColWidth, nHeight);
    painter.drawText(textRect1, Qt::AlignRight | Qt::AlignVCenter, c_sFirstColTitle);

    // 单号
    xPos += nFirstColWidth;
    QRect textRect2(xPos, yPos, nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignRight | Qt::AlignVCenter, c_sSecondColTitle);

    // 应收件数/数量
    xPos += nSecondColWidth;
    QRect textRect3(xPos, yPos, nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);

    // 实收件数/数量
    xPos += nThirdColWidth;
    QRect textRect4(xPos, yPos, nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignRight | Qt::AlignVCenter, c_sFourthColTitle);

    // 金额
    xPos += nFourthColWidth;
    QRect textRect5(xPos, yPos, nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFifthColTitle);

    // 上传时间
    xPos += nFifthColWidth;
    QRect textRect6(xPos, yPos, nSixthColWidth, nHeight);
    painter.drawText(textRect6, Qt::AlignRight | Qt::AlignVCenter, c_sSixthColTitle);

    // 状态
    xPos += nSixthColWidth;
    QRect textRect7(xPos, yPos, nSeventhColWidth, nHeight);
    painter.drawText(textRect7, Qt::AlignRight | Qt::AlignVCenter, c_sSeventhColTitle);

    // 操作
    xPos += nSeventhColWidth;
    QRect textRect8(xPos, yPos, nEighthColWidth, nHeight);
    painter.drawText(textRect8, Qt::AlignRight | Qt::AlignVCenter, c_sEighthColTitle);
}
