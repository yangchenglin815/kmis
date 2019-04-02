#include "ReceiveOrderCheckWidget.h"
#include "ui_ReceiveOrderCheckWidget.h"
#include "../data/enumData.h"

ReceiveOrderCheckWidget::ReceiveOrderCheckWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReceiveOrderCheckWidget)
    , m_pReceiveOrderInfo(NULL)
{
    ui->setupUi(this);
    initConnect();
}

ReceiveOrderCheckWidget::~ReceiveOrderCheckWidget()
{
    delete ui;
}

void ReceiveOrderCheckWidget::initCtrl(DeliveryOrderCtrl *pDeliveryOrderCtrl)
{
    ui->receiveOrderGoodsWidget->initCtrl(pDeliveryOrderCtrl);
}

//void ReceiveOrderCheckWidget::initData(ReceiveOrderInfo *pReceiveOrderInfo, bool isFinished)
//{
//    m_pReceiveOrderInfo = pReceiveOrderInfo;
//    ui->orderIdValueLabel->setText(m_pReceiveOrderInfo->sCode);
//    ui->providerNameLabel->setText(m_pReceiveOrderInfo->sProviderName);
//    ui->orderTimeLabel->setText(QString("%1 %2").arg(pReceiveOrderInfo->sUploadDate).arg(pReceiveOrderInfo->sUploadTime));
//    ui->receiveOrderGoodsWidget->initData(pReceiveOrderInfo->receiveOrderGoodsInfoList, isFinished);
//}

void ReceiveOrderCheckWidget::initData(const QList<DeliveryOrderDetailInfo_s> &deliveryOrderDetailInfoList, ReceiveOrderInfo *pReceiveOrderInfo)
{
    ui->orderIdValueLabel->setText(pReceiveOrderInfo->sCode);
    ui->providerNameLabel->setText(pReceiveOrderInfo->sProviderName);
    ui->orderTimeLabel->setText(QString("%1 %2").arg(pReceiveOrderInfo->sUploadDate).arg(pReceiveOrderInfo->sUploadTime));
    ui->receiveOrderGoodsWidget->initData(deliveryOrderDetailInfoList, (pReceiveOrderInfo->nRecieveState == e_RecieveOrderFinish));
}

void ReceiveOrderCheckWidget::on_backButton_clicked()
{
    emit sigBack();
}

void ReceiveOrderCheckWidget::slot_saveReceiveGoods(ReceiveOrderGoodsInfo *pReceiveOrderGoodsInfo, ReceiveOrderGoodsInfo receiveOrderGoodsInfo)
{
    if (m_pReceiveOrderInfo != NULL)
    {
        m_pReceiveOrderInfo->nRecieveState = e_RecieveOrderDoing;
        if (pReceiveOrderGoodsInfo->nRealReceiveSumNum >= 0)
        {
            m_pReceiveOrderInfo->nRealReceiveSumNum += (pReceiveOrderGoodsInfo->nRealReceiveSumNum - receiveOrderGoodsInfo.nRealReceiveSumNum);
        }
        m_pReceiveOrderInfo->fRealReceiveSumValue += (pReceiveOrderGoodsInfo->fRealReceiveSumValue - receiveOrderGoodsInfo.fRealReceiveSumValue);
        m_pReceiveOrderInfo->fSumPrice += (pReceiveOrderGoodsInfo->fSumPrice - receiveOrderGoodsInfo.fSumPrice);
    }
}

void ReceiveOrderCheckWidget::slot_finishReceiveOrderGoods()
{
    m_pReceiveOrderInfo->nRecieveState = e_RecieveOrderFinish;
    on_backButton_clicked();
}

void ReceiveOrderCheckWidget::initConnect()
{
    qRegisterMetaType<ReceiveOrderGoodsInfo*>("ReceiveOrderGoodsInfo*");
    qRegisterMetaType<ReceiveOrderGoodsInfo>("ReceiveOrderGoodsInfo");
    connect(ui->receiveOrderGoodsWidget, SIGNAL(sigSaveReceiveGoods(ReceiveOrderGoodsInfo*, ReceiveOrderGoodsInfo)),
            this, SLOT(slot_saveReceiveGoods(ReceiveOrderGoodsInfo*, ReceiveOrderGoodsInfo)));
    connect(ui->receiveOrderGoodsWidget, SIGNAL(sigFinishReceiveOrderGoods()),
            this, SLOT(slot_finishReceiveOrderGoods()));
}
