#ifndef RECIEVINGGOODSDATA_H
#define RECIEVINGGOODSDATA_H

#include <QVariant>

// 送货单信息
struct DeliveryOrderInfo_s
{
    int nId; // 送货单id
    QString sCode; // 送货单编号
    int nOrderType; // 订单类型
    QString sProviderName; // 提供商名称
    QString sProviderCode; // 提供商编号
    int nNeedReceiveSumNum; // 应收件数
    float fNeedReceiveSumValue; // 应收数量
    int nRealReceiveSumNum; // 实收件数
    float fRealReceiveSumValue; // 实收数量
    float fSumPrice; // 金额
    QString sUploadDate; // 上传日期
    QString sUploadTime; // 上传时间
    int nRecieveState; // 收货状态 (已完成，收货中，未完成)
};

// 送货单明细信息
struct DeliveryOrderDetailInfo_s
{
    int nId; // 送货单商品id
    int nGoodsId; // 商品id
    QString sGoodName; // 商品名称
    QString sGoodsCode; // 商品编号
    QString sUnitSpecification; // 规格单位  (如4公斤/箱)
    float fUnitSpecificationValue; // 规格单位值  (4 -- 4公斤/箱的4)
    int nNeedReceiveSumNum; // 应收件数
    float fNeedReceiveSumValue; // 应收数量
    int nRealReceiveSumNum; // 实收件数
    float fRealReceiveSumValue; // 实收数量
    float fSumPrice; // 收货金额
    int nRecieveGoodsState; // 收货状态 0.未收，1.已收
};

// 标品计件
struct ReceiveOrderGoodsDetailStandardInfo
{
    float fStandardWeight; // 规格
    int nReceiveNum; // 采购件数
    float fReciveSumValue; // 采购数量
    float fPrice; // 单价
};

// 非标品计件
struct ReceiveOrderGoodsDetailNoStandardInfo
{
    float fAllWeidght; // 毛重
    float fPeelWeight; // 皮重
    int nReceiveNum; // 采购件数
    float fPrice; // 单价
};

// 非标品散斤
struct ReceiveOrderGoodsDetailDisperseInfo
{
    float fPrice; // 单价
    float fReciveSumValue; // 实采数量
};

// 收货商品明细
struct ReceiveGoodsDetail_s
{
    bool bStandardGoods; // 是否标品
    bool bFixWeight; // 重量是否固定
    bool bDisperseWeight; // 是否散斤称重
    ReceiveOrderGoodsDetailStandardInfo standardInfo;
    ReceiveOrderGoodsDetailNoStandardInfo noStandardInfo;
    ReceiveOrderGoodsDetailDisperseInfo disperseInfo;
};

//
struct ReceiveGoodsDetailChanged
{
    int nId; // 送货单商品id
    int nRealReceiveSumNum; // 实收数量
    float fRealReceiveSumValue; // 实收重量
    float fSumPrice; // 总价
    float fAddedSumPrice; // 变化的总价格
    float nAddedRealReceiveSumNum; // 变化的实收数量
    float fAddedRealReceiveSumValue; // 变化的实收重量
};

// 创建手工收货单商品信息
struct GoodsForCreateInfo
{
    int nGoodsId; // 商品id
    QString sGoodName; // 商品名称
    QString sGoodsCode; // 商品编号
    QString sUnitSpecification; // 规格单位
    float fUnitSpecificationValue; // 规格单位值
    QString sSpecification; // 规格
    bool bStandardGoods; // 是否标品
};
Q_DECLARE_METATYPE(GoodsForCreateInfo)

struct ReceiveProviderInfo
{
    int nId; // 供应商id
    QString sName; // 供应商名称
    QString sCode; // 供应商编号
    QList<GoodsForCreateInfo*> goodsForCreateInfoList;
};
Q_DECLARE_METATYPE(ReceiveProviderInfo)

struct ReceiveOrderGoodsInfo
{
    int nId; // 送货单商品id
    int nGoodsId; // 商品id
    QString sGoodName; // 商品名称
    QString sGoodsCode; // 商品编号
    QString sUnitSpecification; // 规格单位  (如4公斤)
    float fUnitSpecificationValue; // 规格单位值  (4 -- 4公斤重的4)
//    QString sSpecification; // 规格 (箱)
    int nNeedReceiveSumNum; // 应收件数
    float fNeedReceiveSumValue; // 应收数量
    int nRealReceiveSumNum; // 实收件数
    float fRealReceiveSumValue; // 实收数量
    float fSumPrice; // 收货金额
    bool bGoodsRecieveFinish; // 收货商品是否完成
    bool bStandardGoods; // 是否标品
    int nWeighType; // 称重类型
    ReceiveOrderGoodsDetailStandardInfo standardInfo;
    ReceiveOrderGoodsDetailNoStandardInfo noStandardInfo;
    ReceiveOrderGoodsDetailDisperseInfo disperseInfo;
};
Q_DECLARE_METATYPE(ReceiveOrderGoodsInfo)

// 收货单信息
struct ReceiveOrderInfo
{
    int nId; // 送货单id
    QString sCode; // 送货单编号
    int nOrderType; // 订单类型
    QString sProviderName; // 提供商名称
    QString sProviderCode; // 提供商编号
    int nNeedReceiveSumNum; // 应收件数
    float fNeedReceiveSumValue; // 应收数量
    int nRealReceiveSumNum; // 实收件数
    float fRealReceiveSumValue; // 实收数量
    float fSumPrice; // 金额
    QString sUploadDate; // 上传日期
    QString sUploadTime; // 上传时间
    int nRecieveState; // 收货状态 (已完成，收货中，未完成)
    QList<ReceiveOrderGoodsInfo*> receiveOrderGoodsInfoList;
};
Q_DECLARE_METATYPE(ReceiveOrderInfo)

#endif // RECIEVINGGOODSDATA_H
