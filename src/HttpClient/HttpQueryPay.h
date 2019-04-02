#ifndef HTTPQUERYPAY_H
#define HTTPQUERYPAY_H

#include "IHttpReqRes.h"
#include "enumData.h"

class HttpQueryPay : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpQueryPay
     * @param nPayMethod  支付类型
     * @param strPayOrderNum  内部支付订单号
     */
    explicit HttpQueryPay(QString sToken, QString sCorpID, QString sUUID, int nPayMethod, QString strPayOrderNum );
    ~HttpQueryPay();
protected:
    void processResponse( QString strResult );
    void processError();
private:
    int m_nPayMethod;
    QString m_sPayOrderNum;
};

#endif // HTTPQUERYPAY_H
