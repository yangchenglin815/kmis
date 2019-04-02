#ifndef MTCOMAPIMANANGER_H
#define MTCOMAPIMANANGER_H

#include <QWidget>
#include <QTimer>
#include "../data/ebalancedata.h"

class MTComAPIMananger : public QWidget
{
    Q_OBJECT
public:  
    static MTComAPIMananger* instance();
    void openMTCom();
    void release();
    void stopCheckWeight(); // 停止检测称重
    void startCheckWeight(); // 定期检查称重
    void setCheckTimeLen(int nTimeLen); // 设置定期检测间隔

private slots:
    void slot_timeOut();
    void slot_stableTimeout();

private:
    explicit MTComAPIMananger(QWidget *parent = 0);
    void initConnect();

signals:
    void sig_stableInfo(EBalanceStandard_Ex balanceStandard_Ex, bool bStable);

private:
    static MTComAPIMananger* m_pInstance;
    QTimer m_timer;
    QTimer m_stableTimer;
    QString m_sWeight;
    int m_nCheckTimeLen;
    bool m_bUseMTCom;
};

#endif // MTCOMAPIMANANGER_H
