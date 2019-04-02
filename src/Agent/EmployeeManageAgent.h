#ifndef EMPLOYEEMANAGEAGENT_H
#define EMPLOYEEMANAGEAGENT_H

#include <QObject>
#include "httpstructdata.h"

class EmployeeManageAgent : public QObject
{
    Q_OBJECT
public:
    static EmployeeManageAgent* instance();
    void getEmployeeManageOrderListRequest(QString sSearchPatter);
    void changeEmployeeStatusOrderRequest(QList<int> nOrderList, int status);
    void getEmployeeScodeOrderRequest();
    void EditEmployeeOrderRequest(AccountInfo info, int status);

private:
    explicit EmployeeManageAgent(QObject *parent = 0);
    void initconnect();

signals:
    void sigOnGetEmployeeManageOrderList(int nCode, QString sMsg, QList<AccountInfo> orderInfoList);
    void sigChangeEmployeeStatusOrder(int nCode, QString sMsg, QList<int> orderList, int status);
    void sigOnGetEmployeeScodeOrder(int nCode, QString sMsg, QString nScode);
    void sigOnEditEmployeeOrder(int nCode, QString sMsg);

private:
    static EmployeeManageAgent* m_pInstance;
};

#endif // EMPLOYEEMANAGEAGENT_H
