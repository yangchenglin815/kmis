#ifndef HTTPGETRECEIVEGOODSDETAIL_H
#define HTTPGETRECEIVEGOODSDETAIL_H

#include "IHttpReqRes.h"

class HttpGetReceiveGoodsDetail : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpGetReceiveGoodsDetail
     * @param sToken  授权标识
     * @param nDeliveryGoodId 送货单明细ID
     */
    explicit HttpGetReceiveGoodsDetail(QString sToken, int nDeliveryGoodId);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    int m_nDeliveryGoodId;
};

#endif // HTTPGETRECEIVEGOODSDETAIL_H
