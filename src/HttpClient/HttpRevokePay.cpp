#include "HttpRevokePay.h"
#include <QScriptEngine>
#include "HttpSignal.h"
#include "CommonFun.h"
#include "KPosLog.h"

HttpRevokePay::HttpRevokePay(QString sToken, QString sCorpID, QString sUUID, EPayMethod ePayMethod, QString strPayOrderNum)
    : m_ePayMethod( ePayMethod )
    , m_sPayOrderNum( strPayOrderNum )
{
    QString userParam = QString("&hq_code=%1&pay_mode=%2&out_trade_no=%3&access_token=%4&uuid=%5")
            .arg(sCorpID).arg(ePayMethod).arg(strPayOrderNum).arg(sToken).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpRevokePaymentAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

HttpRevokePay::~HttpRevokePay()
{

}

void HttpRevokePay::processResponse( QString strResult )
{    
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();//状态值
    QString sMsg = sc.property("msg").toString();//返回消息
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpRevokePay 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QString strOrderNum = sc.property("data").property("out_trade_no").toString();//小票订单号
    int nRevoked = sc.property("data").property("revoked").toInt32();
    if( m_ePayMethod == PayMemCard ) {
        QString strMemCardBanlance = sc.property("data").property("member_card_banlance").toString();//会员卡余额
        int nMemCardIntegral = sc.property("data").property("member_card_integral").toInt32();//会员卡积分
        HttpSignal::instance()->sigOnMemCardRevokePay( nCode, sMsg, strOrderNum, nRevoked, strMemCardBanlance, nMemCardIntegral );
    } else {
        HttpSignal::instance()->sigOnRevokePay( nCode, sMsg, strOrderNum, nRevoked );
    }
    this->deleteLater();
}

void HttpRevokePay::processError()
{
    if( m_ePayMethod == PayMemCard ) {
        HttpSignal::instance()->sigOnMemCardRevokePay( e_connectServerError, c_sNetError, m_sPayOrderNum, -1, "", 0 );
    } else {
        HttpSignal::instance()->sigOnRevokePay( e_connectServerError, c_sNetError, m_sPayOrderNum, -1 );
    }
    this->deleteLater();
}
