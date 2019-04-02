#include "HttpCreatePayMemberCard.h"
#include "CommonFun.h"
#include "KPosLog.h"
#include "HttpSignal.h"
#include <QScriptEngine>

HttpCreatePayMemberCard::HttpCreatePayMemberCard(QString sToken, QString sCorpID, QString sUUID, QString strBarCode,
                                                 QString strPayAmt, QString strSale, int nInteg,
                                                 QString strPayPwd, QString strIntToAmt)
{
    QString userParam = "";
    userParam = QString("&hq_code=%1&receipts=%2&auth_code=%3&pay_mode=%4&sum=%5&integral=%6&int_to_amt=%7&access_token=%8&uuid=%9&source=1")
            .arg(sCorpID).arg(strSale).arg(strBarCode).arg(e_PayMemCard).arg(strPayAmt)
            .arg(nInteg).arg(strIntToAmt).arg(sToken).arg(sUUID);

    if( !strPayPwd.isEmpty() )
    {
        QString strPwd = CommonFun::getStringMd5(strPayPwd);
        userParam += QString("&pay_password=%1").arg(strPwd);
    }
    else
    {
        userParam += QString( "&pay_password=%1").arg(strPayPwd);
    }

    QString systemParam = CommonFun::generateSystemParams( c_sHttpCreatePaymentAction );
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpCreatePayMemberCard::processResponse(QString strResult)
{
    KPosLog::instance()->writeErrorLog(this->getTestUrl());
    KPosLog::instance()->writeErrorLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();//状态值
    QString sMsg = sc.property("msg").toString();//返回消息
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpCreatPay 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog( "HttpCreatPay::processResponse" + strResult);
    }
    QString sBanlanceOrderNum = sc.property("data").property("banlance_pay").toString();
    QString sIntegralOrderNum = sc.property("data").property("integral_pay").toString();

    HttpSignal::instance()->sigOnCreatePayMemberCard(nCode, sMsg, sBanlanceOrderNum, sIntegralOrderNum);

    this->deleteLater();
}

void HttpCreatePayMemberCard::processError()
{
    HttpSignal::instance()->sigOnCreatePayMemberCard(e_connectServerError, c_sNetError, "", "");
    this->deleteLater();
}

