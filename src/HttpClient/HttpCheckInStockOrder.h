#ifndef HTTPCHECKINSTOCKORDER_H
#define HTTPCHECKINSTOCKORDER_H


#include "IHttpReqRes.h"

class HttpCheckInStockOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpCheckInStockOrder(QString sToken, QString sCorpID,QString sUuid, int nOrderId);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPCHECKINSTOCKORDER_H
