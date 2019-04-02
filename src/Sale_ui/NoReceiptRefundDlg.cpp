#include "NoReceiptRefundDlg.h"
#include "ui_NoReceiptRefundDlg.h"
#include "CommonFun.h"
#include <QDebug>

NoReceiptRefundDlg::NoReceiptRefundDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NoReceiptRefundDlg)
    , m_nRefundReasonId(-1)
    , m_nIntegralMoney(0.0f)
{
    ui->setupUi(this);
    setWindowFlags( Qt::FramelessWindowHint );
    ui->titleWidget->setTitleText(QStringLiteral("退货结算"));
    initConnect();
}

NoReceiptRefundDlg::~NoReceiptRefundDlg()
{
    delete ui;
}

void NoReceiptRefundDlg::setRefundCash(float fRefundCash)
{
    ui->refundCashLabel->setText(QString("￥%1").arg(CommonFun::handleCash(fRefundCash - m_nIntegralMoney)));
}

void NoReceiptRefundDlg::setRefundReasonId(int nReasonId)
{
    m_nRefundReasonId = nReasonId;
}

void NoReceiptRefundDlg::showIntegralMoney(float fMoney)
{
    m_nIntegralMoney = fMoney;
    ui->integralLabel->show();
    ui->integralMoneyLabel->show();
    ui->integralMoneyLabel->setText(QString("￥%1").arg(CommonFun::floatToString(fMoney)));
}

void NoReceiptRefundDlg::hideIntegralMoney()
{
    m_nIntegralMoney = 0.0f;
    ui->integralLabel->hide();
    ui->integralMoneyLabel->hide();
}

void NoReceiptRefundDlg::on_confirmButton_clicked()
{
    this->hide();
    emit sigConfirm(m_nRefundReasonId);
}

void NoReceiptRefundDlg::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(hide()));
}


