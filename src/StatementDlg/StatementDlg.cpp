#include "StatementDlg.h"
#include "ui_StatementDlg.h"
#include "SatementAgent.h"
#include "CommonFun.h"
#include "DlgCommon.h"
#include "OddChangeDlg.h"
#include "AlipayRechargeDlg.h"
#include "KPosIni.h"
#include "OnlineStateAgent.h"
#include "RefundPayDlg.h"
#include "MemPayDlg.h"
#include "EnumToString.h"
#include "KPosSetAgent.h"
#include "BalanceManage.h"
#include <QDebug>
#include <QMessageBox>
#include "TipsDlg.h"
#include "KPosLog.h"
#include "globaldata.h"

const QString strPaymentText = "支付详情";
const QString strDisText = "折";
const float fEpsinon = 0.1;
const float fNetPayEpsinon = 0.01;

StatementDlg::StatementDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatementDlg)
  , m_pStatementCtr( NULL )
  , m_pPayDetailsDlg( NULL )
  , m_nClickedNum( 0 )
  , m_fSmallChange( 0.00 )
  , m_bFirst( true )
  , m_bModify( true )
  , m_eCurPayState( e_PayWaiting )
  , m_eCurPayType( e_Payment )
  , m_nOnePageCount( 5 )
  , m_nCurPageNum( 1 )
  , m_nTotalPageNum( 1 )
  , m_bOnline( true )
  , m_bDiscardZero( true )
  , m_pAlipayRechargeDlg(NULL)
{
    ui->setupUi(this);

    setWindowTitle("结算");
    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    setModal( true );
    ui->titleWidget->setTitleText( "结算" );
    ui->titleWidget->setCloseButtonFocus( false );
    ui->integUseMemEdit->setValidator(new QIntValidator(0, 100000, this));

    m_pStatementCtr = new StatementCtr( this );

    initCtrl();
    initPayMethod();
    initConnect();
    slot_payInfoChanged();//结算按键支付初始化
    bool bOnline = OnlineStateAgent::instance()->isOnline();
    slot_OnlineState( bOnline );
}

StatementDlg::~StatementDlg()
{
    delete ui;
}

void StatementDlg::setStatementInfo( StatementInfo stStatementInfo )
{
    initCtrl();

    if( m_listPayInfo.size() > 0 ) {
        m_nCurPageNum = 1;
        updatePayMethod();
    }

    m_stStatementInfo = stStatementInfo;

    //使用Agent访问数据库，获取该订单 总的支付数和成功的支付数
    //根据订单号，从数据库获取支付详情信息，并加载到支付对话框中
    QList<PayDetail_s> listPayDetails;
    QList<PaymentDetailInfo*> listPaymentDetails;
    m_pStatementCtr->getPayDetailsList( m_stStatementInfo.strOrderNum, listPayDetails );

    QList<PayDetail_s>::iterator it = listPayDetails.begin();
    for( int i = 1 ; it != listPayDetails.end(); ++it ) {
        PaymentDetailInfo *pPayDetailsInfo = new PaymentDetailInfo;
        pPayDetailsInfo->sPaymentSequence = it->strOrderNum;
        pPayDetailsInfo->strPaymentOrderNum = it->strPaymentOrderNum;
        pPayDetailsInfo->ePayMethod = (EPayMethod)it->nPayMethod;
        pPayDetailsInfo->fPaymentSum = it->fPayMoney;
        pPayDetailsInfo->ePaymentState = (EPaymentState)it->nStatus;
        pPayDetailsInfo->ePayType = (EPaymentType)it->nPayType;
        pPayDetailsInfo->nPos = i++;
        switch( pPayDetailsInfo->ePayType ) {
        case e_Payment:
            if( pPayDetailsInfo->ePaymentState == e_PayFailed ) {
                pPayDetailsInfo->eButtonStatus = eDisAble;
                m_stStatementInfo.nTotalNum += 1;
            } else if( pPayDetailsInfo->ePaymentState == e_PaySuccess ){
                m_stStatementInfo.nSucNum += 1;
                m_stStatementInfo.nTotalNum += 1;
            }
            break;
        case e_Refund:
            if( pPayDetailsInfo->ePaymentState == e_PaySuccess ) {
                pPayDetailsInfo->eButtonStatus = eDisAble;
                m_stStatementInfo.nTotalNum += 1;
            } else if( pPayDetailsInfo->ePaymentState == e_PayRefund ) {
                pPayDetailsInfo->eButtonStatus = eDisAble;
                m_stStatementInfo.nTotalNum += 1;
            }
            break;
        }

        listPaymentDetails.push_back( pPayDetailsInfo );
    }

    setPayDetailsText( m_stStatementInfo.nSucNum, m_stStatementInfo.nTotalNum );
    QString strDisText = "";
    if( m_stStatementInfo.fDiscount > 0.00 ) {
        strDisText = CommonFun::floatToString( m_stStatementInfo.fDiscount );
    }

    QString strDisAmtText = CommonFun::floatToString( m_stStatementInfo.fDisAmt );
    QString strSimpleAmt = CommonFun::floatToString(m_stStatementInfo.fSimpleAmt);

    ui->virtualPayWidget->getVirtualAmtEdit()->setText( strSimpleAmt );
    ui->discountValueLabel->setText( strDisText );
    ui->disAmtValueLabel->setText( "￥" + strDisAmtText );
    ui->simpleAmtValueLabel->setText( "￥" + strSimpleAmt );
    ui->amtPaidValueLabel->setText( "￥0.00" );
    ui->receivedValueLabel->setText( "￥" + strSimpleAmt  );

    strSimpleAmt = CommonFun::handleCash(m_stStatementInfo.fSimpleAmt);
    ui->factAmtCashEdit->setText( strSimpleAmt );
}

void StatementDlg::setSaleDetailsModify( bool bModify )
{
    m_bModify = bModify;
}

bool StatementDlg::getSaleDetailsModify()
{
    return m_bModify;
}

void StatementDlg::setMemInfo( MemRegisterInfo_s stMemInfo )
{
    m_stMemInfo = stMemInfo;
}

void StatementDlg::setDiscardZero( bool bDiscardZero )
{
    m_bDiscardZero = bDiscardZero;
    ui->samllChangeButton->setEnabled( m_bDiscardZero );
}

void StatementDlg::updateSaleHeadMemInfo( QString strOrderNum, MemRegisterInfo_s stMemRegInfo )
{
    SatementAgent::Instance()->updateSaleHeadMemInfo( strOrderNum, stMemRegInfo );
}

//任务栏上窗口关闭判断
bool StatementDlg::event(QEvent *event)
{
    if( event->type() == QEvent::Close ) {
        event->ignore();
        return true;
    }

    return QDialog::event( event );
}

void StatementDlg::slot_closeWnd()
{
    //1. 如果已收金额为零，则可以关闭窗口；否则，不可以关闭窗口
    QString strAmtPaid = ui->amtPaidValueLabel->text();
    QStringList strList = strAmtPaid.split( "￥" );
    if( (strList.size() == 2) && ((strList[1] == "0") || (strList[1] == "0.0") || (strList[1] == "0.00")) ) {
        hide();
    }
}

//支付方式按钮状态
void StatementDlg::slot_OnlineState( bool bOnline )
{    
    if( m_bOnline == bOnline && !bOnline ) return;

    m_bOnline = bOnline;

    if( bOnline ) {//有网
        //所有按钮有效
        QList< StatementMethodButton *>::iterator it = m_listPayButton.begin();
        for( ; it != m_listPayButton.end(); ++it ) {
            (*it)->setEnabled( true );
        }
    } else {
        //列表更新到按钮首页
        m_nCurPageNum = 1;
        updatePayButton( m_nCurPageNum );
        //除了现金和储值卡，其他按钮无效
        QList< StatementMethodButton *>::iterator it = m_listPayButton.begin();
        for( int i = 0; it != m_listPayButton.end(); ++it,++i ) {
            if( (*it)->getPayInfo().nPayType != PayCash && !(*it)->getPayInfo().bVirtualPay ) {
                (*it)->setEnabled( false );
            } else if( (*it)->getPayInfo().nPayType == PayCash /*&& m_eCurPayMethod != PayCash
                       && m_eCurPayMethod != PayStoreCard*/ ) {
                emit (*it)->click();
            }
        }
    }
}

void StatementDlg::slot_showPayMethodWnd()
{
    StatementMethodButton *pBtn = (StatementMethodButton*)sender();
    switch( pBtn->getPayInfo().nPayType ) {
    case PayNull:
        break;
    case PayCash:
    case UnionPay:
    case PayMemCard:
    case PayStoreCard:
    case PayAlipay:
    case PayWeChat:
    case ApplePay:
    case JdWallet:
    case Coupon:
    case VirtualPayPage:
    case PayEntityCard:
    case e_virtualPay:
    {
        if(pBtn->getPayInfo().nPayType == Coupon){
            if( m_stStatementInfo.fCouponDisAmt > 0.00) {
                WarningDlg *pDlg = new WarningDlg();
                pDlg->setTitle( "提示" );
                pDlg->setContent( "一个订单只能使用一张优惠券" );
                pDlg->exec();
                return;
            }
//            //当金额小于50时候选择优惠券不切换
//            if(m_stStatementInfo.fSimpleAmt < 50)
//            {
//                WarningDlg *pDlg = new WarningDlg();
//                pDlg->setTitle( "提示" );
//                pDlg->setContent( "金额小于50元无法使用优惠券" );
//                pDlg->exec();
//                return;
//            }
        }

        initUnSelectPayMethod();
        pBtn->setSelectedSelf();
        m_stCurPayInfo = pBtn->getPayInfo();
        payMethodStatement();
    }
        break;
    case PayFrontPage:
        slot_frontPage();
        updateSelectPayButton();
        break;
    case PayNextPage:
        slot_nextPage();
        updateSelectPayButton();
        break;
    default:
        break;
    }

}

void StatementDlg::slot_showCashPay()
{
    ui->stackedWidget->setCurrentIndex( 0 );
    StatementMethodButton *pBtn = (StatementMethodButton *)sender();
    m_stCurPayInfo = pBtn->getPayInfo();

    QString strReceived = ui->receivedValueLabel->text().split("￥")[1];
    //strReceived = strReceived.left( strReceived.size() -1);
    strReceived = updateCashRoundWay( strReceived );
    ui->factAmtCashEdit->setText( strReceived );
}

void StatementDlg::slot_showUnionPay()
{
    ui->stackedWidget->setCurrentWidget( ui->unionPayWidget );
    StatementMethodButton *pBtn = (StatementMethodButton *)sender();
    m_stCurPayInfo = pBtn->getPayInfo();

    QString strText = "";
    QStringList strList = ui->receivedValueLabel->text().split( "￥" );
    if( strList.size() == 2 ) {
        strText = strList[1];
    } else {
        strText = "0.00";
    }
    //strText = updateOtherRoundWay( strText );
    ui->factAmtUnionEdit->setText( strText );
}

void StatementDlg::slot_showMemCardPay()
{
    ui->stackedWidget->setCurrentIndex( 1 );
    StatementMethodButton *pBtn = (StatementMethodButton *)sender();
    m_stCurPayInfo = pBtn->getPayInfo();
    QString strText = "";
    if( !m_stMemInfo.stMemInfo.strAccountBalance.isEmpty() ) {
        ui->id_lab_mem_card_value->setText( "￥" + m_stMemInfo.stMemInfo.strAccountBalance );
        QStringList strList = ui->receivedValueLabel->text().split("￥");
        if( strList.size() == 2 ) {
            float fReceived = strList[1].toFloat();
            if( fReceived - m_stMemInfo.stMemInfo.strAccountBalance.toFloat() > 0.001 ) {
                strText = m_stMemInfo.stMemInfo.strAccountBalance;
            } else {
                strText = strList[1];
            }
        }
    } else {
        ui->id_lab_mem_card_value->setText( m_stMemInfo.stMemInfo.strAccountBalance );
        strText = m_stMemInfo.stMemInfo.strAccountBalance;
    }
    //strText = updateOtherRoundWay( strText );
    ui->balanceMemEdit->setText( strText );
    ui->id_lab_integ_value->setText( QString::number( m_stMemInfo.stMemInfo.nIntegral ) );
    //积分可抵现金
    float fExchangeCash = m_stMemInfo.strIntExchangeAmt.toFloat() * m_stMemInfo.stMemInfo.nIntegral;
    ui->id_lab_can_arrived_value->setText(QString::number(fExchangeCash, 'f', 2));
}

void StatementDlg::slot_storeCardPay()
{
    ui->useAmtStoreEdit->setText(ui->receivedValueLabel->text().split("￥")[1]);
    ui->stackedWidget->setCurrentIndex( 2 );
    StatementMethodButton *pBtn = (StatementMethodButton *)sender();
    m_stCurPayInfo = pBtn->getPayInfo();
    ui->cardIDStoreEdit->setFocus();
}

void StatementDlg::slot_alipayPay()
{
    ui->stackedWidget->setCurrentIndex( 3 );
    StatementMethodButton *pBtn = (StatementMethodButton *)sender();
    m_stCurPayInfo = pBtn->getPayInfo();

    QString strText = "";
    QStringList strList = ui->receivedValueLabel->text().split( "￥" );
    if( strList.size() == 2 ) {
        strText = strList[1];
    } else {
        strText = "0.00";
    }
    //strText = updateOtherRoundWay( strText );
    ui->factAmtAlipayEdit->setText( strText );
}

void StatementDlg::slot_weChatPay()
{
    ui->stackedWidget->setCurrentIndex( 4 );
    StatementMethodButton *pBtn = (StatementMethodButton *)sender();
    m_stCurPayInfo = pBtn->getPayInfo();

    QString strText = "";
    QStringList strList = ui->receivedValueLabel->text().split( "￥" );
    if( strList.size() == 2 ) {
        strText = strList[1];
    } else {
        strText = "0.00";
    }
    //strText = updateOtherRoundWay( strText );
    ui->factAmtWeEdit->setText( strText );
}

void StatementDlg::slot_applePay()
{
    ui->stackedWidget->setCurrentIndex( 5 );
    StatementMethodButton *pBtn = (StatementMethodButton *)sender();
    m_stCurPayInfo = pBtn->getPayInfo();

    QString strText = "";
    QStringList strList = ui->receivedValueLabel->text().split( "￥" );
    if( strList.size() == 2 ) {
        strText = strList[1];
    } else {
        strText = "0.00";
    }
    //strText = updateOtherRoundWay( strText );
    ui->factAmtAppleEdit->setText( strText );
}

void StatementDlg::slot_jdWalletPay()
{
    ui->stackedWidget->setCurrentIndex( 6 );
    StatementMethodButton *pBtn = (StatementMethodButton *)sender();
    m_stCurPayInfo = pBtn->getPayInfo();

    QString strText = "";
    QStringList strList = ui->receivedValueLabel->text().split( "￥" );
    if( strList.size() == 2 ) {
        strText = strList[1];
    } else {
        strText = "0.00";
    }
    //strText = updateOtherRoundWay( strText );
    ui->factAmtJdEdit->setText( strText );
}

//优惠券分页
void StatementDlg::slot_CouponPayWnd()
{
    ui->factAmtCouponEdit_1->setText( "" );
    ui->factAmtCouponEdit_2->setText( "" );
    ui->factAmtCouponLabel_3->setText( "" );

    ui->stackedWidget->setCurrentIndex( 7 );
    StatementMethodButton *pBtn = (StatementMethodButton *)sender();
    m_stCurPayInfo = pBtn->getPayInfo();

    QString strText = "";
    QStringList strList = ui->receivedValueLabel->text().split( "￥" );
    if( strList.size() == 2 ) {
        strText = strList[1];
    } else {
        strText = "0.00";
    }
    //strText = updateOtherRoundWay( strText );
//    ui->factAmtCouponEdit_2->setText( strText );
}

void StatementDlg::slot_VirtualPayWnd()
{
    ui->virtualPayWidget->setVirtualWidgetVisible(true);
    ui->stackedWidget->setCurrentWidget( ui->virtualPayWidget );
//    StatementMethodButton *pBtn = (StatementMethodButton *)sender();
//    m_stCurPayInfo = pBtn->getPayInfo();

    //默认选中第一种虚拟支付方式
    m_stCurPayInfo = ui->virtualPayWidget->getCurPayInfo();

    QString strText = "";
    QStringList strList = ui->receivedValueLabel->text().split( "￥" );
    if( strList.size() == 2 ) {
        strText = strList[1];
    } else {
        strText = "0.00";
    }
    ui->virtualPayWidget->getVirtualAmtEdit()->setText( strText );
}

void StatementDlg::slot_virtualPaysWnd()
{
    ui->stackedWidget->setCurrentWidget(ui->virtualPaysPage);
    QString strText = "";
    QStringList strList = ui->receivedValueLabel->text().split( "￥" );
    if( strList.size() == 2 ) {
        strText = strList[1];
    } else {
        strText = "0.00";
    }
    ui->virtualPaysPage->setFactorAmt(strText);
    ui->virtualPaysPage->initPayButtons(m_virtualPayList);
}

void StatementDlg::showPayCityCardWnd()
{
    ui->virtualPayWidget->clickPayBtn(e_PayEntityCard);
    ui->virtualPayWidget->setVirtualWidgetVisible(false);
    ui->stackedWidget->setCurrentWidget( ui->virtualPayWidget );
    m_stCurPayInfo = ui->virtualPayWidget->getCurPayInfo();

    QString strText = "";
    QStringList strList = ui->receivedValueLabel->text().split( "￥" );
    if( strList.size() == 2 ) {
        strText = strList[1];
    } else {
        strText = "0.00";
    }
    ui->virtualPayWidget->getVirtualAmtEdit()->setText( strText );
}

void StatementDlg::slot_frontPage()
{
    if( m_nCurPageNum < 0 ) return;

    //显示下一页的结算方式
    --m_nCurPageNum;
    updatePayButton( m_nCurPageNum );
}

void StatementDlg::slot_nextPage()
{
    if( m_nCurPageNum >= m_nTotalPageNum ) return;

    //显示下一页的结算方式
    ++m_nCurPageNum;
    updatePayButton( m_nCurPageNum );
}

void StatementDlg::initCtrl()
{
    ui->paymentDetailButton->setText( strPaymentText + "(0/0)" );
    ui->discountValueLabel->setText( strDisText );
    ui->disAmtValueLabel->setText( "￥0.00" );
    ui->simpleAmtValueLabel->setText( "￥0.00" );
    ui->amtPaidValueLabel->setText( "￥0.00" );
    ui->receivedValueLabel->setText( "￥0.00" );
    ui->factAmtCashEdit->setText( "" );
    //优惠券信息清空
    ui->factAmtCouponEdit_1->setText( "" );
    ui->factAmtCouponEdit_2->setText( "" );
    ui->factAmtCouponLabel_3->setText( "" );
    ui->factAmtCouponEdit_2->setEnabled(false);
    ui->factAmtCouponEdit_2->setFocusPolicy(Qt::NoFocus);

    ui->virtualPayWidget->initPayInfo();
    ui->virtualPayWidget->getVirtualAmtEdit()->setText( "" );//虚拟支付
    initMemInfo();
    setEnabled( true );
    m_nClickedNum = 0;
    m_fSmallChange = 0.00;
}

void StatementDlg::initMemInfo()
{
    ui->id_lab_mem_card_value->setText( "" );
    ui->id_lab_integ_value->setText( "" );
    ui->balanceMemEdit->setText( "" );
    ui->integUseMemEdit->setText( "" );
    ui->memWarningLabel->setText( "" );

    MemRegisterInfo_s stMemReg;
    m_stMemInfo = stMemReg;
}

void StatementDlg::initPayMethod()
{
//    m_listPayInfo.clear();
//    PayWayInfoSet stPayWayInfo;

//    stPayWayInfo.nPayType = PayCash;
//    m_listPayInfo.append( stPayWayInfo );
////    stPayWayInfo.nPayType = UnionPay;
////    m_listPayInfo.append( stPayWayInfo );
//    stPayWayInfo.nPayType = PayMemCard;
//    m_listPayInfo.append( stPayWayInfo );
//    stPayWayInfo.nPayType = PayStoreCard;
//    m_listPayInfo.append( stPayWayInfo );
//    stPayWayInfo.nPayType = PayAlipay;
//    m_listPayInfo.append( stPayWayInfo );
//    stPayWayInfo.nPayType = PayWeChat;
//    m_listPayInfo.append( stPayWayInfo );
//    stPayWayInfo.nPayType = ApplePay;
//    m_listPayInfo.append( stPayWayInfo );
//    stPayWayInfo.nPayType = JdWallet;
//    m_listPayInfo.append( stPayWayInfo );
//    stPayWayInfo.nPayType = Coupon;
//    m_listPayInfo.append( stPayWayInfo );
    m_listPayButton.clear();
    m_listPayButton.push_back( ui->payMethodBtn_1 );
    m_listPayButton.push_back( ui->payMethodBtn_2 );
    m_listPayButton.push_back( ui->payMethodBtn_3 );
    m_listPayButton.push_back( ui->payMethodBtn_4 );
    m_listPayButton.push_back( ui->payMethodBtn_5 );

//    if( m_listPayInfo.size() <= 5 ) {

//        m_nCurPageNum = 1;
//        m_nTotalPageNum = 1;
//    } else if( m_listPayInfo.size() >5 ) {
//        m_nCurPageNum = 1;
//        m_nTotalPageNum = getTotalNum();
//    }

//    updatePayButton( m_nCurPageNum );
//    emit ui->payMethodBtn_1->click();//默认显示第一个结算方式
}

void StatementDlg::updatePayMethod()
{
    updatePayButton( m_nCurPageNum );
    emit ui->payMethodBtn_1->click();//默认显示第一个结算方式

    bool bOnline = OnlineStateAgent::instance()->isOnline();
    slot_OnlineState( bOnline );
}

void StatementDlg::initConnect()
{
    connect( ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT( slot_closeWnd() ) );
    connect( OnlineStateAgent::instance(), SIGNAL(sigOnlineState(bool)), this, SLOT( slot_OnlineState(bool) ) );

    connect( ui->payMethodBtn_1, SIGNAL(clicked()), this, SLOT( slot_showPayMethodWnd() ) );
    connect( ui->payMethodBtn_2, SIGNAL(clicked()), this, SLOT( slot_showPayMethodWnd() ) );
    connect( ui->payMethodBtn_3, SIGNAL(clicked()), this, SLOT( slot_showPayMethodWnd() ) );
    connect( ui->payMethodBtn_4, SIGNAL(clicked()), this, SLOT( slot_showPayMethodWnd() ) );
    connect( ui->payMethodBtn_5, SIGNAL(clicked()), this, SLOT( slot_showPayMethodWnd() ) );

    //抹零
    connect( ui->samllChangeButton, SIGNAL( clicked(bool)), this, SLOT( slot_samllChange() ) );

    //数字键盘
    connect( ui->DigitalKeyWnd, SIGNAL( sigText(QString)), this, SLOT( slot_setText(QString) ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigDelete()), this, SLOT( slot_deleteValue() ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigClear()), this, SLOT( slot_clearZero() ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigConfirm()), this, SLOT( slot_statement()) );

    //百
    connect( ui->factorButton, SIGNAL(clicked()), this, SLOT( slot_factor_amt() ) );
    connect( ui->fiftyButton, SIGNAL(clicked()), this, SLOT( slot_fifty_amt() ) );
    connect( ui->hundredButton, SIGNAL(clicked()), this, SLOT( slot_hundred() ) );
    connect( ui->twoHundredButton, SIGNAL(clicked()), this, SLOT( slot_two_hundred() ) );

    //结算
    connect( ui->statementButton, SIGNAL(clicked()), this, SLOT( slot_statement() ) );
    connect( ui->statementMemButton, SIGNAL(clicked()), this, SLOT( slot_memberStatement() ) );
    connect( ui->integUseMemEdit, SIGNAL(textChanged(QString)), this, SLOT( slot_textChanged(QString) ) );
    //connect( ui->statementStoreButton, SIGNAL(clicked()), this, SLOT( slot_statement() ) );
    connect( ui->statementAlipayButton, SIGNAL(clicked()), this, SLOT( slot_statement() ) );
    connect( ui->statementWeButton, SIGNAL(clicked()), this, SLOT( slot_statement() ) );
    connect( ui->statementAppleButton, SIGNAL(clicked()), this, SLOT( slot_statement() ) );
    connect( ui->statementJdButton, SIGNAL(clicked()), this, SLOT( slot_statement() ) );
    connect( ui->statementUnionButton, SIGNAL(clicked()), this, SLOT( slot_statement()) );
    connect( ui->statementCouponButton, SIGNAL(clicked()), this, SLOT( slot_statement() ) );
    connect( ui->virtualPayWidget, SIGNAL(sig_virtualStatement()), this, SLOT( slot_statement() ) );
    connect(ui->virtualPaysPage, SIGNAL(sigConfirm()), this, SLOT(slot_virtualPaysStatement()));

    connect( ui->paymentDetailButton, SIGNAL(clicked(bool)), this, SLOT( slot_showPayDetailsDlg() ) );

    //支付返回信号
    connect( m_pStatementCtr, SIGNAL( sigOnCreatePayStatus(int,QString,QString,QString,EPayMethod)) \
             , this, SLOT( slot_memPayInfo( int,QString,QString,QString,EPayMethod ) ) );
    connect(m_pStatementCtr, SIGNAL(sigOnPayStoreCardInfo(int,QString,PayStoreCardInfo))
            , this, SLOT(slot_onPayStoreCardInfo(int,QString,PayStoreCardInfo)));
    connect(m_pStatementCtr, SIGNAL(sigOnCreatePayMemberCard(int,QString,QString,QString))
            , this, SLOT(slot_onCreatePayMemberCard(int,QString,QString,QString)));
    connect(m_pStatementCtr, SIGNAL(sigOnUpdateMemberIntegral(int,QString,int,QString))
            , this, SLOT(slot_onUpdateMemberIntegral(int,QString,int,QString)));

    connect( KPosSetAgent::instance(), SIGNAL(sigPayWaySetChanged()), this, SLOT( slot_payInfoChanged() ) );
}

void StatementDlg::initUnSelectPayMethod()
{
    QList< StatementMethodButton *>::iterator it = m_listPayButton.begin();
    for( ; it != m_listPayButton.end(); ++it ) {
        if( (*it)->getPayInfo().nPayType != PayFrontPage && (*it)->getPayInfo().nPayType != PayNextPage ) {
            (*it)->setUnSelectedSelf();
        }
    }

    PayWayInfoSet stPayInfo;
    m_stCurPayInfo = stPayInfo;
}

void StatementDlg::slot_samllChange()
{
    //只能在已支付金额为0的情况下，才能抹零
    if( ui->amtPaidValueLabel->text().split("￥")[1].toFloat() >= 0.01 ) return;

    m_nClickedNum++;

    int nNum = m_nClickedNum%2;
    QString strTotal = "";
    if( nNum == 1 ) {
        strTotal.sprintf( "%.2f", m_stStatementInfo.fSimpleAmt );
        QStringList strList = strTotal.split( "." );
        if( strList.size() == 2 ) {
            QString str = strList[1];
            if( str.toInt() >= 50 ) {
                strTotal = strList[0] + "." + QString::number( 50 );
            } else {
                int nTotalMoney = m_stStatementInfo.fSimpleAmt;
                strTotal.sprintf( "%.2f", (float)nTotalMoney );
            }
            m_fSmallChange = m_stStatementInfo.fSimpleAmt - strTotal.toFloat();
            ui->simpleAmtValueLabel->setText( "￥" + strTotal );
        }
    } else {
        int nTotalMoney = m_stStatementInfo.fSimpleAmt;
        m_fSmallChange = m_stStatementInfo.fSimpleAmt - (float)nTotalMoney;
        strTotal.sprintf( "￥%.2f", (float)nTotalMoney );
        ui->simpleAmtValueLabel->setText( strTotal );

    }

    refreashDiscountMoney();
    refreshReceivedAndFactMoney();
}

void StatementDlg::slot_setText( QString strText )
{
    QLineEdit* pEditWnd = (QLineEdit*)focusWidget();
    if (pEditWnd == ui->integUseMemEdit)
    {
        ui->integUseMemEdit->insert(strText);
        return;
    }

    firstClick();
    //非会员卡结算
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;
    if( p_wnd->text().isEmpty() && strText == "." ) return;

    if(p_wnd == ui->factAmtCouponEdit_1&& strText == ".") return;
    if( p_wnd == ui->cardIDStoreEdit && strText == "." ) return;

    int nNum = findDecimalsNum();
    if( m_stCurPayInfo.nPayType == PayCash ) {
        if( nNum >= 1 ) return;
    } else {
        if( nNum >= 2 ) return;
//        if( m_stCurPayInfo.nDropType == eUntreated ) {
//            if( nNum >= 2 ) return;
//        } else {
//            if( nNum >= 1 ) return;
//        }
    }
    if( strText == "00" && nNum >= 1 ) return;
    if( findPoint() && strText == "." ) return;


    QString sText = p_wnd->text().append( strText );
    p_wnd->setText( sText );
}

void StatementDlg::slot_deleteValue()
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

void StatementDlg::slot_clearZero()
{
    firstClick();

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    p_wnd->setText( "" );
}

void StatementDlg::slot_factor_amt()
{
    m_bFirst = true;

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( p_wnd == ui->integUseMemEdit ) return;

    QString str_amt_received = ui->receivedValueLabel->text().split( "￥" )[1];

//    if( m_stCurPayInfo.nPayType == PayCash ) {
//        str_amt_received = str_amt_received.left( str_amt_received.size() - 1 );
//    }
    str_amt_received = floatRoundWay( str_amt_received );

    p_wnd->setText( str_amt_received );
}

void StatementDlg::slot_fifty_amt()
{
    firstClick();

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( p_wnd == ui->integUseMemEdit ) return;

    p_wnd->setText( "50" );
}

void StatementDlg::slot_hundred()
{
    firstClick();

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( p_wnd == ui->integUseMemEdit ) return;

    p_wnd->setText( "100" );

}

void StatementDlg::slot_two_hundred()
{
    firstClick();

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( p_wnd == ui->integUseMemEdit ) return;

    p_wnd->setText( "200" );
}

//结算
void StatementDlg::slot_statement()
{
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( m_stCurPayInfo.nPayType == Coupon ) {
        ui->factAmtCouponEdit_2->setText("");
        if( m_stStatementInfo.fCouponDisAmt > 0.00 ) {
            ui->factAmtCouponLabel_3->setText( "一个订单只能使用一张优惠券" );
            return;
        } else if( ui->factAmtCouponEdit_1->text().isEmpty() ) {
            ui->factAmtCouponLabel_3->setText( "优惠券号不能为空" );
            return;
        } else if( ui->factAmtCouponEdit_1->text().size() != 9 ) {
            ui->factAmtCouponLabel_3->setText( "优惠券号长度不对" );
            return;
        }

        QString CouponNumber_1 = ui->factAmtCouponEdit_1->text().mid(0,4);
//        int CouponNumber_2 = ui->factAmtCouponEdit_1->text().mid(4,5).toInt();
        if(CouponNumber_1 != "9805"/* ||CouponNumber_2 > 10000 */){
            ui->factAmtCouponLabel_3->setText( "优惠券号错误" );
            return;
        }
        //添加金额
        ui->factAmtCouponEdit_2->setText("5");
    }

//    QString strFactAmt = "";
//    if( p_wnd != ui->integUseMemEdit && p_wnd != ui->factAmtCouponEdit_1 && p_wnd != ui->cardIDStoreEdit ) {
//        strFactAmt = p_wnd->text();
//        strFactAmt = floatRoundWay( strFactAmt ); // 应该不需要分的元整方式的处理
////        QList<QString> listFact = strFactAmt.split( "." );
////        if( listFact.size() == 2 && p_wnd->text().split(".")[1].isEmpty() ) {
////            strFactAmt = p_wnd->text() + "0";
////            p_wnd->setText( strFactAmt );
////        }
//        p_wnd->setText( strFactAmt );
//        if( p_wnd->text().toFloat()+0.003 < 0.01 ) return;
//    }

    if( p_wnd == ui->virtualPayWidget->getVirtualAmtEdit() ) {
        m_stCurPayInfo = ui->virtualPayWidget->getCurPayInfo();
    }

    //判断是哪种结算方式
    switch ( m_stCurPayInfo.nPayType ) {
    case PayCash:
        cashStatement();
        break;
    case UnionPay:
        virtualPayStatement( "银联卡虚拟支付" );
        break;
//    case PayMemCard:
//        memberStatement();
//        break;
    case PayStoreCard:
        storeCardStatement();
        break;
    case PayAlipay:
    case PayWeChat:
        if( m_stCurPayInfo.bVirtualPay ) {
            if( m_stCurPayInfo.nPayType == PayAlipay ) {
                virtualPayStatement( "支付宝虚拟支付" );
            } else if( m_stCurPayInfo.nPayType == PayWeChat ) {
                virtualPayStatement( "微信虚拟支付" );
            }
        } else {
            networkPayStatement();
        }
        break;
    case ApplePay:
        appleStatement();
        break;
    case JdWallet:
        jdWalletStatement();
        break;
    case Coupon:
        couponStatement();
        break;
    case PayCityCard://市民卡
        virtualPayStatement( "市民卡虚拟支付" );
        break;
    case PayFengCha: //果麦
        virtualPayStatement( "果麦虚拟支付" );
        break;
    case PayCheck: //支票
        virtualPayStatement( "支票虚拟支付" );
        break;
    case PayBills: //欠单
        virtualPayStatement( "欠单虚拟支付" );
        break;
    case PayEntityCard: //实体卡
        virtualPayStatement( "实体卡虚拟支付" );
        break;
    case PayOther: //其他
        virtualPayStatement( "其他虚拟支付" );
        break;
//    case e_virtualPay: // 虚拟支付
//        virtualPaysStatement();
        break;
    default:
        break;
    }
}

void StatementDlg::slot_virtualPaysStatement()
{
    virtualPaysStatement();
}

void StatementDlg::slot_textChanged( QString strText )
{
    if( m_stMemInfo.strIntExchangeAmt.toFloat() <= 0 ) {
        ui->integUseMemEdit->setText("0");
        ui->arrivedValueLabel->setText("0");
        return;
    }

    int nIntegral = strText.toInt();
//    if (nIntegral == 0)
//    {
//        ui->balanceMemEdit->setText(ui->receivedValueLabel->text().split( "￥" )[1]);
//        ui->arrivedValueLabel->setText("0");
//        return;
//    }

    if( nIntegral > ui->id_lab_integ_value->text().toInt() ) {
        nIntegral = ui->id_lab_integ_value->text().toInt();
    }

    float fExchangeAmt = nIntegral * m_stMemInfo.strIntExchangeAmt.toFloat();
    QString strExchangeAmt = CommonFun::floatToString( fExchangeAmt );
    ui->arrivedValueLabel->setText( strExchangeAmt );

    //更新抵现积分后，需要更新支付金额
    float fBalance = ui->balanceMemEdit->text().toFloat();
    QList<QString> listReceived = ui->receivedValueLabel->text().split( "￥" );
    float fReceived = 0.00;
    if( listReceived.size() != 2 ) return;

    fReceived = listReceived[1].toFloat();
//    if( fBalance + fExchangeAmt - fReceived > 0 && fReceived - fExchangeAmt>0 ) {
        fBalance = fReceived - fExchangeAmt;
        if (fBalance >= 0)
        {
            ui->balanceMemEdit->setText( CommonFun::floatToString( fBalance ) );
            ui->integUseMemEdit->setText( QString::number( nIntegral ) );
        }
        else
        {
            int nTempIntegral = (int) (fReceived / m_stMemInfo.strIntExchangeAmt.toFloat());
            ui->integUseMemEdit->setText( QString::number(nTempIntegral));
        }

//    } else {

//    }
}

void StatementDlg::slot_cashSure()
{
    QObject *p_obj = QObject::sender();
    if( p_obj ) {
        delete p_obj;
        p_obj = NULL;
    }

    BalanceManage::instance()->openCashBox();//打开钱箱
    //结算完成后，要更新 优惠金额到销售表中，实收金额，找零金额
    //点击确定，刷新界面
    float fTotalMoney = ui->simpleAmtValueLabel->text().split( "￥" )[1].toFloat();//4.95  整单金额
    float fAmtPaid = ui->amtPaidValueLabel->text().split( "￥" )[1].toFloat();//已付金额
    float fAmtReceived = ui->receivedValueLabel->text().split( "￥" )[1].toFloat();//待收金额
    float fFactAmt = ui->factAmtCashEdit->text().toFloat();//当前实际支付金额

    //通过Agent，加载支付详情信息到支付详情表
//    m_eCurPayState = e_PaySuccess;
//    PaymentDetailInfo stPaymentDetail;
//    getPayDetail( stPaymentDetail, fFactAmt );
//    stPaymentDetail.fPaymentSum = fFactAmt;
//    stPaymentDetail.strIntExchangeAmt = m_stMemInfo.strIntExchangeAmt;
//    m_pStatementCtr->insertPayDetailData( stPaymentDetail );

//    float fFactReceived = 0.00;
//    QString strRece = ui->receivedValueLabel->text().split( "￥" )[1];
////    strRece = updateCashRoundWay( strRece );
//    fFactReceived = strRece.toFloat();

    float fFactReceived = CommonFun::handleCash(fAmtReceived).toFloat();
    float f_diff = fFactReceived - fFactAmt;
//    qDebug()<<"aaaaaa -- "<<f_diff;
//    qDebug()<<"0000000 -- "<<CommonFun::handleMoneyCoin(f_diff);
    if(f_diff > 0.0001f) {
        fAmtPaid = fAmtPaid + fFactAmt;
        fAmtReceived = fTotalMoney - fAmtPaid;
        QString str_paid = "";
        QString str_received = "";
        str_paid.sprintf( "￥%.2f", fAmtPaid );
        str_received.sprintf( "%.2f", fAmtReceived );
        ui->amtPaidValueLabel->setText( str_paid );
        ui->receivedValueLabel->setText( "￥" + str_received );

        str_received = updateCashRoundWay( str_received );
        ui->factAmtCashEdit->setText( str_received );
    }
    else /*if( CommonFun::handleMoneyCoin(f_diff).toFloat() < fEpsinon ) */
    {//现金结算完成
        //损益
        m_stStatementInfo.fProfitLoss = fFactReceived - fAmtReceived;
        m_stStatementInfo.fOddChange =  CommonFun::handleCash(fFactAmt - fFactReceived).toFloat();
//        qDebug()<<"3333333333333 -- "<<fFactReceived;
//        qDebug()<<"4444444444444 -- "<<fAmtReceived;
//        qDebug()<<"5555555555555 -- "<<m_stStatementInfo.fOddChange;

        fAmtPaid = fAmtPaid + fFactAmt;
        m_stStatementInfo.fDisAmt = ui->disAmtValueLabel->text().split( "￥" )[1].toFloat();//优惠金额
        //找零窗口
        OddChangeDlg *p_dlg_odd = new OddChangeDlg();
        p_dlg_odd->setTitleText( "找零" );
        connect( p_dlg_odd, SIGNAL( sig_wnd_close()), this, SLOT( slot_closeOddChangeDlg() ) );
        p_dlg_odd->setData( fFactAmt, fAmtReceived, m_stStatementInfo.fOddChange );
        p_dlg_odd->show();
        fFactAmt -= m_stStatementInfo.fOddChange;
    }

    m_eCurPayState = e_PaySuccess;
    PaymentDetailInfo stPaymentDetail;
    getPayDetail( stPaymentDetail, fFactAmt );
    stPaymentDetail.fPaymentSum = fFactAmt;
    stPaymentDetail.strIntExchangeAmt = m_stMemInfo.strIntExchangeAmt;
    m_pStatementCtr->insertPayDetailData( stPaymentDetail );

    //支付成功数，支付数
    m_stStatementInfo.nSucNum += 1;
    m_stStatementInfo.nTotalNum += 1;
    setPayDetailsText( m_stStatementInfo.nSucNum, m_stStatementInfo.nTotalNum );

    m_bFirst = true;
}

void StatementDlg::slot_memPaySure()
{

}

void StatementDlg::slot_cashClose()
{
    QObject *p_obj = QObject::sender();

    if( m_bFirst ) {
        m_bFirst = false;
    }

    if( p_obj ) {
        delete p_obj;
        p_obj = NULL;
    }
}

void StatementDlg::slot_PayWndClose()
{
//    QObject *p_obj = QObject::sender();

//    if( p_obj ) {
//        delete p_obj;
//        p_obj = NULL;
//    }
    if (m_pAlipayRechargeDlg != NULL)
    {
        m_pAlipayRechargeDlg->hide();
        m_pAlipayRechargeDlg->stopAllTimer();
    }

    //如果待收金额为零，则表示结算完成，关闭结算窗口
    QStringList strList = ui->receivedValueLabel->text().split( "￥" );
    float fRece = strList[1].toFloat() + 0.003;
    if( strList.size() == 2 &&  fRece< 0.01 ) {
        //上传小票，查找未上传的小票，进行上传
        //应付金额
        QString strFactorAmt = ui->simpleAmtValueLabel->text().split( "￥")[1];
        QString strSmallChangeAmt = CommonFun::floatToString( m_fSmallChange );
        m_stStatementInfo.fDisAmt = ui->disAmtValueLabel->text().split( "￥" )[1].toFloat();//优惠金额
        QDateTime dt = QDateTime::currentDateTime();
        //m_pStatementCtr->updateSaleHeadFactorAmt( m_stStatementInfo.strOrderNum, strFactorAmt );
        m_pStatementCtr->updateSmallChangeAmt( m_stStatementInfo.strOrderNum, strSmallChangeAmt );
        m_pStatementCtr->updateSaleHeadStatementInfo( m_stStatementInfo.strOrderNum, CommonFun::floatToString(m_stStatementInfo.fDisAmt), "0.00", strFactorAmt, "0.00" );
        m_pStatementCtr->updateSaleHeadComplete( m_stStatementInfo.strOrderNum, e_headComplete, dt );
        m_pStatementCtr->printReceipt( m_stStatementInfo.strOrderNum, m_stMemInfo );
        KPosLog::instance()->writeDebugLog( "抹零金额1，订单号：" + m_stStatementInfo.strOrderNum + "，金额：" + strSmallChangeAmt );

        emit sig_oddChange( "0.0" );
        this->setEnabled( false );
        closeWnd();
    }
}

void StatementDlg::slot_closeOddChangeDlg()
{
    QObject *p_obj = QObject::sender();

    if( p_obj ) {
        delete p_obj;
        p_obj = NULL;
    }

//    //上传小票，查找未上传的小票，进行上传
//    float fAmtPaid = ui->amtPaidValueLabel->text().split( "￥" )[1].toFloat();//已付金额;
//    float fFactReceived = 0.00;
//    QString strRece = ui->receivedValueLabel->text().split( "￥" )[1];
//    strRece = updateCashRoundWay( strRece );
//    fFactReceived = strRece.toFloat();
//    float fOutAmt = fAmtPaid + fFactReceived;
    float fFactorAmt = ui->factAmtCashEdit->text().toFloat() + ui->amtPaidValueLabel->text().split( "￥")[1].toFloat(); // 已付金额

//    QString strSimple = ui->simpleAmtValueLabel->text().split( "￥")[1];
//    strSimple = strSimple.left( strSimple.size() -1 );//整单金额
//    float fOddChange = fFactorAmt - strSimple.toFloat();//找零金额
//    QString strOddChange = "";
//    strOddChange.sprintf( "%.1f", fOddChange );

//    QDateTime dt = QDateTime::currentDateTime();
//    //更新损益金额，总优惠金额，找零金额
    m_stStatementInfo.fDisAmt = ui->disAmtValueLabel->text().split( "￥" )[1].toFloat();//优惠金额
//    QString strDisAmt = CommonFun::floatToString( m_stStatementInfo.fDisAmt );
//    QString strProfitLoss = CommonFun::floatToString( m_stStatementInfo.fProfitLoss );
//    //QString strSimpleAmt = CommonFun::floatToString( m_stStatementInfo.fSimpleAmt );
    QString strOddChange = CommonFun::floatToString( m_stStatementInfo.fOddChange );
//    QString strOutAmt = CommonFun::floatToString( fOutAmt );
    QString strSmallChangeAmt = CommonFun::floatToString( m_fSmallChange );
//    m_pStatementCtr->updateSaleHeadOutAmt( m_stStatementInfo.strOrderNum, strOutAmt );
//    m_pStatementCtr->updateSmallChangeAmt( m_stStatementInfo.strOrderNum, strSmallChangeAmt );
//    m_pStatementCtr->updateSaleHeadStatementInfo( m_stStatementInfo.strOrderNum, strDisAmt, strProfitLoss, CommonFun::floatToString( fFactorAmt ), strOddChange );
//    m_pStatementCtr->updateSaleHeadComplete( m_stStatementInfo.strOrderNum, e_headComplete, dt );

    SaleHead stSaleHead;
    m_pStatementCtr->findSaleHead(m_stStatementInfo.strOrderNum, stSaleHead);
    stSaleHead.fAllDisAmt = m_stStatementInfo.fDisAmt;
    stSaleHead.fProfitLoss = m_stStatementInfo.fProfitLoss;
    stSaleHead.fOddChange = m_stStatementInfo.fOddChange;
//    qDebug()<<"777777 --- "<<stSaleHead.fProfitLoss;
//    qDebug()<<"888888 --- "<<stSaleHead.fOddChange;
//    stSaleHead.fOughtAmt = fOutAmt + strSmallChangeAmt.toFloat() + stSaleHead.fCouponDisAmt - stSaleHead.fProfitLoss;
    m_pStatementCtr->getOughtAmt(m_stStatementInfo.strOrderNum, stSaleHead.fOughtAmt);
    stSaleHead.sSmallChangeAmt = strSmallChangeAmt;
    stSaleHead.fFactorAmt = fFactorAmt - m_stStatementInfo.fOddChange;
    stSaleHead.nStatus = e_headComplete;
    stSaleHead.dtCompleteTime = QDateTime::currentDateTime();
    m_pStatementCtr->updateSaleHead(stSaleHead);

    m_pStatementCtr->printReceipt( m_stStatementInfo.strOrderNum, m_stMemInfo );
    KPosLog::instance()->writeDebugLog( "抹零金额2，订单号：" + m_stStatementInfo.strOrderNum + "，金额：" + strSmallChangeAmt );

    emit sig_oddChange( strOddChange );
    this->setEnabled( false );
    closeWnd();
}

void StatementDlg::slot_virtualPay()
{
    QObject *p_obj = QObject::sender();
    if( p_obj ) {
        delete p_obj;
        p_obj = NULL;
    }

    //结算完成后，要更新 优惠金额到销售表中，实收金额，找零金额
    //点击确定，刷新界面
    float fTotalMoney = ui->simpleAmtValueLabel->text().split( "￥" )[1].toFloat();//4.95  整单金额
    float fAmtPaid = ui->amtPaidValueLabel->text().split( "￥" )[1].toFloat();//已付金额
    float fAmtReceived = ui->receivedValueLabel->text().split( "￥" )[1].toFloat();//待收金额
    float fFactAmt = 0.00;

    switch ( m_stCurPayInfo.nPayType ) {
    case PayAlipay:
        fFactAmt = ui->factAmtAlipayEdit->text().toFloat();
        break;
    case PayWeChat:
        fFactAmt = ui->factAmtWeEdit->text().toFloat();
        break;
    case UnionPay:
//        fFactAmt = ui->factAmtUnionEdit->text().toFloat();
//        break;
    case PayCityCard:
    case PayFengCha:
    case PayCheck:
    case PayBills:
    case PayEntityCard:
    case PayOther:
        fFactAmt = ui->virtualPayWidget->getVirtualAmtEdit()->text().toFloat();
        break;
    default:
        break;
    }

    //通过Agent，加载支付详情信息到支付详情表
    m_eCurPayState = e_PaySuccess;
    PaymentDetailInfo stPaymentDetail;
    getPayDetail( stPaymentDetail, fFactAmt );
    stPaymentDetail.fPaymentSum = fFactAmt;
    stPaymentDetail.strIntExchangeAmt = m_stMemInfo.strIntExchangeAmt;
    m_pStatementCtr->insertPayDetailData( stPaymentDetail );

    float f_diff = fAmtReceived - fFactAmt;
    if( f_diff >= fNetPayEpsinon ) {
        fAmtPaid = fAmtPaid + fFactAmt;
        fAmtReceived = fTotalMoney - fAmtPaid;
        QString str_paid = "";
        QString str_received = "";
        str_paid.sprintf( "￥%.2f", fAmtPaid );
        str_received.sprintf( "%.2f", fAmtReceived );
        ui->amtPaidValueLabel->setText( str_paid );
        ui->receivedValueLabel->setText( "￥" + str_received );

        switch ( m_stCurPayInfo.nPayType ) {
        case PayAlipay:
            ui->factAmtAlipayEdit->setText( str_received );
            break;
        case PayWeChat:
            ui->factAmtWeEdit->setText( str_received );
            break;
        case UnionPay:
//            ui->factAmtUnionEdit->setText( str_received );
//            break;
        case PayCityCard:
        case PayFengCha:
        case PayCheck:
        case PayBills:
        case PayEntityCard:
        case PayOther:
            ui->virtualPayWidget->getVirtualAmtEdit()->setText( str_received );
            break;
        default:
            break;
        }
    } else if( f_diff < fNetPayEpsinon ) {//现金结算完成
        //损益
        m_stStatementInfo.fProfitLoss = 0.00;

        m_stStatementInfo.fOddChange = 0.00;
//        float fFactReceived = 0.00;
//        QString strRece = ui->receivedValueLabel->text().split( "￥" )[1];
//        strRece = updateCashRoundWay( strRece );
//        fFactReceived = strRece.toFloat();
        float fOutAmt = fAmtPaid + fFactAmt;


        QDateTime dt = QDateTime::currentDateTime();
        //更新损益金额，总优惠金额，找零金额
        m_stStatementInfo.fDisAmt = ui->disAmtValueLabel->text().split( "￥" )[1].toFloat();//优惠金额
        QString strDisAmt = CommonFun::floatToString( m_stStatementInfo.fDisAmt );
        QString strProfitLoss = CommonFun::floatToString( m_stStatementInfo.fProfitLoss );
        //QString strSimpleAmt = CommonFun::floatToString( m_stStatementInfo.fSimpleAmt );
        QString strOddChange = CommonFun::floatToString( m_stStatementInfo.fOddChange );
        QString strOutAmt = CommonFun::floatToString( fOutAmt );
        QString strSmallChangeAmt = CommonFun::floatToString( m_fSmallChange );
        m_pStatementCtr->updateSaleHeadOutAmt( m_stStatementInfo.strOrderNum, strOutAmt );
        m_pStatementCtr->updateSmallChangeAmt( m_stStatementInfo.strOrderNum, strSmallChangeAmt );
        m_pStatementCtr->updateSaleHeadStatementInfo( m_stStatementInfo.strOrderNum, strDisAmt, strProfitLoss, strOutAmt, strOddChange );
        m_pStatementCtr->updateSaleHeadComplete( m_stStatementInfo.strOrderNum, e_headComplete, dt );
        m_pStatementCtr->printReceipt( m_stStatementInfo.strOrderNum, m_stMemInfo );
        KPosLog::instance()->writeDebugLog( "抹零金额3，订单号：" + m_stStatementInfo.strOrderNum + "，金额：" + strSmallChangeAmt );

        emit sig_oddChange( strOddChange );
        this->setEnabled( false );
        closeWnd();
    }

    //支付成功数，支付数
    m_stStatementInfo.nSucNum += 1;
    m_stStatementInfo.nTotalNum += 1;
    setPayDetailsText( m_stStatementInfo.nSucNum, m_stStatementInfo.nTotalNum );

    m_bFirst = true;
}

void StatementDlg::slot_virtualPays()
{
    QObject *p_obj = QObject::sender();
    if( p_obj ) {
        delete p_obj;
        p_obj = NULL;
    }

    float fTotalMoney = ui->simpleAmtValueLabel->text().split( "￥" )[1].toFloat();//4.95  整单金额
    float fAmtPaid = ui->amtPaidValueLabel->text().split( "￥" )[1].toFloat();//已付金额
    float fAmtReceived = ui->receivedValueLabel->text().split( "￥" )[1].toFloat();//待收金额
    float fFactAmt = ui->virtualPaysPage->getFactorAmt().toFloat();
    //通过Agent，加载支付详情信息到支付详情表
    m_eCurPayState = e_PaySuccess;
    PaymentDetailInfo stPaymentDetail;
    m_stCurPayInfo = ui->virtualPaysPage->getCurPayWayInfo();
    getPayDetail( stPaymentDetail, fFactAmt );
    stPaymentDetail.strIntExchangeAmt = m_stMemInfo.strIntExchangeAmt;
    m_pStatementCtr->insertPayDetailData( stPaymentDetail );

    float f_diff = fAmtReceived - fFactAmt;
    if( f_diff >= fNetPayEpsinon )
    {
        fAmtPaid = fAmtPaid + fFactAmt;
        fAmtReceived = fTotalMoney - fAmtPaid;
        QString str_paid = "";
        QString str_received = "";
        str_paid.sprintf( "￥%.2f", fAmtPaid );
        str_received.sprintf( "%.2f", fAmtReceived );
        ui->amtPaidValueLabel->setText( str_paid );
        ui->receivedValueLabel->setText( "￥" + str_received );
        ui->virtualPaysPage->setFactorAmt(str_received);
    }
    else if ( f_diff < fNetPayEpsinon )
    {//现金结算完成
        //损益
        m_stStatementInfo.fProfitLoss = 0.00;
        m_stStatementInfo.fOddChange = 0.00;
        float fOutAmt = fAmtPaid + fFactAmt;
        QDateTime dt = QDateTime::currentDateTime();
        //更新损益金额，总优惠金额，找零金额
        m_stStatementInfo.fDisAmt = ui->disAmtValueLabel->text().split( "￥" )[1].toFloat();//优惠金额
        QString strDisAmt = CommonFun::floatToString( m_stStatementInfo.fDisAmt );
        QString strProfitLoss = CommonFun::floatToString( m_stStatementInfo.fProfitLoss );
        //QString strSimpleAmt = CommonFun::floatToString( m_stStatementInfo.fSimpleAmt );
        QString strOddChange = CommonFun::floatToString( m_stStatementInfo.fOddChange );
        QString strOutAmt = CommonFun::floatToString( fOutAmt );
        QString strSmallChangeAmt = CommonFun::floatToString( m_fSmallChange );
        m_pStatementCtr->updateSaleHeadOutAmt( m_stStatementInfo.strOrderNum, strOutAmt );
        m_pStatementCtr->updateSmallChangeAmt( m_stStatementInfo.strOrderNum, strSmallChangeAmt );
        m_pStatementCtr->updateSaleHeadStatementInfo( m_stStatementInfo.strOrderNum, strDisAmt, strProfitLoss, strOutAmt, strOddChange );
        m_pStatementCtr->updateSaleHeadComplete( m_stStatementInfo.strOrderNum, e_headComplete, dt );
        m_pStatementCtr->printReceipt( m_stStatementInfo.strOrderNum, m_stMemInfo );
        KPosLog::instance()->writeDebugLog( "抹零金额3，订单号：" + m_stStatementInfo.strOrderNum + "，金额：" + strSmallChangeAmt );

        emit sig_oddChange( strOddChange );
        this->setEnabled( false );
        closeWnd();
    }

    //支付成功数，支付数
    m_stStatementInfo.nSucNum += 1;
    m_stStatementInfo.nTotalNum += 1;
    setPayDetailsText( m_stStatementInfo.nSucNum, m_stStatementInfo.nTotalNum );

    m_bFirst = true;
}

//优惠券支付确认,可以付 分
void StatementDlg::slot_couponPay()
{
    QObject *p_obj = QObject::sender();
    if( p_obj ) {
        delete p_obj;
        p_obj = NULL;
    }

    ui->statementCouponButton->setEnabled( false );
    slot_createPayInfo((EPayMethod)m_stCurPayInfo.nPayType, ui->factAmtCouponEdit_1->text(), ui->factAmtCouponEdit_2->text() );
}

void StatementDlg::slot_getPayStatus( int nPayMethod, QString strPayOrderNum )
{

    m_pStatementCtr->getPayStatusRequest( nPayMethod, strPayOrderNum );
}

void StatementDlg::slot_createPayInfo( EPayMethod ePayMethod, QString strBarCode, QString strPayAmt )
{
    m_pStatementCtr->createPayInfoRequest( m_stStatementInfo.strOrderNum, ePayMethod, strBarCode, strPayAmt );
}


//支付返回值处理
void StatementDlg::slot_memPayInfo( int nCode, QString strMsg, QString strOrderNumS, QString strAuthCode, EPayMethod ePayMethod )
{
    if( ePayMethod == Coupon )
    {//优惠券返回执行
        handleCouponInfo( nCode, strMsg, strOrderNumS, strAuthCode );
    }
    else if( ePayMethod == PayMemCard )
    {
        ui->statementMemButton->setEnabled(true);
        handleMemPayInfo(nCode, strMsg, strOrderNumS, strAuthCode);
    }
    else if (ePayMethod == PayStoreCard)
    {
        ui->statementStoreButton->setEnabled(true);
        handleStoreCardInfo(nCode, strMsg, strOrderNumS, strAuthCode);
    }

}

void StatementDlg::slot_onPayStoreCardInfo(int nCode, QString sMsg, PayStoreCardInfo storeCardInfo)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("储值卡信息获取失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        ui->cardIDStoreEdit->setText(storeCardInfo.sCardNum);
        ui->currentAmtStoreEdit->setText(QString("￥%1").arg(QString::number(storeCardInfo.fCardBalance, 'f', 2)));
        m_storeCardInfo = storeCardInfo;
    }
}

void StatementDlg::slot_onCreatePayMemberCard(int nCode, QString sMsg, QString sBanlanceOrderNum, QString sIntegralOrderNum)
{
    handleMemPayInfo(nCode, sMsg, sBanlanceOrderNum, sIntegralOrderNum);
}

void StatementDlg::slot_onUpdateMemberIntegral(int nCode, QString sMsg, int nGiftIntegral, QString sOrderNum)
{
    if(nCode != e_success)
    {
        return;
    }
    if (m_pStatementCtr != NULL)
    {
        m_pStatementCtr->updateIntegral(nGiftIntegral, sOrderNum); // 更新主表会员积分
    }
}

//网络结算支付信息
void StatementDlg::slot_payInfo(QString strOrderNumS , EStatementStatus eStatementStatus , QString sBarCode)
{
    if( eStatementStatus == StatementScaning ) return;//在“请扫码”的状态下，点击取消，则直接返回

    //支付成功，计算待收等支付信息
    //结算完成后，要更新 优惠金额到销售表中，实收金额，找零金额
    float fTotalMoney = ui->simpleAmtValueLabel->text().split( "￥" )[1].toFloat();
    float fAmtPaid = ui->amtPaidValueLabel->text().split( "￥" )[1].toFloat();
    float fAmtReceived = ui->receivedValueLabel->text().split( "￥" )[1].toFloat();

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    float fFactAmt = p_wnd->text().toFloat();

    //通过Agent，加载支付详情信息到支付详情表
    m_eCurPayState = (EPaymentState)eStatementStatus;
    PaymentDetailInfo stPaymentDetail;
    stPaymentDetail.strAuthCode = sBarCode;
    getPayDetail( stPaymentDetail, fFactAmt );
    stPaymentDetail.strPaymentOrderNum = strOrderNumS;
    stPaymentDetail.fPaymentSum = fFactAmt;
    stPaymentDetail.strIntExchangeAmt = m_stMemInfo.strIntExchangeAmt;
    m_pStatementCtr->insertPayDetailData( stPaymentDetail );

    //支付成功数，支付数
    if( eStatementStatus == StatementSuc ) {
        fAmtPaid = fAmtPaid + fFactAmt;
        fAmtReceived = fTotalMoney - fAmtPaid;
        QString str_paid = "";
        QString str_received = "";
        str_paid.sprintf( "￥%.2f", fAmtPaid );
        str_received.sprintf( "%.2f", fAmtReceived );
        ui->amtPaidValueLabel->setText( str_paid );
        ui->receivedValueLabel->setText( "￥" + str_received );
        p_wnd->setText( str_received );

        m_stStatementInfo.nSucNum += 1;

    }
    m_stStatementInfo.nTotalNum += 1;
    setPayDetailsText( m_stStatementInfo.nSucNum, m_stStatementInfo.nTotalNum );

    m_bFirst = true;

//    if( eStatementStatus == StatementScaning ) return;//在“请扫码”的状态下，点击取消，则直接返回

//    //支付成功，计算待收等支付信息
//    //结算完成后，要更新 优惠金额到销售表中，实收金额，找零金额
//    float fTotalMoney = ui->simpleAmtValueLabel->text().split( "￥" )[1].toFloat();
//    float fAmtPaid = ui->amtPaidValueLabel->text().split( "￥" )[1].toFloat();
//    float fAmtReceived = ui->receivedValueLabel->text().split( "￥" )[1].toFloat();

//    QLineEdit *p_wnd = NULL;
//    bool b_has_focus = getCurFocusWnd( p_wnd );
//    if( !b_has_focus ) return;

//    float fFactAmt = p_wnd->text().toFloat();

//    //通过Agent，加载支付详情信息到支付详情表
//    m_eCurPayState = (EPaymentState)eStatementStatus;
//    PaymentDetailInfo stPaymentDetail;
//    getPayDetail( stPaymentDetail, fFactAmt );
//    stPaymentDetail.strPaymentOrderNum = strOrderNumS;
//    stPaymentDetail.fPaymentSum = fFactAmt;
//    stPaymentDetail.strIntExchangeAmt = m_stMemInfo.strIntExchangeAmt;
//    m_pStatementCtr->insertPayDetailData( stPaymentDetail );

//    //支付成功数，支付数
//    if( eStatementStatus == StatementSuc ) {
//        fAmtPaid = fAmtPaid + fFactAmt;
//        fAmtReceived = fTotalMoney - fAmtPaid;
//        QString str_paid = "";
//        QString str_received = "";
//        str_paid.sprintf( "￥%.2f", fAmtPaid );
//        str_received.sprintf( "%.2f", fAmtReceived );
//        ui->amtPaidValueLabel->setText( str_paid );
//        ui->receivedValueLabel->setText( "￥" + str_received );
//        p_wnd->setText( str_received );

//        m_stStatementInfo.nSucNum += 1;

//    }
//    m_stStatementInfo.nTotalNum += 1;
//    setPayDetailsText( m_stStatementInfo.nSucNum, m_stStatementInfo.nTotalNum );

//    m_bFirst = true;

}

void StatementDlg::slot_payRevoke( QString strOrderNumS )
{
    m_pStatementCtr->payRevokeRequest( (EPayMethod)m_stCurPayInfo.nPayType, strOrderNumS );
}

void StatementDlg::slot_RevokePay( QString strPayOrderNum, QString strPaidAmt )
{
    Q_UNUSED( strPayOrderNum )

    float fAmtPaid = ui->amtPaidValueLabel->text().split( "￥" )[1].toFloat();
    fAmtPaid -= strPaidAmt.toFloat();
    float fAmtReceived = ui->receivedValueLabel->text().split( "￥" )[1].toFloat();
    fAmtReceived += strPaidAmt.toFloat();

    QString strAmtPaid = CommonFun::floatToString( fAmtPaid );
    QString strRecdAmt = CommonFun::floatToString( fAmtReceived );
    ui->amtPaidValueLabel->setText( "￥" + strAmtPaid );
    ui->receivedValueLabel->setText( "￥" + strRecdAmt );

    strRecdAmt.sprintf( "%.1f", fAmtReceived );
    ui->factAmtCashEdit->setText( strRecdAmt );
    //会员卡和储值卡
    strRecdAmt = CommonFun::floatToString( fAmtReceived );

    ui->factAmtAlipayEdit->setText( strRecdAmt );
    ui->factAmtWeEdit->setText( strRecdAmt );
    ui->factAmtAppleEdit->setText( strRecdAmt );
    ui->factAmtJdEdit->setText( strRecdAmt );
    //ui->factAmtUnionEdit->setText( strRecdAmt );
    ui->balanceMemEdit->setText( strRecdAmt );
    ui->integUseMemEdit->setText( "" );
    ui->virtualPayWidget->getVirtualAmtEdit()->setText( strRecdAmt );
    //支付详情成功数-1
    m_stStatementInfo.nSucNum -= 1;
    setPayDetailsText( m_stStatementInfo.nSucNum, m_stStatementInfo.nTotalNum );
}

void StatementDlg::slot_revokeAllAmt( QString strOrderNum, QString strPaidAmt )
{
    BalanceManage::instance()->openCashBox();//打开钱箱
    //退款订单插入到数据库
    m_eCurPayState = e_PaySuccess;
    PaymentDetailInfo stPaymentDetail;
    stPaymentDetail.sPaymentSequence = strOrderNum;//m_stStatementInfo.strOrderNum;
    QDateTime dtCur = QDateTime::currentDateTime();
    QString strPaymentOrderNum =  KPosIni::getPosCode() + dtCur.toString( "yyMMddhhmmss" );
    stPaymentDetail.strPaymentOrderNum =  strPaymentOrderNum;
    stPaymentDetail.ePayMethod = PayCash;
    stPaymentDetail.ePaymentState = e_PayRefund;
    stPaymentDetail.ePayType = e_Refund;
    stPaymentDetail.fPaymentSum = -strPaidAmt.toFloat();
    m_pStatementCtr->insertPayDetailData( stPaymentDetail );

    //结算界面退款更新
    float fAmtPaid = ui->amtPaidValueLabel->text().split( "￥" )[1].toFloat();
    fAmtPaid -= strPaidAmt.toFloat();
    float fAmtReceived = ui->receivedValueLabel->text().split( "￥" )[1].toFloat();
    fAmtReceived += strPaidAmt.toFloat();

    QString strAmtPaid = CommonFun::floatToString( fAmtPaid );
    QString strRecdAmt = CommonFun::floatToString( fAmtReceived );
    ui->amtPaidValueLabel->setText( "￥" + strAmtPaid );
    ui->receivedValueLabel->setText( "￥" + strRecdAmt );

    strRecdAmt.sprintf( "%.1f", fAmtReceived );
    ui->factAmtCashEdit->setText( strRecdAmt );
    //会员卡和储值卡
    strRecdAmt = CommonFun::floatToString( fAmtReceived );

    ui->factAmtAlipayEdit->setText( strRecdAmt );
    ui->factAmtWeEdit->setText( strRecdAmt );
    ui->factAmtAppleEdit->setText( strRecdAmt );
    ui->factAmtJdEdit->setText( strRecdAmt );
    //ui->factAmtUnionEdit->setText( strRecdAmt );
    ui->balanceMemEdit->setText( strRecdAmt );
    ui->integUseMemEdit->setText( "" );
    ui->virtualPayWidget->getVirtualAmtEdit()->setText( strRecdAmt );
    //支付详情成功数-1
    m_stStatementInfo.nSucNum = 0;
    m_stStatementInfo.nTotalNum += 1;
    setPayDetailsText( m_stStatementInfo.nSucNum, m_stStatementInfo.nTotalNum );

    m_pPayDetailsDlg->hide();
}

void StatementDlg::slot_MemCardRevokePay( QString strPayOrderNum, QString strPaidAmt, QString strMemCardBalance, int nMemCardIntegral )
{
    slot_RevokePay( strPayOrderNum, strPaidAmt );
    //更新会员信息
    m_stMemInfo.stMemInfo.strAccountBalance = strMemCardBalance;
    m_stMemInfo.stMemInfo.nIntegral = nMemCardIntegral;
    ui->id_lab_mem_card_value->setText( "￥" + m_stMemInfo.stMemInfo.strAccountBalance );
    ui->id_lab_integ_value->setText( QString::number( m_stMemInfo.stMemInfo.nIntegral ) );
}

void StatementDlg::slot_showPayDetailsDlg()
{
    m_pPayDetailsDlg = new PaymentDetailDlg();

    QString strSimpleAmt = ui->simpleAmtValueLabel->text();
    QString strPaid = ui->amtPaidValueLabel->text();
    QString strReceived = ui->receivedValueLabel->text();

    m_pPayDetailsDlg->initData( m_stStatementInfo.strOrderNum, strSimpleAmt, strPaid, strReceived );

    //根据订单号，从数据库获取支付详情信息，并加载到支付对话框中
    QList<PayDetail_s> listPayDetails;
    QList<PaymentDetailInfo*> listPaymentDetails;
    m_pStatementCtr->getPayDetailsList( m_stStatementInfo.strOrderNum, listPayDetails );

    QList<PayDetail_s>::iterator it = listPayDetails.begin();
    for( int i = 1 ; it != listPayDetails.end(); ++it ) {
        PaymentDetailInfo *pPayDetailsInfo = new PaymentDetailInfo;
        pPayDetailsInfo->sPaymentSequence = it->strOrderNum;
        pPayDetailsInfo->strPaymentOrderNum = it->strPaymentOrderNum;
        pPayDetailsInfo->ePayMethod = (EPayMethod)it->nPayMethod;
        pPayDetailsInfo->fPaymentSum = it->fPayMoney;
        pPayDetailsInfo->nPayIntegral = it->nPayIntegral;
        pPayDetailsInfo->strIntExchangeAmt = it->strIntExchangeAmt;
        pPayDetailsInfo->ePaymentState = (EPaymentState)it->nStatus;
        pPayDetailsInfo->ePayType = (EPaymentType)it->nPayType;
        pPayDetailsInfo->bVirtual = it->bVirtual;
        pPayDetailsInfo->nPos = i++;
        switch( pPayDetailsInfo->ePayType ) {
        case e_Payment:
            if( pPayDetailsInfo->ePaymentState == e_PayFailed ) {
                pPayDetailsInfo->eButtonStatus = eDisAble;
            }
            break;
        case e_Refund:
            if( pPayDetailsInfo->ePaymentState == e_PaySuccess ) {
                pPayDetailsInfo->eButtonStatus = eDisAble;
            }
            break;
        }

        listPaymentDetails.push_back( pPayDetailsInfo );
    }

    m_pPayDetailsDlg->setPayDetailsList( listPaymentDetails );

    connect( m_pPayDetailsDlg, SIGNAL( sigButtonPress(EPayMethod, QString,float, bool)), this, SLOT( slot_RefundPress(EPayMethod, QString,float,bool ) ) );
    connect( m_pStatementCtr, SIGNAL( sig_RevokePay(int,QString,QString,int) ), m_pPayDetailsDlg, SLOT( slot_RevokePay( int, QString, QString,int) ) );
    connect( m_pStatementCtr, SIGNAL(sig_MemCardRevokePay(int,QString,QString,int,QString,int)), m_pPayDetailsDlg, SLOT( slot_MemCardRevokePay(int,QString,QString,int,QString,int) ) );
    connect( m_pPayDetailsDlg, SIGNAL(sig_RevokePay(QString,QString)), this, SLOT( slot_RevokePay( QString,QString) ) );
    connect( m_pPayDetailsDlg, SIGNAL(sig_MemCardRevokePay(QString,QString,QString,int)), this, SLOT( slot_MemCardRevokePay(QString,QString,QString,int)) );
    connect( m_pPayDetailsDlg, SIGNAL( sig_revokeAllAmt(QString,QString)), this, SLOT( slot_revokeAllAmt( QString, QString ) ) );
    m_pPayDetailsDlg->exec();

    if( m_pPayDetailsDlg ) {
        delete m_pPayDetailsDlg;
        m_pPayDetailsDlg = NULL;
    }
}

void StatementDlg::slot_payInfoChanged()
{
    KPosSet stKPosSet;
    KPosSetAgent::instance()->getKPosSetInfo( stKPosSet );
    m_virtualPayList = stKPosSet.virtualPaySet.virtualList;
    m_listPayInfo.clear();
    QList<PayWayInfoSet> listPayInfo = stKPosSet.payWaySet.payWayInfoSetList;

//    //新增虚拟支付页面
//    PayWayInfoSet stPayWay;
//    stPayWay.nPayType = e_PayVirtual; //虚拟支付
//    stPayWay.bStartUse = true; // 是否启动
//    stPayWay.bChargeMember = true; // 是否用于会员充值
//    stPayWay.bVirtualPay = true; // 是否虚拟支付
//    stPayWay.nDropType = eUntreated; //　分的圆整方式,4表示不处理
//    if( listPayInfo.size() >= 2 ) {
//        QList<PayWayInfoSet>::iterator it = listPayInfo.begin();
//        ++it;
//        listPayInfo.insert( ++it, stPayWay );
//    } else if( listPayInfo.size() == 1 ){
//        QList<PayWayInfoSet>::iterator it = listPayInfo.begin();
//        listPayInfo.insert( ++it, stPayWay );
//    } else {
//        listPayInfo.push_front( stPayWay );
//    }

    int nSize = listPayInfo.size();
    for (int i = 0; i < nSize; i++)
    {
        if(listPayInfo[i].bStartUse)
        {
            m_listPayInfo.append(listPayInfo[i]);
        }
    }

    if( m_listPayInfo.size() <= 5 ) {
        m_nCurPageNum = 1;
        m_nTotalPageNum = 1;
    } else if( m_listPayInfo.size() >5 ) {
        m_nCurPageNum = 1;
        m_nTotalPageNum = getTotalNum();
    }

    updatePayButton( m_nCurPageNum );
}

void StatementDlg::slot_RefundPress( EPayMethod ePayMethod, QString strPayOrderNum, float fPayMoney, bool bVirtual )
{
    if( ePayMethod == PayCash || ( ePayMethod != PayCash && bVirtual ) ) {
        //1）弹出退款对话框，确认是否退款
        DlgCommon *pDlg = new DlgCommon( 0, true );
        pDlg->set_title( "退款" );
        pDlg->set_content( "是否确认退款?" );
        connect( pDlg, SIGNAL(sig_btn_cancel()), pDlg, SLOT( close() ) );
        connect( pDlg, SIGNAL(sig_dlg_close()), pDlg, SLOT( close() ) );

        if( QDialog::Accepted == pDlg->exec() ) {
            m_pStatementCtr->refundRequest( ePayMethod, strPayOrderNum, bVirtual );
        }

        if( pDlg ) {
            delete pDlg;
            pDlg = NULL;
        }
    } else {
        RefundPayDlg *pDlgRefund = new RefundPayDlg( 0, ePayMethod, strPayOrderNum );
        pDlgRefund->setTitle( "退款" );
        pDlgRefund->setAmtLabelText( "退款金额" );
        QString strPayMoney = "";
        strPayMoney.sprintf( "%.2f", fPayMoney );
        pDlgRefund->setContext( strPayMoney, RefundWaiting );

        connect( pDlgRefund, SIGNAL( sig_closeWnd() ), this, SLOT( slot_PayWndClose() ) );
        connect( pDlgRefund, SIGNAL( sig_getPayStatus(int, QString)), this, SLOT( slot_getPayStatus( int, QString ) ) );
        connect( pDlgRefund, SIGNAL( sig_payRevoke( QString )), this, SLOT( slot_payRevoke( QString ) ) );
//            connect( m_pStatementCtr, SIGNAL(sigOnCreatePayStatus(int,QString,QString,int))
//                     , pDlgRefund, SLOT( slot_GetPayStatus( int,QString,QString,int ) ) );
        connect( m_pStatementCtr, SIGNAL(sig_RevokePay(int,QString,QString,int)) \
                 , pDlgRefund, SLOT( slot_RevokePay( int,QString,QString,int ) ) );
        connect( m_pStatementCtr, SIGNAL(sig_MemCardRevokePay(int,QString,QString,int,QString,int)) \
                 , pDlgRefund, SLOT( slot_MemRevokePay(int,QString,QString,int,QString,int)) );
        //发送订单号给后台退款
        m_pStatementCtr->refundRequest( ePayMethod, strPayOrderNum, m_stCurPayInfo.bVirtualPay );
        pDlgRefund->startQueryStatusTimer();

        pDlgRefund->exec();

//        if( pDlgRefund ) {
//            delete pDlgRefund;
//            pDlgRefund = NULL;
//        }
    }
}

//刷新优惠金额
void StatementDlg::refreashDiscountMoney()
{
    float fValue = m_stStatementInfo.fSimpleAmt - ui->simpleAmtValueLabel->text().split( "￥" )[1].toFloat();
    float fDis = m_stStatementInfo.fDisAmt + fValue;
    QString strDis = "";
    strDis.sprintf( "￥%.2f", fDis );
    ui->disAmtValueLabel->setText( strDis );
}

//刷新待收和实收金额
void StatementDlg::refreshReceivedAndFactMoney()
{
    //更新待收金额和实收金额
    QString strReceived = "";
    float fReceived = ui->simpleAmtValueLabel->text().split( "￥" )[1].toFloat() \
            - ui->amtPaidValueLabel->text().split( "￥" )[1].toFloat();

    //刷新所有实际支付的文本
    strReceived.sprintf( "%.1f", fReceived );
    ui->factAmtCashEdit->setText( strReceived );

    strReceived.sprintf( "%.2f", fReceived );
    ui->receivedValueLabel->setText( "￥" + strReceived );

    ui->balanceMemEdit->setText( strReceived );
    ui->integUseMemEdit->setText( "0" );

    ui->factAmtAlipayEdit->setText( strReceived );
    ui->factAmtWeEdit->setText( strReceived );
    ui->factAmtAppleEdit->setText( strReceived );
    ui->factAmtJdEdit->setText( strReceived );
    //ui->factAmtUnionEdit->setText( strReceived );
    ui->virtualPayWidget->getVirtualAmtEdit()->setText( strReceived );
}

void StatementDlg::payMethodStatement()
{
    switch ( m_stCurPayInfo.nPayType ) {
    case PayCash:
        slot_showCashPay();
        break;
    case UnionPay:
        slot_showUnionPay();
        break;
    case PayMemCard:
        slot_showMemCardPay();
        break;
    case PayStoreCard:
        slot_storeCardPay();
        break;
    case PayAlipay:
        slot_alipayPay();
        break;
    case PayWeChat:
        slot_weChatPay();
        break;
    case ApplePay:
        slot_applePay();
        break;
    case JdWallet:
        slot_jdWalletPay();
        break;
    case Coupon:
        slot_CouponPayWnd();
        break;
    case VirtualPayPage:
        slot_VirtualPayWnd();
        break;
    case e_virtualPay:
        slot_virtualPaysWnd();
        break;
    case PayEntityCard:
        showPayCityCardWnd();
        break;
    default:
        break;
    }
}

void StatementDlg::updateSelectPayButton()
{
    QList< StatementMethodButton *>::iterator it = m_listPayButton.begin();
    for( ; it != m_listPayButton.end(); ++it ) {
        if( (*it)->getPayInfo().nPayType == m_stCurPayInfo.nPayType ) {
            (*it)->setSelectedSelf();
            break;
        }
    }
}

void StatementDlg::cashStatement()
{
    DlgCommon *pDlg = new DlgCommon();
    pDlg->set_title( "现金" );
    pDlg->set_content( "是否确认支付?" );
    connect( pDlg, SIGNAL( sig_btn_sure() ), this, SLOT( slot_cashSure() ) );
    connect( pDlg, SIGNAL( sig_dlg_close() ), this, SLOT( slot_cashClose() ) );
    connect( pDlg, SIGNAL( sig_btn_cancel() ), this, SLOT( slot_cashClose() ) );
    pDlg->show();
}

void StatementDlg::slot_memberStatement()
{
    if( m_stMemInfo.stMemInfo.strCardNo.isEmpty() ) return;

    //如果余额使用>会员卡余额，则余额使用=会员卡余额；如果余额使用>待收金额，则余额使用=待收金额；如果余额使用<待收金额,则焦点显示在积分使用上
    float f_balance = ui->balanceMemEdit->text().toFloat();
//    float f_card_balance = ui->id_lab_mem_card_value->text().split( "￥" )[1].toFloat();
    float f_received = ui->receivedValueLabel->text().split( "￥" )[1].toFloat();
//    if( f_balance - f_card_balance > -0.01 ) {
//        f_balance = f_card_balance;
//    }

//    if( f_balance - f_received > -fEpsinon ) {
//        f_balance = f_received;
//    } else {
////        QLineEdit *p_wnd = NULL;
////        bool b_has_focus = getCurFocusWnd( p_wnd );
////        if( !b_has_focus ) return;

////        if( p_wnd != ui->integUseMemEdit ) {
////            ui->integUseMemEdit->setFocus();
////            return;
////        }
//    }

//    id_lab_integ_value  积分
//    id_lab_can_arrived_value 可抵现

    //如果积分使用>可用积分，那么积分使用 = 可用积分,然后更新抵现金额
//    int n_integ = ui->id_lab_integ_value->text().toInt();//可用积分
    if (f_balance < 0)
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("会员金额支付不应该小于0！！！"));
        return;
    }
    int n_balance = ui->integUseMemEdit->text().toInt();//使用积分
    if (n_balance * m_stMemInfo.strIntExchangeAmt.toFloat() + f_balance > f_received)
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("会员支付金额不应该大于待收金额！！！"));
        return;
    }


//    if( n_balance > n_integ ) {
//        n_balance = n_integ;
//        ui->integUseMemEdit->setText( QString::number( n_balance) );
//        float fIntToAmt = 0.00;
//        if( m_stMemInfo.strIntExchangeAmt.toFloat() != 0 ) {
//            fIntToAmt = n_balance * m_stMemInfo.strIntExchangeAmt.toFloat();
//        } else {
//            fIntToAmt = 0;
//            n_balance = 0;
//            ui->integUseMemEdit->setText( "0" );
//        }
//        ui->id_lab_can_arrived_value->setText( CommonFun::floatToString( fIntToAmt ) );//抵现
//    }

//    QString str_balance = "";
//    str_balance.sprintf( "%.2f", f_balance );
//    ui->balanceMemEdit->setText( str_balance );

    //如果会员卡有密码，则弹出会员密码输入对话框；如果没有密码，则显示公共对话框
    QString strPayAmt = CommonFun::floatToString( f_balance );
    if( !m_stMemInfo.bPaypwd ) {
        DlgCommon *pMemDlg = new DlgCommon( 0, true );
        pMemDlg->set_title( "会员卡" );
        pMemDlg->set_content( "是否确认支付?");
        connect( pMemDlg, SIGNAL(sig_dlg_close()), pMemDlg, SLOT(close()) );
        connect(pMemDlg, SIGNAL(sig_btn_cancel()), pMemDlg, SLOT(close()));
        if( pMemDlg->exec() == QDialog::Accepted ) {
            ui->statementMemButton->setEnabled( false );
            if (m_pStatementCtr != NULL)
            {
                m_pStatementCtr->createPayMemberCardRequest(m_stStatementInfo.strOrderNum, m_stMemInfo.stMemInfo.strCardNo, strPayAmt, n_balance, "", m_stMemInfo.strIntToAmt);
            }
        }
    } else {
        MemPayDlg *pMemPayDlg = new MemPayDlg( 0, m_stMemInfo.strPayPwd );

        if( pMemPayDlg->exec() == QDialog::Accepted ) {
            //会员支付信息发送后台处理,并关闭该对话框
            QString strPayPasswd = pMemPayDlg->getPayPwd();
            ui->statementMemButton->setEnabled( false );
            //会员支付信息发送后台处理
            if (m_pStatementCtr != NULL)
            {
                m_pStatementCtr->createPayMemberCardRequest(m_stStatementInfo.strOrderNum, m_stMemInfo.stMemInfo.strCardNo, strPayAmt, n_balance, strPayPasswd, m_stMemInfo.strIntToAmt);
            }
        }
    }

}

void StatementDlg::storeCardStatement()
{
//    ui->useAmtStoreEdit->setFocus();
}

void StatementDlg::networkPayStatement()
{
    //如果实际支付金额>待付金额，则提示，并无法支付
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( p_wnd->text().toFloat()+0.003 < 0.01 ) return;
    QString strReceived = ui->receivedValueLabel->text();
    QStringList strList = strReceived.split( "￥" );
    if( p_wnd->text().toFloat() > strList[1].toFloat() ) {
        p_wnd->setText( strList[1] );
    }

    if (m_pAlipayRechargeDlg == NULL)
    {
        m_pAlipayRechargeDlg = new AlipayRechargeDlg( 0, (EPayMethod)m_stCurPayInfo.nPayType );
        m_pAlipayRechargeDlg->setAmtLabelText( "支付金额" );
        connect( m_pAlipayRechargeDlg, SIGNAL( sig_closeWnd() ), this, SLOT( slot_PayWndClose() ) );
        connect( m_pAlipayRechargeDlg, SIGNAL( sig_createPayInfo(EPayMethod,QString,QString)), this, SLOT( slot_createPayInfo( EPayMethod,QString,QString ) ) );//创建支付请求
        connect( m_pAlipayRechargeDlg, SIGNAL( sig_getPayStatus(int, QString)), this, SLOT( slot_getPayStatus( int, QString ) ) );//发送获取支付状态的请求
        connect( m_pAlipayRechargeDlg, SIGNAL( sig_payInfo(QString,EStatementStatus,QString)), this, SLOT( slot_payInfo(QString, EStatementStatus,QString) ) );
        connect( m_pAlipayRechargeDlg, SIGNAL( sig_payRevoke( QString )), this, SLOT( slot_payRevoke( QString ) ) );//发送撤销请求
        connect( m_pStatementCtr, SIGNAL( sigOnCreatePayStatus(int,QString,QString,QString,EPayMethod)) \
                 , m_pAlipayRechargeDlg, SLOT( slot_GetCreatePayInfo( int,QString,QString,QString,EPayMethod ) ) );//后台支付信息回复 有5秒定时循环
        connect( m_pStatementCtr, SIGNAL(sig_GetPayStatus(int,QString,QString,int)) \
                 , m_pAlipayRechargeDlg, SLOT( slot_GetPayStatus( int,QString,QString,int ) ) );//后台状态信息回复
    }
    m_pAlipayRechargeDlg->setCurPayMethod((EPayMethod)m_stCurPayInfo.nPayType);
    m_pAlipayRechargeDlg->setContext( p_wnd->text(), StatementScaning );
    m_pAlipayRechargeDlg->exec();
}

void StatementDlg::appleStatement()
{

}

void StatementDlg::jdWalletStatement()
{

}

//优惠券支付结算点击
void StatementDlg::couponStatement()
{
    if( ui->factAmtCouponEdit_1->text().isEmpty() || ui->factAmtCouponEdit_2->text().isEmpty()
            || ui->factAmtCouponEdit_2->text().toFloat() == 0.00 ) return;

    ui->factAmtCouponLabel_3->setText("");

    float fAmtReceived = ui->receivedValueLabel->text().split( "￥" )[1].toFloat();//待收金额
    float fCouponAmt = ui->factAmtCouponEdit_2->text().toFloat();//优惠券输入的金额
    if( fCouponAmt - fAmtReceived >= 0.00 ) {
        fCouponAmt = fAmtReceived;
        ui->factAmtCouponEdit_2->setText( CommonFun::floatToString( fAmtReceived ) );
    }

    DlgCommon *pDlg = new DlgCommon();
    pDlg->set_title( "优惠券" );
    pDlg->set_content( "是否确认支付?" );
    connect( pDlg, SIGNAL( sig_btn_sure() ), this, SLOT( slot_couponPay()) );
    connect( pDlg, SIGNAL( sig_dlg_close() ), this, SLOT( slot_cashClose() ) );
    connect( pDlg, SIGNAL( sig_btn_cancel() ), this, SLOT( slot_cashClose() ) );
    pDlg->show();
//    slot_createPayInfo( EPayMethod ePayMethod, QString strBarCode, QString strPayAmt );

//    qDebug()<<"llalalalalallalal";

}

void StatementDlg::virtualPayStatement(QString strText)
{
    //如果实际支付金额>待付金额，则提示，并无法支付
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( p_wnd->text().toFloat()+0.003 < 0.01 ) return;
    QString strReceived = ui->receivedValueLabel->text();
    QStringList strList = strReceived.split( "￥" );
    if( p_wnd->text().toFloat() > strList[1].toFloat() ) {
        p_wnd->setText( strList[1] );
    }

    DlgCommon *pDlg = new DlgCommon();
    pDlg->set_title( strText );
    pDlg->set_content( "是否确认支付?" );
    connect( pDlg, SIGNAL( sig_btn_sure() ), this, SLOT( slot_virtualPay() ) );
    connect( pDlg, SIGNAL( sig_dlg_close() ), this, SLOT( slot_cashClose() ) );
    connect( pDlg, SIGNAL( sig_btn_cancel() ), this, SLOT( slot_cashClose() ) );
    pDlg->show();
}

void StatementDlg::virtualPaysStatement()
{
    //如果实际支付金额>待付金额，则提示，并无法支付
    float fFactorAmt = ui->virtualPaysPage->getFactorAmt().toFloat();
    QString strReceived = ui->receivedValueLabel->text();
    QStringList strList = strReceived.split( "￥" );
    if(fFactorAmt > strList[1].toFloat())
    {
        ui->virtualPaysPage->setFactorAmt(strList[1]);
    }

    DlgCommon *pDlg = new DlgCommon();
    pDlg->set_title(ui->virtualPaysPage->getCurPayName());
    pDlg->set_content( "是否确认支付?" );
    connect( pDlg, SIGNAL( sig_btn_sure() ), this, SLOT( slot_virtualPays() ) );
    connect( pDlg, SIGNAL( sig_dlg_close() ), this, SLOT( slot_cashClose() ) );
    connect( pDlg, SIGNAL( sig_btn_cancel() ), this, SLOT( slot_cashClose() ) );
    pDlg->show();
}

void StatementDlg::firstClick()
{
    if( m_bFirst ) {
        //ui->factAmtCashEdit->setText( "" );
        QLineEdit *p_wnd = NULL;
        bool b_has_focus = getCurFocusWnd( p_wnd );
        if( !b_has_focus ) return;

        p_wnd->setText( "" );

        m_bFirst = false;
    }
}

//默认为2位小数点
int StatementDlg::findDecimalsNum()
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

bool StatementDlg::findPoint()
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

bool StatementDlg::getCurFocusWnd( QLineEdit *&pEditWnd )
{
    pEditWnd = (QLineEdit*)focusWidget();
    if( ui->factAmtCashEdit == pEditWnd
            || ui->balanceMemEdit == pEditWnd
            || ui->integUseMemEdit == pEditWnd
            || ui->factAmtAlipayEdit == pEditWnd
            || ui->factAmtWeEdit == pEditWnd
            || ui->factAmtAppleEdit == pEditWnd
            || ui->factAmtJdEdit == pEditWnd
//            || ui->factAmtUnionEdit == pEditWnd
            || ui->factAmtCouponEdit_1 == pEditWnd
            || ui->factAmtCouponEdit_2 == pEditWnd
            || ui->useAmtStoreEdit == pEditWnd
            || ui->currentAmtStoreEdit == pEditWnd
            || ui->cardIDStoreEdit == pEditWnd
            || ui->virtualPayWidget->getVirtualAmtEdit() == pEditWnd)
    {
        return true;
    }

    return false;
}

void StatementDlg::setPayDetailsText( int nPaySucNum, int nPayTotalNum )
{
    QString str_text = QString( "支付详情(%1/%2)" ).arg( nPaySucNum ).arg( nPayTotalNum );
    ui->paymentDetailButton->setText( str_text );
}

bool StatementDlg::getPayDetail( PaymentDetailInfo &stPaymentDetail, float fFactAmt )
{
    stPaymentDetail.sPaymentSequence = m_stStatementInfo.strOrderNum;
    QDateTime dtCur = QDateTime::currentDateTime();
    QString strPaymentOrderNum =  KPosIni::getPosCode() + dtCur.toString( "yyMMddhhmmss" );
    stPaymentDetail.strPaymentOrderNum =  strPaymentOrderNum;
    stPaymentDetail.ePayMethod = (EPayMethod)m_stCurPayInfo.nPayType;
    stPaymentDetail.ePaymentState = m_eCurPayState;
    stPaymentDetail.ePayType = m_eCurPayType;
    stPaymentDetail.fPaymentSum = fFactAmt;
    stPaymentDetail.bVirtual = m_stCurPayInfo.bVirtualPay;
    return true;
}

int StatementDlg::getTotalNum()
{
    int nTotalNum = (m_listPayInfo.size()-2)/3 + ( ( (m_listPayInfo.size()-2)%3)==0 ?0:1);

    return nTotalNum;
}

void StatementDlg::updatePayButton( int nPageNum )
{
    clearPayButtonText();
    int nSize = m_listPayInfo.size();
    //1.如果总的只有一页，然后加载按钮内容
    if( m_nTotalPageNum == 1 ) {
        QList< StatementMethodButton *>::iterator it = m_listPayButton.begin();
        for( int i =0; it != m_listPayButton.end(); ++it, ++i ) {
            if( i >= nSize ) break;

            (*it)->setText( EnumToString::payMethodToString( (EPayMethod)m_listPayInfo[i].nPayType ) );
            (*it)->setPayInfo( m_listPayInfo[i] );
        }
        return;
    }

    //2. 如果有多页，然后根据页号，加载按钮内容
    PayWayInfoSet stPayinfo;
    if( nPageNum == 1 ) {
        QList< StatementMethodButton *>::iterator it = m_listPayButton.begin();
        for( int i =1; it != m_listPayButton.end(); ++it, ++i ) {
            if( m_nOnePageCount < i ) break;
            if( i == 5 ) {
                (*it)->setRightButton();
                stPayinfo.nPayType = PayNextPage;
                (*it)->setPayInfo( stPayinfo );
                break;
            }

            (*it)->setText( EnumToString::payMethodToString( (EPayMethod)m_listPayInfo[i-1].nPayType ) );
            (*it)->setPayInfo( m_listPayInfo[i-1] );
        }
    } else if( nPageNum >1 && nPageNum < m_nTotalPageNum ) {
        int i = 4 + (nPageNum - 2)*3;
        QList< StatementMethodButton *>::iterator it = m_listPayButton.begin();
        for( int j = 1; it != m_listPayButton.end(); ++it,++j ) {
            if( m_nOnePageCount < j ) break;
            if( j == 1 ) {
                (*it)->setLeftButton();
                stPayinfo.nPayType = PayFrontPage;
                (*it)->setPayInfo( stPayinfo );
                continue;
            } else if( j == 5 ) {
                (*it)->setRightButton();
                stPayinfo.nPayType = PayNextPage;
                (*it)->setPayInfo( stPayinfo );
                break;
            }

            ++i;
            if( i > m_listPayInfo.size() ) break;

            (*it)->setText( EnumToString::payMethodToString( (EPayMethod)m_listPayInfo[i-1].nPayType) );
            (*it)->setPayInfo( m_listPayInfo[i-1] );
        }
    } else {
        int i = 4 + (nPageNum - 2)*3;
        QList< StatementMethodButton *>::iterator it = m_listPayButton.begin();
        for( int j = 1; it != m_listPayButton.end(); ++it, ++j ) {
            if( m_nOnePageCount < j ) break;
            if( j == 1 ) {
                (*it)->setLeftButton();
                stPayinfo.nPayType = (int)PayFrontPage;
                (*it)->setPayInfo( stPayinfo );
                continue;
            }

            ++i;
            if( i > m_listPayInfo.size() ) break;

            (*it)->setText( EnumToString::payMethodToString( (EPayMethod) m_listPayInfo[i-1].nPayType ) );
            (*it)->setPayInfo( m_listPayInfo[i-1] );
        }
    }
}

void StatementDlg::clearPayButtonText()
{
    PayWayInfoSet stPayInfo;
    QList< StatementMethodButton *>::iterator it = m_listPayButton.begin();
    for( ; it != m_listPayButton.end(); ++it ) {
        (*it)->setText( "" );
        (*it)->setPayInfo( stPayInfo );
        (*it)->setUnSelectedSelf();
    }
}

//void StatementDlg::memPayRequest(EPayMethod ePayMethod, QString strCardNo, QString strPayAmt, int nInteg, QString strPayPasswd, QString strIntToAmt )
//{
//    m_pStatementCtr->memPayRequest( m_stStatementInfo.strOrderNum, ePayMethod, strCardNo, strPayAmt, nInteg, strPayPasswd, strIntToAmt );
//}

void StatementDlg::updateRoundWay( QString strText )
{
    QLineEdit *p_wnd = NULL;
    bool bWndFocus = getCurFocusWnd( p_wnd );
    if( !bWndFocus ) return;

    switch( m_stCurPayInfo.nPayType ) {
    case PayCash:
        strText = updateCashRoundWay( strText );
        break;
    case UnionPay:
    case PayMemCard:
    case PayStoreCard:
    case PayAlipay:
    case PayWeChat:
    case ApplePay:
    case JdWallet:
        //strText = updateOtherRoundWay( strText );
        break;
    case Coupon:
    default:
        break;
    }

    p_wnd->setText( strText );
}

QString StatementDlg::updateCashRoundWay( QString strText )
{
    if( m_stCurPayInfo.nPayType != PayCash ) return "";

    float fText = strText.toFloat() + 0.003;
    switch ( m_stCurPayInfo.nDropType ) {
    case eUntreated://不处理
    {
         strText = strText.sprintf( "%.1f", fText );
        //p_wnd->setText( strText );
    }
        break;
    case eAbandon://舍弃
    {
        int nText = fText*10;
        float fText = nText*0.1;
        strText = QString::number( fText, 'f', 1 );
        //p_wnd->setText( strText );
    }
        break;
    case eRounding://四舍五入
    {
        strText = strText.sprintf( "%.1f", fText );
        //p_wnd->setText( strText );
    }
        break;
    case eCarry://进位
    {
        int nText = fText*100;
        nText = nText%10;
        if( nText > 0 ) {
            nText = fText*10 + 1;
        } else {
            nText = fText*10;
        }
        float fText = nText*0.1;
        strText = strText.sprintf( "%.1f", fText );
        //p_wnd->setText( strText );
    }
        break;
    default:
        break;
    }
    return strText;
}

QString StatementDlg::updateOtherRoundWay( QString strText )
{
    if( m_stCurPayInfo.nPayType == PayCash ) return "";

    float fText = strText.toFloat() +0.003;
    switch ( m_stCurPayInfo.nDropType ) {
    case eUntreated://不处理
        break;
    case eAbandon://舍弃
    {
        int nText = fText*10;
        float fText = nText*0.1;
        strText = strText.sprintf( "%.1f", fText );
        //p_wnd->setText( strText );
    }
        break;
    case eRounding://四舍五入
    {
        strText = strText.sprintf( "%.1f", strText.toFloat() );
        //p_wnd->setText( strText );
    }
        break;
    case eCarry://进位
    {
        int nText = fText*100;
        nText = nText%10;
        if( nText > 0 ) {
            nText = fText*10 + 1;
        } else {
            nText = fText*10;
        }
        float fText = nText*0.1;
        strText = strText.sprintf( "%.1f", fText );
    }
        break;
    default:
        break;
    }
    return strText;
}

QString StatementDlg::floatRoundWay( QString strAmt )
{
    QString strText = "";
    float fAmt = CommonFun::StringToFloat( strAmt );
    strText = strText.sprintf( "%.2f", fAmt );

    if( m_stCurPayInfo.nPayType != PayCash ) {
        return strText;
    }

    switch ( m_stCurPayInfo.nDropType ) {
    case eRounding://四舍五入
    {
        strText = strText.sprintf( "%.1f", fAmt );
    }
        break;
    case eAbandon://舍弃
    {
        int nText = fAmt*10;
        float fText = nText*0.1;
        strText = strText.sprintf( "%.1f", fText );
    }
        break;
    case eCarry://进位
    {
        int nText = fAmt*100;
        nText = nText%10;
        if( nText > 0 ) {
            nText = fAmt*10 + 1;
        } else {
            nText = fAmt*10;
        }
        float fText = nText*0.1;
        strText = strText.sprintf( "%.1f", fText );
    }
        break;
    case eUntreated://不处理
    {
        if( m_stCurPayInfo.nPayType == PayCash ) {
            strText = strText.sprintf( "%.1f", fAmt );
        } else {
            strText = strText.sprintf( "%.2f", fAmt );
        }
    }
        break;
    default:
        break;
    }

    return strText;
}

void StatementDlg::on_cardIDStoreEdit_returnPressed()
{
    QString sCardNum = ui->cardIDStoreEdit->text().trimmed();
    if (m_pStatementCtr == NULL || sCardNum.isEmpty())
    {
        return;
    }

    m_pStatementCtr->getPayCodeRequest(sCardNum);
}

void StatementDlg::on_statementStoreButton_clicked()
{
    ui->cardIDStoreEdit->setFocus();
    bool bEmpty = true;
    if (ui->cardIDStoreEdit->text().trimmed().isEmpty())
    {
        ui->cardIDStoreEdit->setFocus();
    }
    else if (ui->currentAmtStoreEdit->text().trimmed().isEmpty())
    {
//        ui->currentAmtStoreEdit->setFocus();
//        TipsDlg::instance()->releaseCtrl( QStringLiteral("请在有网的情况下扫码！"));
        ui->cardIDStoreEdit->setFocus();
    }
    else if (ui->useAmtStoreEdit->text().trimmed().isEmpty())
    {
        ui->useAmtStoreEdit->setFocus();
    }
    else
    {
        bEmpty = false;
    }

    if (bEmpty)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("填写都不能为空！"));
    }
    else
    {
        DlgCommon *pDlg = new DlgCommon();
        pDlg->set_title("储值卡");
        pDlg->set_content("是否确认支付?");
        connect( pDlg, SIGNAL( sig_btn_sure() ), this, SLOT( slot_confirmStoreCardPay()) );
        connect( pDlg, SIGNAL( sig_dlg_close() ), this, SLOT( slot_cashClose() ) );
        connect( pDlg, SIGNAL( sig_btn_cancel() ), this, SLOT( slot_cashClose() ) );
        pDlg->show();
    }
}

void StatementDlg::slot_confirmStoreCardPay()
{
    QObject *p_obj = QObject::sender();
    if( p_obj ) {
        delete p_obj;
        p_obj = NULL;
    }

    ui->statementStoreButton->setEnabled(false);
    QString strBarCode = m_storeCardInfo.sCardID;
    QString strPayAmt = ui->useAmtStoreEdit->text();
    m_pStatementCtr->createPayInfoRequest(m_stStatementInfo.strOrderNum, PayStoreCard, strBarCode, strPayAmt );
}

//优惠券支付返回处理
void StatementDlg::handleCouponInfo( int nCode, QString sMsg, QString strOrderNumS, QString strAuthCode )
{
    Q_UNUSED( strOrderNumS )
    Q_UNUSED( strAuthCode )

    ui->statementCouponButton->setEnabled( true );
    if( nCode != 0  ){//支付券支付失败
        float fCouponAmt = ui->factAmtCouponEdit_2->text().toFloat();//优惠券输入的金额
        //通过Agent，加载支付详情信息到支付详情表
        m_eCurPayState = e_PayFailed;
        PaymentDetailInfo stPaymentDetail;
        getPayDetail( stPaymentDetail, fCouponAmt );
        stPaymentDetail.strAuthCode = strAuthCode;
        stPaymentDetail.fPaymentSum = fCouponAmt;
        stPaymentDetail.strIntExchangeAmt = m_stMemInfo.strIntExchangeAmt;
        m_pStatementCtr->insertPayDetailData( stPaymentDetail );

        ui->factAmtCouponLabel_3->setText( sMsg );
        m_stStatementInfo.nTotalNum += 1;
    }else{//支付券支付成功
        float fTotalMoney = ui->simpleAmtValueLabel->text().split( "￥" )[1].toFloat();//整单金额
        float fAmtReceived = ui->receivedValueLabel->text().split( "￥" )[1].toFloat();//待收金额
        float fFactAmt = ui->factAmtCouponEdit_2->text().toFloat();//优惠券使用金额

        //通过Agent，加载支付详情信息到支付详情表
        m_eCurPayState = e_PaySuccess;
        PaymentDetailInfo stPaymentDetail;
        getPayDetail( stPaymentDetail, fFactAmt );
        stPaymentDetail.strPaymentOrderNum = strOrderNumS;
        stPaymentDetail.strAuthCode = strAuthCode;
        stPaymentDetail.fPaymentSum = fFactAmt;
        stPaymentDetail.strIntExchangeAmt = m_stMemInfo.strIntExchangeAmt;
        m_pStatementCtr->insertPayDetailData( stPaymentDetail );

        //优惠券支付成功，更新销售界面中的合计金额，已经优惠金额
        m_stStatementInfo.fCouponDisAmt += fFactAmt;
        m_stStatementInfo.fSimpleAmt -= fFactAmt;
        m_stStatementInfo.fDisAmt += fFactAmt;
        emit sig_updateSaleHead( m_stStatementInfo );

        float f_diff = fAmtReceived - fFactAmt;
        if( f_diff >= fNetPayEpsinon ) {//没有结算完
            float fDisAmt = ui->disAmtValueLabel->text().split( "￥")[1].toFloat() + fFactAmt;
            fTotalMoney -= fFactAmt;
            fAmtReceived -= fFactAmt;
            ui->disAmtValueLabel->setText( "￥" + CommonFun::floatToString( fDisAmt ) );
            ui->simpleAmtValueLabel->setText( "￥" + CommonFun::floatToString( fTotalMoney ) );
            ui->receivedValueLabel->setText( "￥" + CommonFun::floatToString( fAmtReceived ) );

            m_nCurPageNum = 1;
            updatePayMethod();
            QList< StatementMethodButton *>::iterator it = m_listPayButton.begin();
            for( int i = 0; it != m_listPayButton.end(); ++it,++i ) {
                if( (*it)->getPayInfo().nPayType == PayCash ) {
                    emit (*it)->click();
                    break;
                }
            }
        } else if( f_diff < fNetPayEpsinon ) {//现金结算完成
            fTotalMoney -= fFactAmt;
            fAmtReceived -= fFactAmt;
            m_stStatementInfo.fProfitLoss = 0.00;
            m_stStatementInfo.fOddChange = 0.00;
            m_stStatementInfo.fDisAmt = ui->disAmtValueLabel->text().split( "￥")[1].toFloat() + fFactAmt;
            m_stStatementInfo.fSimpleAmt = fTotalMoney;

            QDateTime dt = QDateTime::currentDateTime();
            //更新损益金额，总优惠金额，找零金额
            QString strDisAmt = CommonFun::floatToString( m_stStatementInfo.fDisAmt );
            QString strProfitLoss = CommonFun::floatToString( m_stStatementInfo.fProfitLoss );
            //QString strSimpleAmt = CommonFun::floatToString( m_stStatementInfo.fSimpleAmt );
            QString strOddChange = CommonFun::floatToString( m_stStatementInfo.fOddChange );
            QString strOutAmt = CommonFun::floatToString( fTotalMoney );
            QString strSmallChangeAmt = CommonFun::floatToString( m_fSmallChange );
            m_pStatementCtr->updateSaleHeadOutAmt( m_stStatementInfo.strOrderNum, strOutAmt );
            m_pStatementCtr->updateSmallChangeAmt( m_stStatementInfo.strOrderNum, strSmallChangeAmt );
            m_pStatementCtr->updateSaleHeadStatementInfo( m_stStatementInfo.strOrderNum, strDisAmt, strProfitLoss, strOutAmt, strOddChange );
            m_pStatementCtr->updateSaleHeadComplete( m_stStatementInfo.strOrderNum, e_headComplete, dt );
            m_pStatementCtr->printReceipt( m_stStatementInfo.strOrderNum, m_stMemInfo );
            KPosLog::instance()->writeDebugLog( "抹零金额4，订单号：" + m_stStatementInfo.strOrderNum + "，金额：" + strSmallChangeAmt );

            emit sig_oddChange( strOddChange );
            this->setEnabled( false );
            closeWnd();
        }
        m_stStatementInfo.nSucNum += 1;
        m_stStatementInfo.nTotalNum += 1;
        ui->factAmtCouponEdit_1->setText( "" );
        ui->factAmtCouponEdit_2->setText( "" );
    }
    setPayDetailsText( m_stStatementInfo.nSucNum, m_stStatementInfo.nTotalNum );
}

void StatementDlg::handleMemPayInfo(int nCode, QString sMsg, QString sBanlanceOrderNum, QString sIntegralOrderNum)
{
    ui->statementMemButton->setEnabled(true);

    //1.更新会员卡余额，积分
    float fPaidAmt = ui->amtPaidValueLabel->text().split("￥")[1].toFloat();
    float fReceivedAmt = ui->receivedValueLabel->text().split("￥")[1].toFloat();
    float fMemCardAmt = ui->id_lab_mem_card_value->text().split("￥")[1].toFloat();
    int nInteger = ui->id_lab_integ_value->text().toInt();

    //2.插入支付详情数据库
    PaymentDetailInfo stPaymentDetail;
    stPaymentDetail.ePaymentState = (nCode != e_success) ? e_PayFailed : e_PaySuccess;
    stPaymentDetail.sPaymentSequence = m_stStatementInfo.strOrderNum;
    QDateTime dtCur = QDateTime::currentDateTime();
    QString strPaymentOrderNum =  KPosIni::getPosCode() + dtCur.toString( "yyMMddhhmmss" );
    stPaymentDetail.strPaymentOrderNum =  strPaymentOrderNum;  
    stPaymentDetail.ePayType = e_Payment;

    stPaymentDetail.bVirtual = false;

    stPaymentDetail.strIntExchangeAmt = m_stMemInfo.strIntExchangeAmt;
    stPaymentDetail.strAuthCode = "";
    if (!sBanlanceOrderNum.isEmpty())
    {
        stPaymentDetail.ePayMethod = PayMemCard;
        stPaymentDetail.strPaymentOrderNum = sBanlanceOrderNum;
        stPaymentDetail.fPaymentSum = ui->balanceMemEdit->text().toFloat();
        stPaymentDetail.nPayIntegral = 0;
        m_pStatementCtr->insertPayDetailData(stPaymentDetail);

    }
    if (!sIntegralOrderNum.isEmpty())
    {
        stPaymentDetail.ePayMethod = IntegralToCansh;
        stPaymentDetail.strPaymentOrderNum = sIntegralOrderNum;
        stPaymentDetail.fPaymentSum = ui->arrivedValueLabel->text().toFloat();
        stPaymentDetail.nPayIntegral = ui->integUseMemEdit->text().toInt();
        m_pStatementCtr->insertPayDetailData(stPaymentDetail);
    }

    if(nCode != e_success) //支付失败
    {
        ui->memWarningLabel->setText(sMsg);
        return;
    }

    float fTotalPay = ui->balanceMemEdit->text().toFloat() + ui->arrivedValueLabel->text().toFloat();
    fPaidAmt += fTotalPay;
    QString strPaidAmt = CommonFun::floatToString( fPaidAmt );
    fMemCardAmt -= ui->balanceMemEdit->text().toFloat();
    QString strMemCardAmt = CommonFun::floatToString( fMemCardAmt );
    m_stMemInfo.stMemInfo.strAccountBalance = strMemCardAmt;
    nInteger -= ui->integUseMemEdit->text().toInt();
    m_stMemInfo.stMemInfo.nIntegral = nInteger;

    if( fReceivedAmt - fTotalPay > 0.00 ) {//
        fReceivedAmt -= fTotalPay;
        ui->amtPaidValueLabel->setText( "￥" + strPaidAmt );
        ui->receivedValueLabel->setText( "￥" + CommonFun::floatToString( fReceivedAmt ) );
        ui->id_lab_mem_card_value->setText( "￥" + strMemCardAmt );
        ui->id_lab_integ_value->setText( QString::number( nInteger ) );

        if( fMemCardAmt - fReceivedAmt >0.00 ) {
            ui->balanceMemEdit->setText( CommonFun::floatToString( fReceivedAmt ) );
        } else {
            ui->balanceMemEdit->setText( CommonFun::floatToString( fMemCardAmt ) );
        }
        ui->integUseMemEdit->setText( "" );
    } else {//结算完成
        //3.如果结算完成，则关闭结算对话框，并且清空销售界面中的信息
        QDateTime dt = QDateTime::currentDateTime();
        QString strSmallChangeAmt = CommonFun::floatToString( m_fSmallChange );
        m_pStatementCtr->updateSaleHeadFactorAmt( m_stStatementInfo.strOrderNum, CommonFun::floatToString( fPaidAmt ) );
        m_pStatementCtr->updateSmallChangeAmt( m_stStatementInfo.strOrderNum, strSmallChangeAmt );
        m_pStatementCtr->updateSaleHeadComplete( m_stStatementInfo.strOrderNum, e_headComplete, dt );
        m_pStatementCtr->printReceipt( m_stStatementInfo.strOrderNum, m_stMemInfo );
        KPosLog::instance()->writeDebugLog( "抹零金额5，订单号：" + m_stStatementInfo.strOrderNum + "，金额：" + strSmallChangeAmt );

        this->setEnabled( false );
        emit sig_oddChange( "0.0" );
        closeWnd();
    }

    m_stStatementInfo.nSucNum += 1;
    m_stStatementInfo.nTotalNum += 1;
    setPayDetailsText( m_stStatementInfo.nSucNum, m_stStatementInfo.nTotalNum );
}

void StatementDlg::handleStoreCardInfo(int nCode, QString sMsg, QString strOrderNumS, QString strAuthCode)
{
    if (nCode != e_success)
    {
        PaymentDetailInfo stPaymentDetail;
        m_eCurPayState = e_PayFailed;
        getPayDetail( stPaymentDetail, ui->useAmtStoreEdit->text().toFloat() );
        stPaymentDetail.fPaymentSum = ui->useAmtStoreEdit->text().toFloat();
        stPaymentDetail.nPayIntegral = 0;
        stPaymentDetail.strIntExchangeAmt = m_stMemInfo.strIntExchangeAmt;
        stPaymentDetail.strPaymentOrderNum = strOrderNumS;
        stPaymentDetail.strAuthCode = strAuthCode;
        m_pStatementCtr->insertPayDetailData( stPaymentDetail );

        m_stStatementInfo.nTotalNum += 1;
        setPayDetailsText( m_stStatementInfo.nSucNum, m_stStatementInfo.nTotalNum );
        ui->memWarningLabel->setText( sMsg );
        TipsDlg::instance()->releaseCtrl( QStringLiteral("储值卡支付失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        PaymentDetailInfo stPaymentDetail;
        m_eCurPayState = e_PaySuccess;
        getPayDetail( stPaymentDetail, ui->useAmtStoreEdit->text().toFloat() );
        stPaymentDetail.fPaymentSum = ui->useAmtStoreEdit->text().toFloat();
        stPaymentDetail.nPayIntegral = 0;
        stPaymentDetail.strIntExchangeAmt = m_stMemInfo.strIntExchangeAmt;
        stPaymentDetail.strPaymentOrderNum = strOrderNumS;
        stPaymentDetail.strAuthCode = strAuthCode;
        m_pStatementCtr->insertPayDetailData( stPaymentDetail );

        float fPaidAmt = ui->amtPaidValueLabel->text().split("￥")[1].toFloat();//已付金额
        float fReceivedAmt = ui->receivedValueLabel->text().split("￥")[1].toFloat();//待收金额
        float fStoreAmt = ui->currentAmtStoreEdit->text().split("￥")[1].toFloat();//储值卡金额
        float fTotalPay = ui->useAmtStoreEdit->text().toFloat();//当前支付总金额
        fStoreAmt -= fTotalPay;
        fPaidAmt += fTotalPay;
        QString strPaidAmt = CommonFun::floatToString( fPaidAmt );
//        fReceivedAmt -= fTotalPay;
        ui->currentAmtStoreEdit->setText( "￥" + CommonFun::floatToString( fStoreAmt ) );
        if( fReceivedAmt - fTotalPay > 0.00 ) {//
            fReceivedAmt -= fTotalPay;
            ui->amtPaidValueLabel->setText( "￥" + strPaidAmt );
            ui->receivedValueLabel->setText( "￥" + CommonFun::floatToString( fReceivedAmt ) );
            ui->useAmtStoreEdit->setText( "￥" + CommonFun::floatToString( fReceivedAmt ) );

//            if( fStoreAmt - fReceivedAmt >0.00 ) {
//                ui->useAmtStoreEdit->setText( CommonFun::floatToString( fReceivedAmt ) );
//            } else {
//                ui->useAmtStoreEdit->setText( CommonFun::floatToString( fStoreAmt ) );
//            }
        } else {//结算完成
            //3.如果结算完成，则关闭结算对话框，并且清空销售界面中的信息
            QDateTime dt = QDateTime::currentDateTime();
            QString strSmallChangeAmt = CommonFun::floatToString( m_fSmallChange );
            m_pStatementCtr->updateSaleHeadFactorAmt( m_stStatementInfo.strOrderNum, CommonFun::floatToString( fPaidAmt ) );
            m_pStatementCtr->updateSmallChangeAmt( m_stStatementInfo.strOrderNum, strSmallChangeAmt );
            m_pStatementCtr->updateSaleHeadComplete( m_stStatementInfo.strOrderNum, e_headComplete, dt );
            m_pStatementCtr->printReceipt( m_stStatementInfo.strOrderNum, m_stMemInfo );
            KPosLog::instance()->writeDebugLog( "抹零金额6，订单号：" + m_stStatementInfo.strOrderNum + "，金额：" + strSmallChangeAmt );

            this->setEnabled( false );
            emit sig_oddChange( "0.0" );
            closeWnd();
        }

        m_stStatementInfo.nSucNum += 1;
        m_stStatementInfo.nTotalNum += 1;
        setPayDetailsText( m_stStatementInfo.nSucNum, m_stStatementInfo.nTotalNum );

        ui->useAmtStoreEdit->setText("");
        ui->currentAmtStoreEdit->setText("");
        ui->cardIDStoreEdit->setText("");
        ui->cardIDStoreEdit->setFocus();

//        TipsDlg::instance()->releaseCtrl( QStringLiteral("储值卡支付成功,sMsg:%1").arg(sMsg));

    }
}

void StatementDlg::closeWnd()
{
    emit sig_wndClose();

    if (m_stMemInfo.stMemInfo.strCardNo.isEmpty())
    {
        return;
    }

    if (m_pStatementCtr != NULL)
    {
//        float fMoney, QString sCardNum, QString sOrderNum
        float fFactorAmt = 0.0f;
        float fIntegralMoney = 0.0f;
        m_pStatementCtr->getFactorAmt(fFactorAmt, m_stStatementInfo.strOrderNum);
        m_pStatementCtr->getIntegralPay(fIntegralMoney, m_stStatementInfo.strOrderNum);
        m_pStatementCtr->updateMemberIntegralRequest(fFactorAmt-fIntegralMoney, m_stMemInfo.stMemInfo.strCardNo, m_stStatementInfo.strOrderNum);
    }
}

//优惠券号输入完成后回车添加优惠金额
void StatementDlg::on_factAmtCouponEdit_1_returnPressed()
{
//    if( m_stCurPayInfo.nPayType == Coupon ) {
       slot_statement();
//    }
}


