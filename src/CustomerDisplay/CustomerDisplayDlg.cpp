#include "CustomerDisplayDlg.h"
#include "ui_CustomerDisplayDlg.h"

CustomerDisplayDlg::CustomerDisplayDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CustomerDisplayDlg)
{
    ui->setupUi(this);

    setWindowIcon( QIcon( ":/shareImages/kpos_logo.png" ) );
    setWindowFlags( Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint );//去掉标题栏,并置顶

    initCtrl();
}

CustomerDisplayDlg::~CustomerDisplayDlg()
{

    delete ui;
}

void CustomerDisplayDlg::setRemoteAdList(QList<QString> remoteAdList)
{
    ui->StandbyADPage->setFileList(remoteAdList);
    ui->SaleADPage->setFileList(remoteAdList);
}

void CustomerDisplayDlg::setCurrentIndex( int nIndex )
{
    ui->stackedWidget->setCurrentIndex( nIndex );
    if( nIndex == 0 ) {
        ui->StandbyADPage->startTimer();
    } else {
        ui->StandbyADPage->stopTimer();
    }
}

void CustomerDisplayDlg::addGoodsToSaleList( SaleDetails stSaleDetailsInfo )
{
    //1. add
    //2. update
    //如果add是第一个，则显示为setCurrentIndex( 1 );
    if( ui->SaleADPage->getSaleDetailsNum() == 0 ) {
        setCurrentIndex( 1 );
    }
    ui->SaleADPage->addGoodsToSaleList( stSaleDetailsInfo );
}

void CustomerDisplayDlg::delGoodsToSaleList( int nSaleDetailsPos )
{
    //如果删除的是最后一个商品，则客显显示为待机
    ui->SaleADPage->delGoodsToSaleList( nSaleDetailsPos );

    if( ui->SaleADPage->getSaleDetailsNum() == 0 ) {
        setCurrentIndex( 0 );
    }
}

void CustomerDisplayDlg::clearGoodsToSaleList()
{
    ui->SaleADPage->clearGoodsToSaleList();
    setCurrentIndex( 0 );
}

void CustomerDisplayDlg::loginMember( bool bMember )
{
    ui->SaleADPage->loginMember( bMember );
}


void CustomerDisplayDlg::initCtrl()
{

}
