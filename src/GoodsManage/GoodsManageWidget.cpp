#include "GoodsManageWidget.h"
#include "ui_GoodsManageWidget.h"
#include "TipsDlg.h"
#include "../data/enumData.h"
#include <QMap>

GoodsManageWidget::GoodsManageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoodsManageWidget)
   , m_goodsManageCtrl(NULL)
       , m_nClickedCategoryBigId(-1)
{
    ui->setupUi(this);
    initconnect();
}

GoodsManageWidget::~GoodsManageWidget()
{
    clearData();
    delete ui;
}

void GoodsManageWidget::initGoodsManageCtrl()
{
   if(m_goodsManageCtrl == NULL){
       m_goodsManageCtrl = new GoodsManageCtrl;
       qRegisterMetaType<QList<CategoryBigInfo_s> >("QList<CategoryBigInfo_s>");
       connect(m_goodsManageCtrl, SIGNAL(sigOnGetCategoryList(int,QString,QList<CategoryBigInfo_s>))
               , this, SLOT(slot_getCategoryList(int,QString,QList<CategoryBigInfo_s>)));
       qRegisterMetaType<QList<sGoodsInfo_s> >("QList<sGoodsInfo_s>");
       connect(m_goodsManageCtrl, SIGNAL(sigOnGetGoodsManageList(int,QString,QList<sGoodsInfo_s>,int))
               , this, SLOT(slot_onGetOrderGoods(int,QString,QList<sGoodsInfo_s>,int)));
   }
   m_goodsManageCtrl->getCategoryRequest();
}

void GoodsManageWidget::slot_searchChanged(QString searchText)
{
    if (searchText.isEmpty())
    {
        return;
    }
    int nLen = m_CategoryBigInfoList.length();
    int nLen2 = 0;
    int nLen3 = 0;
    sCategoryBigInfo* pOrderCategoryBigInfo = NULL;
    sCategorySmallInfo* pOrderCategorySmallInfo = NULL;

    QMap<int, sGoodsInfo*> rootMap;
    QList<sGoodsInfo*> infoList;
    sGoodsInfo* pOrderGoodsInfo = NULL;
    for (int i = 0; i < nLen; i++)
    {
        pOrderCategoryBigInfo = m_CategoryBigInfoList[i];
        nLen2 = pOrderCategoryBigInfo->sCategorySmallInfoList.length();
        for (int j = 0; j < nLen2; j++)
        {
            pOrderCategorySmallInfo = pOrderCategoryBigInfo->sCategorySmallInfoList[j];
            nLen3 = pOrderCategorySmallInfo->sGoodsInfoList.length();
            for (int k = 0; k < nLen3; k++)
            {
                pOrderGoodsInfo = pOrderCategorySmallInfo->sGoodsInfoList[k];
                if (pOrderGoodsInfo->sName.contains(searchText) || pOrderGoodsInfo->sCodeId == searchText || pOrderGoodsInfo->sCode == searchText)
                {
//                    rootMap.insert(pOrderGoodsInfo->nId, pOrderGoodsInfo);
                    infoList.append(pOrderGoodsInfo);
                }
            }
        }
    }
//    ui->orderGoodsWidget->initData(rootMap.values());
    ui->orderGoodsWidget->initData(infoList);
}

void GoodsManageWidget::slot_clickCategorySmall(int nCategorySmallId)
{
    int nLen = m_CategoryBigInfoList.length();
    int nLen2 = 0;
    sCategoryBigInfo* pOrderCategoryBigInfo = NULL;
    sCategorySmallInfo* pOrderCategorySmallInfo = NULL;

    if (nCategorySmallId >= 0)
    {
        for (int i = 0; i < nLen; i++)
        {
            pOrderCategoryBigInfo = m_CategoryBigInfoList[i];
            nLen2 = pOrderCategoryBigInfo->sCategorySmallInfoList.length();
            for (int j = 0; j < nLen2; j++)
            {
                pOrderCategorySmallInfo = pOrderCategoryBigInfo->sCategorySmallInfoList[j];
                if (pOrderCategorySmallInfo->nId == nCategorySmallId)
                {
                    m_categoryBigSmallIdMap.insert(m_nClickedCategoryBigId, nCategorySmallId);
                    ui->orderGoodsWidget->initData(pOrderCategorySmallInfo->sGoodsInfoList);
                    return;
                }
            }
        }
    }
    else
    {
        m_categoryBigSmallIdMap.insert(m_nClickedCategoryBigId, nCategorySmallId);
        int nLen3 = 0;
        QMap<int, sGoodsInfo*> rootMap;
        QList<sGoodsInfo*> infoList;
        sGoodsInfo* pOrderGoodsInfo = NULL;
        for (int i = 0; i < nLen; i++)
        {
            pOrderCategoryBigInfo = m_CategoryBigInfoList[i];
            if (pOrderCategoryBigInfo->nId == m_nClickedCategoryBigId)
            {
                nLen2 = pOrderCategoryBigInfo->sCategorySmallInfoList.length();
                for (int j = 0; j < nLen2; j++)
                {
                    pOrderCategorySmallInfo = pOrderCategoryBigInfo->sCategorySmallInfoList[j];
                    nLen3 = pOrderCategorySmallInfo->sGoodsInfoList.length();
                    for (int k = 0; k < nLen3; k++)
                    {
                        pOrderGoodsInfo = pOrderCategorySmallInfo->sGoodsInfoList[k];
                        infoList.append(pOrderGoodsInfo);
//                        rootMap.insert(pOrderGoodsInfo->nId, pOrderGoodsInfo);
                    }
                }
                break;
            }
        }
//        ui->orderGoodsWidget->initData(rootMap.values());
        ui->orderGoodsWidget->initData(infoList);
    }
}

void GoodsManageWidget::slot_getCategoryList(int nCode, QString sMsg, QList<CategoryBigInfo_s> categoryBigInfoList)
{
    if (nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QString(QStringLiteral("出现异常--错误码:%1, 错误信息:%2")).arg(nCode).arg(sMsg));
        return;
    }

    CategoryBigInfo_s orderCategoryBigInfo_s;
    CategorySmallInfo_s orderCategorySmallInfo_s;
    sCategoryBigInfo* pOrderCategoryBigInfo = NULL;
    sCategorySmallInfo* pOrderCategorySmallInfo = NULL;
    int nLen1 = categoryBigInfoList.length();
    int nLen2 = 0;
    for (int i = 0; i < nLen1; i++)
    {
        orderCategoryBigInfo_s = categoryBigInfoList[i];
        pOrderCategoryBigInfo = new sCategoryBigInfo;
        pOrderCategoryBigInfo->nId = orderCategoryBigInfo_s.nId;
        pOrderCategoryBigInfo->sName = orderCategoryBigInfo_s.sName;
        pOrderCategoryBigInfo->sCategorySmallInfoList.clear();
        nLen2 = orderCategoryBigInfo_s.smallCategoryList.length();
        if (nLen2 > 0)
        {
            for (int j = 0; j < nLen2; j++)
            {
                orderCategorySmallInfo_s = orderCategoryBigInfo_s.smallCategoryList[j];
                pOrderCategorySmallInfo = new sCategorySmallInfo;
                pOrderCategorySmallInfo->nId = orderCategorySmallInfo_s.nId;
                pOrderCategorySmallInfo->sName = orderCategorySmallInfo_s.sName;
                pOrderCategorySmallInfo->leafCategoryIdList = orderCategorySmallInfo_s.leafCategoryIdList;
                pOrderCategorySmallInfo->nNumber = 0;
                pOrderCategorySmallInfo->bFakeSmallCategory = false;
                pOrderCategorySmallInfo->sGoodsInfoList.clear();
                pOrderCategoryBigInfo->sCategorySmallInfoList.append(pOrderCategorySmallInfo);
            }
            pOrderCategoryBigInfo->nNumber = pOrderCategoryBigInfo->sCategorySmallInfoList.length();
        }
        else // 只有一级分类，无二级分类的情况
        {
            pOrderCategorySmallInfo = new sCategorySmallInfo;
            pOrderCategorySmallInfo->nId = orderCategoryBigInfo_s.nId;
            pOrderCategorySmallInfo->sName = orderCategoryBigInfo_s.sName;
            pOrderCategorySmallInfo->leafCategoryIdList.append(orderCategoryBigInfo_s.nId);
            pOrderCategorySmallInfo->nNumber = 0;
            pOrderCategorySmallInfo->bFakeSmallCategory = true; // 创建一个假的二级分类
            pOrderCategorySmallInfo->sGoodsInfoList.clear();
            pOrderCategoryBigInfo->sCategorySmallInfoList.append(pOrderCategorySmallInfo);
            pOrderCategoryBigInfo->nNumber = 0;
        }
        m_CategoryBigInfoList.append(pOrderCategoryBigInfo);
    }
    ui->categoryBigWidget->initData(m_CategoryBigInfoList);
}

sCategoryBigInfo *GoodsManageWidget::getCategoryBigInfo(int nCategoryBigId)
{
    sCategoryBigInfo* pOrderCategoryBigInfo = NULL;
    int nLen = m_CategoryBigInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        pOrderCategoryBigInfo = m_CategoryBigInfoList[i];
        if (pOrderCategoryBigInfo->nId == nCategoryBigId)
        {
            return pOrderCategoryBigInfo;
        }
    }

    return NULL;
}

void GoodsManageWidget::slot_clickCategoryBig(int nCategoryBigId)
{
    sCategoryBigInfo* pOrderCategoryBigInfo = getCategoryBigInfo(nCategoryBigId);
    m_nClickedCategoryBigId = nCategoryBigId;
    int nDefaultSelectedId = c_nNegativeNumber;
    if (m_categoryBigSmallIdMap.contains(m_nClickedCategoryBigId))
    {
        nDefaultSelectedId = m_categoryBigSmallIdMap.value(m_nClickedCategoryBigId);
    }
    int nLen1 = pOrderCategoryBigInfo->sCategorySmallInfoList.length();
    sCategorySmallInfo* pOrderCategorySmallInfo = NULL;
    sGoodsInfo* pOrderGoodsInfo;
    int nLen2 = 0;
    for (int i = 0; i < nLen1; i++)
    {
        pOrderCategorySmallInfo = pOrderCategoryBigInfo->sCategorySmallInfoList[i];
        nLen2 = pOrderCategorySmallInfo->sGoodsInfoList.length();
//        int nSelectedCategoryNumber = 0;
        for (int j = 0; j < nLen2; j++)
        {
            pOrderGoodsInfo = pOrderCategorySmallInfo->sGoodsInfoList[j];
//            if (pOrderGoodsInfo->nOrderGoodsNumber > 0)
//            {
//                nSelectedCategoryNumber++;
//            }
        }
//        pOrderCategorySmallInfo->nNumber = nSelectedCategoryNumber;
    }
    ui->categorySmallWidget->initData(pOrderCategoryBigInfo->sCategorySmallInfoList, nDefaultSelectedId);

    if (m_goodsManageCtrl != NULL)
    {
        if (!m_nRequestCategoryIdList.contains(nCategoryBigId))
        {
            m_nRequestCategoryIdList.append(nCategoryBigId);
            m_goodsManageCtrl->getGoodsManageListRequest(nCategoryBigId, "");
        }
    }
}

void GoodsManageWidget::slot_onGetOrderGoods(int nCode, QString sMsg, QList<sGoodsInfo_s> orderGoodsInfoList, int nCategoryBigId)
{
    if (nCode != e_success)
    {
        m_nRequestCategoryIdList.removeAll(nCategoryBigId);
        TipsDlg::instance()->releaseCtrl(QString(QStringLiteral("出现异常--错误码:%1, 错误信息:%2")).arg(nCode).arg(sMsg));
        return;
    }

    sCategoryBigInfo* pOrderCategoryBigInfo = NULL;
    sCategorySmallInfo* pOrderCategorySmallInfo = NULL;
    sGoodsInfo_s orderGoodsInfo_s;
    sGoodsInfo* pOrderGoodsInfo = NULL;
    int nLen1 = m_CategoryBigInfoList.length();
    int nLen2 = 0;
    int nLen3 = 0;
    for (int i = 0; i < nLen1; i++)
    {
        pOrderCategoryBigInfo = m_CategoryBigInfoList[i];
        nLen2 = pOrderCategoryBigInfo->sCategorySmallInfoList.length();
        for (int j = 0; j < nLen2; j++)
        {
            pOrderCategorySmallInfo = pOrderCategoryBigInfo->sCategorySmallInfoList[j];
            nLen3 = orderGoodsInfoList.length();
            for (int k = 0; k < nLen3; k++)
            {
                orderGoodsInfo_s = orderGoodsInfoList[k];
                if (pOrderCategorySmallInfo->leafCategoryIdList.contains(orderGoodsInfo_s.nId))
                {
                    pOrderGoodsInfo = new sGoodsInfo;
                    pOrderGoodsInfo->nId = orderGoodsInfo_s.nId;
                    pOrderGoodsInfo->category = orderGoodsInfo_s.category;
                    pOrderGoodsInfo->fPrice = orderGoodsInfo_s.fPrice;
                    pOrderGoodsInfo->sCode = orderGoodsInfo_s.sCode;
                    pOrderGoodsInfo->sCodeId = orderGoodsInfo_s.sCodeId;
                    pOrderGoodsInfo->sName = orderGoodsInfo_s.sName;
                    pOrderGoodsInfo->sStockNumber = orderGoodsInfo_s.sStockNumber;
                    pOrderGoodsInfo->sUnitSpecification = orderGoodsInfo_s.sUnitSpecification;
                    pOrderGoodsInfo->vPrice = orderGoodsInfo_s.vPrice;
                    pOrderGoodsInfo->nBelongCategoryBigId = pOrderCategoryBigInfo->nId; // 所属的大类id
                    pOrderGoodsInfo->nBelongCategorySmallId = pOrderCategorySmallInfo->nId; // 所属的类id
                    pOrderCategorySmallInfo->sGoodsInfoList.append(pOrderGoodsInfo);
                }
            }
        }
    }
    ui->categoryBigWidget->initData(m_CategoryBigInfoList);
}

void GoodsManageWidget::initconnect()
{
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
    connect(ui->titleWidget, SIGNAL(sigReturnClicked()), this, SIGNAL(sigReturnClicked()));
    connect(ui->orderGoodsWidget, SIGNAL(sigFastCreateDocument()), this, SIGNAL(sigFastCreateDocument()));
    connect(ui->categoryBigWidget, SIGNAL(sigClickCategoryBig(int))
            , this, SLOT(slot_clickCategoryBig(int)));
    connect(ui->categorySmallWidget, SIGNAL(sigClickCategorySmall(int))
            , this, SLOT(slot_clickCategorySmall(int)));
}

void GoodsManageWidget::clearData()
{
    m_nRequestCategoryIdList.clear();

    sCategoryBigInfo* pCategoryBigInfo = NULL;
    sCategorySmallInfo* pCategorySmallInfo = NULL;
    sGoodsInfo* pGoodsInfo = NULL;
    int nLen1 = m_CategoryBigInfoList.length();
    int nLen2 = 0;
    int nLen3 = 0;
    for (int i = 0; i < nLen1; i++)
    {
        pCategoryBigInfo = m_CategoryBigInfoList[i];
        nLen2 = pCategoryBigInfo->sCategorySmallInfoList.length();
        for (int j = 0; j < nLen2; j++)
        {
            pCategorySmallInfo = pCategoryBigInfo->sCategorySmallInfoList[j];
            nLen3 = pCategorySmallInfo->sGoodsInfoList.length();
            for (int k = 0; k < nLen3; k++)
            {
                pGoodsInfo = pCategorySmallInfo->sGoodsInfoList[k];
                delete pGoodsInfo;
            }
            delete pCategorySmallInfo;
        }
        delete pCategoryBigInfo;
    }
    m_CategoryBigInfoList.clear();
}
