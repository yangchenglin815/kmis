#include "RefundWithReceiptTitle.h"
#include <QPainter>

RefundWithReceiptTitle::RefundWithReceiptTitle(QWidget *parent) : QWidget(parent)
{

}

void RefundWithReceiptTitle::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.fillRect(this->rect(), QBrush("#fafafa"));

    QFont font;
    font.setPixelSize(16);
    font.setFamily("微软雅黑");
    painter.setFont(font);
    QPen pen;
    pen.setColor("#666666");
    painter.setPen(pen);
    static const int c_nFirstColWidth = 108;
    static const int c_nSecondColWidth = 66;
    static const int c_nThirdColWidth = 162;
    static const int c_nFourthColWidth = 90;
    static const int c_nFifthColWidth = 200;

    static const QString c_sFirstColTitle = QStringLiteral("序号");
    static const QString c_sSecondColTitle = QStringLiteral("退款方式");
    static const QString c_sThirdColTitle = QStringLiteral("退款金额");
    static const QString c_sFourthColTitle = QStringLiteral("退款状态");
    static const QString c_sFifthColTitle = QStringLiteral("操作");

    int nHeight = this->height();
    int nWidth = this->width();

    int xPos = 0;
    int yPos = 0;
    QRect textRect(xPos, yPos, c_nFirstColWidth, nHeight);
    painter.drawText(textRect, Qt::AlignHCenter | Qt::AlignVCenter, c_sFirstColTitle);

    xPos += c_nFirstColWidth;
    QRect textRect2(xPos, yPos, c_nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignHCenter | Qt::AlignVCenter, c_sSecondColTitle);

    xPos += c_nSecondColWidth;
    QRect textRect3(xPos, yPos, c_nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignHCenter | Qt::AlignVCenter, c_sThirdColTitle);

    xPos += c_nThirdColWidth;
    QRect textRect4(xPos, yPos, c_nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignHCenter | Qt::AlignVCenter, c_sFourthColTitle);

    xPos = nWidth - c_nFifthColWidth;
    QRect textRect5(xPos, yPos, c_nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignHCenter | Qt::AlignVCenter, c_sFifthColTitle);

    QPen linePen;
    linePen.setColor("#ededed");
    painter.setPen(linePen);
    painter.drawLine(0, nHeight - 1, nWidth, nHeight - 1);
}
