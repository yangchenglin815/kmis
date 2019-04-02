#ifndef HTTPGETINSTOCKORDERLIST_H
#define HTTPGETINSTOCKORDERLIST_H

#include <QObject>
#include "IHttpReqRes.h"

class HttpGetInStockOrderList : public IHttpReqRes
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
     * @brief HttpGetInStockOrderListAction
     * @param sToken
     * @param sCorpID
     * @param sUUID
     * @param sStartDate
     * @param sEndDate
     * @param searchPatter
     * @param nLimit
     * @param nOffset
     */
    HttpGetInStockOrderList(QString sToken, QString sCorpID,QString sUUID,  QString sStartDate, QString sEndDate
                                , QString searchPatter, int nLimit, int nOffset);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETINSTOCKORDERLIST_H
