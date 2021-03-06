#include "HttpEditReportLoss.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include <QScriptEngine>

HttpEditReportLoss::HttpEditReportLoss(QString sToken, QString sCorpID, QString sUuid, QList<AddReportLossSelectInfo> infoList, int selectId)
{
    QJsonArray jsonArray;
    int nLen = infoList.length();
    AddReportLossSelectInfo pGoodsInfo;
    for (int i = 0; i < nLen; i++)
    {
        pGoodsInfo = infoList[i];
        QJsonObject dataJson;
        dataJson.insert("content_id", pGoodsInfo.goodsId);
        dataJson.insert("product_id", pGoodsInfo.id);
        dataJson.insert("quantity", pGoodsInfo.sNumber);
        dataJson.insert("total_amount", pGoodsInfo.sMoney);
        dataJson.insert("remark", pGoodsInfo.sReason);
        jsonArray.insert(i, dataJson); //
    }
    QJsonDocument document;
    document.setArray(jsonArray);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QString byte_str = QString::fromUtf8(byte_array);

    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3&order_id=%4&product_lists=%5").arg(sToken).arg(sCorpID).arg(sUuid).arg(selectId).arg(byte_str);
    QString systemParam = CommonFun::generateSystemParams(c_sEditReportLossOrderListAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpEditReportLoss::processResponse(QString strResult)
{
    qDebug()<<"EditReportLoss:"<<strResult;
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpEditReportLossOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }
    HttpSignal::instance()->sigEditReportLossOrderList(nCode, sMsg);
    this->deleteLater();
}

void HttpEditReportLoss::processError()
{
    HttpSignal::instance()->sigEditReportLossOrderList(e_connectServerError, c_sNetError);
    this->deleteLater();
}
