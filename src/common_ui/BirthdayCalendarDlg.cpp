#include "BirthdayCalendarDlg.h"
#include "ui_BirthdayCalendarDlg.h"

BirthdayCalendarDlg::BirthdayCalendarDlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BirthdayCalendarDlg)
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint | Qt::Tool ); //隐藏标题栏
    this->setAttribute(Qt::WA_TranslucentBackground, true);
}

BirthdayCalendarDlg::~BirthdayCalendarDlg()
{
    delete ui;
}

