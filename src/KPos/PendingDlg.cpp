#include "PendingDlg.h"
#include "ui_PendingDlg.h"
#include "SaleHeadAgent.h"
#include "SaleDetailsAgent.h"

#include <QDebug>

int gnArrowFirstHeight = 94;

PendingDlg::PendingDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PendingDlg)
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint );
    setModal( true );
    init();
    initConnect();
    setWindowTitle("挂单解单");
}

PendingDlg::~PendingDlg()
{
    delete ui;
}

void PendingDlg::initData()
{
    //加载数据库中，状态为挂载的销售信息
    m_mapSaleHead.clear();
    ui->goodsSellListWidget->clearGoodsInfo();
    SaleHeadAgent::Instance()->findStatusToSaleHead( e_headPending, m_mapSaleHead );
    ui->pendingListWidget->initData( m_mapSaleHead );
    emit sig_pendingChanged();
}

void PendingDlg::slot_selectSaleHead( const QString &strOrderNum, int nPosition )
{
    //向销售明细表中加载销售明细信息
    QList< SaleDetails > listSaleDetails;//key:销售明细id
    SaleDetailsAgent::Instance()->findSaleDetails( strOrderNum, listSaleDetails );

    ui->goodsSellListWidget->clearGoodsInfo();
    QList< SaleDetails >::iterator itSale = listSaleDetails.begin();
    for( ; itSale != listSaleDetails.end(); ++itSale ) {
        itSale->goodsInfo.bSelectStatus = false;
        ui->goodsSellListWidget->addGoodsInfo( *itSale, false );//const SaleDetails&
    }

    setArrowPosition( nPosition );
}

void PendingDlg::slot_unPending( const QString &strOrderNum )
{
    SaleHeadAgent::Instance()->updateStatus( strOrderNum, e_headSelling );
    emit sig_addSaleHead( strOrderNum );
    emit sig_pendingChanged();
}

void PendingDlg::slot_deleteOrder( const QString &strOrderNum, bool bSelect )
{
    SaleHeadAgent::Instance()->updateStatus( strOrderNum, e_headCancel );
    QDateTime dt = QDateTime::currentDateTime();
    SaleHeadAgent::Instance()->updateCompleteTime( strOrderNum, dt );

    QMap< int, SaleHead >::iterator it = m_mapSaleHead.begin();
    for( ; it != m_mapSaleHead.end(); ++it ) {
        if( it.value().strOrderNum == strOrderNum ) {
            m_mapSaleHead.erase( it );
            break;
        }
    }

    if( bSelect ) {
        ui->goodsSellListWidget->clearGoodsInfo();
    }

    emit sig_pendingChanged();
}

void PendingDlg::slot_clearOrder()
{
    QMap< int, SaleHead >::iterator it = m_mapSaleHead.begin();
    for( ; it != m_mapSaleHead.end(); ++it ) {
        SaleHeadAgent::Instance()->updateStatus( it.value().strOrderNum, e_headCancel );
        QDateTime dt = QDateTime::currentDateTime();
        SaleHeadAgent::Instance()->updateCompleteTime( it.value().strOrderNum, dt );
    }
    m_mapSaleHead.clear();
    ui->goodsSellListWidget->clearGoodsInfo();
    ui->pendingListWidget->init();
    emit sig_pendingChanged();
}

void PendingDlg::init()
{
    ui->titleWidget->setTitleText(QStringLiteral("解单挂单"));
    ui->pendingListWidget->setTitleMinHeight(36);

    ui->goodsSellListWidget->setSelectStatus( false );
}

void PendingDlg::initConnect()
{
    connect( ui->pendingListWidget, SIGNAL(sig_selectSaleHead(const QString&,int)), this, SLOT( slot_selectSaleHead( const QString&,int) ) );
    connect( ui->pendingListWidget, SIGNAL(sig_unPending(const QString &)), this, SLOT( slot_unPending( const QString & ) ) );
    connect( ui->pendingListWidget, SIGNAL( sig_deleteOrder(const QString&, bool)), this, SLOT( slot_deleteOrder(const QString&, bool) ) );
    connect( ui->clearButton, SIGNAL( clicked()), this, SLOT( slot_clearOrder() ) );
    connect( ui->titleWidget, SIGNAL(sig_close_wnd()), this, SIGNAL( sig_hideDlg() ) );
}

void PendingDlg::setArrowPosition( int nPosition )
{
    int nArrowHeight = ui->arrowLabel->height();
    int nItemHeight = ui->pendingListWidget->getItemHeight();
    int nMoveHeight =  (nItemHeight - nArrowHeight)/2;
    ui->arrowLabel->move( ui->arrowLabel->x(), gnArrowFirstHeight + nPosition*nItemHeight + nMoveHeight );
}
