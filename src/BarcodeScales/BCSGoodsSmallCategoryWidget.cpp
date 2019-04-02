#include "BCSGoodsSmallCategoryWidget.h"
#include "ui_BCSGoodsSmallCategoryWidget.h"

BCSGoodsSmallCategoryWidget::BCSGoodsSmallCategoryWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BCSGoodsSmallCategoryWidget)
    , m_nOnePageCount(10)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
    initConnect();
}

BCSGoodsSmallCategoryWidget::~BCSGoodsSmallCategoryWidget()
{
    delete ui;
}

void BCSGoodsSmallCategoryWidget::initData(const QList<OrderCategorySmallInfo *> &orderCategorySmallInfoList, int nDefaultSelectedId)
{
    m_orderCategorySmallInfoList = orderCategorySmallInfoList;

    m_rootOrderCategorySmallInfo.sName = QStringLiteral("全部");
    m_rootOrderCategorySmallInfo.nNumber = countRootSelectNumber();
    m_rootOrderCategorySmallInfo.nId = c_nNegativeNumber;
    m_rootOrderCategorySmallInfo.orderGoodsInfoList.clear();

    m_nCurPage = 1;
    int nCount = m_orderCategorySmallInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }

    ui->listView->setDefaultSelectedCategoryId(nDefaultSelectedId);
    emit sigClickCategorySmall(nDefaultSelectedId);
    generateUI();
}

void BCSGoodsSmallCategoryWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void BCSGoodsSmallCategoryWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void BCSGoodsSmallCategoryWidget::slot_clickCategorySmall(int categorySmallId)
{
    m_nCurCategorySmallId = categorySmallId;
    emit sigClickCategorySmall(categorySmallId);
}

void BCSGoodsSmallCategoryWidget::generateUI()
{
    ui->listView->clearItems();
    ui->listView->appendItem(m_rootOrderCategorySmallInfo);

    int nCount = m_orderCategorySmallInfoList.length();
    if (!(nCount == 1 && m_orderCategorySmallInfoList[0]->bFakeSmallCategory))
    {
        int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
        int nEndPos = m_nCurPage * m_nOnePageCount;
        for (int i = nStartPos; i < nEndPos && i < nCount; i++)
        {
            ui->listView->appendItem(*(m_orderCategorySmallInfoList[i]));
        }
    }
}

void BCSGoodsSmallCategoryWidget::checkCurPageButtonState()
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

void BCSGoodsSmallCategoryWidget::initConnect()
{
    connect(ui->listView, SIGNAL(sigClickCategorySmall(int)), this, SLOT(slot_clickCategorySmall(int)));
}

int BCSGoodsSmallCategoryWidget::countRootSelectNumber()
{
    int nNumber = 0;
    int nLen = m_orderCategorySmallInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        nNumber += m_orderCategorySmallInfoList[i]->nNumber;
    }
    return nNumber;
}
