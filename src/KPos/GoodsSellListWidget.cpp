#include "GoodsSellListWidget.h"
#include "ui_GoodsSellListWidget.h"
#include "KPosIni.h"
#include "LoginKPosAgent.h"
#include "SaleHeadAgent.h"
#include "SaleDetailsAgent.h"
#include "ModifyGoodsNumDlg.h"
#include "CommonFun.h"
#include <QDebug>
#include "PromotionWidget.h"
#include "CategoryInfoAgent.h"
#include "KPosServerIni.h"

GoodsSellListWidget::GoodsSellListWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GoodsSellListWidget)
    , m_pModifyGoodsNumDlg( NULL )
    , m_nCurPage(1)
    , m_nTotalPage( 1 )
    , m_nOnePageCount(5)
    , m_nSaleDetailPos(0)
    , m_bMemSell( false )
    , m_bPromotioned( false )
    , m_nSingleMaxNum( 1000 )
{
    ui->setupUi(this);
    ui->upPageButton->setDisabled(true); 
    setCurPage( m_nCurPage, m_nTotalPage );
    initCtrl();
    initConnect();
}

GoodsSellListWidget::~GoodsSellListWidget()
{
    delete ui;
}

void GoodsSellListWidget::initData()
{
    m_stSaleHead.nSerialNum = -1;
    m_listSelectGoodsInfo.clear();
    m_mapSaleDetailInfo.clear();
    ui->listView->clearItems();
    m_nCurPage = 1;
    m_nTotalPage = 1;
    m_nSaleDetailPos = 0;
    m_bMemSell = false;
    setCurPage( m_nCurPage, m_nTotalPage );
}

void GoodsSellListWidget::generateSellList()
{
    ui->listView->clearItems();
    //ui->listView->appendTitle();
    int nStartPos = m_nOnePageCount * (m_nCurPage - 1);
    int nEndPos = m_nOnePageCount * m_nCurPage;
    int nLen = m_mapSaleDetailInfo.size();
    for (int i = nStartPos; i < nEndPos && i < nLen; i++)
    {
        ui->listView->appendItem( m_mapSaleDetailInfo[i+1].goodsInfo );
    }
}

void GoodsSellListWidget::addGoodsInfo( GoodsInfo st_goodsInfo, QString strNum )
{
    if( getGoodsNum() < 1 ) {
        initSaleHead();
        SaleHeadAgent::Instance()->insertSaleHeadTable(m_stSaleHead);
    }

    int nPos = m_mapSaleDetailInfo.size() + 1;
    m_nSaleDetailPos = SaleDetailsAgent::Instance()->getLastSaleDetailsPos() + 1;

    if( m_nCurPage != m_nTotalPage ) {
        ui->listView->clearItems();

        m_nCurPage = m_nTotalPage;
        setCurPage( m_nCurPage, m_nTotalPage );
        generateSellList();
    }

    if( ui->listView->getRows() == m_nOnePageCount ) {
        m_nCurPage = m_nTotalPage + 1;
        m_nTotalPage += 1;
        setCurPage( m_nCurPage, m_nTotalPage );
        ui->listView->clearItems();
    }

    cancelAllSelectGoods();

    SaleDetails stSaleDetails;
    stSaleDetails.strOrderNum = m_stSaleHead.strOrderNum;
    stSaleDetails.strBarCode = st_goodsInfo.sBarCode;
    stSaleDetails.nGoodsId = st_goodsInfo.nId;
    stSaleDetails.strGoodsName = st_goodsInfo.sName;
    stSaleDetails.nStatus = 1;
    stSaleDetails.nSaleDetailPos = m_nSaleDetailPos;
    stSaleDetails.fPrice = st_goodsInfo.fPrice;
    stSaleDetails.fMemPrice = st_goodsInfo.fMemberPrice;

    QString strSumPrice = "";
    strSumPrice.sprintf( "%.2f", stSaleDetails.fPrice * strNum.toFloat() );
    QString strMemSumPrice = "";
    strMemSumPrice.sprintf( "%.2f", stSaleDetails.fMemPrice * strNum.toFloat() );
    stSaleDetails.strOrgSum = strSumPrice;
    stSaleDetails.strOrgMemSum = strMemSumPrice;
    stSaleDetails.goodsInfo.nPos = nPos;
    stSaleDetails.goodsInfo.nSaleDetailPos = m_nSaleDetailPos;
    stSaleDetails.goodsInfo.sGoodsName = st_goodsInfo.sName;
    stSaleDetails.goodsInfo.strGoodsShortName = st_goodsInfo.sShortName;
    if (!st_goodsInfo.sPluName.isEmpty())
    {
        stSaleDetails.goodsInfo.sGoodsName = st_goodsInfo.sPluName;
        stSaleDetails.goodsInfo.strGoodsShortName = st_goodsInfo.sPluName;
    }
    stSaleDetails.goodsInfo.fNumber = strNum.toFloat();
    goodsToSaleDetail( stSaleDetails.goodsInfo, st_goodsInfo );
    stSaleDetails.fSwapPrice = stSaleDetails.goodsInfo.fPrice;
    stSaleDetails.strSwapAmt = stSaleDetails.goodsInfo.sSumPrice;
    stSaleDetails.dtCreateTime = QDateTime::currentDateTime();
    m_mapSaleDetailInfo.insert( nPos, stSaleDetails );
    stSaleDetails.goodsInfo.bSelectStatus = true;
    m_listSelectGoodsInfo.append( stSaleDetails.goodsInfo.nSaleDetailPos );
    ui->listView->appendItem( stSaleDetails.goodsInfo );

    //加入数据库
    SaleDetailsAgent::Instance()->insertSaleDetailsTable( stSaleDetails );

    updateSaleHeadSumPrice();

    emit sig_addGoodsToSaleList( stSaleDetails );
}

void GoodsSellListWidget::addGoodsInfo( SaleDetails &stSaleDetails, bool bSelect )
{
    cancelAllSelectGoods();

    int nPos = m_mapSaleDetailInfo.size() + 1;
    stSaleDetails.goodsInfo.nPos = nPos;
    m_mapSaleDetailInfo.insert( nPos, stSaleDetails );
    if( nPos <= m_nOnePageCount ) {
        if( bSelect ) {
            stSaleDetails.goodsInfo.bSelectStatus = true;
        }

        if( m_bMemSell && stSaleDetails.fMemPrice>0.00) {//会员价为0，则认为没有会员价
            stSaleDetails.goodsInfo.fPrice = stSaleDetails.fMemPrice;
        } else {
            stSaleDetails.goodsInfo.fPrice = stSaleDetails.fPrice;
        }
        stSaleDetails.fSwapPrice = stSaleDetails.goodsInfo.fPrice;
        float fSumPrice = stSaleDetails.goodsInfo.fPrice*stSaleDetails.goodsInfo.fNumber;
        stSaleDetails.goodsInfo.sSumPrice = CommonFun::handleMoneyCoin(fSumPrice);
        stSaleDetails.strSwapAmt = stSaleDetails.goodsInfo.sSumPrice;
        ui->listView->appendItem( stSaleDetails.goodsInfo );
        m_listSelectGoodsInfo.append( stSaleDetails.goodsInfo.nSaleDetailPos );
    }
    m_nTotalPage = getPageNum( m_mapSaleDetailInfo.size() );
    setCurPage( m_nCurPage, m_nTotalPage );

    updateSaleHeadSumPrice();
}

//标品
void GoodsSellListWidget::updateGoodsInfo( GoodsInfo st_goodsInfo )
{
    cancelAllSelectGoods();

    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
        if( it.value().strBarCode != st_goodsInfo.sBarCode ) continue;
        if( it.value().goodsInfo.fNumber - m_nSingleMaxNum >= 0 ) return;

        it.value().goodsInfo.fNumber = it.value().goodsInfo.fNumber + 1;
        QString strSumPrice = "";
        strSumPrice.sprintf( "%.2f", it.value().goodsInfo.fNumber * it.value().fPrice );
        it.value().strOrgSum = strSumPrice;//原总额
        strSumPrice.sprintf( "%.2f", it.value().goodsInfo.fNumber * it.value().goodsInfo.fPrice );
        it.value().goodsInfo.sSumPrice = strSumPrice;//现总额
        if( it.value().fGrantDisRate == 0.00 ) {
            if( m_bMemSell && it.value().fMemPrice>0.00 ) {
                it.value().goodsInfo.fPrice = it.value().fMemPrice;
                strSumPrice.sprintf( "%.2f", it.value().goodsInfo.fNumber * it.value().goodsInfo.fPrice );
                it.value().fAllDisAmt = it.value().strOrgSum.toFloat() - strSumPrice.toFloat();
                it.value().goodsInfo.sSumPrice = strSumPrice;
            }
        } else {
            it.value().fAllDisAmt = it.value().strOrgSum.toFloat() - it.value().goodsInfo.sSumPrice.toFloat();
        }
        it.value().fSwapPrice = it.value().goodsInfo.fPrice;
        it.value().strSwapAmt = strSumPrice;

//        SaleDetailsAgent::Instance()->updateSaleDetailsNum( it.value().strOrderNum
//                                        , it.value().goodsInfo.fNumber, strSumPrice, it.value().nGoodsId  );
        SaleDetailsAgent::Instance()->insertSaleDetailsTable( *it );
        m_listSelectGoodsInfo.append( it.value().goodsInfo.nSaleDetailPos );
        //如果列表中存在，则直接更新
        bool bHas = ui->listView->isGoods( it.value().goodsInfo );
        if( bHas ) {
            GoodsDetailInfo stGoodsDetails = it.value().goodsInfo;
            stGoodsDetails.bSelectStatus = true;
            ui->listView->appendItem( stGoodsDetails );
        } else {
            ui->listView->clearItems();
            //如果列表中不存在，则更新到当前标品所在的页，然后更新数据
            m_nCurPage = getPageNum( it.key() );
            setCurPage( m_nCurPage, m_nTotalPage );
            generateSellList();
        }
        updateSelectGoods();

        emit sig_addGoodsToSaleList( it.value() );

        break;
    }

    updateSaleHeadSumPrice();
}

void GoodsSellListWidget::clearGoodsInfo()
{
    initData();
}

void GoodsSellListWidget::cancelAllSelectGoods()
{
    m_listSelectGoodsInfo.clear();
    clearAllGoodsStatus();
    ui->listView->cancelAllSelectGoods();

}

bool GoodsSellListWidget::getSelectGoodsInfo( QList<int> &listSelectGoodsInfo )
{
    listSelectGoodsInfo = m_listSelectGoodsInfo;
    return true;
}

bool GoodsSellListWidget::getSelectGoodsInfo( QList<SaleDetails> &listSaleDetails )
{
    QList<int>::iterator itSelect = m_listSelectGoodsInfo.begin();
    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();//key:序号，nPos
    for( ; itSelect != m_listSelectGoodsInfo.end(); ++itSelect ) {
        it = m_mapSaleDetailInfo.begin();
        for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
            if( *itSelect == it.value().nSaleDetailPos ) {
                listSaleDetails.append( *it );
                break;
            }
        }
    }
    return true;
}

bool GoodsSellListWidget::getAllGoodsInfo( QList<SaleDetails> &listSaleDetails )
{
    if( m_mapSaleDetailInfo.size() <= 0 ) return false;

    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();//key:序号，nPos
    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
        listSaleDetails.append( it.value() );
    }
    return true;
}

void GoodsSellListWidget::updateGoodsList()
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
        SaleDetailsAgent::Instance()->updateSaleDetailsTable( *it );
    }
    m_nTotalPage = getPageNum( m_mapSaleDetailInfo.size() );
    setCurPage( m_nCurPage, m_nTotalPage );
    generateSellList();

    updateSaleHeadSumPrice();
}

void GoodsSellListWidget::addSaleHead( const QString &strOrderNum )
{
    QList< SaleDetails > listSaleDetails;
    SaleHeadAgent::Instance()->findSaleHead( strOrderNum, m_stSaleHead );
    SaleDetailsAgent::Instance()->findSaleDetails( strOrderNum, listSaleDetails );    

    //获取所有商品列表，更新销售明细中的商品信息
    QMap<int, GoodsInfo_s> mapGoodsInfoFirst;
    CategoryInfoAgent::instance()->getGoodsList( mapGoodsInfoFirst );
    QMap<int, GoodsInfo_s>::iterator itGoods = mapGoodsInfoFirst.begin();
    QList< SaleDetails >::iterator itSale = listSaleDetails.begin();

    float fOughtAmt = 0.00;
    //删、改
    while( itSale!=listSaleDetails.end() ) {
        bool bHas = false;
        itGoods = mapGoodsInfoFirst.begin();
        for( ; itGoods != mapGoodsInfoFirst.end(); ++itGoods ) {
            if( itGoods.value().sBarCode == itSale->strBarCode ) {//使用条码比较商品
                itSale->strGoodsName = itGoods.value().sName;
                itSale->nGoodsId = itGoods.value().nId;
                itSale->fSwapPrice = itGoods.value().goodsPriceInfo.fPrice;
                itSale->strSwapAmt = CommonFun::floatToString( itSale->fSwapPrice * itSale->goodsInfo.fNumber );
                itSale->fGrantDisRate = 0.0;
                itSale->fAllDisAmt = 0.00;
                itSale->fPrice = itGoods.value().goodsPriceInfo.fPrice;
                itSale->fMemPrice = itGoods.value().goodsPriceInfo.fMemberPrice;
                itSale->strOrgSum = itSale->strSwapAmt;
                itSale->strOrgMemSum = CommonFun::floatToString( itSale->fMemPrice * itSale->goodsInfo.fNumber );
                itSale->goodsInfo.nGoodsId = itSale->nGoodsId;
                itSale->goodsInfo.strGoodsCode = itGoods.value().sCode;
                itSale->goodsInfo.sGoodsName = itSale->strGoodsName;
                itSale->goodsInfo.strGoodsShortName = itGoods.value().sShortName;
                itSale->goodsInfo.fPrice = itSale->fPrice;
                itSale->goodsInfo.sSumPrice = itSale->strOrgSum;
                itSale->goodsInfo.bDisCount = false;
                fOughtAmt += itSale->strSwapAmt.toFloat();
                //更新销售明细数据库中数据
                SaleDetailsAgent::Instance()->updateSaleDetailsTable( *itSale );
                addGoodsInfo( *itSale );
                emit sig_addGoodsToSaleList( *itSale );

                bHas = true;
                break;
            }
        }

        if( !bHas ) {//表示商品信息没有销售明细中的商品，则删除销售明细中的商品
            //删除销售明细中的数据库
            SaleDetailsAgent::Instance()->cancelSaleDetailsState( itSale->nSaleDetailPos );
            itSale = listSaleDetails.erase( itSale );
        } else {
            ++itSale;
        }
    }

    //更新销售主表信息，如果销售明细size为空，则删除该订单
    if( listSaleDetails.size() == 0 ) {
        SaleHeadAgent::Instance()->updateStatus(strOrderNum, e_headCancel);
    } else {
        //更新销售主表信息
        m_stSaleHead.nSaleTotalNum = listSaleDetails.size();
        m_stSaleHead.fOughtAmt = fOughtAmt;//应付金额
        m_stSaleHead.fFactorAmt = 0;//实付金额
        m_stSaleHead.fOddChange = 0;//找零
        m_stSaleHead.strMemCardId = "";
        m_stSaleHead.strMemName = "";
        m_stSaleHead.strLastShopping = "";
        m_stSaleHead.strLastCharge = "";
        m_stSaleHead.nMemInteger = 0;
        m_stSaleHead.fGrantDisRate = 0.0;
        m_stSaleHead.fAllDisAmt = 0.00;
        m_stSaleHead.fCouponDisAmt = 0.00;
        m_stSaleHead.fProfitLoss = 0.00;
        m_stSaleHead.nStatus = 2;

        SaleHeadAgent::Instance()->insertSaleHeadTable( m_stSaleHead );
    }
    updateSaleHeadSumPrice();
}

void GoodsSellListWidget::setSelectStatus( bool bSelect )
{
    ui->listView->setSelectStatus( bSelect );
}

bool GoodsSellListWidget::isGoods(const QString sKeyId )
{
    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
        if( it.value().strBarCode == sKeyId ) {
            return true;
        }
    }
    return false;
}

int GoodsSellListWidget::getSelectGoodsNum()
{
    int nNum = m_listSelectGoodsInfo.size();
    return nNum;
}

int GoodsSellListWidget::getGoodsNum()
{
    int nNum = m_mapSaleDetailInfo.size();
    return nNum;
}

bool GoodsSellListWidget::getSaleHead( SaleHead &stSaleHead )
{
    if( m_stSaleHead.nSerialNum < 0 ) {
        return false;
    }

    stSaleHead = m_stSaleHead;
    return true;
}

void GoodsSellListWidget::setSaleHead(SaleHead stSaleHead)
{
    m_stSaleHead = stSaleHead;
    SaleHeadAgent::Instance()->insertSaleHeadTable( m_stSaleHead );
}

void GoodsSellListWidget::setSaleHeadStatus( ESaleHeadStatus e_saleHeadStatus )
{
    m_stSaleHead.nStatus = e_saleHeadStatus;
    if( m_stSaleHead.nStatus == e_headPending ) {
        //1.加载数据库:订单和明细表
        m_stSaleHead.dtFactorTime = QDateTime::currentDateTime();
        SaleHeadAgent::Instance()->updateStatus( m_stSaleHead.strOrderNum, e_saleHeadStatus, m_stSaleHead.dtFactorTime );
        //2. 然后清除所有数据
        initData();
    }
}

void GoodsSellListWidget::setMemStatus( bool bMemStatus )
{
    m_bMemSell = bMemStatus;
}

bool GoodsSellListWidget::getMemStatus()
{
    return m_bMemSell;
}

void GoodsSellListWidget::setSingleMaxNum( int nSingleMaxNum )
{
    if( nSingleMaxNum <= 0 ) return;

    m_nSingleMaxNum = nSingleMaxNum;
}

void GoodsSellListWidget::slot_deleteSelectGoods()
{
    int nNoSelectGoodsPos = findNoSelectGoods();
    if( nNoSelectGoodsPos < 0 ) {
        ui->listView->clearItems();
        m_mapSaleDetailInfo.clear();
        m_listSelectGoodsInfo.clear();
        m_nCurPage = 1;
        m_nTotalPage = 1;
        setCurPage( m_nCurPage, m_nTotalPage );
        updateSaleHeadSumPrice();
        initData();
        //删除数据库中数据
        SaleDetailsAgent::Instance()->cancelSaleDetailsState( m_stSaleHead.strOrderNum );
        SaleHeadAgent::Instance()->updateStatus(m_stSaleHead.strOrderNum, e_headCancel);
        return;
    }

    deleteSelectGoods();
    ui->listView->clearItems();

    //然后对m_mapSaleDetailInfo的key值重新排序，重新加载销售明细列表
    QMap< int, SaleDetails > mapSaleDetailInfo;
    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
    int nGoodsPos = 1;
    for( int i = 1; it != m_mapSaleDetailInfo.end(); ++it,++i ) {
        it.value().goodsInfo.nPos = i;
        mapSaleDetailInfo.insert( i, it.value() );

        if( it.value().nSaleDetailPos == nNoSelectGoodsPos ) {
            nGoodsPos = i;
        }

    }
    m_mapSaleDetailInfo = mapSaleDetailInfo;

    m_nCurPage = getPageNum( nGoodsPos );
    int nTotalNum = m_mapSaleDetailInfo.size();
    m_nTotalPage = getPageNum( nTotalNum );
    setCurPage( m_nCurPage, m_nTotalPage );
    generateSellList();
    updateSaleHeadSumPrice();
    if( getGoodsNum() < 1 ) {
        //删除数据库中数据
        SaleDetailsAgent::Instance()->cancelSaleDetailsState( m_stSaleHead.strOrderNum );
        SaleHeadAgent::Instance()->updateStatus(m_stSaleHead.strOrderNum, e_headCancel);
    }
}

void GoodsSellListWidget::slot_clearAllGoods()
{
    //删除销售和销售明细数据库数据
    SaleDetailsAgent::Instance()->cancelSaleDetailsState( m_stSaleHead.strOrderNum );
    SaleHeadAgent::Instance()->updateStatus( m_stSaleHead.strOrderNum, e_headCancel);

    initData();
    updateSaleHeadSumPrice();
}

void GoodsSellListWidget::slot_updateGoodsInfo( SaleDetails stSaleDetails )
{
    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
        if( it.value().nSaleDetailPos != stSaleDetails.nSaleDetailPos ) continue;

        stSaleDetails.goodsInfo.bSelectStatus = true;
        it.value() = stSaleDetails;
        //重新更新数据库
        SaleDetailsAgent::Instance()->updateSaleDetailsTable( stSaleDetails );
        //如果列表中存在，则直接更新
        bool bHas = ui->listView->isGoods( it.value().goodsInfo );
        if( bHas ) {
            GoodsDetailInfo stGoodsDetails = it.value().goodsInfo;
            ui->listView->appendItem( stGoodsDetails );
        } else {
            ui->listView->clearItems();
            //如果列表中不存在，则更新到当前标品所在的页，然后更新数据
            m_nCurPage = getPageNum( it.key() );
            setCurPage( m_nCurPage, m_nTotalPage );
            generateSellList();
        }

        emit sig_addGoodsToSaleList( it.value() );

        break;
    }

    updateSaleHeadSumPrice();
}

void GoodsSellListWidget::slot_updateGoodsInfo( const QList<SaleDetails> &listSaleDetails, bool bSaleHeadDis )
{
    //更新m_mapSaleDetailInfo数据
    QList<SaleDetails>::const_iterator itList = listSaleDetails.constBegin();
    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
    for( ; itList != listSaleDetails.constEnd(); ++itList ) {
        it = m_mapSaleDetailInfo.begin();
        for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
            if( itList->nSaleDetailPos != it.value().nSaleDetailPos ) continue;

            it.value() = *itList;
            break;
        }
    }

    //更新选中状态和appenItem更新商品显示
    QList<int>::iterator itSelect = m_listSelectGoodsInfo.begin();
    it = m_mapSaleDetailInfo.begin();
    for( ; it != m_mapSaleDetailInfo.constEnd(); ++it ) {
        if( !bSaleHeadDis ) {
            itSelect = m_listSelectGoodsInfo.begin();
            for( ; itSelect != m_listSelectGoodsInfo.end(); ++itSelect ) {
                if( *itSelect != it.value().nSaleDetailPos ) continue;

                it.value().goodsInfo.bSelectStatus = true;
                break;
            }
        } else {
            it.value().goodsInfo.bSelectStatus = true;
        }

        //重新更新数据库
        SaleDetailsAgent::Instance()->updateSaleDetailsTable( it.value() );
        //如果列表中存在，则直接更新
        bool bHas = ui->listView->isGoods( it.value().goodsInfo );
        if( bHas ) {
            GoodsDetailInfo stGoodsDetails = it.value().goodsInfo;
            ui->listView->appendItem( stGoodsDetails );
        } else {
            ui->listView->clearItems();
            //如果列表中不存在，则更新到当前标品所在的页，然后更新数据
            m_nCurPage = getPageNum( it.key() );
            setCurPage( m_nCurPage, m_nTotalPage );
            generateSellList();
        }

        emit sig_addGoodsToSaleList( it.value() );
    }

    updateSaleHeadSumPrice();
}

void GoodsSellListWidget::on_upPageButton_clicked()
{
    if (m_nCurPage > 1)
    {
        m_nCurPage--;
        setCurPage( m_nCurPage, m_nTotalPage );
    }
    if (m_nCurPage == 1)
    {
        ui->upPageButton->setEnabled(false);
    }
    ui->downPageButton->setEnabled(true);

    generateSellList();
    updateSelectGoods();
}

void GoodsSellListWidget::on_downPageButton_clicked()
{
    int nLen = m_mapSaleDetailInfo.size();
    if (m_nCurPage*m_nOnePageCount < nLen)
    {
        m_nCurPage++;
        setCurPage( m_nCurPage, m_nTotalPage );
    }
    if (m_nCurPage*m_nOnePageCount >= nLen)
    {
        ui->downPageButton->setEnabled(false);
    }
    ui->upPageButton->setEnabled(true);

    generateSellList();
    updateSelectGoods();
}

void GoodsSellListWidget::slot_selectGoods( GoodsDetailInfo st_goodsInfo )
{
    QList<int>::iterator it = m_listSelectGoodsInfo.begin();
    for( ; it != m_listSelectGoodsInfo.end(); ++it ) {
        if( *it == st_goodsInfo.nSaleDetailPos ) {
            m_listSelectGoodsInfo.erase( it );
            st_goodsInfo.bSelectStatus = false;
            ui->listView->appendItem( st_goodsInfo );
            return;
        }
    }

    m_listSelectGoodsInfo.append( st_goodsInfo.nSaleDetailPos );
    st_goodsInfo.bSelectStatus = true;
    ui->listView->appendItem( st_goodsInfo );
}

void GoodsSellListWidget::slot_showModifyNumDlg( GoodsDetailInfo st_goodsInfo )
{
    cancelAllSelectGoods();
    if( !m_listSelectGoodsInfo.contains( st_goodsInfo.nSaleDetailPos ) ) {
        m_listSelectGoodsInfo.append( st_goodsInfo.nSaleDetailPos );
        st_goodsInfo.bSelectStatus = true;
        ui->listView->appendItem( st_goodsInfo );
    }

    m_pModifyGoodsNumDlg->setSingleMaxNum( m_nSingleMaxNum );
    m_pModifyGoodsNumDlg->setGoodsDetailInfo( st_goodsInfo );
    m_pModifyGoodsNumDlg->exec();
}

void GoodsSellListWidget::slot_ModifyGoodsNum()
{
    if( m_listSelectGoodsInfo.size() != 1 ) return;

    GoodsDetailInfo st_goodsInfo;
    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
        if( it.value().nSaleDetailPos == m_listSelectGoodsInfo.first() ) {
            st_goodsInfo = it.value().goodsInfo;
            break;
        }
    }

    if( st_goodsInfo.nPos < 0 ) return;
    m_pModifyGoodsNumDlg->setSingleMaxNum( m_nSingleMaxNum );
    m_pModifyGoodsNumDlg->setGoodsDetailInfo( st_goodsInfo );
    m_pModifyGoodsNumDlg->exec();
}

void GoodsSellListWidget::slot_ModifyGoodsNum( int nSaleDetailPos, QString strGoodsNum )
{
    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
        if( it.value().nSaleDetailPos == nSaleDetailPos ) {
            it.value().goodsInfo.fNumber = strGoodsNum.toFloat();
            float fSumPrice = it.value().fPrice * it.value().goodsInfo.fNumber;
            it.value().strOrgSum = CommonFun::floatToString( fSumPrice );
            fSumPrice = it.value().fMemPrice * it.value().goodsInfo.fNumber;
            it.value().strOrgMemSum = CommonFun::floatToString( fSumPrice );
            fSumPrice = it.value().goodsInfo.fPrice * it.value().goodsInfo.fNumber;
            it.value().goodsInfo.sSumPrice = CommonFun::floatToString( fSumPrice );
            it.value().fSwapPrice = it.value().goodsInfo.fPrice;
            it.value().strSwapAmt = it.value().goodsInfo.sSumPrice;
            it.value().fAllDisAmt = it.value().strOrgSum.toFloat() - fSumPrice;
            GoodsDetailInfo stGoodsDetails = it.value().goodsInfo;
            if( m_listSelectGoodsInfo.contains( stGoodsDetails.nSaleDetailPos ) ) {
                stGoodsDetails.bSelectStatus = true;
            }
            ui->listView->appendItem( stGoodsDetails );

            emit sig_addGoodsToSaleList( it.value() );
            SaleDetailsAgent::Instance()->updateSaleDetailsTable( it.value() );
//            SaleDetailsAgent::Instance()->updateSaleDetailsNum( it.value().strOrderNum, strGoodsNum.toFloat()
//                                                                , it.value().goodsInfo.sSumPrice, stGoodsDetails.nGoodsId );
            break;
        }
    }

    if( m_pModifyGoodsNumDlg ) {
        m_pModifyGoodsNumDlg->hide();
    }

    updateSaleHeadSumPrice();
}

void GoodsSellListWidget::slot_showPromotionDlg()
{
    PromotionWidget *pPromotionWidget = new PromotionWidget();

    QMap<int, SaleDetails> mapPromotion;//key:促销商品的序号
    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();//key:序号，nPos
    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
        if( it.value().goodsInfo.bPromotion ) {
            mapPromotion.insert( it.key(), it.value() );
        }
    }

    pPromotionWidget->setPromotion( mapPromotion, m_bPromotioned );

    pPromotionWidget->show();
}

void GoodsSellListWidget::initCtrl()
{
    m_pModifyGoodsNumDlg = new ModifyGoodsNumDlg();
    connect( m_pModifyGoodsNumDlg, SIGNAL(sig_modifyGoodsNum(int,QString)), this, SLOT( slot_ModifyGoodsNum(int,QString) ) );
    m_pModifyGoodsNumDlg->hide();
}

void GoodsSellListWidget::initConnect()
{
    connect( ui->listView, SIGNAL(sig_selectGoods(GoodsDetailInfo)), this, SLOT( slot_selectGoods( GoodsDetailInfo ) ) );
    connect( ui->listView, SIGNAL( sig_doubleClickItem(GoodsDetailInfo)), this, SLOT( slot_showModifyNumDlg( GoodsDetailInfo ) ) );
    connect( ui->listView, SIGNAL(sig_showPromotionDlg()), this, SLOT( slot_showPromotionDlg() ) );
}

void GoodsSellListWidget::initSaleHead()
{
    QString sSerialNum = KPosIni::getSerialNum();
    m_stSaleHead.nSerialNum = sSerialNum.toInt();

    int nLastSaleHeadId = SaleHeadAgent::Instance()->getLastSaleHeadId();

    m_stSaleHead.nSaleHeadId = nLastSaleHeadId + 1;
    m_stSaleHead.dtCreateTime = QDateTime::currentDateTime();
    m_stSaleHead.strPosId = KPosIni::getPosCode();
    QString strDateTime = QDateTime::currentDateTime().toString( "yyMMdd" );

    m_stSaleHead.strOrderNum = m_stSaleHead.strPosId + strDateTime + sSerialNum;//单号（pos号+日期YYMMDD+流水号）


//    m_stSaleHead.strOrderNum = m_stSaleHead.strPosId + strDateTime + strSerialNum;
    m_stSaleHead.nSaleTotalNum = 0;
    m_stSaleHead.fOughtAmt = 0.00f;
    m_stSaleHead.fFactorAmt = 0.00f;
    m_stSaleHead.fOddChange = 0.00f;
    m_stSaleHead.strMemCardId = "";
    m_stSaleHead.nMemInteger = 0;

    m_stSaleHead.strDisReason = "";
    m_stSaleHead.fGrantDisRate = 0.0f;
    m_stSaleHead.fAllDisAmt = 0.00f;
    m_stSaleHead.fCouponDisAmt = 0.00f;
    m_stSaleHead.fProfitLoss = 0.00f;
    m_stSaleHead.nStatus = e_headSelling;//交易状态:正在进行，挂单，完成，取消

    m_stSaleHead.nType = 0;//购物类型:0.现购，1.网购，2.团购
    m_stSaleHead.nShopId = KPosIni::getShopId();//门店编号
    m_stSaleHead.eUploadStatus = eNotUpload;//上传总部状态
    m_stSaleHead.dtFactorTime = m_stSaleHead.dtCreateTime;//实际交易时间
    m_stSaleHead.nCostTime = 0;//交易花费时间

    SalemanInfo stSaleman = LoginKPosAgent::instance()->getLoginKPosInfo().salemanInfo;
    m_stSaleHead.nCashierId = stSaleman.nUserId;//收款员编号
    m_stSaleHead.strCashierName = stSaleman.sUsername;//收款员姓名
    m_stSaleHead.nShoppingId = 0;//导购员ID
    m_stSaleHead.strShoppingName = "";//导购员名字

    m_stSaleHead.nTranStatus = 0;
    m_stSaleHead.nSaleType = 0;
    m_stSaleHead.strReturnOrderNum = "";
    m_stSaleHead.strReturnReason = "";
    m_stSaleHead.nSaleMode = 1;//销售方式:默认为Kpos销售
    m_stSaleHead.strLog = "";
}

void GoodsSellListWidget::setCurPage( int nCurPage, int nTotalPage )
{
    QString strPage = QString( "%1/%2页" ).arg( nCurPage ).arg( nTotalPage );
    ui->sellListPageLabel->setText( strPage );

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

//更新listView中显示的所有选中行的颜色
void GoodsSellListWidget::updateSelectGoods()
{
    clearAllGoodsStatus();

    int nRow = ui->listView->getRows();
    for( int i = 0; i < nRow; i++ ) {
        GoodsDetailInfo st_goodsInfo;
        bool bHas = ui->listView->findItem( i, st_goodsInfo );
        if( bHas ) {
            //查找
            bool bHasGoods = m_listSelectGoodsInfo.contains( st_goodsInfo.nSaleDetailPos );
            if( bHasGoods ) {
                st_goodsInfo.bSelectStatus = true;
                //加深颜色
                ui->listView->appendItem( st_goodsInfo );
            } else {
                continue;
            }

        } else {
            continue;
        }
    }
}

void GoodsSellListWidget::deleteSelectGoods()
{
    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
    while( it != m_mapSaleDetailInfo.end() ) {
        int nSaleDetailPos = it.value().nSaleDetailPos;
        if( m_listSelectGoodsInfo.contains( nSaleDetailPos ) ) {
            //删除数据库数据
            SaleDetailsAgent::Instance()->cancelSaleDetailsState( it.value().nSaleDetailPos );
            m_listSelectGoodsInfo.removeOne( nSaleDetailPos );
            it = m_mapSaleDetailInfo.erase( it );
        } else {
            ++it;
        }
    }
}

void GoodsSellListWidget::clearAllGoodsStatus()
{
    QMap<int, SaleDetails>::iterator it = m_mapSaleDetailInfo.begin();
    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
        it.value().goodsInfo.bSelectStatus = false;
    }
}

int GoodsSellListWidget::findNoSelectGoods()
{
    GoodsDetailInfo st_goodsInfo;
    int nNoselectDetailPos = -1;
    bool bNoSelect = ui->listView->isNoSelectGoods( st_goodsInfo );
    if( bNoSelect ) {
        return st_goodsInfo.nSaleDetailPos;
    }

    //查找当前页之前的所有销售id，找到未被选中的销售id
    int nPageNum = 1;
    if( m_nCurPage > 1 ) {
        nPageNum = m_nCurPage - 1;

        int nMaxSeritalNum = nPageNum * m_nOnePageCount;
        for( int i = nMaxSeritalNum; i>0; i-- ) {
            QMap< int, SaleDetails >::iterator it_goods = m_mapSaleDetailInfo.find( i );
            if( it_goods == m_mapSaleDetailInfo.end() ) continue;

            if( m_listSelectGoodsInfo.contains( it_goods.value().nSaleDetailPos ) ) {
                continue;
            }

            nNoselectDetailPos = it_goods.value().nSaleDetailPos;
            return nNoselectDetailPos;
        }
    }

    //查找下一页未被选中的销售id
    if( m_nCurPage < m_nTotalPage ) {
        int nMinSeritalNum = m_nCurPage * m_nOnePageCount;
        for( int i = nMinSeritalNum; i < m_mapSaleDetailInfo.size(); i++ ) {
            QMap< int, SaleDetails >::iterator it_goods = m_mapSaleDetailInfo.find( i+1 );
            if( it_goods == m_mapSaleDetailInfo.end() ) continue;

            if( m_listSelectGoodsInfo.contains( it_goods.value().nSaleDetailPos ) ) {
                continue;
            }
            nNoselectDetailPos = it_goods.value().nSaleDetailPos;
            return nNoselectDetailPos;
        }
    }

    return nNoselectDetailPos;
}

//更新订单合计金额
void GoodsSellListWidget::updateSaleHeadSumPrice()
{
    updateSaleHeadMemPrice();
    updateSaleHeadDisPrice();
    updateSaleHeadDisRate();

    float fSumPrice = 0.00;
    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
        fSumPrice += it.value().goodsInfo.sSumPrice.toFloat();
    }

    fSumPrice -= m_stSaleHead.fCouponDisAmt;
    QString strSumPrice = "";
    strSumPrice.sprintf( "%.2f", fSumPrice );

    m_stSaleHead.fOughtAmt = fSumPrice;
    m_stSaleHead.nSaleTotalNum = m_mapSaleDetailInfo.size();
    m_stSaleHead.fAllDisAmt += m_stSaleHead.fCouponDisAmt;//其他优惠+优惠券优惠金额
    QString strAllDisAmt = CommonFun::floatToString( m_stSaleHead.fAllDisAmt );
    SaleHeadAgent::Instance()->insertSaleHeadTable( m_stSaleHead );
    emit sig_updateGoodsSumPrice( strSumPrice, strAllDisAmt );
}

void GoodsSellListWidget::updateSaleHeadDisPrice()
{
    float fAllDisAmt = 0.00;
    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
        fAllDisAmt += it.value().fAllDisAmt;
    }

    m_stSaleHead.fAllDisAmt = fAllDisAmt;//优惠总金额
}

void GoodsSellListWidget::updateSaleHeadMemPrice()
{
    float fDisAmt = 0.00;
    //会员优惠金额
    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
        if( it.value().fGrantDisRate == 0 ) {
            if( m_bMemSell && it.value().fMemPrice>0.00 ) {
                it.value().fAllDisAmt = (it.value().fPrice - it.value().fMemPrice)*it.value().goodsInfo.fNumber;
                fDisAmt += it.value().fAllDisAmt;
            }
        } else {
            fDisAmt += it.value().fAllDisAmt;
        }
    }
    m_stSaleHead.fAllDisAmt = fDisAmt;
}

void GoodsSellListWidget::updateSaleHeadDisRate()
{
//    float fGrantDisRate = 0.00;
//    bool bDisEq = true;
//    //会员优惠金额
//    QMap< int, SaleDetails >::iterator it = m_mapSaleDetailInfo.begin();
//    fGrantDisRate = it.value().fGrantDisRate;
//    for( ; it != m_mapSaleDetailInfo.end(); ++it ) {
//        if( fGrantDisRate != it.value().fGrantDisRate  ) {
//            bDisEq = false;
//            break;
//        }
//    }

//    if( bDisEq ) {
//        m_stSaleHead.fGrantDisRate = fGrantDisRate;
//    } else {
//        m_stSaleHead.fGrantDisRate = 0.0;
//    }
}

int GoodsSellListWidget::getPageNum( int nGoodsPos )
{
    int nPageNum = nGoodsPos/m_nOnePageCount;
    int nRemainder = nGoodsPos%m_nOnePageCount;
    if( nRemainder >= 1 ) {
        nPageNum += 1;
    }

    if( nPageNum < 1 ) {
        nPageNum = 1;
    }

    return nPageNum;
}

void GoodsSellListWidget::goodsToSaleDetail( GoodsDetailInfo &stGoodsDetail
                                             , const GoodsInfo& stGoodsInfo )
{
//    stGoodsDetail.nPos = nPos;
//    stGoodsDetail.nSaleDetailPos = m_nSaleDetailPos;
    if( m_bMemSell && stGoodsInfo.fMemberPrice>0.00 ) {
        stGoodsDetail.fPrice = stGoodsInfo.fMemberPrice;
    } else {
        stGoodsDetail.fPrice = stGoodsInfo.fPrice;
    }
//    stGoodsDetail.fNumber = 1;//test数据
    stGoodsDetail.nCategoryId = stGoodsInfo.nCategoryId;
    stGoodsDetail.strGoodsCode = stGoodsInfo.sCode;
    stGoodsDetail.nGoodsId = stGoodsInfo.nId;
    stGoodsDetail.bStandard = stGoodsInfo.bStandard;
    stGoodsDetail.sGoodsName = stGoodsInfo.sName;
    stGoodsDetail.sUnit = stGoodsInfo.sSaleUnit;
    stGoodsDetail.nTasteType = stGoodsInfo.nPluGrade;
    stGoodsDetail.bPromotion = stGoodsInfo.bPromotion;
    QString strSumPrice = CommonFun::handleMoneyCoin(stGoodsDetail.fPrice * stGoodsDetail.fNumber);
    stGoodsDetail.sSumPrice = strSumPrice;
}

void GoodsSellListWidget::saleDetailToGoods( GoodsInfo &stGoodsInfo
                                             , const GoodsDetailInfo &stGoodsDetail )
{
    Q_UNUSED( stGoodsInfo )
    Q_UNUSED( stGoodsDetail )
}

//促销解析
void GoodsSellListWidget::parsePromotion(PromotionDetails *PromotionInfo)
{
    Q_UNUSED( PromotionInfo )
}
