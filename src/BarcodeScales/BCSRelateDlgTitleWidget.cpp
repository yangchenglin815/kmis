#include "BCSRelateDlgTitleWidget.h"
#include <QPainter>
#include <QMouseEvent>

static int nCheckBoxStartXPos = -1;
static int nCheckBoxEndXPos = -1;

BCSRelateDlgTitleWidget::BCSRelateDlgTitleWidget(QWidget *parent)
    : QWidget(parent)
    , m_bSelected(false)
{

}

void BCSRelateDlgTitleWidget::paintEvent(QPaintEvent *event)
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

    static const int c_nFirstColWidth = 46;
    static const int c_nSecondColWidth = 54;
    static const int c_nThirdColWidth = 54;
    static const int c_nFourthColWidth = 84;
    static const int c_nFifthColWidth = 131;
    static const int c_sSixthColWidth = 184;

    static const QString c_sFirstColTitle = QStringLiteral("选择");
    static const QString c_sSecondColTitle = QStringLiteral("序号");
    static const QString c_sThirdColTitle = QStringLiteral("编号");
    static const QString c_sFourthColTitle = QStringLiteral("型号");
    static const QString c_sFifthColTitle = QStringLiteral("IP");
    static const QString c_sSixthColTitle = QStringLiteral("状态");


    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;
    // 选择
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

//    QRect textRect1(xPos, yPos, c_nFirstColWidth, nHeight);
//    painter.drawText(textRect1, Qt::AlignRight | Qt::AlignVCenter, c_sFirstColTitle);

    // 序号
    xPos += c_nFirstColWidth;
    QRect textRect2(xPos, yPos, c_nSecondColWidth, nHeight);
    painter.drawText(textRect2, Qt::AlignRight | Qt::AlignVCenter, c_sSecondColTitle);

    // 编号
    xPos += c_nSecondColWidth;
    QRect textRect3(xPos, yPos, c_nThirdColWidth, nHeight);
    painter.drawText(textRect3, Qt::AlignRight | Qt::AlignVCenter, c_sThirdColTitle);

    // 型号
    xPos += c_nThirdColWidth;
    QRect textRect4(xPos, yPos, c_nFourthColWidth, nHeight);
    painter.drawText(textRect4, Qt::AlignRight | Qt::AlignVCenter, c_sFourthColTitle);

    // IP
    xPos += c_nFourthColWidth;
    QRect textRect5(xPos, yPos, c_nFifthColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFifthColTitle);

    // 状态
    xPos += c_nFifthColWidth;
    QRect textRect6(xPos, yPos, c_sSixthColWidth, nHeight);
    painter.drawText(textRect6, Qt::AlignRight | Qt::AlignVCenter, c_sSixthColTitle);
}

void BCSRelateDlgTitleWidget::mousePressEvent(QMouseEvent *event)
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

