#include "GoodsCellButton.h"
#include <QPainter>
#include "../util/GlobalSignal.h"
#include "../KPosSet/AdjustPositionWidget.h"

static const int c_nAllTextWidth = 100;
static const int c_nAllTextHeight = 60;
int gnGoodsNameHeight = 14;
static const int c_nGoodsNameVSpace = 4; // 两行商品名之间的文字间距
static const int c_nGoodsPriceHeight = 12;
static const int c_nGoodsNameAndPriceSpace = 10;

GoodsCellButton::GoodsCellButton(QWidget *parent)
    : QPushButton(parent)
    , m_bSelected(false)
    , m_nGoodsId( -1 )
    , m_sBarCode( "" )
    , m_nGoodsWidgetType( e_goodsSale )
    , m_nPixSize( 12 )
    , m_sGoodsName("")
    , m_sPriceName("")
    , m_nGoodsPosition(-1)
    , m_bDbClick(false)
{
    initConnect();
}

void GoodsCellButton::setGoodsInfo(QString strGoodsName, QString strPriceName, QString strBarCode, int nGoodsId , int nGoodsPosition)
{
    m_sGoodsName = strGoodsName;
    m_sPriceName = strPriceName;
    m_sBarCode = strBarCode;
    m_nGoodsId = nGoodsId;
    m_nGoodsPosition = nGoodsPosition;
}

void GoodsCellButton::setSelectedSelf()
{
    m_bSelected = true;
//    if (m_nGoodsWidgetType == e_goodsSet)
//    {
//        this->setStyleSheet("QPushButton{border-image: url(:/saleImage/goods_btn_press.png);}");
//    }
}

void GoodsCellButton::setUnSelectedSelf()
{
    m_bSelected = false;
//    if (m_nGoodsWidgetType == e_goodsSet)
//    {
//        this->setStyleSheet("QPushButton{border-image: url(:/saleImage/goods_btn_normal.png);}");
//    }
}

void GoodsCellButton::setGoodsWidget(int nGoodsWidgetType)
{
    m_nGoodsWidgetType = nGoodsWidgetType;
}

void GoodsCellButton::setFontSize( int nPixSize )
{
    m_nPixSize = nPixSize;
    update();
}

int GoodsCellButton::getGoodsId()
{
    return m_nGoodsId;
}

void GoodsCellButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);
    // 绘制商品名称
    QPainter goodsNamePainter(this);
    QPen pen;
    pen.setColor("#333333");
    QFont font;
//    m_nPixSize = 8;
    font.setPixelSize( m_nPixSize );
    font.setBold(true);
    font.setFamily(QStringLiteral("微软雅黑"));
    goodsNamePainter.setPen(pen);
    goodsNamePainter.setFont(font);

    gnGoodsNameHeight = m_nPixSize +2;

    const int nFirstGoodsNameXPos = 4;//(this->width() - c_nAllTextWidth)/2;
    const int nFirstGoodsNameYPos = (this->height() - c_nAllTextHeight)/2;
    const int nSecondGoodsNameXPos = nFirstGoodsNameXPos;
    const int nSecondGoodsNameYPos = nFirstGoodsNameYPos + gnGoodsNameHeight + c_nGoodsNameVSpace;
    const int nThirdGoodsNameXPos = nFirstGoodsNameXPos;
    const int nThirdGoodsNameYPos = nSecondGoodsNameYPos + gnGoodsNameHeight + c_nGoodsNameVSpace;
    QRect textRecFirstRow(nFirstGoodsNameXPos, nFirstGoodsNameYPos, this->width()-nFirstGoodsNameXPos, gnGoodsNameHeight);
    QRect textRecSecondRow(nSecondGoodsNameXPos, nSecondGoodsNameYPos, this->width()-nFirstGoodsNameXPos, gnGoodsNameHeight);
    QRect textRecThirdRow( nThirdGoodsNameXPos, nThirdGoodsNameYPos, this->width()-nFirstGoodsNameXPos, gnGoodsNameHeight );

    QString showContentFirstRow = goodsNamePainter.fontMetrics().elidedText(m_sGoodsName, Qt::ElideRight, this->width()-nFirstGoodsNameXPos );
    showContentFirstRow = m_sGoodsName.left(showContentFirstRow.length());

    QString showContentSecondRow = goodsNamePainter.fontMetrics().elidedText(m_sGoodsName.right(m_sGoodsName.length()-showContentFirstRow.length()), Qt::ElideRight, this->width()-nFirstGoodsNameXPos);
    showContentSecondRow = m_sGoodsName.mid(showContentFirstRow.length(), showContentSecondRow.length() );

    QString showContentThirdRow = m_sGoodsName.right( m_sGoodsName.length() - showContentSecondRow.length() - showContentFirstRow.length() );

    goodsNamePainter.drawText(textRecFirstRow, Qt::AlignLeft | Qt::AlignVCenter, showContentFirstRow);
    goodsNamePainter.drawText(textRecSecondRow, Qt::AlignLeft | Qt::AlignVCenter, showContentSecondRow);
    goodsNamePainter.drawText( textRecThirdRow, Qt::AlignLeft | Qt::AlignVCenter, showContentThirdRow);

    // 绘制商品价格
    QPainter goodsPricePainter(this);
    QPen pen2;
    pen2.setColor("#333333");
    QFont font2;
    font2.setPixelSize( m_nPixSize );
    font2.setFamily(QStringLiteral("微软雅黑"));
    goodsPricePainter.setPen(pen2);
    goodsPricePainter.setFont(font2);
    const int nGoodsPriceNameXpos = 3;

    int nGoodsPriceNameYPos =0 ;
//    if( showContentThirdRow.isEmpty() ) {
//        nGoodsPriceNameYPos = nSecondGoodsNameYPos + gnGoodsNameHeight + c_nGoodsNameAndPriceSpace;
//    } else {
        nGoodsPriceNameYPos = nThirdGoodsNameYPos + gnGoodsNameHeight;// + gnGoodsNameHeight + c_nGoodsNameAndPriceSpace;
//    }
    QRect goodsPriceTextRec(nGoodsPriceNameXpos, nGoodsPriceNameYPos, this->width()-nGoodsPriceNameXpos*2, c_nGoodsPriceHeight);
    goodsPricePainter.drawText(goodsPriceTextRec, Qt::AlignRight | Qt::AlignVCenter, m_sPriceName);
}

void GoodsCellButton::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    if (m_nGoodsWidgetType != e_goodsSet)
    {
        return;
    }
    m_bDbClick = true;
    AdjustPositionWidget::instance()->hide();
}

void GoodsCellButton::initConnect()
{
    connect(this, SIGNAL(clicked()), this, SLOT(slot_onClicked()));
    connect(GlobalSignal::instance(), SIGNAL(sigGoodsCellButtonClicked(QString, GoodsWidgetType)),
            this, SLOT(slot_otherGoodsCellButtonClicked(QString, GoodsWidgetType)));
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(slot_checkClickType()));
}

void GoodsCellButton::showAdjustWidget()
{
    if (m_nGoodsWidgetType != e_goodsSet)
    {
        return;
    }
    emit GlobalSignal::instance()->sigGoodsCellMovePosition(m_nGoodsPosition);
//    QPoint globalPos = this->mapFromGlobal(QPoint(0,0));

//    AdjustPositionWidget *pInstance = AdjustPositionWidget::instance();
//    int nAdjustWidgetWidth = pInstance->width();
//    const int nArrowHeight = 9;
//    int nXPos = (-globalPos.x()) - (nAdjustWidgetWidth - this->width())/2;
//    int nYPos = (-globalPos.y()) + this->height() - nArrowHeight;
//    pInstance->setPosition(m_nGoodsPosition);
//    pInstance->setOwnerType(m_nGoodsWidgetType);
//    pInstance->move(nXPos, nYPos);
//    pInstance->activateWindow();
//    pInstance->showNormal();
}

void GoodsCellButton::slot_onClicked()
{
    if (!m_sGoodsName.isEmpty())
    {
        if (m_nGoodsWidgetType == e_goodsSet)
        {
            AdjustPositionWidget::instance()->hide();
            m_timer.start(500);
        }
        setSelectedSelf();
        GlobalSignal::instance()->sigGoodsCellButtonClicked( m_sBarCode, (GoodsWidgetType)m_nGoodsWidgetType);
    }
    else
    {
//        if (m_nGoodsWidgetType == e_goodsSet)
//        {
//            this->setStyleSheet("QPushButton{border-image: url(:/saleImage/goods_category_btn_normal.png);}");
//        }
    }
}

void GoodsCellButton::slot_otherGoodsCellButtonClicked(QString strBarCode, GoodsWidgetType goodsWidgetType)
{
    if(m_nGoodsWidgetType != goodsWidgetType) return;

    if(m_bSelected && m_sBarCode != strBarCode)
    {
        setUnSelectedSelf();
    }
}

void GoodsCellButton::slot_checkClickType()
{
    m_timer.stop();
    if (m_bDbClick)
    {
        m_bDbClick = false;
        return;
    }

    showAdjustWidget();
}

