#ifndef HTTPGETALLUSERINFO_H
#define HTTPGETALLUSERINFO_H

#include "IHttpReqRes.h"
#include "httpstructdata.h"

class HttpGetAllUserInfo : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpGetAllUserInfo(QString sToken, QString sCorpID, QString sUUID);

protected:
    void processResponse( QString strResult );
    void processError();
private:

};

#endif // HTTPGETALLUSERINFO_H
