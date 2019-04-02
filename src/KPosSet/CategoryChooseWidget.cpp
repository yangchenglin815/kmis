#include "CategoryChooseWidget.h"
#include "ui_CategoryChooseWidget.h"
#include "structData.h"
#include <QDebug>

CategoryChooseWidget::CategoryChooseWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CategoryChooseWidget)
    , m_sCategoryName(QStringLiteral("热销"))
    , m_nOnePageCount(12)
    , m_nCurPage(1)
{
    ui->setupUi(this);
//    test();
    initConnect();
}

CategoryChooseWidget::~CategoryChooseWidget()
{
    delete ui;
}

//void CategoryChooseWidget::test()
//{
//    CategoryChooseInfo categoryChooseInfo;
//    for (int i = 0; i < 30; i++)
//    {
//        categoryChooseInfo.skeyId = i;
//        categoryChooseInfo.name = QString(QStringLiteral("呵哈%1")).arg(i);
//        categoryChooseInfo.num = i;
//        if (i == 0)
//        {
//            categoryChooseInfo.bRoot = true;
//            m_rootCategoryChooseInfo = categoryChooseInfo;
//            continue;
//        }
//        else
//        {
//            categoryChooseInfo.bRoot = false;
//        }
//        m_categoryChooseInfoList.append(categoryChooseInfo);
////        ui->listView->appendItem(categoryChooseInfo);
//    }

//    m_nCurPage = 1;
//    int nLen = m_categoryChooseInfoList.length();
//    m_nTotalPage = nLen/m_nOnePageCount + ((nLen%m_nOnePageCount == 0)?0:1);
//    checkCurPageButtonState();
//    generateUIData();
//}

void CategoryChooseWidget::initData(const QList<CategoryInfo*> &categoryInfoList, const CategoryInfo &rootCategoryInfo)
{
    m_categoryChooseInfoList.clear();
    int nLen = categoryInfoList.length();
    int nCount = 2;
    for (int i = 0; i < nLen; i++)
    {
        const CategoryInfo &tempCategoryInfo = *categoryInfoList[i];
        if (tempCategoryInfo.sKeyId != rootCategoryInfo.sKeyId)
        {
            CategoryChooseInfo categoryChooseInfo;
            categoryChooseInfo.bRoot = false;
            categoryChooseInfo.skeyId = tempCategoryInfo.sKeyId;
            categoryChooseInfo.name = tempCategoryInfo.sName;
            categoryChooseInfo.selectedGoodsIdList = getSelectedGoodsId(tempCategoryInfo, rootCategoryInfo);
            categoryChooseInfo.num = categoryChooseInfo.selectedGoodsIdList.length();
            categoryChooseInfo.position = nCount;
            GoodsChooseInfo goodsChooseInfo;
            GoodsInfo goodsInfo;
            int nLen = tempCategoryInfo.listGoodsInfo.length();
            for (int i = 0; i < nLen; i++)
            {
                goodsInfo = tempCategoryInfo.listGoodsInfo[i];
                goodsChooseInfo.bRootGoods = false;
                goodsChooseInfo.id = goodsInfo.nId;
                QString strName = "";
                if( goodsInfo.sShortName.isEmpty() ) {
                    strName = goodsInfo.sName;
                } else {
                    strName = goodsInfo.sShortName;
                }
                goodsChooseInfo.name = strName;
                goodsChooseInfo.price = QString::number(goodsInfo.fPrice);
                goodsChooseInfo.unit = goodsInfo.sSaleUnit;
                categoryChooseInfo.goodsChooseInfoList.append(goodsChooseInfo);
            }
            m_categoryChooseInfoList.append(categoryChooseInfo);
            nCount++;
        }
        else
        {
            m_rootCategoryChooseInfo.bRoot = true;
            m_rootCategoryChooseInfo.skeyId = rootCategoryInfo.sKeyId;
            m_rootCategoryChooseInfo.name = rootCategoryInfo.sName;
            m_rootCategoryChooseInfo.position = 1;
            m_rootCategoryChooseInfo.num = rootCategoryInfo.listGoodsInfo.length();
            m_rootCategoryChooseInfo.goodsChooseInfoList.clear();
            m_rootCategoryChooseInfo.selectedGoodsIdList.clear();
            GoodsChooseInfo goodsChooseInfo;
            GoodsInfo goodsInfo;
            int nLen = rootCategoryInfo.listGoodsInfo.length();
            for (int i = 0; i < nLen; i++)
            {
                goodsInfo = rootCategoryInfo.listGoodsInfo[i];
                goodsChooseInfo.bRootGoods = true;
                goodsChooseInfo.id = goodsInfo.nId;
                QString strName = "";
                if( goodsInfo.sShortName.isEmpty() ) {
                    strName = goodsInfo.sName;
                } else {
                    strName = goodsInfo.sShortName;
                }
                goodsChooseInfo.name = strName;
                goodsChooseInfo.price = QString::number(goodsInfo.fPrice);
                goodsChooseInfo.unit = goodsInfo.sSaleUnit;
                m_rootCategoryChooseInfo.goodsChooseInfoList.append(goodsChooseInfo);
//                m_rootCategoryChooseInfo.selectedGoodsIdList.append(goodsChooseInfo.id);
            }         
        }
    }
    m_nCurPage = 1;
    nLen = m_categoryChooseInfoList.length();
    m_nTotalPage = nLen/m_nOnePageCount + ((nLen%m_nOnePageCount == 0)?0:1);
    ui->listView->setDefultSelectedCategoryKeyId(rootCategoryInfo.sKeyId);
    checkCurPageButtonState();
    generateUIData();

    slot_chooseCategory(m_rootCategoryChooseInfo);
}

void CategoryChooseWidget::slot_chooseCategory(CategoryChooseInfo categoryChooseInfo)
{
    emit sigChooseCategory(categoryChooseInfo);
}

void CategoryChooseWidget::slot_upPage()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUIData();
}

void CategoryChooseWidget::slot_downPage()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUIData();
}

void CategoryChooseWidget::initConnect()
{
    connect(ui->listView, SIGNAL(sigChooseCategory(CategoryChooseInfo)),
            this, SLOT(slot_chooseCategory(CategoryChooseInfo)));
    connect(ui->upArrowButton, SIGNAL(sigClick()), this, SLOT(slot_upPage()));
    connect(ui->downArrowButton, SIGNAL(sigClick()), this, SLOT(slot_downPage()));
}

void CategoryChooseWidget::generateUIData()
{
    ui->downArrowButton->setArrowText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));

    ui->listView->clearItems();
    int nStartPos = m_nOnePageCount * (m_nCurPage - 1);
    int nEndPos = m_nOnePageCount * m_nCurPage;
    int nLen = m_categoryChooseInfoList.length();
    ui->listView->appendItem(m_rootCategoryChooseInfo);
    for (int i = nStartPos; i < nEndPos && i < nLen; i++)
    {
        ui->listView->appendItem(m_categoryChooseInfoList[i]);
    }
}

void CategoryChooseWidget::checkCurPageButtonState()
{
    if (m_nCurPage <= 1)
    {
        m_nCurPage = 1;
        ui->upArrowButton->setArrowDisable();
    }
    else
    {
        ui->upArrowButton->setArrowEnable();
    }

    if (m_nCurPage < m_nTotalPage)
    {
        ui->downArrowButton->setArrowEnable();
    }
    else
    {
        m_nCurPage = m_nTotalPage;
        ui->downArrowButton->setArrowDisable();
    }
}

QList<int> CategoryChooseWidget::getSelectedGoodsId(CategoryInfo categoryInfo, CategoryInfo rootCategoryInfo)
{
    QList<int> goodsIdList;
    int len1 = categoryInfo.listGoodsInfo.length();
    for (int i = 0; i < len1; i++)
    {
        int nFindId = categoryInfo.listGoodsInfo[i].nId;
        int len2 = rootCategoryInfo.listGoodsInfo.length();
        for (int j = 0; j < len2; j++)
        {
            if (nFindId == rootCategoryInfo.listGoodsInfo[j].nId)
            {
                goodsIdList.append(nFindId);
                rootCategoryInfo.listGoodsInfo.removeAt(j);
                break;
            }
        }
    }
    return goodsIdList;
}
