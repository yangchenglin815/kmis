#include "CustomerSaleWidget.h"
#include "ui_CustomerSaleWidget.h"
#include "CommonFun.h"
#include "ScreenInfo.h"

CustomerSaleWidget::CustomerSaleWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomerSaleWidget)
    , m_nCurPage( 1 )
    , m_nTotalPage( 1 )
    , m_nOnePageCount( 8 )
    , m_bMemSell( false )
{
    ui->setupUi(this);
    ScreenInfo::resetGrid(this);
}

CustomerSaleWidget::~CustomerSaleWidget()
{
    delete ui;
}

void CustomerSaleWidget::addGoodsToSaleList( SaleDetails stSaleDetailsInfo )
{
//    if( ui->listView->getRows() == m_nOnePageCount ) {
//        m_nCurPage += 1;
////        generateSellList();
////        ui->listView->clearItems();
//    }

//    int nPos = m_mapSaleDetailInfo.size() + 1;
    stSaleDetailsInfo.goodsInfo.bSelectStatus = false;
    ui->listView->appendItem( stSaleDetailsInfo.goodsInfo );

    m_mapSaleDetailInfo.insert(stSaleDetailsInfo.nSaleDetailPos, stSaleDetailsInfo );

//    m_nTotalPage = getTotalPageNum( m_mapSaleDetailInfo.size() );

    updateGoodsSumPrice();
}

//标品才有更新
void CustomerSaleWidget::updateGoodsToSaleList( SaleDetails stSaleDetailsInfo )
{
    addGoodsToSaleList(stSaleDetailsInfo);

//    stSaleDetailsInfo.goodsInfo.bSelectStatus = false;

//    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
//    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
//        if( it.value().nGoodsId != stSaleDetailsInfo.nGoodsId ) continue;

//        SaleDetails &stSaleDetails = it.value();
//        stSaleDetails = stSaleDetailsInfo;
//        //如果列表中存在，则直接更新
//        bool bHas = ui->listView->isGoods( it.value().goodsInfo );
//        if( bHas ) {
//            GoodsDetailInfo stGoodsDetails = it.value().goodsInfo;
//            ui->listView->appendItem( stGoodsDetails );
//        } else {
//            ui->listView->clearItems();
//            //如果列表中不存在，则更新到当前标品所在的页，然后更新数据
//            m_nCurPage = getCurPageNum( it.key() );
//            generateSellList();
//        }
//        break;
//    }

//    updateGoodsSumPrice();
}

void CustomerSaleWidget::delGoodsToSaleList( int nSaleDetailsPos )
{
    ui->listView->deleteSelectGoods( nSaleDetailsPos );
    m_mapSaleDetailInfo.remove(nSaleDetailsPos);

//    //然后对m_mapSaleDetailInfo的key值重新排序，重新加载销售明细列表
//    QMap< int, SaleDetails > mapSaleDetailInfo;
//    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
//    int nGoodsPos = 1;

//    while( it != m_mapSaleDetailInfo.end() ) {
////        if( it.value().nSaleDetailPos == nSaleDetailsPos ) {
////            it = m_mapSaleDetailInfo.erase( it );
////            continue;
////        }

//        it->goodsInfo.nPos = nGoodsPos;
//        mapSaleDetailInfo.insert( it->nSaleDetailPos, it.value() );
//        ++nGoodsPos;
//        ++it;
//    }

//    m_mapSaleDetailInfo = mapSaleDetailInfo;
//    if( m_mapSaleDetailInfo.size() == 0 ) {
//        m_bMemSell = false;
//    }

//    int nTotalNum = m_mapSaleDetailInfo.size();
//    m_nCurPage = getTotalPageNum( nTotalNum );
//    m_nTotalPage = m_nCurPage;
//    generateSellList();
    updateGoodsSumPrice();
}

void CustomerSaleWidget::clearGoodsToSaleList()
{
    ui->listView->clearItems();
    m_mapSaleDetailInfo.clear();
    m_nCurPage = 1;
    m_nTotalPage = 1;
    m_bMemSell = false;
    updateGoodsSumPrice();
}

void CustomerSaleWidget::updateGoodsList()
{
    ui->listView->clearItems();
    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();//key:序号，nPos
    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
        if( it->fGrantDisRate == 0.00 ) {
            if( m_bMemSell && it->fMemPrice>0.00 ) {
                float fDiff = it->fPrice - it->fMemPrice;
                it->goodsInfo.fPrice = it->fMemPrice;
                it->fAllDisAmt = fDiff * it->goodsInfo.fNumber;
            } else {
                it->goodsInfo.fPrice = it->fPrice;
            }
        }

        float fSumPrice = it->goodsInfo.fPrice * it->goodsInfo.fNumber;
        QString strSumPrice = CommonFun::floatToString( fSumPrice );
        it->goodsInfo.sSumPrice = strSumPrice;
        it->fSwapPrice = it->goodsInfo.fPrice;
        it->strSwapAmt = strSumPrice;
        ui->listView->appendItem( it->goodsInfo );
    }
    m_nTotalPage = getTotalPageNum( m_mapSaleDetailInfo.size() );
    //setCurPage( m_nCurPage, m_nTotalPage );
    generateSellList();

    updateGoodsSumPrice();
}

int CustomerSaleWidget::getSaleDetailsNum()
{
    return m_mapSaleDetailInfo.size();
}

void CustomerSaleWidget::loginMember( bool bMember )
{
    m_bMemSell = bMember;
    if( bMember ) {
        updateGoodsList();
    }
}

bool CustomerSaleWidget::isGoods( int nGoodsId )
{
    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
        if( it.value().nGoodsId == nGoodsId ) return true;
    }

    return false;
}

void CustomerSaleWidget::generateSellList()
{
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1)*m_nOnePageCount;
    int nEndPos = nStartPos + m_nOnePageCount;
    int nLen = m_mapSaleDetailInfo.size();
    GoodsDetailInfo goodsDetailInfo;
    for (int i = nStartPos; i < nEndPos && i < nLen; i++)
    {
        goodsDetailInfo = m_mapSaleDetailInfo[i].goodsInfo;
        ui->listView->appendItem(goodsDetailInfo);
    }
}

//更新商品合计金额
void CustomerSaleWidget::updateGoodsSumPrice()
{
    float fSumPrice = 0.00;
    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
        fSumPrice += it.value().goodsInfo.sSumPrice.toFloat();
    }

    QString strSumPrice = "";
    strSumPrice.sprintf( "￥%.2f", fSumPrice );
    ui->totalValueLabel->setText( strSumPrice );
}

int CustomerSaleWidget::getCurPageNum( int nGoodsPos )
{
    if( m_nCurPage > nGoodsPos ) {
        m_nCurPage = nGoodsPos;
    } else if( m_nCurPage < nGoodsPos ) {
        m_nCurPage = nGoodsPos + 1 - m_nOnePageCount;
    }

    return m_nCurPage;
}

int CustomerSaleWidget::getTotalPageNum( int nGoodsPos )
{
    int nPageNum = nGoodsPos/m_nOnePageCount;
    if( nPageNum < 1 ) return 1;

    nPageNum = nGoodsPos - m_nOnePageCount + 1;

    return nPageNum;
}
