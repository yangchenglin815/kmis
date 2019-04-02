#ifndef HTTPGETGOODSCODE_H
#define HTTPGETGOODSCODE_H

#include "IHttpReqRes.h"

class HttpGetQuickGoodsInfo : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpGetQuickGoodsInfo(QString sToken, QString sCorpID, QString sUUID, QString sBigCategoryCode);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString m_sBigCategoryCode;
};

#endif // HTTPGETGOODSCODE_H
