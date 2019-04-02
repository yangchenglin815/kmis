#include "HttpMemInfoQuery.h"
#include "CommonFun.h"
#include <QScriptEngine>
#include "KPosLog.h"
#include "httpstructdata.h"
#include "HttpSignal.h"
#include "enumData.h"
#include "KPosServerIni.h"

HttpMemInfoQuery::HttpMemInfoQuery( QString sCorpID, QString strUUID, QString strMemCardId, bool bForRefund)
    : m_sMemCardId(strMemCardId)
    , m_bForRefund(bForRefund)
{
    KPosLog::instance()->writeErrorLog(QString("HttpMemInfoQuery::HttpMemInfoQuery -- %1").arg(strMemCardId));

    QString systemParam = CommonFun::generateSystemParams( c_sHttpQueryMemInfo );
    QString userParam = QString("&hq_code=%1&uuid=%2&card_mobile=%3")
            .arg(sCorpID).arg( strUUID ).arg(strMemCardId);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpMemInfoQuery::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpMemInfoQuery 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    MemRegisterInfo_s stMemReg;

    int UserType = KPosServerIni::getKPosUserType();

    if(UserType == e_commonVersion){
        stMemReg.stMemInfo.strCardNo = sc.property("data").property("card_no").toString();//vip_account: "00000001",
        stMemReg.stMemInfo.strCardNo = CommonFun::httpNullToString( stMemReg.stMemInfo.strCardNo );
    }    //把账号当做卡号使用
    else if(UserType == e_tianMaoVersion){
        stMemReg.stMemInfo.strCardNo = sc.property("data").property("vip_account").toString();//vip_account: "00000001",
        stMemReg.stMemInfo.strCardNo = CommonFun::httpNullToString( stMemReg.stMemInfo.strCardNo );
    }

    stMemReg.stMemInfo.strName = sc.property("data").property("vip_name").toString();
    stMemReg.stMemInfo.strMobile = sc.property( "data").property("mobile").toString();
    stMemReg.stMemInfo.nSex = sc.property("data").property("sex").toInt32();

//    stMemReg.eDocumentType = (EDocumentType)sc.property("data").property("document_type").toInt32();
//    stMemReg.strDocumentNum = sc.property("data").property("document_num").toString();
//    stMemReg.strAddress = sc.property("data").property("address").toString();
    //stMemReg.strPayPwd = sc.property("data").property("pay_password").toString();
    stMemReg.bPaypwd= sc.property("data").property("pay_password").toBool();
    stMemReg.nOPeratorId = sc.property("data").property("user_id").toInt32();

    QString strBirthday = sc.property("data").property("birthday").toString();
    stMemReg.stMemInfo.dtBirthday = QDateTime::fromString( strBirthday, "yyyy-MM-dd" );
    //stMemReg.stMemInfo.nMemTypeId = sc.property("data").property("vip_type_id").toInt32();
    stMemReg.stMemInfo.nMemLevelId = sc.property("data").property("vip_level_id").toInt32();
    stMemReg.stMemInfo.strAccountBalance = sc.property("data").property("account_balance").toString();
    stMemReg.stMemInfo.nIntegral = sc.property("data").property("integral").toInt32();
    stMemReg.stMemInfo.nCardStatus = sc.property("data").property("card_status").toInt32();
    QString strLastDate = sc.property("data").property("last_shopping").toString();
    stMemReg.stMemInfo.dtShopping = QDateTime::fromString( strLastDate, "yyyy-MM-dd hh:mm:ss" );
    stMemReg.strIntExchangeAmt = sc.property("data").property("exchange_price").toString();// 1积分抵价
    stMemReg.strMaxGiftAmt = sc.property("data").property("discount_amt").toString();// 最大优惠金额
    stMemReg.strRechargeAmt1 = sc.property("data").property("recharge_amt_1").toString();//充值基准金额1
    stMemReg.strRechargeAmt2 = sc.property("data").property("recharge_amt_2").toString();//充值基准金额2
    stMemReg.strRechargeAmt3 = sc.property("data").property("recharge_amt_3").toString();//充值基准金额3
    stMemReg.strGiftAmt1 = sc.property("data").property("gift_amt_1").toString(); //赠送基准金额1
    stMemReg.strGiftAmt2 = sc.property("data").property("gift_amt_2").toString(); //赠送基准金额2
    stMemReg.strGiftAmt3 = sc.property("data").property("gift_amt_3").toString(); //赠送基准金额3

    stMemReg.strSaleAmt = sc.property("data").property("sales_amt").toString();// 消费基准金额
    stMemReg.strGiftIntegral = sc.property("data").property("gift_integral").toString();// 赠送基准积分

    if (!m_bForRefund)
    {
        HttpSignal::instance()->sigOnMemInfoQuery(nCode, sMsg, stMemReg);
    }
    else
    {
        HttpSignal::instance()->sigOnMemInfoQueryForRefund(nCode, sMsg, stMemReg);
    }

    this->deleteLater();
}

void HttpMemInfoQuery::processError()
{
    MemRegisterInfo_s stMemReg;
    if (!m_bForRefund)
    {
        HttpSignal::instance()->sigOnMemInfoQuery( e_connectServerError, c_sNetError, stMemReg );
    }
    else
    {
        HttpSignal::instance()->sigOnMemInfoQueryForRefund(e_connectServerError, c_sNetError, stMemReg);
    }

    this->deleteLater();
}
