#ifndef HTTPUPLOADSCREENAD_H
#define HTTPUPLOADSCREENAD_H

#include "IHttpReqRes.h"

class HttpUploadScreenAD : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpUploadScreenAD
     * @param sCorpID 企业编号
     * @param sToken 授权标识
     * @param nShopID 门店ID
     * @param sUUID 通用唯一识别码
     * @param sADPath 图片信息
     */
    explicit HttpUploadScreenAD(QString sToken, QString sCorpID, QString sUUID, QString sADPath);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    void getADFileByteArray(QByteArray& byteArray, QString sADPath);
};

#endif // HTTPUPLOADSCREENAD_H
