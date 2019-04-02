#ifndef HTTPGETEMPLOYEESCODEORDER_H
#define HTTPGETEMPLOYEESCODEORDER_H

#include "IHttpReqRes.h"

class HttpGetEmployeeScodeOrder : public IHttpReqRes
{
    Q_OBJECT
public:
     explicit HttpGetEmployeeScodeOrder(QString sToken, QString sCorpID,QString sUuid);
protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETEMPLOYEESCODEORDER_H
