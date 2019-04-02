#include "HttpGetQuickGoodsInfo.h"
#include "CommonFun.h"
#include "KPosLog.h"
#include "enumData.h"
#include "HttpSignal.h"
#include <QScriptEngine>

HttpGetQuickGoodsInfo::HttpGetQuickGoodsInfo(QString sToken, QString sCorpID, QString sUUID, QString sBigCategoryCode)
{
    m_sBigCategoryCode = sBigCategoryCode;

    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3&cid_code=%4").arg(sToken).arg(sCorpID).arg(sUUID).arg(sBigCategoryCode);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetQuickGoodsInfoAction);;
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array="";
    array.append(allParam);
    setReqParams(array);
}

void HttpGetQuickGoodsInfo::processResponse(QString strResult)
{
    KPosLog::instance()->writeErrorLog(this->getTestUrl());
    KPosLog::instance()->writeErrorLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetQuickGoodsInfo 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QString sPlu,sCode,sUnit;
    sPlu = sc.property("data").property("plu_code").toString(); // Plu码
    sCode=sc.property("data").property("product_code").toString(); // 商品编号
    sUnit=sc.property("data").property("unit_info").toString();

    HttpSignal::instance()->sigOnGetQuickGoodsInfo(nCode, sMsg,sPlu,sCode,sUnit,m_sBigCategoryCode);
    this->deleteLater();
}

void HttpGetQuickGoodsInfo::processError()
{
    HttpSignal::instance()->sigOnGetQuickGoodsInfo(e_connectServerError, c_sNetError, "", "", "", "");
    this->deleteLater();
}

