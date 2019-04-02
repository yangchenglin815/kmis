#ifndef HTTPGETSHOPINFO_H
#define HTTPGETSHOPINFO_H

#include "IHttpReqRes.h"

class HttpGetShopInfo : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
        sCorpCode -- 企业编号
        nShopCode -- 门店编号
    */
    explicit HttpGetShopInfo(QString sUUID, QString sCorpCode, QString sShopCode);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETSHOPINFO_H
