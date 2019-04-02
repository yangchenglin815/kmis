#include "HttpSaveGoodsGroup.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"

HttpSaveGoodsGroup::HttpSaveGoodsGroup(QString sCorpID, QString sToken, QString sUUID, int nGroupId, QList<QString> pluList)
{
    QString sPluListJson = createPluListJson(pluList);
    QString userParam = QString("&hq_code=%1&access_token=%2&uuid=%3&group_id=%4&product_lists=%5")
            .arg(sCorpID).arg(sToken).arg(sUUID).arg(nGroupId).arg(sPluListJson);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpSaveGoodsGroupAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpSaveGoodsGroup::processResponse(QString strResult)
{
//    KPosLog::instance()->writeErrorLog(this->getTestUrl());
//    KPosLog::instance()->writeErrorLog(strResult);

    this->deleteLater();
}

void HttpSaveGoodsGroup::processError()
{

    this->deleteLater();
}

QString HttpSaveGoodsGroup::createPluListJson(const QList<QString> &pluList)
{
    QJsonArray jsonArray;
    int nLen = pluList.length();
    for (int i = 0; i < nLen; i++)
    {
        QJsonObject dataJson;
        dataJson.insert("plu_code", pluList[i]);
        jsonArray.insert(i, dataJson); //
    }

    QJsonDocument document;
    document.setArray(jsonArray);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}

