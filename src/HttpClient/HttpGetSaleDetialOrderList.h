#ifndef HTTPGETSALEDETIALORDERLIST_H
#define HTTPGETSALEDETIALORDERLIST_H
#include "IHttpReqRes.h"
#include "receiptdata.h"

class HttpGetSaleDetialOrderList : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpGetSaleDetialOrderList(QString sToken, QString sCropID, QString sUuid);
protected:
    void processResponse(QString strResult);
    void processError();
private:
    QList<ReceiptInfo> m_InfoList;
};

#endif // HTTPGETSALEDETIALORDERLIST_H
