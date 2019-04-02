#include "HttpCreateGoodsGroup.h"
#include "../data/constData.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/barcodescaledata.h"
#include <QScriptEngine>

HttpCreateGoodsGroup::HttpCreateGoodsGroup(QString sCorpID, QString sToken, QString sUUID, QString sGroupName)
{
    m_sGroupName = sGroupName;

    QString userParam = QString("&hq_code=%1&access_token=%2&uuid=%3&group_name=%4")
            .arg(sCorpID).arg(sToken).arg(sUUID).arg(sGroupName);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpCreateGoodsGroupAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpCreateGoodsGroup::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();//状态值
    QString sMsg = sc.property("msg").toString();//返回消息
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpCreateGoodsGroup 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    BCSGroupManageLeftInfo bcsGroupManageLeftInfo;
    bcsGroupManageLeftInfo.nGroupId = sc.property("data").property("group_id").toInt32();
    bcsGroupManageLeftInfo.sGroupNum = sc.property("data").property("group_code").toString(); // 组号
    bcsGroupManageLeftInfo.sGroupName = m_sGroupName; // 组名

    HttpSignal::instance()->sigOnCreateGoodsGroup(nCode, sMsg, bcsGroupManageLeftInfo);

    this->deleteLater();
}

void HttpCreateGoodsGroup::processError()
{
    BCSGroupManageLeftInfo bcsGroupManageLeftInfo;
    HttpSignal::instance()->sigOnCreateGoodsGroup(e_connectServerError, c_sNetError, bcsGroupManageLeftInfo);
    this->deleteLater();
}

