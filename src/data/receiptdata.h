#ifndef RECEIPTDATA_H
#define RECEIPTDATA_H

#include <QString>
#include <QMap>
#include <QList>

#include "../data/adjustpricedata.h"
#include "../data/stockdata.h"
#include "../data/httpstructdata.h"
#include "structData.h"

// 销售明细  小票信息
struct ReceiptInfo
{
    int id;
    QString bScode;   // 小票编号
    QString bSaleman;   // 销售员
    QString salemanId;
    QString bSaleGuide; // 导购员
    QString saleGuideId;
    QString bDealTime;  // 交易时间
    int type;     // 0:销售小票 1:退货小票 2:会员充值 3:储值卡充值 4:退充值
    int state;          // 状态  1:改价 0:正常 -1:删除
};
Q_DECLARE_METATYPE(ReceiptInfo)

struct ReceiptDetialInfo{
    int id;
    QString sGoodsName; // 名称
    QString sGoodsUnit; // 单位
    QString sGoodsCode; // 商品编码
    float sGoodsNum; // 数量
    float sGoodsPrice; // 单价
    float sGoodsSumPrice; // 总价
    int status;    // 小票状态  0:删除  1:改价  2:正常
};
Q_DECLARE_METATYPE(ReceiptDetialInfo)

// 会员的打印选项
struct ReceiptMemberOption
{
    bool bShowInfo; // 是否显示会员信息
    bool bShowIntegral; // 是否显示积分
    bool bShowAccountAndRemain; // 显示账号和余额
};

// 打印选项
struct ReceiptPrintOption
{
    bool bGoodsCode; // 打印商品编码
    bool bCountCategory; // 打印分类小计
    bool bAddGoodsNumAfterGoodsName; // 商品数量(x1)添加到商品名后
    bool bPrice; // 打印单价
    bool bGoodsNameInOneRow; // 商品名称独占一行 （暂时不做）
    bool bUnit; // 打印单位
    bool bForbidBigFont; // 禁止大写字体
    bool bShortGoodsName; // 打印商品简称
    ReceiptMemberOption memberInfo; // 会员的打印选项
};

// 销售物品的信息
struct ReceiptSaleGoodsInfo
{
    QString sGoodsName; // 名称
    QString sGoodsShortName; // 商品简称
    QString sGoodsUnit; // 单位
    QString sGoodsCode; // 商品编码
    QString sGoodsNum; // 数量
    QString sGoodsPrice; // 单价
    QString sGoodsSumPrice; // 总价
};

// 小票分类统计
struct ReceiptCategoryCount
{
    int nTotalNum; // 总量
    QString strTotalPrice; // 总价
    QString sCategoryName; // 分类名字
};

// 销售信息
struct ReceiptSaleInfo
{
    QList<ReceiptCategoryCount> categoryCountList; // 分类统计列表
    QList<ReceiptSaleGoodsInfo> saleGoodsInfoList; // 物品销售列表
};

// 门店信息
struct ReceiptShopInfo
{
    QString sShopCode; // 门店号
    QString sShopName;//门店名称
    QString sKPosCode; // 款机号
    QString sSaleman; // 销售员
    QString sSaleGuide; // 导购员
    QString sSequence; // 流水号
    QString sDealTime; // 交易时间
};

// 小票结算信息
struct ReceiptSettlementInfo
{
    QString sSumPrice; // 总计金额
    QString sSumNumber; // 总计数量
    //QString sMemberCutMoney; // 会员优惠
    //QString sDiscountMoney; // 折扣金额
    QString sAllDisAmt;//总优惠金额
    QString sWantGetPrice; // 应收金额
    QString sRealGetPrice; // 实收金额
    QString sReturnMoney; // 找零金额
};

// 付款方式统计
//struct ReceiptSettleTypeCount
//{
//    QString sOnlineSettleMoney; // 线上支付总金额
//    QString sCashSettleMoney; // 现金支付

//    QString sPayCash; //现金支付
//    QString sUnionPay;//银联
//    QString sPayMemCard; //会员卡支付
//    QString sPayStoreCard; //储值卡支付
//    QString sPayAlipay; //支付宝
//    QString sPayWeChat; //微信支付
//    QString sApplePay; //苹果支付
//    QString sJdWallet; //京东钱包
//    QString sCoupon; //优惠券
//    QString sIntegralToCansh;//积分抵现
//    QString sPayEntityCard; //实体卡
//    QString sPayCityCard; //市民卡
//    QString sPayFengCha; //果麦
//    QString sPayCheck;   //支票
//    QString sPayBills; //欠单
//    QString sPayOther; //其他
//};

// 会员信息
struct ReceiptMemberInfo
{
    QString sAccount; // 会员账号
    QString sBalance; // 当前余额
    QString sGetIntegral; // 本次积分
    QString sTotalIntegral; // 剩余积分
};

// 会员充值信息（只用于打印）
struct MemberRechargeInfo
{
    QString strCardNo;//会员卡号
    QString strName;//会员名
    QString strRechargeAmt;//充值金额
    QString strGiftAmt;//赠送金额
    QString sBalance; // 当前余额
    QString strPayMethod;//支付方式
};

struct ReceiptPrintData
{
    bool bRefund; // 是否是退货小票
    QString sBarcode; // 条形码数据
//    QString sQRCode; // 二维码数据，后台配置
//    QString sHeadContent; // 头部语，后台配置
//    QString sHeadWords; // 头部文字，后台配置
//    QString sTailContent; // 尾部语，后台配置
//    QString sPicturePath; // 自定义图片，后台配置
    ReceiptShopInfo shopInfo; // 门店信息
    ReceiptSaleInfo saleInfo; // 销售信息
    ReceiptSettlementInfo settlementInfo; // 小票结算信息
    QMap<QString, QString> settleTypeMap; // 付款方式统计
    ReceiptMemberInfo memberInfo; // 会员信息
//    ReceiptPrintOption option; // 打印选项，后台配置
};

struct MemRechargePrintInfo
{
    //QString sBarcode; // 条形码数据
    QString sHeadContent; // 头部语，后台配置
    QString sHeadWords; // 头部文字，后台配置
    QString sTailContent; // 尾部语，后台配置
    ReceiptShopInfo stShopInfo; // 门店信息
    MemberRechargeInfo stMemberRechargeInfo; // 会员充值信息
};

struct AdjustPricePrintData
{
    QString sShopName; // 门店名称
    QString sShopCode; // 门店号
    AdjustPriceOrderInfo adjustOrderInfo;
    QList<AdjustPriceGoodsInfo> adjustPriceInfoList;
    QString sPrintTime; // 打印时间
};

struct ReportLossPrintData{
    QString sShopName;
    QString sShopCode;
    ReportLossInfo reportLossInfo;
    QList<AddReportLossInfo> reportLossInfoList;
    QString sPrintTime;
};

struct InStockPrintData
{
    QString sShopName; // 门店名称
    QString sShopCode; // 门店号
    InStockOrderInfo stockOrderInfo;
    QList<InStockOrderGoodsInfo> stockInfoList;
    QString sPrintTime; // 打印时间
    QString sTotal;//总金额
};

struct SaleDetialPrintData
{
   SaleHead saleHead;
   QList<PaymentDetailInfo> paymentInfoList;
   QList<SaleDetails> itemInfoList;
   QString sPrintTime;
};

struct OutStockPrintData
{
    QString sShopName; // 门店名称
    QString sShopCode; // 门店号
    OutStockOrderInfo stockOrderInfo;
    QList<OutStockOrderGoodsInfo> stockInfoList;
    QString sPrintTime; // 打印时间
    QString sTotal;//总金额
};

struct StockPrintData
{
    QString sShopName; // 门店名称
    QString sShopCode; // 门店号
    StockOrderInfo stockOrderInfo;
    QList<StockOrderGoodsInfo> stockInfoList;
    QList<StockOrderGoodsInfo> removedInfoList; // 移除的
    QList<StockOrderGoodsInfo> updateInfoList; // 更新的
    QList<StockOrderGoodsInfo> addedInfoList; // 添加的
    QString sPrintTime; // 打印时间
};

struct LogoutPrintData
{
    QString sShopName; // 门店名称
    QString sShopCode; // 门店号
    QString sKPosCode; // 款机号
    QString sSaleman; // 销售员
    QString sLoginTime; // 登入时间
    QString sLogoutTime; // 登出时间
    QMap<QString, QString> payMethodMap; // 支付方式
    int nSaleNum; // 销售笔数
    QString sSaleMoney; // 销售金额
    int nSaleRefundNum; // 退款笔数
    QString sSaleRefundMoney; // 退款金额
    QString sSubmitSum; // 交款金额
    QString sPrintTime; // 打印时间
};

#endif // RECEIPTDATA_H
