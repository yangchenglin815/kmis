#include "HttpGetAllUserInfo.h"
#include "CommonFun.h"
#include "KPosLog.h"
#include <QScriptEngine>
#include "HttpSignal.h"
#include "httpstructdata.h"
#include "constData.h"
#include <QScriptValueIterator>

HttpGetAllUserInfo::HttpGetAllUserInfo(QString sToken, QString sCorpID, QString sUUID )
{
    QString userParam = "";
    userParam = QString("&hq_code=%1&uuid=%2&access_token=%3")
            .arg( sCorpID ).arg( sUUID ).arg(sToken);

    QString systemParam = CommonFun::generateSystemParams( c_sHttpAllUserList );
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);

    KPosLog::instance()->writeDebugLog( allParam );
}

void HttpGetAllUserInfo::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();//状态值
    QString sMsg = sc.property("msg").toString();//返回消息
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetAllUserInfo 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog( "HttpGetAllUserInfo::processResponse" + strResult);
    }

    QList<SalemanInfo> listSalemanInfo;
    if (sc.property("data").isArray())
    {
        QScriptValueIterator it(sc.property("data"));
        SalemanInfo stSalemanInfo;
        while (it.hasNext())
        {
            it.next();
            stSalemanInfo.nUserId = it.value().property("id").toInt32();
            if ( stSalemanInfo.nUserId == 0)
            {
                continue;
            }
            stSalemanInfo.sUserCode = it.value().property("user_code").toString();
            stSalemanInfo.sUsername = it.value().property("realname").toString();
            stSalemanInfo.sEmail = it.value().property("email").toString();
            stSalemanInfo.sMobile = it.value().property("mobile").toString();
            stSalemanInfo.nSex = it.value().property("sex").toInt32();
            stSalemanInfo.sUserPic = it.value().property("avatar").toString();
            stSalemanInfo.sRoleCode = it.value().property("role_code").toString();

            QString strPrivile = it.value().property("pos_authority").toString();
            if( strPrivile == "all" ) {
                QList<QString> listPrivilege;
                listPrivilege.append( "0100" );
                listPrivilege.append( "0200" );
                listPrivilege.append( "0300" );
                listPrivilege.append( "0400" );
                listPrivilege.append( "0600" );
                listPrivilege.append( "0800" );
                listPrivilege.append( "0900" );
                listPrivilege.append( "1000" );
                stSalemanInfo.privilegeList = listPrivilege;
            } else {
                stSalemanInfo.privilegeList = strPrivile.split(",");
            }

            listSalemanInfo.append( stSalemanInfo );
        }
    }

    HttpSignal::instance()->sigOnGetAllUserInfo( nCode, sMsg, listSalemanInfo );
    this->deleteLater();
}

void HttpGetAllUserInfo::processError()
{
    QList<SalemanInfo> listSalemanInfo;

    HttpSignal::instance()->sigOnGetAllUserInfo( -1, c_sNetError, listSalemanInfo );
    this->deleteLater();
}
