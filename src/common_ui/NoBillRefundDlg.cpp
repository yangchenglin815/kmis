#include "NoBillRefundDlg.h"
#include "ui_NoBillRefundDlg.h"

NoBillRefundDlg::NoBillRefundDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoBillRefundDlg)
{
    ui->setupUi(this);
}

NoBillRefundDlg::~NoBillRefundDlg()
{
    delete ui;
}
