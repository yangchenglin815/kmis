#include "PersonalWalletDlg.h"
#include "ui_PersonalWalletDlg.h"

PersonalWalletDlg::PersonalWalletDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonalWalletDlg)
{
    ui->setupUi(this);
}

PersonalWalletDlg::~PersonalWalletDlg()
{
    delete ui;
}
