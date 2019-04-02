#include "CheckOrderCategoryDetailTitleWidget.h"
#include <QPainter>

CheckOrderCategoryDetailTitleWidget::CheckOrderCategoryDetailTitleWidget(QWidget *parent) : QWidget(parent)
{

}

void CheckOrderCategoryDetailTitleWidget::paintEvent(QPaintEvent *event)
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

    static const int c_nFirstColWidth = 86;
    static const int c_nSecondColWidth = 100;
    static const int c_nThirdColWidth = 165;
    static const int c_nFourthColWidth = 162;
    static const int c_nFifthColWidth = 105;
    static const int c_nSixthColWidth = 110;
    static const QString c_sFirstColTitle = QStringLiteral("类别");
    static const QString c_sSecondColTitle = QStringLiteral("单号");
    static const QString c_sThirdColTitle = QStringLiteral("制单时间");
    static const QString c_sFourthColTitle = QStringLiteral("制单人/上传人");
    static const QString c_sFifthColTitle = QStringLiteral("上传时间");
    static const QString c_sSixthColTitle = QStringLiteral("状态");

    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;
    // 类别
    QRect textRect1(xPos, yPos, c_nFirstColWidth, nHeight);
    painter.drawText(textRect1, Qt::AlignRight | Qt::AlignVCenter, c_sFirstColTitle);

    // 单号
    xPos += c_nFirstColWidth;
    QRect textRect2(xPos, yPos, c_nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignRight | Qt::AlignVCenter, c_sSecondColTitle);

    // 制单时间
    xPos += c_nSecondColWidth;
    QRect textRect3(xPos, yPos, c_nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);

    // 制单人/上传人
    xPos += c_nThirdColWidth;
    QRect textRect4(xPos, yPos, c_nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignRight | Qt::AlignVCenter, c_sFourthColTitle);

    // 上传时间
    xPos += c_nFourthColWidth;
    QRect textRect5(xPos, yPos, c_nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFifthColTitle);

    // 状态
    xPos += c_nFifthColWidth;
    QRect textRect6(xPos, yPos, c_nSixthColWidth, nHeight);
    painter.drawText(textRect6, Qt::AlignRight | Qt::AlignVCenter, c_sSixthColTitle);
}
