#include "ResetKeyAgent.h"
#include "../util/ThreadManager.h"
#include "../util/HttpSignal.h"
#include "CommonFun.h"
#include "MTScaleAPIDll.h"
#include "HttpClient.h"
#include "enumData.h"
#include "KPosLog.h"
#include <QDateTime>
#include <QDebug>
#include <QTime>
#include <QApplication>
#include <QDir>

ResetKeyAgent* ResetKeyAgent::m_pInstance = NULL;

ResetKeyAgent::ResetKeyAgent(QObject *parent)
    : QObject(parent)
//    , m_nCheckStateCount(0)
{
    initConnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

ResetKeyAgent *ResetKeyAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new ResetKeyAgent;
    }
    return m_pInstance;
}

void ResetKeyAgent::initConnect()
{
    connect(HttpSignal::instance(), SIGNAL(sigResetPasswd(int,QString))
             , this, SIGNAL(sigResetPasswd(int, QString)));
}

void ResetKeyAgent::resetKeyRequest(QString oldkey, QString newkey){
    HttpClient::instance()->resetKey(oldkey, newkey);
}
