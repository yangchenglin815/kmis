#ifndef HTTPGETADJUSTPRICEORDERLIST_H
#define HTTPGETADJUSTPRICEORDERLIST_H

#include "IHttpReqRes.h"

class HttpGetAdjustPriceOrderList : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpGetAdjustPriceOrderList
     * @param sToken
     * @param sCorpID
     * @param sStartDate   筛选起始日期，默认null为7天
     * @param sEndDate     筛选截止日期，默认null为7天
     * @param searchPatter
     * @param nLimit
     * @param nOffset
     */
    explicit HttpGetAdjustPriceOrderList(QString sToken, QString sCorpID, QString sUUID, QString sStartDate, QString sEndDate
                                         , QString searchPatter, int nLimit, int nOffset);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETADJUSTPRICEORDERLIST_H
