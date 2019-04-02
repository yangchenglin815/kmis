#include "CategoryGoodsTitleWidget.h"
#include "constData.h"
#include <QPainter>

CategoryGoodsTitleWidget::CategoryGoodsTitleWidget(QWidget *parent) : QWidget(parent)
{

}

void CategoryGoodsTitleWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.fillRect(this->rect(), QBrush("#fafafa"));

    QFont font;
    font.setPixelSize(f_fontSizeMode2);
    font.setFamily(f_fontStyle);
    painter.setFont(font);
    QPen pen;
    pen.setColor("#666666");
    painter.setPen(pen);

    static const int c_nFirstColWidth = 50;
    static const int c_nSecondColWidth = 212;
    static const int c_nThirdColWidth = 80;
    static const int c_nFourthColWidth = 80;
    static const int c_nFifthColWidth = 110;
    static const int c_nSixthColWidth = 82;
    static const QString c_sFirstColTitle = QStringLiteral("商品");
    static const QString c_sSecondColTitle = QStringLiteral("商品条码/PLU码");
    static const QString c_sThirdColTitle = QStringLiteral("原价");
    static const QString c_sFourthColTitle = QStringLiteral("会员价");
    static const QString c_sFifthColTitle = QStringLiteral("称重类型");
    static const QString c_sSixColTitle = QStringLiteral("库存数量");

    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;
    // 商品
    QRect textRect1(xPos, yPos, c_nFirstColWidth, nHeight);
    painter.drawText(textRect1, Qt::AlignRight | Qt::AlignVCenter, c_sFirstColTitle);

    //
    xPos += c_nFirstColWidth;
    QRect textRect2(xPos, yPos, c_nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignRight | Qt::AlignVCenter, c_sSecondColTitle);

    //
    xPos += c_nSecondColWidth;
    QRect textRect3(xPos, yPos, c_nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);

    //
    xPos += c_nThirdColWidth;
    QRect textRect4(xPos, yPos, c_nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignRight | Qt::AlignVCenter, c_sFourthColTitle);

    //
    xPos += c_nFourthColWidth;
    QRect textRect5(xPos, yPos, c_nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFifthColTitle);

    //
    xPos += c_nFifthColWidth;
    QRect textRect6(xPos, yPos, c_nSixthColWidth, nHeight);
    painter.drawText(textRect6, Qt::AlignRight | Qt::AlignVCenter, c_sSixColTitle);
}

