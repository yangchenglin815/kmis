#ifndef HTTPCHECKADJUSTPRICEORDER_H
#define HTTPCHECKADJUSTPRICEORDER_H

#include "IHttpReqRes.h"

class HttpCheckAdjustPriceOrder : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpCheckAdjustPriceOrder
     * @param sToken
     * @param sCorpID
     * @param nOrderId
     */
    explicit HttpCheckAdjustPriceOrder(QString sToken, QString sCorpID, QString sUUID, int nOrderId);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    int m_nOrderId;
};

#endif // HTTPCHECKADJUSTPRICEORDER_H
