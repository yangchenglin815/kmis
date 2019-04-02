#ifndef HTTPGETORDERCARDLISTDETAIL_H
#define HTTPGETORDERCARDLISTDETAIL_H

#include "IHttpReqRes.h"

class HttpGetOrderCardListDetail : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpGetOrderCardListDetail
     * @param sToken  授权标识
     * @param orderCardIdList 要货卡ID列表
     */
    explicit HttpGetOrderCardListDetail(QString sToken, QString sCorpID, QString sUUID, const QList<int>& orderCardIdList, bool bUploadFinish);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString createOrderIdListJson(const QList<int>& orderCardIdList);

private:
    bool m_bUploadFinish;
    QList<int> m_orderCardIdList;
};

#endif // HTTPGETORDERCARDLISTDETAIL_H
