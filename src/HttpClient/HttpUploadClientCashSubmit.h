#ifndef HTTPUPLOADCLIENTCASHSUBMIT_H
#define HTTPUPLOADCLIENTCASHSUBMIT_H

#include "IHttpReqRes.h"

class HttpUploadClientCashSubmit : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpUploadClientCashSubmit
     * @param sCorpID 企业编号
     * @param sShopId 门店id
     * @param sPosCode POS编号
     * @param sSubmitAmount  上交金额
     * @param sUUID 唯一标识符
     * @param sUserCode 收银员编号
     * @param sOperateAt 上机时间
     * @param sLastSubmitAt 上次交款时间
     * @param sLoginId 登录id
     * @param sSubmitCode 交款流水号
     */
    explicit HttpUploadClientCashSubmit(QString sToken,QString sCorpID,QString sSubmitAmount,QString sUUID, QString sOperateAt,
                                        QString sLastSubmitAt,QString sUserCode,QString sLoginId,QString sSubmitCode);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPUPLOADCLIENTCASHSUBMIT_H
