#include "ReportLossCtrl.h"
#include "../Agent/ReportLossAgent.h"
#include "../Agent/CategoryInfoAgent.h"
#include "../Agent/LoginKPosAgent.h"
#include "QDebug"

ReportLossCtrl::ReportLossCtrl(QObject *parent)
   : QObject(parent)
{
   initConnect();
}


void ReportLossCtrl::getReportLossOrderListRequest(QString sStartDate, QString sEndDate, QString searchPatter)
{
    ReportLossAgent::instance()->getReportLossOrderListRequest(sStartDate, sEndDate, searchPatter);
}

void ReportLossCtrl::AddReportLossListRequest(QList<AddReportLossSelectInfo> infoList)
{
    ReportLossAgent::instance()->AddReportLossListRequest(infoList);
}

void ReportLossCtrl::editReportLossListRequest(QList<AddReportLossSelectInfo> infoList, int selectId)
{
    ReportLossAgent::instance()->editReportLossListRequest(infoList, selectId);
}

void ReportLossCtrl::deleteReportLossListRequest(int selectId)
{
    ReportLossAgent::instance()->deleteReportLossListRequest(selectId);
}

void ReportLossCtrl::checkReportLossListRequest(int selectId)
{
    ReportLossAgent::instance()->checkReportLossListRequest(selectId);
}

void ReportLossCtrl::getReportLossDetialRequest(int selectId, int mode)
{
    ReportLossAgent::instance()->getReportLossDetialRequest(selectId, mode);
}

void ReportLossCtrl::slot_categoryGoodsChanged()
{
    emit sigCategoryGoodsChanged();
}

void ReportLossCtrl::initConnect()
{
   connect(CategoryInfoAgent::instance(), SIGNAL(sigCategoryGoodsChanged()), this, SLOT(slot_categoryGoodsChanged()));
   qRegisterMetaType<QList<ReportLossInfo> >("QList<ReportLossInfo>");
   connect(ReportLossAgent::instance(), SIGNAL(sigOnGetReportLossOrderList(int,QString,QList<ReportLossInfo>))
           , this, SIGNAL(sigOnGetReportLossOrderList(int,QString,QList<ReportLossInfo>)));
   connect(ReportLossAgent::instance(), SIGNAL(sigAddReportLossOrderList(int,QString))
           , this, SIGNAL(sigAddReportLossOrderList(int,QString)));
   connect(ReportLossAgent::instance(), SIGNAL(sigDeleteReportLossOrderList(int,QString))
           , this, SIGNAL(sigDeleteReportLossOrderList(int,QString)));
   connect(ReportLossAgent::instance(), SIGNAL(sigCheckReportLossOrderList(int,QString))
           , this, SIGNAL(sigCheckReportLossOrderList(int,QString)));
   connect(ReportLossAgent::instance(), SIGNAL(sigEditReportLossOrderList(int,QString))
           , this, SIGNAL(sigEditReportLossOrderList(int,QString)));
   qRegisterMetaType<QList<AddReportLossSelectInfo>>("QList<AddReportLossSelectInfo>");
   connect(ReportLossAgent::instance(), SIGNAL(sigOnGetReportLossDeitalOrderList(int,QString,QList<AddReportLossSelectInfo>))
           , this, SIGNAL(sigOnGetReportLossDetialOrderList(int,QString,QList<AddReportLossSelectInfo>)));
   connect(ReportLossAgent::instance(), SIGNAL(sigOnGetEditReportLossDetialOrder(int,QString,QList<AddReportLossSelectInfo>,int))
           , this, SIGNAL(sigOnGetEditReportLossDetialOrder(int,QString,QList<AddReportLossSelectInfo>,int)));
   connect(ReportLossAgent::instance(), SIGNAL(sigOnGetPrintReportLossDetialOrder(int,QString,QList<AddReportLossSelectInfo>,int))
           , this, SIGNAL(sigOnGetPrintReportLossDetialOrder(int,QString,QList<AddReportLossSelectInfo>,int)));
}
