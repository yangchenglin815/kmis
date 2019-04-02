#ifndef HTTPDOWNLOADKPOSSET_H
#define HTTPDOWNLOADKPOSSET_H

#include "IHttpReqRes.h"
#include "../data/setstructdata.h"
#include <QScriptValue>

class HttpDownloadKPosSet : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpDownloadKPosSet
     * @param sUUID
     * @param sCorpID
     */
    explicit HttpDownloadKPosSet(QString sToken, QString sUUID, QString sCorpID, QString sLastTime);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    void analysisKPosSet(const QScriptValue& dataValue, KPosSet &kPosSet);
    void analysisGoodSet(const QScriptValue& dataValue, GoodSet& goodSet);
    void analysisKeySet(const QScriptValue& dataValue, KeySet& keySet);
    void analysisParamsSet(const QScriptValue& dataValue, ParamsSet& paramsSet);
    void analysisSystemSetParams(const QScriptValue& sc, SystemSetParams& systemSetParams);
    void analysisShopSetParams(const QScriptValue& sc, ShopSetParams& shopSetParams);
    void analysisPayWaySet(const QScriptValue& dataValue, PayWaySet& payWaySet);
    void analysisVirtualPaySet(const QScriptValue& dataValue, VirtualPaySet& virtualPaySet);
    void analysisPosInfoSet(const QScriptValue& dataValue, PosInfoSet& posInfoSet);
    void analysisScreenSet(const QScriptValue& dataValue, ScreenSet& screenSet);
    void analysisReceipOption(const QScriptValue& dataValue, ReceiptSet& receiptSet);
    void analysisCategoryNodeInfo(const QScriptValue& dataValue, CategoryNodeSet& allCategoryInfoSet);
    void analysisCategoryUnitInfo(const QScriptValue& dataValue, CategoryUnitSet& allCategoryUnitSet);
    void generateCategoryNodeList(const QScriptValue& dataValue,CategoryInfoNode& categoryInfoNode);

};

#endif // HTTPDOWNLOADKPOSSET_H
