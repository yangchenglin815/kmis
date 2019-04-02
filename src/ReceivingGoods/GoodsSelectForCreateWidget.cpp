#include "GoodsSelectForCreateWidget.h"
#include "ui_GoodsSelectForCreateWidget.h"

GoodsSelectForCreateWidget::GoodsSelectForCreateWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GoodsSelectForCreateWidget)
    , m_nOnePageCount(8)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
    initConnect();
}

GoodsSelectForCreateWidget::~GoodsSelectForCreateWidget()
{
    delete ui;
}

void GoodsSelectForCreateWidget::appendOneInfo(GoodsForCreateInfo *pGoodsForCreateInfo)
{
    ui->listView->setHaveDeleteButtonFlag(true);

    int nLen = m_goodsForCreateInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_goodsForCreateInfoList[i]->nGoodsId == pGoodsForCreateInfo->nGoodsId)
        {
            m_goodsForCreateInfoList.removeAt(i);
            break;
        }
    }

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

void GoodsSelectForCreateWidget::clearData()
{
    m_goodsForCreateInfoList.clear();
    m_nTotalPage = 1;
    m_nCurPage = 1;
    checkCurPageButtonState();
    generateUI();
}

void GoodsSelectForCreateWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void GoodsSelectForCreateWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void GoodsSelectForCreateWidget::on_lastStepButton_clicked()
{
    emit sigLastStep();
}

void GoodsSelectForCreateWidget::on_confirmButton_clicked()
{
    emit sigConfirmCreateOrder();
}

void GoodsSelectForCreateWidget::slot_delSelectItem(int nGoodId)
{
    removeOneInfo(nGoodId);
    emit sigDelSelectItem(nGoodId);
}

void GoodsSelectForCreateWidget::generateUI()
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

void GoodsSelectForCreateWidget::checkCurPageButtonState()
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

void GoodsSelectForCreateWidget::initConnect()
{
    connect(ui->listView, SIGNAL(sigDeleteItem(int)), this, SLOT(slot_delSelectItem(int)));
}

void GoodsSelectForCreateWidget::removeOneInfo(int nGoodsId)
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
