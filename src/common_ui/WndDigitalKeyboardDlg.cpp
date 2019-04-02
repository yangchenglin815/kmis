#include "WndDigitalKeyboardDlg.h"
#include "ui_WndDigitalKeyboardDlg.h"

WndDigitalKeyboardDlg::WndDigitalKeyboardDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WndDigitalKeyboardDlg)
{
    ui->setupUi(this);
    setWindowFlags( Qt::FramelessWindowHint | Qt::Tool); //隐藏标题栏
    ui->titleWnd->setTitleText(QStringLiteral("数字键盘"));
    initConnect();
}

WndDigitalKeyboardDlg::~WndDigitalKeyboardDlg()
{
    delete ui;
}

void WndDigitalKeyboardDlg::initConnect()
{
    connect(ui->titleWnd, SIGNAL(sig_close_wnd()), this, SLOT(hide()));
    connect(ui->keyboardWidget, SIGNAL(sigText(QString)), this, SIGNAL(sigText(QString)));
    connect(ui->keyboardWidget, SIGNAL(sigDelete()), this, SIGNAL(sigDelete()));
    connect(ui->keyboardWidget, SIGNAL(sigClear()), this, SIGNAL(sigClear()));
    connect(ui->keyboardWidget, SIGNAL(sigConfirm()), this, SIGNAL(sigConfirm()));
}
