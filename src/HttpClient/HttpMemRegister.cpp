#include "HttpMemRegister.h"
#include <QScriptEngine>
#include "HttpSignal.h"
#include "KPosLog.h"
#include "CommonFun.h"
#include "enumData.h"

HttpMemRegister::HttpMemRegister(QString strCorpId, MemRegisterInfo_s stMemRegister, int nShopId)
{
    m_stMemRegisterInfo = stMemRegister;

    QString systemParam = CommonFun::generateSystemParams( c_sHttpRegisterMem );
    QString strOperatorId = "";
    if( stMemRegister.nOPeratorId >= 0 ) {
        strOperatorId = QString::number( stMemRegister.nOPeratorId );
    }

    QString strDocumentType = "";

    if( stMemRegister.eDocumentType < 0 ) {
        stMemRegister.strDocumentNum = "";
    } else {
        strDocumentType = QString::number( stMemRegister.eDocumentType );
    }

    QString strPwd = "";
    if( !stMemRegister.strPayPwd.isEmpty() ) {
        strPwd = CommonFun::getStringMd5( stMemRegister.strPayPwd );
    }

    QString userParam = QString("&hq_code=%1&register_orgz_id=%2&vip_name=%3&sex=%4&mobile=%5"
            "&pay_password=%6&birthday=%7&vip_level_id=%8&user_id=%9") \
            .arg(strCorpId).arg( nShopId ).arg( stMemRegister.stMemInfo.strName )\
            .arg( stMemRegister.stMemInfo.nSex ).arg( stMemRegister.stMemInfo.strMobile ) \
            .arg( stMemRegister.strPayPwd ).arg( stMemRegister.stMemInfo.dtBirthday.toString("yyyy-MM-dd") ) \
            .arg( stMemRegister.stMemInfo.nMemLevelId).arg( strOperatorId );
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpMemRegister::processResponse(QString strResult)
{
    KPosLog::instance()->writeErrorLog(this->getTestUrl());
    KPosLog::instance()->writeErrorLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpMemRegister 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QString strCardNo = sc.property( "data").property("card_no").toString();
    m_stMemRegisterInfo.strIntExchangeAmt = sc.property( "data").property("exchange_price").toString();// 1积分抵价
    m_stMemRegisterInfo.strMaxGiftAmt = sc.property( "data").property("discount_amt").toString();// 最大优惠金额
    m_stMemRegisterInfo.strRechargeAmt1 = sc.property("data").property("recharge_amt_1").toString();//充值基准金额1
    m_stMemRegisterInfo.strRechargeAmt2 = sc.property("data").property("recharge_amt_2").toString();//充值基准金额2
    m_stMemRegisterInfo.strRechargeAmt3 = sc.property("data").property("recharge_amt_3").toString();//充值基准金额3
    m_stMemRegisterInfo.strGiftAmt1 = sc.property("data").property("gift_amt_1").toString(); //赠送基准金额1
    m_stMemRegisterInfo.strGiftAmt2 = sc.property("data").property("gift_amt_2").toString(); //赠送基准金额2
    m_stMemRegisterInfo.strGiftAmt3 = sc.property("data").property("gift_amt_3").toString(); //赠送基准金额3
    m_stMemRegisterInfo.strSaleAmt = sc.property( "data").property("sales_amt").toString();// 消费金额
    m_stMemRegisterInfo.strGiftIntegral = sc.property( "data").property("gift_integral").toString();// 赠送积分
    int nStatus = 0;//sc.property( "data").property("status").toInt32();
    m_stMemRegisterInfo.stMemInfo.strCardNo = strCardNo;
    HttpSignal::instance()->sigOnMemRegister( nCode, sMsg, strCardNo, nStatus, m_stMemRegisterInfo );
    this->deleteLater();
}

void HttpMemRegister::processError()
{
    MemRegisterInfo_s stMemRegister;
    m_stMemRegisterInfo = stMemRegister;

    HttpSignal::instance()->sigOnMemRegister( e_connectServerError, "当前没有网络", "", 1, m_stMemRegisterInfo );
    this->deleteLater();
}
