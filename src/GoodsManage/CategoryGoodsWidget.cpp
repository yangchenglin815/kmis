#include "CategoryGoodsWidget.h"
#include "ui_CategoryGoodsWidget.h"

CategoryGoodsWidget::CategoryGoodsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CategoryGoodsWidget)
  , m_nOnePageCount(7)
  , m_nTotalPage(1)
  , m_nCurPage(1)
{
    ui->setupUi(this);
    initConnect();
//    QList<sGoodsInfo*> infoList;
//    sGoodsInfo *info = NULL;
//    for(int i=0;i<10;i++){
//        info = new sGoodsInfo;
//        info->nId = i+1;
//        info->sName = "胖头三文鱼";
//        info->sCode = "0100001";
//        info->fPrice = 20.99;
//        info->vPrice = 20.99;
//        info->category = 1;
//        info->sStockNumber = "10000.00";
//        info->sUnitSpecification = "公斤";
//        info->sCodeId = "201612060001";
//        infoList.append(info);
//    }
//    initData(infoList);
}

CategoryGoodsWidget::~CategoryGoodsWidget()
{
    delete ui;
}

void CategoryGoodsWidget::initData(const QList<sGoodsInfo *> &sGoodsInfoList)
{
    m_GoodsInfoList = sGoodsInfoList;
    m_nCurPage = 1;
    int nCount = m_GoodsInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void CategoryGoodsWidget::findGoodsPage(int nGoodsId)
{
    int nLen = m_GoodsInfoList.length();
   sGoodsInfo* pGoodsInfo = NULL;
    for (int i = 0; i < nLen; i++)
    {
        pGoodsInfo = m_GoodsInfoList[i];
        if (pGoodsInfo->nId == nGoodsId)
        {
            m_nCurPage = ((i + 1) / m_nOnePageCount) + (((i + 1) % m_nOnePageCount == 0) ? 0 : 1);
            generateUI();
            return;
        }
    }
}

void CategoryGoodsWidget::slot_lastPage()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void CategoryGoodsWidget::slot_nextPage()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void CategoryGoodsWidget::slot_confirmPage()
{
   emit sigFastCreateDocument();
}

void CategoryGoodsWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_GoodsInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        m_GoodsInfoList[i]->id = i+1;
        ui->listView->appendItem(*(m_GoodsInfoList[i]));
    }
}

void CategoryGoodsWidget::checkCurPageButtonState()
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

void CategoryGoodsWidget::initConnect()
{
   connect(ui->lastPageButton, SIGNAL(clicked()), this, SLOT(slot_lastPage()));
   connect(ui->nextPageButton, SIGNAL(clicked()), this, SLOT(slot_nextPage()));
   connect(ui->confirmButton, SIGNAL(clicked()), this, SLOT(slot_confirmPage()));
}

sGoodsInfo *CategoryGoodsWidget::getFirstSearchOrderGoods()
{
//    int nLen = m_GoodsInfoList.length();
//    sGoodsInfo* pGoodsInfo = NULL;
//    for (int i = 0; i < nLen; i++)
//    {
//        pGoodsInfo = m_GoodsInfoList[i];
//        if (pGoodsInfo->nGoodsNumber > 0)
//        {
//            return pGoodsInfo;
//        }
//    }
//    return pGoodsInfo;
}
