#ifndef HTTPRECEIVEGOODSEND_H
#define HTTPRECEIVEGOODSEND_H

#include "IHttpReqRes.h"

class HttpReceiveGoodsEnd : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpReceiveGoodsEnd
     * @param sToken
     * @param nDeliveryId
     */
    explicit HttpReceiveGoodsEnd(QString sToken, int nDeliveryId);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPRECEIVEGOODSEND_H
