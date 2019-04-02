#ifndef BALANCEMANAGE_H
#define BALANCEMANAGE_H

#include <QObject>
#include <QTimer>
#include "../data/ebalancedata.h"
#include "ScaleVgaData.h"

class BalanceManage : public QObject
{
    Q_OBJECT
public:  
    static BalanceManage* instance();
    static void Release();
    void startCheckBalance(); // 定期检查称重
    void stopCheckBalance();
    void setCheckTimeLen(int nTimeLen);
    void autoClearTareWeight(); // 自动去皮
    void openCashBox(); // 开钱箱
    void printBitmapFile(QString sBitmapPath); // 打印位图
    void cutPage(); // 打印完毕后切纸
    QString getPosName();
    bool isIntegratedScale();

private:
    explicit BalanceManage(QObject *parent = 0);
    void initConnect();
    bool testDll(QString sPosName, QString& sHintText);
    QString AnalysisScaleWeight(QString sData);

private slots:
    void slot_timeOut();
    void slot_stableTimeout();

signals:
    void sig_stableInfo(EBalanceStandard_Ex balanceStandard_Ex, bool bStable);

private:
    static BalanceManage* m_pInstance;
    ScaleVgaData *m_scaleVgaData;
    QTimer m_timer;
    QTimer m_stableTimer;
    QString m_sWeight;
    int m_nCheckTimeLen;
    QString m_sPosName;
    bool m_bAutoPeel;

};

#endif // BALANCEMANAGE_H
