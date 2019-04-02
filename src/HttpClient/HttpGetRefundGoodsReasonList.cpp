#include "HttpGetRefundGoodsReasonList.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../util/KPosIni.h"
#include "../data/enumData.h"
#include "../data/httpstructdata.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpGetRefundGoodsReasonList::HttpGetRefundGoodsReasonList(QString sToken, QString sCorpID, QString sUUID, bool bIsOnline)
    : m_bProcessError(false)
{
    if (bIsOnline)
    {
        QString userParam = QString("&hq_code=%1&access_token=%2&uuid=%3").arg(sCorpID).arg(sToken).arg(sUUID);
        QString systemParam = CommonFun::generateSystemParams(c_sHttpGetRefundGoodsReasonListAction);
        QStringList paramList = systemParam.append(userParam).split("&");
        QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
        QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
        QByteArray array;
        array.append(allParam);
        setReqParams(array);
    }
    else
    {
        processError();
    }
}

void HttpGetRefundGoodsReasonList::processResponse(QString strResult)
{
    if (!m_bProcessError)
    {
        QScriptEngine engine;
        QScriptValue sc = engine.evaluate("value=" + strResult);
        int nCode = sc.property("code").toInt32();
        QString sMsg = sc.property("msg").toString();
        if (!sc.property("code").isValid())
        {
            KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetRefundGoodsReasonList 返回参数json格式错误"));
            nCode = e_connectServerError;
            sMsg = c_sServerJsonError;
        }
        else if (nCode == e_success)
        {
            KPosIni::setRefundGoodsReasonJosn(strResult);
            QList<RefundGoodsReason> reasonList;
            if (sc.property("data").isArray())
            {
                RefundGoodsReason reason;
                QScriptValueIterator it(sc.property("data"));
                while (it.hasNext())
                {
                    it.next();
                    reason.nId =  it.value().property("id").toInt32();// 原因id
                    if (reason.nId <= 0)
                    {
                        continue;
                    }
                    reason.sContent = it.value().property("reasons").toString(); // 原因内容
                    reasonList.append(reason);
                }
            }

            HttpSignal::instance()->sigOnGetRefundGoodsReasonList(nCode, sMsg, reasonList);
            this->deleteLater();
        }
        else
        {
            KPosLog::instance()->writeErrorLog(this->getTestUrl());
            KPosLog::instance()->writeErrorLog(strResult);
            processError();
        }
    }
    else
    {
        QScriptEngine engine;
        QScriptValue sc = engine.evaluate("value=" + strResult);
        int nCode = e_connectServerError;
        QString sMsg = c_sNetError;
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetRefundGoodsReasonList,取本地数据:%1").arg(strResult));
        QList<RefundGoodsReason> reasonList;
        if (sc.property("data").isArray())
        {
            RefundGoodsReason reason;
            QScriptValueIterator it(sc.property("data"));
            while (it.hasNext())
            {
                it.next();
                reason.nId =  it.value().property("id").toInt32();// 原因id
                if (reason.nId <= 0)
                {
                    continue;
                }
                reason.sContent = it.value().property("reasons").toString(); // 原因内容
                reasonList.append(reason);
            }
        }
        HttpSignal::instance()->sigOnGetRefundGoodsReasonList(nCode, sMsg, reasonList);
        this->deleteLater();
    }
}

void HttpGetRefundGoodsReasonList::processError()
{
    m_bProcessError = true;
    QString sRefundGoodsJson = KPosIni::getRefundGoodsReasonJson();
    processResponse(sRefundGoodsJson);
    m_bProcessError = false;

//    QList<RefundGoodsReason> orderInfoList;
//    HttpSignal::instance()->sigOnGetRefundGoodsReasonList(e_connectServerError, c_sNetError, orderInfoList);
//    this->deleteLater();
}

