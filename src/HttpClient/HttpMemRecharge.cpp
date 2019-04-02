#include "HttpMemRecharge.h"
#include "CommonFun.h"
#include <QScriptEngine>
#include "HttpSignal.h"
#include "KPosLog.h"
#include "enumData.h"

//auth_code就是用户支付的（微信或支付宝）付款码
HttpMemRecharge::HttpMemRecharge(QString strCorpID, QString strUUID, QString strMemCardId, QString strRechargeAmt
                                 , int nPayMethod, int nOperatorId, QString strPayCode, int nOrgzId, bool bVirtual )
{
    QString systemParam = CommonFun::generateSystemParams( c_sHttpRechargeMem );
    QString userParam = QString("&hq_code=%1&card_no=%2&amount=%3&payment_mode=%4"
        "&user_id=%5&auth_code=%6&orgz_id=%7&is_virtual=%8&uuid=%9")
            .arg(strCorpID).arg(strMemCardId).arg( strRechargeAmt ).arg( nPayMethod )
            .arg( nOperatorId ).arg( strPayCode ).arg( nOrgzId ).arg( bVirtual ).arg(strUUID);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpMemRecharge::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpMemRecharge 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    //out_trade_no: 后台定义的付款码
    QString strTradeNo = sc.property("data").property("out_trade_no").toString();
    QString strCardNo = sc.property("data").property("card_no").toString();
    //account_balance:账户余额
    QString strAccountBalance = sc.property( "data").property("account_balance").toString();
    int nIntegral = sc.property( "data" ).property( "account_integral" ).toInt32();
    QString strGiftAmt = sc.property("data").property( "gift_amount" ).toString();

    HttpSignal::instance()->sigOnMemRecharge( nCode, sMsg, strCardNo, strAccountBalance, strTradeNo, nIntegral, strGiftAmt );
    this->deleteLater();
}

void HttpMemRecharge::processError()
{
    HttpSignal::instance()->sigOnMemRecharge( e_connectServerError, "当前没有网络", "", "", "", -1, "" );
    this->deleteLater();
}
