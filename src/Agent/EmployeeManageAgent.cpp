#include "EmployeeManageAgent.h"

#include "../HttpClient/HttpClient.h"
#include "../util/HttpSignal.h"
#include "../util/ThreadManager.h"

EmployeeManageAgent* EmployeeManageAgent::m_pInstance = NULL;

EmployeeManageAgent *EmployeeManageAgent::instance()
{
    if(m_pInstance == NULL){
        m_pInstance = new EmployeeManageAgent;
    }
    return m_pInstance;
}

void EmployeeManageAgent::getEmployeeManageOrderListRequest(QString sSearchPatter)
{
    HttpClient::instance()->getEmployeeManageOrderList(sSearchPatter);
}

void EmployeeManageAgent::changeEmployeeStatusOrderRequest(QList<int> nOrderList, int status)
{
    HttpClient::instance()->changeEmployeeStatusOrder(nOrderList, status);
}

void EmployeeManageAgent::getEmployeeScodeOrderRequest()
{
    HttpClient::instance()->getEmployeeScodeOrderRequest();
}

void EmployeeManageAgent::EditEmployeeOrderRequest(AccountInfo info, int status)
{
    HttpClient::instance()->EditEmployeeOrderRequest(info, status);
}

EmployeeManageAgent::EmployeeManageAgent(QObject *parent) : QObject(parent)
{
    initconnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

void EmployeeManageAgent::initconnect()
{
    qRegisterMetaType<QList<AccountInfo> >("QList<AccountInfo>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetEmployeeManageOrderList(int,QString,QList<AccountInfo>))
            , this, SIGNAL(sigOnGetEmployeeManageOrderList(int,QString,QList<AccountInfo>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnChangeEmployeeStatusOrder(int,QString,QList<int>,int))
            , this, SIGNAL(sigChangeEmployeeStatusOrder(int,QString,QList<int>,int)));
    connect(HttpSignal::instance(), SIGNAL(sigOnGetEmployeeScodeOrder(int,QString,QString))
            , this, SIGNAL(sigOnGetEmployeeScodeOrder(int,QString,QString)));
    connect(HttpSignal::instance(), SIGNAL(sigOnEditEmployeeOrder(int,QString))
            , this, SIGNAL(sigOnEditEmployeeOrder(int,QString)));
}
