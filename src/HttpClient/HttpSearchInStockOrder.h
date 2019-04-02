#ifndef HTTPSEARCHINSTOCKORDER_H
#define HTTPSEARCHINSTOCKORDER_H

#include <QObject>
#include "IHttpReqRes.h"

class HttpSearchInStockOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpSearchInStockOrder(QString sToken, QString sCorpID, QString sUUid, int nOrderId, int searchType);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    int m_nSearchType;
    int m_nOrderId;
};

#endif // HTTPSEARCHINSTOCKORDER_H
