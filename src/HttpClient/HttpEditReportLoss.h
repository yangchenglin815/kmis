#ifndef HTTPEDITREPORTLOSS_H
#define HTTPEDITREPORTLOSS_H

#include "IHttpReqRes.h"
#include "structData.h"

class HttpEditReportLoss : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpEditReportLoss(QString sToken, QString sCorpID, QString sUuid, QList<AddReportLossSelectInfo> infoList, int selectId);
protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPEDITREPORTLOSS_H
