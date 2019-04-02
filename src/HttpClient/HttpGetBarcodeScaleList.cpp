#include "HttpGetBarcodeScaleList.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/GlobalSignal.h"
#include "../util/HttpSignal.h"
#include "barcodescaledata.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpGetBarcodeScaleList::HttpGetBarcodeScaleList(QString sCorpID, QString sToken, QString sUUID)
{
    QString userParam = QString("&hq_code=%1&access_token=%2&uuid=%3").arg(sCorpID).arg(sToken).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetBarcodeScaleListAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetBarcodeScaleList::processResponse(QString strResult)
{
//    KPosLog::instance()->writeErrorLog(this->getTestUrl());
//    KPosLog::instance()->writeErrorLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetInStockOrderList 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<BarCodeScaleInfo> scaleInfoList;
    if (sc.property("data").isArray())
    {
        BarCodeScaleInfo scaleInfo;
        QScriptValueIterator it1(sc.property("data"));
        while (it1.hasNext())
        {
            it1.next();

//            scaleInfo.nGroupId = it1.value().property("group_id").toInt32(); // 商品组Id
            scaleInfo.sKeyId= it1.value().property("id").toString(); // 主键id
            if (scaleInfo.sKeyId.isEmpty())
            {
                continue;
            }
            scaleInfo.sCode= it1.value().property("code").toString(); // 条码秤编号
            scaleInfo.sModel = it1.value().property("scale_type").toString(); // 条码秤型号
            scaleInfo.sIP = it1.value().property("IP").toString(); // 条码秤IP
            scaleInfo.sGoodsGroup = it1.value().property("group_id").toString(); // 关联商品组Id
            scaleInfo.sGoodsGroupName = it1.value().property("group_name").toString(); // 关联商品组名称
            scaleInfo.sSendDownTime = it1.value().property("last_broadcast_at").toString(); // 上次下发时间
            if(scaleInfo.sGoodsGroup.toInt() == c_nDefaultGoodsGroupId)
            {
                scaleInfo.sGoodsGroupName = QStringLiteral("默认商品组");
            }
            scaleInfoList.append(scaleInfo);
        }
    }
    HttpSignal::instance()->sigOnGetBarcodeScaleList(nCode, sMsg, scaleInfoList);

    this->deleteLater();

}

void HttpGetBarcodeScaleList::processError()
{
    QList<BarCodeScaleInfo> scaleInfoList;
    HttpSignal::instance()->sigOnGetBarcodeScaleList(e_connectServerError, c_sNetError, scaleInfoList);
    this->deleteLater();
}

