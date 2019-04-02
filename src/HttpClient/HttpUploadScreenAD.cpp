#include "HttpUploadScreenAD.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../data/constData.h"
#include <QImage>

HttpUploadScreenAD::HttpUploadScreenAD(QString sToken,QString sCorpID, QString sUUID, QString sADPath)
{
    QString sFileSuffix = ".doc";
    QString userParam = QString("&access_token=%1&uuid=%2&file_suffix=%3&hq_code=%4")
            .arg(sToken).arg(sUUID).arg(sFileSuffix).arg(sCorpID);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpUploadScreenAdAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    QByteArray adFileByteArray;
    getADFileByteArray(adFileByteArray, sADPath);
    array.append("&file_info='");
    array.append(adFileByteArray.toBase64());
    array.append("'");
    setReqParams(array);
}

void HttpUploadScreenAD::processResponse(QString strResult)
{
    qDebug()<<strResult;
//    KPosLog::instance()->writeTestLog("111111111111111111111111111");
//    KPosLog::instance()->writeTestLog(strResult); // 测试用
}

void HttpUploadScreenAD::processError()
{
    qDebug()<<"222222222222";
}

void HttpUploadScreenAD::getADFileByteArray(QByteArray &byteArray, QString sADPath)
{
    QFile adFile(sADPath);
    if (adFile.open(QIODevice::ReadOnly))
    {
        byteArray = adFile.readAll();
        if (byteArray.size() == 0)
        {
            // 文件超过1G，readAll会一次性读不出来，暂时不做分段读取的逻辑
            qDebug()<<QStringLiteral("广告文件读取不正常");
        }
        else
        {
            qDebug()<<QString("%1 -- %2").arg(sADPath).arg(byteArray.size());
        }
    }
    else
    {
        // 日志记录
        qDebug()<<QStringLiteral("广告文件打开失败");
    }


//    QFile file(sADPath);
//    file.open(QIODevice::ReadOnly);
//    int file_len = file.size();
//    QDataStream in(&file);
//    char *m_buf = new char[file_len];
//    in.readRawData(m_buf, file_len);
//    file.close();
//    byteArray = QByteArray(m_buf, file_len);
//    delete m_buf;
}
