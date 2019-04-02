#ifndef HTTPSAVEINSTOCKORDER_H
#define HTTPSAVEINSTOCKORDER_H


#include <QObject>

#include "IHttpReqRes.h"
#include "../data/stockdata.h"

class HttpSaveInStockOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpSaveInStockOrder(QString sToken, QString sCorpID, QString sUUID, int nOrderId
                                      , const QList<InStockSelectGoodsInfo>& selectGoodsList);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString createGoodsListJson(const QList<InStockSelectGoodsInfo>& selectGoodsList);
};

#endif // HTTPSAVEINSTOCKORDER_H
