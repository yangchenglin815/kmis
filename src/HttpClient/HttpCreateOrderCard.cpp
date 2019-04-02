#include "HttpCreateOrderCard.h"
#include "../util/KPosLog.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../data/enumData.h"
#include <QScriptEngine>

HttpCreateOrderCard::HttpCreateOrderCard(QString sToken, int nShopID, QString sCorpID, const QList<OrderGoodsInfo *> &orderGoodsInfoList, QString sUUID)
{
    QString orderGoodsInfoListJson = createOrderGoodsListJson(orderGoodsInfoList);
    QString userParam = QString("&access_token=%1&orgz_id=%2&hq_code=%3&product_lists=%4&uuid=%5")
            .arg(sToken).arg(nShopID).arg(sCorpID).arg(orderGoodsInfoListJson).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpCreateOrderCardAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpCreateOrderCard::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpCreateOrderCard 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnCreateOrderCard(nCode, sMsg);

    this->deleteLater();
}

void HttpCreateOrderCard::processError()
{
    HttpSignal::instance()->sigOnCreateOrderCard(e_connectServerError, c_sNetError);
    this->deleteLater();
}

QString HttpCreateOrderCard::createOrderGoodsListJson(const QList<OrderGoodsInfo *> &orderGoodsInfoList)
{
    QJsonArray jsonArray;
    int nLen = orderGoodsInfoList.length();
    OrderGoodsInfo* pOrderGoodsInfo = NULL;
    for (int i = 0; i < nLen; i++)
    {
        pOrderGoodsInfo = orderGoodsInfoList[i];
        QJsonObject dataJson;
        dataJson.insert("product_id", pOrderGoodsInfo->nId);
        dataJson.insert("product_package", pOrderGoodsInfo->nOrderGoodsNumber);
        jsonArray.insert(i, dataJson); //
    }

    QJsonDocument document;
    document.setArray(jsonArray);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}

