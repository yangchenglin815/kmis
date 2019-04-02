#include "TipsDlg.h"
#include "ui_TipsDlg.h"

TipsDlg* TipsDlg::m_pInstance = NULL;

TipsDlg::TipsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TipsDlg)
  ,isMasked(false)
  ,isPrased(false)
{
    ui->setupUi(this);
    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    setModal( true );
}

TipsDlg::~TipsDlg()
{
    delete ui;
}
TipsDlg *TipsDlg::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new TipsDlg;
    }
    return m_pInstance;
}

void TipsDlg::maskUI(const QString& str)
{
    ui->contextLabel->setText(str);
    show();
    raise();
    isPrased=false;
    isMasked=true;
    emit sig_masked();
}

void TipsDlg::releaseCtrl(const QString& str)
{
    ui->contextLabel->setText(str);
    show();
    raise();
    isPrased=true;
    isMasked=false;
    emit sig_releaseCtrl();
}

void TipsDlg::workDone()
{
    hide();
    isPrased=true;
    isMasked=false;
}

void TipsDlg::on_deleteBtn_clicked()
{
//    if(false==isMasked)
        hide();
//    else
//        ui->contextLabel->setText("暂无法关闭，请耐心等候...");
}
