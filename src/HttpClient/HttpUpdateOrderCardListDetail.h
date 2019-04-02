#ifndef HTTPUPDATEORDERCARDLISTDETAIL_H
#define HTTPUPDATEORDERCARDLISTDETAIL_H

#include "IHttpReqRes.h"

class HttpUpdateOrderCardListDetail : public IHttpReqRes
{
    Q_OBJECT

public:
    /**
     * @brief HttpUpdateOrderCardListDetatil
     * @param sToken 授权标识
     * @param changedNumMap 商品ID,要货件数的map
     * @param orderCardIdList 要货卡ID列表
     */
    explicit HttpUpdateOrderCardListDetail(QString sToken, QString sCorpID, QString sUUID, const QMap<int, int>& changedNumMap, const QList<int>& orderCardIdList);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString createChangedNumMapJson(const QMap<int, int>& changedNumMap);
    QString createOrderCardIdListJson(const QList<int>& orderCardIdList);

};

#endif // HTTPUPDATEORDERCARDLISTDETAIL_H
