#include "ReportLossWid.h"
#include "ui_ReportLossWid.h"

ReportLossWid::ReportLossWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportLossWid)
  , m_reportLossCtrl(NULL)
{
    ui->setupUi(this);
    initconnect();
    init();
}

ReportLossWid::~ReportLossWid()
{
    delete ui;
}

void ReportLossWid::initReportLossCtrl()
{
   if(m_reportLossCtrl == NULL){
       m_reportLossCtrl = new ReportLossCtrl;
       ui->mainPage->initReportLossCtrl(m_reportLossCtrl);
       ui->editPage->initReportLossCtrl(m_reportLossCtrl);
   }
   ui->mainPage->getReportLossOrder();
}

void ReportLossWid::setCategoryList(QList<CategoryInfo *> categoryInfoList)
{
    ui->editPage->setCategoryList(categoryInfoList);
}

void ReportLossWid::slot_showDetialPage()
{
    ui->stackedWidget->setCurrentWidget(ui->inquirePage);
}

void ReportLossWid::slot_showAddReportLossPage()
{
    ui->editPage->initMode(1);
    ui->editPage->initEditPage();
    ui->stackedWidget->setCurrentWidget(ui->editPage);
}

void ReportLossWid::slot_ReturnClicked()
{
    if (ui->stackedWidget->currentWidget() == ui->mainPage)
    {
        ui->mainPage->hideCalendarWidget();
        emit sigReturnClicked();
    }
    else
    {
        ui->stackedWidget->setCurrentWidget(ui->mainPage);
    }
}

void ReportLossWid::slot_printReportLossOrder(QList<AddReportLossSelectInfo> infoList, int nOrderId)
{
    ui->mainPage->printReportLossOrder(infoList, nOrderId);
}

void ReportLossWid::slot_updateOrder()
{
    initReportLossCtrl();
    ui->stackedWidget->setCurrentWidget(ui->mainPage);
}

void ReportLossWid::slot_getReportLossDetial(QList<AddReportLossSelectInfo> orderInfoList)
{
    ui->inquirePage->initData(orderInfoList);
}

void ReportLossWid::slot_showEditReportLossPage()
{
    ui->editPage->initMode(2);
    ui->stackedWidget->setCurrentWidget(ui->editPage);
}

void ReportLossWid::init()
{
    ui->stackedWidget->setCurrentWidget(ui->mainPage);
}

void ReportLossWid::initconnect()
{
    qRegisterMetaType<QList<AddReportLossSelectInfo>>("QList<AddReportLossSelectInfo>");
    connect(ui->editPage, SIGNAL(sigPrintReportLossOrder(QList<AddReportLossSelectInfo>,int))
            , this, SLOT(slot_printReportLossOrder(QList<AddReportLossSelectInfo>, int)));
    connect(ui->mainPage, SIGNAL(showDetialPage()), this, SLOT(slot_showDetialPage()));
    connect(ui->mainPage, SIGNAL(showAddReportLossPage()), this, SLOT(slot_showAddReportLossPage()));
    connect(ui->mainPage, SIGNAL(showEditReportLossPage()), this, SLOT(slot_showEditReportLossPage()));
    connect(ui->titleWidget, SIGNAL(sigReturnClicked()), this, SLOT(slot_ReturnClicked()));
    connect(ui->editPage, SIGNAL(sigSaveOrderSuccess()), this, SLOT(slot_updateOrder()));
    connect(ui->mainPage, SIGNAL(getReportLossDetialOrder(QList<AddReportLossSelectInfo>))
            , this, SLOT(slot_getReportLossDetial(QList<AddReportLossSelectInfo>)));
}
