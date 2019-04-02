#ifndef HTTPCHECKKPOSUPDATE_H
#define HTTPCHECKKPOSUPDATE_H

#include "IHttpReqRes.h"

class HttpCheckKPosUpdate : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
        sCorpID 企业编号
        sUUID -- 通用唯一识别码
        sAppVersion -- 应用程序版本
    */
    explicit HttpCheckKPosUpdate(QString sCorpID, QString sUUID, QString sAppVersion);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPCHECKKPOSUPDATE_H
