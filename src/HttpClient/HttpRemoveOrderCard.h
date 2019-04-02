#ifndef HTTPREMOVEORDERCARD_H
#define HTTPREMOVEORDERCARD_H

#include "IHttpReqRes.h"

class HttpRemoveOrderCard : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpRemoveOrderCard(QString sToken, QString sCorpID, QString sUUID, const QList<int>& orderIdList);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString createOrderIdListJson(const QList<int>& orderIdList);
};

#endif // HTTPREMOVEORDERCARD_H
