#ifndef HTTPMEMSETSTATUS_H
#define HTTPMEMSETSTATUS_H

#include "IHttpReqRes.h"

class HttpMemSetStatus : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpMemSetStatus( QString strCorpId, QString strCardId, int nCardStatus );

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPMEMSETSTATUS_H
