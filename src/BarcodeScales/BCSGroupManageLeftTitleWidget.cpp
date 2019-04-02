#include "BCSGroupManageLeftTitleWidget.h"
#include <QPainter>

BCSGroupManageLeftTitleWidget::BCSGroupManageLeftTitleWidget(QWidget *parent) : QWidget(parent)
{

}

void BCSGroupManageLeftTitleWidget::paintEvent(QPaintEvent *event)
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

    static const QString c_sFirstColTitle = QStringLiteral("序号");
    static const QString c_sSecondColTitle = QStringLiteral("组号");
    static const QString c_sThirdColTitle = QStringLiteral("组名");


    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;
    // 序号
    QRect textRect1(xPos, yPos, c_nFirstColWidth, nHeight);
    painter.drawText(textRect1, Qt::AlignRight | Qt::AlignVCenter, c_sFirstColTitle);

    // 组号
    xPos += c_nFirstColWidth;
    QRect textRect2(xPos, yPos, c_nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignRight | Qt::AlignVCenter, c_sSecondColTitle);

    // 组名
    xPos += c_nSecondColWidth;
    QRect textRect3(xPos, yPos, c_nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);
}

