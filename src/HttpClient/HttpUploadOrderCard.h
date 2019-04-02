#ifndef HTTPUPLOADORDERCARD_H
#define HTTPUPLOADORDERCARD_H

#include "IHttpReqRes.h"

class HttpUploadOrderCard : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpUploadOrderCard
     * @param sToken
     * @param orderCardIdList
     */
    explicit HttpUploadOrderCard(QString sToken, QString sCorpID, QString sUUID, const QList<int>& orderCardIdList);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString createOrderIdListJson(const QList<int>& orderCardIdList);

private:
    QList<int> m_orderCardIdList;
};

#endif // HTTPUPLOADORDERCARD_H
