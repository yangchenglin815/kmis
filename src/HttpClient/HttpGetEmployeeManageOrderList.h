#ifndef HTTPGETEMPLOYEEMANAGEORDERLIST_H
#define HTTPGETEMPLOYEEMANAGEORDERLIST_H

#include <QObject>
#include "IHttpReqRes.h"

class HttpGetEmployeeManageOrderList : public IHttpReqRes
{
    Q_OBJECT
public:
    HttpGetEmployeeManageOrderList(QString sToken, QString sCorpID,QString sUUID, QString searchPatter, int nLimit, int nOffset);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETEMPLOYEEMANAGEORDERLIST_H
