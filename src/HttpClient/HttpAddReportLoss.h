#ifndef HTTPADDREPORTLOSS_H
#define HTTPADDREPORTLOSS_H

#include "IHttpReqRes.h"
#include "structData.h"

class HttpAddReportLoss : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpAddReportLoss(QString sToken, QString sCorpID,QString sUuid, QList<AddReportLossSelectInfo> infoList);
protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPADDREPORTLOSS_H
