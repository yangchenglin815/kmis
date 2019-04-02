#ifndef HTTPCREATEMEMBERCARDPAYMENT_H
#define HTTPCREATEMEMBERCARDPAYMENT_H

#include "IHttpReqRes.h"

class HttpCreatePayMemberCard : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpCreatePayMemberCard(QString sToken, QString sCorpID, QString sUUID, QString strBarCode, QString strPayAmt, QString strSale
                                     ,int nInteg = 0, QString strPayPwd="" , QString strIntToAmt="0.00");

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPCREATEMEMBERCARDPAYMENT_H
