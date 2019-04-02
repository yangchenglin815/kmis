#include "GoodsManageCtrl.h"
#include "../util/HttpSignal.h"


GoodsManageCtrl::GoodsManageCtrl(QObject *parent)
  : QObject(parent)
{
   initConnect();
}

void GoodsManageCtrl::getGoodsManageListRequest(int nCategoryBigId, QString searchPattern)
{
    int nOffset = -1;
    int nLimit = -1;
    QList<int> leafCategoryIdList;
    GoodsManageAgent::instance()->getLeafCategoryIdListRequest(nCategoryBigId, leafCategoryIdList);
    GoodsManageAgent::instance()->getGoodsManageListRequest(searchPattern, nLimit, nOffset, leafCategoryIdList, "req_num", "asc", nCategoryBigId);
}

void GoodsManageCtrl::getCategoryRequest()
{
    GoodsManageAgent::instance()->getCategoryListRequest();
}

void GoodsManageCtrl::initConnect()
{
   qRegisterMetaType<QList<CategoryBigInfo_s> >("QList<CategoryBigInfo_s>");
   connect(GoodsManageAgent::instance(), SIGNAL(sigOnGetCategoryList(int,QString,QList<CategoryBigInfo_s>))
           , this, SIGNAL(sigOnGetCategoryList(int,QString,QList<CategoryBigInfo_s>)));
   qRegisterMetaType<QList<sGoodsInfo_s> >("QList<sGoodsInfo_s>");
   connect(GoodsManageAgent::instance(), SIGNAL(sigOnGetGoodsManageList(int,QString,QList<sGoodsInfo_s>,int))
           , this, SIGNAL(sigOnGetGoodsManageList(int,QString,QList<sGoodsInfo_s>,int)));
}
