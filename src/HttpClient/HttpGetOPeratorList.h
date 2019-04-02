#ifndef HTTPGETOPERATORLIST_H
#define HTTPGETOPERATORLIST_H

#include "IHttpReqRes.h"

class HttpGetOPeratorList : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpGetOPeratorList( QString sCorpCode, int nShopID );
protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETOPERATORLIST_H
