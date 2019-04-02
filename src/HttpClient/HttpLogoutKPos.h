#ifndef HTTPLOGOUTKPOS_H
#define HTTPLOGOUTKPOS_H

#include "IHttpReqRes.h"

class HttpLogoutKPos : public IHttpReqRes
{
    Q_OBJECT
public:
//    hq_code	String	是	公司编码
//    access_token	String	是	授权标识
//    print_report	Int	是	是否打印报表，0.否；1.是
    explicit HttpLogoutKPos(QString sToken, QString sCorpID, QString sUUID, bool bGetReport);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    bool m_bGetReport;
};

#endif // HTTPLOGOUTKPOS_H
