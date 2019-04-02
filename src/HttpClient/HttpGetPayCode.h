#ifndef HTTPGETPAYCODE_H
#define HTTPGETPAYCODE_H

#include "IHttpReqRes.h"

class HttpGetPayCode : public IHttpReqRes
{
public:
    HttpGetPayCode(QString sCardNum);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETPAYCODE_H
