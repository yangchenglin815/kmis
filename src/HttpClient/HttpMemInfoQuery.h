#ifndef HTTPMEMINFOQUERY_H
#define HTTPMEMINFOQUERY_H

#include "IHttpReqRes.h"

class HttpMemInfoQuery : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpMemInfoQuery( QString sCorpID, QString strUUID, QString strMemCardId, bool bForRefund);

protected:
    void processResponse(QString strResult);
    void processError();
private:
    QString m_sMemCardId;
    bool m_bForRefund;
};

#endif // HTTPMEMINFOQUERY_H
