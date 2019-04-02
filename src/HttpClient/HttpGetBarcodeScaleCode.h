#ifndef HTTPGETBARCODESCALECODE_H
#define HTTPGETBARCODESCALECODE_H

#include "IHttpReqRes.h"

class HttpGetBarcodeScaleCode : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpGetBarcodeScaleCode(QString sCorpID, QString sToken, QString sUUID);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETBARCODESCALECODE_H
