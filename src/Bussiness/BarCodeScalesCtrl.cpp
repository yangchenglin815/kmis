#include "BarCodeScalesCtrl.h"
#include "../Agent/BarCodeScalesAgent.h"
#include "../Agent/OrderGoodsAgent.h"
#include "../Agent/CategoryInfoAgent.h"
#include "../data/constData.h"

BarCodeScalesCtrl::BarCodeScalesCtrl(QObject *parent) : QObject(parent)
{
    initConnect();
}

void BarCodeScalesCtrl::checkBcsState(const QList<BarCodeScaleInfo> &infoList)
{
    BarCodeScalesAgent::instance()->checkBcsState(infoList);
}

void BarCodeScalesCtrl::getAllCategoryRequest()
{
    OrderGoodsAgent::instance()->getOrderCategoryRequest();
}

void BarCodeScalesCtrl::getBcsGoods(QMap<int, QList<BCSGoodsInfo> > &bcsGoodsInfoMap)
{
    QMap<int, QList<GoodsInfo_s> > goodsInfoMap;
    CategoryInfoAgent::instance()->getAllWeighGoodsList(goodsInfoMap);
    QList<int> keyList = goodsInfoMap.keys();
    int nLen1 = keyList.length();
    int nKey = -1;
    int nLen2 = -1;
    QList<GoodsInfo_s> goodInfoList;
    QList<BCSGoodsInfo> bcsGoodsInfoList;
    BCSGoodsInfo bcsGoodsInfo;
    for (int i = 0; i < nLen1; i++)
    {
        nKey = keyList[i];
        bcsGoodsInfo.nCategoryId = nKey;
        goodInfoList = goodsInfoMap.value(nKey);
        bcsGoodsInfoList.clear();
        nLen2 = goodInfoList.length();
        for (int j = 0; j < nLen2; j++)
        {
            convertToBcsGoodsInfo(bcsGoodsInfo, goodInfoList[j]);
            bcsGoodsInfoList.append(bcsGoodsInfo);
        }
        bcsGoodsInfoMap.insert(nKey, bcsGoodsInfoList);
    }
}

void BarCodeScalesCtrl::sendDownBcs(QList<BarCodeScaleInfo> &infoList , QList<BCSGroupManageLeftInfo> &m_leftInfoList)
{
    BarCodeScalesAgent::instance()->sendDownBcs(infoList, m_leftInfoList);
}

void BarCodeScalesCtrl::createGoodsGroupRequest(QString sGroupName)
{
    BarCodeScalesAgent::instance()->createGoodsGroupRequest(sGroupName);
}

void BarCodeScalesCtrl::getGoodsGroupListRequest()
{
    BarCodeScalesAgent::instance()->getGoodsGroupListRequest();
}


void BarCodeScalesCtrl::saveGoodsGroupRequest(int nGroupId, const QList<QString> &pluList)
{
    BarCodeScalesAgent::instance()->saveGoodsGroupRequest(nGroupId, pluList);
}

void BarCodeScalesCtrl::getBarcodeScaleCodeRequest()
{
    BarCodeScalesAgent::instance()->getBarcodeScaleCodeRequest();
}

void BarCodeScalesCtrl::addBarcodeScaleRequest(QString sCode, QString sType, QString sIp, int nGroupId)
{
    BarCodeScalesAgent::instance()->addBarcodeScaleRequest(sCode, sType, sIp, nGroupId);
}

void BarCodeScalesCtrl::getBarcodeScaleListRequest()
{
    BarCodeScalesAgent::instance()->getBarcodeScaleListRequest();
}

void BarCodeScalesCtrl::updateScaleProductIssueRequest(const QList<QString> &scaleList)
{
    BarCodeScalesAgent::instance()->updateScaleProductIssueRequest(scaleList);
}

void BarCodeScalesCtrl::deleteScaleRequestRequest(QString scaleId)
{
    BarCodeScalesAgent::instance()->deleteScaleRequestRequest(scaleId);
}

void BarCodeScalesCtrl::slot_onGetGoodsGroupList(int nCode, QString sMsg, QList<BCSGroupManageLeftInfo> leftInfoList)
{
    QMap<QString, GoodsInfo_s> goodsInfoMap;
    CategoryInfoAgent::instance()->getAllWeighGoodsList(goodsInfoMap);
    QMap<QString, GoodsInfo_s>::iterator iter;

    BCSGroupManageLeftInfo leftInfo;
    leftInfo.nGroupId = c_nDefaultGoodsGroupId;
    leftInfo.sGroupName = QStringLiteral("默认商品组");
    leftInfo.sGroupNum = "000";

    BCSGroupManageRightInfo rightInfo;
    for (iter = goodsInfoMap.begin(); iter != goodsInfoMap.end(); iter++)
    {
        rightInfo.sKeyId = iter->sBarCode; // 主键id:商品plu
        rightInfo.nGoodsId = iter->nId; //
        //            rightInfo.sSeq; // 序号
        rightInfo.sGoodsName = iter->sShortName; // 商品名称
        if (rightInfo.sGoodsName.isEmpty())
        {
            rightInfo.sGoodsName = iter->sName;
        }
        rightInfo.sGoodsCode = iter->sCode; // 商品编号
        rightInfo.sGoodsUnit = iter->sSaleUnit; // 商品单位
        rightInfo.sGoodsPlu = iter->sBarCode; // 商品plu码
        if (rightInfo.sGoodsPlu.length() == 4)
        {
            rightInfo.sGoodsPlu.append("1");
        }
        rightInfo.sGoodsPrice = QString::number(iter->goodsPriceInfo.fPrice, 'f', 2); // 商品价格
        rightInfo.sGoodsMemberPrice = QString::number(iter->goodsPriceInfo.fMemberPrice, 'f', 2); // 商品会员价
        leftInfo.rightInfoList.append(rightInfo);
    }
    leftInfoList.append(leftInfo);

    emit sigOnGetGoodsGroupList(nCode, sMsg, leftInfoList);
}

void BarCodeScalesCtrl::initConnect()
{
    qRegisterMetaType<QList<OrderCategoryBigInfo_s> >("QList<OrderCategoryBigInfo_s>");
    connect(OrderGoodsAgent::instance(), SIGNAL(sigOnGetOrderCategory(int,QString,QList<OrderCategoryBigInfo_s>))
            ,this, SIGNAL(sigOnGetOrderCategory(int,QString,QList<OrderCategoryBigInfo_s>)));

    connect(BarCodeScalesAgent::instance(), SIGNAL(sigOnCheckBcsState(QString, bool))
            ,this, SIGNAL(sigOnCheckBcsState(QString, bool)));
    connect(BarCodeScalesAgent::instance(), SIGNAL(sigOnCheckBcsStateFinish())
            ,this, SIGNAL(sigOnCheckBcsStateFinish()));

    connect(BarCodeScalesAgent::instance(), SIGNAL(sigOnSendDownBcsState(QString,bool))
            ,this, SIGNAL(sigOnSendDownBcsState(QString,bool)));
    connect(BarCodeScalesAgent::instance(), SIGNAL(sigOnSendDownBcsFinish()), this, SIGNAL(sigOnSendDownBcsFinish()));

    connect(BarCodeScalesAgent::instance(), SIGNAL(sigOnCreateGoodsGroup(int,QString,BCSGroupManageLeftInfo)),
            this, SIGNAL(sigOnCreateGoodsGroup(int,QString,BCSGroupManageLeftInfo)));

    qRegisterMetaType<QList<BCSGroupManageLeftInfo> >("QList<BCSGroupManageLeftInfo>");
    connect(BarCodeScalesAgent::instance(), SIGNAL(sigOnGetGoodsGroupList(int,QString,QList<BCSGroupManageLeftInfo>))
             , this, SLOT(slot_onGetGoodsGroupList(int,QString,QList<BCSGroupManageLeftInfo>)));
    connect(BarCodeScalesAgent::instance(), SIGNAL(sigOnGetBarcodeScaleCode(int,QString,QString)), this, SIGNAL(sigOnGetBarcodeScaleCode(int,QString,QString)));

    qRegisterMetaType<QList<BarCodeScaleInfo> >("QList<BarCodeScaleInfo>");
    connect(BarCodeScalesAgent::instance(), SIGNAL(sigOnGetBarcodeScaleList(int,QString,QList<BarCodeScaleInfo>))
             , this, SIGNAL(sigOnGetBarcodeScaleList(int,QString,QList<BarCodeScaleInfo>)));
    connect(BarCodeScalesAgent::instance(), SIGNAL(sigOnAddBarcodeScale(int,QString))
             , this, SIGNAL(sigOnAddBarcodeScale(int,QString)));
    connect(BarCodeScalesAgent::instance(), SIGNAL(sigOnDeleteScale(int, QString, QString))
             , this, SIGNAL(sigOnDeleteScale(int, QString, QString)));
}

void BarCodeScalesCtrl::convertToBcsGoodsInfo(BCSGoodsInfo &bcsGoodsInfo, const GoodsInfo_s &goodsInfo)
{
    bcsGoodsInfo.sKeyId = goodsInfo.sPluCode;
    bcsGoodsInfo.sName = goodsInfo.sName; // 商品名字
    bcsGoodsInfo.sCode = goodsInfo.sCode; // 商品编号
    bcsGoodsInfo.sUnit = goodsInfo.sSaleUnit; // 商品单位
    bcsGoodsInfo.sPlu = goodsInfo.sPluCode; // 商品PLU码
    bcsGoodsInfo.sPrice = QString::number(goodsInfo.goodsPriceInfo.fPrice, 'f', 2); // 商品价格
    bcsGoodsInfo.sMemberPrice = QString::number(goodsInfo.goodsPriceInfo.fMemberPrice, 'f', 2); // 商品会员价
}

