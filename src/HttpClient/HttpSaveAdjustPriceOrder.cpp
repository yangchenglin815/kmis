#include "HttpSaveAdjustPriceOrder.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include <QScriptEngine>

HttpSaveAdjustPriceOrder::HttpSaveAdjustPriceOrder(QString sToken, QString sCorpID, QString sUUID, int nOrderId, const QList<AdjustPriceSelectGoodsInfo> &selectGoodsList)
{
    QString goodsListJson = createGoodsListJson(selectGoodsList);
    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3&product_lists=%4").arg(sToken).arg(sCorpID).arg(sUUID).arg(goodsListJson);
    if (nOrderId > 0)
    {
        userParam.append(QString("&order_id=%1").arg(nOrderId));
    }
    QString systemParam = CommonFun::generateSystemParams(c_sSaveAdjustPriceOrderAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpSaveAdjustPriceOrder::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpSaveAdjustPriceOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnSaveAdjustPriceOrder(nCode, sMsg);

    this->deleteLater();
}

void HttpSaveAdjustPriceOrder::processError()
{
    HttpSignal::instance()->sigOnSaveAdjustPriceOrder(e_connectServerError, c_sNetError);
    this->deleteLater();
}

QString HttpSaveAdjustPriceOrder::createGoodsListJson(const QList<AdjustPriceSelectGoodsInfo> &selectGoodsList)
{
    QJsonArray jsonArray;
    int nLen = selectGoodsList.length();
    AdjustPriceSelectGoodsInfo goodsInfo;
    for (int i = 0; i < nLen; i++)
    {
        goodsInfo = selectGoodsList[i];
        QJsonObject dataJson;
        dataJson.insert("product_id", goodsInfo.nId); // 商品ID
        dataJson.insert("current_price", goodsInfo.fNowPrice); // 现售价
        dataJson.insert("current_member_price", goodsInfo.fNowMemberPrice);// 现会员价
        dataJson.insert("old_sale_price", goodsInfo.fOldPrice); // 原售价
        dataJson.insert("old_member_price", goodsInfo.fOldMemberPrice); // 原会员价
        dataJson.insert("sale_unit", goodsInfo.sWeighUnit); // 销售单位
        jsonArray.insert(i, dataJson);
    }

    QJsonDocument document;
    document.setArray(jsonArray);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}

