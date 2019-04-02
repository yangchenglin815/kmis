#ifndef HTTPCHECKREGISTERRESULT_H
#define HTTPCHECKREGISTERRESULT_H

#include "IHttpReqRes.h"

class HttpCheckRegisterResult : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
        sUUID -- 通用唯一识别码
    */
    explicit HttpCheckRegisterResult(QString sUUID);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPCHECKREGISTERRESULT_H
