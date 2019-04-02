#include "PendingListTitleWidget.h"
#include <QPaintEvent>
#include <QPainter>

PendingListTitleWidget::PendingListTitleWidget(QWidget *parent)
    : QWidget(parent)
{

}

void PendingListTitleWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.fillRect(this->rect(), QBrush("#fafafa"));

    QFont font;
    font.setPixelSize(12);
    font.setFamily("微软雅黑");
    painter.setFont(font);
    QPen pen;
    pen.setColor("#666666");
    painter.setPen(pen);
    static const int c_nFirstColWidth = 58;
    static const int c_nSecondColWidth = 130;
    static const int c_nThirdColWidth = 68;
    static const QString c_sFirstColTitle = QStringLiteral("订单号");
    static const QString c_sSecondColTitle = QStringLiteral("创建时间");
    static const QString c_sThirdColTitle = QStringLiteral("操作");

    int nHeight = this->height();
    int nWidth = this->width();

    int xPos = 0;
    int yPos = 0;
    QRect textRect(xPos, yPos, c_nFirstColWidth, nHeight);
    painter.drawText(textRect, Qt::AlignHCenter | Qt::AlignVCenter, c_sFirstColTitle);

    xPos += c_nFirstColWidth;
    QRect textRect2(xPos, yPos, c_nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignHCenter | Qt::AlignVCenter, c_sSecondColTitle);

    xPos = nWidth - c_nThirdColWidth;
    QRect textRect3(xPos, yPos, c_nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignHCenter | Qt::AlignVCenter, c_sThirdColTitle);

    QPen linePen;
    linePen.setColor("#ededed");
    painter.setPen(linePen);
    painter.drawLine(0, nHeight , nWidth, nHeight);
}
