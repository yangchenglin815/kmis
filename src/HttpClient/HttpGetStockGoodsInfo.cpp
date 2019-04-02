#include "HttpGetStockGoodsInfo.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/enumData.h"
#include "../data/constData.h"
#include <QScriptEngine>


HttpGetStockGoodsInfo::HttpGetStockGoodsInfo(QString sToken, QString sCorpID, QString sUUID, int nGoodsId)
{
    QString userParam = QString("&access_token=%1&hq_code=%2&product_id=%3&uuid=%4")
            .arg(sToken).arg(sCorpID).arg(nGoodsId).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sGetStockGoodsInfoAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetStockGoodsInfo::processResponse(QString strResult)
{
    //    KPosLog::instance()->writeTestLog(this->getTestUrl());
    //    KPosLog::instance()->writeTestLog(strResult);
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetStockOrderList 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    qRegisterMetaType<GoodsStockInfo>("GoodsStockInfo");
    GoodsStockInfo goodsStockInfo;
    goodsStockInfo.fShouldStockNum = sc.property("data").property("book_inventory_num").toString().toFloat();
    goodsStockInfo.fBuyPrice = sc.property("data").property("batch_price").toString().toFloat();
    goodsStockInfo.nBatchId = sc.property("data").property("batch_id").toInt32();
    goodsStockInfo.fMarkNum = sc.property("data").property("spec_num").toString().toFloat();

    markNum=QString::number(goodsStockInfo.fMarkNum, 'f', 2);
    qDebug()<<"48规格单位:"+markNum;
    float fBuyPrice = goodsStockInfo.fBuyPrice;
    HttpSignal::instance()->sigOnGetStockGoodsInfo(nCode, sMsg, goodsStockInfo);
    HttpSignal::instance()->sigOnGetOutStockGoodsInfo(markNum, fBuyPrice);
    this->deleteLater();
}

void HttpGetStockGoodsInfo::processError()
{
    GoodsStockInfo goodsStockInfo;
    HttpSignal::instance()->sigOnGetStockGoodsInfo(e_connectServerError, c_sNetError, goodsStockInfo);
    this->deleteLater();
}

