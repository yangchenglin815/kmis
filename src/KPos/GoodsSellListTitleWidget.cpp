#include "GoodsSellListTitleWidget.h"
#include <QPainter>
#include "../data/constData.h"

GoodsSellListTitleWidget::GoodsSellListTitleWidget(QWidget *parent)
    : QWidget(parent)
    , m_nPixSize(12 * g_heightRate)
{

}

void GoodsSellListTitleWidget::setPixSize( int nPixSize )
{
    m_nPixSize = nPixSize;
    update();
}

void GoodsSellListTitleWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.fillRect(this->rect(), QBrush("#fafafa"));

    QFont font;
    font.setPixelSize( m_nPixSize );
    font.setFamily("微软雅黑");
    painter.setFont(font);
    QPen pen;
    pen.setColor("#666666");
    painter.setPen(pen);
    static const int c_nFirstColWidth = 35 * g_heightRate;
    static const int c_nSecondColWidth = 72 * g_heightRate;
    static const int c_nThirdColWidth = 30 * g_heightRate;
    static const int c_nFourthColWidth = 104 * g_heightRate;
    static const int c_nFifthColWidth = 41 * g_heightRate;
    static const QString c_sFirstColTitle = QStringLiteral("序号");
    static const QString c_sSecondColTitle = QStringLiteral("商品名称");
    static const QString c_sThirdColTitle = QStringLiteral("单价");
    static const QString c_sFourthColTitle = QStringLiteral("数量");
    static const QString c_sFifthColTitle = QStringLiteral("金额");

    int nHeight = this->height();
    int nWidth = this->width();
    int xPos = 0;
    int yPos = 0;
    QRect textRect(xPos, yPos, c_nFirstColWidth, nHeight);
    painter.drawText(textRect, Qt::AlignCenter, c_sFirstColTitle);

    xPos += c_nFirstColWidth;
    QRect textRect2(xPos, yPos, c_nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignCenter, c_sSecondColTitle);

    xPos += c_nSecondColWidth;
    QRect textRect3(xPos, yPos, c_nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignCenter, c_sThirdColTitle);

    xPos += c_nThirdColWidth;
    QRect textRect4(xPos, yPos, c_nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignCenter, c_sFourthColTitle);

    xPos += c_nFourthColWidth;
    QRect textRect5(xPos, yPos, c_nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignCenter, c_sFifthColTitle);

    QPen linePen;
    linePen.setColor("#ededed");
    painter.setPen(linePen);
    painter.drawLine(0, nHeight - 1, nWidth, nHeight - 1);
}
