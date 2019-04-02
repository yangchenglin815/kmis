#ifndef KPOSSETAGENT_H
#define KPOSSETAGENT_H

#include <QObject>
#include <QMutex>
#include "../data/setstructdata.h"

class KPosSetAgent : public QObject
{
    Q_OBJECT
public:  
    static KPosSetAgent* instance();
    void downloadKPosSetRequest(QString sLastTime);
    void uploadKPosSetRequest(const KPosSet &kPosSet, bool bSync);
    void addCustomCategoryRequest(QString sCategoryName, int nPos);
    void delCustomCategoryRequest(int nCategroyId );
    void getKPosSetInfo(KPosSet& kPosSet);
    void setKPosSetInfo(const KPosSet& kPosSet);

private:
    explicit KPosSetAgent(QObject *parent = 0);

private slots:
    void slot_onDownloadKPosSet(int nCode, QString sMsg, KPosSet kPosSet, QString sUpdateTime);
    void slot_onUploadKPosSet(int nCode, QString sMsg, QString sUpdateTime);
    void slot_onAddCustomCategory(int nCode, QString sMsg, int nCategoryId);
    void slot_onDeleteCustomCategory(int nCode, QString sMsg, int nCategoryId);

private:
    void initConnect();
    void init();
    void initPosInfoSet();
    void initKeySet();
    void initParamsSet();
    void initPayWaySet();
    void initReceiptPrintOption();

signals:
    void sigDownloadKPosSetFinished();
    void sigOnAddCustomCategory(int nCode, QString sMsg, int nCategoryId);
    void sigOnDeleteCustomCategory(int nCode, QString sMsg, int nCategoryId);
    void sigStartUpdateThread();

    void sigPosInfoChanged();
    void sigKeySetChanged();
    void sigGoodSetChanged();
    void sigPayWaySetChanged();
    void sigParamsSetChanged();
    void sigScreenSetChanged(ScreenSet screenSet);

private:
    KPosSet m_kPosSet;
    static KPosSetAgent* m_pInstance;
    QMutex m_kPosSetLocker;
    QMutex m_lockDownDownSetLocker;
};

#endif // KPOSSETAGENT_H
