#ifndef HTTPGETGOODSGROUPLIST_H
#define HTTPGETGOODSGROUPLIST_H

#include "IHttpReqRes.h"

class HttpGetGoodsGroupList : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpGetGoodsGroupList
     * @param sCorpID
     * @param sToken
     * @param sUUID
     */
    explicit HttpGetGoodsGroupList(QString sCorpID, QString sToken, QString sUUID);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETGOODSGROUPLIST_H
