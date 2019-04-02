#ifndef HTTPGETREPORTLOSSDETIAL_H
#define HTTPGETREPORTLOSSDETIAL_H

#include "IHttpReqRes.h"

class HttpGetReportLossDetial : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpGetReportLossDetial(QString sToken, QString sCorpID, QString sUUID, int selectId, int mode);
protected:
    void processResponse(QString strResult);
    void processError();
private:
    int s_mode; // 0:编辑报损单 1:查看明细 2:打印明细
    int m_selectId;
};

#endif // HTTPGETREPORTLOSSDETIAL_H
