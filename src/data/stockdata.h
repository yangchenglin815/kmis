#ifndef STOCKDATA_H
#define STOCKDATA_H

#include <QVariant>

struct StockOrderInfo
{
    qint64 nOrderId; // 单号id
    QString sOrderNum; // 单号
    QString sMaker; // 制单人
    QString sChecker; // 审核人
    QString sMakeTime; // 审核时间
    QString sCreateTime; // 制单时间
    int nState; // 状态
};
struct InStockOrderInfo
{
    qint64 nOrderId; // 单号id
    QString sOrderNum; // 单号
    QString sMaker; // 制单人
    QString sChecker; // 审核人
    QString sMakeTime; // 修改时间
    QString sCheckTime; // 审核时间
    QString sShop; // 门店
    int nState; // 审核状态
};

typedef struct InStockOrderSearchInfo
{//查看入库商品信息
    bool isEdited;//已修改的flag
    QString sSeq; // 行序号
    QString sCode; // 商品编码
    qint64 nId; // 商品种类id
    QString sName;//商品名
    QString sPrice; // 传过来的单价
    QString sTotal; // 传过来的总金额
    QString sCount; // 传过来的数量
    QString sBoxNum; // 传过来的件数,筐数
    QString sSubTotal; //传过来的小计金额
    QString sWeighUnit; // 称重单位/要货规格单位
    QString sSellUnit;//销售单位
    QString sBelongCategory; // 所属分类
    QString sBarCode; // 商品条码/plu码
    QString sPinYinName; // 拼音助记码
    QString sWuBiName; // 五笔助记码
    bool bStandard;//商品类型(标品，非标品）
    float fShouldCount; // 变更入单总个体数量
    float fShouldTotal; // 应该变成的小计单价
    float fBatchPrice; //编辑好的入库单价
    float fMarkNum;//入库规格单位
    float fPackage;//入库件数
}InStockSelectGoodsInfo, InStockOrderGoodsInfo;
Q_DECLARE_METATYPE(InStockOrderSearchInfo)
Q_DECLARE_METATYPE(InStockOrderInfo)


struct OutStockOrderInfo
{
    qint64 nOrderId; // 单号id
    QString sOrderNum; // 单号
    QString sMaker; // 制单人
    QString sChecker; // 审核人
    QString sMakeTime; // 修改时间
    QString sCheckTime; // 审核时间
    QString sShop; // 门店
    int nState; // 审核状态
};

typedef struct OutStockOrderSearchInfo
{//查看出库商品信息
    bool isEdited;//已修改的flag
    QString sSeq; // 行序号
    QString sCode; // 商品编码
    qint64 nId; // 商品种类id
    QString sName;//商品名
    QString sPrice; // 传过来的单价
    QString sTotal; // 传过来的总金额
    QString sCount; // 传过来的数量
    QString sBoxNum; // 传过来的件数,筐数
    QString sSubTotal; //传过来的小计金额
    QString sWeighUnit; // 称重单位/要货规格单位
    QString sSellUnit;//销售单位
    QString sBelongCategory; // 大类
    QString sBarCode; // 商品条码/plu码
    QString sPinYinName; // 拼音助记码
    QString sWuBiName; // 五笔助记码
    bool bStandard;//商品类型(标品，非标品）
    float fShouldCount; // 变更入单总个体数量
    float fShouldTotal; // 应该变成的小计单价
    float fBatchPrice; //编辑好的入库单价
    float fMarkNum;//箱数与件数的量比系数  如 5公斤/箱的5
    float fPackage;//入库件数
}OutStockSelectGoodsInfo, OutStockOrderGoodsInfo;
Q_DECLARE_METATYPE(OutStockOrderSearchInfo)
Q_DECLARE_METATYPE(OutStockOrderInfo)


Q_DECLARE_METATYPE(StockOrderInfo)

typedef struct StockOrderSearchInfo
{
    QString sSeq; // 序号
    int nId; // 商品id
    QString sName; // 商品名称
    QString sCode; // 商品编码
    QString sBelongCategory; // 所属分类
    QString sBarCode; // 商品条码/plu码
    QString sShortName; // 商品简称
    QString sPinYinName; // 拼音助记码
    QString sWuBiName; // 五笔助记码
    QString sWeighUnit; // 称重单位
    bool bStandard;//商品类型(标品，非标品）
    float fShouldStockNum; // 账盘数量
    float fRealStockNum; // 实盘数量
    float fStockDifferNum; // 差异数量
    float fBuyDifferPrice; // 进价差异金额
    int nBatchId; // 最新批次ID
    float fBatchPrice; //最新批次进价
}StockSelectGoodsInfo, StockOrderGoodsInfo;
Q_DECLARE_METATYPE(StockOrderSearchInfo)

// 商品库存信息
struct GoodsStockInfo
{
    float fShouldStockNum; // 账盘数量/入库数量
    float fBuyPrice; // 进价/入库单价
    int nBatchId; // 最新批次ID/商品ID
    float fPackage;//入库件数
    float fMarkNum;//转化关系
};

#endif // STOCKDATA_H

