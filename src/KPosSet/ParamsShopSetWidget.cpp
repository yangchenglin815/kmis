#include "ParamsShopSetWidget.h"
#include <QPainter>

ParamsShopSetWidget::ParamsShopSetWidget(QWidget *parent)
    : QWidget(parent)
    , m_nRowCount(6)
{

}

void ParamsShopSetWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    int nWidth = this->width();
    int nHeight = this->height();
    QPainter painter(this);
    QPen pen;
    pen.setColor("#e1e1e1");
    painter.setPen(pen);
    painter.drawRect(0,0,nWidth-1,nHeight-1);


    int nItemHeight = nHeight/m_nRowCount;
    for (int i = 1; i < m_nRowCount; i++)
    {
        painter.drawLine(0, nItemHeight*i, nWidth, nItemHeight*i);
    }

    painter.drawLine(nWidth/2, nItemHeight, nWidth/2, nItemHeight*4);
}

