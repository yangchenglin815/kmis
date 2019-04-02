#ifndef HTTPCHECKREPORTLOSS_H
#define HTTPCHECKREPORTLOSS_H

#include "IHttpReqRes.h"

class HttpCheckReportLoss : public IHttpReqRes
{
public:
    explicit HttpCheckReportLoss(QString sToken, QString sCorpID,QString sUuid, int selectId);
protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPCHECKREPORTLOSS_H
