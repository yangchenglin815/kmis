#ifndef REPORTCHARTSDATA_H
#define REPORTCHARTSDATA_H

#include <QVariant>

// 实时销售排行信息
struct RankChartsInfo
{
    int nGoodsId; // 商品id
    int nPosition; // 排序位置
    QString sGoodsName; // 商品名称
    QString sGoodsCode; // 商品编号
    float fSaleMoney; // 销售额
    float fGoodsPrice; // 单价
    float fSaleNumber; // 销售量
    int nPeopleNumber; // 客流
};
Q_DECLARE_METATYPE(RankChartsInfo)

// 实时销售汇总信息
struct SummaryChartsInfo
{
    QString sTimePeriod;// 时段
    float fSaleMoney; // 销售额
    int nPeopleNumber; // 客流量
    float fPeoplePrice;// 客单价
};
Q_DECLARE_METATYPE(SummaryChartsInfo)

#endif // REPORTCHARTSDATA_H
