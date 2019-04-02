#ifndef HTTPCHECKISONLINE_H
#define HTTPCHECKISONLINE_H

#include "IHttpReqRes.h"

class HttpCheckIsOnline : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
        sUUID -- 通用唯一识别码
    */
    HttpCheckIsOnline(QString sToken, QString sCorpID, QString sUUID);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPCHECKISONLINE_H
