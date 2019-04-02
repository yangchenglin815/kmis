#include "PromotionWidget.h"
#include "ui_PromotionWidget.h"

PromotionWidget::PromotionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PromotionWidget)
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    setAttribute( Qt::WA_ShowModal, true );

    initCtrl();
    initConnect();
}

PromotionWidget::~PromotionWidget()
{
    delete ui;
}

void PromotionWidget::setPromotion( QMap<int, SaleDetails> mapPromotion, bool bPromotion )
{
    hideAllLabel();
    QMap<int, SaleDetails>::iterator it = mapPromotion.begin();
    QList<QLabel*>::iterator itShop = m_listShopping.begin();
    QList<QLabel*>::iterator itGoods = m_listGoods.begin();
    QList<QLabel*>::iterator itStatus = m_listPromotionStatus.begin();

    for( ; it != mapPromotion.end(); ++it ) {
        if( itShop == m_listShopping.end() ) return;
        if( itGoods == m_listGoods.end() ) return;
        if( itStatus == m_listPromotionStatus.end() ) return;

        QString strPos = QString("第%1个商品:").arg( it.key() );
        (*itShop)->setText( strPos );
        (*itGoods)->setText( it.value().goodsInfo.sGoodsName );
        (*itShop)->show();
        (*itGoods)->show();
        if( bPromotion ) {
            (*itStatus)->setText( "已享受" );
            (*itStatus)->show();
        }
        ++itShop;
        ++itGoods;
        ++itStatus;
    }
}

void PromotionWidget::initCtrl()
{
    ui->titleWidget->setTitleText( "促销" );

    m_listShopping.append( ui->shoppingCartLabel_01 );
    m_listShopping.append( ui->shoppingCartLabel_02 );
    m_listShopping.append( ui->shoppingCartLabel_03 );
    m_listShopping.append( ui->shoppingCartLabel_04 );
    m_listShopping.append( ui->shoppingCartLabel_05 );
    m_listShopping.append( ui->shoppingCartLabel_06 );

    m_listGoods.append( ui->goodsNameLabel_01 );
    m_listGoods.append( ui->goodsNameLabel_02 );
    m_listGoods.append( ui->goodsNameLabel_03 );
    m_listGoods.append( ui->goodsNameLabel_04 );
    m_listGoods.append( ui->goodsNameLabel_05 );
    m_listGoods.append( ui->goodsNameLabel_06 );

    m_listPromotionStatus.append( ui->promotionStatusLabel_01 );
    m_listPromotionStatus.append( ui->promotionStatusLabel_02 );
    m_listPromotionStatus.append( ui->promotionStatusLabel_03 );
    m_listPromotionStatus.append( ui->promotionStatusLabel_04 );
    m_listPromotionStatus.append( ui->promotionStatusLabel_05 );
    m_listPromotionStatus.append( ui->promotionStatusLabel_06 );
}

void PromotionWidget::initConnect()
{
    connect( ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT( close() ) );
}

void PromotionWidget::hideAllLabel()
{
    QList<QLabel*>::iterator itShop = m_listShopping.begin();
    for( ; itShop != m_listShopping.end(); ++itShop ) {
        (*itShop)->hide();
    }

    QList<QLabel*>::iterator itGoods = m_listGoods.begin();
    for( ; itGoods != m_listGoods.end(); ++itGoods ) {
        (*itGoods)->hide();
    }

    QList<QLabel*>::iterator itStatus = m_listPromotionStatus.begin();
    for( ; itStatus != m_listPromotionStatus.end(); ++itStatus ) {
        (*itStatus)->hide();
    }
}


