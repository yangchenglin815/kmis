#include "IHttpReqRes.h"
#include "TipsDlg.h"
#include <QDebug> // 测试用
#include "../util/KPosLog.h"
#include "../data/constData.h"
#include "KPosServerIni.h"

IHttpReqRes::IHttpReqRes(QObject *parent)
    : QObject(parent)
    , m_nReconnectTimes(0)
    , m_nOverTimeLen(10)
    , m_bOverTime(false)
{
    m_sUrlAddress = KPosServerIni::getServerIp() + "/gateway?";/*c_sHttpAddress;*/
    initConnect();
}

IHttpReqRes::~IHttpReqRes()
{

}

void IHttpReqRes::setNetManager(QNetworkAccessManager* pManager)
{
    pManager->setNetworkAccessible(QNetworkAccessManager::Accessible);
    m_pManager = pManager;
}

void IHttpReqRes::setReqParams(QByteArray byArr)
{
    byArr.replace("+","%2B");
    byArr.replace("#", "%23");
    m_reqParams = byArr;
}

void IHttpReqRes::postRequest()
{
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    request.setUrl(QUrl(m_sUrlAddress));
    m_pReply = m_pManager->post(request, m_reqParams);
    connect(m_pReply, SIGNAL(finished()), this, SLOT(slot_ReplyFinished()));
    m_sTestUrl = request.url().toString().append(m_reqParams); // 测试用
    if (!m_sTestUrl.contains(c_sHttpOnlineCheckAction))
    {
        qDebug()<<m_sTestUrl;
        KPosLog::instance()->writeDebugLog(m_sTestUrl);
    }

    m_bOverTime = false;
    if (!m_overTimer.isActive())
    {
        m_overTimer.start(m_nOverTimeLen*1000);
    }
}

QString IHttpReqRes::getTestUrl()
{
    return m_sTestUrl;
}

void IHttpReqRes::setOverTimeLengh(int nOverTimeLengh)
{
    m_nOverTimeLen = nOverTimeLengh;
}

bool IHttpReqRes::isOverTime()
{
    return m_bOverTime;
}

void IHttpReqRes::setReqUrlAddress(QString urlAddress)
{
    m_sUrlAddress = urlAddress;
}

void IHttpReqRes::slot_ReplyFinished()
{
    m_bOverTime = false;
    m_overTimer.stop();

    QTextCodec *codec = QTextCodec::codecForName("utf8");

    QNetworkReply::NetworkError err = m_pReply->error();

    if (err != QNetworkReply::NoError)
    {
        //        OnlineStateAgent::instance()->setOnlineState(false);
        KPosLog::instance()->writeErrorLog(QString(QStringLiteral("网络异常: %1; errorCod:%2; errorMsg:%3")).arg(m_sTestUrl).arg(err).arg(m_pReply->errorString()));
        processError();
    }
    else
    {
        m_nReconnectTimes = 0;
        QString strResult = codec->toUnicode(m_pReply->readAll());
        m_pReply->deleteLater();
        m_pReply = NULL;
        processResponse(strResult);
    }
}

void IHttpReqRes::slot_overTimeout()
{
    m_bOverTime = true;
    KPosLog::instance()->writeErrorLog(QString(QStringLiteral("网络超时: %1;")).arg(m_sTestUrl));
    processError();
}

void IHttpReqRes::initConnect()
{
    connect(&m_overTimer, SIGNAL(timeout()), this, SLOT(slot_overTimeout()));
}
