#include "RankChartsWidget.h"
#include "ui_RankChartsWidget.h"
#include "../util/KPosServerIni.h"
#include "../Agent/LoginKPosAgent.h"
#include "../util/KPosLog.h"

RankChartsWidget::RankChartsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RankChartsWidget)
{
    ui->setupUi(this);
}

RankChartsWidget::~RankChartsWidget()
{
    delete ui;
}

void RankChartsWidget::test()
{
    QString sIpAddress = KPosServerIni::getReceiveRankChartsUrl();
    int nShopID = LoginKPosAgent::instance()->getLoginKPosInfo().nShopID;
    QString sUrl = QString("%1?orgz_id=%2?date=2016-10-29").arg(sIpAddress).arg(nShopID);
    KPosLog::instance()->writeDebugLog(sUrl);
    ui->webView->load(QUrl(sUrl));
}
