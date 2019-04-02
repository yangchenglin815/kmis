#ifndef HTTPSAVERECEIVEGOODS_H
#define HTTPSAVERECEIVEGOODS_H

#include "IHttpReqRes.h"
#include "../data/recievinggoodsdata.h"

class HttpSaveReceiveGoods : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpSaveReceiveGoods
     * @param sToken  授权标识
     * @param nDeliveryGoodId 送货单明细ID
     */
    explicit HttpSaveReceiveGoods(QString sToken, const ReceiveGoodsDetail_s &receiveGoodsDetail, int nDeliverGoodId);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPSAVERECEIVEGOODS_H
