#ifndef HTTPCHECKSTOCKORDER_H
#define HTTPCHECKSTOCKORDERA_H

#include "IHttpReqRes.h"

class HttpCheckStockOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpCheckStockOrder(QString sToken, QString sCorpID, QString sUUID, int nOrderId);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPCHECKSTOCKORDER_H
