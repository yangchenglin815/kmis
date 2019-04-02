#include "PaymentDetailDlg.h"
#include "ui_PaymentDetailDlg.h"
#include "CommonFun.h"
#include "DlgCommon.h"

PaymentDetailDlg::PaymentDetailDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PaymentDetailDlg)
    , m_sOrderNum( "" )
{
    ui->setupUi(this);
    ui->titleWidget->setTitleText(QStringLiteral("支付详情"));
    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    setModal( true );

    initCtrl();
    initConnect();
}

PaymentDetailDlg::~PaymentDetailDlg()
{
    delete ui;
}

void PaymentDetailDlg::initData( QString strOrderNum, QString strSimpleAmt, QString strPaid, QString strReceive )
{
    m_sOrderNum = strOrderNum;
    ui->simpleAmtValueLabel->setText( strSimpleAmt );
    ui->PaidAmtValueLabel->setText( strPaid );
    ui->receivedAmtValueLabel->setText( strReceive );
}

void PaymentDetailDlg::setPayDetailsList( QList<PaymentDetailInfo*> &listPayDetails )
{
    ui->payDetailsWidget->insertPayDetailsList( listPayDetails );
    ui->totalPayDetailsLabel->setText( QString::number( listPayDetails.size() ) );
}

void PaymentDetailDlg::slotPress(EPayMethod ePayMethod, QString strPayOrderNum, float fPayMoney, bool bVirtual )
{
    emit sigButtonPress( ePayMethod, strPayOrderNum, fPayMoney, bVirtual );
}

void PaymentDetailDlg::slot_RevokePay( int nCode, QString strMsg, QString strPayOrderNum, int nRevoked )
{
    Q_UNUSED( strMsg )
    if( nCode != 0 ) return;

    if( nRevoked == 1 ) {
        ui->payDetailsWidget->refundPayOrderNum( strPayOrderNum );

        //更新待付金额、已收金额
        PaymentDetailInfo *pPayDetailsInfo = ui->payDetailsWidget->getPayOrderInfo( strPayOrderNum );
        if( !pPayDetailsInfo ) return;

        pPayDetailsInfo->eButtonStatus = eDisAble;
        ui->payDetailsWidget->updatePayDetails( *pPayDetailsInfo );

        float fPaidAmt = ui->PaidAmtValueLabel->text().split("￥")[1].toFloat();
        float fReceivedAmt = ui->receivedAmtValueLabel->text().split("￥")[1].toFloat();
        fPaidAmt -= pPayDetailsInfo->fPaymentSum;
        fReceivedAmt += pPayDetailsInfo->fPaymentSum;

        QString strPaidAmt = "";
        strPaidAmt.sprintf( "￥%.2f", fPaidAmt );
        QString strReceivedAmt = "";
        strReceivedAmt.sprintf( "￥%.2f", fReceivedAmt );
        ui->PaidAmtValueLabel->setText( strPaidAmt );
        ui->receivedAmtValueLabel->setText( strReceivedAmt );

        QString strPayMoney = CommonFun::floatToString( pPayDetailsInfo->fPaymentSum );
        emit sig_RevokePay( strPayOrderNum, strPayMoney );
    }
}

void PaymentDetailDlg::slot_MemCardRevokePay( int nCode, QString strMsg, QString strPayOrderNum, int nRevoked, QString strMemCardBalance, int nMemCardIntegral )
{
    Q_UNUSED( strMsg )
    if( nCode != 0 ) return;
    if( nRevoked != 1 ) return;

    ui->payDetailsWidget->refundPayOrderNum( strPayOrderNum );
    //更新待付金额、已收金额
    PaymentDetailInfo *pPayDetailsInfo = ui->payDetailsWidget->getPayOrderInfo( strPayOrderNum );
    if( !pPayDetailsInfo ) return;

    pPayDetailsInfo->eButtonStatus = eDisAble;
    ui->payDetailsWidget->updatePayDetails( *pPayDetailsInfo );

    float fPaidAmt = ui->PaidAmtValueLabel->text().split("￥")[1].toFloat();
    float fReceivedAmt = ui->receivedAmtValueLabel->text().split("￥")[1].toFloat();
    fPaidAmt -= pPayDetailsInfo->fPaymentSum;
    fReceivedAmt += pPayDetailsInfo->fPaymentSum;

    float fIntToAmt = 0.00;
    if( pPayDetailsInfo->strIntExchangeAmt.toFloat() != 0 ) {
        fIntToAmt = pPayDetailsInfo->nPayIntegral*pPayDetailsInfo->strIntExchangeAmt.toFloat();
        fPaidAmt -= fIntToAmt;
        fReceivedAmt += fIntToAmt;
    }

    QString strPaidAmt = "";
    strPaidAmt.sprintf( "￥%.2f", fPaidAmt );
    QString strReceivedAmt = "";
    strReceivedAmt.sprintf( "￥%.2f", fReceivedAmt );
    ui->PaidAmtValueLabel->setText( strPaidAmt );
    ui->receivedAmtValueLabel->setText( strReceivedAmt );

    QString strPayMoney = CommonFun::floatToString( pPayDetailsInfo->fPaymentSum + fIntToAmt );
    emit sig_MemCardRevokePay( strPayOrderNum, strPayMoney, strMemCardBalance, nMemCardIntegral );
}

//使用现金退掉所有金额
void PaymentDetailDlg::slot_revokeAllAmt()
{
    QList<QString> strList = ui->PaidAmtValueLabel->text().split( "￥" );
    if( strList.size() == 2 && strList[1].toFloat() == 0.00 ) {
        return;
    }

    //是否确定退款
    DlgCommon *pDlg = new DlgCommon( 0, true );
    pDlg->set_title( "退款" );
    pDlg->set_content( "是否确认退款?" );
    connect( pDlg, SIGNAL(sig_btn_cancel()), pDlg, SLOT(close()) );
    connect( pDlg, SIGNAL(sig_dlg_close()), pDlg, SLOT( close() ) );
    if( pDlg->exec() != QDialog::Accepted ) {
        return;
    }

    float fPaidAmt = ui->PaidAmtValueLabel->text().split("￥")[1].toFloat();
    float fReceivedAmt = ui->receivedAmtValueLabel->text().split("￥")[1].toFloat();
    //向支付详情表中添加一条退款数据  m_sOrderNum，支付订单号， 支付方式，退款金额，支付状态，支付类型，创建时间，完成时间
    QString strPaidAmt = CommonFun::floatToString( fPaidAmt );

    fReceivedAmt += fPaidAmt;
    fPaidAmt -= fPaidAmt;
    QString strReceivedAmt = "";
    strReceivedAmt.sprintf( "￥%.2f", fReceivedAmt );
    ui->PaidAmtValueLabel->setText( "￥" + CommonFun::floatToString( fPaidAmt ) );
    ui->receivedAmtValueLabel->setText( strReceivedAmt );
    emit sig_revokeAllAmt( m_sOrderNum, strPaidAmt );
}

void PaymentDetailDlg::initCtrl()
{

}

void PaymentDetailDlg::initConnect()
{
    connect( ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT( close() ) );
    connect( ui->payDetailsWidget, SIGNAL(sigButtonPress(EPayMethod,QString,float,bool)), this, SLOT( slotPress(EPayMethod, QString, float,bool)) ) ;//SIGNAL(sigButtonPress(EPayMethod,QString)) );
    //connect( ui->payDetailsWidget, SIGNAL(sigButtonRelease(EPayMethod,QString)), this, SIGNAL(sigButtonRelease(EPayMethod,QString)) );
    connect( ui->cashRefundBtn, SIGNAL(clicked(bool)), this, SLOT( slot_revokeAllAmt() ) );
}
