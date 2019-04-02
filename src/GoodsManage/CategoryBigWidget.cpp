#include "CategoryBigWidget.h"
#include "ui_CategoryBigWidget.h"

CategoryBigWidget::CategoryBigWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CategoryBigWidget)
  , m_nOnePageCount(7)
  , m_nTotalPage(1)
  , m_nCurPage(1)
  , m_nSelectedBigCategoryId(-1)
{
    ui->setupUi(this);
    initConnect();
}

CategoryBigWidget::~CategoryBigWidget()
{
    delete ui;
}

void CategoryBigWidget::initData(const QList<sCategoryBigInfo *> &categoryBigInfoList)
{
    m_categoryBigInfoList = categoryBigInfoList;
    m_nCurPage = 1;
    int nCount = m_categoryBigInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (nCount == 0)
    {
        ui->listView->clearItems();
        return;
    }

    if (m_nSelectedBigCategoryId < 0)
    {
        m_nSelectedBigCategoryId = m_categoryBigInfoList[0]->nId;
    }
    ui->listView->setDefaultSelectedCategoryId(m_nSelectedBigCategoryId);
    checkCurPageButtonState();
    generateUI();
    emit sigClickCategoryBig(m_nSelectedBigCategoryId);
}

void CategoryBigWidget::clickCategoryBigId(int nCategoryId)
{
    m_nSelectedBigCategoryId = nCategoryId;
    ui->listView->setDefaultSelectedCategoryId(nCategoryId);
    generateUI();
}

void CategoryBigWidget::slot_clickCategoryBig(int nCategoryId)
{
    m_nSelectedBigCategoryId = nCategoryId;
    emit sigClickCategoryBig(nCategoryId);
}

void CategoryBigWidget::generateUI()
{
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_categoryBigInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        if ((i == (nEndPos - 1)) || (i == (nCount - 1)))
        {
            m_categoryBigInfoList[i]->bDrawLine = false;
        }
        else
        {
            m_categoryBigInfoList[i]->bDrawLine = true;
        }
        ui->listView->appendItem(*(m_categoryBigInfoList[i]));
    }
}

void CategoryBigWidget::checkCurPageButtonState()
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

void CategoryBigWidget::initConnect()
{
    connect(ui->listView, SIGNAL(sigClickCategoryBig(int)), this, SLOT(slot_clickCategoryBig(int)));
}

void CategoryBigWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    if (m_nCurPage > m_nTotalPage || m_nCurPage < 0)
    {
        m_nCurPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void CategoryBigWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    if (m_nCurPage > m_nTotalPage || m_nCurPage < 0)
    {
        m_nCurPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}
