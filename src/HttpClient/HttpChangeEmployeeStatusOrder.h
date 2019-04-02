#ifndef HTTPCHANGEEMPLOYEESTATUSORDER_H
#define HTTPCHANGEEMPLOYEESTATUSORDER_H

#include "IHttpReqRes.h"

class HttpChangeEmployeeStatusOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpChangeEmployeeStatusOrder(QString sToken, QString sCorpID,QString sUuid, QList<int> nOrderIdList, int status);
protected:
    void processResponse(QString strResult);
    void processError();

private:
    QList<int> m_nOrderIdList;
    int m_nStatus;
};

#endif // HTTPCHANGEEMPLOYEESTATUSORDER_H
