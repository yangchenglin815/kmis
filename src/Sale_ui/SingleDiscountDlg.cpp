#include "SingleDiscountDlg.h"
#include "ui_SingleDiscountDlg.h"
#include "CommonFun.h"
#include "KPosSetAgent.h"

SingleDiscountDlg::SingleDiscountDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SingleDiscountDlg)
    , m_bFirst( true )
    , m_bMember( false )
{
    ui->setupUi(this);
    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    setModal( true );

    initCtrl();
    initConnect();
    setWindowTitle("折扣");
}

SingleDiscountDlg::~SingleDiscountDlg()
{
    delete ui;
}

void SingleDiscountDlg::initData()
{
    ui->goodsNameValueLabel->setText( "" );
    ui->barCodeValueLabel->setText( "" );
    ui->originalAmtValueLabel->setText( "" );
    ui->discountValueLabel->setText( "" );
    ui->rediscountEdit->setText( "" );
    ui->nowAmtEdit->setText( "" );
    ui->transAmtValueLabel->setText( "" );
    ui->disAmtValueLabel->setText( "" );
}

//设置销售明细信息
void SingleDiscountDlg::setSaleDetails( SaleDetails stSaleDetails )
{
    initData();
    m_stSaleDetails = stSaleDetails;

    QString strName = "";
    if( m_stSaleDetails.goodsInfo.strGoodsShortName.isEmpty() ) {
        strName = m_stSaleDetails.goodsInfo.sGoodsName;
    } else {
        strName = m_stSaleDetails.goodsInfo.strGoodsShortName;
    }

    ui->goodsNameValueLabel->setText( strName );
    ui->barCodeValueLabel->setText( m_stSaleDetails.strBarCode );
    ui->originalAmtValueLabel->setText( "￥" + CommonFun::floatToString( m_stSaleDetails.fPrice ) );

    QString strGrantDisRate = "";
    if( m_stSaleDetails.fGrantDisRate > 0.00 ) {
        strGrantDisRate = CommonFun::floatToString( m_stSaleDetails.fGrantDisRate ) + "折";
    }

    QString strSingleDisAmt = CommonFun::floatToString( m_stSaleDetails.fPrice - m_stSaleDetails.goodsInfo.fPrice );
//    QString strAllDisAmt = CommonFun::floatToString( m_stSaleDetails.fAllDisAmt );
    ui->discountValueLabel->setText( strGrantDisRate );
    ui->transAmtValueLabel->setText( "￥" + CommonFun::floatToString( m_stSaleDetails.fSwapPrice ) );
    ui->disAmtValueLabel->setText( "￥" + strSingleDisAmt );
}

void SingleDiscountDlg::setMember( bool bMember )
{
    m_bMember = bMember;
}

void SingleDiscountDlg::initCtrl()
{
    ui->titleWidget->setTitleText( "单品折扣" );

    QRegExp regx("[1-9][0-9]");
    QRegExpValidator *pReg = new QRegExpValidator( regx, this);
    ui->rediscountEdit->setValidator( pReg );
}

void SingleDiscountDlg::initConnect()
{
    connect( ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(close()) );
    //数字键盘
    connect( ui->DigitalKeyWnd, SIGNAL( sigText(QString)), this, SLOT( slot_setText(QString) ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigDelete()), this, SLOT( slot_deleteValue() ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigClear()), this, SLOT( slot_clearZero() ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigConfirm()), this, SLOT( slot_enter()) );

    //百
    connect( ui->twentyButton, SIGNAL(clicked()), this, SLOT( slot_twenty() ) );
    connect( ui->fiftyButton, SIGNAL(clicked()), this, SLOT( slot_fifty() ) );
    connect( ui->hundredButton, SIGNAL(clicked()), this, SLOT( slot_hundred() ) );
    connect( ui->twoHundredButton, SIGNAL(clicked()), this, SLOT( slot_twoHundred() ) );

    connect( ui->rediscountEdit, SIGNAL(textChanged(QString)), this, SLOT( slot_rediscountChanged(QString) ) );
    connect( ui->nowAmtEdit, SIGNAL(textChanged(QString)), this, SLOT( slot_amtChanged( QString) ) );
    connect( ui->disCommitBtn, SIGNAL(clicked()), this, SLOT( slot_enter() ) );
}

//软键盘输入
void SingleDiscountDlg::firstClick()
{
    if( m_bFirst ) {
        QLineEdit *p_wnd = NULL;
        bool b_has_focus = getCurFocusWnd( p_wnd );
        if( !b_has_focus ) return;

        p_wnd->setText( "" );

        m_bFirst = false;
    }
}

bool SingleDiscountDlg::getCurFocusWnd( QLineEdit *&pEditWnd )
{
    pEditWnd = (QLineEdit*)focusWidget();
    if( ui->rediscountEdit == pEditWnd \
            || ui->nowAmtEdit == pEditWnd  ) {
        return true;
    }

    return false;
}

//默认为2位小数点
int SingleDiscountDlg::findDecimalsNum()
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

bool SingleDiscountDlg::findPoint()
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

void SingleDiscountDlg::updateDiscount()
{
    QString strDiscount = ui->rediscountEdit->text();
    if( strDiscount.isEmpty() ) return;

    if( strDiscount.size() == 2 ) {
        float fDiscount = strDiscount.toFloat()/10.0;
        strDiscount.sprintf( "%.1f", fDiscount );
        ui->rediscountEdit->setText( strDiscount );
    }
}

void SingleDiscountDlg::updateSwapAmt()
{
    if( ui->nowAmtEdit->text().isEmpty() ) {
        ui->transAmtValueLabel->setText( ui->originalAmtValueLabel->text() );
    } else {
        ui->transAmtValueLabel->setText( "￥" + ui->nowAmtEdit->text() );
    }
}

//更新折扣金额Amt == amount
void SingleDiscountDlg::updateDiscountAmt()
{
    QString strDisAmt = "";
    float fDisAmt = 0.00;
    fDisAmt = m_stSaleDetails.fPrice - ui->nowAmtEdit->text().toFloat();
    strDisAmt.sprintf( "￥%.2f", fDisAmt );
    ui->disAmtValueLabel->setText( strDisAmt );
}

void SingleDiscountDlg::disChangeToAmt()
{
    if( ui->rediscountEdit != (QLineEdit*)focusWidget() ) return;
    //1. 如果为空，
    if( ui->rediscountEdit->text().isEmpty() ) {
        ui->nowAmtEdit->setText( "" );
        updateSwapAmt();
        updateDiscountAmt();
        return;
    }

    QString strDis = ui->rediscountEdit->text();
    QStringList strList = strDis.split( "." );
    float fDis = 0.0;
    if( strList.size() != 2 && strDis.size() == 2 ) {
        fDis = strDis.toFloat()*0.1;
        strDis.sprintf( "%.1f", fDis );
        ui->rediscountEdit->setText( strDis );
    } else {
        fDis = strDis.toFloat();
    }

    float fDisPrice = 0.00;
    if( ui->discountValueLabel->text().isEmpty() ) {
        fDisPrice = m_stSaleDetails.fPrice*fDis/10.0;
    } else {
        fDisPrice = m_stSaleDetails.goodsInfo.fPrice*fDis/10.0;
    }
    QString strDisPrice = CommonFun::floatToString( fDisPrice );
    ui->nowAmtEdit->setText( strDisPrice );

    updateSwapAmt();
    updateDiscountAmt();
}

void SingleDiscountDlg::amtChangeToDis()
{
    if( ui->nowAmtEdit != (QLineEdit*)focusWidget() ) return;

    if( ui->nowAmtEdit->text().isEmpty() ) {
        ui->rediscountEdit->setText( "" );
        updateSwapAmt();
        updateDiscountAmt();
        return;
    }
    float fDis = 0.0;
    QString strDis = "";
    if( ui->nowAmtEdit->text().toFloat() - m_stSaleDetails.fPrice>=0.00 ) {
        ui->rediscountEdit->setText( "" );
    } else {
        fDis = (ui->nowAmtEdit->text().toFloat()*1.00)/m_stSaleDetails.fPrice*10;
        strDis.sprintf( "%.1f", fDis );
        ui->rediscountEdit->setText( strDis );
    }

    updateSwapAmt();
    updateDiscountAmt();
}

void SingleDiscountDlg::slot_setText( QString strText )
{
    firstClick();

    //非会员卡结算
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( ui->rediscountEdit == p_wnd && strText == "." ) return;
    if( p_wnd->text().isEmpty() && /*( strText == "0" || */strText == "00" /*)*/  ) return;
    if( ui->rediscountEdit == p_wnd && p_wnd->text().size() >= 2 ) return;
    if( ui->rediscountEdit == p_wnd && p_wnd->text().size() >= 1 && strText == "00" ) return;

    int nNum = findDecimalsNum();
    if( strText == "00" && nNum >= 1 ) return;
    if( findPoint() && strText == "." ) return;
    if( nNum >= 2 ) return;

    QString sText = p_wnd->text();
    p_wnd->setText( sText.append( strText ) );
}

void SingleDiscountDlg::slot_deleteValue()
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

void SingleDiscountDlg::slot_clearZero()
{
    firstClick();

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    p_wnd->setText( "" );
}

void SingleDiscountDlg::slot_enter()
{
    if( ui->rediscountEdit->text().isEmpty() && ui->nowAmtEdit->text().isEmpty() ) return;

    KPosSet stKPosSet;
    KPosSetAgent::instance()->getKPosSetInfo( stKPosSet );
    if( !ui->nowAmtEdit->text().isEmpty() ) {
        if( !stKPosSet.paramsSet.shopSetParams.bSellZeroGoodsBySeller && ui->nowAmtEdit->text().toFloat()<= 0.00 ) return;

        m_stSaleDetails.goodsInfo.fPrice = ui->nowAmtEdit->text().toFloat();
        m_stSaleDetails.fSwapPrice = m_stSaleDetails.goodsInfo.fPrice;
    }

//    if( !ui->rediscountEdit->text().isEmpty() ) {
//        m_stSaleDetails.goodsInfo.fPrice = m_stSaleDetails.goodsInfo.fPrice*ui->rediscountEdit->text().toFloat()*0.10;
//        m_stSaleDetails.fSwapPrice = m_stSaleDetails.goodsInfo.fPrice;
//    } else {
//        if( m_bMember ) {
//            m_stSaleDetails.goodsInfo.fPrice = m_stSaleDetails.fMemPrice;
//        } else {
//            m_stSaleDetails.goodsInfo.fPrice = m_stSaleDetails.fPrice;
//        }
//        m_stSaleDetails.fSwapPrice = m_stSaleDetails.goodsInfo.fPrice;
//    }

    m_stSaleDetails.fGrantDisRate = ui->rediscountEdit->text().toFloat();

    if( m_stSaleDetails.fGrantDisRate > 0 ) {
        m_stSaleDetails.goodsInfo.bDisCount = true;
    } else {
        m_stSaleDetails.goodsInfo.bDisCount = false;
    }

    if( !ui->nowAmtEdit->text().isEmpty() ) {
        m_stSaleDetails.goodsInfo.sSumPrice = CommonFun::handleMoneyCoin(ui->nowAmtEdit->text().toFloat()*m_stSaleDetails.goodsInfo.fNumber);
        m_stSaleDetails.strSwapAmt = m_stSaleDetails.goodsInfo.sSumPrice;
    }

    if( !ui->disAmtValueLabel->text().isEmpty() ) {
        m_stSaleDetails.fAllDisAmt = ui->disAmtValueLabel->text().split( "￥" )[1].toFloat() * m_stSaleDetails.goodsInfo.fNumber;
    }
    emit sig_commit( m_stSaleDetails );
    close();
}

void SingleDiscountDlg::slot_twenty()
{
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;
    if( ui->rediscountEdit == p_wnd ) return;
    firstClick();

    p_wnd->setText( "20" );
}

void SingleDiscountDlg::slot_fifty()
{
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;
    if( ui->rediscountEdit == p_wnd ) return;
    firstClick();

    p_wnd->setText( "50" );
}

void SingleDiscountDlg::slot_hundred()
{
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;
    if( ui->rediscountEdit == p_wnd ) return;
    firstClick();

    p_wnd->setText( "100" );

}

void SingleDiscountDlg::slot_twoHundred()
{
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;
    if( ui->rediscountEdit == p_wnd ) return;
    firstClick();

    p_wnd->setText( "200" );
}

void SingleDiscountDlg::slot_rediscountChanged( QString strText )
{
    Q_UNUSED( strText )

    disChangeToAmt();
}

void SingleDiscountDlg::slot_amtChanged( QString strText )
{
    Q_UNUSED( strText )

    amtChangeToDis();
}

