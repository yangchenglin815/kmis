#include "OnlineStateAgent.h"
#include "HttpClient.h"
#include "../util/HttpSignal.h"
#include "../util/ThreadManager.h"
#include <QDebug>

OnlineStateAgent* OnlineStateAgent::m_pInstance = NULL;

MyMutexReadLocker::MyMutexReadLocker(QReadWriteLock &readwriteLock)
{
    m_pReadWriteLock = &readwriteLock;
    m_pReadWriteLock->lockForRead();
}

MyMutexReadLocker::~MyMutexReadLocker()
{
    m_pReadWriteLock->unlock();
}

OnlineStateAgent *OnlineStateAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new OnlineStateAgent;
    }
    return m_pInstance;
}

void OnlineStateAgent::checkIsOnlineRequest()
{
    HttpClient::instance()->checkIsOnline();
}

bool OnlineStateAgent::isOnline()
{
    MyMutexReadLocker myMutexReadLocker(m_readWriteLock);
    Q_UNUSED(myMutexReadLocker)
    return m_bOnline;
}

void OnlineStateAgent::setOnlineState(bool isOnline)
{
    //bool bChange = false;
    m_readWriteLock.lockForWrite();
    if( m_bOnline != isOnline )
    {
        m_bOnline = isOnline;
        //bChange = true;
    }
    m_readWriteLock.unlock();

    emit sigOnlineState( isOnline );
//    if( bChange && m_bOnline )
//    {
//        emit sigUploadReceipt( isOnline );
//    }
}

void OnlineStateAgent::slot_onlineState(bool isOnline)
{
    setOnlineState(isOnline);
}

void OnlineStateAgent::slot_timeout()
{
    HttpClient::instance()->checkIsOnline();
}

void OnlineStateAgent::slot_overTimeout()
{
    setOnlineState(false);
}

OnlineStateAgent::OnlineStateAgent()
    :m_bOnline(false)
{
    initConnect();
//    moveToThread(ThreadManager::getAgentThread());
//    ThreadManager::getAgentThread()->start();
}

void OnlineStateAgent::initConnect()
{
    connect(HttpSignal::instance(), SIGNAL(sigOnlineState(bool)), this, SLOT(slot_onlineState(bool)));
}
