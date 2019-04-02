#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include "enumData.h"
#include "structData.h"
#include "../data/setstructdata.h"
#include "../data/ordergoodsdata.h"
#include "../data/recievinggoodsdata.h"
#include "../data/adjustpricedata.h"
#include "../data/stockdata.h"
#include "httpstructdata.h"

class HttpClient : public QObject
{
    Q_OBJECT
public:
    static HttpClient* instance();
    void setToken(QString sToken);
    void getShopInfo(QString sCorpID, QString sShopCode); // 获取门店信息
    void registerPos(QString sCorpID, QString sShopCode); // pos机注册
    void checkRegisterResult(); // 检查注册结果
    void checkIsOnline(); // 检查在线状态
    void loginKPos(QString sUserCode, QString sPassword); // 登录
    void updateToken(QString sUserCode, QString sPassword); // 更新token
    void LogoutKPos(bool bGetReport); //　登出
    void getAllUserInfoRequest();
    void getCategory(QString sLastTime); // 获取所有分类
    void getAllGoods(QString sLastTime); // 获取所有商品
    void getAllGoodsPrice(QString sLastTime); // 获取所有商品价格
    void checkKPosUpdate(); // 检查KPos更新
    void uploadReceipt( QString strSale );
    // 结算支付请求
    void createPayInfoRequest(EPayMethod ePayMethod, QString strBarCode, QString strPayAmt, QString strSale, QString sSaleDetailsJson
                              , int nInteg=0, QString strPayPwd="", QString strIntToAmt="");
    void createPayQueryRequest( int nPayMethod, QString strPayOrderNum );
    void payRevokeRequest( EPayMethod ePayMethod, QString strPayOrderNum );//撤销请求
    void createPayMemberCard(QString strBarCode, QString strPayAmt, QString strSale
                             , int nInteg=0, QString strPayPwd="", QString strIntToAmt=""); // 会员支付
    void updateMemberIntegral(float fMoney, QString sCardNum, QString sOrderNum, QString sRefundOrderNum = ""); // 更新会员积分

    // 退货
    void getRefundGoodsReasonList(bool bIsOnline); // 退货原因
    void searchReceipt(QString sOrderNum); // 搜索销售小票
    void uploadClientCashSubmit(ClentCashSubmit_s m_clentCashSubmit);//交款
    void uploadClientCashSubmitSync(ClentCashSubmit_s ClentCashSubmit);//离线交款

    // 设置
    void uploadKPosSet(const KPosSet &kPosSet, bool bSync); // 上传KPos设置
    void downloadKPosSet(QString sLastTime); // 下载KPos设置
    void addCustomCategory(QString sCategoryName, int nPos); // 添加自定义分类
    void updateCustomCategory(int nCategoryId, QString sCategoryName); // 更新自定义分类
    void deleteCustomCategory(int nCategoryId); // 删除自定义分类
    void uploadScreenAD(QString sADPath); // 上传广告文件
    //会员
    void memQueryRequest( QString strMemCardId );
    void memQueryForRefundRequest(QString strMemCardId);
    void memRechargeRequest(QString strMemCardId, QString strRechargeAmt \
                             , int nPayMethod, int nOperatorId, QString strPayCode, bool bVirtual);//会员充值
    void memRegisterRequest( MemRegisterInfo_s stMemRegister );
    void memModifyPwdRequest( QString strCardId, QString strOldPwd, QString strNewPwd);
    void replaceMemCardRequest(QString strOldCardId, QString strNewCardId);
    void memSetCardStatusRequest( QString strCardId, int nStatus );
    void getMemTypeListRequest();
    void getMemGradeListRequest( int nMemTypeId );
    void getOPeratorListRequest();

    // 要货
    void getOrderCategory(); // 获取要货分类
    void getOrderGoods(QString searchPattern, int nLimit, int nOffset, const QList<int> &categoryIdList, QString sSortBy, QString sSort, int nCategoryBigId); // 获取要货商品
    void createOrderCardRequest(const QList<OrderGoodsInfo *> &orderGoodsInfoList);
    void removeOrderCard(QList<int> orderIdList); // 删除

    // 要货审核
    void getOrderCategoryForCheck(); // 获取要货审核的分类
    void getOrderCardList(int nLimit, int nOffset, const QList<int> &categoryIdList, QString sStartDate, QString sEndDate, QString sSearchText); // 要货卡列表
    void getOrderCardListDetail(const QList<int>& orderCardIdList, bool bUploadFinish); // 获取要货卡明细
    void updateOrderCardListDetail(const QMap<int, int>& changedNumMap, const QList<int>& orderCardIdList); // 更新要货卡
    void uploadOrderCard(const QList<int>& orderCardIdList); // 上传要货卡
    // 收货
    void getDeliveryOrderList(int nLimit, int nOffset, QString sStartDate, QString sEndDate); // 获取送货单列表
    void startReceiveGoods(int nDeliveryId); // 开始收货
    void endReceiveGoods(int nDeliveryId); // 停止收货
    void getDeliveryDetail(int nDeliveryId); // 获取送货单明细
    void getReceiveGoodsDetail(int nDeliverGoodId); // 获取收货物品明细
    void saveReceiveGoods(const ReceiveGoodsDetail_s &receiveGoodsDetail, int nDeliverGoodId); // 保存收货

    // 改价
    void getAdjustPriceOrderList(QString sStartDate, QString sEndDate, QString sSearchPatter); // 获取改价单列表
    void checkAdjustPriceOrder(int nOrderId); // 审核改价单
    void removeAdjustPriceOrder(int nOrderId); // 删除改价单
    void searchAdjustPriceOrder(int nOrderId); // 查看改价单
    void editAdjustPriceOrder(int nOrderId); // 编辑改价单
    void printAdjustPriceOrder(int nOrderId); // 打印改价单
    void saveAdjustPriceOrder(int nOrderId, const QList<AdjustPriceSelectGoodsInfo>& selectGoodsList);

    // 盘点
    void getStockOrderList(QString sStartDate, QString sEndDate, QString sSearchPatter); // 获取盘点单列表
    void checkStockOrder(int nOrderId); // 审核盘点单
    void removeStockOrder(int nOrderId); // 删除盘点单
    void searchStockOrder(int nOrderId); // 查看盘点单
    void editStockOrder(int nOrderId); // 编辑盘点单
    void printStockOrder(int nOrderId); // 打印盘点单
    void saveStockOrder(int nOrderId, const QList<StockSelectGoodsInfo> &selectGoodsList);
    void getStockGoodsInfo(int nGoodsId);

    // 储值卡
    void getPayCode(QString sCardNum); // 获取储值卡信息

    // 入库
    void getInStockOrderList(QString sStartDate, QString sEndDate, QString sSearchPatter); // 获取入库单列表
    void checkInStockOrder(int nOrderId); // 审核盘点单
    void removeInStockOrder(int nOrderId); // 删除盘点单
    void searchInStockOrder(int nOrderId); // 查看盘点单
    void editInStockOrder(int nOrderId); // 编辑盘点单
    void printInStockOrder(int nOrderId); // 打印盘点单
    void saveInStockOrder(int nOrderId, const QList<InStockSelectGoodsInfo> &selectGoodsList);

    // 出库
    void getOutStockOrderList(QString sStartDate, QString sEndDate, QString sSearchPatter); // 获取入库单列表
    void checkOutStockOrder(int nOrderId); // 审核盘点单
    void removeOutStockOrder(int nOrderId); // 删除盘点单
    void searchOutStockOrder(int nOrderId); // 查看盘点单
    void editOutStockOrder(int nOrderId); // 编辑盘点单
    void printOutStockOrder(int nOrderId); // 打印盘点单
    void saveOutStockOrder(int nOrderId, const QList<OutStockSelectGoodsInfo> &selectGoodsList);

    // 快速建档
    void getQuickGoodsInfo(QString sBigCategoryCode); // 获取商品编码
    void createQuickGoodsRequest(const ProductInfo& info); // 创建快速建档商品

    // 条码秤
    void createGoodsGroup(QString sGroupName); // 创建商品组
    void getGoodsGroupList(); // 获取商品组列表
    void saveGoodsGroup(int nGroupId, const QList<QString>& pluList); // 保存商品组
    void getBarcodeScaleCode(); // 获取条码秤编号
    void addBarcodeScale(QString sCode, QString sType, QString sIp, int nGroupId); // 添加条码秤
    void getBarcodeScaleList(); // 获取条码秤列表
    void updateScaleProductIssue(const QList<QString> &scaleList);//更新条码秤商品下发时间
    void deleteScale(QString scaleId);//删除条码秤

    // 修改密码
    void resetKey(QString oldkey, QString newkey);

    // 员工管理
    void getEmployeeManageOrderList(QString sSearchPatter);
    void changeEmployeeStatusOrder(QList<int> orderList, int status);
    void getEmployeeScodeOrderRequest();
    void EditEmployeeOrderRequest(AccountInfo info, int status);

    // 销售明细
    void getSaleDetialListRequest();
    void getSaleReceiptListRequest(QString selectId);

    // 报损
    void getReportLossOrderList(QString sStartDate, QString sEndDate, QString sSearchPatter);
    void AddReportLossOrderList(QList<AddReportLossSelectInfo> infoList);
    void editReportLossOrderList(QList<AddReportLossSelectInfo> infoList, int selectId);
    void deleteReportLossOrderList(int selectId);
    void checkReportLossOrderList(int selectId);
    void getReportLossDetialOrderList(int selectId, int mode);

    // 商品管理
    void getGoodsManageOrderList(QString searchPattern, int nLimit, int nOffset, const QList<int> &categoryIdList, QString sSortBy, QString sSort, int nCategoryBigId);
    void getCategoryOrderList();

private:
    explicit HttpClient(QObject *parent=NULL);

private:
    static HttpClient* m_pInstance;
    QString m_strTokenInfo;
    QNetworkAccessManager* m_pManager;
    QString m_sToken;
};

#endif // HTTPCLIENT_H
