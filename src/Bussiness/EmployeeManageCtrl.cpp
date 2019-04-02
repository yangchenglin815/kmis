#include "EmployeeManageCtrl.h"
#include "EmployeeManageAgent.h"
#include <QDebug>

EmployeeManageCtrl::EmployeeManageCtrl(QObject *parent) : QObject(parent)
{
    initconnect();
}

void EmployeeManageCtrl::getEmployeeManageListRequest(QString sSearchPatter)
{
    EmployeeManageAgent::instance()->getEmployeeManageOrderListRequest(sSearchPatter);
}

void EmployeeManageCtrl::changeEmployeeStatusOrderRequest(QList<int> nOrderList, int status)
{
    EmployeeManageAgent::instance()->changeEmployeeStatusOrderRequest(nOrderList, status);
}

void EmployeeManageCtrl::getEmployeeScodeOrderRequest()
{
    EmployeeManageAgent::instance()->getEmployeeScodeOrderRequest();
}

void EmployeeManageCtrl::EditEmployeeOrderRequest(AccountInfo info, int status)
{
    EmployeeManageAgent::instance()->EditEmployeeOrderRequest(info, status);
}

void EmployeeManageCtrl::initconnect()
{
    qRegisterMetaType<QList<AccountInfo> >("QList<AccountInfo>");
    connect(EmployeeManageAgent::instance(), SIGNAL(sigOnGetEmployeeManageOrderList(int,QString,QList<AccountInfo>))
            , this, SIGNAL(sigOnGetEmployeeManageList(int,QString,QList<AccountInfo>)));
    connect(EmployeeManageAgent::instance(), SIGNAL(sigChangeEmployeeStatusOrder(int,QString,QList<int>,int))
            , this, SIGNAL(sigChangeEmployeeStatusOrder(int,QString,QList<int>,int)));
    connect(EmployeeManageAgent::instance(), SIGNAL(sigOnGetEmployeeScodeOrder(int,QString,QString))
            , this, SIGNAL(sigOnGetEmployeeScodeOrder(int,QString,QString)));
    connect(EmployeeManageAgent::instance(), SIGNAL(sigOnEditEmployeeOrder(int,QString))
            , this, SIGNAL(sigOnEditEmployeeOrder(int,QString)));
}
