#include "HttpReceiveGoodsEnd.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"

HttpReceiveGoodsEnd::HttpReceiveGoodsEnd(QString sToken, int nDeliveryId)
{
    QString userParam = QString("&access_token=%1&delivery_order_id=%2").arg(sToken).arg(nDeliveryId);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpReceiveGoodsEndAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpReceiveGoodsEnd::processResponse(QString strResult)
{
    Q_UNUSED( strResult )
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    this->deleteLater();
}

void HttpReceiveGoodsEnd::processError()
{

    this->deleteLater();
}

