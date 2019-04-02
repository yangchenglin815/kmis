#include "HttpLoginKPos.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"
#include "../data/httpstructdata.h"
#include "../data/enumData.h"
#include <QScriptEngine>

HttpLoginKPos::HttpLoginKPos(QString sCorpID, QString sUserCode, QString sPassword, QString sUUID,
                             QString sAppName, QString sAppVersion, QString sOSVersion,
                             QString sBranchName, bool bUpdateToken)
{
    m_sPassword = sPassword;
    m_sUserCode = sUserCode;
    m_bUpdateToken = bUpdateToken;
    QString systemParam = CommonFun::generateSystemParams(c_sHttpLoginKPosAction);
    QString userParam = QString("&hq_code=%1&username=%2&password=%3&uuid=%4&app_name=%5&app_version=%6"
                                "&os_version=%7&brand_name=%8").arg(sCorpID).arg(sUserCode).arg(sPassword)
            .arg(sUUID).arg(sAppName).arg(sAppVersion).arg(sOSVersion).arg(sBranchName);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpLoginKPos::processResponse(QString strResult)
{
//    KPosLog::instance()->writeErrorLog("111 -- " + this->getTestUrl());
//    KPosLog::instance()->writeErrorLog("111 -- " + strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpLoginKPos 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    LoginKPosInfo loginKPosInfo;
    loginKPosInfo.sToken = sc.property("data").property("access_token").toString(); //访问标识
    // 用户信息
    loginKPosInfo.salemanInfo.sPassword = m_sPassword;
    loginKPosInfo.salemanInfo.nUserId = sc.property("data").property("id").toInt32();//用户ID
    loginKPosInfo.salemanInfo.sUserCode = m_sUserCode;//用户编码
    loginKPosInfo.salemanInfo.sUsername = sc.property("data").property("realname").toString();//用户名
    loginKPosInfo.salemanInfo.sEmail = sc.property("data").property("email").toString();//用户邮箱
    loginKPosInfo.salemanInfo.sMobile = sc.property("data").property("mobile").toString();//手机
    loginKPosInfo.salemanInfo.sRoleCode = sc.property("data").property("role_code").toString();//角色编码
//    loginKPosInfo.salemanInfo.sLoginTime = sc.property("data").property("login_at").toString(); //登入时间
    QString sSex = sc.property("data").property("sex").toString();//性别
    if (sSex == QStringLiteral("男"))
    {
        loginKPosInfo.salemanInfo.nSex = e_man;
    }
    else if (sSex == QStringLiteral("女"))
    {
        loginKPosInfo.salemanInfo.nSex = e_woman;
    }
    else
    {
        loginKPosInfo.salemanInfo.nSex = e_nullSex;
    }
    loginKPosInfo.salemanInfo.sUserPic = sc.property("data").property("avatar").toString();//用户头像
//    loginKPosInfo.salemanInfo.nUserPrivilege = sc.property("data").property("purview").toInt32();//用户权限

    QString sPrivileges = sc.property("data").property("pos_authority").toString(); // 角色权限
    if (sPrivileges == "all")
    {
        loginKPosInfo.salemanInfo.privilegeList<<c_sSaleCode<<c_sReportCode<<c_sStockCode
                                              <<c_sOrderGoodsCode<<c_sAccountManageCode<<c_sSetCode
                                             <<c_sModifyPasswordCode<<c_sAdjustPriceCode;
    }
    else
    {
        loginKPosInfo.salemanInfo.privilegeList = sPrivileges.split(",");
    }
//    loginKPosInfo.salemanInfo.sRoleCode = sc.property("data").property("role_code").toString(); // 角色编码
//    loginKPosInfo.salemanInfo.sRoleName = sc.property("data").property("role_name").toString(); // 角色显示名称
//    loginKPosInfo.salemanInfo.sRoleShowName = sc.property("data").property("display_name").toString(); // 角色名称
//    if (loginKPosInfo.salemanInfo.sRoleShowName.isEmpty())
//    {
//        loginKPosInfo.salemanInfo.sRoleShowName = loginKPosInfo.salemanInfo.sRoleName;
//    }

    // pos机信息
    loginKPosInfo.sCorpCode = sc.property("data").property("hq_code").toString();//企业编码
    loginKPosInfo.sCorpName = sc.property("data").property("hq_name").toString(); // 企业名称
    loginKPosInfo.nShopID = sc.property("data").property("belong_orgz_id").toInt32(); // 门店ID
    loginKPosInfo.sShopName = sc.property("data").property("belong_orgz_name").toString(); // 门店名称
    loginKPosInfo.sShopCode = sc.property("data").property("orgz_code").toString(); // 门店编号
    loginKPosInfo.sPosCode = sc.property("data").property("pos_code").toString(); // 款机号
    loginKPosInfo.nLoginId = sc.property("data").property("login_id").toInt32(); // 登录ID
    // 用户上次钱包余额信息
    loginKPosInfo.fPurseRemain = sc.property("data").property("total_amt").toString().toFloat();//钱包剩余金额
    loginKPosInfo.sLastHandPurseTime = sc.property("data").property("last_submit_at").toString();//上次交款时间

    if (!m_bUpdateToken)
    {
       HttpSignal::instance()->sigOnLoginKPos(nCode, sMsg, loginKPosInfo);
    }
    else
    {
       if (nCode == e_success)
       {
           HttpSignal::instance()->sigOnUpdateToken(loginKPosInfo.sToken);
       }
    }
    this->deleteLater();
}

void HttpLoginKPos::processError()
{
    LoginKPosInfo loginKPosInfo;
    loginKPosInfo.salemanInfo.sUserCode = m_sUserCode;
    loginKPosInfo.salemanInfo.sPassword = m_sPassword;
    if (!m_bUpdateToken)
    {
        HttpSignal::instance()->sigOnLoginKPos(e_connectServerError, c_sNetError, loginKPosInfo);
    }
    this->deleteLater();
}
