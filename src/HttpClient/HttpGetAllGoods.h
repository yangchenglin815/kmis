#ifndef HTTPGETALLGOODS_H
#define HTTPGETALLGOODS_H

#include "IHttpReqRes.h"

class HttpGetAllGoods : public IHttpReqRes
{
    Q_OBJECT

public:

    /**
     * @brief HttpGetAllGoods
     * @param sUUID
     * @param sCorpID
     * @param sLastTime
     */
    explicit HttpGetAllGoods(QString sToken, QString sUUID, QString sCorpID, QString sLastTime);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETALLGOODS_H
