#include "SaleCtrl.h"
#include "CategoryInfoAgent.h"
#include "SaleHeadAgent.h"
#include "SaleDetailsAgent.h"
#include "PayDetailsAgent.h"
#include "OnlineStateAgent.h"
#include "MemCardInfoAgent.h"
#include "KPosSetAgent.h"
#include "../util/KPosIni.h"
#include "../util/KPosLog.h"
#include "InStockAgent.h"
#include "QuickAddGoodsAgent.h"
#include "SatementAgent.h"
#include <QDebug>

SaleCtrl::SaleCtrl( QObject *parent )
    : QObject( parent )
{
    initConnect();
    init();
}

SaleCtrl::~SaleCtrl()
{
    clearCategoryInfo();
}

void SaleCtrl::updateCategoryAndGoodsInfo()
{
    clearCategoryInfo();

    QList<CategoryInfo_s> categoryInfoList;
    CategoryInfoAgent::instance()->getCategoryList(categoryInfoList);

    QMap<int, GoodsInfo_s> goodsInfoMap;
    QMap<int, QList<GoodsInfo_s> > goodsInfoSecondMap;
    CategoryInfoAgent::instance()->getGoodsList(goodsInfoMap, goodsInfoSecondMap);

    int nCategoryLen = categoryInfoList.length();
    CategoryInfo_s categoryInfo_s;
    int nGoodsLen = -1;
    CategoryInfo *pCategoryInfo = NULL;
    GoodsInfo goodsInfoFirst;
    GoodsInfo goodsInfoSecond;
    int nGoodsId = -1;

    for (int i = 0; i < nCategoryLen; i++)
    {
        pCategoryInfo = new CategoryInfo;
        categoryInfo_s = categoryInfoList[i];
        nGoodsLen = categoryInfo_s.goodsIdList.length();
        for (int j = 0; j < nGoodsLen; j++)
        {
            nGoodsId = categoryInfo_s.goodsIdList[j];
            if (goodsInfoMap.contains(nGoodsId))
            {
                goodsInfoProtocolToLocal(goodsInfoFirst, goodsInfoMap.value(nGoodsId));
                goodsInfoFirst.goodsInfoList.clear();
                if (goodsInfoSecondMap.contains(nGoodsId))
                {
                    QList<GoodsInfo_s> goodsInfo_sSecondList= goodsInfoSecondMap.value(nGoodsId);
                    for (int k = 0; k < goodsInfo_sSecondList.length(); k++)
                    {
                        goodsInfoProtocolToLocal(goodsInfoSecond, goodsInfo_sSecondList[k]);
                        goodsInfoFirst.goodsInfoList.append(goodsInfoSecond);
                    }
                }
                pCategoryInfo->listGoodsInfo.append(goodsInfoFirst);
            }
        }
        pCategoryInfo->nId = categoryInfo_s.nId;
        pCategoryInfo->sName = categoryInfo_s.sName;
        pCategoryInfo->bCustom = categoryInfo_s.bCustom;
        pCategoryInfo->sKeyId = categoryInfo_s.sKeyId;
        m_listCategoryInfo.append(pCategoryInfo);
    }
}

void SaleCtrl::searchGoodsInfo(QString sSearchText, QList<GoodsInfo> &goodsInfoList)
{
    QList<GoodsInfo_s> listGoodsInfoS;
    CategoryInfoAgent::instance()->searchGoods(sSearchText, listGoodsInfoS );
    int nLen = listGoodsInfoS.length();
    for(int i = 0; i < nLen; i++)
    {
        GoodsInfo stGoodsInfo;
        goodsInfoProtocolToLocal(stGoodsInfo, listGoodsInfoS[i]);
        goodsInfoList.append(stGoodsInfo);
    }
}

bool SaleCtrl::searchGoodsInfo( QString strGoodsInfo )
{
    QList<GoodsInfo_s> listGoodsInfoS;
    bool bHas = CategoryInfoAgent::instance()->searchGoods( strGoodsInfo, listGoodsInfoS );
    if( !bHas ) return bHas;

    if( listGoodsInfoS.size() == 0 ) return false;
    QList<GoodsInfo> listGoodsInfo;
    int nLen = listGoodsInfoS.length();

    for(int i = 0; i < nLen; i++)
    {
        GoodsInfo stGoodsInfo;
        goodsInfoProtocolToLocal(stGoodsInfo, listGoodsInfoS[i]);
        listGoodsInfo.append(stGoodsInfo);
    }

    if( listGoodsInfo.size() == 1 ) {
        emit sig_searchGoodsInfo( listGoodsInfo[0] );
    } else {
        emit sig_goodsInfo( listGoodsInfo );
    }
    return true;
}

void SaleCtrl::clearSearchGoodsInfo()
{
//    QList<GoodsInfo*>::iterator itSearch = m_listSearchGoodsInfo.begin();
//    while( itSearch != m_listSearchGoodsInfo.end() ) {
//        GoodsInfo *pGoodsInfo = *itSearch;
//        itSearch = m_listSearchGoodsInfo.erase( itSearch );
//        if( pGoodsInfo ) {
//            delete pGoodsInfo;
//            pGoodsInfo = NULL;
//        }
    //    }
}

//打印上张小票
void SaleCtrl::printLastReceipt( MemRegisterInfo_s stMemRegInfo )
{
    //获取最后一条完成的销售数据
    QString strOrderNum = SaleHeadAgent::Instance()->findStatusToLastSaleOrderNum( e_headComplete );
    if( strOrderNum.isEmpty() ) return;

    //1. 销售订单
    SaleHead stSaleHead;
    SaleHeadAgent::Instance()->findSaleHead( strOrderNum, stSaleHead );
    //2. 销售明细
    QList<SaleDetails> listSaleDetails;
    SaleDetailsAgent::Instance()->findSaleDetails( strOrderNum, listSaleDetails );
    int nTotalNum = listSaleDetails.size();
    stSaleHead.nSaleTotalNum = nTotalNum;
    //3. 支付明细
    QList<PayDetail_s> listPayDetails;
    PayDetailsAgent::Instance()->findData( strOrderNum, listPayDetails );

    SaleHeadAgent::Instance()->printReceipt( strOrderNum, stSaleHead, listSaleDetails, listPayDetails, stMemRegInfo);
}

void SaleCtrl::peeling()
{
    BalanceManage::instance()->autoClearTareWeight();
}

void SaleCtrl::getCategoryInfoList(QList<CategoryInfo*> &categoryInfoList)
{
    categoryInfoList = m_listCategoryInfo;
}

int SaleCtrl::getSaleHeadPendingNum()
{
    QMap< int, SaleHead> mapSaleHead;
    SaleHeadAgent::Instance()->findStatusToSaleHead( e_headPending, mapSaleHead );
    return mapSaleHead.size();
}

bool SaleCtrl::isSaleReceipt(QString sOrderNum, SaleHead &saleHead)
{
    bool bFind = SaleHeadAgent::Instance()->findSaleHead(sOrderNum, saleHead);
    return (bFind && (saleHead.nSaleType == 0));
}

void SaleCtrl::findSaleDetails(const QString &searchText, QList<SaleDetails> &listSaleDetails)
{
    QList<QString> refundOrderNumList;
    SaleHeadAgent::Instance()->getFinishRefundOrderNumList(searchText, refundOrderNumList);
    SaleDetailsAgent::Instance()->findRefundSaleDetails(searchText, listSaleDetails, refundOrderNumList);
}

//bool SaleCtrl::isRefundFinish(QString sRefundOrderNum)
//{
//    SaleHead saleHead;
//    bool bFind = SaleHeadAgent::Instance()->findRefundSaleHead(sRefundOrderNum, saleHead);
//    bool bFinish = (saleHead.nStatus == e_headComplete);
//    return (bFind && bFinish);
//}

void SaleCtrl::getFinishRefundOrderNumList(QString sOrderNum, QList<QString> &refundOrderNumList)
{
    SaleHeadAgent::Instance()->getFinishRefundOrderNumList(sOrderNum, refundOrderNumList);
}

void SaleCtrl::getRefundGoodsReasonListRequest()
{
    SaleDetailsAgent::Instance()->getRefundGoodsReasonListRequest();
}

void SaleCtrl::getMemInfoForRefundRequest(QString strMemCardId)
{
    MemCardInfoAgent::instance()->memQueryForRefundRequest(strMemCardId);
}

void SaleCtrl::searchReceiptRequst(QString sOrderNum)
{
    SaleDetailsAgent::Instance()->searchReceiptRequst(sOrderNum);
}

bool SaleCtrl::isReceiptFormat(QString searchText)
{
    QString sPosCode = KPosIni::getPosCode();
    return (searchText.length() == (sPosCode.length() + 11));
}

bool SaleCtrl::isOnline()
{
    return OnlineStateAgent::instance()->isOnline();
}

void SaleCtrl::printRefundReceipt(QString strOrderNum, const SaleHead &stSaleHead, const QList<SaleDetails> &listSaleDetails
                            , const QList<PayDetail_s> &listPayDetails , const MemRegisterInfo_s &stMemRegInfo)
{
    SaleHeadAgent::Instance()->printRefundReceipt( strOrderNum, stSaleHead, listSaleDetails, listPayDetails, stMemRegInfo );
}

void SaleCtrl::getCategoryNodeList(QList<CategoryInfoNode> &nodeList)
{
    KPosSet kPosSet;
    KPosSetAgent::instance()->getKPosSetInfo(kPosSet);
    nodeList = kPosSet.categoryNodeSet.nodeList;
}

void SaleCtrl::getQuickGoodsInfoRequest(QString sCategoryCode)
{
    QuickAddGoodsAgent::instance()->getQuickGoodsInfoRequest(sCategoryCode);
}

void SaleCtrl::createQuickGoodsRequest(const ProductInfo &info)
{
    QuickAddGoodsAgent::instance()->createQuickGoodsRequest(info);
}

void SaleCtrl::startUpdateThread()
{
    emit QuickAddGoodsAgent::instance()->sigStartUpdateThread();
}

void SaleCtrl::updateMemberIntegralRequest(float fMoney, QString sCardNum, QString sOrderNum, QString sRefundOrderNum)
{
    SatementAgent::Instance()->updateMemberIntegralRequest(fMoney, sCardNum, sOrderNum, sRefundOrderNum);
}

void SaleCtrl::getIntegralPayMoney(float &fMoney, QString sOrderNum)
{
    SatementAgent::Instance()->getIntegralPayMoney(fMoney, sOrderNum);
}

void SaleCtrl::getPayIntegral(int &nIntegral, QString sOrderNum)
{
    SatementAgent::Instance()->getPayIntegral(nIntegral, sOrderNum);
}

void SaleCtrl::slot_getGoodsList(QString sCategoryKeyId)
{
    //通过分类id，获取该分类下所有的商品
    QList<GoodsInfo> listGoodsInfo;
    QList<CategoryInfo*>::iterator it = m_listCategoryInfo.begin();
    for( ; it != m_listCategoryInfo.end(); ++it ) {
        if( (*it)->sKeyId == sCategoryKeyId ) {
            listGoodsInfo = (*it)->listGoodsInfo;
            emit sig_goodsInfo( listGoodsInfo );

            break;
        }
    }
}

//加载分类数据到分类按钮
void SaleCtrl::slot_addCategoryData()
{
    //1. 加载到分类按钮
    emit sig_allCategoryInfo( m_listCategoryInfo );
}

void SaleCtrl::slot_categoryGoodsChanged()
{
    qDebug()<<QStringLiteral("商品有改变 33333333333");
//    updateCategoryAndGoodsInfo();
    emit sigCategoryGoodsChanged();    
}

void SaleCtrl::initConnect()
{
    connect( BalanceManage::instance(), SIGNAL(sig_stableInfo(EBalanceStandard_Ex,bool))
             , this, SIGNAL( sig_stableInfo(EBalanceStandard_Ex,bool) ) );
    connect(CategoryInfoAgent::instance(), SIGNAL(sigCategoryGoodsChanged()), this, SLOT(slot_categoryGoodsChanged()));
    qRegisterMetaType<QList<RefundGoodsReason> >("QList<RefundGoodsReason>");
    connect(SaleDetailsAgent::Instance(), SIGNAL(sigOnGetRefundGoodsReasonList(int,QString,QList<RefundGoodsReason>))
            , this, SIGNAL(sigOnGetRefundGoodsReasonList(int,QString,QList<RefundGoodsReason>)));
    qRegisterMetaType<SaleHead>("SaleHead");
    qRegisterMetaType<QList<SaleDetails> >("QList<SaleDetails>");
    connect(SaleDetailsAgent::Instance(), SIGNAL(sigOnSearchReceipt(int,QString,SaleHead,QList<SaleDetails>, float, int))
            , this, SIGNAL(sigOnSearchReceipt(int,QString,SaleHead,QList<SaleDetails>, float, int)));
    qRegisterMetaType<MemRegisterInfo_s>("MemRegisterInfo_s");
    connect(MemCardInfoAgent::instance(), SIGNAL(sigOnMemInfoQueryForRefund(int,QString,MemRegisterInfo_s))
            , this, SIGNAL(sigOnMemInfoQueryForRefund(int,QString,MemRegisterInfo_s)));
    connect(QuickAddGoodsAgent::instance(), &QuickAddGoodsAgent::sigOnGetQuickGoodsInfo, this, &SaleCtrl::sigOnGetQuickGoodsInfo);
    connect(QuickAddGoodsAgent::instance(), &QuickAddGoodsAgent::sigOnCreateQuickGoods, this, &SaleCtrl::sigOnCreateQuickGoods);
}

void SaleCtrl::init()
{
    updateCategoryAndGoodsInfo();

    /*for (int i = 0; i < 1; i++)
    {
        CategoryInfo categoryInfo;
        categoryInfo.nCategoryId = i;
        categoryInfo.sName = QStringLiteral("热销%1").arg(i+1);

        for( int j = 1; j < 40; ++j ) {
            GoodsInfo pGoodsInfo;
            pGoodsInfo.nId = j;
            pGoodsInfo.sName = "进口超级无敌无籽沙壤大西瓜";
            pGoodsInfo.strCode = "1";
            pGoodsInfo.fPrice = 12.11;
            pGoodsInfo.sSaleUnit = "公斤";
            pGoodsInfo.bStandard = true;//标品
            pGoodsInfo.nTasteType = j;
            pGoodsInfo.bPromotion = true;
            pGoodsInfo.bAllowSell = true;
            categoryInfo.listGoodsInfo.append( pGoodsInfo );
        }

        m_listCategoryInfo.append( categoryInfo );
    }

    for (int i = 1; i < 35; i++)
    {
        CategoryInfo categoryInfo;
        categoryInfo.nCategoryId = i;
        categoryInfo.sName = QStringLiteral("热销%1").arg(i+1);

        GoodsInfo pGoodsInfo;
        pGoodsInfo.nId = 40 + i;
        pGoodsInfo.sName = "进口超级无敌无籽沙壤大西瓜";
        pGoodsInfo.strCode = "1";
        pGoodsInfo.fPrice = 12.11;
        pGoodsInfo.sSaleUnit = "公斤";
        pGoodsInfo.bStandard = false;//非标品
        pGoodsInfo.nTasteType = 0;//无口味分级
        pGoodsInfo.bPromotion = false;
        pGoodsInfo.bAllowSell = true;
        categoryInfo.listGoodsInfo.append( pGoodsInfo );

        m_listCategoryInfo.append( categoryInfo );
    }*/
}

void SaleCtrl::goodsInfoProtocolToLocal( GoodsInfo &stGoodsInfo, const GoodsInfo_s &stGoodsInfoS )
{
    stGoodsInfo.nId = stGoodsInfoS.nId;
    stGoodsInfo.sCode = stGoodsInfoS.sCode;
    stGoodsInfo.sBarCode = stGoodsInfoS.sBarCode;
    stGoodsInfo.sName = stGoodsInfoS.sName;
    stGoodsInfo.sShortName = stGoodsInfoS.sShortName;
    stGoodsInfo.sPinYinName = stGoodsInfoS.sPinYinName; // 拼音助记码
    stGoodsInfo.sWuBiName = stGoodsInfoS.sWuBiName; // 五笔助记码
    stGoodsInfo.sPluCode = stGoodsInfoS.sPluCode; // plu码
    stGoodsInfo.sPluName = stGoodsInfoS.sPluName; // 商品Plu名称
    stGoodsInfo.nPluGrade = stGoodsInfoS.nPluGrade; // 商品plu等级
//    stGoodsInfo.nCategoryId = stGoodsInfoS.nCategoryId;
    stGoodsInfo.fPrice = stGoodsInfoS.goodsPriceInfo.fPrice;
    stGoodsInfo.fMemberPrice = stGoodsInfoS.goodsPriceInfo.fMemberPrice;
//    stGoodsInfo.nTasteType = stGoodsInfoS.nTasteType;
    stGoodsInfo.bStandard = stGoodsInfoS.bStandard;
    stGoodsInfo.sSaleUnit = stGoodsInfoS.sSaleUnit;
    stGoodsInfo.sSpeUnit = stGoodsInfoS.sSpeUnit;
    stGoodsInfo.sCategoryName = stGoodsInfoS.sCategoryName;
    stGoodsInfo.fMarkNum=stGoodsInfoS.fMarkNum;
//    stGoodsInfo.bAllowSell = stGoodsInfoS.bAllowSell;
}

//需要添加锁
void SaleCtrl::clearCategoryInfo()
{
    QList<CategoryInfo*>::iterator it = m_listCategoryInfo.begin();
    while( it != m_listCategoryInfo.end() ) {
        //对商品信息delete
//        QList<GoodsInfo*> listGoodsInfo = (*it)->listGoodsInfo;
//        QList<GoodsInfo*>::iterator itGoods = listGoodsInfo.begin();
//        while( itGoods != listGoodsInfo.end() ) {
//            GoodsInfo *pGoodsInfo = *itGoods;
//            itGoods = listGoodsInfo.erase( itGoods );
//            if( pGoodsInfo ) {
//                delete pGoodsInfo;
//                pGoodsInfo = NULL;
//            }
//        }

        CategoryInfo *pCategoryInfo = *it;
        it = m_listCategoryInfo.erase( it );
        if( pCategoryInfo ) {
            delete pCategoryInfo;
            pCategoryInfo = NULL;
        }
    }

    m_listCategoryInfo.clear();
}
