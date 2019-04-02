#include "HttpGetMemTypeList.h"
#include "KPosLog.h"
#include <QScriptEngine>
#include "KPosIni.h"
#include "HttpSignal.h"
#include "CommonFun.h"
#include "enumData.h"
#include <QScriptValueIterator>

HttpGetMemTypeList::HttpGetMemTypeList()
{
    QString userParam = QString("&hq_code=%1")\
            .arg(KPosIni::getCorpID());
    QString systemParam = CommonFun::generateSystemParams( c_sHttpMemTypeList );
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);

//    KPosLog::instance()->writeDebugLog( allParam );
}

void HttpGetMemTypeList::processResponse( QString strResult )
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();//状态值
    QString sMsg = sc.property("msg").toString();//返回消息
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetMemTypeList 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<MemTypeInfo_s> listMemType;
    if (sc.property("data").isArray())
    {
        QScriptValueIterator it(sc.property("data"));
        MemTypeInfo_s stMemTypeInfo;
        while (it.hasNext())
        {
            it.next();
            stMemTypeInfo.nId = it.value().property("id").toInt32();
            if (stMemTypeInfo.nId == 0)
            {
                continue;
            }
            stMemTypeInfo.strTypeName = it.value().property("type_name").toString();
            listMemType.append( stMemTypeInfo );
        }
    }

    HttpSignal::instance()->sigOnMemTypeList( nCode, sMsg, listMemType );
    this->deleteLater();
}

void HttpGetMemTypeList::processError()
{
    QList<MemTypeInfo_s> listMemType;
    HttpSignal::instance()->sigOnMemTypeList( -1, "", listMemType );

    this->deleteLater();
}
