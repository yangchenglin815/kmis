#include "HttpUpdateMemberIntegral.h"
#include "CommonFun.h"
#include "KPosLog.h"
#include "HttpSignal.h"
#include <QScriptEngine>

HttpUpdateMemberIntegral::HttpUpdateMemberIntegral(QString sCorpID, QString sToken, QString sUUID, float fMoney, QString sCardNum, QString sOrderNum, QString sRefundOrderNum)
{
    m_sOrderNum = sOrderNum;
    if (!sRefundOrderNum.isEmpty())
    {
        m_sOrderNum = sRefundOrderNum;
    }
    QString userParam = QString("&hq_code=%1&access_token=%2&uuid=%3&pay_amount=%4&card_no=%5&sales_num=%6")
            .arg(sCorpID).arg(sToken).arg(sUUID).arg(fMoney).arg(sCardNum).arg(sOrderNum);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpUpdateMemberIntegralAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpUpdateMemberIntegral::processResponse(QString strResult)
{
    KPosLog::instance()->writeErrorLog(this->getTestUrl());
    KPosLog::instance()->writeErrorLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();//状态值
    QString sMsg = sc.property("msg").toString();//返回消息
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpUpdateMemberIntegral 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

//    "present_point": 29,
//    "integral": 29,
//    "account_balance": 1200

    int nGiftIntegral = sc.property("data").property("present_point").toInt32();
    HttpSignal::instance()->sigOnUpdateMemberIntegral(nCode, sMsg, nGiftIntegral, m_sOrderNum);


    this->deleteLater();
}

void HttpUpdateMemberIntegral::processError()
{

    this->deleteLater();
}

