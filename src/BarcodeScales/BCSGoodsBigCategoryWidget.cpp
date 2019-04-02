#include "BCSGoodsBigCategoryWidget.h"
#include "ui_BCSGoodsBigCategoryWidget.h"

BCSGoodsBigCategoryWidget::BCSGoodsBigCategoryWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BCSGoodsBigCategoryWidget)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
    , m_nSelectedBigCategoryId(-1)
{
    ui->setupUi(this);
    initConnect();
}

BCSGoodsBigCategoryWidget::~BCSGoodsBigCategoryWidget()
{
    delete ui;
}

void BCSGoodsBigCategoryWidget::initData(const QList<OrderCategoryBigInfo *> &categoryBigInfoList)
{
    m_infoList = categoryBigInfoList;
    m_nCurPage = 1;
    int nCount = m_infoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (nCount == 0)
    {
        ui->listView->clearItems();
        return;
    }

    if (m_nSelectedBigCategoryId < 0)
    {
        m_nSelectedBigCategoryId = m_infoList[0]->nId;
    }
    ui->listView->setDefaultSelectedCategoryId(m_nSelectedBigCategoryId);
    generateUI();
    emit sigClickCategoryBig(m_nSelectedBigCategoryId);
}

void BCSGoodsBigCategoryWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void BCSGoodsBigCategoryWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void BCSGoodsBigCategoryWidget::slot_clickCategoryBig(int nCategoryId)
{
    m_nSelectedBigCategoryId = nCategoryId;
    emit sigClickCategoryBig(nCategoryId);
}

void BCSGoodsBigCategoryWidget::generateUI()
{
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_infoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        if ((i == (nEndPos - 1)) || (i == (nCount - 1)))
        {
            m_infoList[i]->bDrawLine = false;
        }
        else
        {
            m_infoList[i]->bDrawLine = true;
        }
        ui->listView->appendItem(*(m_infoList[i]));
    }
}

void BCSGoodsBigCategoryWidget::checkCurPageButtonState()
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

void BCSGoodsBigCategoryWidget::initConnect()
{
    connect(ui->listView, SIGNAL(sigClickCategoryBig(int)), this, SLOT(slot_clickCategoryBig(int)));
}
