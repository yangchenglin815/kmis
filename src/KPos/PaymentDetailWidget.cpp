#include "PaymentDetailWidget.h"
#include "ui_PaymentDetailWidget.h"

PaymentDetailWidget::PaymentDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaymentDetailWidget),
    m_nOnePageCount(2),
    m_nCurPage(1),
    m_nTotalPage(1)
{
    ui->setupUi(this);

    initCtrl();
    initConnect();
}

PaymentDetailWidget::~PaymentDetailWidget()
{
    delete ui;
}

void PaymentDetailWidget::updatePayDetails( PaymentDetailInfo &stPayDetails )
{
    ui->PayDetailsView->appendItem( stPayDetails );
}

void PaymentDetailWidget::insertPayDetailsList( QList<PaymentDetailInfo*> &listPayDetails )
{
    initCtrl();
    m_paymentDetailInfoList = listPayDetails;
    generatePaymentDetail();
    if( m_nCurPage < m_nTotalPage ) {
        ui->downPageButton->setEnabled( true );
    }
}

void PaymentDetailWidget::refundPayOrderNum( QString strPayOrderNum )
{
    QList<PaymentDetailInfo*>::iterator it = m_paymentDetailInfoList.begin();
    for( ; it != m_paymentDetailInfoList.end(); ++it ) {
        if( (*it)->strPaymentOrderNum == strPayOrderNum ) {
            (*it)->ePayType = e_Refund;
            (*it)->ePaymentState = e_PayRefund;
            ui->PayDetailsView->appendItem( **it );
            break;
        }
    }
}

PaymentDetailInfo *PaymentDetailWidget::getPayOrderInfo( QString strPayOrderNum )
{
    PaymentDetailInfo *pPayDetailsInfo = NULL;
    QList<PaymentDetailInfo*>::iterator it = m_paymentDetailInfoList.begin();
    for( ; it != m_paymentDetailInfoList.end(); ++it ) {
        if( (*it)->strPaymentOrderNum == strPayOrderNum ) {
            pPayDetailsInfo = (*it);
            break;
        }
    }
    return pPayDetailsInfo;
}

void PaymentDetailWidget::generatePaymentDetail()
{
    ui->PayDetailsView->clearItem();
    int nLen = m_paymentDetailInfoList.length();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    for (int i = nStartPos; i < nEndPos && i < nLen; i++)
    {
        ui->PayDetailsView->appendItem(*m_paymentDetailInfoList[i]);
    }
    m_nTotalPage = nLen/m_nOnePageCount + (nLen % m_nOnePageCount != 0);
    ui->pageLabel->setText(QStringLiteral("%1/%2页").arg(m_nCurPage).arg(m_nTotalPage));
}

void PaymentDetailWidget::initCtrl()
{
    ui->upPageButton->setEnabled( false );
    ui->downPageButton->setEnabled( false );
}

void PaymentDetailWidget::initConnect()
{
    connect( ui->PayDetailsView, SIGNAL(sigButtonClicked(EPayMethod,QString,float,bool)), this, SIGNAL(sigButtonPress(EPayMethod,QString,float,bool) ) );
    connect( ui->PayDetailsView, SIGNAL(sigButtonRelease(EPayMethod,QString)), this, SIGNAL(sigButtonRelease(EPayMethod,QString)) );
}

void PaymentDetailWidget::on_upPageButton_clicked()
{
    if (m_nCurPage > 1)
    {
        m_nCurPage--;
        generatePaymentDetail();
    }

    if( m_nCurPage == 1 ) {
        ui->upPageButton->setEnabled( false );
    }

    if( m_nCurPage < m_nTotalPage ) {
        ui->downPageButton->setEnabled( true );
    }
}

void PaymentDetailWidget::on_downPageButton_clicked()
{

    if (m_nCurPage * m_nOnePageCount < m_paymentDetailInfoList.length())
    {
        m_nCurPage++;
        generatePaymentDetail();
    }

    if( m_nCurPage > 1 ) {
        ui->upPageButton->setEnabled( true );
    }

    if( m_nCurPage >= m_nTotalPage ) {
        ui->downPageButton->setEnabled( false );
    }
}

