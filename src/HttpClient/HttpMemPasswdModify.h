#ifndef HTTPMEMPASSWDMODIFY_H
#define HTTPMEMPASSWDMODIFY_H

#include "IHttpReqRes.h"

class HttpMemPasswdModify : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpMemPasswdModify( QString strCorpId, QString strCardId \
                                  , QString strOldPwd, QString strNewPwd );

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPMEMPASSWDMODIFY_H
