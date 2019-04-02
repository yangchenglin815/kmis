#include "HttpGetShopInfo.h"
#include "../data/constData.h"
#include "../data/httpstructdata.h"
#include "../data/enumData.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"
//#include <QDebug> // 测试用
#include <QScriptEngine>

HttpGetShopInfo::HttpGetShopInfo(QString sUUID, QString sCorpCode, QString sShopCode)
{
    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetShopInfoAction);
    QString userParam = QString("&hq_code=%1&orgz_code=%2&uuid=%3").arg(sCorpCode).arg(sShopCode).arg(sUUID);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetShopInfo::processResponse(QString strResult)
{
//    qDebug()<< strResult;
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetShopInfo 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }
    ShopInfo shopInfo;
    shopInfo.sCorpName = sc.property("data").property("hq_name").toString();
    shopInfo.sShopName = sc.property("data").property("orgz_name").toString();
    HttpSignal::instance()->sigOnGetShopInfo(nCode, sMsg, shopInfo);
    this->deleteLater();
}

void HttpGetShopInfo::processError()
{
    ShopInfo shopInfo;
    shopInfo.sCorpName = "";
    shopInfo.sShopName = "";
    HttpSignal::instance()->sigOnGetShopInfo(e_connectServerError, c_sNetError, shopInfo);
    this->deleteLater();
}
