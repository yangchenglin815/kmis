#ifndef HTTPGETGOODSMANAGELIST_H
#define HTTPGETGOODSMANAGELIST_H

#include "IHttpReqRes.h"

class HttpGetGoodsManageList : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpGetGoodsManageList(QString sToken, int nShopID, QString sCorpID, QString searchPattern, int nLimit, int nOffset
                                    , const QList<int> &categoryIdList, QString sSortBy, QString sSort, int nCategoryBigId, QString sUUID);
protected:
    void processResponse(QString strResult);
    void processError();
private:
    QString createCategoryIdListJson(const QList<int> &categoryIdList);

private:
    int m_nCategoryBigId;
};

#endif // HTTPGETGOODSMANAGELIST_H
