#include "KPosComboBoxSimple.h"
#include <QPainter>

KPosComboBoxSimple::KPosComboBoxSimple(QWidget *parent)
    : QWidget(parent)
    , m_sContent("")
    , m_sOutLineColor("#ea8852")
    , m_bHasOutline(true)
    , m_nFontSize(14)
{

}

void KPosComboBoxSimple::setContent(QString content)
{
    m_sContent = content;
    update();
}

void KPosComboBoxSimple::setFontSize(int nFontSize)
{
    m_nFontSize = nFontSize;
}

void KPosComboBoxSimple::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    int nWidth = this->width();
    int nHeight = this->height();
    // 区域颜色
    QRect rect(0, 0, nWidth, nHeight);
    if (m_bHasOutline)
    {
        painter.setPen(QPen(QBrush(QColor(m_sOutLineColor)), 2, Qt::SolidLine));//设置画笔形式
    }
    else
    {
        painter.setPen(QPen(QBrush(QColor(m_sOutLineColor)), 2, Qt::NoPen));//设置画笔形式
    }

    painter.setBrush(QBrush("#ffffff"));//设置画刷形式
    painter.drawRect(rect);

    // 区域文字
    int nXPos = 12;
    int nYPos = 0;
    QFont font;
    font.setPixelSize(m_nFontSize);
    font.setFamily("微软雅黑");
    painter.setFont(font);
    QPen pen;
    pen.setColor("#666666");
    painter.setPen(pen);
    QRect textRect(nXPos, nYPos, nWidth, nHeight);
    painter.drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, m_sContent);

    // 勾选
    int nArrowWidth = 9;
    int nArrowHeight = 9;
    int nRightSpace = 6;
    nXPos = nWidth - nArrowWidth - nRightSpace;
    nYPos = (nHeight - nArrowHeight)/2;
    QPixmap selectedPixmap(":/kPosSetImage/dropDownArrow.png");
    QRect selectedRect(nXPos, nYPos, nArrowWidth, nArrowHeight);
    painter.drawPixmap(selectedRect, selectedPixmap);
}

void KPosComboBoxSimple::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    emit sigClicked();
}
