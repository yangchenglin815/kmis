#include "HttpGetOPeratorList.h"
#include "CommonFun.h"
#include "KPosLog.h"
#include "KPosIni.h"
#include <QScriptEngine>
#include "HttpSignal.h"
#include "enumData.h"
#include <QScriptValueIterator>

HttpGetOPeratorList::HttpGetOPeratorList( QString sCorpCode, int nShopID )
{
    QString userParam = QString("&hq_code=%1&orgz_id=%2").arg(sCorpCode).arg( nShopID );
    QString systemParam = CommonFun::generateSystemParams( c_sHttpOPeratorList );
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);

//    KPosLog::instance()->writeDebugLog( allParam );
}

void HttpGetOPeratorList::processResponse(QString strResult)
{
    //    qDebug()<<strResult;
//    KPosLog::instance()->writeTestLog(strResult);
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpDownloadKPosSet 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<OperatorInfo_s> listOPerator;
    if (sc.property("data").isArray())
    {
        QScriptValueIterator it(sc.property("data"));
        OperatorInfo_s stOPeratorInfo;
        while (it.hasNext())
        {
            it.next();
            stOPeratorInfo.nId = it.value().property("cashier_id").toInt32();
            if ( stOPeratorInfo.nId == 0)
            {
                continue;
            }
            stOPeratorInfo.strName = it.value().property("cashier_name").toString();
            listOPerator.append( stOPeratorInfo );
        }
    }

    HttpSignal::instance()->sigOnOperatorList( nCode, sMsg, listOPerator );

    this->deleteLater();
}

void HttpGetOPeratorList::processError()
{
    QList<OperatorInfo_s> listOPerator;
    HttpSignal::instance()->sigOnOperatorList( e_connectServerError, QStringLiteral("网络异常"), listOPerator );
    this->deleteLater();
}
