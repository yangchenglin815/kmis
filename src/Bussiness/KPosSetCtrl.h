#ifndef KPOSSETCTRL_H
#define KPOSSETCTRL_H

#include <QObject>
#include "../data/setstructdata.h"

class KPosSetCtrl : public QObject
{
    Q_OBJECT
public:
    explicit KPosSetCtrl(QObject *parent = 0);
    void getKPosSetInfo(KPosSet &kPosSet);
//    void setKPosSetInfo(const KPosSet &kPosSet);
    void uploadKPosSet(const KPosSet& kPosSet, bool bSync);
    void addCustomCategoryRequest(QString sCategoryName, int nPos);
    void delCustomCategoryRequest(int nCategoryId );

private:
    void initConnect();

signals:
    void sigOnAddCustomCategory(int,QString,int);
};

#endif // KPOSSETCTRL_H
