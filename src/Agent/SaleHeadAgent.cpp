#include "SaleHeadAgent.h"
#include "ThreadManager.h"
#include "PosDBFactory.h"
#include "ReceiptPictureMaker.h"
#include "CategoryInfoAgent.h"
#include "KPosIni.h"
#include "CommonFun.h"
#include "EnumToString.h"
#include <QDebug>

SaleHeadAgent *SaleHeadAgent::m_pInstance = NULL;

SaleHeadAgent::SaleHeadAgent(QObject *parent)
    : QObject(parent)
    , sLastOrderNumber("")
{
    moveToThread( ThreadManager::getAgentThread() );
    ThreadManager::getAgentThread()->start();
}

SaleHeadAgent::~SaleHeadAgent()
{

}

SaleHeadAgent *SaleHeadAgent::Instance()
{
    if( m_pInstance == NULL ) {
        m_pInstance = new SaleHeadAgent( );
    }
    return m_pInstance;
}

void SaleHeadAgent::Release()
{
    if( m_pInstance ) {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

void SaleHeadAgent::insertSaleHeadTable( const SaleHead &stSaleHead )
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->replaceSaleHead( stSaleHead );
}

void SaleHeadAgent::updateStatus( const QString &strOrderNum, const ESaleHeadStatus &eSaleHeadStatus )
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->updateStatus( strOrderNum, eSaleHeadStatus );
}

void SaleHeadAgent::updateStatus( const QString &strOrderNum, const ESaleHeadStatus &eSaleHeadStatus, const QDateTime &dtFactorTime )
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->updateStatus( strOrderNum, eSaleHeadStatus, dtFactorTime );
}

void SaleHeadAgent::updateCompleteTime( const QString &strOrderNum, const QDateTime &dtCompleteTime )
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->updateCompleteTime( strOrderNum, dtCompleteTime );
}

void SaleHeadAgent::deleteSaleHeadTable( const QString &strOrderNum )
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->deleteSaleHead( strOrderNum );
}

void SaleHeadAgent::findSaleHead( int nDayBefore, QList<QString> &listOrderNum )
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->findSaleHead( nDayBefore, listOrderNum );
}

bool SaleHeadAgent::findSaleHead( const QString &strOrderNum, SaleHead &stSaleHead )
{
    return PosDBFactory::getPosDB()->m_pSaleHeadTable->findSaleHead( strOrderNum, stSaleHead );
}

//bool SaleHeadAgent::findRefundSaleHead(QString sRefundOrderNum, SaleHead &saleHead)
//{
//    return PosDBFactory::getPosDB()->m_pSaleHeadTable->findRefundSaleHead(sRefundOrderNum, saleHead);
//}

void SaleHeadAgent::getFinishRefundOrderNumList(QString sOrderNum, QList<QString> &refundOrderNumList)
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->getFinishRefundOrderNumList(sOrderNum, refundOrderNumList);
}

void SaleHeadAgent::findAllUnUploadSale( QList<SaleHead> &listSaleHead )
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->findAllUnUploadSale( listSaleHead );
}

void SaleHeadAgent::findStatusToSaleHead( const ESaleHeadStatus &eSaleHeadStatus, QMap< int, SaleHead> &mapSaleHead )
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->findStatusToSaleHead( eSaleHeadStatus, mapSaleHead );
}

void SaleHeadAgent::clearSaleHeadTable()
{

}

int SaleHeadAgent::getLastSaleHeadId()
{
    int nLastSaleHeadId = PosDBFactory::getPosDB()->m_pSaleHeadTable->getLastSaleHeadId();
    return nLastSaleHeadId;
}

int SaleHeadAgent::getPendingOrder()
{
    int nPendingOrderNum = PosDBFactory::getPosDB()->m_pSaleHeadTable->getPendingOrder();
    return nPendingOrderNum;
}


QString SaleHeadAgent::findStatusToLastSaleOrderNum( ESaleHeadStatus eSaleHeadStatus )
{
    if (!sLastOrderNumber.isEmpty())
    {
        return sLastOrderNumber;
    }

    return PosDBFactory::getPosDB()->m_pSaleHeadTable->findStatusToLastSaleOrderNum( eSaleHeadStatus );
}

//打印小票
void SaleHeadAgent::printReceipt(QString strOrderNum, const SaleHead &stSaleHead, const QList<SaleDetails> &listSaleDetails,
                                 const QList<PayDetail_s> &listPayDetails, const MemRegisterInfo_s &stMemRegInfo)
{
    sLastOrderNumber = stSaleHead.strOrderNum;
    bool isRefund = stSaleHead.nSaleType;
    //获取所有分类名
    QList<CategoryInfo_s> categoryInfoList;
    CategoryInfoAgent::instance()->getCategoryList(categoryInfoList);

    ReceiptPrintData stReceiptPrint;
    ReceiptShopInfo shopInfo; // 门店信息
    ReceiptSettlementInfo settlementInfo; // 小票结算信息
//    ReceiptSettleTypeCount settleTypeCount; // 付款方式统计

    stReceiptPrint.sBarcode = strOrderNum;

    shopInfo.sShopCode = QString::number( KPosIni::getShopId() );
    shopInfo.sKPosCode = KPosIni::getPosCode();
    shopInfo.sSaleman = KPosIni::getUserName();
    shopInfo.sSaleGuide = stSaleHead.strShoppingName;
    shopInfo.sSequence = strOrderNum;
    shopInfo.sDealTime = stSaleHead.dtCompleteTime.toString( "yyyy-MM-dd hh:mm:ss" );// 交易完成时间
    stReceiptPrint.shopInfo = shopInfo;

    QList<ReceiptCategoryCount> categoryCountList; // 分类统计列表（所有商品所对应的分类，以及该分类下有多少商品）
    QList<ReceiptSaleGoodsInfo> saleGoodsInfoList; // 物品销售列表,所有商品明细

    QList<SaleDetails>::const_iterator it = listSaleDetails.begin();

    int nTotalNum = 0;
    for( ; it != listSaleDetails.end(); ++it ) {
        ReceiptSaleGoodsInfo stGoodsInfo;
        stGoodsInfo.sGoodsName = it->strGoodsName;// 名称
        stGoodsInfo.sGoodsShortName = it->goodsInfo.strGoodsShortName; // 商品简称
        stGoodsInfo.sGoodsCode = it->goodsInfo.strGoodsCode; // 商品编号
        stGoodsInfo.sGoodsUnit = it->goodsInfo.sUnit;// 单位
        if(isRefund && -it->goodsInfo.fRefundNumber < 0.00001f)
        {
            continue;
        }
        stGoodsInfo.sGoodsNum = CommonFun::floatToString3(it->goodsInfo.fNumber);// 数量
        stGoodsInfo.sGoodsSumPrice = it->goodsInfo.sSumPrice;// 总价
        nTotalNum++;
        stGoodsInfo.sGoodsPrice = CommonFun::floatToString(it->goodsInfo.fPrice);// 单价
        saleGoodsInfoList.append( stGoodsInfo );

        QString strCateName = "";
        int nCategoryLen = categoryInfoList.length();
        CategoryInfo_s categoryInfo_s;
        for (int i = 0; i < nCategoryLen; i++)
        {
            categoryInfo_s = categoryInfoList[i];
            if (categoryInfo_s.bCustom)
            {
                continue;
            }
            if (categoryInfo_s.goodsIdList.size() == 0)
            {
                continue;
            }
            if (categoryInfo_s.goodsIdList.contains(it->nGoodsId))
            {
                strCateName = categoryInfo_s.sName;
                break;
            }
        }

        bool bHas = false;
        QList<ReceiptCategoryCount>::iterator itReceiptCate = categoryCountList.begin();
        for( ; itReceiptCate != categoryCountList.end(); ++itReceiptCate ) {
            if( itReceiptCate->sCategoryName == strCateName ) {
                itReceiptCate->nTotalNum += 1;
                float fSumPrice = itReceiptCate->strTotalPrice.toFloat() + stGoodsInfo.sGoodsSumPrice.toFloat();
                itReceiptCate->strTotalPrice = CommonFun::floatToString( fSumPrice );
                bHas = true;
                break;
            }
        }

        if( !bHas ) {
            ReceiptCategoryCount stReceipt;
            stReceipt.nTotalNum = 1;
            stReceipt.strTotalPrice = stGoodsInfo.sGoodsSumPrice;
            stReceipt.sCategoryName = strCateName;
            categoryCountList.append( stReceipt );
        }
    }

    stReceiptPrint.saleInfo.categoryCountList = categoryCountList;
    stReceiptPrint.saleInfo.saleGoodsInfoList = saleGoodsInfoList;

    settlementInfo.sSumPrice = CommonFun::floatToString( stSaleHead.fFactorAmt + stSaleHead.fAllDisAmt- stSaleHead.fProfitLoss );// 总计金额 = 应收金额 + 优惠金额+损益金额
    settlementInfo.sSumNumber = QString::number( nTotalNum );// 总计数量
    //settlementInfo.sMemberCutMoney = CommonFun::floatToString( stSaleHead.fMemDisAmt );// 会员优惠
    //settlementInfo.sDiscountMoney = CommonFun::floatToString( stSaleHead.fGrantDisAmt );// 折扣金额
    settlementInfo.sAllDisAmt = CommonFun::floatToString( stSaleHead.fAllDisAmt - stSaleHead.fProfitLoss );//总优惠金额:打印小票中需要添加损益
    settlementInfo.sWantGetPrice = CommonFun::floatToString( stSaleHead.fOughtAmt ); // 应收金额
    settlementInfo.sRealGetPrice = CommonFun::floatToString( stSaleHead.fFactorAmt);// 实收金额
    settlementInfo.sReturnMoney = CommonFun::floatToString( stSaleHead.fOddChange );// 找零金额
    stReceiptPrint.settlementInfo = settlementInfo;

    ReceiptMemberInfo stMemberInfo; // 会员信息
    stMemberInfo.sAccount = stMemRegInfo.stMemInfo.strCardNo; // 会员账号
    stMemberInfo.sBalance = stMemRegInfo.stMemInfo.strAccountBalance; // 当前余额
    stMemberInfo.sGetIntegral = QString::number( stMemRegInfo.stMemInfo.nNewAddInt );// 本次积分(新增积分）
    stMemberInfo.sTotalIntegral = QString::number( stMemRegInfo.stMemInfo.nIntegral );// 剩余总积分
    stReceiptPrint.memberInfo = stMemberInfo;

    QList<PayDetail_s>::const_iterator itPay = listPayDetails.begin();
    for( ; itPay != listPayDetails.end(); ++itPay )
    {
        if (itPay->fPayMoney != 0)
        {
            if (!stReceiptPrint.settleTypeMap.contains(EnumToString::payMethodToString(itPay->nPayMethod)))
            {
                stReceiptPrint.settleTypeMap.insert(EnumToString::payMethodToString(itPay->nPayMethod), QString::number(itPay->fPayMoney, 'f', 2));
            }
            else
            {
                QString sOldValue = stReceiptPrint.settleTypeMap.value(EnumToString::payMethodToString(itPay->nPayMethod));
                stReceiptPrint.settleTypeMap.insert(EnumToString::payMethodToString(itPay->nPayMethod), QString::number(itPay->fPayMoney + sOldValue.toFloat(), 'f', 2));
            }
        }
    }

    stReceiptPrint.bRefund = false;

    ReceiptPictureMaker::instance()->printReceipt( stReceiptPrint );
}

void SaleHeadAgent::printRefundReceipt(QString strOrderNum, const SaleHead &stSaleHead, const QList<SaleDetails> &listSaleDetails, const QList<PayDetail_s> &listPayDetails, const MemRegisterInfo_s &stMemRegInfo)
{
    sLastOrderNumber = stSaleHead.strOrderNum;

    //获取所有分类名
    QList<CategoryInfo_s> categoryInfoList;
    CategoryInfoAgent::instance()->getCategoryList(categoryInfoList);

    ReceiptPrintData stReceiptPrint;
    ReceiptShopInfo shopInfo; // 门店信息
    ReceiptSettlementInfo settlementInfo; // 小票结算信息

    stReceiptPrint.sBarcode = strOrderNum;

    shopInfo.sShopCode = QString::number( KPosIni::getShopId() );
    shopInfo.sKPosCode = KPosIni::getPosCode();
    shopInfo.sSaleman = KPosIni::getUserName();
    shopInfo.sSequence = strOrderNum;
    shopInfo.sDealTime = stSaleHead.dtCompleteTime.toString( "yyyy-MM-dd hh:mm:ss" );// 交易完成时间
    stReceiptPrint.shopInfo = shopInfo;

    QList<ReceiptCategoryCount> categoryCountList; // 分类统计列表（所有商品所对应的分类，以及该分类下有多少商品）
    QList<ReceiptSaleGoodsInfo> saleGoodsInfoList; // 物品销售列表,所有商品明细

    QList<SaleDetails>::const_iterator it = listSaleDetails.begin();

    int nTotalNum = 0;
    for( ; it != listSaleDetails.end(); ++it ) {
        ReceiptSaleGoodsInfo stGoodsInfo;
        stGoodsInfo.sGoodsName = it->strGoodsName;// 名称
        stGoodsInfo.sGoodsShortName = it->goodsInfo.strGoodsShortName; // 商品简称
        stGoodsInfo.sGoodsCode = it->goodsInfo.strGoodsCode; // 商品编号
        stGoodsInfo.sGoodsUnit = it->goodsInfo.sUnit;// 单位
        if (-it->goodsInfo.fRefundNumber < 0.00001f)
        {
            continue;
        }
        stGoodsInfo.sGoodsNum = CommonFun::floatToString3(it->goodsInfo.fRefundNumber);// 退货数量
        stGoodsInfo.sGoodsSumPrice = it->goodsInfo.sRefundSumPrice;// 退货总价
        nTotalNum++;

        stGoodsInfo.sGoodsPrice = CommonFun::floatToString(it->goodsInfo.fPrice);// 单价
        saleGoodsInfoList.append( stGoodsInfo );

        QString strCateName = "";
        int nCategoryLen = categoryInfoList.length();
        CategoryInfo_s categoryInfo_s;
        for (int i = 0; i < nCategoryLen; i++)
        {
            categoryInfo_s = categoryInfoList[i];
            if (categoryInfo_s.bCustom)
            {
                continue;
            }
            if (categoryInfo_s.goodsIdList.size() == 0)
            {
                continue;
            }
            if (categoryInfo_s.goodsIdList.contains(it->nGoodsId))
            {
                strCateName = categoryInfo_s.sName;
                break;
            }
        }

        bool bHas = false;
        QList<ReceiptCategoryCount>::iterator itReceiptCate = categoryCountList.begin();
        for( ; itReceiptCate != categoryCountList.end(); ++itReceiptCate ) {
            if( itReceiptCate->sCategoryName == strCateName ) {
                itReceiptCate->nTotalNum += 1;
                float fSumPrice = itReceiptCate->strTotalPrice.toFloat() + stGoodsInfo.sGoodsSumPrice.toFloat();
                itReceiptCate->strTotalPrice = CommonFun::floatToString( fSumPrice );
                bHas = true;
                break;
            }
        }

        if( !bHas ) {
            ReceiptCategoryCount stReceipt;
            stReceipt.nTotalNum = 1;
            stReceipt.strTotalPrice = stGoodsInfo.sGoodsSumPrice;
            stReceipt.sCategoryName = strCateName;
            categoryCountList.append( stReceipt );
        }
    }

    stReceiptPrint.saleInfo.categoryCountList = categoryCountList;
    stReceiptPrint.saleInfo.saleGoodsInfoList = saleGoodsInfoList;

    settlementInfo.sSumPrice = CommonFun::floatToString(stSaleHead.fFactorAmt + stSaleHead.fAllDisAmt - stSaleHead.fProfitLoss);// 总计金额 = 应收金额 + 优惠金额+损益金额
    settlementInfo.sSumNumber = QString::number( nTotalNum );// 总计数量
    settlementInfo.sAllDisAmt = CommonFun::floatToString( stSaleHead.fAllDisAmt - stSaleHead.fProfitLoss );//总优惠金额:打印小票中需要添加损益
    settlementInfo.sWantGetPrice = CommonFun::floatToString( stSaleHead.fOughtAmt); // 应收金额
    settlementInfo.sRealGetPrice = CommonFun::floatToString( stSaleHead.fFactorAmt);// 实收金额
    settlementInfo.sReturnMoney = CommonFun::floatToString( stSaleHead.fOddChange );// 找零金额
    stReceiptPrint.settlementInfo = settlementInfo;

    ReceiptMemberInfo stMemberInfo; // 会员信息
    stMemberInfo.sAccount = stMemRegInfo.stMemInfo.strCardNo; // 会员账号
    stMemberInfo.sBalance = stMemRegInfo.stMemInfo.strAccountBalance; // 当前余额
    stMemberInfo.sGetIntegral = QString::number( stMemRegInfo.stMemInfo.nNewAddInt );// 本次积分(新增积分）
    stMemberInfo.sTotalIntegral = QString::number( stMemRegInfo.stMemInfo.nIntegral );// 剩余总积分
    stReceiptPrint.memberInfo = stMemberInfo;

    QList<PayDetail_s>::const_iterator itPay = listPayDetails.begin();
    for( ; itPay != listPayDetails.end(); ++itPay )
    {
        if (itPay->fPayMoney != 0)
        {
            if (!stReceiptPrint.settleTypeMap.contains(EnumToString::payMethodToString(itPay->nPayMethod)))
            {
                stReceiptPrint.settleTypeMap.insert(EnumToString::payMethodToString(itPay->nPayMethod), QString::number(itPay->fPayMoney, 'f', 2));
            }
            else
            {
                QString sOldValue = stReceiptPrint.settleTypeMap.value(EnumToString::payMethodToString(itPay->nPayMethod));
                stReceiptPrint.settleTypeMap.insert(EnumToString::payMethodToString(itPay->nPayMethod), QString::number(itPay->fPayMoney + sOldValue.toFloat(), 'f', 2));
            }
        }
    }

    stReceiptPrint.bRefund = true;
    ReceiptPictureMaker::instance()->printReceipt( stReceiptPrint );
}
