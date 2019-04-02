#ifndef HTTPSAVESTOCKORDER_H
#define HTTPSAVESTOCKORDER_H

#include <QObject>

#include "IHttpReqRes.h"
#include "../data/stockdata.h"

class HttpSaveStockOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpSaveStockOrder(QString sToken, QString sCorpID, QString sUUID, int nOrderId
                                      , const QList<StockSelectGoodsInfo>& selectGoodsList);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString createGoodsListJson(const QList<StockSelectGoodsInfo>& selectGoodsList);
};

#endif // HTTPSAVESTOCKORDER_H
