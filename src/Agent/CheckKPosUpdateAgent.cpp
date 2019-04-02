#include "CheckKPosUpdateAgent.h"
#include "../HttpClient/HttpClient.h"
#include "../util/HttpSignal.h"
#include "OnlineStateAgent.h"
#include "ThreadManager.h"

CheckKPosUpdateAgent* CheckKPosUpdateAgent::m_pInstance = NULL;

CheckKPosUpdateAgent::CheckKPosUpdateAgent(QObject *parent)
    : QObject(parent)
{
    initConnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

CheckKPosUpdateAgent *CheckKPosUpdateAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new CheckKPosUpdateAgent;
    }
    return m_pInstance;
}

void CheckKPosUpdateAgent::checkKPosUpdateRequest()
{
    if (OnlineStateAgent::instance()->isOnline())
    {
        HttpClient::instance()->checkKPosUpdate();
    }
    else
    {
        emit sigLocalCheckKPosUpdate();
    }
}

void CheckKPosUpdateAgent::slot_onCheckKPosUpdate(int nCode, QString sMsg, KPosUpdateInfo kPosUpdateInfo)
{
    emit sigOnCheckKPosUpdate(nCode, sMsg, kPosUpdateInfo);
}

void CheckKPosUpdateAgent::slot_localCheckKPosUpdate()
{
    KPosUpdateInfo kPosUpdateInfo;
    kPosUpdateInfo.nUpdateType = e_noUpdate;
    emit sigOnCheckKPosUpdate(-1, QStringLiteral("网络异常"), kPosUpdateInfo);
}

void CheckKPosUpdateAgent::initConnect()
{
    qRegisterMetaType<KPosUpdateInfo>("KPosUpdateInfo");
    connect(HttpSignal::instance(), SIGNAL(sigOnCheckKPosUpdate(int, QString, KPosUpdateInfo)),
            this, SLOT(slot_onCheckKPosUpdate(int, QString, KPosUpdateInfo)));
    connect(this, SIGNAL(sigLocalCheckKPosUpdate()), this, SLOT(slot_localCheckKPosUpdate()));
}
