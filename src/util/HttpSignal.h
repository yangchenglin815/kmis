#ifndef HTTPSIGNAL_H
#define HTTPSIGNAL_H

#include <QObject>
#include "../data/httpstructdata.h"
#include "../data/setstructdata.h"
#include "../data/ordergoodsdata.h"
#include "../data/recievinggoodsdata.h"
#include "../data/adjustpricedata.h"
#include "../data/stockdata.h"
#include "../data/structData.h"
#include "../data/barcodescaledata.h"
#include "goodsmanagedata.h"
#include "enumData.h"

class HttpSignal : public QObject
{
    Q_OBJECT
public:
    static HttpSignal* instance();

private:
    explicit HttpSignal(QObject *parent = 0);

signals:
    void sigOnGetShopInfo(int nCode, QString sMsg, ShopInfo shopInfo);
    void sigOnRegisterPos(int nCode, QString sMsg);
    void sigOnCheckRegisterResult(int nCode, QString sMsg, RegistResultInfo registResultInfo);
    void sigOnlineState(bool isOnline);
    void sigOnLoginKPos(int nCode, QString sMsg, LoginKPosInfo loginKPosInfo); // 登入
    void sigOnUpdateToken(QString sToken); // 更新token
    void sigOnLogoutKPos(int nCode, QString sMsg); // 登出
    void sigOnGetCategory(int nCode, QString sMsg, QList<CategoryInfo_s> categoryInfoList, QString sUpdateTime);
    void sigOnGetAllGoods(int nCode, QString sMsg, QMap<QString, GoodsInfo_s> goodsInfoMap, QString sUpdateTime);
    void sigOnGetChangedGoods(int nCode, QString sMsg, QMap<QString, GoodsInfo_s> createMap, QMap<QString, GoodsInfo_s> updateMap
                              , QList<QString> deleteList, QString sUpdateTime);
    void sigOnGetAllGoodsPrice(int nCode, QString sMsg, QMap<QString, GoodsPriceInfo_s>, QString sUpdateTime);
    void sigOnCheckKPosUpdate(int nCode, QString sMsg, KPosUpdateInfo kPosUpdateInfo);
    // 结算支付
    void sigOnCreatePayStatus( int nCode, QString sMsg, QString strOrderNumS, QString strAuthCode, EPayMethod ePayMethod );
    void sigOnGetPayStatus( int nCode, QString sMsg, QString strOrderNumS, int nTradeState );
    void sigOnCreatePayMemberCard(int nCode, QString sMsg, QString sBanlanceOrderNum, QString sIntegralOrderNum);
    void sigOnUploadReceiptSuc( int nCode, QString sMsg, QList<QString> strListOrderNum );
    void sigOnRevokePay( int nCode, QString sMsg, QString strOrderNum, int nRevoked );//支付撤销
    void sigOnMemCardRevokePay( int nCode, QString sMsg, QString strOrderNum, int nRevoked, QString strMemCardBanlance, int nMemCardIntegral );//会员支付撤销
    void sigOnUpdateMemberIntegral(int nCode, QString sMsg, int nGiftIntegral, QString sOrderNum);

    // 退货
    void sigOnGetRefundGoodsReasonList(int nCode, QString sMsg, QList<RefundGoodsReason>);
    void sigOnSearchReceipt(int nCode, QString sMsg, SaleHead saleHead, QList<SaleDetails> saleDetailsList, float fIntegralPayMoney, int nIntegralPay);

    // 配置
    void sigOnDownloadKPosSet(int nCode, QString sMsg, KPosSet kPosSet, QString sUpdateTime);
    void sigOnUploadKPosSet(int nCode, QString sMsg, QString sUpdateTime);
    void sigOnAddCustomCategory(int nCode, QString sMsg, int nCategoryId);
    void sigOnDeleteCustomCategory(int nCode, QString sMsg, int nCategoryId);
    //会员
    void sigOnMemInfoQuery( int nCode, QString sMsg, MemRegisterInfo_s stMemRegInfo );
    void sigOnMemInfoQueryForRefund(int nCode, QString sMsg, MemRegisterInfo_s stMemRegInfo);
    void sigOnMemRecharge( int nCode, QString sMsg, QString strCardNo, QString strAccountBalance, QString strTradeNo, int nIntegral, QString strGiftAmt );
    void sigOnMemRegister( int nCode, QString strMsg, QString strCardNo, int nStatus, MemRegisterInfo_s stMemRegister );
    void sigOnMemPwdModify( int nCode, QString sMsg, QString strCardNo, int nStatus );
    void sigOnReplaceMemCard( int nCode, QString sMsg, QString strOldCardId, QString strNewCardId );
    void sigOnMemStatus( int nCode, QString sMsg, QString strCardNo, int nCardStatus );
    void sigOnMemReplaceCard( int nCode, QString sMsg );
    //会员类型和会员等级列表
    void sigOnMemTypeList( int nCode, QString sMsg, QList<MemTypeInfo_s> listMemType );
    void sigOnMemGradeList( int nCode, QString sMsg, QList<MemGradeInfo_s> listMemGrade );
    //业务员列表
    void sigOnOperatorList( int nCode, QString sMsg, QList<OperatorInfo_s> listOperator );
    void sigOnGetAllUserInfo( int nCode, QString sMsg, QList<SalemanInfo> listSalemanInfo );
    // 要货
    void sigOnGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> orderCategoryBigList); // 要货的分类
    void sigOnGetOrderGoods(int nCode, QString sMsg, QList<OrderGoodsInfo_s> orderGoodsInfoList, int nCategoryBigId); // 分类的商品
    void sigOnCreateOrderCard(int nCode, QString sMsg);
    // 要货审核
    void sigOnGetOrderCategoryForCheck(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> orderCategoryBigList); // 要货审核的分类
    void sigOnGetOrderCardList(int nCode, QString sMsg, QList<OrderCardInfo_s> orderCardList);
    void sigOnGetOrderCardListDetail(int nCode, QString sMsg, QList<OrderCardDetailInfo_s> orderCardDetailInfoList, bool bUploadFinish, QList<int> orderCardIdList); // 要货卡明细
    void sigOnUpdateOrderCardListDetail(int nCode, QString sMsg); // 更新要货卡明细
    void sigOnUploadOrderCard(int nCode, QString sMsg, QList<int>); // 上传要货卡
    void sigOnRemoveOrderCard(int nCode, QString sMsg); // 删除要货卡
    // 收货
    void sigOnGetDeliveryOrderList(int nCode, QString sMsg, QList<DeliveryOrderInfo_s> deliveryOrderInfoList);
    void sigOnStartReceiveGoods(int nCode, QString sMsg, int nDeliveryId);
    void sigOnGetDeliveryDetail(int nCode, QString sMsg, QList<DeliveryOrderDetailInfo_s> deliveryOrderDetailInfoList, int nDeliveryId);
    void sigOnGetReceiveGoodsDetail(int nCode, QString sMsg, ReceiveGoodsDetail_s receiveGoodsDetail, int nDeliveryGoodId);
    // 改价
    void sigOnGetAdjustPriceOrderList(int nCode, QString sMsg, QList<AdjustPriceOrderInfo> orderInfoList);
    void sigOnCheckAdjustPriceOrder(int nCode, QString sMsg, int nOrderId);
    void sigOnRemoveAdjustPriceOrder(int nCode, QString sMsg, int nOrderId);
    void sigOnSearchAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> searchInfoList);
    void sigOnEditAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnPrintAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnSaveAdjustPriceOrder(int nCode, QString sMsg);
    // 盘点
    void sigOnGetStockOrderList(int nCode, QString sMsg, QList<StockOrderInfo> orderInfoList);
    void sigOnCheckStockOrder(int nCode, QString sMsg);
    void sigOnRemoveStockOrder(int nCode, QString sMsg, int nOrderId);
    void sigOnSearchStockOrder(int nCode, QString sMsg, QList<StockOrderSearchInfo> searchInfoList);
    void sigOnEditStockOrder(int nCode, QString sMsg, QList<StockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnPrintStockOrder(int nCode, QString sMsg, QList<StockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnSaveStockOrder(int nCode, QString sMsg);
    void sigOnGetStockGoodsInfo(int nCode, QString sMsg, GoodsStockInfo goodsStockInfo);
    void sigOnGetOutStockGoodsInfo(const QString& markNum, float fBuyPrice);
    // 储值卡
    void sigOnPayStoreCardInfo(int nCode, QString sMsg, PayStoreCardInfo storeCardInfo); // 获取储值卡信息

    // 交款
    void sigOnUploadClientCashSubmit(int nCode, QString sMsg);// 交款

    // 入库
    void sigOnGetInStockOrderList(int nCode, QString sMsg, QList<InStockOrderInfo> orderInfoList);
    void sigOnCheckInStockOrder(int nCode, QString sMsg);
    void sigOnRemoveInStockOrder(int nCode, QString sMsg, int nOrderId);
    void sigOnSearchInStockOrder(int nCode, QString sMsg,QString sTotal, QList<InStockOrderSearchInfo> searchInfoList);
    void sigOnEditInStockOrder(int nCode, QString sMsg, QList<InStockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnPrintInStockOrder(int nCode, QString sMsg, QList<InStockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnSaveInStockOrder(int nCode, QString sMsg);

    // 出库
    void sigOnGetOutStockOrderList(int nCode, QString sMsg, QList<OutStockOrderInfo> orderInfoList);
    void sigOnCheckOutStockOrder(int nCode, QString sMsg);
    void sigOnRemoveOutStockOrder(int nCode, QString sMsg, int nOrderId);
    void sigOnSearchOutStockOrder(int nCode, QString sMsg,QString sTotal, QList<OutStockOrderSearchInfo> searchInfoList);
    void sigOnEditOutStockOrder(int nCode, QString sMsg, QList<OutStockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnPrintOutStockOrder(int nCode, QString sMsg, QList<OutStockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnSaveOutStockOrder(int nCode, QString sMsg);
    //快速建档
    void sigOnSaveQuickAddGoods(int nCode, QString sMsg,const QString& plu,const QString& goodCode,const QString &unit);
    void sigOnGetQuickGoodsInfo(int nCode, QString sMsg, QString sPlu, QString sGoodsCode, QString sUnits, QString sBigCategoryCode); // 获取快速建档商品信息
    void sigOnCreateQuickGoods(int nCode, QString sMsg); // 创建快速建档商品

    // 条码秤
    void sigOnCreateGoodsGroup(int nCode, QString sMsg, BCSGroupManageLeftInfo bcsGroupManageLeftInfo); // 创建商品组
    void sigOnGetGoodsGroupList(int nCode, QString sMsg, QList<BCSGroupManageLeftInfo> leftInfoList); // 获取商品组列表
    void sigOnGetBarcodeScaleList(int nCode, QString sMsg, QList<BarCodeScaleInfo> scaleInfoList);//获取条码秤列表
    void sigOnGetBarcodeScaleCode(int nCode, QString sMsg, QString sBcsCode); // 获取条码秤编号
    void sigOnAddBarcodeScale(int nCode, QString sMsg);// 新增条码秤
    void sigOnDeleteScale(int nCode, QString sMsg, QString scaleId);//删除条码秤
    //
    void sigResetPasswd(int nCode, QString sMsg); //修改密码

    // 员工管理
    void sigOnGetEmployeeManageOrderList(int nCode, QString sMsg, QList<AccountInfo> orderInfoList);
    void sigOnChangeEmployeeStatusOrder(int nCode, QString sMsg, QList<int> orderList, int status);
    void sigOnGetEmployeeScodeOrder(int nCode, QString sMsg, QString nScode);
    void sigOnEditEmployeeOrder(int nCode, QString sMsg);

    // 销售明细
    void sigOnGetSaleDetialOrderList(int nCode, QString sMsg, QList<ReceiptInfo> infoList);
    void sigOnGetSaleReceiptOrderList(int nCode, QString sMsg, SaleHead saleHead, QList<SaleDetails> saleDetailsList, QList<PaymentDetailInfo> paymentInfoList);

    // 报损
    void sigOnGetReportLossOrderList(int nCode, QString sMsg, QList<ReportLossInfo> orderInfoList);
    void sigAddReportLossOrderList(int nCode, QString sMsg);
    void sigEditReportLossOrderList(int nCode, QString sMsg);
    void sigDeleteReportLossOrderList(int nCode, QString sMsg);
    void sigCheckReportLossOrderList(int nCode, QString sMsg);
    void sigOnGetReportLossDetialOrderList(int nCode, QString sMsg, QList<AddReportLossSelectInfo> infoList);
    void sigOnGetEditReportLossDetialOrderList(int nCode, QString sMsg, QList<AddReportLossSelectInfo> infoList, int selectId);
    void sigOnGetPrintReportLossDetialOrderList(int nCode, QString sMsg, QList<AddReportLossSelectInfo> infoList, int selectId);

    // 商品管理
    void sigOnGetGoodsManageCategoryOrderList(int nCode, QString sMsg, QList<CategoryBigInfo_s> categoryBigInfoList);
    void sigOnGetGoodsManageGoodsList(int nCode, QString sMsg, QList<sGoodsInfo_s> orderGoodsInfoList, int nCategoryBigId);

private:
    static HttpSignal* m_pInstance;
};

#endif // HTTPSIGNAL_H
