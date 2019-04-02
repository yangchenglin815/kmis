#include "HttpAddCustomCategory.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include <QDebug>
#include <QScriptEngine>
#include <QScriptValue>
#include "HttpSignal.h"

HttpAddCustomCategory::HttpAddCustomCategory(QString sCorpID, QString sToken, int nShopID, QString sUUID, QString sCategoryName, int nPos)
{
    QString userParam = QString("&hq_code=%1&access_token=%2&orgz_id=%3&uuid=%4&category_name=%5&rank=%6")
            .arg(sCorpID).arg(sToken).arg(nShopID).arg(sUUID).arg(sCategoryName).arg( nPos );
    QString systemParam = CommonFun::generateSystemParams(c_sHttpAddCustomCategoryAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpAddCustomCategory::processResponse(QString strResult)
{
//    KPosLog::instance()->writeErrorLog(this->getTestUrl());
//    KPosLog::instance()->writeErrorLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();//状态值
    QString sMsg = sc.property("msg").toString();//返回消息
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpAddCustomCategory 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    int nCategoryId = sc.property("data").property("categories_id").toInt32();
    HttpSignal::instance()->sigOnAddCustomCategory(nCode, sMsg, nCategoryId);

    this->deleteLater();
}

void HttpAddCustomCategory::processError()
{
    HttpSignal::instance()->sigOnAddCustomCategory(e_connectServerError, c_sNetError, -1);
    this->deleteLater();
}
