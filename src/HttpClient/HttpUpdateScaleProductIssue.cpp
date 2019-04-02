#include "HttpUpdateScaleProductIssue.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include <QScriptEngine>
#include <QDatetime>

HttpUpdateScaleProductIssue::HttpUpdateScaleProductIssue(QString sCorpID, QString sToken, QString sUUID, QList<QString> scaleList)
{
    QString sScaleListJson = createScaleListJson(scaleList);
    QString issueTime= CommonFun::getCurDateTime();
    QString userParam = QString("&hq_code=%1&access_token=%2&uuid=%3&issue_time=%4&scale_list=%5")
            .arg(sCorpID).arg(sToken).arg(sUUID).arg(issueTime).arg(sScaleListJson);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpUpdateScaleProductIssueAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}



void HttpUpdateScaleProductIssue::processResponse(QString strResult)
{
//    KPosLog::instance()->writeErrorLog(this->getTestUrl());
//    KPosLog::instance()->writeErrorLog(strResult);

    this->deleteLater();
}

void HttpUpdateScaleProductIssue::processError()
{
//    HttpSignal::instance()->sigOnDeleteScale(e_connectServerError, c_sNetError, m_nScaleId);
    this->deleteLater();
}

QString HttpUpdateScaleProductIssue::createScaleListJson(const QList<QString> &scaleList)
{

    QJsonArray jsonArray;
    int nLen = scaleList.length();
    for (int i = 0; i < nLen; i++)
    {
        QJsonObject dataJson;
        dataJson.insert("scale_id", scaleList[i]);
        jsonArray.insert(i, dataJson); //
    }

    QJsonDocument document;
    document.setArray(jsonArray);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}
