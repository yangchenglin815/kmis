#ifndef HTTPGETOUTSTOCKORDERLIST_H
#define HTTPGETOUTSTOCKORDERLIST_H

#include <QObject>
#include "IHttpReqRes.h"

class HttpGetOutStockOrderList : public IHttpReqRes
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
     * @brief HttpGetOutStockOrderListAction
     * @param sToken
     * @param sCorpID
     * @param sUUID
     * @param sStartDate
     * @param sEndDate
     * @param searchPatter
     * @param nLimit
     * @param nOffset
     */
    HttpGetOutStockOrderList(QString sToken, QString sCorpID,QString sUUID,  QString sStartDate, QString sEndDate
                                , QString searchPatter, int nLimit, int nOffset);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETOutStockORDERLIST_H
