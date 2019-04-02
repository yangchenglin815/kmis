#include "HttpDeleteCustomCategory.h"
#include "../util/CommonFun.h"
#include <QDebug>
#include <QScriptEngine>
#include <QScriptValue>
#include "KPosLog.h"
#include "HttpSignal.h"

HttpDeleteCustomCategory::HttpDeleteCustomCategory(QString sCorpID, QString sToken, int nShopID, QString sUUID, int nCategoryId)
{
    m_nCategoryId = nCategoryId;

    QString userParam = QString("&hq_code=%1&access_token=%2&orgz_id=%3&uuid=%4&category_id=%5")
            .arg(sCorpID).arg(sToken).arg(nShopID).arg(sUUID).arg(nCategoryId);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpDeleteCustomCategoryAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpDeleteCustomCategory::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpDeleteCustomCategory 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnDeleteCustomCategory(nCode, sMsg, m_nCategoryId);

    this->deleteLater();
}

void HttpDeleteCustomCategory::processError()
{
    HttpSignal::instance()->sigOnDeleteCustomCategory( e_connectServerError, c_sNetError, m_nCategoryId);
    this->deleteLater();
}
