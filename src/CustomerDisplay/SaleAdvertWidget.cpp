#include "SaleAdvertWidget.h"
#include "ui_SaleAdvertWidget.h"
#include <QFontDatabase>
#include "CommonFun.h"
#include "ScreenInfo.h"

SaleAdvertWidget::SaleAdvertWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SaleAdvertWidget)
{
    ui->setupUi(this);
    ScreenInfo::resetGrid(this);
    ui->platformValueLabel->setText( "00.000" );//测试

    connect(BalanceManage::instance(), SIGNAL(sig_stableInfo(EBalanceStandard_Ex,bool)), this, SLOT(slot_stableInfo(EBalanceStandard_Ex,bool)));
}

SaleAdvertWidget::~SaleAdvertWidget()
{
    delete ui;
}

void SaleAdvertWidget::addGoodsToSaleList( SaleDetails stSaleDetailsInfo )
{
    //如果是标品，并且已经存在，则更新；否则，则新增
    if( stSaleDetailsInfo.goodsInfo.bStandard ) {
        bool bHas = ui->CustomerSaleListWidget->isGoods( stSaleDetailsInfo.nGoodsId );
        if( bHas ) {
            ui->CustomerSaleListWidget->updateGoodsToSaleList( stSaleDetailsInfo );
        } else {
            ui->CustomerSaleListWidget->addGoodsToSaleList( stSaleDetailsInfo );
        }
    } else {
        ui->CustomerSaleListWidget->addGoodsToSaleList( stSaleDetailsInfo );
    }

    updateAddGoodsInfo( stSaleDetailsInfo );
}

void SaleAdvertWidget::delGoodsToSaleList( int nSaleDetailsPos )
{
    ui->CustomerSaleListWidget->delGoodsToSaleList( nSaleDetailsPos );
}

void SaleAdvertWidget::clearGoodsToSaleList()
{
    ui->CustomerSaleListWidget->clearGoodsToSaleList();
}

void SaleAdvertWidget::loginMember( bool bMember )
{
    ui->CustomerSaleListWidget->loginMember( bMember );
}

int SaleAdvertWidget::getSaleDetailsNum()
{
    return ui->CustomerSaleListWidget->getSaleDetailsNum();
}

void SaleAdvertWidget::setFileList(QList<QString> adList)
{
    ui->advertImageWidget->setFileList(adList);
}

void SaleAdvertWidget::slot_stableInfo( EBalanceStandard_Ex balanceStandard_Ex, bool bStable )
{
    Q_UNUSED( bStable )

    QString strWeight = balanceStandard_Ex.sWeight.left( balanceStandard_Ex.sWeight.length() - 1 );
    ui->platformValueLabel->setText( strWeight );
}

void SaleAdvertWidget::updateAddGoodsInfo( SaleDetails stSaleDetailsInfo )
{
    QString strName = "";
    if( stSaleDetailsInfo.goodsInfo.strGoodsShortName.isEmpty() ) {
        strName = stSaleDetailsInfo.strGoodsName;
    } else {
        strName = stSaleDetailsInfo.goodsInfo.strGoodsShortName;
    }

    ui->goodsNameValueLabel->setText( strName );
    QString strPrice = CommonFun::floatToString( stSaleDetailsInfo.goodsInfo.fPrice );
    ui->goodsPriceValueLabel->setText( strPrice );
    QString strNum = "";
    strNum.sprintf( "%.3f", stSaleDetailsInfo.goodsInfo.fNumber );
    ui->goodsNumValueLabel->setText( strNum );
    ui->goodsAmtValueLabel->setText( stSaleDetailsInfo.goodsInfo.sSumPrice );
}
