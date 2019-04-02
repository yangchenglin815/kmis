#include "PressKeyWidget.h"
#include "GlobalSignal.h"
#include "EnumToString.h"
#include <QPainter>
#include <QMouseEvent>

enum LayerType
{
    e_nullLayer,
    e_eyeLayer,
    e_grayLayer,
};

static int nStartX = 0;
static const int c_nEyeWidth = 23;
static const int c_nEyeHeight = 20;

PressKeyWidget::PressKeyWidget(QWidget *parent)
    : QWidget(parent)
    , m_nFirstLayerType(e_eyeLayer)
    , m_nSecondLayerType(e_nullLayer)
    , m_sContent("NULL")
    , m_bEyeOpen(true)
    , m_nPosition(-1)
{

}

void PressKeyWidget::addEye()
{
    m_nFirstLayerType = e_eyeLayer;
    m_nSecondLayerType = e_nullLayer;
    this->update();
}

void PressKeyWidget::addEye_Gray()
{
    m_nFirstLayerType = e_eyeLayer;
    m_nSecondLayerType = e_grayLayer;
    this->update();
}

void PressKeyWidget::addGray_Eye()
{
    m_nFirstLayerType = e_grayLayer;
    m_nSecondLayerType = e_eyeLayer;
    this->update();
}

void PressKeyWidget::setContent(int nKeyId)
{
    m_nKeyId = nKeyId;
    m_sContent = EnumToString::keySetTypeToString(nKeyId);
    this->update();
}

void PressKeyWidget::setEyeState(bool bOpen)
{
    m_bEyeOpen = bOpen;
    this->update();
}

void PressKeyWidget::setPosition(int nPos)
{
    m_nPosition = nPos;
}

int PressKeyWidget::getKeyId()
{
    return m_nKeyId;
}

bool PressKeyWidget::isEyeOpen()
{
    return m_bEyeOpen;
}

void PressKeyWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    int nWidth = this->width();
    int nHeight = this->height();

    QPixmap normalRectImage(":/kPosSetImage/normalRect.png");
    painter.drawPixmap(this->rect(), normalRectImage);

    // 区域文字
    QFont font;
    font.setPixelSize(12);
    font.setFamily("微软雅黑");
    painter.setFont(font);
    QPen pen;
    pen.setColor("#ffffff");
    painter.setPen(pen);
    QRect textRect(0, 0, nWidth, nHeight);
    painter.drawText(textRect, Qt::AlignHCenter | Qt::AlignVCenter, m_sContent);

    if (m_nFirstLayerType == e_eyeLayer)
    {
        paintEyeImage(painter, this->rect());
    }
    else if (m_nFirstLayerType == e_grayLayer)
    {
        paintGrayRectImage(painter, this->rect());
    }

    if (m_nSecondLayerType == e_eyeLayer)
    {
        paintEyeImage(painter, this->rect());
    }
    else if (m_nSecondLayerType == e_grayLayer)
    {
        paintGrayRectImage(painter, this->rect());
    }
}

void PressKeyWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    QRect eyeRect(nStartX, 0, c_nEyeWidth, c_nEyeHeight);
    if (eyeRect.contains(event->pos()))
    {
        m_bEyeOpen = !m_bEyeOpen;
        if (m_bEyeOpen)
        {
            addEye();
        }
        else
        {
            addGray_Eye();
        }
    }
}

void PressKeyWidget::paintGrayRectImage(QPainter &painter, const QRect& rect)
{
    QPixmap sImagePath(":/kPosSetImage/grayRect.png");
    painter.drawPixmap(rect, sImagePath);
}

void PressKeyWidget::paintEyeImage(QPainter &painter, const QRect &rect)
{
    QString sImagePath = "";
    if (m_bEyeOpen)
    {
        sImagePath = ":/kPosSetImage/openEye.png";
    }
    else
    {
        sImagePath = ":/kPosSetImage/closeEye.png";
    }
    QPixmap pixmap(sImagePath);
    nStartX = rect.width() - c_nEyeWidth;
    painter.drawPixmap(nStartX, 0, c_nEyeWidth, c_nEyeHeight, pixmap);
}
