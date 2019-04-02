#ifndef HTTPDELETEREPORTLOSS_H
#define HTTPDELETEREPORTLOSS_H

#include "IHttpReqRes.h"

class HttpDeleteReportLoss : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpDeleteReportLoss(QString sToken, QString sCorpID,QString sUuid, int selectId);
protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPDELETEREPORTLOSS_H
