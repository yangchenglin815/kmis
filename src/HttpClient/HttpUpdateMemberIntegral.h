#ifndef HTTPUPDATEMEMBERINTEGRAL_H
#define HTTPUPDATEMEMBERINTEGRAL_H

#include "IHttpReqRes.h"

class HttpUpdateMemberIntegral : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpUpdateMemberIntegral
     * @param sCorpID 公司编码
     * @param sToken 授权标识
     * @param sUUID  通用唯一识别码
     * @param fMoney 会员消费实付金额
     * @param sCardNum 会员卡号
     * @param sOrderNum 销售订单号
     */
    explicit HttpUpdateMemberIntegral(QString sCorpID, QString sToken, QString sUUID, float fMoney, QString sCardNum, QString sOrderNum, QString sRefundOrderNum = "");

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString m_sOrderNum;
};

#endif // HTTPUPDATEMEMBERINTEGRAL_H
