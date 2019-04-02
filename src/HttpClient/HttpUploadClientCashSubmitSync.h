#ifndef HTTPUPLOADCLIENTCASHSUBMITSYNC_H
#define HTTPUPLOADCLIENTCASHSUBMITSYNC_H

#include "IHttpReqRes.h"

class HttpUploadClientCashSubmitSync : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpUploadClientCashSubmitSync
     * @param sCorpID 企业编号
     * @param sShopId 门店id
     * @param sPosCode POS编号
     * @param sSubmitAmount  上交金额
     * @param sUUID 唯一标识符
     * @param sUserCode 收银员编号
     * @param sOperateAt 上机时间
     * @param sLastSubmitAt 上次交款时间
     */
    explicit HttpUploadClientCashSubmitSync(QString sToken,QString sCorpID,QString sSubmitAmount,QString sUUID,QString sOperateAt,
                                            QString sLastSubmitAt,QString sUserCode,QString login_at,QString logout_at ,QString submit_code);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPUPLOADCLIENTCASHSUBMITSYNC_H
