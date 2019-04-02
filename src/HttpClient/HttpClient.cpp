#include "HttpClient.h"
#include "HttpGetShopInfo.h"
#include "HttpRegisterPos.h"
#include "HttpCheckRegisterResult.h"
#include "HttpCheckIsOnline.h"
#include "HttpLoginKPos.h"
#include "HttpGetCategory.h"
#include "HttpGetAllGoods.h"
#include "HttpGetAllGoodsPrice.h"
#include "HttpUploadReceipt.h"
#include "HttpCheckKPosUpdate.h"
#include "HttpCreatPay.h"
#include "HttpQueryPay.h"
#include "HttpRevokePay.h"
#include "HttpCreatePayMemberCard.h"
#include "HttpUploadKPosSet.h"
#include "HttpDownloadKPosSet.h"
#include "HttpAddCustomCategory.h"
#include "HttpUpdateCustomCategory.h"
#include "HttpDeleteCustomCategory.h"
#include "HttpUploadScreenAD.h"
#include "HttpMemInfoQuery.h"
#include "HttpMemRecharge.h"
#include "HttpMemRegister.h"
#include "HttpMemPasswdModify.h"
#include "HttpMemSetStatus.h"
#include "HttpGetMemTypeList.h"
#include "HttpGetMemGradeList.h"
#include "HttpGetOPeratorList.h"
#include "HttpUpdateMemberIntegral.h"
#include "HttpGetOrderCategory.h"
#include "HttpGetOrderGoods.h"
#include "HttpCreateOrderCard.h"
#include "HttpRemoveOrderCard.h"
#include "HttpGetOrderCardList.h"
#include "HttpGetOrderCardListDetail.h"
#include "HttpUpdateOrderCardListDetail.h"
#include "HttpUploadOrderCard.h"
#include "HttpGetDeliveryOrderList.h"
#include "HttpReplaceMemCard.h"
#include "HttpReceiveGoodsStart.h"
#include "HttpReceiveGoodsEnd.h"
#include "HttpGetDeliveryDetail.h"
#include "HttpGetReceiveGoodsDetail.h"
#include "HttpSaveReceiveGoods.h"
#include "HttpGetAdjustPriceOrderList.h"
#include "HttpCheckAdjustPriceOrder.h"
#include "HttpRemoveAdjustPriceOrder.h"
#include "HttpSearchAdjustPriceOrder.h"
#include "HttpSaveAdjustPriceOrder.h"
#include "HttpGetStockOrderList.h"
/*入库部分*/
#include "HttpGetInStockOrderList.h"
#include "HttpSearchInStockOrder.h"
#include "HttpRemoveInStockOrder.h"
#include "HttpCheckInStockOrder.h"
#include "HttpSaveInStockOrder.h"

/*出库部分*/
#include "HttpGetOutStockOrderList.h"
#include "HttpSearchOutStockOrder.h"
#include "HttpRemoveOutStockOrder.h"
#include "HttpCheckOutStockOrder.h"
#include "HttpSaveOutStockOrder.h"

//快速建档
#include "HttpGetQuickGoodsInfo.h"
#include "HttpCreateQuickGoods.h"
#include "HttpCheckStockOrder.h"
#include "HttpRemoveStockOrder.h"
#include "HttpSearchStockOrder.h"
#include "HttpSaveStockOrder.h"
#include "HttpGetStockGoodsInfo.h"
#include "HttpGetRefundGoodsReasonList.h"
#include "HttpSearchReceipt.h"
#include "HttpUploadClientCashSubmit.h"
#include "HttpUploadClientCashSubmitSync.h"
#include "HttpGetAllUserInfo.h"
#include "HttpGetPayCode.h"
#include "HttpLogoutKPos.h"
#include "HttpCreateGoodsGroup.h"
#include "HttpGetGoodsGroupList.h"
#include "HttpSaveGoodsGroup.h"
#include "HttpAddBarcodeScale.h"
#include "HttpGetBarcodeScaleCode.h"
#include "HttpGetBarcodeScaleList.h"
#include "HttpUpdateScaleProductIssue.h"
#include "HttpDeleteScale.h"
#include "../util/CommonFun.h"
#include "../util/KPosIni.h"
#include "../util/KPosLog.h"
#include "../data/enumData.h"
#include "httpresetkey.h"

// 员工管理
#include "HttpGetEmployeeManageOrderList.h"
#include "HttpChangeEmployeeStatusOrder.h"
#include "HttpGetEmployeeScodeOrder.h"
#include "HttpEditEmployeeOrderRequest.h"

// 销售明细
#include "HttpGetSaleDetialOrderList.h"

// 报损
#include "HttpGetReportLossOrderList.h"
#include "HttpEditReportLoss.h"
#include "HttpAddReportLoss.h"
#include "HttpDeleteReportLoss.h"
#include "HttpCheckReportLoss.h"
#include "HttpGetReportLossDetial.h"

// 商品管理
#include "HttpGetGoodsManageList.h"
#include "HttpGetGoodsManageCategory.h"

HttpClient* HttpClient::m_pInstance = NULL;

HttpClient::HttpClient(QObject *parent)
    : QObject(parent)
    , m_pManager(NULL)
{
    m_pManager = new QNetworkAccessManager();
}

HttpClient *HttpClient::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new HttpClient;
    }
    return m_pInstance;
}

void HttpClient::setToken(QString sToken)
{
    m_sToken = sToken;
}

void HttpClient::getShopInfo(QString sCorpID, QString sShopCode)
{
    QString sUUID = CommonFun::getUUID();
    HttpGetShopInfo* p = new HttpGetShopInfo(sUUID, sCorpID, sShopCode);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::registerPos(QString sCorpID, QString sShopCode)
{
    QString sUUID = CommonFun::getUUID();
    HttpRegisterPos* p = new HttpRegisterPos(sCorpID, sShopCode, sUUID);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::checkRegisterResult()
{
    QString sUUID = CommonFun::getUUID();
    HttpCheckRegisterResult* p = new HttpCheckRegisterResult(sUUID);
    p->setNetManager(m_pManager);
    p->postRequest();

    //    KPosLog::instance()->writeTestLog( p->getTestUrl()); // 测试用
}

void HttpClient::checkIsOnline()
{
    QString sUUID = CommonFun::getUUID();

    QString sCorpID = KPosIni::getCorpID();
    HttpCheckIsOnline* p = new HttpCheckIsOnline(m_sToken, sCorpID, sUUID);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::loginKPos(QString sUserCode, QString sPassword)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    QString sAppName = CommonFun::getAppName();
    QString sAppVersion = CommonFun::getAppVersion();
    QString sOsVersion = CommonFun::getOsVersion();
    QString sBrandName = CommonFun::getBranchName();
    HttpLoginKPos* p = new HttpLoginKPos(sCorpID, sUserCode, sPassword, sUUID, sAppName, sAppVersion, sOsVersion, sBrandName);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::updateToken(QString sUserCode, QString sPassword)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    QString sAppName = CommonFun::getAppName();
    QString sAppVersion = CommonFun::getAppVersion();
    QString sOsVersion = CommonFun::getOsVersion();
    QString sBrandName = CommonFun::getBranchName();
    HttpLoginKPos* p = new HttpLoginKPos(sCorpID, sUserCode, sPassword, sUUID, sAppName, sAppVersion, sOsVersion, sBrandName, true);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::LogoutKPos(bool bGetReport)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpLogoutKPos* p = new HttpLogoutKPos(m_sToken, sCorpID, sUUID, bGetReport);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getAllUserInfoRequest()
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpGetAllUserInfo* p = new HttpGetAllUserInfo(m_sToken, sCorpID, sUUID );
    p->setNetManager( m_pManager );
    p->postRequest();
}

void HttpClient::getCategory(QString sLastTime)
{
    QString sUUID = CommonFun::getUUID();
    QString sCorpID = KPosIni::getCorpID();
    HttpGetCategory* p = new HttpGetCategory(m_sToken, sUUID, sCorpID, sLastTime);
    p->setNetManager(m_pManager);
    p->postRequest();
    //    KPosLog::instance()->writeTestLog(p->getTestUrl()); // 测试用
}

void HttpClient::getAllGoods(QString sLastTime)
{
    QString sUUID = CommonFun::getUUID();
    QString sCorpID = KPosIni::getCorpID();
    HttpGetAllGoods* p = new HttpGetAllGoods( m_sToken, sUUID, sCorpID, sLastTime);
    p->setNetManager(m_pManager);
    p->postRequest();
    //    KPosLog::instance()->writeTestLog(p->getTestUrl()); // 测试用
}

void HttpClient::getAllGoodsPrice(QString sLastTime)
{
    QString sUUID = CommonFun::getUUID();
    QString sCorpID = KPosIni::getCorpID();
    HttpGetAllGoodsPrice* p = new HttpGetAllGoodsPrice(sUUID, m_sToken, sCorpID, sLastTime);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::uploadReceipt( QString strSale )
{
    QString sUUID = CommonFun::getUUID();
    QString sCorpID = KPosIni::getCorpID();
    HttpUploadReceipt* p = new HttpUploadReceipt( m_sToken, sCorpID, sUUID, strSale );
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::checkKPosUpdate()
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    QString sAppVersion = CommonFun::getAppVersion();
    HttpCheckKPosUpdate* p = new HttpCheckKPosUpdate(sCorpID, sUUID, sAppVersion);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::createPayInfoRequest(EPayMethod ePayMethod, QString strBarCode, QString strPayAmt, QString strSale
                                      , QString sSaleDetailsJson, int nInteg, QString strPayPwd, QString strIntToAmt)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpCreatPay *pCreatPay= new HttpCreatPay(m_sToken, sCorpID, sUUID, ePayMethod, strBarCode, strPayAmt, strSale, sSaleDetailsJson, nInteg, strPayPwd, strIntToAmt );
    pCreatPay->setNetManager( m_pManager );
    pCreatPay->postRequest();
}

void HttpClient::createPayQueryRequest( int nPayMethod, QString strPayOrderNum )
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpQueryPay *pQueryPay = new HttpQueryPay( m_sToken, sCorpID, sUUID, nPayMethod, strPayOrderNum );
    pQueryPay->setNetManager( m_pManager );
    pQueryPay->postRequest();
}

void HttpClient::payRevokeRequest( EPayMethod ePayMethod, QString strPayOrderNum )
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpRevokePay *pRevokePay = new HttpRevokePay(m_sToken, sCorpID, sUUID ,ePayMethod, strPayOrderNum );
    pRevokePay->setNetManager( m_pManager );
    pRevokePay->postRequest();
}

void HttpClient::createPayMemberCard(QString strBarCode, QString strPayAmt, QString strSale, int nInteg, QString strPayPwd, QString strIntToAmt)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpCreatePayMemberCard *pCreatPay= new HttpCreatePayMemberCard(m_sToken, sCorpID, sUUID, strBarCode, strPayAmt, strSale, nInteg, strPayPwd, strIntToAmt);
    pCreatPay->setNetManager( m_pManager );
    pCreatPay->postRequest();
}

void HttpClient::updateMemberIntegral(float fMoney, QString sCardNum, QString sOrderNum, QString sRefundOrderNum)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpUpdateMemberIntegral* p = new HttpUpdateMemberIntegral(sCorpID, m_sToken, sUUID, fMoney, sCardNum, sOrderNum, sRefundOrderNum);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getRefundGoodsReasonList(bool bIsOnline)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpGetRefundGoodsReasonList *p = new HttpGetRefundGoodsReasonList(m_sToken, sCorpID, sUUID , bIsOnline);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::searchReceipt(QString sOrderNum)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpSearchReceipt* p = new HttpSearchReceipt(m_sToken, sCorpID, sUUID, sOrderNum, 0);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::uploadKPosSet(const KPosSet &kPosSet, bool bSync)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpUploadKPosSet *p = new HttpUploadKPosSet(sCorpID, m_sToken, sUUID, kPosSet, bSync);
    p->setNetManager(m_pManager);
    p->postRequest();
    //    KPosLog::instance()->writeTestLog(p->getTestUrl()); // 测试用
}

void HttpClient::downloadKPosSet(QString sLastTime)
{
    QString sUUID = CommonFun::getUUID();
    QString sCorpID = KPosIni::getCorpID();
    HttpDownloadKPosSet *p = new HttpDownloadKPosSet(m_sToken, sUUID, sCorpID, sLastTime);
    p->setNetManager(m_pManager);
    p->postRequest();
    //    KPosLog::instance()->writeTestLog(p->getTestUrl()); // 测试用
}

void HttpClient::addCustomCategory(QString sCategoryName, int nPos )
{
    QString sCorpID = KPosIni::getCorpID();
    int nShopID = KPosIni::getShopId();
    QString sUUID = CommonFun::getUUID();
    HttpAddCustomCategory *p = new HttpAddCustomCategory(sCorpID, m_sToken, nShopID, sUUID, sCategoryName, nPos );
    p->setNetManager(m_pManager);
    p->postRequest();
    //    KPosLog::instance()->writeTestLog(p->getTestUrl()); // 测试用
}

void HttpClient::updateCustomCategory(int nCategoryId, QString sCategoryName)
{
    QString sCorpID = KPosIni::getCorpID();
    int nShopID = KPosIni::getShopId();
    QString sUUID = CommonFun::getUUID();
    HttpUpdateCustomCategory *p = new HttpUpdateCustomCategory(sCorpID, m_sToken, nShopID, sUUID, nCategoryId, sCategoryName);
    p->setNetManager(m_pManager);
    p->postRequest();
    //    KPosLog::instance()->writeTestLog(p->getTestUrl()); // 测试用
}

void HttpClient::deleteCustomCategory(int nCategoryId)
{
    QString sCorpID = KPosIni::getCorpID();
    int nShopID = KPosIni::getShopId();
    QString sUUID = CommonFun::getUUID();
    HttpDeleteCustomCategory *p = new HttpDeleteCustomCategory(sCorpID, m_sToken, nShopID, sUUID, nCategoryId);
    p->setNetManager(m_pManager);
    p->postRequest();
    //    KPosLog::instance()->writeTestLog(p->getTestUrl()); // 测试用
}

void HttpClient::uploadScreenAD(QString sADPath)
{
    QString sUUID = CommonFun::getUUID();
    QString sCorpID = KPosIni::getCorpID();
    HttpUploadScreenAD *p = new HttpUploadScreenAD(m_sToken, sCorpID, sUUID, sADPath);
    p->setNetManager(m_pManager);
    p->postRequest();
    //    KPosLog::instance()->writeTestLog(p->getTestUrl()); // 测试用
}

void HttpClient::memQueryRequest( QString strMemCardId )
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpMemInfoQuery *p = new HttpMemInfoQuery(sCorpID, sUUID, strMemCardId, false);
    p->setNetManager(m_pManager);
    p->postRequest();

    //    KPosLog::instance()->writeTestLog(p->getTestUrl()); // 测试用
}

void HttpClient::memQueryForRefundRequest(QString strMemCardId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpMemInfoQuery *p = new HttpMemInfoQuery(sCorpID, sUUID, strMemCardId, true);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::memRechargeRequest( QString strMemCardId, QString strRechargeAmt \
                                     , int nPayMethod, int nOperatorId, QString strPayCode, bool bVirtual )
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    int nShopId = KPosIni::getShopId();
    HttpMemRecharge *p = new HttpMemRecharge(sCorpID, sUUID, strMemCardId, strRechargeAmt, nPayMethod, nOperatorId, strPayCode, nShopId, bVirtual);
    p->setNetManager(m_pManager);
    p->postRequest();

    //    KPosLog::instance()->writeTestLog(p->getTestUrl()); // 测试用
}

void HttpClient::memRegisterRequest( MemRegisterInfo_s stMemRegister )
{
    QString sCorpID = KPosIni::getCorpID();
    int nShopId = KPosIni::getShopId();
    HttpMemRegister *p = new HttpMemRegister( sCorpID, stMemRegister, nShopId );
    p->setNetManager(m_pManager);
    p->postRequest();

    //    KPosLog::instance()->writeTestLog(p->getTestUrl()); // 测试用
}

void HttpClient::memModifyPwdRequest(QString strCardId, QString strOldPwd, QString strNewPwd )
{
    QString sCorpID = KPosIni::getCorpID();
    HttpMemPasswdModify *p = new HttpMemPasswdModify( sCorpID, strCardId, strOldPwd, strNewPwd );
    p->setNetManager(m_pManager);
    p->postRequest();

    //    KPosLog::instance()->writeTestLog(p->getTestUrl()); // 测试用
}

void HttpClient::replaceMemCardRequest( QString strOldCardId, QString strNewCardId )
{
    QString sCorpID = KPosIni::getCorpID();
    QString strUserName = KPosIni::getUserCode();
    HttpReplaceMemCard *p = new HttpReplaceMemCard( sCorpID, strOldCardId, strNewCardId, strUserName );
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::memSetCardStatusRequest( QString strCardId, int nStatus )
{
    QString sCorpID = KPosIni::getCorpID();
    HttpMemSetStatus *p = new HttpMemSetStatus( sCorpID, strCardId, nStatus );
    p->setNetManager(m_pManager);
    p->postRequest();

    //    KPosLog::instance()->writeTestLog(p->getTestUrl()); // 测试用
}

void HttpClient::getMemTypeListRequest()
{
    HttpGetMemTypeList *p = new HttpGetMemTypeList();
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getMemGradeListRequest( int nMemTypeId )
{
    HttpGetMemGradeList *p = new HttpGetMemGradeList( nMemTypeId );
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getOPeratorListRequest()
{
    QString sCorpID = KPosIni::getCorpID();
    int nShopId = KPosIni::getShopId();
    HttpGetOPeratorList *p = new HttpGetOPeratorList( sCorpID, nShopId );
    p->setNetManager(m_pManager);
    p->postRequest();

    // KPosLog::instance()->writeTestLog(p->getTestUrl()); // 测试用
}

void HttpClient::getOrderCategory()
{
    int nLevel = 4; // 分类的层数
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpGetOrderCategory *p = new HttpGetOrderCategory(m_sToken, sCorpID, nLevel, e_getCategoryForOrder, sUUID);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getOrderGoods(QString searchPattern, int nLimit, int nOffset, const QList<int> &categoryIdList, QString sSortBy, QString sSort, int nCategoryBigId)
{
    int nShopId = KPosIni::getShopId();
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpGetOrderGoods *p = new HttpGetOrderGoods(m_sToken, nShopId, sCorpID, searchPattern, nLimit, nOffset, categoryIdList, sSortBy, sSort, nCategoryBigId, sUUID);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::createOrderCardRequest(const QList<OrderGoodsInfo *> &orderGoodsInfoList)
{
    int nShopId = KPosIni::getShopId();
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpCreateOrderCard *p = new HttpCreateOrderCard(m_sToken, nShopId, sCorpID, orderGoodsInfoList, sUUID);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::removeOrderCard(QList<int> orderIdList)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpRemoveOrderCard *p = new HttpRemoveOrderCard(m_sToken, sCorpID, sUUID, orderIdList);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getOrderCategoryForCheck()
{
    int nLevel = 1; // 分类的层数
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpGetOrderCategory *p = new HttpGetOrderCategory(m_sToken, sCorpID, nLevel, e_getCategoryForCheck ,sUUID);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getOrderCardList(int nLimit, int nOffset, const QList<int> &categoryIdList, QString sStartDate, QString sEndDate, QString sSearchText)
{
    int nShopId = KPosIni::getShopId();
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    int nStatus = 0; // 全部状态
    HttpGetOrderCardList *p = new HttpGetOrderCardList(m_sToken, nShopId, sCorpID, sUUID, nLimit, nOffset, categoryIdList, nStatus, sStartDate, sEndDate, sSearchText);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getOrderCardListDetail(const QList<int> &orderCardIdList, bool bUploadFinish)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpGetOrderCardListDetail *p = new HttpGetOrderCardListDetail(m_sToken, sCorpID, sUUID, orderCardIdList, bUploadFinish);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::updateOrderCardListDetail(const QMap<int, int> &changedNumMap, const QList<int> &orderCardIdList)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpUpdateOrderCardListDetail *p = new HttpUpdateOrderCardListDetail(m_sToken, sCorpID, sUUID, changedNumMap, orderCardIdList);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::uploadOrderCard(const QList<int> &orderCardIdList)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpUploadOrderCard *p = new HttpUploadOrderCard(m_sToken, sCorpID, sUUID, orderCardIdList);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getDeliveryOrderList(int nLimit, int nOffset, QString sStartDate, QString sEndDate)
{
    int nShopId = KPosIni::getShopId();
    int nProviderId = c_nNegativeNumber;
    QString sOrderCode = "";
    QString sOrderType = "";
    int nOrderStatus = c_nNegativeNumber;

    HttpGetDeliveryOrderList *p = new HttpGetDeliveryOrderList(m_sToken, nShopId, nLimit, nOffset, nProviderId, sOrderCode, sOrderType, nOrderStatus, sStartDate, sEndDate);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::startReceiveGoods(int nDeliveryId)
{
    HttpReceiveGoodsStart *p = new HttpReceiveGoodsStart(m_sToken, nDeliveryId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::endReceiveGoods(int nDeliveryId)
{
    HttpReceiveGoodsEnd *p = new HttpReceiveGoodsEnd(m_sToken, nDeliveryId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getDeliveryDetail(int nDeliveryId)
{
    HttpGetDeliveryDetail *p = new HttpGetDeliveryDetail(m_sToken, nDeliveryId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getReceiveGoodsDetail(int nDeliverGoodId)
{
    HttpGetReceiveGoodsDetail *p = new HttpGetReceiveGoodsDetail(m_sToken, nDeliverGoodId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::saveReceiveGoods(const ReceiveGoodsDetail_s &receiveGoodsDetail, int nDeliverGoodId)
{
    HttpSaveReceiveGoods *p = new HttpSaveReceiveGoods(m_sToken, receiveGoodsDetail, nDeliverGoodId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getAdjustPriceOrderList(QString sStartDate, QString sEndDate, QString sSearchPatter)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    int nLimit = -1;
    int nOffset = -1;
    HttpGetAdjustPriceOrderList *p = new HttpGetAdjustPriceOrderList(
                m_sToken, sCorpID, sUUID, sStartDate, sEndDate, sSearchPatter, nLimit, nOffset);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::checkAdjustPriceOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpCheckAdjustPriceOrder* p = new HttpCheckAdjustPriceOrder(m_sToken, sCorpID, sUUID, nOrderId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::removeAdjustPriceOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpRemoveAdjustPriceOrder* p = new HttpRemoveAdjustPriceOrder(m_sToken, sCorpID, sUUID, nOrderId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::searchAdjustPriceOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpSearchAdjustPriceOrder* p = new HttpSearchAdjustPriceOrder(m_sToken, sCorpID, sUUID, nOrderId, e_searchAdjustForSearch);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::editAdjustPriceOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpSearchAdjustPriceOrder* p = new HttpSearchAdjustPriceOrder(m_sToken, sCorpID, sUUID, nOrderId, e_searchAdjustForEdit);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::printAdjustPriceOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpSearchAdjustPriceOrder* p = new HttpSearchAdjustPriceOrder(m_sToken, sCorpID, sUUID, nOrderId, e_searchAdjustForPrint);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::saveAdjustPriceOrder(int nOrderId, const QList<AdjustPriceSelectGoodsInfo> &selectGoodsList)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpSaveAdjustPriceOrder *p = new HttpSaveAdjustPriceOrder(m_sToken, sCorpID, sUUID, nOrderId, selectGoodsList);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getStockOrderList(QString sStartDate, QString sEndDate, QString sSearchPatter)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    int nLimit = -1;
    int nOffset = -1;
    HttpGetStockOrderList *p = new HttpGetStockOrderList(
                m_sToken, sCorpID, sUUID, sStartDate, sEndDate, sSearchPatter, nLimit, nOffset);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::checkStockOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpCheckStockOrder* p = new HttpCheckStockOrder(m_sToken, sCorpID, sUUID, nOrderId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::removeStockOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpRemoveStockOrder* p = new HttpRemoveStockOrder(m_sToken, sCorpID, sUUID, nOrderId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::searchStockOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpSearchStockOrder* p = new HttpSearchStockOrder(m_sToken, sUUID, sCorpID, nOrderId, e_searchStockForSearch);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::editStockOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpSearchStockOrder* p = new HttpSearchStockOrder(m_sToken, sUUID, sCorpID, nOrderId, e_searchStockForEdit);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::printStockOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpSearchStockOrder* p = new HttpSearchStockOrder(m_sToken, sUUID, sCorpID, nOrderId, e_searchStockForPrint);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::saveStockOrder(int nOrderId, const QList<StockSelectGoodsInfo> &selectGoodsList)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpSaveStockOrder *p = new HttpSaveStockOrder(m_sToken, sCorpID, sUUID, nOrderId, selectGoodsList);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getStockGoodsInfo(int nGoodsId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpGetStockGoodsInfo* p = new HttpGetStockGoodsInfo(m_sToken, sCorpID, sUUID, nGoodsId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getPayCode(QString sCardNum)
{
    HttpGetPayCode* p = new HttpGetPayCode(sCardNum);
    p->setNetManager(m_pManager);
    p->postRequest();
}


void HttpClient::uploadClientCashSubmit(ClentCashSubmit_s m_clentCashSubmit)
{
    QString sLoginId = KPosIni::getLoginId();
    QString sCorpID = KPosIni::getCorpID();

    HttpUploadClientCashSubmit* p = new HttpUploadClientCashSubmit
            (m_sToken, sCorpID, m_clentCashSubmit.submit_amount, m_clentCashSubmit.uuid, m_clentCashSubmit.operate_at,
             m_clentCashSubmit.last_submit_at, m_clentCashSubmit.user_code, sLoginId, m_clentCashSubmit.submit_code);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::uploadClientCashSubmitSync(ClentCashSubmit_s ClentCashSubmit)
{
    QString sCorpID = KPosIni::getCorpID();

    HttpUploadClientCashSubmitSync* p = new HttpUploadClientCashSubmitSync
            (m_sToken, sCorpID, ClentCashSubmit.submit_amount, ClentCashSubmit.uuid, ClentCashSubmit.operate_at,
             ClentCashSubmit.last_submit_at, ClentCashSubmit.user_code, ClentCashSubmit.login_at, ClentCashSubmit.logout_at,ClentCashSubmit.submit_code);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getInStockOrderList(QString sStartDate, QString sEndDate, QString sSearchPatter)
{//请求入库单列表

    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    int nLimit = -1;
    int nOffset = -1;
    HttpGetInStockOrderList *p = new HttpGetInStockOrderList(
                m_sToken, sCorpID,sUUID, sStartDate, sEndDate, sSearchPatter, nLimit, nOffset);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::checkInStockOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpCheckInStockOrder* p = new HttpCheckInStockOrder(m_sToken, sCorpID,sUUID, nOrderId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::removeInStockOrder(int nOrderId)
{

    QString sCorpID = KPosIni::getCorpID();
    QString sUUid = CommonFun::getUUID();
    HttpRemoveInStockOrder* p = new HttpRemoveInStockOrder(m_sToken, sCorpID,sUUid, nOrderId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::searchInStockOrder(int nOrderId)
{//查看入库单
    QString sCorpID = KPosIni::getCorpID();
    QString sUUid = CommonFun::getUUID();
    HttpSearchInStockOrder* p = new HttpSearchInStockOrder(m_sToken, sCorpID,sUUid, nOrderId, e_searchStockForSearch);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::editInStockOrder(int nOrderId)
{
    //编辑未审核的
    QString sCorpID = KPosIni::getCorpID();
    QString sUUid = CommonFun::getUUID();
    HttpSearchInStockOrder* p = new HttpSearchInStockOrder(m_sToken, sCorpID,sUUid, nOrderId, e_searchStockForEdit);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::printInStockOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUid = CommonFun::getUUID();
    HttpSearchInStockOrder* p = new HttpSearchInStockOrder(m_sToken, sCorpID,sUUid, nOrderId, e_searchStockForPrint);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::saveInStockOrder(int nOrderId, const QList<InStockSelectGoodsInfo> &selectGoodsList)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpSaveInStockOrder *p = new HttpSaveInStockOrder(m_sToken, sCorpID, sUUID, nOrderId, selectGoodsList);
    p->setNetManager(m_pManager);
    p->postRequest();
}


void HttpClient::getOutStockOrderList(QString sStartDate, QString sEndDate, QString sSearchPatter)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    int nLimit = -1;
    int nOffset = -1;
    HttpGetOutStockOrderList *p = new HttpGetOutStockOrderList(
                m_sToken, sCorpID,sUUID, sStartDate, sEndDate, sSearchPatter, nLimit, nOffset);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::checkOutStockOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpCheckOutStockOrder* p = new HttpCheckOutStockOrder(m_sToken, sCorpID,sUUID, nOrderId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::removeOutStockOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUid = CommonFun::getUUID();
    HttpRemoveOutStockOrder* p = new HttpRemoveOutStockOrder(m_sToken, sCorpID,sUUid, nOrderId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::searchOutStockOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUid = CommonFun::getUUID();
    HttpSearchOutStockOrder* p = new HttpSearchOutStockOrder(m_sToken, sCorpID,sUUid, nOrderId, e_searchStockForSearch);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::editOutStockOrder(int nOrderId)
{
    //编辑未审核的
    QString sCorpID = KPosIni::getCorpID();
    QString sUUid = CommonFun::getUUID();
    HttpSearchOutStockOrder* p = new HttpSearchOutStockOrder(m_sToken, sCorpID,sUUid, nOrderId, e_searchStockForEdit);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::printOutStockOrder(int nOrderId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUid = CommonFun::getUUID();
    HttpSearchOutStockOrder* p = new HttpSearchOutStockOrder(m_sToken, sCorpID,sUUid, nOrderId, e_searchStockForPrint);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::saveOutStockOrder(int nOrderId, const QList<OutStockSelectGoodsInfo> &selectGoodsList)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpSaveOutStockOrder *p = new HttpSaveOutStockOrder(m_sToken, sCorpID, sUUID, nOrderId, selectGoodsList);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getQuickGoodsInfo(QString sBigCategoryCode)
{
    QString sCorpId = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpGetQuickGoodsInfo *p = new HttpGetQuickGoodsInfo(m_sToken, sCorpId, sUUID, sBigCategoryCode);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::createQuickGoodsRequest(const ProductInfo &info)
{
    QString sCorpId = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
//    HttpCreateQuickGoods *p = new HttpCreateQuickGoods(sCorpId, m_sToken, sUUID, info);
//    p->setNetManager(m_pManager);
//    p->postRequest();
    HttpCreateQuickGoods *p = new HttpCreateQuickGoods(m_sToken, sCorpId, sUUID, info);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::createGoodsGroup(QString sGroupName)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpCreateGoodsGroup* p = new HttpCreateGoodsGroup(sCorpID, m_sToken, sUUID, sGroupName);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getGoodsGroupList()
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpGetGoodsGroupList* p = new HttpGetGoodsGroupList(sCorpID, m_sToken, sUUID);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::saveGoodsGroup(int nGroupId, const QList<QString> &pluList)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpSaveGoodsGroup *p = new HttpSaveGoodsGroup(sCorpID, m_sToken, sUUID, nGroupId, pluList);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getBarcodeScaleCode()
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpGetBarcodeScaleCode* p = new HttpGetBarcodeScaleCode(sCorpID, m_sToken, sUUID);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::addBarcodeScale(QString sCode, QString sType, QString sIp, int nGroupId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpAddBarcodeScale* p = new HttpAddBarcodeScale(sCorpID, m_sToken, sUUID, sCode, sType, sIp, nGroupId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getBarcodeScaleList()
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpGetBarcodeScaleList* p = new HttpGetBarcodeScaleList(sCorpID, m_sToken, sUUID);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::updateScaleProductIssue(const QList<QString> &scaleList)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpUpdateScaleProductIssue* p = new HttpUpdateScaleProductIssue(sCorpID, m_sToken, sUUID, scaleList);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::deleteScale(QString scaleId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpDeleteScale* p = new HttpDeleteScale(sCorpID, m_sToken, sUUID, scaleId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::resetKey(QString oldkey, QString newkey){
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpResetKey *p = new HttpResetKey(sCorpID, m_sToken, sUUID, oldkey, newkey);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getEmployeeManageOrderList(QString sSearchPatter)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    int nLimit = -1;
    int nOffset = -1;
    HttpGetEmployeeManageOrderList *p = new HttpGetEmployeeManageOrderList(
                m_sToken, sCorpID,sUUID, sSearchPatter, nLimit, nOffset);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::changeEmployeeStatusOrder(QList<int> orderList, int status)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUid = CommonFun::getUUID();
    HttpChangeEmployeeStatusOrder* p = new HttpChangeEmployeeStatusOrder(m_sToken, sCorpID,sUUid, orderList, status);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getEmployeeScodeOrderRequest()
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUid = CommonFun::getUUID();
    HttpGetEmployeeScodeOrder* p = new HttpGetEmployeeScodeOrder(m_sToken, sCorpID, sUUid);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::EditEmployeeOrderRequest(AccountInfo info, int status)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUid = CommonFun::getUUID();
    HttpEditEmployeeOrderRequest* p = new HttpEditEmployeeOrderRequest(m_sToken, sCorpID, sUUid, info, status);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getSaleDetialListRequest()
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUid = CommonFun::getUUID();
    HttpGetSaleDetialOrderList* p = new HttpGetSaleDetialOrderList(m_sToken, sCorpID, sUUid);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getSaleReceiptListRequest(QString selectId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUid = CommonFun::getUUID();
    HttpSearchReceipt* p = new HttpSearchReceipt(m_sToken, sCorpID, sUUid, selectId, 1);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getReportLossOrderList(QString sStartDate, QString sEndDate, QString sSearchPatter)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    int nLimit = -1;
    int nOffset = -1;
    HttpGetReportLossOrderList *p = new HttpGetReportLossOrderList(m_sToken, sCorpID, sUUID, sStartDate, sEndDate, sSearchPatter, nLimit, nOffset);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::AddReportLossOrderList(QList<AddReportLossSelectInfo> infoList)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpAddReportLoss *p = new HttpAddReportLoss(m_sToken, sCorpID, sUUID, infoList);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::editReportLossOrderList(QList<AddReportLossSelectInfo> infoList, int selectId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpEditReportLoss *p = new HttpEditReportLoss(m_sToken, sCorpID, sUUID, infoList, selectId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::deleteReportLossOrderList(int selectId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpDeleteReportLoss *p = new HttpDeleteReportLoss(m_sToken, sCorpID, sUUID, selectId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::checkReportLossOrderList(int selectId)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpCheckReportLoss *p = new HttpCheckReportLoss(m_sToken, sCorpID, sUUID, selectId);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getReportLossDetialOrderList(int selectId, int mode)
{
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpGetReportLossDetial *p = new HttpGetReportLossDetial(m_sToken, sCorpID, sUUID, selectId, mode);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getGoodsManageOrderList(QString searchPattern, int nLimit, int nOffset, const QList<int> &categoryIdList, QString sSortBy, QString sSort, int nCategoryBigId)
{
    int nShopId = KPosIni::getShopId();
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpGetGoodsManageList *p = new HttpGetGoodsManageList(m_sToken, nShopId, sCorpID, searchPattern, nLimit, nOffset, categoryIdList, sSortBy, sSort, nCategoryBigId, sUUID);
    p->setNetManager(m_pManager);
    p->postRequest();
}

void HttpClient::getCategoryOrderList()
{
    int nLevel = 4; // 分类的层数
    QString sCorpID = KPosIni::getCorpID();
    QString sUUID = CommonFun::getUUID();
    HttpGetGoodsManageCategory *p = new HttpGetGoodsManageCategory(m_sToken, sCorpID, nLevel, sUUID);
    p->setNetManager(m_pManager);
    p->postRequest();
}

