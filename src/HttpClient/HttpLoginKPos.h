#ifndef HTTPLOGINKPOS_H
#define HTTPLOGINKPOS_H

#include "IHttpReqRes.h"

class HttpLoginKPos : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
        sCorpID -- 公司编码
        sUserName -- 登录用户名
        sPassword -- 登录密码
        sUUID -- 通用唯一识别码
        sAppName -- 应用程序名称
        sAppVersion -- 应用程序版本
        sOSVersion -- 系统版本
        sBranchName -- 终端品牌名称（手机端用）
    */
    HttpLoginKPos(QString sCorpID, QString sUserCode, QString sPassword, QString sUUID,
                  QString sAppName, QString sAppVersion, QString sOSVersion,
                  QString sBranchName = "", bool bUpdateToken = false);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString m_sPassword;
    QString m_sUserCode;
    bool m_bUpdateToken;
};

#endif // HTTPLOGINKPOS_H
