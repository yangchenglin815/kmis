#include "HttpUpdateCustomCategory.h"
#include "../util/CommonFun.h"
#include <QDebug>

HttpUpdateCustomCategory::HttpUpdateCustomCategory(QString sCorpID, QString sToken, int nShopID, QString sUUID, int nCategoryId, QString sCategoryName)
{
    QString userParam = QString("&hq_code=%1&access_token=%2&orgz_id=%3&uuid=%4&category_id=%5&category_name=%6")
            .arg(sCorpID).arg(sToken).arg(nShopID).arg(sUUID).arg(nCategoryId).arg(sCategoryName);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpUpdateCustomCategoryAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpUpdateCustomCategory::processResponse(QString strResult)
{
    qDebug()<<strResult;
    this->deleteLater();
}

void HttpUpdateCustomCategory::processError()
{
    this->deleteLater();
}
