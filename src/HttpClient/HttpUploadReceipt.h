#ifndef HTTPUPLOADRECEIPT_H
#define HTTPUPLOADRECEIPT_H

#include "IHttpReqRes.h"

class HttpUploadReceipt : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
        sToken -- 授权标识
        strSale -- 小票json字符串
    */
    explicit HttpUploadReceipt(QString sToken, QString sCorpID, QString sUUID, QString strSale );

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPUPLOADRECEIPT_H
