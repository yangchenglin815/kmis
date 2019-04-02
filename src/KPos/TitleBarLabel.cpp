#include "TitleBarLabel.h"
#include "ui_TitleBarLabel.h"
#include "KPosIni.h"
#include "LoginKPosAgent.h"
#include "OnlineStateAgent.h"

TitleBarLabel::TitleBarLabel(QWidget *parent) :
    QLabel(parent),
    ui(new Ui::TitleBarLabel)
{
    ui->setupUi(this);
    init();
    initConnect();
}

TitleBarLabel::~TitleBarLabel()
{
    delete ui;
}

void TitleBarLabel::setPixSize( int nPixSize )
{
    QFont ft;
    ft.setPixelSize( nPixSize );

    ui->stableButton->setFont( ft );
    ui->zeroButton->setFont( ft );
    ui->overWeightButton->setFont( ft );
    ui->lessWeightButton->setFont( ft );
    ui->memberButton->setFont( ft );
    ui->onlineStateButton->setFont( ft );

    ui->shopLabel->setFont( ft );
    ui->storeLabel->setFont( ft );
    ui->storeNameLabel->setFont( ft );

    ui->cashierLabel->setFont( ft );
    ui->cashierNameLabel->setFont( ft );
    ui->posLabel->setFont( ft );
    ui->posIDLabel->setFont( ft );

    ui->backButton->setFont( ft );
}

void TitleBarLabel::setBalanceStable( bool bStable )
{
    ui->stableButton->setEnabled( bStable );
}

void TitleBarLabel::setBalanceZero( bool bZero )
{
    ui->zeroButton->setEnabled( bZero );
}

void TitleBarLabel::setBalanceOverload( bool bOverWeight )
{
    ui->overWeightButton->setEnabled( bOverWeight );
}

void TitleBarLabel::setBalanceUnderload( bool bUnderWeight )
{
    ui->lessWeightButton->setEnabled( bUnderWeight );
}

void TitleBarLabel::setMemStatus( bool bMemStatus )
{
    ui->memberButton->setEnabled( bMemStatus );
}

void TitleBarLabel::slot_OnlineState(bool bOnline)
{
    ui->onlineStateButton->setEnabled(bOnline);
}

void TitleBarLabel::init()
{
    ui->shopLabel->setText( KPosIni::getCorpName() );
    ui->storeNameLabel->setText( KPosIni::getShopName() );
    ui->posIDLabel->setText( KPosIni::getPosCode() );
    QString strCashierName = LoginKPosAgent::instance()->getLoginKPosInfo().salemanInfo.sUsername;
    ui->cashierNameLabel->setText( strCashierName );

    ui->memberButton->setEnabled( false );//会员
}

void TitleBarLabel::initConnect()
{
    connect( ui->backButton, SIGNAL(clicked(bool)), this, SIGNAL( sig_backHomePage() ) );
    connect(OnlineStateAgent::instance(), SIGNAL(sigOnlineState(bool)), this, SLOT(slot_OnlineState(bool)));
}
