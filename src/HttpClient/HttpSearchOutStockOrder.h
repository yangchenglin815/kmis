#ifndef HTTPSEARCHOUTSTOCKORDER_H
#define HTTPSEARCHOUTSTOCKORDER_H

#include <QObject>
#include "IHttpReqRes.h"

class HttpSearchOutStockOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpSearchOutStockOrder(QString sToken, QString sCorpID, QString sUUid, int nOrderId, int searchType);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    int m_nSearchType;
    int m_nOrderId;
};

#endif // HTTPSEARCHOutStockORDER_H
