#include "BCSCreateGroupDlg.h"
#include "ui_BCSCreateGroupDlg.h"

BCSCreateGroupDlg::BCSCreateGroupDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSCreateGroupDlg)
{
    ui->setupUi(this);
}

BCSCreateGroupDlg::~BCSCreateGroupDlg()
{
    delete ui;
}
