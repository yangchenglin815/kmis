#ifndef HTTPSEARCHRECEIPT_H
#define HTTPSEARCHRECEIPT_H

#include "IHttpReqRes.h"

class HttpSearchReceipt : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpSearchReceipt(QString sToken, QString sCorpID, QString sUUID, QString sOrderNum, bool isSaleDetial);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString m_sOrderNum;
    bool m_isSaleDetial;
};

#endif // HTTPSEARCHRECEIPT_H
