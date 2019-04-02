#ifndef STOCKINGDATA_H
#define STOCKINGDATA_H

#include <QVariant>

// 盘点订单的商品信息
struct StockingOrderGoodsInfo
{
    int nGoodsId; // 商品id
    QString sGoodsName; // 商品名称
    QString sGoodsCode; // 商品编码
    QString sCategoryName; // 商品类别
    QString sUnit; // 称重单位
    float fShouldStockNum; // 本该的库存量
    float fRealStockNum; // 实际的库存量
    float fDifferMoney; // 相差金额
    bool bSelected; // 选择
    bool bLocated; // 是否定位
};
Q_DECLARE_METATYPE(StockingOrderGoodsInfo)

// 盘点订单信息
struct StockingOrderInfo
{
    QString sOrderId; // 订单id
    int nType; // 类型
    int nState; // 状态
    QString sStockingData; // 盘点日期
    QString sOrderMaker; // 制单人
    QString sOrderMakeDate; // 制单日期
    QString sCheckStockingMan; // 录入审核人
    QString sCheckStockingDate; // 录入审核日期
    QString sStockingAgainCode; // 复盘编号
    QList<StockingOrderGoodsInfo*> m_stockingOrderGoodsInfoList;
};
Q_DECLARE_METATYPE(StockingOrderInfo)

#endif // STOCKINGDATA_H
