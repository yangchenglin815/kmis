#include "ReportLossAgent.h"
#include "../HttpClient/HttpClient.h"
#include "../util/HttpSignal.h"
#include "../util/ThreadManager.h"
#include "QDebug"

ReportLossAgent* ReportLossAgent::m_pInstance = NULL;

ReportLossAgent *ReportLossAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new ReportLossAgent;
    }
    return m_pInstance;
}

void ReportLossAgent::getReportLossOrderListRequest(QString sStartDate, QString sEndDate, QString searchPatter)
{
    HttpClient::instance()->getReportLossOrderList(sStartDate, sEndDate, searchPatter);
}

void ReportLossAgent::AddReportLossListRequest(QList<AddReportLossSelectInfo> infoList)
{
    HttpClient::instance()->AddReportLossOrderList(infoList);
}

void ReportLossAgent::editReportLossListRequest(QList<AddReportLossSelectInfo> infoList, int selectId)
{
    HttpClient::instance()->editReportLossOrderList(infoList, selectId);
}

void ReportLossAgent::deleteReportLossListRequest(int selectId)
{
    HttpClient::instance()->deleteReportLossOrderList(selectId);
}

void ReportLossAgent::checkReportLossListRequest(int selectId)
{
    HttpClient::instance()->checkReportLossOrderList(selectId);
}

void ReportLossAgent::getReportLossDetialRequest(int selectId, int mode)
{
    HttpClient::instance()->getReportLossDetialOrderList(selectId, mode);
}

ReportLossAgent::ReportLossAgent(QObject *parent) : QObject(parent)
{
    initConnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

void ReportLossAgent::initConnect()
{
    qRegisterMetaType<QList<ReportLossInfo>>("QList<ReportLossInfo>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetReportLossOrderList(int,QString,QList<ReportLossInfo>))
            , this, SIGNAL(sigOnGetReportLossOrderList(int,QString,QList<ReportLossInfo>)));
    connect(HttpSignal::instance(), SIGNAL(sigAddReportLossOrderList(int,QString))
            , this, SIGNAL(sigAddReportLossOrderList(int,QString)));
    connect(HttpSignal::instance(), SIGNAL(sigDeleteReportLossOrderList(int,QString))
            , this, SIGNAL(sigDeleteReportLossOrderList(int,QString)));
    connect(HttpSignal::instance(), SIGNAL(sigCheckReportLossOrderList(int,QString))
            , this, SIGNAL(sigCheckReportLossOrderList(int,QString)));
    connect(HttpSignal::instance(), SIGNAL(sigEditReportLossOrderList(int,QString))
            , this, SIGNAL(sigEditReportLossOrderList(int,QString)));
    qRegisterMetaType<QList<AddReportLossSelectInfo>>("QList<AddReportLossSelectInfo>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetReportLossDetialOrderList(int,QString,QList<AddReportLossSelectInfo>))
            , this, SIGNAL(sigOnGetReportLossDeitalOrderList(int,QString,QList<AddReportLossSelectInfo>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnGetEditReportLossDetialOrderList(int,QString,QList<AddReportLossSelectInfo>,int))
            , this, SIGNAL(sigOnGetEditReportLossDetialOrder(int,QString,QList<AddReportLossSelectInfo>,int)));
    connect(HttpSignal::instance(), SIGNAL(sigOnGetPrintReportLossDetialOrderList(int,QString,QList<AddReportLossSelectInfo>,int))
            , this, SIGNAL(sigOnGetPrintReportLossDetialOrder(int,QString,QList<AddReportLossSelectInfo>,int)));
}
