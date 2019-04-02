#include "ReceiveGoodsForCreateWidget.h"
#include "ui_ReceiveGoodsForCreateWidget.h"

ReceiveGoodsForCreateWidget::ReceiveGoodsForCreateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReceiveGoodsForCreateWidget)
{
    ui->setupUi(this);
    initConnect();
}

ReceiveGoodsForCreateWidget::~ReceiveGoodsForCreateWidget()
{
    delete ui;
}

void ReceiveGoodsForCreateWidget::initData(const QList<GoodsForCreateInfo *> &goodsForCreateInfoList)
{
    m_goodsForSearchList = goodsForCreateInfoList;
    ui->goodsSearchForCreateWidget->initData(goodsForCreateInfoList);
    ui->goodsSelectForCreateWidget->clearData();
}

void ReceiveGoodsForCreateWidget::slot_searchChanged(QString searchText)
{
    if (!searchText.isEmpty())
    {
        int nLen = m_goodsForSearchList.length();
        GoodsForCreateInfo* pGoodsForCreateInfo = NULL;
        QList<GoodsForCreateInfo*> searchList;
        for (int i = 0; i < nLen; i++)
        {
            pGoodsForCreateInfo = m_goodsForSearchList[i];
            if (pGoodsForCreateInfo->sGoodName.contains(searchText)
                    || pGoodsForCreateInfo->sGoodsCode.contains(searchText))
            {
                searchList.append(pGoodsForCreateInfo);
            }
        }
        ui->goodsSearchForCreateWidget->initData(searchList);
    }
    else
    {
        ui->goodsSearchForCreateWidget->initData(m_goodsForSearchList);
    }
}

void ReceiveGoodsForCreateWidget::slot_clickSearchItem(int nGoodsId)
{
    int nLen = m_goodsForSearchList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_goodsForSearchList[i]->nGoodsId == nGoodsId)
        {
            ui->goodsSelectForCreateWidget->appendOneInfo(m_goodsForSearchList[i]);
            m_goodsSelectedList.append(m_goodsForSearchList[i]);
            m_goodsForSearchList.removeAt(i);
            break;
        }
    }
}

void ReceiveGoodsForCreateWidget::slot_delSelectItem(int nGoodsId)
{
    int nLen = m_goodsSelectedList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_goodsSelectedList[i]->nGoodsId == nGoodsId)
        {
            ui->goodsSearchForCreateWidget->appendOneInfo(m_goodsSelectedList[i]);
            m_goodsForSearchList.append(m_goodsSelectedList[i]);
            m_goodsSelectedList.removeAt(i);
            break;
        }
    }
}

void ReceiveGoodsForCreateWidget::slot_confirmCreateOrder()
{
    emit sigConfirmCreateOrder(m_goodsSelectedList);
}

void ReceiveGoodsForCreateWidget::initConnect()
{
    connect(ui->goodsSelectForCreateWidget, SIGNAL(sigLastStep()), this, SIGNAL(sigLastStep()));
    connect(ui->goodsSelectForCreateWidget, SIGNAL(sigDelSelectItem(int)), this, SLOT(slot_delSelectItem(int)));
    connect(ui->goodsSelectForCreateWidget, SIGNAL(sigConfirmCreateOrder()), this, SLOT(slot_confirmCreateOrder()));
    connect(ui->goodsSearchForCreateWidget, SIGNAL(sigSearchChanged(QString)),
            this, SLOT(slot_searchChanged(QString)));
    connect(ui->goodsSearchForCreateWidget, SIGNAL(sigClickSearchItem(int)), this, SLOT(slot_clickSearchItem(int)));
}
