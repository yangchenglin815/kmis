#ifndef HTTPGETBARCODESCALELIST_H
#define HTTPGETBARCODESCALELIST_H

#include "IHttpReqRes.h"

class HttpGetBarcodeScaleList : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpGetBarcodeScaleList(QString sCorpID, QString sToken, QString sUUID);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETBARCODESCALELIST_H
