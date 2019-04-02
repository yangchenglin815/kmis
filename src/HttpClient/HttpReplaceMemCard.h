#ifndef HTTPREPLACEMEMCARD_H
#define HTTPREPLACEMEMCARD_H

#include "IHttpReqRes.h"

class HttpReplaceMemCard : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpReplaceMemCard( QString strCorpId, QString strOldCardId, QString strNewCardId, QString strUserName );
protected:
    void processResponse(QString strResult);
    void processError();
private:
    QString m_sOldCardId;
    QString m_sNewCardId;
};

#endif // HTTPREPLACEMEMCARD_H
