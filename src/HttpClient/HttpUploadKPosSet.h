#ifndef HTTPUPLOADKPOSSET_H
#define HTTPUPLOADKPOSSET_H

#include "IHttpReqRes.h"
#include "../data/setstructdata.h"
#include <QJsonObject>

class HttpUploadKPosSet : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @param sPosCode pos机编号
     * @param sCorpID 企业编号
     * @param sToken 授权标识
     * @param sUUID 通用唯一识别码
     * @param kPosSet Pos设置信息：基础、按键、商品、外显、支付、参数
     * @param bSync 是否同步到其他Pos机：0.不同步，1.同步
     */
    explicit HttpUploadKPosSet(QString sCorpID, QString sToken, QString sUUID, const KPosSet &kPosSet, bool bSync);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QJsonObject createPosInfoSetObjectJson(const PosInfoSet& posInfoSet); // Pos机基础信息
    QJsonObject createKeySetInfoObjectJson(const KeySetInfo& keySetInfo);
    QJsonObject createKeySetObjectJson(const KeySet& keySet); // 按键设置
    QJsonObject createCategoryInfoSetObjectJson(const CategoryInfoSet& categoryInfoSet);
    QJsonObject createGoodSetObjectJson(const GoodSet& goodSet); // 商品设置
    QJsonObject createMovieADObjectJson(const MovieAD& movieAD);
    QJsonObject createScreenSetObjectJson(const ScreenSet& screenSet); // 外显设置
    QJsonObject createPayWayInfoSetObjectJson(const PayWayInfoSet& payWayInfoSet);
    QJsonObject createPayWaySetObjectJson(const PayWaySet& payWaySet); // 支付设置
    QJsonObject createSystemSetParamsObjectJson(const SystemSetParams& systemSetParams);
    QJsonObject createShopSetParamsObjectJson(const ShopSetParams& shopSetParams);
    QJsonObject createParamsSetObjectJson(const ParamsSet& paramsSet); // 参数设置
    QString createKPosSetJson(const KPosSet& kPosSet); // KPos设置的json字符串
};

#endif // HTTPUPLOADKPOSSET_H
