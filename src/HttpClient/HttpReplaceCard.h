#ifndef HTTPREPLACECARD_H
#define HTTPREPLACECARD_H

#include "IHttpReqRes.h"

class HttpReplaceCard : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpReplaceCard( QString sCorpCode , QString strOldCardNo, QString strNewCardNo );
protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPREPLACECARD_H
