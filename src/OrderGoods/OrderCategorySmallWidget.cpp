#include "OrderCategorySmallWidget.h"
#include "ui_OrderCategorySmallWidget.h"

OrderCategorySmallWidget::OrderCategorySmallWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OrderCategorySmallWidget)
    , m_nOnePageCount(11)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
    initConnect();
}

OrderCategorySmallWidget::~OrderCategorySmallWidget()
{
    delete ui;
}

void OrderCategorySmallWidget::initData(const QList<OrderCategorySmallInfo *> &orderCategorySmallInfoList, int nDefaultSelectedId)
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

void OrderCategorySmallWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    if (m_nCurPage > m_nTotalPage || m_nCurPage < 0)
    {
        m_nCurPage = 1;
    }
    generateUI();
}

void OrderCategorySmallWidget::slot_clickCategorySmall(int categorySmallId)
{
    m_nCurCategorySmallId = categorySmallId;
    emit sigClickCategorySmall(categorySmallId);
}

void OrderCategorySmallWidget::generateUI()
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

void OrderCategorySmallWidget::initConnect()
{
    connect(ui->listView, SIGNAL(sigClickCategorySmall(int)), this, SLOT(slot_clickCategorySmall(int)));
}

int OrderCategorySmallWidget::countRootSelectNumber()
{
    int nNumber = 0;
    int nLen = m_orderCategorySmallInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        nNumber += m_orderCategorySmallInfoList[i]->nNumber;
    }
    return nNumber;
}


