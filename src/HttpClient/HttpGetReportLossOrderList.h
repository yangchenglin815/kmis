#ifndef HTTPGETREPORTLOSSORDERLIST_H
#define HTTPGETREPORTLOSSORDERLIST_H

#include "IHttpReqRes.h"

class HttpGetReportLossOrderList : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpGetReportLossOrderList(QString sToken, QString sCorpID, QString sUUID, QString sStartDate, QString sEndDate
                                        , QString searchPatter, int nLimit, int nOffset);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETREPORTLOSSORDERLIST_H
