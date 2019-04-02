#ifndef HTTPGETSTOCKORDERLIST_H
#define HTTPGETSTOCKORDERLIST_H

#include "IHttpReqRes.h"

class HttpGetStockOrderList : public IHttpReqRes
{
    Q_OBJECT
public:

//    hq_code	String
//    access_token	String
//    start_date	date
//    end_date	date
//    limit	int
//    offset	int
//    search_pattern	stirng

    /**
     * @brief HttpGetStockOrderListAction
     * @param sToken
     * @param sCorpID
     * @param sStartDate
     * @param sEndDate
     * @param searchPatter
     * @param nLimit
     * @param nOffset
     */
    HttpGetStockOrderList(QString sToken, QString sCorpID, QString sUUID, QString sStartDate, QString sEndDate
                                , QString searchPatter, int nLimit, int nOffset);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETSTOCKORDERLIST_H
