#include "BCSManageTitleWidget.h"
#include <QPainter>

BCSManageTitleWidget::BCSManageTitleWidget(QWidget *parent) : QWidget(parent)
{

}

void BCSManageTitleWidget::paintEvent(QPaintEvent *event)
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

    static const int c_nFirstColWidth = 40;
    static const int c_nSecondColWidth = 45;
    static const int c_nThirdColWidth = 65;
    static const int c_nFourthColWidth = 119;
    static const int c_nFifthColWidth = 219;
    static const int c_nSixthColWidth = 142;
    static const int c_nSeventhColWidth = 92;

    static const QString c_sFirstColTitle = QStringLiteral("序号");
    static const QString c_sSecondColTitle = QStringLiteral("编号");
    static const QString c_sThirdColTitle = QStringLiteral("型号");
    static const QString c_sFourthColTitle = QStringLiteral("IP");
    static const QString c_sFifthColTitle = QStringLiteral("关联商品组");
    static const QString c_sSixthColTitle = QStringLiteral("上次下发时间");
    static const QString c_sSeventhColTitle = QStringLiteral("状态");


    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;
    // 序号
    QRect textRect1(xPos, yPos, c_nFirstColWidth, nHeight);
    painter.drawText(textRect1, Qt::AlignRight | Qt::AlignVCenter, c_sFirstColTitle);

    // 编号
    xPos += c_nFirstColWidth;
    QRect textRect2(xPos, yPos, c_nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignRight | Qt::AlignVCenter, c_sSecondColTitle);

    // 型号
    xPos += c_nSecondColWidth;
    QRect textRect3(xPos, yPos, c_nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);

    // IP
    xPos += c_nThirdColWidth;
    QRect textRect4(xPos, yPos, c_nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignRight | Qt::AlignVCenter, c_sFourthColTitle);

    // 关联商品组
    xPos += c_nFourthColWidth;
    QRect textRect5(xPos, yPos, c_nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFifthColTitle);

    // 上次下发时间
    xPos += c_nFifthColWidth;
    QRect textRect6(xPos, yPos, c_nSixthColWidth, nHeight);
    painter.drawText(textRect6, Qt::AlignRight | Qt::AlignVCenter, c_sSixthColTitle);

    // 状态
    xPos += c_nSixthColWidth;
    QRect textRect7(xPos, yPos, c_nSeventhColWidth, nHeight);
    painter.drawText(textRect7, Qt::AlignRight | Qt::AlignVCenter, c_sSeventhColTitle);
}

