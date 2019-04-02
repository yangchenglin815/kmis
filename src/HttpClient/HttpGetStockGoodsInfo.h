#ifndef HTTPGETSTOCKGOODSINFO_H
#define HTTPGETSTOCKGOODSINFO_H

#include "IHttpReqRes.h"

class HttpGetStockGoodsInfo : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpGetStockGoodsInfo
     * @param sToken
     * @param sCorpID
     * @param nGoodsId
     */
    explicit HttpGetStockGoodsInfo(QString sToken, QString sCorpID, QString sUUID, int nGoodsId);
    QString markNum="";

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETSTOCKGOODSINFO_H
