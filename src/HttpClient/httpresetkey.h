#ifndef HTTPRESETKEY_H
#define HTTPRESETKEY_H
#include "IHttpReqRes.h"

class HttpResetKey: public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpResetKey(QString sCorpID, QString sToken, QString sUUID, QString oldkey, QString newkey);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString m_nScaleId;
};

#endif // HTTPRESETKEY_H
