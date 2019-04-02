#include "FuncDlg.h"
#include "ui_FuncDlg.h"

FuncDlg::FuncDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FuncDlg)
{
    ui->setupUi(this);

}

FuncDlg::~FuncDlg()
{
    delete ui;
}
