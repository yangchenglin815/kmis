#include "DlgCommon.h"
#include "ui_DlgCommon.h"

DlgCommon::DlgCommon(QWidget *parent, bool bAccept) :
    QDialog(parent),
    ui(new Ui::DlgCommon)
  , m_bAccept( bAccept )
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    setModal( true );
//    setAttribute( Qt::WA_DeleteOnClose );
    init_connect();
}

DlgCommon::~DlgCommon()
{
    delete ui;
}

void DlgCommon::init_connect()
{
    connect( ui->deleteBtn, SIGNAL(clicked()), this, SLOT( slot_dlg_close() ) );
    connect( ui->sureBtn, SIGNAL( clicked()), this, SLOT( slot_sure() ) );
    connect( ui->cancelBtn, SIGNAL( clicked()), this, SLOT( slot_cancel() ) );
}

void DlgCommon::set_title( QString str_title )
{
    QString str_text = /*"  " +*/ str_title;
    ui->titleLabel->setText( str_text );
    setWindowTitle( str_text );
}

QString DlgCommon::get_title()
{
    QString strText = ui->titleLabel->text().trimmed();//去空格
    return strText;
}

void DlgCommon::set_content( QString str_content )
{
    ui->contextLabel->setText( str_content );
}

QString DlgCommon::get_content()
{
    return ui->contextLabel->text();
}

void DlgCommon::set_btn_sure_text( QString str_sure )
{
    ui->sureBtn->setText( str_sure );
}

void DlgCommon::set_btn_cancel_text( QString str_cancel )
{
    ui->cancelBtn->setText( str_cancel );
}

void DlgCommon::hideCancelButton()
{
    ui->cancelBtn->hide();
}

void DlgCommon::hideDeleteButton()
{
    ui->deleteBtn->hide();
}

void DlgCommon::showDeleteButton()
{
    ui->deleteBtn->show();
}

void DlgCommon::hideSureButton()
{
    ui->sureBtn->hide();
}

void DlgCommon::hideBottomWidget()
{
    ui->bottomWidget->hide();
}

void DlgCommon::showBottomWidget()
{
    ui->bottomWidget->show();
}

void DlgCommon::slot_dlg_close()
{
    this->hide();
    emit sig_dlg_close();
}

void DlgCommon::slot_sure()
{
    this->hide();
    if( m_bAccept ) {
        this->accept();
    } else {
        emit sig_btn_sure();
    }
}

void DlgCommon::slot_cancel()
{
    this->hide();
    emit sig_btn_cancel();
}
