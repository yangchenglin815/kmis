#ifndef HTTPGETMEMGRADELIST_H
#define HTTPGETMEMGRADELIST_H

#include "IHttpReqRes.h"

class HttpGetMemGradeList : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpGetMemGradeList( int nMemTypeId );
protected:
    void processResponse( QString strResult );
    void processError();
};

#endif // HTTPGETMEMGRADELIST_H
