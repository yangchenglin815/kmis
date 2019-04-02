#include "KPosComboBox.h"
#include "../util/GlobalSignal.h"
#include <QPainter>
#include <QDebug>

KPosComboBox::KPosComboBox(QWidget *parent)
    : QWidget(parent)
    , m_pStringListWidget(NULL)
    , m_sContent("")
    , m_sOutLineColor("#ea8852")
    , m_bHasOutline(true)
    , m_nFontSize(12)
{
    m_pStringListWidget = new StringListWidget;
    connect(m_pStringListWidget, SIGNAL(sigClicked(QString)), this, SLOT(slot_clicked(QString)));
}

KPosComboBox::~KPosComboBox()
{
    if (m_pStringListWidget != NULL)
    {
        m_pStringListWidget->deleteLater();
    }
}

void KPosComboBox::setListWidgetPosition(QPoint globalPoint)
{
    if (m_pStringListWidget != NULL)
    {
        m_pStringListWidget->move(globalPoint);
    }
}

void KPosComboBox::initListWidget(QList<QString> strList)
{
    if (m_pStringListWidget != NULL)
    {
        m_pStringListWidget->initData(strList, this->height(), this->width());
    }
}

void KPosComboBox::initListWidget(QList<QString> strList, int nItemHeight)
{
    if (m_pStringListWidget != NULL)
    {
        m_pStringListWidget->initData(strList, nItemHeight, this->width());
    }
}

void KPosComboBox::setContent(QString sContent)
{
    m_sContent = sContent;
    update();
}

QString KPosComboBox::getContent()
{
    return m_sContent;
}

void KPosComboBox::setOutline(bool bHasOutline, QString sColor)
{
    m_bHasOutline = bHasOutline;
    m_sOutLineColor = sColor;
}

void KPosComboBox::hideListWidget()
{
    if (m_pStringListWidget != NULL)
    {
        m_pStringListWidget->hide();
    }
}

void KPosComboBox::setFontSize(int nFontSize)
{
    m_nFontSize = nFontSize;
    if (m_pStringListWidget != NULL)
    {
        m_pStringListWidget->setFontSize(nFontSize);
    }
}

void KPosComboBox::paintEvent(QPaintEvent *event)
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

    painter.setBrush(QBrush("#f6f6f6"));//设置画刷形式
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

void KPosComboBox::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    if (m_pStringListWidget == NULL)
    {
        return;
    }
    if (m_pStringListWidget->isActiveWindow())
    {
        m_pStringListWidget->hide();
    }
    else
    {
        QPoint globalPoint = this->mapToGlobal(QPoint(0, 0));
        globalPoint.setY(globalPoint.y() + this->height());
        setListWidgetPosition(globalPoint);
        m_pStringListWidget->activateWindow();
        m_pStringListWidget->showNormal();
    }
}

void KPosComboBox::slot_clicked(QString sContent)
{
    setContent(sContent);
    if (m_pStringListWidget != NULL)
    {
        m_pStringListWidget->hide();
    }
    emit sigClicked();
}
