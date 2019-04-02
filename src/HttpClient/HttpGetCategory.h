#ifndef HTTPGETCATEGORY_H
#define HTTPGETCATEGORY_H

#include "IHttpReqRes.h"

class HttpGetCategory : public IHttpReqRes
{
    Q_OBJECT
public:

    /**
     * @brief HttpGetCategory
     * @param sUUID
     * @param sCorpID
     * @param sLastTime
     */
    explicit HttpGetCategory(QString sToken, QString sUUID, QString sCorpID, QString sLastTime);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETCATEGORY_H
