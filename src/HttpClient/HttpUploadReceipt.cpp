#include "HttpUploadReceipt.h"
#include "../util/CommonFun.h"
#include <QByteArray>
#include <QScriptEngine>
#include "KPosLog.h"
#include "HttpSignal.h"
#include "enumData.h"

HttpUploadReceipt::HttpUploadReceipt( QString sToken, QString sCorpID, QString sUUID, QString strSale )
{
    QString userParam = QString("&hq_code=%1&receipts=%2&access_token=%3&uuid=%4&source=1")
            .arg(sCorpID).arg(strSale.replace("&", " ")).arg(sToken).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpUploadReceiptAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpUploadReceipt::processResponse( QString strResult )
{
    //qDebug()<< strResult;
    //KPosLog::instance()->writeDebugLog( strResult );
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();//状态值
    QString sMsg = sc.property("msg").toString();//返回消息
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpUploadReceipt 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QString strOrderNum = sc.property("data").property("upload_nums").toString();//小票订单号
    QList<QString> strList = strOrderNum.split( "," );
    //for( int i = 0; i < strList.size(); ++i ) {
        HttpSignal::instance()->sigOnUploadReceiptSuc( nCode, sMsg, strList );
    //}
    this->deleteLater();
}

void HttpUploadReceipt::processError()
{
    QList<QString> strList;
    HttpSignal::instance()->sigOnUploadReceiptSuc( e_connectServerError, "", strList );
    this->deleteLater();
}
