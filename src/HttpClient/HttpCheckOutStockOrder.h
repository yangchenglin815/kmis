#ifndef HTTPCHECKOUTSTOCKORDER_H
#define HTTPCHECKOUTSTOCKORDER_H


#include "IHttpReqRes.h"

class HttpCheckOutStockOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpCheckOutStockOrder(QString sToken, QString sCorpID,QString sUuid, int nOrderId);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPCHECKOutStockORDER_H
