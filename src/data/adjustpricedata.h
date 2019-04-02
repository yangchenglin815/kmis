#ifndef ADJUSTPRICEDATA_H
#define ADJUSTPRICEDATA_H

#include <QVariant>

struct AdjustPriceOrderInfo
{
    int nOrderId; // 单号id
    QString sOrderNum; // 单号
    QString sMaker; // 制单人
    QString sChecker; // 审核人
    QString sMakeTime; // 修改时间
    QString sEffectTime; // 生效时间
    int nState; // 状态
};
Q_DECLARE_METATYPE(AdjustPriceOrderInfo)

typedef struct AdjustPriceOrderSearchInfo
{
    QString sSeq; // 序号
    int nId; // 商品id
    QString sName; // 商品名称
    QString sCode; // 商品编码
    QString sBarCode; // 商品条码/plu码
    QString sShortName; // 商品简称
    QString sPinYinName; // 拼音助记码
    QString sWuBiName; // 五笔助记码
    QString sWeighUnit; // 称重单位
    float fOldPrice; // 原售价
    float fNowPrice; // 现售价
    float fOldMemberPrice; // 原会员价
    float fNowMemberPrice; // 现会员价
}AdjustPriceSelectGoodsInfo, AdjustPriceGoodsInfo;
Q_DECLARE_METATYPE(AdjustPriceOrderSearchInfo)
//struct AdjustPriceSelectGoodsInfo
//{
//    QString sSeq; // 序号
//    int nId; // 商品id
//    QString sName; // 商品名称
//    QString sCode; // 商品编码
//    QString sWeighUnit; // 称量单位
//    float fOldPrice; // 原单价
//    float fNowPrice; // 现单价
//    float fOldMemberPrice; // 原会员价
//    float fNowMemberPrice; // 现会员价
//};
//Q_DECLARE_METATYPE(AdjustPriceSelectGoodsInfo)

#endif // ADJUSTPRICEDATA_H

