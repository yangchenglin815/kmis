#ifndef HTTPDELETESCALE_H
#define HTTPDELETESCALE_H

#include "IHttpReqRes.h"

class HttpDeleteScale : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpDeleteScale(QString sCorpID, QString sToken, QString sUUID, QString scaleId);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString m_nScaleId;
};

#endif // HTTPDELETESCALE_H
