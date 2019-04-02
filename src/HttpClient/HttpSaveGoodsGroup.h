#ifndef HTTPSAVEGOODSGROUP_H
#define HTTPSAVEGOODSGROUP_H

#include "IHttpReqRes.h"

class HttpSaveGoodsGroup : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpSaveGoodsGroup(QString sCorpID, QString sToken, QString sUUID, int nGroupId, QList<QString> pluList);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString createPluListJson(const QList<QString> &pluList);
};

#endif // HTTPSAVEGOODSGROUP_H
