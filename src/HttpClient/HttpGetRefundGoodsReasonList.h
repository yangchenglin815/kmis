#ifndef HTTPGETREFUNDGOODSREASONLIST_H
#define HTTPGETREFUNDGOODSREASONLIST_H

#include "IHttpReqRes.h"

class HttpGetRefundGoodsReasonList : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpGetRefundGoodsReasonList(QString sToken, QString sCorpID, QString sUUID, bool bIsOnline);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    bool m_bProcessError;
};

#endif // HTTPGETREFUNDGOODSREASONLIST_H
