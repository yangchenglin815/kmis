#ifndef HTTPCREATPAY_H
#define HTTPCREATPAY_H

#include "IHttpReqRes.h"
#include "enumData.h"

class HttpCreatPay : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpGetPayStatus
     * @param sToken
     * @param ePayMethod  支付方式
     * @param strBarCode  付款码
     * @param strPayAmt   支付金额
     * @param strSale     销售明细
     * @param nInteg      抵现积分
     * @param strPayPwd   支付密码
     * @param strIntToAmt 积分抵现金额
     */
    explicit HttpCreatPay(QString sToken, QString sCorpID, QString sUUID, EPayMethod ePayMethod, QString strBarCode, QString strPayAmt, QString strSale
                          , QString sSaleDetailsJson, int nInteg = 0, QString strPayPwd="" , QString strIntToAmt="0.00");
    ~HttpCreatPay();
protected:
    void processResponse( QString strResult );
    void processError();
private:
    EPayMethod m_ePayMethod;
    QString m_sBarCode;
    QString m_sPayAmt;
    QString m_sSale;

    int m_nInteg;//会员积分
    QString m_sPayPwd;//会员支付密码
    QString m_sIntToAmt;//积分抵现
};

#endif // HTTPCREATPAY_H
