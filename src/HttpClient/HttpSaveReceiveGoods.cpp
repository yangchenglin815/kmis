#include "HttpSaveReceiveGoods.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"
#include <QScriptEngine>

HttpSaveReceiveGoods::HttpSaveReceiveGoods(QString sToken, const ReceiveGoodsDetail_s &receiveGoodsDetail, int nDeliverGoodId)
{
    QString userParam = QString("&access_token=%1&delivery_content_id=%2").arg(sToken).arg(nDeliverGoodId);
    if (receiveGoodsDetail.bStandardGoods)
    {
        QString str = QString("&receive_type=1&suttle_spec=%1&b_package=%2&b_quantity=%3&unit_price=%4")
                .arg(receiveGoodsDetail.standardInfo.fStandardWeight)
                .arg(receiveGoodsDetail.standardInfo.nReceiveNum)
                .arg(receiveGoodsDetail.standardInfo.fReciveSumValue)
                .arg(receiveGoodsDetail.standardInfo.fPrice);
        userParam.append(str);
    }
    else
    {
        if (receiveGoodsDetail.bDisperseWeight)
        {
            QString str = QString("&receive_type=2&b_quantity=%1&unit_price=%2")
                    .arg(receiveGoodsDetail.disperseInfo.fReciveSumValue)
                    .arg(receiveGoodsDetail.disperseInfo.fPrice);
            userParam.append(str);
        }
        else
        {
            QString str = QString("&receive_type=1&weight_ascertainable=%1&gross_weight=%2&unit_tare=%3&b_package=%4&unit_price=%5")
                    .arg(receiveGoodsDetail.bFixWeight?1:2)
                    .arg(receiveGoodsDetail.noStandardInfo.fAllWeidght)
                    .arg(receiveGoodsDetail.noStandardInfo.fPeelWeight)
                    .arg(receiveGoodsDetail.noStandardInfo.nReceiveNum)
                    .arg(receiveGoodsDetail.noStandardInfo.fPrice);
            userParam.append(str);
        }
    }

    QString systemParam = CommonFun::generateSystemParams(c_sHttpSaveReceiveGoodsAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpSaveReceiveGoods::processResponse(QString strResult)
{
    Q_UNUSED( strResult )
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);
    this->deleteLater();
}

void HttpSaveReceiveGoods::processError()
{
    this->deleteLater();
}

