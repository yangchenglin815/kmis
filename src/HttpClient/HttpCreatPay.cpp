#include "HttpCreatPay.h"
#include "CommonFun.h"
#include "KPosIni.h"
#include "HttpSignal.h"
#include <QScriptEngine>
#include "KPosLog.h"
#include <QDebug>

HttpCreatPay::HttpCreatPay(QString sToken, QString sCorpID, QString sUUID, EPayMethod ePayMethod,
                           QString strBarCode, QString strPayAmt, QString strSale,
                           QString sSaleDetailsJson, int nInteg, QString strPayPwd, QString strIntToAmt )
    : m_ePayMethod( ePayMethod )
    , m_sBarCode( strBarCode )
    , m_sPayAmt( strPayAmt )
    , m_sSale( strSale )
    , m_nInteg( nInteg )
    , m_sPayPwd( strPayPwd )
    , m_sIntToAmt( strIntToAmt )
{
    QString userParam = "";
    userParam = QString("&hq_code=%1&receipts=%2&auth_code=%3&pay_mode=%4&sum=%5&integral=%6&int_to_amt=%7&access_token=%8&uuid=%9")
            .arg(sCorpID).arg( strSale ).arg( strBarCode ).arg( ePayMethod ).arg( strPayAmt )
            .arg( nInteg ).arg( strIntToAmt ).arg( sToken ).arg( sUUID );

    if( !strPayPwd.isEmpty() )
    {
        QString strPwd = CommonFun::getStringMd5( strPayPwd );
        userParam += QString( "&pay_password=%1").arg( strPwd );
    }
    else
    {
        userParam += QString( "&pay_password=%1").arg( strPayPwd );
    }

    if (!sSaleDetailsJson.isEmpty())
    {
        userParam.append(QString("&consume_detail=%1").arg(sSaleDetailsJson));
    }

    userParam += QString( "&source=1");

    QString systemParam = CommonFun::generateSystemParams( c_sHttpCreatePaymentAction );
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);

    KPosLog::instance()->writeDebugLog( allParam );
    QString time = QTime::currentTime().toString("hh:mm:ss SSSS");
    qDebug()<<"HttpCreatPay::HttpCreatPay"<<time;
}

HttpCreatPay::~HttpCreatPay()
{

}

void HttpCreatPay::processResponse( QString strResult )
{
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
    QString strOrderNumS = sc.property("data").property("out_trade_no").toString();//服务器给的
    QString strAuthCode = sc.property("data").property("auth_code").toString();//pos机产生的

    HttpSignal::instance()->sigOnCreatePayStatus(nCode, sMsg, strOrderNumS, strAuthCode, m_ePayMethod );
    this->deleteLater();
}

void HttpCreatPay::processError()
{
    HttpSignal::instance()->sigOnCreatePayStatus(e_connectServerError, c_sNetError, "", m_sBarCode, m_ePayMethod );
    this->deleteLater();
}
