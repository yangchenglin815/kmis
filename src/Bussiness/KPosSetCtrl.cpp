#include "KPosSetCtrl.h"
#include "../Agent/KPosSetAgent.h"

KPosSetCtrl::KPosSetCtrl(QObject *parent) : QObject(parent)
{
    initConnect();
}

void KPosSetCtrl::getKPosSetInfo(KPosSet &kPosSet)
{
    KPosSetAgent::instance()->getKPosSetInfo(kPosSet);
}

//void KPosSetCtrl::setKPosSetInfo(const KPosSet &kPosSet)
//{
//    KPosSetAgent::instance()->setKPosSetInfo(kPosSet);
//}

void KPosSetCtrl::uploadKPosSet(const KPosSet &kPosSet, bool bSync)
{
    Q_UNUSED( bSync )

    KPosSetAgent::instance()->uploadKPosSetRequest(kPosSet, true);
}

void KPosSetCtrl::addCustomCategoryRequest(QString sCategoryName, int nPos )
{
    KPosSetAgent::instance()->addCustomCategoryRequest(sCategoryName, nPos );
}

void KPosSetCtrl::delCustomCategoryRequest( int nCategoryId )
{
    KPosSetAgent::instance()->delCustomCategoryRequest( nCategoryId );
}

void KPosSetCtrl::initConnect()
{
    connect(KPosSetAgent::instance(), SIGNAL(sigOnAddCustomCategory(int,QString,int))
            , this, SIGNAL(sigOnAddCustomCategory(int,QString,int)));
}
