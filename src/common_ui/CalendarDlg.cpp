#include "CalendarDlg.h"
#include "ui_CalendarDlg.h"

CalendarDlg::CalendarDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalendarDlg)
{
    ui->setupUi(this);
}

CalendarDlg::~CalendarDlg()
{
    delete ui;
}
