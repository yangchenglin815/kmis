#ifndef EMPLOYEEMANAGECTRL_H
#define EMPLOYEEMANAGECTRL_H

#include <QObject>
#include "httpstructdata.h"

class EmployeeManageCtrl : public QObject
{
    Q_OBJECT
public:
    explicit EmployeeManageCtrl(QObject *parent = 0);
    void getEmployeeManageListRequest(QString sSearchPatter);
    void changeEmployeeStatusOrderRequest(QList<int> nOrderList, int status);
    void getEmployeeScodeOrderRequest();
    void EditEmployeeOrderRequest(AccountInfo info, int status);

private:
    void initconnect();

signals:
    void sigOnGetEmployeeManageList(int nCode, QString sMsg, QList<AccountInfo> orderInfoList);
    void sigChangeEmployeeStatusOrder(int nCode, QString sMsg, QList<int> nOrderList, int status);
    void sigOnGetEmployeeScodeOrder(int nCode, QString sMsg, QString nScode);
    void sigOnEditEmployeeOrder(int nCode, QString sMsg);
};

#endif // EMPLOYEEMANAGECTRL_H
