#include "HttpGetOrderCardListDetail.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/ordergoodsdata.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpGetOrderCardListDetail::HttpGetOrderCardListDetail(QString sToken, QString sCorpID, QString sUUID, const QList<int> &orderCardIdList, bool bUploadFinish)
{
    m_orderCardIdList = orderCardIdList;
    m_bUploadFinish = bUploadFinish;

    QString sOrderIdListJson = createOrderIdListJson(orderCardIdList);

    QString userParam = QString("&access_token=%1&hq_code=%2&req_order_lists=%3&uuid=%4").arg(sToken).arg(sCorpID).arg(sOrderIdListJson).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetOrderCardListDetailAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetOrderCardListDetail::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetOrderCardListDetail 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<OrderCardDetailInfo_s> orderCardDetailInfoList;
    OrderCardDetailInfo_s orderCardDetailInfo;
    if (sc.property("data").isArray())
    {
        QScriptValueIterator it(sc.property("data"));
        while (it.hasNext())
        {
            it.next();
            orderCardDetailInfo.nId = it.value().property("product_id").toInt32(); // 商品ID
            if (orderCardDetailInfo.nId == 0)
            {
                continue;
            }
            orderCardDetailInfo.sCode = it.value().property("product_code").toString(); // 商品编码
            orderCardDetailInfo.sName = it.value().property("product_name").toString(); // 商品名称
            orderCardDetailInfo.sShortName = it.value().property("aka").toString(); // 商品简称
            orderCardDetailInfo.sUnitSpecification = it.value().property("spe_unit").toString(); // 规格单位
            orderCardDetailInfo.fUnitSpecificationValue = it.value().property("purchase_spec").toString().toFloat(); // 规格单位量
            orderCardDetailInfo.fPrice = it.value().property("unit_price").toString().toFloat(); // 单件单价
            orderCardDetailInfo.nOrderGoodsNumber = it.value().property("req_package").toInt32(); // 要货量
            orderCardDetailInfoList.append(orderCardDetailInfo);
        }
    }

    HttpSignal::instance()->sigOnGetOrderCardListDetail(nCode, sMsg, orderCardDetailInfoList, m_bUploadFinish, m_orderCardIdList);
    this->deleteLater();
}

void HttpGetOrderCardListDetail::processError()
{
    QList<OrderCardDetailInfo_s> orderCardDetailInfoList;
    HttpSignal::instance()->sigOnGetOrderCardListDetail(e_connectServerError, c_sNetError, orderCardDetailInfoList, m_bUploadFinish, m_orderCardIdList);
    this->deleteLater();
}

QString HttpGetOrderCardListDetail::createOrderIdListJson(const QList<int> &orderCardIdList)
{
    QJsonArray jsonArray;
    int nLen = orderCardIdList.length();
    for (int i = 0; i < nLen; i++)
    {
        QJsonObject dataJson;
        dataJson.insert("req_order_id", orderCardIdList[i]);
        jsonArray.insert(i, dataJson); //
    }

    QJsonDocument document;
    document.setArray(jsonArray);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}

