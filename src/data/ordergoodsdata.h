#ifndef ORDERGOODSDATA_H
#define ORDERGOODSDATA_H

#include <QString>
#include <QVariant>

struct OrderGoodsInfo_s
{
    int nId; // 商品id //    "product_id": 13,
    int nCategoryId; // 所属分类id //    "cid": 10,
    QString sName; // 商品名称 //    "product_name": "莴笋",
    QString sCode; // //    "product_bar_code": "2100013",
    QString sStockNumber; // 库存数量 //    "stock_qty": null,
    float fUnitSpecificationValue; // 规格单位量 //    "purchase_spec": 250,
    QString sUnitSpecification; // 规格单位//    "spe_unit": "250公斤/公斤",
    int nSaleNumberToday; // 当日已定//    "req_num": 0,
    float fPrice; // 单件单价 //    "price": "2.50",
    QString sSaleNumberYesterday; // 上日销售数量//    "yesterday_sale_qty": 0,
    QString sSaleNumberLastweek; // 上周销售数量//    "lastweek_sale_qty": 0,
    int nOrderSaleRate; // 订销差率//    "dx_rate": "无",
    QString sSuggestOrderNumber; //	建议要货件数//    "suggest_package": ""
};

struct OrderCategorySmallInfo_s
{
    int nId;
    QString sName;
    QList<int> leafCategoryIdList;
};

struct OrderCategoryBigInfo_s
{
    int nId;
    QString sName;
    QList<OrderCategorySmallInfo_s> smallCategoryList;
};

// 要货卡信息
struct OrderCardInfo_s
{
    int nOrderCardId; // 订单id
    QString sCardOrOrderId; // 卡号/单号
    int nCategoryId; // 分类id
    QString sCategoryName; // 分类名
    int nCategoryNum; // 分类数量
    bool bUploadFinish; // 是否已上传
    QString sOrderMaker; // 制单人
    QString sUploader; // 上传人
    QString sUpdateTime; // 修改时间
    QString sCreateTime; // 制单时间
    int nWantState; // 时段
};

// 要货卡详细信息
struct OrderCardDetailInfo_s
{
    int nId; // 商品ID
    QString sCode; // 商品编码
    QString sName; // 商品名称
    QString sShortName; // 商品简称
    QString sUnitSpecification; // 规格单位
    float fUnitSpecificationValue; // 规格单位量
    float fPrice; // 单件单价
    int nOrderGoodsNumber; // 要货量
};

struct OrderGoodsInfo
{
    int nId; // 商品ID
    QString sCode; // 商品编码
    QString sName; // 商品名称
    QString sUnitSpecification; // 规格单位
    float fUnitSpecificationValue; // 规格单位量
    QString sStockNumber; // 库存数量
    int nSaleNumberToday; // 当日已定
    float fPrice; // 单件单价
    QString sSaleNumberYesterday; // 上日销售数量
    QString sSaleNumberLastweek; // 上周销售数量
//    min_qty	int	要货件数下限，默认是1
//    max_qty	int	要货件数上限，默认是没有上限
    QString sSuggestOrderNumber; //	建议要货件数
    int nOrderSaleRate; // 订销差率
    int nOrderGoodsNumber; // 要货量
    int nBelongCategoryBigId; // 所属的大类id
    int nBelongCategorySmallId; // 所属的类id
};
Q_DECLARE_METATYPE(OrderGoodsInfo)

struct OrderCategorySmallInfo
{
    int nId;
    QString sName;
    int nNumber; // 选中的商品种数
    QList<int> leafCategoryIdList;
    QList<OrderGoodsInfo*> orderGoodsInfoList;
    bool bFakeSmallCategory; // 是否是假的二级分类
};
Q_DECLARE_METATYPE(OrderCategorySmallInfo)

struct OrderCategoryBigInfo
{
    int nId;
    QString sName;
    int nNumber; // 二级分类个数
    bool bDrawLine;
    QList<OrderCategorySmallInfo*> orderCategorySmallInfoList;
};
Q_DECLARE_METATYPE(OrderCategoryBigInfo)

struct CheckOrderGoodsInfo
{    
    int nId; // 商品ID
    QString sCode; // 商品编码
    QString sName; // 商品名称
    QString sShortName; // 商品简称
    QString sUnitSpecification; // 规格单位
    float fUnitSpecificationValue; // 规格单位量
    float fPrice; // 单件单价
    int nOrderGoodsNumber; // 要货量
    int nCheckOrderGoodsNumber; // 审核数量
};
Q_DECLARE_METATYPE(CheckOrderGoodsInfo)

struct CheckOrderCategoryDetailInfo
{
    int nOrderCardId; // 要货卡id
    QString sCardOrOrderId; // 卡号/单号
    int nCategoryId; // 分类id
    QString sCategoryName; // 分类名
    int nCategoryNum; // 分类数量
    bool bSelected; // 是否选中
    bool bUploadFinish; // 是否已上传
    QString sOrderMaker; // 制单人
    QString sUploader; // 上传人
    QString sUpdateTime; // 修改时间
    QString sCreateTime; // 制单时间
    QString sWantState; // 时段
};
Q_DECLARE_METATYPE(CheckOrderCategoryDetailInfo)

struct CheckOrderCategoryInfo
{
    int nId;
    QString sName;
    QList<CheckOrderCategoryDetailInfo*> m_categoryDetailInfoList;
};
Q_DECLARE_METATYPE(CheckOrderCategoryInfo)

#endif // ORDERGOODSDATA_H
