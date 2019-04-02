#ifndef GOODSMANAGEDATA
#define GOODSMANAGEDATA

#include <QString>
#include <QVariant>

struct sGoodsInfo_s
{
    int id;
    int nId; // 商品ID
    int nCategoryId; //所属分类
    QString sCode; // 商品编码
    QString sName; // 商品名称
    QString sUnitSpecification; // 规格单位
    float sStockNumber; // 库存数量
    QString sCodeId; // 商品条码
    float fPrice; // 单件单价
    float vPrice; // 会员价
    int category; // 称重类型 1:标品 2:计重 3:计数
};

struct CategorySmallInfo_s
{
    int nId;
    QString sName;
    QList<int> leafCategoryIdList;
};

struct CategoryBigInfo_s
{
    int nId;
    QString sName;
    QList<CategorySmallInfo_s> smallCategoryList;
};

struct sGoodsInfo
{
    int id;
    int nId; // 商品ID
    QString sCode; // 商品编码
    QString sName; // 商品名称
    QString sUnitSpecification; // 规格单位
    float sStockNumber; // 库存数量
    QString sCodeId; // 商品条码
    float fPrice; // 单件单价
    float vPrice; // 会员价
    int category;
    int nBelongCategoryBigId; // 所属的大类id
    int nBelongCategorySmallId; // 所属的类id
};
Q_DECLARE_METATYPE(sGoodsInfo)

struct sCategorySmallInfo
{
    int nId;
    QString sName;
    int nNumber; // 选中的商品种数
    QList<int> leafCategoryIdList;
    QList<sGoodsInfo*> sGoodsInfoList;
    bool bFakeSmallCategory; // 是否是假的二级分类
};
Q_DECLARE_METATYPE(sCategorySmallInfo)

struct sCategoryBigInfo
{
    int nId;
    QString sName;
    int nNumber; // 二级分类个数
    bool bDrawLine;
    QList<sCategorySmallInfo*> sCategorySmallInfoList;
};
Q_DECLARE_METATYPE(sCategoryBigInfo)
#endif // GOODSMANAGEDATA

