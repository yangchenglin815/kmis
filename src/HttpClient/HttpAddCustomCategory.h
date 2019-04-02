#ifndef HTTPADDCUSTOMCATEGORY_H
#define HTTPADDCUSTOMCATEGORY_H

#include "IHttpReqRes.h"

class HttpAddCustomCategory : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @param sCorpID  企业编号
     * @param sToken   授权标识
     * @param nShopID  门店ID
     * @param sUUID    通用唯一识别码
     * @param sCategoryName  自定义大类名称
     */
    explicit HttpAddCustomCategory(QString sCorpID, QString sToken, int nShopID, QString sUUID, QString sCategoryName, int nPos);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPADDCUSTOMCATEGORY_H
