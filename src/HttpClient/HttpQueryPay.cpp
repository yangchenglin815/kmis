#include "HttpQueryPay.h"
#include "CommonFun.h"
#include "KPosIni.h"
#include "HttpSignal.h"
#include <QScriptEngine>
#include "KPosLog.h"
#include <QDebug>

HttpQueryPay::HttpQueryPay( QString sToken, QString sCorpID, QString sUUID, int nPayMethod, QString strPayOrderNum )
    : m_nPayMethod( nPayMethod )
    , m_sPayOrderNum( strPayOrderNum )
{
    QString userParam = QString("&hq_code=%1&pay_mode=%2&pay_num=%3&access_token=%4&uuid=%5")\
            .arg( sCorpID ).arg( nPayMethod ).arg( strPayOrderNum ).arg( sToken ).arg( sUUID );
    QString systemParam = CommonFun::generateSystemParams( c_sHttpQueryPaymentAction );
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);

    KPosLog::instance()->writeDebugLog( allParam );

    QString time = QTime::currentTime().toString("hh:mm:ss SSSS");
    qDebug()<<"HttpQueryPay::HttpQueryPay"<<time;
}

HttpQueryPay::~HttpQueryPay()
{

}

void HttpQueryPay::processResponse( QString strResult )
{
    QString time = QTime::currentTime().toString("hh:mm:ss SSSS");
    qDebug()<<"HttpQueryPay::processResponse"<<time;
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();//状态值
    QString sMsg = sc.property("msg").toString();//返回消息
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpQueryPay 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

//    eTradeSuc = 0, //支付成功
//    eTradeWaiting = 1, //用户支付中
//    eTradeFailed = 2, //支付失败
//    eTradeRevoke = 3, //支付已撤销
//    eTradeTransferRefund = 4, //转入退款
//    eTradeNoPay = 5, //未支付
//    eTradeClosed = 6,   //已关闭
//    eTradeRefund = 7  //7.未付款交易超时关闭，或支付完成后全额退款

    QString strPayOrderNum = sc.property("data").property("out_trade_no").toString();
    int nTradeState = sc.property("data").property("trade_state").toInt32();
    HttpSignal::instance()->sigOnGetPayStatus(nCode, sMsg, strPayOrderNum, nTradeState);
    this->deleteLater();
}

void HttpQueryPay::processError()
{
    HttpSignal::instance()->sigOnGetPayStatus( e_connectServerError, c_sNetError, m_sPayOrderNum, eTradeWaiting);
    this->deleteLater();
}
