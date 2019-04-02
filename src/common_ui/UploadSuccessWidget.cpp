#include "UploadSuccessWidget.h"
#include "ui_UploadSuccessWidget.h"

UploadSuccessWidget::UploadSuccessWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UploadSuccessWidget)
{
    ui->setupUi(this);
}

UploadSuccessWidget::~UploadSuccessWidget()
{
    delete ui;
}
