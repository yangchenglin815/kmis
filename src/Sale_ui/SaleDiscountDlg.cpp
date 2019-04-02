#include "SaleDiscountDlg.h"
#include "ui_SaleDiscountDlg.h"
#include "CommonFun.h"

SaleDiscountDlg::SaleDiscountDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SaleDiscountDlg)
    , m_bSaleHeadDis( false )
{
    ui->setupUi(this);
    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    setModal( true );

    initCtrl();
    initConnect();
    setWindowTitle("整单折扣");
}

SaleDiscountDlg::~SaleDiscountDlg()
{
    delete ui;
}

void SaleDiscountDlg::initData()
{
    ui->originalAmtValueLabel->setText( "" );
    ui->discountValueLabel->setText( "" );
    ui->rediscountEdit->setText( "" );
    ui->transAmtValueLabel->setText( "" );
    ui->disAmtValueLabel->setText( "" );
}

void SaleDiscountDlg::setSaleDetails(const QList<SaleDetails> &listSaleDetails )
{
    initData();
    m_listSaleDetails = listSaleDetails;

    updateOrgSum();
    updateDiscount();
    updateTotalSwapAmt();
    updateTotalDiscountAmt();
}

void SaleDiscountDlg::setMember( bool bMember )
{
    m_bMember = bMember;
}

void SaleDiscountDlg::setSaleHeadDis( bool bSaleHeadDis )
{
    m_bSaleHeadDis = bSaleHeadDis;
}

void SaleDiscountDlg::initCtrl()
{
    ui->titleWidget->setTitleText( "折扣" );

    QRegExp regx("[1-9][0-9]");
    QRegExpValidator *pReg = new QRegExpValidator( regx, this);
    ui->rediscountEdit->setValidator( pReg );
}

void SaleDiscountDlg::initConnect()
{
    connect( ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(close()) );
    //数字键盘
    connect( ui->DigitalKeyWnd, SIGNAL( sigText(QString)), this, SLOT( slot_setText(QString) ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigDelete()), this, SLOT( slot_deleteValue() ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigClear()), this, SLOT( slot_clearZero() ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigConfirm()), this, SLOT( slot_enter()) );

    connect( ui->rediscountEdit, SIGNAL(textChanged(QString)), this, SLOT( slot_rediscountChanged(QString) ) );
    connect( ui->disCommitBtn, SIGNAL(clicked()), this, SLOT( slot_enter() ) );
}

//软键盘输入
void SaleDiscountDlg::firstClick()
{
    if( m_bFirst ) {
        QLineEdit *p_wnd = NULL;
        bool b_has_focus = getCurFocusWnd( p_wnd );
        if( !b_has_focus ) return;

        p_wnd->setText( "" );

        m_bFirst = false;
    }
}

bool SaleDiscountDlg::getCurFocusWnd( QLineEdit *&pEditWnd )
{
    pEditWnd = (QLineEdit*)focusWidget();
    if( ui->rediscountEdit == pEditWnd ) {
        return true;
    }

    return false;
}

//默认为2位小数点
int SaleDiscountDlg::findDecimalsNum()
{
    QLineEdit *p_wnd = NULL;
    bool bWndFocus = getCurFocusWnd( p_wnd );
    if( !bWndFocus ) return -1;

    QString str_value = p_wnd->text();
    QStringList str_list = str_value.split( "." );
    if( str_list.size() == 2 ) {
        QString str_dec = str_list[1];
        return str_dec.length();
    }

    return 0;
}

bool SaleDiscountDlg::findPoint()
{
    QLineEdit *p_wnd = NULL;
    bool bWndHasFocus = getCurFocusWnd( p_wnd );
    if( !bWndHasFocus ) return true;

    QString str_point = p_wnd->text();
    for( int i = 0; i < str_point.length(); i++ ) {
        if( str_point[i] == '.' ) {
            return true;
        }
    }

    return false;
}

void SaleDiscountDlg::updateOrgSum()
{
    float fOrgSum = 0.00;
    QString strOrgSum = "";
    QList<SaleDetails>::iterator it = m_listSaleDetails.begin();
    for( ; it != m_listSaleDetails.end(); ++it ) {
        fOrgSum += it->strOrgSum.toFloat();
    }

    strOrgSum = CommonFun::floatToString( fOrgSum );
    ui->originalAmtValueLabel->setText( "￥" + strOrgSum );
}

void SaleDiscountDlg::updateDiscount()
{
    float fDis = 0.00;
    QString strDis = "";
    bool bDisEq = true;
    QList<SaleDetails>::iterator it = m_listSaleDetails.begin();
    fDis = it->fGrantDisRate;
    for( ; it != m_listSaleDetails.end(); ++it ) {
        if( fDis != it->fGrantDisRate ) {
            bDisEq = false;
            break;
        }
    }

    if( bDisEq && fDis != 0.00 ) {
        strDis = CommonFun::floatToString( fDis );
        ui->discountValueLabel->setText( strDis + "折");
    } else {
        ui->discountValueLabel->setText( "" );
    }
}

void SaleDiscountDlg::updateNowDiscount()
{
    QString strDiscount = ui->rediscountEdit->text();
    if( strDiscount.isEmpty() ) return;
    if( strDiscount.toFloat() < 1 ) {
        ui->rediscountEdit->setText( "" );
        return;
    }

    if( strDiscount.size() == 2 ) {
        float fDiscount = strDiscount.toFloat()/10.0;
        strDiscount.sprintf( "%.1f", fDiscount );
        ui->rediscountEdit->setText( strDiscount );
    }
}

void SaleDiscountDlg::updateSwapAmt()
{
    QString strRedis = ui->rediscountEdit->text();
    if( strRedis.isEmpty() ) return;

    float fSwapAmt = 0.00;

    QList<SaleDetails>::iterator it = m_listSaleDetails.begin();
    for( ; it != m_listSaleDetails.end(); ++it ) {
        fSwapAmt = it->strSwapAmt.toFloat()*strRedis.toFloat()*0.10;
        it->strSwapAmt = CommonFun::floatToString( fSwapAmt );
        if( it->fGrantDisRate > 0.00 ) {
            it->fGrantDisRate = it->fGrantDisRate * strRedis.toFloat()*0.10;
        } else {
            it->fGrantDisRate = strRedis.toFloat();
        }

        if( it->fGrantDisRate > 0.00 ) {
            it->goodsInfo.bDisCount = true;
        } else {
            it->goodsInfo.bDisCount = false;
        }

        it->goodsInfo.fPrice = it->goodsInfo.fPrice*strRedis.toFloat()*0.10;
        it->goodsInfo.sSumPrice = it->strSwapAmt;
    }
}

void SaleDiscountDlg::updateDiscountAmt()
{
    QList<SaleDetails>::iterator it = m_listSaleDetails.begin();
    for( ; it != m_listSaleDetails.end(); ++it ) {
        it->fAllDisAmt = it->strOrgSum.toFloat() - it->strSwapAmt.toFloat();
    }
}

void SaleDiscountDlg::updateTotalSwapAmt()
{
    float fSwapSum = 0.00;
    QString strSwapSum = "";
    QString strRedis = ui->rediscountEdit->text();

    QList<SaleDetails>::iterator it = m_listSaleDetails.begin();
    for( ; it != m_listSaleDetails.end(); ++it ) {

        if( strRedis.isEmpty() ) {
            fSwapSum += it->strSwapAmt.toFloat();
        } else {
            fSwapSum += it->strSwapAmt.toFloat()*strRedis.toFloat()*0.10;
        }
    }

    strSwapSum = CommonFun::floatToString( fSwapSum );
    ui->transAmtValueLabel->setText( "￥" + strSwapSum );
}

void SaleDiscountDlg::updateTotalDiscountAmt()
{
    QString strOrgSum = ui->originalAmtValueLabel->text();
    QList<QString> strOrgSumList = strOrgSum.split( "￥" );
    if( strOrgSumList.size() != 2 ) return;
    float fOrgSum = strOrgSumList[1].toFloat();

    QString strSwapSum = ui->transAmtValueLabel->text();
    QList<QString> strSwapSumList = strSwapSum.split( "￥" );
    if( strSwapSumList.size() != 2 ) return;
    float fSwapSum = strSwapSumList[1].toFloat();

    float fGrantDis = fOrgSum - fSwapSum;
    QString strGrantDis = CommonFun::floatToString( fGrantDis );
    ui->disAmtValueLabel->setText( "￥" + strGrantDis );
}

void SaleDiscountDlg::slot_setText( QString strText )
{
    firstClick();

    //非会员卡结算
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( ui->rediscountEdit == p_wnd && strText == "." ) return;
    if( p_wnd->text().isEmpty() && ( strText == "0" || strText == "00" )  ) return;
    if( ui->rediscountEdit == p_wnd && p_wnd->text().size() >= 2 ) return;

    int nNum = findDecimalsNum();
    if( strText == "00" && nNum >= 1 ) return;
    if( findPoint() && strText == "." ) return;
    if( nNum >= 2 ) return;

    QString sText = p_wnd->text();
    p_wnd->setText( sText.append( strText ) );
}

void SaleDiscountDlg::slot_deleteValue()
{
    if( m_bFirst ) {
        m_bFirst = false;
    }

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    QString str_value = p_wnd->text();
    str_value.remove( str_value.length() - 1, 1);
    p_wnd->setText( str_value );
}

void SaleDiscountDlg::slot_clearZero()
{
    firstClick();

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    p_wnd->setText( "" );
}

void SaleDiscountDlg::slot_enter()
{
    if( ui->rediscountEdit->text().isEmpty() ) return;

    updateSwapAmt();
    updateDiscountAmt();

    emit sig_commit( m_listSaleDetails, m_bSaleHeadDis );
    close();
}

void SaleDiscountDlg::slot_rediscountChanged( QString strText )
{
    Q_UNUSED( strText )

    updateNowDiscount();
    updateTotalSwapAmt();
    updateTotalDiscountAmt();
}
