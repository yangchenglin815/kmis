#ifndef HTTPREMOVEOUTSTOCKORDER_H
#define HTTPREMOVEOUTSTOCKORDER_H
#include "IHttpReqRes.h"

class HttpRemoveOutStockOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpRemoveOutStockOrder(QString sToken, QString sCorpID,QString sUuid, int nOrderId);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    int m_nOrderId;
};

#endif // HTTPREMOVEOutStockORDER_H
