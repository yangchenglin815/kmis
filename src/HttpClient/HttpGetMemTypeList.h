#ifndef HTTPGETMEMTYPELIST_H
#define HTTPGETMEMTYPELIST_H

#include "IHttpReqRes.h"

class HttpGetMemTypeList : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpGetMemTypeList();
protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETMEMTYPELIST_H
