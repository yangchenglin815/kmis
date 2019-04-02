#include "ReportChartsWidget.h"
#include "ui_ReportChartsWidget.h"

ReportChartsWidget::ReportChartsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportChartsWidget)
{
    ui->setupUi(this);
    initConnect();
}

ReportChartsWidget::~ReportChartsWidget()
{
    delete ui;
}

void ReportChartsWidget::on_summaryChartsButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->summaryChartsPage);
    ui->summaryChartsPage->test();
}

void ReportChartsWidget::on_rankChartsButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->rankChartsPage);
    ui->rankChartsPage->test();
}

void ReportChartsWidget::slot_returnClicked()
{
    if (ui->stackedWidget->currentWidget() == ui->chartsHomePage)
    {
        emit sigReturnClicked();
    }
    else
    {
        ui->stackedWidget->setCurrentWidget(ui->chartsHomePage);
    }
}

void ReportChartsWidget::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sigReturnClicked()), this, SLOT(slot_returnClicked()));
}
