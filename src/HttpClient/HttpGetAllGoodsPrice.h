#ifndef HTTPGETALLGOODSPRICE_H
#define HTTPGETALLGOODSPRICE_H

#include "IHttpReqRes.h"

class HttpGetAllGoodsPrice : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpGetAllGoodsPrice
     * @param sToken
     * @param sUUID
     * @param sLastUpdateTime
     */
    explicit HttpGetAllGoodsPrice(QString sUUID, QString sToken, QString sCorpID, QString sLastTime);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETALLGOODSPRICE_H
