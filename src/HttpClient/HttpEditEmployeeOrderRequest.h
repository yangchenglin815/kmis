#ifndef HTTPEDITEMPLOYEEORDERREQUEST_H
#define HTTPEDITEMPLOYEEORDERREQUEST_H

#include "IHttpReqRes.h"
#include "httpstructdata.h"

class HttpEditEmployeeOrderRequest : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpEditEmployeeOrderRequest(QString sToken, QString sCorpID,QString sUuid, AccountInfo info, int status);
protected:
    void processResponse(QString strResult);
    void processError();
private:
    AccountInfo m_info;
    int m_status;
};

#endif // HTTPEDITEMPLOYEEORDERREQUEST_H
