#ifndef HTTPUPDATECUSTOMCATEGORY_H
#define HTTPUPDATECUSTOMCATEGORY_H

#include "IHttpReqRes.h"

class HttpUpdateCustomCategory : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpUpdateCustomCategory
     * @param sCorpID  企业编号
     * @param sToken   授权标识
     * @param nShopID  门店ID
     * @param sUUID    通用唯一识别码
     * @param nCategoryId    自定义大类ID
     * @param sCategoryName  自定义大类名称
     */
    explicit HttpUpdateCustomCategory(QString sCorpID, QString sToken, int nShopID, QString sUUID, int nCategoryId, QString sCategoryName);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPUPDATECUSTOMCATEGORY_H
