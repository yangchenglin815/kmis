#ifndef HTTPMEMRECHARGE_H
#define HTTPMEMRECHARGE_H

#include "IHttpReqRes.h"

class HttpMemRecharge : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpMemRecharge
     * @param strCorpID   企业编号
     * @param strMemCardId   卡号
     * @param strRechargeAmt 充值金额
     * @param nPayMethod 支付方式:1.现金，2.会员卡支付，3.储值卡支付，4.支付宝，5.微信支付，6.苹果支付，7.京东钱包，8.优惠券，9.积分抵现
     * @param nOperatorId 操作员id
     * @param strPayCode 付款码
     * @param nOrgzId 门店ID
     */
    explicit HttpMemRecharge(QString strCorpID, QString strUUID, QString strMemCardId, QString strRechargeAmt
                              , int nPayMethod, int nOperatorId, QString strPayCode, int nOrgzId, bool bVirtual);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPMEMRECHARGE_H
