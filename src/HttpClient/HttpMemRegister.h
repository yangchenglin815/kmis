#ifndef HTTPMEMREGISTER_H
#define HTTPMEMREGISTER_H

#include "IHttpReqRes.h"
#include "httpstructdata.h"

class HttpMemRegister : public IHttpReqRes
{
    Q_OBJECT
public:
    explicit HttpMemRegister( QString strCorpId, MemRegisterInfo_s stMemRegister, int nShopId );

protected:
    void processResponse(QString strResult);
    void processError();
private:
    MemRegisterInfo_s m_stMemRegisterInfo;
};

#endif // HTTPMEMREGISTER_H
