#ifndef BARCODESCALE_H
#define BARCODESCALE_H

#include <QVariant>

struct BarCodeScaleInfo
{
    QString sKeyId; // 主键id
    QString sSeq;//列表序号
    QString sCode; // 编号
    QString sModel; // 型号
    QString sIP; // IP
    QString sGoodsGroup; // 关联商品组ID
    QString sGoodsGroupName;//关联商品组名称
    QString sSendDownTime; // 上次下发时间
    int nState; // 状态
};
Q_DECLARE_METATYPE(BarCodeScaleInfo)

// 条码秤商品信息
struct BCSGoodsInfo
{
    QString sKeyId;
    QString sName; // 商品名字
    QString sCode; // 商品编号
    QString sUnit; // 商品单位
    QString sPlu; // 商品PLU码
    QString sPrice; // 商品价格
    QString sMemberPrice; // 商品会员价
    int nCategoryId; // 分类id
};
Q_DECLARE_METATYPE(BCSGoodsInfo)

struct BCSGroupManageRightInfo
{
    QString sKeyId; // 主键id:商品plu
    int nGoodsId; //
    QString sSeq; // 序号
    QString sGoodsName; // 商品名称
    QString sGoodsCode; // 商品编号
    QString sGoodsUnit; // 商品单位
    QString sGoodsPlu; // 商品plu码
    QString sGoodsPrice; // 商品价格
    QString sGoodsMemberPrice; // 商品会员价
};
Q_DECLARE_METATYPE(BCSGroupManageRightInfo)

struct BCSGroupManageLeftInfo
{
    int nGroupId; // 组id
//    QString sKeyId; // 主键id:组id
    QString sSeq; // 序号
    QString sGroupNum; // 组号
    QString sGroupName; // 组名
    QList<BCSGroupManageRightInfo> rightInfoList;//商品信息
};
Q_DECLARE_METATYPE(BCSGroupManageLeftInfo)

//struct BCSSendDownData
//{
//    QString sKeyId; // 主键id:商品id
//    QString sSeq; // 序号
//    QString sCode; // 编号
//    QString sModel; // 型号
//    QString sIP; // IP
//    int nState; // 状态
//};
//Q_DECLARE_METATYPE(BCSSendDownData)

#endif // BARCODESCALE_H

