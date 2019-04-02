#ifndef HTTPCREATEQUICKGOODS_H
#define HTTPCREATEQUICKGOODS_H

#include "IHttpReqRes.h"
#include "structData.h"

class HttpCreateQuickGoods : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpCreateQuickGoods(QString sToken, QString sCorpID, QString sUUID, const ProductInfo &info);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString createInfoJson(const ProductInfo &info);
};

#endif // HTTPCREATEQUICKGOODS_H
