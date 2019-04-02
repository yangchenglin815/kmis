#include "CheckOrderGoodsWidget.h"
#include "ui_CheckOrderGoodsWidget.h"
#include "../data/enumData.h"
#include <QDebug>

CheckOrderGoodsWidget::CheckOrderGoodsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CheckOrderGoodsWidget)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
    , m_nOrderGoodsSumNumber(0)
    , m_rOrderGoodsSumPrice(0.0)
    , m_bSelectSortByPrice(true)
    , m_bDownSortByPrice(true)
    , m_bDownSortByNumber(true)
{
    ui->setupUi(this);
    init();
    initConnect();
}

CheckOrderGoodsWidget::~CheckOrderGoodsWidget()
{
    delete ui;
}

void CheckOrderGoodsWidget::initData(const QList<OrderCardDetailInfo_s> &orderGoodsInfoList, bool bUploadFinish)
{
    ui->titleWidget->setCheckTitle(bUploadFinish);
    if (bUploadFinish)
    {
        ui->confirmButton->hide();
    }
    else
    {
        ui->confirmButton->show();
    }
    ui->listView->setUploadFinishedFlag(bUploadFinish);

    m_checkOrderGoodsInfoList.clear();
    int nLen = orderGoodsInfoList.length();
    OrderCardDetailInfo_s orderCardDetailInfo_s;
    CheckOrderGoodsInfo checkOrderGoodsInfo;
    m_nOrderGoodsSumNumber = 0;
    m_rOrderGoodsSumPrice = 0;
    for (int i = 0; i < nLen; i++)
    {
        orderCardDetailInfo_s = orderGoodsInfoList[i];
        checkOrderGoodsInfo.nId = orderCardDetailInfo_s.nId; // 商品ID
        checkOrderGoodsInfo.sCode = orderCardDetailInfo_s.sCode; // 商品编码
        checkOrderGoodsInfo.sName = orderCardDetailInfo_s.sName; // 商品名称
        checkOrderGoodsInfo.sShortName = orderCardDetailInfo_s.sShortName; // 商品简称
        checkOrderGoodsInfo.sUnitSpecification = orderCardDetailInfo_s.sUnitSpecification; // 规格单位
        checkOrderGoodsInfo.fUnitSpecificationValue = orderCardDetailInfo_s.fUnitSpecificationValue; // 规格单位量
        checkOrderGoodsInfo.fPrice = orderCardDetailInfo_s.fPrice; // 单件单价
        checkOrderGoodsInfo.nOrderGoodsNumber = orderCardDetailInfo_s.nOrderGoodsNumber; // 要货量
        checkOrderGoodsInfo.nCheckOrderGoodsNumber = orderCardDetailInfo_s.nOrderGoodsNumber; // 审核量
        m_nOrderGoodsSumNumber += checkOrderGoodsInfo.nCheckOrderGoodsNumber;
        m_rOrderGoodsSumPrice += checkOrderGoodsInfo.nCheckOrderGoodsNumber * orderCardDetailInfo_s.fUnitSpecificationValue * checkOrderGoodsInfo.fPrice;

        m_checkOrderGoodsInfoList.append(checkOrderGoodsInfo);
    }
    ui->sumNumberLabel->setText(QString(QStringLiteral("（共%1件）")).arg(m_nOrderGoodsSumNumber));
    ui->sumPriceLabel->setText(QString("￥%1").arg(QString::number(m_rOrderGoodsSumPrice, 'f', 2)));

    m_nCurPage = 1;
    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    slot_downSortByPrice(true);
}

void CheckOrderGoodsWidget::slot_downSortByPrice(bool bDownSort)
{
    m_bDownSortByPrice = bDownSort;
    m_bSelectSortByPrice = true;
    int nLen = m_checkOrderGoodsInfoList.length();
    double fSumPriceCur = 0.0;
    double fSumPriceNext = 0.0;
    for (int i = 0; i < nLen - 1; i++)
    {
        for (int j = 0; j < nLen - 1 - i; j++)
        {
            fSumPriceCur = m_checkOrderGoodsInfoList[j].fPrice * m_checkOrderGoodsInfoList[j].nCheckOrderGoodsNumber;
            fSumPriceNext = m_checkOrderGoodsInfoList[j+1].fPrice * m_checkOrderGoodsInfoList[j+1].nCheckOrderGoodsNumber;
            if ((bDownSort && (fSumPriceCur < fSumPriceNext))
                    || (!bDownSort && (fSumPriceCur > fSumPriceNext)))
            {
                m_checkOrderGoodsInfoList.move(j, j+1);
            }
        }
    }
    generateUI();
}

void CheckOrderGoodsWidget::slot_downSortByNumber(bool bDownSort)
{
    m_bDownSortByNumber = bDownSort;
    m_bSelectSortByPrice = false;
    int nLen = m_checkOrderGoodsInfoList.length();
    int nCurNum = 0;
    int nNextNum = 0;
    for (int i = 0; i < nLen - 1; i++)
    {
        for (int j = 0; j < nLen - 1 - i; j++)
        {
            nCurNum = m_checkOrderGoodsInfoList[j].nCheckOrderGoodsNumber;
            nNextNum = m_checkOrderGoodsInfoList[j+1].nCheckOrderGoodsNumber;
            if ((bDownSort && (nCurNum < nNextNum))
                    || (!bDownSort && (nCurNum > nNextNum)))
            {
                m_checkOrderGoodsInfoList.move(j, j+1);
            }
        }
    }
    generateUI();
}

void CheckOrderGoodsWidget::slot_clickPriceText()
{
    m_bSelectSortByPrice = true;
    slot_downSortByPrice(m_bDownSortByPrice);
}

void CheckOrderGoodsWidget::slot_clickNumberText()
{
    m_bSelectSortByPrice = false;
    slot_downSortByNumber(m_bDownSortByNumber);
}

void CheckOrderGoodsWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void CheckOrderGoodsWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void CheckOrderGoodsWidget::on_confirmButton_clicked()
{
    emit sigOrderNumberChanged(m_changedOrderMap);
}

void CheckOrderGoodsWidget::slot_orderNumberAdded(int nId, int bAddedOrderNum, float fUnitValue, float fPrice)
{
    m_nOrderGoodsSumNumber += bAddedOrderNum;
    m_rOrderGoodsSumPrice += bAddedOrderNum * fUnitValue * fPrice;

    // 修改界面数据
    ui->sumNumberLabel->setText(QString(QStringLiteral("（共%1件）")).arg(m_nOrderGoodsSumNumber));
    QString sSumPrice;
    sSumPrice.sprintf("%.2f", m_rOrderGoodsSumPrice);
    ui->sumPriceLabel->setText(QString(QStringLiteral("￥%1")).arg(sSumPrice));

    // 修改数据
    int nLen = m_checkOrderGoodsInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        CheckOrderGoodsInfo& checkOrderGoodsInfo = m_checkOrderGoodsInfoList[i];
        if (checkOrderGoodsInfo.nId == nId)
        {
            checkOrderGoodsInfo.nCheckOrderGoodsNumber += bAddedOrderNum;
            if (checkOrderGoodsInfo.nCheckOrderGoodsNumber != checkOrderGoodsInfo.nOrderGoodsNumber)
            {
                m_changedOrderMap.insert(checkOrderGoodsInfo.nId, checkOrderGoodsInfo.nCheckOrderGoodsNumber);
            }
            else
            {
                m_changedOrderMap.remove(checkOrderGoodsInfo.nId);
            }
            break;
        }
    }
}

void CheckOrderGoodsWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_checkOrderGoodsInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(m_checkOrderGoodsInfoList[i]);
    }
}

void CheckOrderGoodsWidget::checkCurPageButtonState()
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

void CheckOrderGoodsWidget::init()
{
    ui->sortByPriceWidget->setSortType(e_sortByPrice);
    ui->sortByPriceWidget->setSelectedState();
    ui->sortByNumWidget->setSortType(e_sortByNumber);
    ui->sortByNumWidget->canncleSelectedState();
}

void CheckOrderGoodsWidget::initConnect()
{
    connect(ui->sortByPriceWidget, SIGNAL(sigDownSort(bool)), this, SLOT(slot_downSortByPrice(bool)));
    connect(ui->sortByNumWidget, SIGNAL(sigDownSort(bool)), this, SLOT(slot_downSortByNumber(bool)));
    connect(ui->sortByPriceWidget, SIGNAL(sigClickText()), this, SLOT(slot_clickPriceText()));
    connect(ui->sortByNumWidget, SIGNAL(sigClickText()), this, SLOT(slot_clickNumberText()));

    connect(ui->listView, SIGNAL(sigOrderNumberAdded(int, int, float, float)), this, SLOT(slot_orderNumberAdded(int, int, float, float)));
}
