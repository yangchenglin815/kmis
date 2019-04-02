#include "BankCardRechargeDlg.h"
#include "ui_BankCardRechargeDlg.h"

BankCardRechargeDlg::BankCardRechargeDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BankCardRechargeDlg)
{
    ui->setupUi(this);
}

BankCardRechargeDlg::~BankCardRechargeDlg()
{
    delete ui;
}
