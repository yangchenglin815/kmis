#include "TitleMemberWidget.h"
#include "constData.h"
#include <QPainter>
#include <QMouseEvent>

int mCheckBoxStartXPos = -1;
int mCheckBoxEndXPos = -1;


TitleMemberWidget::TitleMemberWidget(QWidget *parent)
 : QWidget(parent)
 , m_bSelected(false)
{

}

void TitleMemberWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.fillRect(this->rect(), QBrush("#fafafa"));

    QFont font;
    font.setPixelSize(f_fontSizeMode2*g_widthRate);
    font.setFamily(f_fontStyle);
    painter.setFont(font);
    QPen pen;
    pen.setColor("#666666");
    painter.setPen(pen);

    //总计7个纵排
    static const int c_nFirstColWidth = 48*g_widthRate;
    static const int c_nSecondColWidth = 48*g_widthRate;
    static const int c_nThirdColWidth = 101*g_widthRate;
    static const int c_nFourthColWidth = 132*g_widthRate;
    static const int c_nFiveColWidth = 132*g_widthRate;
    static const int c_nSixColWidth = 128*g_widthRate;
    static const int c_nSevenColWidth = 128*g_widthRate;

    static const QString c_sSecondColTitle = QString::fromUtf8("序号");
    static const QString c_sThirdColTitle = QString::fromUtf8("员工工号");
    static const QString c_sFourthColTitle = QString::fromUtf8("员工名称");
    static const QString c_sFiveColTitle = QString::fromUtf8("手机号码");
    static const QString c_sSixColTitle = QString::fromUtf8("角色");
    static const QString c_sSevenColTitle = QString::fromUtf8("状态");

    int nHeight = this->height();
    int xPos = 0;
    int yPos = 0;

    // 选择列
    const int checkBoxSideLenght = 16*g_widthRate;
    const int nLeftSpace = 30*g_widthRate;
    int nSelectBoxXPos = xPos + nLeftSpace;
    int nSelectBoxYPos = yPos + (nHeight - checkBoxSideLenght) / 2;
    QRect selectBoxRect(nSelectBoxXPos, nSelectBoxYPos, checkBoxSideLenght, checkBoxSideLenght);
    QPixmap checkBoxPixmap;
    checkBoxPixmap.load(m_bSelected ? ":/orderGoodsImage/checkBoxPress.png" : ":/orderGoodsImage/checkBoxWithSide.png");
    painter.drawPixmap(selectBoxRect, checkBoxPixmap);
    mCheckBoxStartXPos = nSelectBoxXPos - checkBoxSideLenght; // 扩大些范围
    mCheckBoxEndXPos = nSelectBoxXPos + 2*checkBoxSideLenght; // 扩大些范围

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

    xPos += c_nFourthColWidth;
    QRect textRect5(xPos, yPos, c_nFiveColWidth, nHeight);
    painter.drawText(textRect5, Qt::AlignRight | Qt::AlignVCenter, c_sFiveColTitle);

    xPos += c_nFiveColWidth;
    QRect textRect6(xPos, yPos, c_nSixColWidth, nHeight);
    painter.drawText(textRect6, Qt::AlignRight | Qt::AlignVCenter, c_sSixColTitle);

    xPos += c_nSixColWidth;
    QRect textRect7(xPos, yPos, c_nSevenColWidth, nHeight);
    painter.drawText(textRect7, Qt::AlignRight | Qt::AlignVCenter, c_sSevenColTitle);

}

void TitleMemberWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    int x = event->pos().x();
    if ((x >= mCheckBoxStartXPos) && (x <= mCheckBoxEndXPos))
    {
        m_bSelected = !m_bSelected;
        update();
        emit sigSelectBox(m_bSelected);
    }
}

