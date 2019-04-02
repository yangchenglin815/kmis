#include "BCSGoodsTitleWidget.h"
#include <QPainter>
#include <QMouseEvent>

int nCheckBoxStartXPos = -1;
int nCheckBoxEndXPos = -1;

BCSGoodsTitleWidget::BCSGoodsTitleWidget(QWidget *parent)
    : QWidget(parent)
    , m_bSelected(false)
{

}

void BCSGoodsTitleWidget::paintEvent(QPaintEvent *event)
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

    static const int c_nFirstColWidth = 100;
    static const int c_nSecondColWidth = 235;
    static const int c_nThirdColWidth = 136;
    static const int c_nFourthColWidth = 138;

    static const QString c_sFirstColTitle = QStringLiteral("商品");
    static const QString c_sSecondColTitle = QStringLiteral("PLU码");
    static const QString c_sThirdColTitle = QStringLiteral("单价");
    static const QString c_sFourthColTitle = QStringLiteral("会员价");


    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;


    // 选择列
    const int checkBoxSideLenght = 16;
    const int nLeftSpace = 30;
    int nSelectBoxXPos = xPos + nLeftSpace;
    int nSelectBoxYPos = yPos + (nHeight - checkBoxSideLenght) / 2;
    QRect selectBoxRect(nSelectBoxXPos, nSelectBoxYPos, checkBoxSideLenght, checkBoxSideLenght);
    QPixmap checkBoxPixmap;
    checkBoxPixmap.load(m_bSelected ? ":/orderGoodsImage/checkBoxPress.png" : ":/orderGoodsImage/checkBoxWithSide.png");
    painter.drawPixmap(selectBoxRect, checkBoxPixmap);
    nCheckBoxStartXPos = nSelectBoxXPos - checkBoxSideLenght; // 扩大些范围
    nCheckBoxEndXPos = nSelectBoxXPos + 2*checkBoxSideLenght; // 扩大些范围

    // 商品
    QRect textRect1(xPos, yPos, c_nFirstColWidth, nHeight);
    painter.drawText(textRect1, Qt::AlignRight | Qt::AlignVCenter, c_sFirstColTitle);

    // PLU码
    xPos += c_nFirstColWidth;
    QRect textRect2(xPos, yPos, c_nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignRight | Qt::AlignVCenter, c_sSecondColTitle);

    // 单价
    xPos += c_nSecondColWidth;
    QRect textRect3(xPos, yPos, c_nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);

    // 会员价
    xPos += c_nThirdColWidth;
    QRect textRect4(xPos, yPos, c_nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignRight | Qt::AlignVCenter, c_sFourthColTitle);
}

void BCSGoodsTitleWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    int x = event->pos().x();
    if ((x >= nCheckBoxStartXPos) && (x <= nCheckBoxEndXPos))
    {
        m_bSelected = !m_bSelected;
        update();
        emit sigSelectBox(m_bSelected);
    }
}

