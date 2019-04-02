#include "AdjustPriceCategoryWidget.h"
#include "ui_AdjustPriceCategoryWidget.h"
#include "../data/constData.h"
#include <QDebug>

AdjustPriceCategoryWidget::AdjustPriceCategoryWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdjustPriceCategoryWidget)
    , m_nCurPage(1)
    , m_nTotalPage(1)
    , m_nOnePageCount(10)
    , m_pUpPageButton(NULL)
    , m_pDownPageButton(NULL)
{
    ui->setupUi(this);
    initConnect();
}

AdjustPriceCategoryWidget::~AdjustPriceCategoryWidget()
{
    delete ui;
}

void AdjustPriceCategoryWidget::setUpDownPageButton(QPushButton *pUpPageButton, QPushButton *pDownPageButton)
{
    m_pUpPageButton = pUpPageButton;
    m_pDownPageButton = pDownPageButton;
    connect(m_pUpPageButton, SIGNAL(clicked()), this, SLOT(slot_upPage()));
    connect(m_pDownPageButton, SIGNAL(clicked()), this, SLOT(slot_downPage()));
}

void AdjustPriceCategoryWidget::initData(QList<CategoryInfo *> categoryInfoList)
{
    m_categoryInfoList = categoryInfoList;

    m_nCurPage = 1;
    int nCount = m_categoryInfoList.size();
    m_nTotalPage = nCount/m_nOnePageCount + ((nCount%m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
    ui->listView->clickSelectKeyId();
}

void AdjustPriceCategoryWidget::searchGoods(QList<GoodsInfo> &goodsInfoList, QString searchText)
{
    int nLen = m_categoryInfoList.length();
    int nLen2 = 0;
    QList<GoodsInfo> tempGoodsInfoList;
    GoodsInfo goodsInfo;
    for (int i = 0; i < nLen; i++)
    {
        if (m_categoryInfoList[i]->bCustom)
        {
            continue;
        }
        tempGoodsInfoList = m_categoryInfoList[i]->listGoodsInfo;
        nLen2 = tempGoodsInfoList.length();
        for (int j = 0; j < nLen2; j++)
        {
            goodsInfo = tempGoodsInfoList[j];
            if ((goodsInfo.sCode == searchText)
                    || (goodsInfo.sBarCode == searchText)
                    || goodsInfo.sName.contains(searchText)
                    || goodsInfo.sShortName.contains(searchText)
                    || goodsInfo.sPinYinName.contains(searchText)
                    || goodsInfo.sWuBiName.contains(searchText))
            {
                goodsInfoList.append(goodsInfo);
            }
        }
    }
}

void AdjustPriceCategoryWidget::searchGood(GoodsInfo &info,int goodsId)
{//获取商品信息
    int nLen = m_categoryInfoList.length();
    int nLen2 = 0;
    QList<GoodsInfo> tempGoodsInfoList;
    for (int i = 0; i < nLen; i++)
    {
        if (m_categoryInfoList[i]->bCustom)
        {
            continue;
        }
        tempGoodsInfoList = m_categoryInfoList[i]->listGoodsInfo;
        nLen2 = tempGoodsInfoList.length();
        for (int j = 0; j < nLen2; j++)
        {
            info = tempGoodsInfoList[j];
            if (info.nId == goodsId)
            {
                return ;
            }
        }
    }

}

void AdjustPriceCategoryWidget::slot_upPage()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void AdjustPriceCategoryWidget::slot_downPage()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void AdjustPriceCategoryWidget::resizeEvent(QResizeEvent *)
{
        int width = this->width();
        int height = this->height();

        int widthNum = width/80;

        if(widthNum > 6)
        {
            widthNum = 6;
        }

        m_nOnePageCount = widthNum * 2;
        int newItemWidth = width/widthNum;
        ui->listView->setWidth(newItemWidth);
        int newItemHeight =height/2;
        ui->listView->setHeight(newItemHeight);

        generateUI();
}

void AdjustPriceCategoryWidget::generateUI()
{
    if (m_pDownPageButton == NULL)
    {
        return;
    }
    m_pDownPageButton->setText(QString("%1/%2页").arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_categoryInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(*(m_categoryInfoList[i]));
    }

    int nLen = nEndPos - nCount;
    for (int i = 0; i < nLen; i++)
    {
        CategoryInfo categoryInfo;
        categoryInfo.nId = c_nNegativeNumber - i;
        categoryInfo.sKeyId = QString("2+%1").arg(categoryInfo.nId);
        ui->listView->appendItem(categoryInfo);
    }
}

void AdjustPriceCategoryWidget::checkCurPageButtonState()
{
    if ((m_pUpPageButton == NULL) || (m_pDownPageButton == NULL))
    {
        return;
    }

    if (m_nCurPage <= 1)
    {
        m_nCurPage = 1;
        m_pUpPageButton->setEnabled(false);
    }
    else
    {
        m_pUpPageButton->setEnabled(true);
    }

    if (m_nCurPage < m_nTotalPage)
    {
        m_pDownPageButton->setEnabled(true);
    }
    else
    {
        m_nCurPage = m_nTotalPage;
        m_pDownPageButton->setEnabled(false);
    }
}

void AdjustPriceCategoryWidget::initConnect()
{
    qRegisterMetaType<CategoryInfo>("CategoryInfo");
    connect(ui->listView, SIGNAL(sigClickItem(CategoryInfo)), this, SIGNAL(sigClickItem(CategoryInfo)));
}
