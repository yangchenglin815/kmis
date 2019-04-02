#include "GoodsSearchForCreateWidget.h"
#include "ui_GoodsSearchForCreateWidget.h"

GoodsSearchForCreateWidget::GoodsSearchForCreateWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GoodsSearchForCreateWidget)
    , m_nOnePageCount(8)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
    initConnect();
}

GoodsSearchForCreateWidget::~GoodsSearchForCreateWidget()
{
    delete ui;
}

void GoodsSearchForCreateWidget::initData(const QList<GoodsForCreateInfo *> &goodsForCreateInfoList)
{
    ui->listView->setHaveDeleteButtonFlag(false);

    m_goodsForCreateInfoList = goodsForCreateInfoList;
    m_nCurPage = 1;
    int nCount = m_goodsForCreateInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void GoodsSearchForCreateWidget::appendOneInfo(GoodsForCreateInfo *pGoodsForCreateInfo)
{
    m_goodsForCreateInfoList.append(pGoodsForCreateInfo);

    int nCount = m_goodsForCreateInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    m_nCurPage = m_nTotalPage;
    checkCurPageButtonState();
    generateUI();
}

void GoodsSearchForCreateWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void GoodsSearchForCreateWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void GoodsSearchForCreateWidget::slot_clickSearchItem(int nGoodsId)
{
    removeOneInfo(nGoodsId);
    emit sigClickSearchItem(nGoodsId);
}

void GoodsSearchForCreateWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_goodsForCreateInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(*(m_goodsForCreateInfoList[i]));
    }
}

void GoodsSearchForCreateWidget::checkCurPageButtonState()
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

void GoodsSearchForCreateWidget::removeOneInfo(int nGoodsId)
{
    int nLen = m_goodsForCreateInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_goodsForCreateInfoList[i]->nGoodsId == nGoodsId)
        {
            m_goodsForCreateInfoList.removeAt(i);
            break;
        }
    }
    checkCurPageButtonState();
    generateUI();
}

void GoodsSearchForCreateWidget::initConnect()
{
    connect(ui->searchEdit, SIGNAL(sigSearchChanged(QString)), this, SIGNAL(sigSearchChanged(QString)));
    connect(ui->listView, SIGNAL(sigClickSearchItem(int)), this, SLOT(slot_clickSearchItem(int)));
}
