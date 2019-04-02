#ifndef HTTPSAVEOUTSTOCKORDER_H
#define HTTPSAVEOUTSTOCKORDER_H


#include <QObject>

#include "IHttpReqRes.h"
#include "../data/stockdata.h"

class HttpSaveOutStockOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpSaveOutStockOrder(QString sToken, QString sCorpID, QString sUUID, int nOrderId
                                      , const QList<OutStockSelectGoodsInfo>& selectGoodsList);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString createGoodsListJson(const QList<OutStockSelectGoodsInfo>& selectGoodsList);
};

#endif // HTTPSAVEOutStockORDER_H
