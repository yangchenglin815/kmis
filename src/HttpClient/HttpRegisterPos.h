#ifndef HTTPREGISTERPOS_H
#define HTTPREGISTERPOS_H

#include "IHttpReqRes.h"

class HttpRegisterPos : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
        sCorpCode -- 企业编号
        sShopCode -- 门店编号
        sUUID -- 通用唯一识别码
        sBrandName -- 终端品牌名称
    */
    explicit HttpRegisterPos(QString sCorpCode, QString sShopCode, QString sUUID);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPREGISTERPOS_H
