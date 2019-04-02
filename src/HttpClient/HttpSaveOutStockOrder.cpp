#include "HttpSaveOutStockOrder.h"

#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include <QScriptEngine>

HttpSaveOutStockOrder::HttpSaveOutStockOrder(QString sToken, QString sCorpID, QString sUUID, int nOrderId
                                             , const QList<OutStockSelectGoodsInfo> &selectGoodsList)
{
    QString systemParam;
    QString goodsListJson = createGoodsListJson(selectGoodsList);
    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3&product_lists=%4").arg(sToken).arg(sCorpID).arg(sUUID).arg(goodsListJson);
    if (nOrderId > 0)
    {
        userParam.append(QString("&order_id=%1").arg(nOrderId));
        systemParam = CommonFun::generateSystemParams(c_sEditOutStockOrderAction);
    }else
        systemParam = CommonFun::generateSystemParams(c_sAddOutStockOrderAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    KPosLog::instance()->writeErrorLog(allParam);
    QByteArray array="";
    array.append(allParam);
    setReqParams(array);
}

void HttpSaveOutStockOrder::processResponse(QString strResult)
{
    //    KPosLog::instance()->writeTestLog(this->getTestUrl());
    //    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpSaveOutStockOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnSaveOutStockOrder(nCode, sMsg);
    this->deleteLater();
}

void HttpSaveOutStockOrder::processError()
{
    HttpSignal::instance()->sigOnSaveOutStockOrder(e_connectServerError, c_sNetError);
    this->deleteLater();
}

QString HttpSaveOutStockOrder::createGoodsListJson(const QList<OutStockSelectGoodsInfo> &selectGoodsList)
{
    QJsonArray jsonArray;
    int nLen = selectGoodsList.length();
    OutStockSelectGoodsInfo goodsInfo;
    for (int i = 0; i < nLen; i++)
    {
        goodsInfo = selectGoodsList[i];
        QJsonObject dataJson;
        dataJson.insert("product_id", goodsInfo.nId); // 商品ID
        dataJson.insert("price", CommonFun::floatToString(goodsInfo.fBatchPrice)); // 单价
        dataJson.insert("quantity", CommonFun::floatToString(goodsInfo.fShouldCount));// 数量
        dataJson.insert("amount", CommonFun::floatToString(goodsInfo.fShouldTotal));// 金额
        dataJson.insert("package", CommonFun::floatToString(goodsInfo.fPackage));// 件数
        jsonArray.insert(i, dataJson);
    }

    QJsonDocument document;
    document.setArray(jsonArray);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QString byte_str=QString::fromUtf8(byte_array);

    return byte_str;
}



