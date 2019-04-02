#ifndef SALECTRL_H
#define SALECTRL_H

#include <QObject>
#include <QList>
#include "structData.h"
#include "setstructdata.h"
#include "BalanceManage.h"

class SaleCtrl : public QObject
{
    Q_OBJECT
public:
    explicit SaleCtrl( QObject *parent = 0 );
    ~SaleCtrl();
public:
    void updateCategoryAndGoodsInfo();
    void searchGoodsInfo(QString sSearchText, QList<GoodsInfo>& goodsInfoList);
    bool searchGoodsInfo( QString strGoodsInfo );
    void clearSearchGoodsInfo();
    void printLastReceipt(MemRegisterInfo_s stMemRegInfo);
    void peeling();
    void getCategoryInfoList(QList<CategoryInfo *> &categoryInfoList);
    int getSaleHeadPendingNum();
    bool isSaleReceipt(QString sOrderNum, SaleHead &saleHead);
    void findSaleDetails(const QString &searchText, QList<SaleDetails> &listSaleDetails);
//    bool isRefundFinish(QString sRefundOrderNum);
    void getFinishRefundOrderNumList(QString sOrderNum, QList<QString>& refundOrderNumList); // 获取已完成退货单号列表
    void getRefundGoodsReasonListRequest(); // 退货原因
    void getMemInfoForRefundRequest(QString strMemCardId);
    void searchReceiptRequst(QString sOrderNum); // 搜索销售小票
    bool isReceiptFormat(QString searchText); // 是否是小票格式
    bool isOnline();
    void printRefundReceipt(QString strOrderNum, const SaleHead &stSaleHead, const QList<SaleDetails> &listSaleDetails
                      , const QList<PayDetail_s> &listPayDetails , const MemRegisterInfo_s &stMemRegInfo);

    void getCategoryNodeList(QList<CategoryInfoNode>& nodeList);
    void getQuickGoodsInfoRequest(QString sCategoryCode); // 获取快速建档商品信息
    void createQuickGoodsRequest(const ProductInfo& info); // 创建快速建档商品
    void startUpdateThread(); // 立即启动3分钟线程
    void updateMemberIntegralRequest(float fMoney, QString sCardNum, QString sOrderNum, QString sRefundOrderNum); // 结算赠积分
    void getIntegralPayMoney(float& fMoney, QString sOrderNum);
    void getPayIntegral(int& nIntegral, QString sOrderNum); // 获取本地积分

public slots:
    void slot_getGoodsList(QString sCategoryKeyId);
    void slot_addCategoryData();
    void slot_categoryGoodsChanged();

signals:
    void sig_allCategoryInfo( QList<CategoryInfo*> listCategoryInfo );
    void sig_goodsInfo( QList<GoodsInfo> listGoodsInfo );
    void sig_searchGoodsInfo( GoodsInfo stGoodsInfo );
    void sig_stableInfo(EBalanceStandard_Ex balanceStandard_Ex, bool bStable);
    void sigCategoryGoodsChanged();
    void sigOnGetRefundGoodsReasonList(int nCode, QString sMsg, QList<RefundGoodsReason>);
    void sigOnSearchReceipt(int nCode, QString sMsg, SaleHead saleHead, QList<SaleDetails> saleDetailsList, float fIntegralPayMoney, int nIntegralPay);
    void sigOnMemInfoQueryForRefund(int nCode, QString sMsg, MemRegisterInfo_s stMemRegInfo);
    void sigOnGetQuickGoodsInfo(int nCode, QString sMsg, QString sPlu, QString sGoodsCode, QString sUnits, QString sBigCategoryCode); // 获取快速建档商品信息
    void sigOnCreateQuickGoods(int nCode, QString sMsg); // 创建快速建档商品

private:
    void initConnect();
    void init();
    //协议层结构转换成业务结构
    void goodsInfoProtocolToLocal( GoodsInfo &stGoodsInfo, const GoodsInfo_s &stGoodsInfoS );
    void clearCategoryInfo();
private:
    QList<CategoryInfo*> m_listCategoryInfo;
};

#endif // SALECTRL_H
