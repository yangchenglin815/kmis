#include "KPosIni.h"
#include <QSettings>
#include <QFile>
#include <QDate>
#include "FilePathManage.h"
#include "../data/constData.h"
#include "KPosServerIni.h"

QString sKPosIniPath = FilePathManage::instance()->getKPosIniPath() + "KPos.ini";

int KPosIni::getRegistResult()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    return settings.value("checkRegistState/registResult", -1).toInt();
}

void KPosIni::setRegistResult(int nRegistResult)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.setValue("checkRegistState/registResult", nRegistResult);
}

QString KPosIni::getAppKey()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    return settings.value("checkRegistState/appKey", "20160918000001").toString();
}

void KPosIni::setAppKey(QString sAppKey)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.setValue("checkRegistState/appKey", sAppKey);
}

QString KPosIni::getAppSecret()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    return settings.value("checkRegistState/appSecret", "E44DA6E95045B7712FE40362F3CF2D16").toString();
}

void KPosIni::setAppSecret(QString sAppSecret)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.setValue("checkRegistState/appSecret", sAppSecret);
}

QString KPosIni::getCorpID()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    return settings.value("checkRegistState/corpID", "").toString();
}

void KPosIni::setCorpID(QString sCorpID)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.setValue("checkRegistState/corpID", sCorpID);
}

QString KPosIni::getPosCode()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    return settings.value("loginKPos/posCode", "").toString();
}

void KPosIni::setPosCode(QString sPosCode)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.setValue("loginKPos/posCode", sPosCode);
}

QString KPosIni::getCorpName()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    return settings.value("loginKPos/corpName", "").toString();
}

void KPosIni::setCorpName(QString corpName)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.setValue("loginKPos/corpName", corpName);
}

int KPosIni::getShopId()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    return settings.value("loginKPos/shopId", -1).toInt();
}

void KPosIni::setShopId( int nShopId )
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.setValue("loginKPos/shopId", nShopId );
}

QString KPosIni::getShopName()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    return settings.value("loginKPos/shopName", "").toString();
}

void KPosIni::setShopName(QString sShopName)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.setValue("loginKPos/shopName", sShopName);
}

QString KPosIni::getShopCode()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    return settings.value("loginKPos/shopCode", "").toString();
}

void KPosIni::setShopCode(QString shopCode)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.setValue("loginKPos/shopCode", shopCode);
}

float KPosIni::getPurseRemain()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    return settings.value("purse/purseRemain", "0.0").toFloat();
}

void KPosIni::setPurseRemain(float purseRemain)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.setValue("purse/purseRemain", purseRemain);
}

QString KPosIni::getSerialNum()
{
    int SequenceMod = KPosServerIni::getSequenceMod();
    QString strSerialNum;
    if(SequenceMod == 0){
        QSettings settings(sKPosIniPath, QSettings::IniFormat);
        settings.setIniCodec("UTF-8");
        int serialNum = settings.value("saleHead/serialNum", 1).toInt();

        QString newSerialNumDate = QDate::currentDate().toString("yyyyMMdd");
        QString SerialNumDate = getSerialNumDate();
        int nSerialNum = serialNum + 1;
        if(SerialNumDate != newSerialNumDate || nSerialNum >= 100000){
            serialNum = 0;
            nSerialNum = serialNum + 1;
        }

        setSerialNumDate(newSerialNumDate);
        setSerialNum( nSerialNum );

        strSerialNum = QString("%1").arg(nSerialNum,5,10,QLatin1Char('0'));
    }
    else if(SequenceMod == 1)
    {
        strSerialNum = QDateTime::currentDateTime().toString( "hhmmss" );
    }


    return strSerialNum;

}

void KPosIni::setSerialNum( int nSerialNum )
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.setValue("saleHead/serialNum", nSerialNum);
}

QString KPosIni::getSerialNumDate()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    return settings.value("saleHead/serialNumDate", QDate::currentDate().toString("yyyyMMdd")).toString();
}

void KPosIni::setSerialNumDate(QString sSerialNumDate)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setValue("saleHead/serialNumDate", sSerialNumDate);
}

QString KPosIni::getUserName()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    return settings.value("UserInfo/UserName", "").toString();
}

void KPosIni::setUserName( QString sUserName )
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setValue("UserInfo/UserName", sUserName );
}

QString KPosIni::getLoginId()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    return settings.value("UserInfo/LoginId", "").toString();
}

void KPosIni::setLoginId(int nLoginId)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setValue("UserInfo/LoginId", nLoginId );
}

QString KPosIni::getUserCode()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    return settings.value("UserInfo/UserCode", "").toString();
}

void KPosIni::setUserCode( QString sUserCode )
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setValue("UserInfo/UserCode", sUserCode );
}

QString KPosIni::getPassword()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    return settings.value("UserInfo/UserPasswd", "").toString();
}

void KPosIni::setPassword( QString sPassword )
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setValue("UserInfo/UserPasswd", sPassword );
}


QString KPosIni::getLastHandPurseTime()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    return settings.value("UserInfo/lastHandPurseTime", "").toString();
}

void KPosIni::setLastHandPurseTime(QString lastHandPurseTime)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.setValue("UserInfo/lastHandPurseTime", lastHandPurseTime);
}

int KPosIni::getCloseAppStatus()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    return settings.value("App/CloseAppStatus", 1).toInt();
}

void KPosIni::setCloseAppStatus( int nCloseAppStatus )
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setValue("App/CloseAppStatus", nCloseAppStatus );
}

QString KPosIni::getCategoryLastUpdateTime()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    return settings.value("LastUpdateTime/category", "").toString();
}

void KPosIni::setCategoryLastUpdateTime(QString sLastTime)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setValue("LastUpdateTime/category", sLastTime);
}

QString KPosIni::getGoodsLastUpdateTime()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    return settings.value("LastUpdateTime/goods", "").toString();
}

void KPosIni::setGoodsLastUpdateTime(QString sLastTime)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setValue("LastUpdateTime/goods", sLastTime);
}

QString KPosIni::getGoodsPriceLastUpdateTime()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    return settings.value("LastUpdateTime/goodsPrice", "").toString();
}

void KPosIni::setGoodsPriceLastUpdateTime(QString sLastTime)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setValue("LastUpdateTime/goodsPrice", sLastTime);
}

QString KPosIni::getKPosSetLastUpdateTime()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    return settings.value("LastUpdateTime/KPosSet", "").toString();
}

void KPosIni::setKPosSetLastUpdateTime(QString sLastTime)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setValue("LastUpdateTime/KPosSet", sLastTime);
}

QString KPosIni::getReceiptShopName()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    QString str = settings.value("Receipt/shopName", "").toString();
    if (str.isEmpty())
    {
        str = getShopName();
    }
    return str;
}

void KPosIni::setReceiptShopName(QString sShopName)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setValue("Receipt/shopName", sShopName);
}

QString KPosIni::getRefundGoodsReasonJson()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    return settings.value("localJson/refundGoodsReasonJson", "").toString();
}

void KPosIni::setRefundGoodsReasonJosn(QString sReasonJson)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setValue("localJson/refundGoodsReasonJson", sReasonJson);
}

void KPosIni::setLoginTime(QString sLoginTime)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setValue("UserInfo/loginTime", sLoginTime);
}

QString KPosIni::getLoginTime()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    return settings.value("UserInfo/loginTime", "").toString();
}

void KPosIni::setRemoteADPathList(const QList<QString> &remoteADList)
{
    int nLen = remoteADList.length();
    QString strs = "";
    for (int i = 0; i < nLen - 1; i++)
    {
        strs.append(QString("%1;").arg(remoteADList[i]));
    }
    if (nLen - 1 >= 0)
    {
        strs.append(remoteADList[nLen-1]);
    }
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setValue("ADPaths/remote", strs);
}

QList<QString> KPosIni::getRemoteADPathList()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    QString strs = settings.value("ADPaths/remote", "").toString();
    return strs.split(";");
}

void KPosIni::DelIniFile()
{
    QFile f;
    f.remove( sKPosIniPath );
}

bool KPosIni::getSetGuide()
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    return settings.value("loginKPos/setGuideFlag", true).toBool();
}

void KPosIni::setSetGuide(bool nflag)
{
    QSettings settings(sKPosIniPath, QSettings::IniFormat);
    settings.setValue("loginKPos/setGuideFlag", nflag);
}
