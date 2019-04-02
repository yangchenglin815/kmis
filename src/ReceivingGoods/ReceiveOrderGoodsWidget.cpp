#include "ReceiveOrderGoodsWidget.h"
#include "ui_ReceiveOrderGoodsWidget.h"
#include "../data/enumData.h"
#include <QMessageBox>

ReceiveOrderGoodsWidget::ReceiveOrderGoodsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReceiveOrderGoodsWidget)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
    , m_pReceiveOrderGoodsDetailDlg(NULL)
    , m_fSumPrice(0.0f)
    , m_pDeliveryOrderCtrl(NULL)
{
    ui->setupUi(this);
//    test();
    initConnect();
}

ReceiveOrderGoodsWidget::~ReceiveOrderGoodsWidget()
{
    if (m_pReceiveOrderGoodsDetailDlg != NULL)
    {
        m_pReceiveOrderGoodsDetailDlg->deleteLater();
    }
    delete ui;
}

void ReceiveOrderGoodsWidget::initCtrl(DeliveryOrderCtrl *pDeliveryOrderCtrl)
{
    m_pDeliveryOrderCtrl = pDeliveryOrderCtrl;
    qRegisterMetaType<ReceiveGoodsDetail_s>("ReceiveGoodsDetail_s");
    connect(m_pDeliveryOrderCtrl, SIGNAL(sigOnGetReceiveGoodsDetail(int,QString,ReceiveGoodsDetail_s,int))
            , this, SLOT(slot_onGetReceiveGoodsDetail(int,QString,ReceiveGoodsDetail_s,int)));
}

void ReceiveOrderGoodsWidget::initData(const QList<DeliveryOrderDetailInfo_s> &deliveryOrderDetailInfoList, bool bReceiveFinish)
{
    ui->titleWidget->setFinishedFlag(bReceiveFinish);
    ui->listView->setFinishFlag(bReceiveFinish);
    if (bReceiveFinish)
    {
        ui->confirmButton->hide();
    }
    else
    {
        ui->confirmButton->show();
    }

    int nLen = deliveryOrderDetailInfoList.length();
    DeliveryOrderDetailInfo_s deliveryOrderDetailInfo_s;
    ReceiveOrderGoodsInfo receiveOrderGoodsInfo;
    for (int i = 0; i < nLen; i++)
    {
        deliveryOrderDetailInfo_s = deliveryOrderDetailInfoList[i];
        receiveOrderGoodsInfo.nId = deliveryOrderDetailInfo_s.nId; // 送货单商品id
        receiveOrderGoodsInfo.nGoodsId = deliveryOrderDetailInfo_s.nGoodsId; // 商品id
        receiveOrderGoodsInfo.sGoodName = deliveryOrderDetailInfo_s.sGoodName; // 商品名称
        receiveOrderGoodsInfo.sGoodsCode = deliveryOrderDetailInfo_s.sGoodsCode; // 商品编号
        receiveOrderGoodsInfo.sUnitSpecification = deliveryOrderDetailInfo_s.sUnitSpecification; // 规格单位  (如4公斤)
        receiveOrderGoodsInfo.fUnitSpecificationValue = deliveryOrderDetailInfo_s.fUnitSpecificationValue; // 规格单位值  (4 -- 4公斤重的4)
//        receiveOrderGoodsInfo.sSpecification = deliveryOrderDetailInfo_s.sSpecification; // 规格 (箱)
        receiveOrderGoodsInfo.nNeedReceiveSumNum = deliveryOrderDetailInfo_s.nNeedReceiveSumNum; // 应收件数
        receiveOrderGoodsInfo.fNeedReceiveSumValue = deliveryOrderDetailInfo_s.fNeedReceiveSumValue; // 应收数量
        receiveOrderGoodsInfo.nRealReceiveSumNum = deliveryOrderDetailInfo_s.nRealReceiveSumNum; // 实收件数
        receiveOrderGoodsInfo.fRealReceiveSumValue = deliveryOrderDetailInfo_s.fRealReceiveSumValue; // 实收数量
        receiveOrderGoodsInfo.fSumPrice = deliveryOrderDetailInfo_s.fSumPrice; // 收货金额
        receiveOrderGoodsInfo.bGoodsRecieveFinish = (deliveryOrderDetailInfo_s.nRecieveGoodsState == e_goodsFinishReceive); // 商品是否收货完成
//        receiveOrderGoodsInfo.bStandardGoods = true; // 是否标品
//        receiveOrderGoodsInfo.nWeighType = deliveryOrderDetailInfo_s.nId; // 称重类型
//        receiveOrderGoodsInfo.standardInfo = deliveryOrderDetailInfo_s.nId;
//        receiveOrderGoodsInfo.noStandardInfo = deliveryOrderDetailInfo_s.nId;
//        receiveOrderGoodsInfo.disperseInfo = deliveryOrderDetailInfo_s.nId;
        m_receiveOrderGoodsInfoList.append(receiveOrderGoodsInfo);
    }

    m_nCurPage = 1;
    int nCount = m_receiveOrderGoodsInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void ReceiveOrderGoodsWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void ReceiveOrderGoodsWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void ReceiveOrderGoodsWidget::on_confirmButton_clicked()
{
    emit sigFinishReceiveOrderGoods();
}

void ReceiveOrderGoodsWidget::slot_receiveOrderGoodsDetail(int nDeliverGoodId)
{
    if (m_pDeliveryOrderCtrl != NULL)
    {
        m_pDeliveryOrderCtrl->getReceiveGoodsDetailRequest(nDeliverGoodId);
    }
}

void ReceiveOrderGoodsWidget::slot_saveReceiveGoods(ReceiveGoodsDetail_s *pReceiveGoodsDetail, ReceiveOrderGoodsInfo *pReceiveOrderGoodsInfo)
{
    Q_UNUSED( pReceiveGoodsDetail )
    Q_UNUSED( pReceiveOrderGoodsInfo )
//    if (ui->listView->isExistReceiveOrderGoods(pReceiveOrderGoodsInfo->nGoodsId))
//    {
//        m_fSumPrice += pReceiveOrderGoodsInfo->fSumPrice - pReceiveGoodsDetail->fSumPrice;
//        ui->sumPriceLabel->setText(QString("￥%1").arg(QString::number(m_fSumPrice, 'f', 2)));

//        ui->listView->appendItem(*pReceiveOrderGoodsInfo);
//        emit sigSaveReceiveGoods(pReceiveOrderGoodsInfo, oldReceiveOrderGoodsInfo);
//    }
}

void ReceiveOrderGoodsWidget::slot_onGetReceiveGoodsDetail(int nCode, QString sMsg, ReceiveGoodsDetail_s receiveGoodsDetail_s, int nDeliveryGoodId)
{
    if (nCode != e_success)
    {
        QMessageBox::information(this, QStringLiteral("提示")
                                 , QString(QStringLiteral("出现异常--错误码:%1, 错误信息:%2")).arg(nCode).arg(sMsg));
        return;
    }

    ReceiveOrderGoodsInfo *pReceiveOrderGoodsInfo = findReceiveOrderGoodsInfo(nDeliveryGoodId);
    if (pReceiveOrderGoodsInfo != NULL)
    {
        if (m_pReceiveOrderGoodsDetailDlg == NULL)
        {
            m_pReceiveOrderGoodsDetailDlg = new ReceiveOrderGoodsDetailDlg;
            m_pReceiveOrderGoodsDetailDlg->initCtrl(m_pDeliveryOrderCtrl);
            qRegisterMetaType<ReceiveGoodsDetail_s*>("ReceiveGoodsDetail_s*");
            qRegisterMetaType<ReceiveOrderGoodsInfo*>("ReceiveOrderGoodsInfo*");
            connect(m_pReceiveOrderGoodsDetailDlg, SIGNAL(sigSaveReceiveGoods(ReceiveGoodsDetail_s*,ReceiveOrderGoodsInfo*)),
                    this, SLOT(slot_saveReceiveGoods(ReceiveGoodsDetail_s*,ReceiveOrderGoodsInfo*)));
        }
        m_pReceiveOrderGoodsDetailDlg->initData(pReceiveOrderGoodsInfo, receiveGoodsDetail_s);
        m_pReceiveOrderGoodsDetailDlg->exec();
    }
}

void ReceiveOrderGoodsWidget::initConnect()
{
    connect(ui->listView, SIGNAL(sigReceiveOrderGoodsDetail(int)),
            this, SLOT(slot_receiveOrderGoodsDetail(int)));
}

void ReceiveOrderGoodsWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_receiveOrderGoodsInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(m_receiveOrderGoodsInfoList[i]);
    }
}

void ReceiveOrderGoodsWidget::checkCurPageButtonState()
{
    if (m_nCurPage <= 1)
    {
        m_nCurPage = 1;
        ui->lastPageButton->setEnabled(false);
    }
    else
    {
        ui->lastPageButton->setEnabled(true);
    }

    if (m_nCurPage < m_nTotalPage)
    {
        ui->nextPageButton->setEnabled(true);
    }
    else
    {
        m_nCurPage = m_nTotalPage;
        ui->nextPageButton->setEnabled(false);
    }
}

ReceiveOrderGoodsInfo *ReceiveOrderGoodsWidget::findReceiveOrderGoodsInfo(int nDeliverGoodId)
{
    int nLen = m_receiveOrderGoodsInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_receiveOrderGoodsInfoList[i].nId == nDeliverGoodId)
        {
            return &m_receiveOrderGoodsInfoList[i];
        }
    }

    return NULL;
}
