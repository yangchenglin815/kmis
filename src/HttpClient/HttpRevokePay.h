#ifndef HTTPREVOKEPAY_H
#define HTTPREVOKEPAY_H

#include "IHttpReqRes.h"
#include "enumData.h"
#include <QObject>

class HttpRevokePay : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpRevokePay(QString sToken, QString sCorpID, QString sUUID, EPayMethod ePayMethod, QString strPayOrderNum );
    ~HttpRevokePay();
protected:
    void processResponse( QString strResult );
    void processError();
private:
    EPayMethod m_ePayMethod;
    QString m_sPayOrderNum;
};

#endif // HTTPREVOKEPAY_H
