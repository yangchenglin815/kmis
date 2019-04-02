#ifndef HTTPREMOVEADJUSTPRICEORDER_H
#define HTTPREMOVEADJUSTPRICEORDER_H

#include "IHttpReqRes.h"

class HttpRemoveAdjustPriceOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpRemoveAdjustPriceOrder(QString sToken, QString sCorpID, QString sUUID, int nOrderId);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    int m_nOrderId;
};

#endif // HTTPREMOVEADJUSTPRICEORDER_H
