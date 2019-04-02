#include "ThreadManager.h"

QThread* ThreadManager::m_pAgentThread = NULL;
QThread* ThreadManager::m_pDownloadThread = NULL;

QThread *ThreadManager::getAgentThread()
{
    if (m_pAgentThread == NULL)
    {
       m_pAgentThread = new QThread;
    }
    return m_pAgentThread;
}

QThread *ThreadManager::getDownloadThread()
{
    if (m_pDownloadThread == NULL)
    {
        m_pDownloadThread = new QThread;
    }
    return m_pDownloadThread;
}
