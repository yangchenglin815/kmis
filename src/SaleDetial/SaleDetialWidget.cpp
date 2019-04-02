#include "SaleDetialWidget.h"
#include "ui_SaleDetialWidget.h"
#include "TipsDlg.h"

SaleDetialWidget::SaleDetialWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SaleDetialWidget)
  , m_saleDetialCtrl(NULL)
{
    ui->setupUi(this);
    init();
    initconnect();
}

SaleDetialWidget::~SaleDetialWidget()
{
    delete ui;
}

void SaleDetialWidget::initSaleDetialList()
{
    if(m_saleDetialCtrl == NULL){
        m_saleDetialCtrl = new SaleDetialCtrl;
        qRegisterMetaType<QList<ReceiptInfo> >("QList<ReceiptInfo>");
        connect(m_saleDetialCtrl, SIGNAL(sigOnGetSaleDetialOrder(int,QString,QList<ReceiptInfo>))
                , this, SLOT(slot_getSaleDetialOrder(int,QString,QList<ReceiptInfo>)));
        ui->receiptListPage->initSaleDetialCtrl(m_saleDetialCtrl);
    }
    m_saleDetialCtrl->getSaleDetialListRequest();
}

void SaleDetialWidget::slot_showDetialPage()
{
    ui->stackedWidget->setCurrentWidget(ui->receiptDetialPage);
}

void SaleDetialWidget::slot_ReturnClicked()
{
    if(ui->stackedWidget->currentWidget() == ui->receiptListPage){
       ui->receiptListPage->hideCalendarWidget();
       ui->receiptListPage->initContent();
       emit sigReturnClicked();
    }
    else if(ui->stackedWidget->currentWidget() == ui->receiptDetialPage){
        ui->stackedWidget->setCurrentWidget(ui->receiptListPage);
    }
}

void SaleDetialWidget::slot_getSaleDetialOrder(int nCode, QString sMsg, QList<ReceiptInfo> InfoList)
{
    if(nCode != e_success){
        TipsDlg::instance()->releaseCtrl(QStringLiteral("销售明细列表获取失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        ui->receiptListPage->initData(InfoList);
    }
}

void SaleDetialWidget::slot_getSaleReceiptOrder(int nCode, QString sMsg, SaleHead saleHead, QList<SaleDetails> InfoList, QList<PaymentDetailInfo> paymentList)
{
    if(nCode != e_success){
        TipsDlg::instance()->releaseCtrl(QStringLiteral("小票明细列表获取失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        ui->receiptDetialPage->initData(InfoList, saleHead, paymentList);
    }
}

void SaleDetialWidget::init()
{
    ui->stackedWidget->setCurrentWidget(ui->receiptListPage);
}

void SaleDetialWidget::initconnect()
{
   connect(ui->receiptListPage, SIGNAL(sigShowDetialPage()), this, SLOT(slot_showDetialPage()));
   connect(ui->titleWidget, SIGNAL(sigReturnClicked()), this, SLOT(slot_ReturnClicked()));
   qRegisterMetaType<QList<SaleDetails>>("QList<SaleDetails>");
   qRegisterMetaType<QList<PaymentDetailInfo>>("QList<PaymentDetailInfo>");
   connect(ui->receiptListPage, SIGNAL(sigGetSaleReceiptOrder(int,QString,SaleHead,QList<SaleDetails>,QList<PaymentDetailInfo>))
           , this, SLOT(slot_getSaleReceiptOrder(int,QString,SaleHead,QList<SaleDetails>,QList<PaymentDetailInfo>)));
}
