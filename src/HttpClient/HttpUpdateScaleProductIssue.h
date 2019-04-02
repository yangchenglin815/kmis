#ifndef HTTPUPDATESCALEPRODUCTISSUE_H
#define HTTPUPDATESCALEPRODUCTISSUE_H

#include "IHttpReqRes.h"

class HttpUpdateScaleProductIssue : public IHttpReqRes
{
     Q_OBJECT
public:
    explicit HttpUpdateScaleProductIssue(QString sCorpID, QString sToken, QString sUUID , QList<QString> scaleList);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString createScaleListJson(const QList<QString> &scaleList);
};

#endif // HTTPUPDATESCALEPRODUCTISSUE_H
