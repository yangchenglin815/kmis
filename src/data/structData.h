#ifndef STRUCTDATA_H
#define STRUCTDATA_H

#include <QVariant>
#include <QDateTime>
#include <QVector>
#include "httpstructdata.h"
#include "enumData.h"

struct GoodsInfo
{
    int nId;//商品id
    QString sCode;//商品编码
    QString sBarCode;//商品条码
    QString sName;//商品名称
    QString sShortName;//商品简称
    QString sPinYinName; // 拼音助记码
    QString sWuBiName; // 五笔助记码
    QString sPluCode; // plu码
    QString sPluName; // 商品Plu名称
    QString sSpeUnit;//要货单位，如50个/卷
    QString sCategoryName;//大类名称
    int nPluGrade; // 商品plu等级
    int nCategoryId;//商品分类id,（20161224 需要修改为strCategoryId)
    float fPrice;//商品价格
    float fMarkNum;//箱数与件数的量比系数  如 5公斤/箱的5
    float fMemberPrice; // 会员价
    int nTasteType;//商品口味分级， 没用了
    bool bStandard;//商品类型(标品，非标品）
    QString sSaleUnit;//销售单位： 元/公斤
    bool bPromotion; // 是否促销
    bool bAllowSell;//是否允许售卖
    QList<GoodsInfo> goodsInfoList;//子商品列表

    GoodsInfo()
        : nId( -1 )
        , sCode( "" )
        , sBarCode( "" )
        , sName( "" )
        , sShortName( "" )
        , nCategoryId( -1 )
        , fPrice( 0.00 )
        , fMemberPrice( 0.00 )
        , nTasteType( 0 )
        , bStandard( false )
        , sSaleUnit( "公斤" )
        , bPromotion( false )
        , bAllowSell( true ) {}
};

Q_DECLARE_METATYPE(GoodsInfo)

struct CategoryInfo
{
    qint64 nId; //商品分类id   nCategoryId
    QString sName; //商品分类名
    bool bCustom;//是否为自定义
    QString sKeyId; // 唯一标识,（pos端组的结构，为了自定义和非自定义分类统一）
    QList<GoodsInfo> listGoodsInfo;
};
//加上下面的语句，CategoryInfo结构体可以自动转换成QVariant结构；否则不能自动转换，并会报错
Q_DECLARE_METATYPE(CategoryInfo)


struct ProductInfo{
    QString goodsName;//商品名
//    QString sCategoryName;//大类名称
    QString cId;//商品分类id
    QString product_code;//商品编号，服务器传入值
    QString product_base_code;//商品PLU编码（服务器传入值）/商品条码（手动输入值）
    qint64 weight_type;//0称重/1非称重,需要获取条码
    QString min_spec_unit;//最小规格单位
    float order_spec_num;//要货规格值
    QString order_spec_unit;//要货规格单位
    float reference_bid_price;//参考进价
    float reference_selling_price;//售价
    float member_price;//会员价
};

Q_DECLARE_METATYPE(ProductInfo)

struct OrderInfo
{
    QString sOrderSequence;
    QString sCreateTime;
    bool bSelect;//选中状态
    OrderInfo()
        : bSelect( false ) {}
};
Q_DECLARE_METATYPE(OrderInfo)

struct PaymentDetailInfo
{
    QString sPaymentSequence; // 订单号
    QString strPaymentOrderNum;//支付单号（现金支付单号：pos号+时间yyMMddhhmmss)
    EPayMethod ePayMethod; // 支付类型
    EPaymentType ePayType;//支付方式
    EPaymentState ePaymentState; // 支付状态
    float fPaymentSum; // 支付金额
    int nPayIntegral;//支付积分
    QString strIntExchangeAmt;//1积分抵价 , 以后不要了
    int nPos;
    EButtonStatus eButtonStatus;//退款按钮状态
    bool bVirtual;//虚拟支付 ， 以后不要了
    QString strAuthCode;//支付授权码
    PaymentDetailInfo()
        : sPaymentSequence( "")
        , strPaymentOrderNum( "" )
        , ePayMethod( PayNull )
        , ePayType( e_Payment )
        , ePaymentState( e_PaySuccess )
        , fPaymentSum( 0.00 )
        , nPayIntegral( 0 )
        , strIntExchangeAmt( "" )
        , nPos( -1 )
        , eButtonStatus( eNormal )
        , bVirtual( false )
        , strAuthCode( "" ){}
};
Q_DECLARE_METATYPE(PaymentDetailInfo)

struct GoodsDetailInfo
{
    int nPos;//列表序号
    int nSaleDetailPos;//销售明细序号
    int nGoodsId; //商品id
    QString strGoodsCode;//商品编码id， 小票中没有保存到数据库，以后要保存到本地数据库
    QString sGoodsName;//商品名字
    QString sGoodsId; //商品编号
    QString strGoodsShortName;//商品简称， 小票中没有保存到数据库，以后要保存到本地数据库
    float fPrice;//显示单价
    float fNumber;//销售数量
    QString sSumPrice;//显示总价
    QString sUnit;//单位
    bool bPromotion;//是否促销
    bool bDisCount; // 是否折扣
    float fHaveRefundNum; // 是否已经退过
    int nTasteType;//商品口味分级
    bool bStandard;//商品类型
    int nCategoryId;//商品分类id
    float fRefundPrice;//退款金额
    float fRefundNumber;//退款数量
    QString sRefundSumPrice;//退款总价
    bool bSelectStatus;//商品选中状态

    GoodsDetailInfo()
        : nPos( -1 )
        , nSaleDetailPos( -1 )
        , nGoodsId( -1 )
        , strGoodsCode( "" )
        , sGoodsName( "" )
        , strGoodsShortName( "" )
        , fPrice( 0.00 )
        , fNumber( 0.00 )
        , sSumPrice( "" )
        , sUnit( "" )
        , bPromotion( false )
        , bDisCount ( false )
        , fHaveRefundNum( 0.0f )
        , bStandard( false )
        , nCategoryId( -1 )
        , fRefundPrice( 0.00 )
        , fRefundNumber( 0.00 )
        , sRefundSumPrice( "0.00" )
        , bSelectStatus( false ) {}
};

Q_DECLARE_METATYPE(GoodsDetailInfo)

typedef struct _tagSaleDetails { //总共24个字段 2016.12.15
    int nSaleDetailPos;       //销售明细id
    QString strOrderNum;     //单号
    QString strBarCode;   //商品条码
    QString strGoodsName;     //商品名称
    int nGoodsId;         //商品id
    QString strGoodsScode; //商品编号

    QString strGoodsSpec;       //商品规格
    float fSwapPrice;     //实际成交单价
    QString strSwapAmt;    //实际成交金额
    float fPopDisAmt;    //促销折扣
    float fPopDisRate;   //促销折扣率,8折

    float fGrantDisRate;//临时折扣率
    float fAllDisAmt;   //所有优惠金额
    float fTaxRate;       //税率
    QString strInpBarCode;  //扫描条码
    QString strBatchNo;   //促销活动号（SJ使用中）

    QString strPromPrice; //促销改价单号
    QDateTime dtCreateTime;//创建时间
    int nStatus;//商品状态: -1:取消，1:正常
    int pStatus;//订单状态: 0:整除 1:改价
    float fPrice;//原单价
    float fMemPrice; //会员价

    QString strOrgSum;//原总金额
    QString strOrgMemSum;//原会员价总金额
    GoodsDetailInfo goodsInfo;
    QString strLog;        //日志

    _tagSaleDetails()
        : nSaleDetailPos( 1 )
        , strOrderNum( "" )
        , strBarCode( "" )
        , strGoodsName( "" )
        , nGoodsId( -1 )
        , strGoodsSpec( "" )
        , fSwapPrice( 0.00 )
        , strSwapAmt( "0.00" )
        , fPopDisAmt( 0.00 )
        , fPopDisRate( 0.00 )
        , fGrantDisRate( 0.00 )
        , fAllDisAmt( 0.00 )
        , fTaxRate( 0.00 )
        , strInpBarCode( "" )
        , strBatchNo( "" )
        , strPromPrice( "" )
        , dtCreateTime( QDateTime::currentDateTime() )
        , nStatus( 1 )
        , fPrice( 0.00 )
        , fMemPrice( 0.00 )
        , strOrgSum( "0.00" )
        , strOrgMemSum( "0.00" )
        , strLog( "" ) {}
} SaleDetails;
Q_DECLARE_METATYPE(SaleDetails)

typedef struct _tagPromotionDetails {
    int nPromotionType;       //促销类型
    QString strPromotionName;     //促销名称
    QString strPromotionID;   //促销ID
    void * pPromotionRule;     //促销规则
    QList<GoodsDetailInfo *> listGoodsDetailInfo;
    float fPromotionAmt;//促销优惠金额

    _tagPromotionDetails()
        : nPromotionType( -1 )
        , strPromotionName( "" )
        , strPromotionID( "" )
        , pPromotionRule( NULL )
        , fPromotionAmt( 0.00 ){}
} PromotionDetails;

typedef struct _tagSaleHead {//总共32个字段 2016.12.15
    int nSaleHeadId;//销售id
    int nSerialNum;//流水号（5位）
    QString strPosId;//款机号
    QString strOrderNum;//单号（pos号+日期YYMMDD+流水号）
    int nSaleTotalNum;//商品总数

    float actChange; //明细表找零
    float fOughtAmt;//应付金额
    float fFactorAmt;//实付金额：
    float fOddChange;//找零
    QString strMemCardId;//会员卡号
    QString strMemName; //会员名称
    QString strLastShopping; // 上次购物时间
    QString strLastCharge; // 上笔找零
    int nMemInteger;//会员积分

    QString strDisReason;//折扣原因
    float fGrantDisRate;//临时折扣率
    float fAllDisAmt;//所有优惠金额
    float fCouponDisAmt;//优惠券优惠金额
    float fProfitLoss;//收银损益(实际支付的钱- 找零-应付金额)
    int nStatus;//交易状态:1:完成，-1:取消【已退款】 2:正在进行，3:挂单，

    int nType;//购物类型:0.现购，1.网购，2.团购
    int nShopId;//门店编号
    EUploadReceiptStatus eUploadStatus;//上传总部状态
    QDateTime dtCreateTime;//创建时间
    QDateTime dtFactorTime;//实际交易时间

    int nCostTime;//交易花费时间
    QDateTime dtCompleteTime;//交易完成时间
    QDateTime dtReceiptUpload;//小票上传时间
    int nCashierId;//收款员编号
    QString strCashierName;//收款员姓名
    int nShoppingId;//导购员ID
    QString strShoppingName;//导购员Name

    int nTranStatus;//交易状态:-1.取消，0.正在进行，1.完成 // 【以后不要了】
    int nSaleType;//销售类型：0.销售小票，1.退货小票，2.会员充值，3.储值卡充值，4.退充值，5.取消小票
    QString strReturnOrderNum;//退货订单号
    QString strReturnReason;//退货原因
    int nSaleMode;//销售方式：：1.KeyPos，2.待定

    QString sSmallChangeAmt; // 抹零金额

    //QVector<SaleDetails*> vctSaleDetails;
    QVector<PaymentDetailInfo*> vctPayDetails;

    QString strLog;        //日志

    _tagSaleHead()
        : nSaleHeadId( -1 )
        , nSerialNum( -1 )
        , strPosId( "" )
        , strOrderNum( "" )
        , nSaleTotalNum( 0 )
        , fOughtAmt( 0.00f )
        , fFactorAmt( 0.00f )
        , fOddChange( 0.00f )
        , strMemCardId( "" )
        , nMemInteger( 0 )
        , strDisReason( "" )
        , fGrantDisRate( 0.00f )
        , fAllDisAmt( 0.00f )
        , fCouponDisAmt( 0.00f )
        , fProfitLoss( 0.00f )
        , nStatus( 1 )
        , nType( 0 )
        , nShopId( 0 )
        , eUploadStatus( eNotUpload )
        , dtCreateTime( QDateTime::currentDateTime() )
        , dtFactorTime( QDateTime::currentDateTime() )
        , nCostTime( 0 )
        , dtCompleteTime()
        , dtReceiptUpload()
        , nCashierId( 0 )
        , strCashierName( "" )
        , nTranStatus( -1 )
        , nSaleType( 0 )
        , strReturnOrderNum( "" )
        , nSaleMode( 1 )
        , strLog( "" ) {}
} SaleHead;

struct RefundWithReceiptInfo
{
    QString sRefundSequence; // 支付单号
    QString sRefundWay; // 退款方式
    QString sRefundState; // 退款状态
    int nRefundSum; // 退款金额
    int nPos;
};
Q_DECLARE_METATYPE(RefundWithReceiptInfo)

struct StatementInfo
{
    QString strOrderNum; // 序列号
    float fDiscount; // 折扣
    float fDisAmt; // 优惠金额
    float fCouponDisAmt;//优惠券优惠金额
    float fProfitLoss;//收银损益
    float fSimpleAmt; // 整单金额
    float fOddChange;//找零金额
    int nSucNum;//支付详情(成功个数）
    int nTotalNum;//支付详情（总个数）

    StatementInfo()
        : strOrderNum( "" )
        , fDiscount( 0.00 )
        , fDisAmt( 0.00 )
        , fProfitLoss( 0.00 )
        , fOddChange( 0.00 )
        , nSucNum( 0 )
        , nTotalNum( 0 ) {}
};

struct GoodsChooseInfo
{
    int id;
    QString name;
    bool bRootGoods;
    QString price; // 价格
    QString unit; // 单位
};
Q_DECLARE_METATYPE(GoodsChooseInfo)

struct CategoryChooseInfo
{
    QString skeyId; // id
    QString name; // 名字
    int num; // 序号
    int position; // 位置
    bool bRoot; // 是否是根节点
    QList<int> selectedGoodsIdList;
    QList<GoodsChooseInfo> goodsChooseInfoList;
};
Q_DECLARE_METATYPE(CategoryChooseInfo)

#endif
