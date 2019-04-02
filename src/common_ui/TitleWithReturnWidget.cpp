#include "TitleWithReturnWidget.h"
#include "ui_TitleWithReturnWidget.h"

TitleWithReturnWidget::TitleWithReturnWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleWithReturnWidget)
{
    ui->setupUi(this);
}

TitleWithReturnWidget::~TitleWithReturnWidget()
{
    delete ui;
}

void TitleWithReturnWidget::on_backButton_clicked()
{
    emit sigReturnClicked();
}
