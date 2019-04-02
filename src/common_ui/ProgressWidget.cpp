#include "ProgressWidget.h"
#include <QPainter>

const int c_nTotalValue = 100;

ProgressWidget::ProgressWidget(QWidget *parent)
    : QWidget(parent)
    , m_nProgressValue(0)
{

}

void ProgressWidget::setProgressValue(int progressValue)
{
    m_nProgressValue = progressValue;
    this->update();
}

void ProgressWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    // 绘制商品名称
    QPainter painter(this);
    int nWidth = this->width();
    int nHeight = this->height();

    // 空白进度条
    QRect blankRect(0, 0, nWidth, nHeight);
    QPixmap blankPixmap(":/progressImage/progressBlank.png");
    blankPixmap = blankPixmap.scaled(nWidth, nHeight);
    painter.drawPixmap(blankRect, blankPixmap);

    // 填充进度条
    int nFillWidth = nWidth*m_nProgressValue / c_nTotalValue;
    QRect fillRect(0, 0, nFillWidth, nHeight);
    QPixmap fillPixmap(":/progressImage/progressFill.png");
    fillPixmap = fillPixmap.scaled(nWidth, nHeight);
    fillPixmap = fillPixmap.copy(fillRect);
    painter.drawPixmap(fillRect, fillPixmap);


    QPen pen;
    pen.setColor("#ffffff");
    QFont font;
    font.setPixelSize(14);
    font.setBold(true);
    font.setFamily(QStringLiteral("微软雅黑"));
    painter.setPen(pen);
    painter.setFont(font);

    int nTextWidth = 50;
    QRect textRect(nWidth - nTextWidth, 0, nTextWidth, nHeight);
    painter.drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, QString("%1%").arg(m_nProgressValue));
}
