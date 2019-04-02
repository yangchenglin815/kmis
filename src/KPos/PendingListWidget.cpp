#include "PendingListWidget.h"
#include "ui_PendingListWidget.h"


PendingListWidget::PendingListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PendingListWidget)
  , m_nCurPageNum( 1 )
  , m_nTotalPageNum( 1 )
  , m_nOnePageCount( 5 )
{
    ui->setupUi(this);
    init();
    initConnect();
}

PendingListWidget::~PendingListWidget()
{
    delete ui;
}

void PendingListWidget::setTitleMinHeight(int minHeight)
{
    ui->titleWidget->setMinimumHeight(minHeight);
}

void PendingListWidget::initData( QMap<int, SaleHead> &mapSaleHead )
{
    init();

    //逆序显示
    QMap< int, SaleHead >::iterator it = mapSaleHead.begin();
    for( ; it != mapSaleHead.end(); ++it ) {
        OrderInfo *pOrderInfo = new OrderInfo;
        pOrderInfo->sOrderSequence = it.value().strOrderNum;
        pOrderInfo->sCreateTime = it.value().dtFactorTime.toString( "MM-dd hh:mm:ss" );
        m_orderList.push_front( pOrderInfo );
    }
    generateSellList();

    //默认显示第一行的销售和销售明细
    showFirstPending();

    int nNum = mapSaleHead.size();
    m_nTotalPageNum = getPageNum( nNum );
    setCurPage( m_nCurPageNum, m_nTotalPageNum );
}

int PendingListWidget::getItemHeight()
{
    return ui->listView->getItemHeight();
}

void PendingListWidget::slot_unPending( QString strOrderNum )
{
    emit sig_unPending( strOrderNum );
}

void PendingListWidget::slot_deleteOrder( QString strOrderNum )
{
    bool bSelect = false;
    QList<OrderInfo *>::iterator itOrder = m_orderList.begin();
    for( ; itOrder != m_orderList.end(); ++itOrder ) {
        if( (*itOrder)->sOrderSequence == strOrderNum ) {
            if( (*itOrder)->bSelect ) {
                 bSelect = true;
            }
            OrderInfo *pOrder = *itOrder;
            ui->listView->removeItem( strOrderNum );
            emit sig_deleteOrder( strOrderNum, bSelect );
            m_orderList.erase( itOrder );
            if( pOrder ) {
                delete pOrder;
                pOrder = NULL;
            }
            break;
        }
    }

    if( m_nCurPageNum < m_nTotalPageNum ) {
        if( m_orderList.size()%m_nOnePageCount == 0 ) {
            m_nTotalPageNum -= 1;
            setCurPage( m_nCurPageNum, m_nTotalPageNum );
        }
    } else if( m_nCurPageNum == m_nTotalPageNum ) {
        if( ui->listView->getItemsNum() < 1 && m_nCurPageNum > 1 ) {
            m_nCurPageNum -= 1;
            m_nTotalPageNum = m_nCurPageNum;
            setCurPage( m_nCurPageNum, m_nTotalPageNum );
        }
    }
    generateSellList();

    if( bSelect ) {
        showFirstPending();
    }
}

void PendingListWidget::slot_selectPending( OrderInfo rInfo )
{
    QList<OrderInfo *>::iterator itOrder = m_orderList.begin();
    for( ; itOrder != m_orderList.end(); ++itOrder ) {
        if( (*itOrder)->bSelect ) {
            (*itOrder)->bSelect = false;
            if( ui->listView->findItem( (*itOrder)->sOrderSequence) ) {
                ui->listView->appendItem( **itOrder );
            }
            break;
        }
    }

    itOrder = m_orderList.begin();
    for( int i=0; itOrder != m_orderList.end(); ++itOrder, ++i ) {
        if( (*itOrder)->sOrderSequence == rInfo.sOrderSequence ) {
            (*itOrder)->bSelect = true;
            ui->listView->appendItem( **itOrder );
            emit sig_selectSaleHead( rInfo.sOrderSequence, i%m_nOnePageCount );
            break;
        }
    }
}

void PendingListWidget::init()
{
    m_nCurPageNum = 1;
    m_nTotalPageNum = 1;
    setCurPage( m_nCurPageNum, m_nTotalPageNum );

    clearOrderList();
    ui->listView->clearItem();
}

void PendingListWidget::slot_upPageButton_clicked()
{
    if (m_nCurPageNum > 1)
    {
        m_nCurPageNum--;
        setCurPage( m_nCurPageNum, m_nTotalPageNum );
    }
    if (m_nCurPageNum == 1)
    {
        ui->upPageButton->setEnabled(false);
    }
    ui->downPageButton->setEnabled(true);

    generateSellList();
}

void PendingListWidget::slot_downPageButton_clicked()
{
    int nLen = m_orderList.size();
    if (m_nCurPageNum*m_nOnePageCount < nLen)
    {
        m_nCurPageNum++;
        setCurPage( m_nCurPageNum, m_nTotalPageNum );
    }
    if (m_nCurPageNum*m_nOnePageCount >= nLen)
    {
        ui->downPageButton->setEnabled(false);
    }
    ui->upPageButton->setEnabled(true);

    generateSellList();
}

void PendingListWidget::initConnect()
{
    connect( ui->listView, SIGNAL( sigUnPending(QString)), this, SLOT( slot_unPending( QString) ) );
    connect( ui->listView, SIGNAL( sigDeleteOrder(QString)), this, SLOT( slot_deleteOrder(QString ) ) );
    connect( ui->listView, SIGNAL( sig_selectPending(OrderInfo)), this, SLOT( slot_selectPending( OrderInfo ) ) );

    connect( ui->upPageButton, SIGNAL(clicked(bool)), this, SLOT( slot_upPageButton_clicked()) );
    connect( ui->downPageButton, SIGNAL(clicked(bool)), this, SLOT( slot_downPageButton_clicked()) );
}

void PendingListWidget::generateSellList()
{
    ui->listView->clearItem();
    int nStartPos = m_nOnePageCount * (m_nCurPageNum - 1);
    int nEndPos = m_nOnePageCount * m_nCurPageNum;
    int nLen = m_orderList.size();
    for (int i = nStartPos; i < nEndPos && i < nLen; i++)
    {
        ui->listView->appendItem( *m_orderList[i] );
    }
}

void PendingListWidget::showFirstPending()
{
    QList<OrderInfo *>::iterator itOrder = m_orderList.begin();
    if( itOrder == m_orderList.end() ) return;

    (*itOrder)->bSelect = true;
    ui->listView->appendItem( *m_orderList[0] );

    emit sig_selectSaleHead( (*itOrder)->sOrderSequence, 1 );
}

void PendingListWidget::setCurPage( int nCurPage, int nTotalPage )
{
    QString strPage = QString( "%1/%2页" ).arg( nCurPage ).arg( nTotalPage );
    ui->pageNumLabel->setText( strPage );

    if( nCurPage == 1 ) {
        ui->upPageButton->setEnabled( false );
    } else {
        ui->upPageButton->setEnabled( true );
    }

    if( nCurPage >= nTotalPage ) {
        ui->downPageButton->setEnabled( false );
    } else {
        ui->downPageButton->setEnabled( true );
    }

}

int PendingListWidget::getPageNum( int nSaleHeadNum )
{
    int nPageNum = nSaleHeadNum/m_nOnePageCount;
    int nRemainder = nSaleHeadNum%m_nOnePageCount;
    if( nRemainder >= 1 ) {
        nPageNum += 1;
    }

    if( nPageNum < 1 ) {
        nPageNum = 1;
    }

    return nPageNum;
}

void PendingListWidget::clearOrderList()
{
    QList<OrderInfo *>::iterator it = m_orderList.begin();
    while( it != m_orderList.end() ) {
        OrderInfo *pOrder = *it;
        it = m_orderList.erase( it );
        if( pOrder ) {
            delete pOrder;
            pOrder = NULL;
        }
    }
}
