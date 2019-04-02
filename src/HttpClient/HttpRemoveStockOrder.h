#ifndef HTTPREMOVESTOCKORDER_H
#define HTTPREMOVESTOCKORDER_H

#include "IHttpReqRes.h"

class HttpRemoveStockOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpRemoveStockOrder(QString sToken, QString sCorpID, QString sUUID, int nOrderId);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    int m_nOrderId;
};

#endif // HTTPREMOVESTOCKORDERACTION_H
