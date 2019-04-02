#include "HttpUploadKPosSet.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/enumData.h"
#include <QScriptEngine>

HttpUploadKPosSet::HttpUploadKPosSet(QString sCorpID, QString sToken, QString sUUID, const KPosSet &kPosSet, bool bSync)
{    
    QString sKPosSetJson = createKPosSetJson(kPosSet);
    QString userParam = QString("&hq_code=%1&access_token=%2&uuid=%3&settings=%4")
            .arg(sCorpID).arg(sToken).arg(sUUID).arg(sKPosSetJson);
    if (bSync)
    {
        userParam.append("&is_sync=1");
    }

    QString systemParam = CommonFun::generateSystemParams(c_sHttpUploadKposSetAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpUploadKPosSet::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    QString sUpdateTime = sc.property("data").property("upload_date").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpUploadKPosSet 返回参数json格式错误"));
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }
    HttpSignal::instance()->sigOnUploadKPosSet(nCode, sMsg, sUpdateTime);

    this->deleteLater();
}

void HttpUploadKPosSet::processError()
{
    this->deleteLater();
}

QJsonObject HttpUploadKPosSet::createPosInfoSetObjectJson(const PosInfoSet &posInfoSet)
{
    Q_UNUSED( posInfoSet )

    QJsonObject dataJson;
//    dataJson.insert("AppVersion", posInfoSet.sAppVersion); // 程序版本
//    dataJson.insert("ShopCode", posInfoSet.sShopCode); // 门店编号
//    dataJson.insert("ShopName", posInfoSet.sShopName); // 门店名称
//    dataJson.insert("Code", posInfoSet.sCode); // pos机编号
//    dataJson.insert("Name", posInfoSet.sName); // pos机名称
//    dataJson.insert("SkinType", posInfoSet.nSkinType); // 皮肤类型
//    dataJson.insert("isChanged", posInfoSet.bChanged ? 1 : 0); // 是否有更改
//    dataJson.insert("PosType", posInfoSet.sPosModel); // pos机名称
    dataJson.insert("set_time", CommonFun::getCurDateTime());

    return dataJson;
}

QJsonObject HttpUploadKPosSet::createKeySetInfoObjectJson(const KeySetInfo &keySetInfo)
{
    QJsonObject dataJson;
    dataJson.insert("KeyId", keySetInfo.nKeyId); // 按键名字
    dataJson.insert("IsUsed", keySetInfo.bStartUsed); // 是否启用
    return dataJson;
}

QJsonObject HttpUploadKPosSet::createKeySetObjectJson(const KeySet& keySet)
{
    QJsonArray homeKeysJsonArray;
    int nHomeKeyListLength = keySet.homeKeyList.length();
    for (int i = 0; i < nHomeKeyListLength; i++)
    {
        homeKeysJsonArray.insert(i, createKeySetInfoObjectJson(keySet.homeKeyList[i])); //
    }

    QJsonArray refundKeysJsonArray;
    int refundKeyListLength = keySet.refundKeyList.length();
    for (int i = 0; i < refundKeyListLength; i++)
    {
        refundKeysJsonArray.insert(i, createKeySetInfoObjectJson(keySet.refundKeyList[i]));
    }

    QJsonObject dataJson;
    dataJson.insert("HomeKeys", homeKeysJsonArray); // 首页按键列表
    dataJson.insert("RefundKeys", refundKeysJsonArray); // 退款按键列表
    dataJson.insert("set_time", CommonFun::getCurDateTime());
//    dataJson.insert("isChanged", keySet.bChanged ? 1 : 0); // 是否有更改

    return dataJson;
}

QJsonObject HttpUploadKPosSet::createCategoryInfoSetObjectJson(const CategoryInfoSet& categoryInfoSet)
{
    int nGoodsIdListLength = categoryInfoSet.goodsIdList.length();
    QString goodsIds;
    for (int i = 0; i < nGoodsIdListLength; i++)
    {
        goodsIds.append(QString::number(categoryInfoSet.goodsIdList[i])).append(",");
    }

    QJsonObject dataJson;
    dataJson.insert("CategoryId", categoryInfoSet.nCategoryId); // 分类id
    dataJson.insert("CategoryName", categoryInfoSet.sCategoryName); // 分类名
    dataJson.insert("GoodsIds", goodsIds); // 所包含的商品id列表（id之间用逗号隔开）
    dataJson.insert("IsCustom", categoryInfoSet.bCustom ? 1 : 0); // 是否自定义

    return dataJson;
}

QJsonObject HttpUploadKPosSet::createGoodSetObjectJson(const GoodSet& goodSet)
{
    QJsonArray jsonArray;
    int nLen = goodSet.categorySetList.length();
    for (int i = 0; i < nLen; i++)
    {
        jsonArray.insert(i, createCategoryInfoSetObjectJson(goodSet.categorySetList[i])); //
    }

    QJsonObject dataJson;
    dataJson.insert("CategorySetList", jsonArray);
    //dataJson.insert("isChanged", goodSet.bChanged ? 1 : 0); // 是否有更改
    dataJson.insert("set_time", CommonFun::getCurDateTime());
    return dataJson;
}

QJsonObject HttpUploadKPosSet::createMovieADObjectJson(const MovieAD &movieAD)
{
    QJsonObject dataJson;
    dataJson.insert("Id", movieAD.nId); // 广告路径
    dataJson.insert("Status", movieAD.nStatus); // 是否播放(是否删除)
    return dataJson;
}

QJsonObject HttpUploadKPosSet::createScreenSetObjectJson(const ScreenSet &screenSet)
{
    QJsonObject dataJson;
//    dataJson.insert("PrinterModel", screenSet.sPrinterModel); // 打印机型号
//    dataJson.insert("IsAllowPrint", screenSet.bAllowPrint ? 1 : 0); // 是否允许打印
//    dataJson.insert("ClientScreenType", screenSet.nClientScreenType); // 客显类型
//    dataJson.insert("ClientScreenModel", screenSet.sClientScreenModel); // 客显型号
//    dataJson.insert("ClientScreenPort", screenSet.sClientScreenPort); // 客显端口
//    dataJson.insert("CardReaderModel", screenSet.sCardReaderModel); // 读卡器型号
//    dataJson.insert("CardReaderPort", screenSet.sCardReaderPort); // 读卡器端口
//    dataJson.insert("EBalanceModel", screenSet.sEBalanceModel); // 电子秤型号
//    dataJson.insert("EBalancePort", screenSet.sEBalancePort); // 电子秤端口

//    QJsonArray remoteADjsonArray;
//    int nRemoteLength = screenSet.remoteADList.length();
//    for (int i = 0; i < nRemoteLength; i++)
//    {
//        remoteADjsonArray.insert(i, createMovieADObjectJson(screenSet.remoteADList[i])); // 远程广告列表
//    }
//    dataJson.insert("RemoteADList", remoteADjsonArray);

//    QJsonArray localADjsonArray;
//    int nLocalLength = screenSet.localADList.length();
//    for (int i = 0; i < nLocalLength; i++)
//    {
//        localADjsonArray.insert(i, createMovieADObjectJson(screenSet.localADList[i])); // 本地广告列表
//    }
//    dataJson.insert("LocalADList", localADjsonArray);
    return dataJson;
}

QJsonObject HttpUploadKPosSet::createPayWayInfoSetObjectJson(const PayWayInfoSet &payWayInfoSet)
{
    QJsonObject dataJson;
    dataJson.insert("PayType", payWayInfoSet.nPayType); // 支付类型
    dataJson.insert("IsUsed", payWayInfoSet.bStartUse ? 1 : 0); // 是否启动
    dataJson.insert("IsChargeMember", payWayInfoSet.bChargeMember ? 1 : 0); // 是否用于会员充值
    dataJson.insert("IsVirtual", payWayInfoSet.bVirtualPay ? 1 : 0); // 是否用于会员充值
    dataJson.insert("DropType", payWayInfoSet.nDropType); //　分的圆整方式
    return dataJson;
}

QJsonObject HttpUploadKPosSet::createPayWaySetObjectJson(const PayWaySet &payWaySet)
{
    QJsonArray payWayInfoSetJsonArray;
    int nLen = payWaySet.payWayInfoSetList.length();
    for (int i = 0; i < nLen; i++)
    {
        payWayInfoSetJsonArray.insert(i, createPayWayInfoSetObjectJson(payWaySet.payWayInfoSetList[i]));
    }
    QJsonObject dataJson;
    dataJson.insert("PayWayInfoSetList", payWayInfoSetJsonArray);
    dataJson.insert("set_time", CommonFun::getCurDateTime());
    return dataJson;
}

QJsonObject HttpUploadKPosSet::createSystemSetParamsObjectJson(const SystemSetParams &systemSetParams)
{
    QJsonObject dataJson;
    dataJson.insert("1", systemSetParams.nDataSaveDays);
    dataJson.insert("2", systemSetParams.nGoodsMaxNumber);
    dataJson.insert("3", systemSetParams.bDiscountOnMember ? 1 : 0);
    dataJson.insert("4", systemSetParams.bDiscountOnDiscount ? 1 : 0);
    dataJson.insert("5", systemSetParams.bDiscardZero ? 1 : 0);
    dataJson.insert("6", systemSetParams.bFillReasonForRefund ? 1 : 0);
    dataJson.insert("7", systemSetParams.bPriceSale ? 1 : 0);
    dataJson.insert("8", systemSetParams.nPriceSaleLimit);
    return dataJson;
}

QJsonObject HttpUploadKPosSet::createShopSetParamsObjectJson(const ShopSetParams &shopSetParams)
{
    QJsonObject dataJson;
    dataJson.insert("1", shopSetParams.bChangePriceBySeller ? "1" : "0");// 收银员是否有打折改价权限
    dataJson.insert("2", shopSetParams.bCreateGoodsBySeller ? "1" : "0");// 是否允许收银员快速建档
    dataJson.insert("3", shopSetParams.bOpenCashboxBySeller ? "1" : "0");// 只有店长才能打开钱箱
    dataJson.insert("4", shopSetParams.bSellZeroGoodsBySeller ? "1" : "0");// 前台是否允许销售售价为零的商品
    dataJson.insert("5", shopSetParams.bHandinCashBySeller ? "1" : "0");// 收银员是否交款
    dataJson.insert("6", shopSetParams.bChooseSeller ? "1" : "0");// 结算是否选择业务员
    dataJson.insert("7", shopSetParams.nPendingListMaxLength); // 最大挂单数
    dataJson.insert("8", shopSetParams.nLockWaitTimeLenth); // 锁屏等待时间
    dataJson.insert("9", shopSetParams.sReceiptShopName);  // 小票门店名称
//    dataJson.insert("10", shopSetParams.bSaleByPrice ? "1" : "0"); // 是否输入价格销售
//    dataJson.insert("11", shopSetParams.sPriceRange); // 价格范围
    return dataJson;
}

QJsonObject HttpUploadKPosSet::createParamsSetObjectJson(const ParamsSet &paramsSet)
{
    QJsonObject dataJson;
//    dataJson.insert("SystemSetParams", createSystemSetParamsObjectJson(paramsSet.systemSetParams)); // 系统参数
    dataJson.insert("ShopSetParams", createShopSetParamsObjectJson(paramsSet.shopSetParams)); // 门店
//    dataJson.insert("isChanged", paramsSet.bChanged ? 1 : 0);
    dataJson.insert("set_time", CommonFun::getCurDateTime());
    return dataJson;
}

QString HttpUploadKPosSet::createKPosSetJson(const KPosSet& kPosSet)
{
    QJsonObject dataJson;
//    if (kPosSet.posInfoSet.bChanged)
//    {
//        dataJson.insert("PosInfoSet", createPosInfoSetObjectJson(kPosSet.posInfoSet));
//    }
    if (kPosSet.keySet.bChanged)
    {
        dataJson.insert("KeySet", createKeySetObjectJson(kPosSet.keySet));
    }
    if (kPosSet.goodSet.bChanged && (kPosSet.goodSet.categorySetList.size()>0))
    {
        dataJson.insert("GoodSet", createGoodSetObjectJson(kPosSet.goodSet));
    }
//    if (kPosSet.screenSet.bChanged)
//    {
//        dataJson.insert("ScreenSet", createScreenSetObjectJson(kPosSet.screenSet));
//    }
    if (kPosSet.payWaySet.bChanged)
    {
        dataJson.insert("PayWaySet", createPayWaySetObjectJson(kPosSet.payWaySet));
    }
    if (kPosSet.paramsSet.bChanged)
    {
        dataJson.insert("ParamsSet", createParamsSetObjectJson(kPosSet.paramsSet));
    }

    QJsonDocument document;
    document.setObject(dataJson);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}
