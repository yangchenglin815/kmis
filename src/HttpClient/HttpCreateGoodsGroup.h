#ifndef HTTPCREATEGOODSGROUP_H
#define HTTPCREATEGOODSGROUP_H

#include "IHttpReqRes.h"

class HttpCreateGoodsGroup : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpCreateGoodsGroup
     * @param sCorpID
     * @param sToken
     * @param sUUID
     * @param sGroupName
     */
    explicit HttpCreateGoodsGroup(QString sCorpID, QString sToken, QString sUUID, QString sGroupName);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString m_sGroupName;
};

#endif // HTTPCREATEGOODSGROUP_H
