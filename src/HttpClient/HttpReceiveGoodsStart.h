#ifndef HTTPRECEIVEGOODSSTART_H
#define HTTPRECEIVEGOODSSTART_H

#include "IHttpReqRes.h"

class HttpReceiveGoodsStart : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpReceiveGoodsStart
     * @param sToken 授权标识
     * @param nDeliveryId 送货单ID
     */
    explicit HttpReceiveGoodsStart(QString sToken, int nDeliveryId);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    int m_nDeliveryId;
};

#endif // HTTPRECEIVEGOODSSTART_H
