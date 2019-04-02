#ifndef HTTPDELETECUSTOMCATEGORY_H
#define HTTPDELETECUSTOMCATEGORY_H

#include "IHttpReqRes.h"

class HttpDeleteCustomCategory : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpDeleteCustomCategory
     * @param sCorpID   企业编号
     * @param sToken    授权标识
     * @param nShopID   门店ID
     * @param sUUID     通用唯一识别码
     * @param nCategoryId  自定义大类ID
     */
    explicit HttpDeleteCustomCategory(QString sCorpID, QString sToken, int nShopID, QString sUUID, int nCategoryId);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    int m_nCategoryId;
};

#endif // HTTPDELETECUSTOMCATEGORY_H
