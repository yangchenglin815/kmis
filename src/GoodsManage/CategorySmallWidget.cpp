#include "CategorySmallWidget.h"
#include "ui_CategorySmallWidget.h"

CategorySmallWidget::CategorySmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CategorySmallWidget)
  , m_nOnePageCount(11)
  , m_nTotalPage(1)
  , m_nCurPage(1)
{
    ui->setupUi(this);
    initConnect();
}

CategorySmallWidget::~CategorySmallWidget()
{
    delete ui;
}

void CategorySmallWidget::initData(const QList<sCategorySmallInfo *> &categorySmallInfoList, int nDefaultSelectedId)
{
    m_categorySmallInfoList = categorySmallInfoList;

    m_rootCategorySmallInfo.sName = QStringLiteral("全部");
    m_rootCategorySmallInfo.nNumber = countRootSelectNumber();
    m_rootCategorySmallInfo.nId = c_nNegativeNumber;
    m_rootCategorySmallInfo.sGoodsInfoList.clear();

    m_nCurPage = 1;
    int nCount = m_categorySmallInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    ui->listView->setDefaultSelectedCategoryId(nDefaultSelectedId);
    emit sigClickCategorySmall(nDefaultSelectedId);
    checkCurPageButtonState();
    generateUI();
}

void CategorySmallWidget::slot_clickCategorySmall(int categorySmallId)
{
    m_nCurCategorySmallId = categorySmallId;
    emit sigClickCategorySmall(categorySmallId);
}

void CategorySmallWidget::slot_lastPage()
{
    m_nCurPage--;
    if (m_nCurPage > m_nTotalPage || m_nCurPage < 0)
    {
        m_nCurPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void CategorySmallWidget::slot_nextPage()
{
    m_nCurPage++;
    if (m_nCurPage > m_nTotalPage || m_nCurPage < 0)
    {
        m_nCurPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void CategorySmallWidget::checkCurPageButtonState()
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

void CategorySmallWidget::generateUI()
{
    ui->listView->clearItems();
    ui->listView->appendItem(m_rootCategorySmallInfo);

    int nCount = m_categorySmallInfoList.length();
    if (!(nCount == 1 && m_categorySmallInfoList[0]->bFakeSmallCategory))
    {
        int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
        int nEndPos = m_nCurPage * m_nOnePageCount;
        for (int i = nStartPos; i < nEndPos && i < nCount; i++)
        {
            ui->listView->appendItem(*(m_categorySmallInfoList[i]));
        }
    }
}

void CategorySmallWidget::initConnect()
{
   connect(ui->listView, SIGNAL(sigClickCategorySmall(int)), this, SLOT(slot_clickCategorySmall(int)));
   connect(ui->lastPageButton, SIGNAL(clicked()), this, SLOT(slot_lastPage()));
   connect(ui->nextPageButton, SIGNAL(clicked()), this, SLOT(slot_nextPage()));
}

int CategorySmallWidget::countRootSelectNumber()
{
    int nNumber = 0;
    int nLen = m_categorySmallInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        nNumber += m_categorySmallInfoList[i]->nNumber;
    }
    return nNumber;
}
