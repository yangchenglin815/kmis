#ifndef HTTPGETDELIVERYDETAIL_H
#define HTTPGETDELIVERYDETAIL_H

#include "IHttpReqRes.h"

class HttpGetDeliveryDetail : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpGetDeliveryDetail
     * @param sToken  授权标识
     * @param nDeliveryId  送货单ID
     */
    explicit HttpGetDeliveryDetail(QString sToken, int nDeliveryId);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    int m_nDeliveryId;
};

#endif // HTTPGETDELIVERYDETAIL_H
