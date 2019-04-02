#include "HttpGetMemGradeList.h"
#include "CommonFun.h"
#include <QScriptEngine>
#include "KPosIni.h"
#include "KPosLog.h"
#include "HttpSignal.h"
#include "enumData.h"
#include <QScriptValueIterator>

HttpGetMemGradeList::HttpGetMemGradeList( int nMemTypeId )
{
    QString userParam = QString("&hq_code=%1&type_id=%2")\
            .arg(KPosIni::getCorpID()).arg( nMemTypeId );
    QString systemParam = CommonFun::generateSystemParams( c_sHttpMemGradeList );
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);

//    KPosLog::instance()->writeDebugLog( allParam );
}

void HttpGetMemGradeList::processResponse( QString strResult )
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();//状态值
    QString sMsg = sc.property("msg").toString();//返回消息
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetMemGradeList 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<MemGradeInfo_s> listMemGrade;
    if (sc.property("data").isArray())
    {
        QScriptValueIterator it(sc.property("data"));
        MemGradeInfo_s stMemGradeInfo;
        while (it.hasNext())
        {
            it.next();
            stMemGradeInfo.nId = it.value().property("id").toInt32();
            if (stMemGradeInfo.nId == 0)
            {
                continue;
            }
            stMemGradeInfo.nTypeId = it.value().property("type_id").toInt32();
            stMemGradeInfo.strLevelName = it.value().property("level_name").toString();
            listMemGrade.append( stMemGradeInfo );
        }
    }

    HttpSignal::instance()->sigOnMemGradeList( nCode, sMsg, listMemGrade );
    this->deleteLater();
}

void HttpGetMemGradeList::processError()
{
    QList<MemGradeInfo_s> listMemGrade;
    HttpSignal::instance()->sigOnMemGradeList( -1, "", listMemGrade );

    this->deleteLater();
}
