#include "SummaryChartsWidget.h"
#include "ui_SummaryChartsWidget.h"
#include "../util/KPosServerIni.h"
#include "../Agent/LoginKPosAgent.h"
#include "../util/KPosLog.h"

SummaryChartsWidget::SummaryChartsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SummaryChartsWidget)
{
    ui->setupUi(this);
}

SummaryChartsWidget::~SummaryChartsWidget()
{
    delete ui;
}

void SummaryChartsWidget::test()
{
    QString sIpAddress = KPosServerIni::getReceiveSummaryChartsUrl();
    int nShopID = LoginKPosAgent::instance()->getLoginKPosInfo().nShopID;
    QString sUrl = QString("%1?orgz_id=%2?date=2016-10-29").arg(sIpAddress).arg(nShopID);
    KPosLog::instance()->writeDebugLog(sUrl);
    ui->webView->load(QUrl(sUrl));
}
