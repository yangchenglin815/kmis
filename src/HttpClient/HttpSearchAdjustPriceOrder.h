#ifndef HTTPSEARCHADJUSTPRICEORDER_H
#define HTTPSEARCHADJUSTPRICEORDER_H

#include "IHttpReqRes.h"

class HttpSearchAdjustPriceOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpSearchAdjustPriceOrder(QString sToken, QString sCorpID, QString sUUID, int nOrderId, int searchType);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    int m_nSearchType;
    int m_nOrderId;
};

#endif // HTTPSEARCHADJUSTPRICEORDER_H
