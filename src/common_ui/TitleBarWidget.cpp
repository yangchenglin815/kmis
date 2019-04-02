#include "TitleBarWidget.h"
#include "ui_TitleBarWidget.h"

TitleBarWidget::TitleBarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleBarWidget)
{
    ui->setupUi(this);

    initCtrl();
    initConnect();
}

TitleBarWidget::~TitleBarWidget()
{
    delete ui;
}

void TitleBarWidget::setTitleText( QString strTitleText )
{
    ui->titleLabel->setText( strTitleText );
}

void TitleBarWidget::setTitleWidth( int nTitleWidth )
{
    this->resize( nTitleWidth, height() );
}

void TitleBarWidget::setCloseButtonFocus( bool bFocus )
{
    if( bFocus ) {
        ui->closeButton->setFocusPolicy( Qt::StrongFocus );
    } else {
        ui->closeButton->setFocusPolicy( Qt::NoFocus );
    }
}

void TitleBarWidget::setCloseButtonEnabled( bool bEnabled )
{
    ui->closeButton->setEnabled( bEnabled );
}

void TitleBarWidget::hideTitleText()
{
    ui->titleLabel->hide();
}

void TitleBarWidget::initCtrl()
{

}

void TitleBarWidget::initConnect()
{
    connect( ui->closeButton, SIGNAL(clicked()), this, SIGNAL( sig_close_wnd()));
}
