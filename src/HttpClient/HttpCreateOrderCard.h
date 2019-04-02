#ifndef HTTPCREATEORDERCARD_H
#define HTTPCREATEORDERCARD_H

#include "IHttpReqRes.h"
#include "../data/ordergoodsdata.h"

class HttpCreateOrderCard : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpCreateOrderCard(QString sToken, int nShopID, QString sCorpID, const QList<OrderGoodsInfo *> &orderGoodsInfoList, QString sUUID);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString createOrderGoodsListJson(const QList<OrderGoodsInfo *> &orderGoodsInfoList);
};

#endif // HTTPCREATEORDERCARD_H
