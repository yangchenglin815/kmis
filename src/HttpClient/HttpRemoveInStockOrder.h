#ifndef HTTPREMOVEINSTOCKORDER_H
#define HTTPREMOVEINSTOCKORDER_H

#include "IHttpReqRes.h"

class HttpRemoveInStockOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpRemoveInStockOrder(QString sToken, QString sCorpID,QString sUuid, int nOrderId);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    int m_nOrderId;
};

#endif // HTTPREMOVEINSTOCKORDER_H
