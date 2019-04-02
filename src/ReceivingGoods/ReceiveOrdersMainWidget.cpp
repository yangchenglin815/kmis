#include "ReceiveOrdersMainWidget.h"
#include "ui_ReceiveOrdersMainWidget.h"
#include "../data/enumData.h"
#include "../data/constData.h"

static QString s_sNormalQss = "font-family:'微软雅黑';font-size:14px;color:#ffffff;border-image: url(:/receivingGoodsImage/topTab.png);";
static QString s_sSelectedQss = "font-family:'微软雅黑';font-size:14px;color:#333333;border-image: url(:/receivingGoodsImage/topTab_Press.png);";

ReceiveOrdersMainWidget::ReceiveOrdersMainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReceiveOrdersMainWidget)
    , m_nOnePageCount(6)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
    init();
    initConnect();
}

ReceiveOrdersMainWidget::~ReceiveOrdersMainWidget()
{
    delete ui;
}

void ReceiveOrdersMainWidget::initData(const QList<ReceiveOrderInfo *> &receiveOrdersInfoList)
{
    m_receiveOrdersInfoList = receiveOrdersInfoList;
    m_allOrdersInfoList = receiveOrdersInfoList;
    setFinishAndNotList();

    m_nCurPage = 1;
    int nCount = m_receiveOrdersInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void ReceiveOrdersMainWidget::updateData()
{
    int nLen = m_allOrdersInfoList.length();
    m_finishOrdersInfoList.clear();
    m_notFinishOrdersInfoList.clear();
    ReceiveOrderInfo *pReceiveOrderInfo = NULL;
    for (int i = 0; i < nLen; i++)
    {
        pReceiveOrderInfo = m_allOrdersInfoList[i];
        if (pReceiveOrderInfo->nRecieveState == e_RecieveOrderFinish)
        {
            m_finishOrdersInfoList.append(pReceiveOrderInfo);
        }
        else
        {
            m_notFinishOrdersInfoList.append(pReceiveOrderInfo);
        }
    }
    generateUI();
}

void ReceiveOrdersMainWidget::appendData(ReceiveOrderInfo *pReceiveOrderInfo)
{
    m_allOrdersInfoList.append(pReceiveOrderInfo);
    if (pReceiveOrderInfo->nRecieveState == e_RecieveOrderFinish)
    {
        m_finishOrdersInfoList.append(pReceiveOrderInfo);
    }
    else
    {
        m_notFinishOrdersInfoList.append(pReceiveOrderInfo);
    }
    updateClick();
}

void ReceiveOrdersMainWidget::on_allRecieveButton_clicked()
{
    setButtonQss(ui->allRecieveButton);
    m_receiveOrdersInfoList = m_allOrdersInfoList;
    m_nCurPage = 1;
    int nCount = m_receiveOrdersInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void ReceiveOrdersMainWidget::on_noFinishReciveButton_clicked()
{
    setButtonQss(ui->noFinishReciveButton);
    m_receiveOrdersInfoList = m_notFinishOrdersInfoList;
    m_nCurPage = 1;
    int nCount = m_receiveOrdersInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void ReceiveOrdersMainWidget::on_finishedRecieveButton_clicked()
{
    setButtonQss(ui->finishedRecieveButton);
    m_receiveOrdersInfoList = m_finishOrdersInfoList;
    m_nCurPage = 1;
    int nCount = m_receiveOrdersInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void ReceiveOrdersMainWidget::setButtonQss(QPushButton *pPushButton)
{
    if (m_pSelectedButton != pPushButton)
    {
        if (pPushButton != NULL)
        {
           pPushButton->setStyleSheet(s_sSelectedQss);
        }
        if (m_pSelectedButton != NULL)
        {
            m_pSelectedButton->setStyleSheet(s_sNormalQss);
        }
        m_pSelectedButton = pPushButton;
    }
}

void ReceiveOrdersMainWidget::init()
{
    ui->allRecieveButton->setStyleSheet(s_sSelectedQss);
    ui->noFinishReciveButton->setStyleSheet(s_sNormalQss);
    ui->finishedRecieveButton->setStyleSheet(s_sNormalQss);
    m_pSelectedButton = ui->allRecieveButton;
}

void ReceiveOrdersMainWidget::initConnect()
{
    connect(ui->listView, SIGNAL(sigCheckReceiveOrder(int)), this, SLOT(slot_checkReceiveOrder(int)));
}

void ReceiveOrdersMainWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_receiveOrdersInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(*(m_receiveOrdersInfoList[i]));
    }
}

void ReceiveOrdersMainWidget::checkCurPageButtonState()
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

void ReceiveOrdersMainWidget::setFinishAndNotList()
{
    int nLen = m_receiveOrdersInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_receiveOrdersInfoList[i]->nRecieveState == e_RecieveOrderFinish)
        {
            m_finishOrdersInfoList.append(m_receiveOrdersInfoList[i]);
        }
        else
        {
            m_notFinishOrdersInfoList.append(m_receiveOrdersInfoList[i]);
        }
    }
}

void ReceiveOrdersMainWidget::updateClick()
{
    if (m_pSelectedButton == ui->allRecieveButton)
    {
        on_allRecieveButton_clicked();
    }
    else if (m_pSelectedButton == ui->noFinishReciveButton)
    {
        on_noFinishReciveButton_clicked();
    }
    else if (m_pSelectedButton == ui->finishedRecieveButton)
    {
        on_finishedRecieveButton_clicked();
    }
    else
    {
        m_pSelectedButton = ui->allRecieveButton;
        on_allRecieveButton_clicked();
    }
}

void ReceiveOrdersMainWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void ReceiveOrdersMainWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void ReceiveOrdersMainWidget::on_createDeliveryOrderButton_clicked()
{
    emit sigCreateDeliveryOrder();
}

void ReceiveOrdersMainWidget::slot_checkReceiveOrder(int nOrderId)
{
    emit sigCheckReceiveOrder(nOrderId);
}

void ReceiveOrdersMainWidget::slot_createOrder(ReceiveProviderInfo receiveProviderInfo)
{
    static int nOrderId = 10000; // 订单编号需要从后台获取，现在在本地模拟
    nOrderId++;
    QString uploadDate = "2017.02.16"; // 后台获取
    QString uploadTime = "11:11"; // 后台获取

    ReceiveOrderInfo* pReceiveOrderInfo = new ReceiveOrderInfo;
    pReceiveOrderInfo->sCode = QString("201555%1").arg(nOrderId); // 订单号
    pReceiveOrderInfo->nOrderType = e_manualOrder; // 订单类型
    pReceiveOrderInfo->sProviderName = receiveProviderInfo.sName; // 提供商名称
    pReceiveOrderInfo->sProviderCode = receiveProviderInfo.sCode; // 提供商编号
    pReceiveOrderInfo->nNeedReceiveSumNum = c_nNegativeNumber; // 应收件数
    pReceiveOrderInfo->fNeedReceiveSumValue = c_nNegativeNumber; // 应收数量
    pReceiveOrderInfo->nRealReceiveSumNum = 0; // 实收件数
    pReceiveOrderInfo->fRealReceiveSumValue = 0.00f; // 实收数量
    pReceiveOrderInfo->fSumPrice = 0.00f; // 金额
    pReceiveOrderInfo->sUploadDate = uploadDate; // 上传日期
    pReceiveOrderInfo->sUploadTime = uploadTime; // 上传时间
    pReceiveOrderInfo->nRecieveState = e_RecieveOrderNotStart; // 收货状态 (已完成，收货中，未完成)

    ReceiveOrderGoodsInfo* pReceiveOrderGoodsInfo = NULL;
    GoodsForCreateInfo* pGoodsForCreateInfo = NULL;
    int nLen = receiveProviderInfo.goodsForCreateInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        pGoodsForCreateInfo = receiveProviderInfo.goodsForCreateInfoList[i];
        pReceiveOrderGoodsInfo = new ReceiveOrderGoodsInfo;
        pReceiveOrderGoodsInfo->nGoodsId = pGoodsForCreateInfo->nGoodsId; // 商品id
        pReceiveOrderGoodsInfo->sGoodName = pGoodsForCreateInfo->sGoodName; // 商品名称
        pReceiveOrderGoodsInfo->sGoodsCode = pGoodsForCreateInfo->sGoodsCode; // 商品编号
        pReceiveOrderGoodsInfo->sUnitSpecification = pGoodsForCreateInfo->sUnitSpecification; // 规格单位
        pReceiveOrderGoodsInfo->fUnitSpecificationValue = pGoodsForCreateInfo->fUnitSpecificationValue; // 规格单位值
//        pReceiveOrderGoodsInfo->sSpecification = pGoodsForCreateInfo->sSpecification; // 规格
        pReceiveOrderGoodsInfo->nNeedReceiveSumNum = c_nNegativeNumber; // 应收件数
        pReceiveOrderGoodsInfo->fNeedReceiveSumValue = c_nNegativeNumber; // 应收数量
        pReceiveOrderGoodsInfo->nRealReceiveSumNum = 0; // 实收件数
        pReceiveOrderGoodsInfo->fRealReceiveSumValue = 0.00f; // 实收数量
        pReceiveOrderGoodsInfo->fSumPrice = 0.00f; // 收货金额
        pReceiveOrderGoodsInfo->bGoodsRecieveFinish = false; // 收货商品是否保存
        pReceiveOrderGoodsInfo->bStandardGoods = pGoodsForCreateInfo->bStandardGoods;

        if (pReceiveOrderGoodsInfo->bStandardGoods)
        {
            pReceiveOrderGoodsInfo->standardInfo.fStandardWeight = pReceiveOrderGoodsInfo->fUnitSpecificationValue;
            pReceiveOrderGoodsInfo->standardInfo.nReceiveNum = 0;
            pReceiveOrderGoodsInfo->standardInfo.fReciveSumValue = 0.0f;
            pReceiveOrderGoodsInfo->standardInfo.fPrice = 0.0f;
        }
        else
        {
            pReceiveOrderGoodsInfo->noStandardInfo.fAllWeidght = pReceiveOrderGoodsInfo->fUnitSpecificationValue;
            pReceiveOrderGoodsInfo->noStandardInfo.fPeelWeight = 0.0f;
            pReceiveOrderGoodsInfo->noStandardInfo.nReceiveNum = 0;
            pReceiveOrderGoodsInfo->noStandardInfo.fPrice = 0.0f;

            pReceiveOrderGoodsInfo->disperseInfo.fReciveSumValue = 0.0f;
            pReceiveOrderGoodsInfo->disperseInfo.fPrice = 0.0f;
        }

        pReceiveOrderGoodsInfo->nWeighType = e_receiveWeighNull;
        pReceiveOrderInfo->receiveOrderGoodsInfoList.append(pReceiveOrderGoodsInfo);
    }

    m_allOrdersInfoList.append(pReceiveOrderInfo);
    if (pReceiveOrderInfo->nRecieveState == e_RecieveOrderFinish)
    {
        m_finishOrdersInfoList.append(pReceiveOrderInfo);
    }
    else
    {
        m_notFinishOrdersInfoList.append(pReceiveOrderInfo);
    }
    updateClick();

    emit sigCreateOrder(pReceiveOrderInfo);
}
