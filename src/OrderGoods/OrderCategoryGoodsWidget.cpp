#include "OrderCategoryGoodsWidget.h"
#include "ui_OrderCategoryGoodsWidget.h"

static const QString c_sReturnButtonText = QStringLiteral("返回");
static const QString c_sOrderGoodsButtonText = QStringLiteral("生成要货卡");

OrderCategoryGoodsWidget::OrderCategoryGoodsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OrderCategoryGoodsWidget)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
    , m_nOrderGoodsSumNumber(0)
    , m_fOrderGoodsSumPrice(0.0)
{
    ui->setupUi(this);
    initConnect();
}

OrderCategoryGoodsWidget::~OrderCategoryGoodsWidget()
{
    delete ui;
}

void OrderCategoryGoodsWidget::initData(const QList<OrderGoodsInfo*> &orderGoodsInfoList)
{
    m_orderGoodsInfoList = orderGoodsInfoList;
    m_nCurPage = 1;
    int nCount = m_orderGoodsInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    slot_sortSecondCol(true);
}

void OrderCategoryGoodsWidget::setConfirmButtonText(bool bReturnButton)
{
    if (bReturnButton)
    {
        ui->confirmButton->setText(c_sReturnButtonText);
    }
    else
    {
        ui->confirmButton->setText(c_sOrderGoodsButtonText);
    }
}

void OrderCategoryGoodsWidget::findGoodsPage(int nGoodsId)
{
    int nLen = m_orderGoodsInfoList.length();
    OrderGoodsInfo* pOrderGoodsInfo = NULL;
    for (int i = 0; i < nLen; i++)
    {
        pOrderGoodsInfo = m_orderGoodsInfoList[i];
        if (pOrderGoodsInfo->nId == nGoodsId)
        {
            m_nCurPage = ((i + 1) / m_nOnePageCount) + (((i + 1) % m_nOnePageCount == 0) ? 0 : 1);
            generateUI();
            return;
        }
    }
}

void OrderCategoryGoodsWidget::clearChooseGoods()
{
    m_nOrderGoodsSumNumber = 0;
    m_fOrderGoodsSumPrice = 0.0f;

    // 修改界面数据
    ui->sumNumberLabel->setText(QString(QStringLiteral("（共%1件）")).arg(m_nOrderGoodsSumNumber));
    ui->sumPriceLabel->setText(QString("￥%1").arg(QString::number(m_fOrderGoodsSumPrice, 'f', 2)));
    m_chooseGoodsInfoMap.clear();
    emit sigOrderGoodsChanged();
    checkCurPageButtonState();
    generateUI();
}

void OrderCategoryGoodsWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void OrderCategoryGoodsWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void OrderCategoryGoodsWidget::on_confirmButton_clicked()
{
    if (ui->confirmButton->text() == c_sReturnButtonText)
    {
        setConfirmButtonText(false);
        OrderGoodsInfo *pOrderGoodsInfo = getFirstSearchOrderGoods();
        if (pOrderGoodsInfo != NULL)
        {
           emit sigClickReturn(pOrderGoodsInfo->nId, pOrderGoodsInfo->nBelongCategoryBigId, pOrderGoodsInfo->nBelongCategorySmallId);
        }
    }
    else
    {
        emit sigCreateOrderCard(m_chooseGoodsInfoMap.values());
    }
}

void OrderCategoryGoodsWidget::slot_orderNumberAdded(int nId, int bAddedOrderNum, float fUnitValue, float fPrice)
{
    m_nOrderGoodsSumNumber += bAddedOrderNum;
    m_fOrderGoodsSumPrice += bAddedOrderNum * fUnitValue * fPrice;

    // 修改界面数据
    ui->sumNumberLabel->setText(QString(QStringLiteral("（共%1件）")).arg(m_nOrderGoodsSumNumber));
    ui->sumPriceLabel->setText(QString("￥%1").arg(QString::number(m_fOrderGoodsSumPrice, 'f', 2)));

    // 修改数据
    OrderGoodsInfo* pOrderGoodsInfo = NULL;
    int nLen = m_orderGoodsInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_orderGoodsInfoList[i]->nId == nId)
        {
            pOrderGoodsInfo = m_orderGoodsInfoList[i];
            int nOldNumber = pOrderGoodsInfo->nOrderGoodsNumber;
            pOrderGoodsInfo->nOrderGoodsNumber += bAddedOrderNum;
            if (ui->confirmButton->text() == c_sReturnButtonText)
            {
                return;
            }
            else
            {
                bool bAdded = (nOldNumber == 0 && (m_orderGoodsInfoList[i]->nOrderGoodsNumber !=0));
                bool bDelete = (nOldNumber != 0 && (m_orderGoodsInfoList[i]->nOrderGoodsNumber == 0));
                if (bAdded || bDelete)
                {
                    emit sigOrderGoodsChanged();
                    if (bAdded)
                    {
                        m_chooseGoodsInfoMap.insert(pOrderGoodsInfo->nId, pOrderGoodsInfo);
                    }
                    else
                    {
                        m_chooseGoodsInfoMap.remove(pOrderGoodsInfo->nId);
                    }
                }
            }
            break;
        }
    }
}

void OrderCategoryGoodsWidget::slot_sortSecondCol(bool bDownSort)
{
    int nLen = m_orderGoodsInfoList.length();
    int nCurValue = 0;
    int nNextVale = 0;
    for (int i = 0; i < nLen - 1; i++)
    {
        for (int j = 0; j < nLen - 1 - i; j++)
        {
            nCurValue = m_orderGoodsInfoList[j]->nSaleNumberToday;
            nNextVale = m_orderGoodsInfoList[j+1]->nSaleNumberToday;
            if ((bDownSort && (nCurValue < nNextVale))
                    || (!bDownSort && (nCurValue > nNextVale)))
            {
                m_orderGoodsInfoList.move(j, j+1);
            }
        }
    }
    generateUI();
}

void OrderCategoryGoodsWidget::slot_sortThirdCol(bool bDownSort)
{
    int nLen = m_orderGoodsInfoList.length();
    int nCurValue = 0;
    int nNextVale = 0;
    for (int i = 0; i < nLen - 1; i++)
    {
        for (int j = 0; j < nLen - 1 - i; j++)
        {
            nCurValue = m_orderGoodsInfoList[j]->nOrderSaleRate;
            nNextVale = m_orderGoodsInfoList[j+1]->nOrderSaleRate;
            if ((bDownSort && (nCurValue < nNextVale))
                    || (!bDownSort && (nCurValue > nNextVale)))
            {
                m_orderGoodsInfoList.move(j, j+1);
            }
        }
    }
    generateUI();
}

void OrderCategoryGoodsWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_orderGoodsInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(*(m_orderGoodsInfoList[i]));
    }
}

void OrderCategoryGoodsWidget::checkCurPageButtonState()
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

void OrderCategoryGoodsWidget::initConnect()
{
   connect(ui->titleWidget, SIGNAL(sigSortSecondCol(bool)), this, SLOT(slot_sortSecondCol(bool)));
   connect(ui->titleWidget, SIGNAL(sigSortThirdCol(bool)), this, SLOT(slot_sortThirdCol(bool)));
   connect(ui->listView, SIGNAL(sigOrderNumberAdded(int, int, float, float)), this, SLOT(slot_orderNumberAdded(int, int, float, float)));
}

OrderGoodsInfo *OrderCategoryGoodsWidget::getFirstSearchOrderGoods()
{
    int nLen = m_orderGoodsInfoList.length();
    OrderGoodsInfo* pOrderGoodsInfo = NULL;
    for (int i = 0; i < nLen; i++)
    {
        pOrderGoodsInfo = m_orderGoodsInfoList[i];
        if (pOrderGoodsInfo->nOrderGoodsNumber > 0)
        {
            return pOrderGoodsInfo;
        }
    }
    return pOrderGoodsInfo;
}
