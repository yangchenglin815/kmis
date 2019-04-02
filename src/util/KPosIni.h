#ifndef KPOSINI_H
#define KPOSINI_H

#include <QString>

class KPosIni
{
public:
    static int getRegistResult(); // 是否注册审核通过
    static void setRegistResult(int nRegistResult);
    static QString getAppKey(); // 企业授权标识
    static void setAppKey(QString sAppKey);
    static QString getAppSecret(); // 企业认证密匙
    static void setAppSecret(QString sAppSecret);
    static QString getCorpID(); // 企业编号
    static void setCorpID(QString sCorpID);
    static QString getPosCode(); // 款机号
    static void setPosCode(QString sPosCode);
    static QString getCorpName(); // 企业名称
    static void setCorpName(QString corpName);
    static int getShopId();
    static void setShopId( int nShopId );
    static QString getShopName(); // 门店名称
    static void setShopName(QString sShopName);
    static QString getShopCode(); // 门店编号
    static void setShopCode(QString shopCode); //
    static float getPurseRemain(); // 钱包剩余
    static void setPurseRemain(float purseRemain);
    static QString getLastHandPurseTime();//上次交款时间
    static void setLastHandPurseTime(QString lastHandPurseTime);
    static QString getSerialNum();//销售流水号
    static void setSerialNum( int nSerialNum );
    static QString getSerialNumDate();//生成销售流水号日期
    static void setSerialNumDate(QString sSerialNumDate);
    static QString getUserCode();//操作员编号
    static void setUserCode(QString sUserCode);
    static QString getUserName();//操作员名
    static void setUserName(QString sUserName);
    static QString getLoginId();//登录信息ID
    static void setLoginId(int nLoginId);
    static QString getPassword();
    static void setPassword(QString sPassword);
    static int getCloseAppStatus();
    static void setCloseAppStatus( int nCloseAppStatus );
    static QString getCategoryLastUpdateTime();
    static void setCategoryLastUpdateTime(QString sLastTime);
    static QString getGoodsLastUpdateTime();
    static void setGoodsLastUpdateTime(QString sLastTime);
    static QString getGoodsPriceLastUpdateTime();
    static void setGoodsPriceLastUpdateTime(QString sLastTime);
    static QString getKPosSetLastUpdateTime();
    static void setKPosSetLastUpdateTime(QString sLastTime);
    static QString getReceiptShopName();
    static void setReceiptShopName(QString sShopName);
    static QString getRefundGoodsReasonJson();
    static void setRefundGoodsReasonJosn(QString sReasonJson);
    static void setLoginTime(QString sLoginTime); // 当前用户登录时间
    static QString getLoginTime(); // 当前用户登录时间
    static void setRemoteADPathList(const QList<QString>& remoteADList);
    static QList<QString> getRemoteADPathList();
    static void DelIniFile();//删除ini文件
    static bool getSetGuide(); // 是否需要设置向导
    static void setSetGuide(bool nflag);
};

#endif // KPOSINI_H
