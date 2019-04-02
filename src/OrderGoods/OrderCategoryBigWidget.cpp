#include "OrderCategoryBigWidget.h"
#include "ui_OrderCategoryBigWidget.h"

OrderCategoryBigWidget::OrderCategoryBigWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OrderCategoryBigWidget)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
    , m_nSelectedBigCategoryId(-1)
{
    ui->setupUi(this);
    initConnect();
//    test();
}

OrderCategoryBigWidget::~OrderCategoryBigWidget()
{
    delete ui;
}

void OrderCategoryBigWidget::initData(const QList<OrderCategoryBigInfo*> &orderCategoryBigInfoList)
{
    m_orderCategoryBigInfoList = orderCategoryBigInfoList;
    m_nCurPage = 1;
    int nCount = m_orderCategoryBigInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (nCount == 0)
    {
        ui->listView->clearItems();
        return;
    }

    if (m_nSelectedBigCategoryId < 0)
    {
        m_nSelectedBigCategoryId = m_orderCategoryBigInfoList[0]->nId;
    }
    ui->listView->setDefaultSelectedCategoryId(m_nSelectedBigCategoryId);
    generateUI();
    emit sigClickCategoryBig(m_nSelectedBigCategoryId);
}

void OrderCategoryBigWidget::clickCategoryBigId(int nCategoryId)
{
    m_nSelectedBigCategoryId = nCategoryId;
    ui->listView->setDefaultSelectedCategoryId(nCategoryId);
    generateUI();
}

void OrderCategoryBigWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    if (m_nCurPage > m_nTotalPage || m_nCurPage < 0)
    {
        m_nCurPage = 1;
    }
    generateUI();
}

void OrderCategoryBigWidget::slot_clickCategoryBig(int nCategoryId)
{
    m_nSelectedBigCategoryId = nCategoryId;
    emit sigClickCategoryBig(nCategoryId);
}

void OrderCategoryBigWidget::generateUI()
{
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_orderCategoryBigInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        if ((i == (nEndPos - 1)) || (i == (nCount - 1)))
        {
            m_orderCategoryBigInfoList[i]->bDrawLine = false;
        }
        else
        {
            m_orderCategoryBigInfoList[i]->bDrawLine = true;
        }
        ui->listView->appendItem(*(m_orderCategoryBigInfoList[i]));
    }
}

void OrderCategoryBigWidget::initConnect()
{
    connect(ui->listView, SIGNAL(sigClickCategoryBig(int)), this, SLOT(slot_clickCategoryBig(int)));
}
