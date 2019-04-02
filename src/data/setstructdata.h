#ifndef SETSTRUCTDATA_H
#define SETSTRUCTDATA_H

#include <QList>
#include "receiptdata.h"

// Pos机基础信息
struct PosInfoSet
{
    QString sAppVersion; // 程序版本
    QString sShopCode;  // 门店编号    门店ID
    QString sShopName; // 门店名称
    QString sCode; // pos机编号
    //   QString sPosModel; // pos机名称
    //   int nSkinType; // 皮肤类型
    bool bChanged; // 是否有更改
};

struct KeySetInfo
{
    int nKeyId; // 按键名字
    bool bStartUsed; // 是否启用
};

// 按键设置
struct KeySet
{
    QList<KeySetInfo> homeKeyList; // 首页按键列表
    QList<KeySetInfo> refundKeyList; // 退款按键列表
    bool bChanged; // 是否有更改
};

struct CategoryInfoSet // 分类信息设置
{
    int nCategoryId; // 分类id
    QString sCategoryName; // 分类名
    QList<int> goodsIdList; // 所包含的商品id列表（id之间用逗号隔开）
    bool bCustom;// 是否自定义
};

// 商品设置
struct GoodSet
{
    QList<CategoryInfoSet> categorySetList;
    bool bChanged; // 是否有更改
};

struct MovieAD // 广告设置
{
    int nId; // 广告id
    int nStatus; // 删除， 可播放， 不可播放
    QString sPath; // 广告路径
    bool bPictrue;
};

// 外显设置
struct ScreenSet
{
    //   QString sPrinterModel; // 打印机型号
    //   bool bAllowPrint; // 是否允许打印
    //   int nClientScreenType; // 客显类型
    //   QString sClientScreenModel; // 客显型号
    //   QString sClientScreenPort; // 客显端口
    //   QString sCardReaderModel; // 读卡器型号
    //   QString sCardReaderPort; // 读卡器端口
    //   QString sEBalanceModel; // 电子秤型号
    //   QString sEBalancePort; // 电子秤端口
    QList<MovieAD> remoteADList; // 远程广告列表
    QList<MovieAD> localADList; // 本地广告列表
    bool bChanged;
};

struct PayWayInfoSet // 支付方式信息
{
    int nPayType; // 支付类型
    bool bStartUse; // 是否启动
    bool bChargeMember; // 是否用于会员充值
    bool bVirtualPay; // 是否虚拟支付
    int nDropType; //　分的圆整方式,4表示不处理
    QString sPayName; // 支付类型名称
    //    int nRefundOrder; // 退款顺序

    PayWayInfoSet()
        : nPayType( -1 ) {}
};

struct VirtualPayInfo
{
    QString sCode;
    QString sName;
};

// 支付设置
struct PayWaySet
{
    QList<PayWayInfoSet> payWayInfoSetList;
    bool bChanged;
};

// 虚拟支付设置
struct VirtualPaySet
{
    QList<VirtualPayInfo> virtualList;
    bool bChanged;
};

struct SystemSetParams // 系统参数
{   
    int nDataSaveDays; // 销售数据保存时间
    int nGoodsMaxNumber; // 销售时单品最大数量
    int bDiscountOnMember; // 会员价打折基础
    int bDiscountOnDiscount; // 是否可以折上折
    bool bDiscardZero; // 是否可以抹零
    int bFillReasonForRefund; // 是否选择退货原因
    bool bPriceSale; // 是否输入价格销售
    int nPriceSaleLimit; // 价格范围
};

struct ShopSetParams // 门店参数
{
    bool bChangePriceBySeller; // 收银员是否有打折改价权限
    bool bCreateGoodsBySeller; // 收银员是否有快速建档权限
    bool bOpenCashboxBySeller; // 收银员是否有开钱箱权限
    bool bSellZeroGoodsBySeller; // 前台是否允许销售售价为零的商品
    bool bHandinCashBySeller; // 收银员是否交款
    bool bChooseSeller; // 结算是否选择业务员
    int nPendingListMaxLength; // 最大挂单数
    int nLockWaitTimeLenth; // 锁屏等待时间
    QString sReceiptShopName; // 小票门店名称
//    bool bSaleByPrice; // 是否输入价格销售
//    QString sPriceRange; // 价格范围
};

// 参数设置
struct ParamsSet
{
    SystemSetParams systemSetParams; // 系统参数
    ShopSetParams shopSetParams; // 门店级参数
    bool bChanged; // 是否有变化
};

// 小票设置
struct ReceiptSet
{
    QString sQRCode; // 二维码数据，后台配置
    QString sHeadContent; // 头部语，后台配置
    QString sHeadWords; // 头部文字，后台配置
    QString sTailContent; // 尾部语，后台配置
    QString sPicturePath; // 自定义图片，后台配置
    ReceiptPrintOption option; // 小票打印选项
    bool bChanged;
};

struct CategoryInfoNode
{
    QString sName; // 分类名
    QString sId; // 分类id
    QString sCode;//分类编码
    int IdLen;//Id级别
	QList<CategoryInfoNode> nodeyList;
};
//typedef QMap<QString,CategoryInfoNode> nodeMap;//键 分类名
//typedef QMap<QString,QString> nodeStrMap;//键： nID  值：分类名
//typedef QList<nodeMap> nodeList;
struct CategoryNodeSet
{
    QList<CategoryInfoNode> nodeList; // 所有分类
    bool bChanged;
};

struct CategoryUnitSet
{
    QStringList unitList; // 所有分类
    bool bChanged;
};

// KPos设置
struct KPosSet
{
    PosInfoSet posInfoSet; // Pos机基础信息
    KeySet keySet; // 按键设置
    GoodSet goodSet; // 商品设置
    ScreenSet screenSet; // 外显设置
    PayWaySet payWaySet; // 支付设置
    VirtualPaySet virtualPaySet; // 虚拟支付设置
    ParamsSet paramsSet; // 参数设置
    ReceiptSet receiptSet;
    CategoryNodeSet categoryNodeSet; // 分类设置
//    CategoryUnitSet unitSet;//单位
};

#endif // SETSTRUCTDATA_H
