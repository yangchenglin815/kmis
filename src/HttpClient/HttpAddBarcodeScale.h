#ifndef HTTPADDBARCODESCALE_H
#define HTTPADDBARCODESCALE_H

#include "IHttpReqRes.h"

class HttpAddBarcodeScale : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpAddBarcodeScale(QString sCorpID, QString sToken, QString sUUID, QString sCode, QString sType, QString sIp, int nGroupId);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString createBcsInfoJson(QString sCode, QString sType, QString sIp, int nGroupId);
};

#endif // HTTPADDBARCODESCALE_H
