#include "CashierPaymentDlg.h"
#include "ui_CashierPaymentDlg.h"

CashierPaymentDlg::CashierPaymentDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CashierPaymentDlg)
{
    ui->setupUi(this);
}

CashierPaymentDlg::~CashierPaymentDlg()
{
    delete ui;
}
