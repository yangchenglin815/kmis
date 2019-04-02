#ifndef HTTPSEARCHSTOCKORDER_H
#define HTTPSEARCHSTOCKORDER_H

#include "IHttpReqRes.h"

class HttpSearchStockOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpSearchStockOrder(QString sToken, QString sUUID, QString sCorpID, int nOrderId, int searchType);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    int m_nSearchType;
    int m_nOrderId;
};

#endif // HTTPSEARCHSTOCKORDER_H
