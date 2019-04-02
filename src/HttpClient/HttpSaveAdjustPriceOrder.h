#ifndef HTTPSAVEADJUSTPRICEORDER_H
#define HTTPSAVEADJUSTPRICEORDER_H

#include "IHttpReqRes.h"
#include "../data/adjustpricedata.h"

class HttpSaveAdjustPriceOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpSaveAdjustPriceOrder(QString sToken, QString sCorpID, QString sUUID, int nOrderId
                                      , const QList<AdjustPriceSelectGoodsInfo>& selectGoodsList);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString createGoodsListJson(const QList<AdjustPriceSelectGoodsInfo>& selectGoodsList);
};

#endif // HTTPSAVEADJUSTPRICEORDER_H
