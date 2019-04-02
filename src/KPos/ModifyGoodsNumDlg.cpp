#include "ModifyGoodsNumDlg.h"
#include "ui_ModifyGoodsNumDlg.h"
#include "../callOuterDll/BalanceManage.h"
#include <QDebug>
#include <QMessageBox>

ModifyGoodsNumDlg::ModifyGoodsNumDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModifyGoodsNumDlg)
    , m_bFirst( true )
    , m_nSingleMaxNum( 1000 )
    , m_bStable(false)
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint );
    setModal( true );

    initCtrl();
    initConnect();
}

ModifyGoodsNumDlg::~ModifyGoodsNumDlg()
{
    delete ui;
}

void ModifyGoodsNumDlg::setGoodsDetailInfo( GoodsDetailInfo &stGoodsDetailsInfo )
{
    disconnect(BalanceManage::instance(), SIGNAL(sig_stableInfo(EBalanceStandard_Ex,bool)),this, SLOT( slot_stableInfo(EBalanceStandard_Ex,bool)));

    m_bFirst = true;

    m_stGoodsDetailInfo = stGoodsDetailsInfo;


    QString strGoodsNum = "";
    if( m_stGoodsDetailInfo.bStandard )
    {
        m_bStable = true;
        strGoodsNum.sprintf( "%d", (int)m_stGoodsDetailInfo.fNumber );
        ui->newNumEdit->setEnabled( false );
        QRegExp regx("[0-9]*");
        QRegExpValidator *pReg = new QRegExpValidator( regx, this);
        ui->newNumEdit->setValidator( pReg );
    }
    else
    {
        m_bStable = false;
        connect(BalanceManage::instance(), SIGNAL(sig_stableInfo(EBalanceStandard_Ex,bool)), this, SLOT( slot_stableInfo(EBalanceStandard_Ex,bool) ) );
        strGoodsNum.sprintf( "%.3f", m_stGoodsDetailInfo.fNumber );
        ui->newNumEdit->setEnabled( true );
        QRegExp regx("[0-9]*.[0-9]{3}");
        QRegExpValidator *pReg = new QRegExpValidator( regx, this);
        ui->newNumEdit->setValidator( pReg );
    }
    ui->newNumEdit->setText( strGoodsNum );
    updateAmountText();

    QString strName = "";
    if( m_stGoodsDetailInfo.strGoodsShortName.isEmpty() ) {
        strName = m_stGoodsDetailInfo.sGoodsName;
    } else {
        strName = m_stGoodsDetailInfo.strGoodsShortName;
    }

    ui->goodsNameValueLabel->setText( strName );
    ui->oldNumValueLabel->setText( strGoodsNum );
}

void ModifyGoodsNumDlg::setSingleMaxNum( int nSingleMaxNum )
{
    m_nSingleMaxNum = nSingleMaxNum;
}

void ModifyGoodsNumDlg::initCtrl()
{
    ui->titleBarWidget->setTitleText( "修改商品数量" );
}

void ModifyGoodsNumDlg::initConnect()
{
    connect( ui->titleBarWidget, SIGNAL(sig_close_wnd()), this, SLOT( close() ) );
    connect( ui->commitButton, SIGNAL( clicked()), this, SLOT( slot_commit() ) );

    //数字键盘
    connect( ui->DigitalKeyWnd, SIGNAL( sigText(QString)), this, SLOT( slot_setText(QString) ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigDelete()), this, SLOT( slot_deleteValue() ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigClear()), this, SLOT( slot_clearZero() ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigConfirm()), this, SLOT( slot_commit() ) );
}

//默认为2位小数点
int ModifyGoodsNumDlg::findDecimalsNum()
{
    QString str_value = ui->newNumEdit->text();
    QStringList str_list = str_value.split( "." );
    if( str_list.size() == 2 ) {
        QString str_dec = str_list[1];
        return str_dec.length();
    }

    return 0;
}

bool ModifyGoodsNumDlg::findPoint()
{
    QString strPoint = ui->newNumEdit->text();
    for( int i = 0; i < strPoint.length(); i++ )
    {
        if( strPoint[i] == '.' )
        {
            return true;
        }
    }

    return false;
}

void ModifyGoodsNumDlg::firstClick()
{
    if( m_bFirst )
    {
        ui->newNumEdit->setText( "" );
        updateAmountText();
        m_bFirst = false;
    }
}

void ModifyGoodsNumDlg::updateAmountText()
{
    QString NumText =  ui->newNumEdit->text();
    float strAmountText = NumText.toFloat() * m_stGoodsDetailInfo.fPrice;
    ui->newAmountEdit->setText(QString::number(strAmountText, 'f', 2));
}

void ModifyGoodsNumDlg::slot_setText( QString strText )
{
    firstClick();

    //非会员卡结算
    if( ui->newNumEdit->text().isEmpty() && strText == "." ) return;

    if( m_stGoodsDetailInfo.bStandard && strText == "." ) return;

    int nNum = findDecimalsNum();

    if( strText == "00" && nNum >= 1 ) return;
    if( findPoint() && strText == "." ) return;
    if( nNum >= 3 ) return;

    QString sText = ui->newNumEdit->text();
    QString strNewText = sText.append( strText );
    if( strNewText.toInt() > m_nSingleMaxNum ) {
        return;
    } else {
        ui->newNumEdit->setText( strNewText );
    }
    updateAmountText();
}

void ModifyGoodsNumDlg::slot_deleteValue()
{
    firstClick();

    QString str_value = ui->newNumEdit->text();
    str_value.remove( str_value.length() - 1, 1);
    ui->newNumEdit->setText( str_value );

    updateAmountText();
}

void ModifyGoodsNumDlg::slot_clearZero()
{
    firstClick();

    ui->newNumEdit->setText( "" );

    updateAmountText();
}

void ModifyGoodsNumDlg::slot_stableInfo(EBalanceStandard_Ex balanceStandard_Ex, bool bStable)
{
    m_bStable = bStable;

    float fWeight = balanceStandard_Ex.sWeight.toFloat();
    if( fWeight < 0.001 ) return;//小于等于0
    if( balanceStandard_Ex.bOverWeight ) return;//过载

    QString strWeight = "";
    strWeight.sprintf( "%.3f", balanceStandard_Ex.sWeight.toFloat() );
    ui->newNumEdit->setText( strWeight );
    updateAmountText();
}

void ModifyGoodsNumDlg::slot_commit()
{
    if (!m_bStable)
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("称重尚不稳定请稍等..."));
        return;
    }

    disconnect(BalanceManage::instance(), SIGNAL(sig_stableInfo(EBalanceStandard_Ex,bool))
                ,this, SLOT(slot_stableInfo(EBalanceStandard_Ex,bool)));

    if( ui->newNumEdit->text().isEmpty() ) return;
    if( ui->newNumEdit->text().toFloat() < 0.0001 ) return;

    emit sig_modifyGoodsNum( m_stGoodsDetailInfo.nSaleDetailPos, ui->newNumEdit->text() );
    ui->newNumEdit->setText( "" );
    updateAmountText();
    this->hide();
}


