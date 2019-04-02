#include "BCSGoodsSelectWidget.h"
#include "ui_BCSGoodsSelectWidget.h"
#include "enumData.h"
#include <QMessageBox>
#include "TipsDlg.h"

BCSGoodsSelectWidget::BCSGoodsSelectWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BCSGoodsSelectWidget)
    , m_pCtrl(NULL)
    , m_nGroupId(-1)
{
    ui->setupUi(this);
    initConnect();
}

BCSGoodsSelectWidget::~BCSGoodsSelectWidget()
{
    delete ui;
}

//void BCSGoodsSelectWidget::test()
//{
//    OrderCategoryBigInfo *pOrderCategoryBigInfo = NULL;
//    for (int i = 0; i < 20; i++)
//    {
//        pOrderCategoryBigInfo = new OrderCategoryBigInfo;
//        pOrderCategoryBigInfo->nId = i + 1;
//        pOrderCategoryBigInfo->sName = QStringLiteral("蔬菜%1").arg(i+1);
//        pOrderCategoryBigInfo->nNumber = 20; // 二级分类个数
//        OrderCategorySmallInfo* pOrderCategorySmallInfo = NULL;
//        for (int j = 0; j < 20; j++)
//        {
//            pOrderCategorySmallInfo = new OrderCategorySmallInfo;
//            pOrderCategorySmallInfo->nId = 100*i+j;
//            pOrderCategorySmallInfo->sName = QStringLiteral("蔬菜%1+%2").arg(i+1).arg(j+1);
//            pOrderCategorySmallInfo->nNumber = 0; // 选中的商品种数
//            pOrderCategorySmallInfo->bFakeSmallCategory = false;// 是否是假的二级分类
//            pOrderCategoryBigInfo->orderCategorySmallInfoList.append(pOrderCategorySmallInfo);
////            QList<int> leafCategoryIdList;
////            QList<OrderGoodsInfo*> orderGoodsInfoList;
////            for (int k = 0; k < 10; k++)
////            {

////            }
//        }
//        m_orderCategoryBigInfoList.append(pOrderCategoryBigInfo);
//    }

//    ui->categoryBigWidget->initData(m_orderCategoryBigInfoList);
//}

void BCSGoodsSelectWidget::setCtrl(BarCodeScalesCtrl *pCtrl)
{
    if (m_pCtrl == NULL)
    {
        m_pCtrl = pCtrl;
        connect(m_pCtrl, SIGNAL(sigOnGetOrderCategory(int,QString,QList<OrderCategoryBigInfo_s>))
                ,this, SLOT(slot_onGetOrderCategory(int,QString,QList<OrderCategoryBigInfo_s>)));
    }
}

void BCSGoodsSelectWidget::setGroupId(int nGroupId)
{
    m_nGroupId = nGroupId;
}

void BCSGoodsSelectWidget::init()
{
    clearData();
    if (m_pCtrl != NULL)
    {
        m_pCtrl->getAllCategoryRequest();
        m_pCtrl->getBcsGoods(m_goodInfoMap);
    }
}

void BCSGoodsSelectWidget::clearData()
{
    OrderCategoryBigInfo* pOrderCategoryBigInfo = NULL;
    OrderCategorySmallInfo* pOrderCategorySmallInfo = NULL;
    OrderGoodsInfo* pOrderGoodsInfo = NULL;
    int nLen1 = m_orderCategoryBigInfoList.length();
    int nLen2 = 0;
    int nLen3 = 0;
    for (int i = 0; i < nLen1; i++)
    {
        pOrderCategoryBigInfo = m_orderCategoryBigInfoList[i];
        nLen2 = pOrderCategoryBigInfo->orderCategorySmallInfoList.length();
        for (int j = 0; j < nLen2; j++)
        {
            pOrderCategorySmallInfo = pOrderCategoryBigInfo->orderCategorySmallInfoList[j];
            nLen3 = pOrderCategorySmallInfo->orderGoodsInfoList.length();
            for (int k = 0; k < nLen3; k++)
            {
                pOrderGoodsInfo = pOrderCategorySmallInfo->orderGoodsInfoList[k];
                delete pOrderGoodsInfo;
            }
            delete pOrderCategorySmallInfo;
        }
        delete pOrderCategoryBigInfo;
    }
    m_orderCategoryBigInfoList.clear();
}

void BCSGoodsSelectWidget::slot_clickCategoryBig(int nCategoryBigId)
{
    OrderCategoryBigInfo* pOrderCategoryBigInfo = getCategoryBigInfo(nCategoryBigId);
    m_nClickedCategoryBigId = nCategoryBigId;
    int nDefaultSelectedId = c_nNegativeNumber;
    if (m_categoryBigSmallIdMap.contains(m_nClickedCategoryBigId))
    {
        nDefaultSelectedId = m_categoryBigSmallIdMap.value(m_nClickedCategoryBigId);
    }
//    int nLen1 = pOrderCategoryBigInfo->orderCategorySmallInfoList.length();
//    OrderCategorySmallInfo* pOrderCategorySmallInfo = NULL;
//    OrderGoodsInfo* pOrderGoodsInfo;
//    int nLen2 = 0;
//    for (int i = 0; i < nLen1; i++)
//    {
//        pOrderCategorySmallInfo = pOrderCategoryBigInfo->orderCategorySmallInfoList[i];
//        nLen2 = pOrderCategorySmallInfo->orderGoodsInfoList.length();
//        int nSelectedCategoryNumber = 0;
//        for (int j = 0; j < nLen2; j++)
//        {
//            pOrderGoodsInfo = pOrderCategorySmallInfo->orderGoodsInfoList[j];
//            if (pOrderGoodsInfo->nOrderGoodsNumber > 0)
//            {
//                nSelectedCategoryNumber++;
//            }
//        }
//        pOrderCategorySmallInfo->nNumber = nSelectedCategoryNumber;
//    }
    ui->categorySmallWidget->initData(pOrderCategoryBigInfo->orderCategorySmallInfoList, nDefaultSelectedId);
}

void BCSGoodsSelectWidget::slot_clickCategorySmall(int nCategorySmallId)
{
    m_categoryBigSmallIdMap.insert(m_nClickedCategoryBigId, nCategorySmallId);

    if (nCategorySmallId >= 0)
    {
        ui->goodsWidget->initData(m_goodInfoMap.value(nCategorySmallId));
    }
    else
    {
        OrderCategoryBigInfo* pOrderCategoryBigInfo = NULL;
        OrderCategorySmallInfo* pOrderCategorySmallInfo = NULL;
        int nLen1 = m_orderCategoryBigInfoList.length();
        int nLen2 = -1;
        QList<BCSGoodsInfo> bcsGoodsInfoList;
        for (int i = 0; i < nLen1; i++)
        {
            pOrderCategoryBigInfo = m_orderCategoryBigInfoList[i];
            if (pOrderCategoryBigInfo->nId == m_nClickedCategoryBigId)
            {
                nLen2 = pOrderCategoryBigInfo->orderCategorySmallInfoList.length();
                for (int j = 0; j < nLen2; j++)
                {
                    pOrderCategorySmallInfo = pOrderCategoryBigInfo->orderCategorySmallInfoList[j];
                    bcsGoodsInfoList.append(m_goodInfoMap.value(pOrderCategorySmallInfo->nId));
                }
                break;
            }
        }
        ui->goodsWidget->initData(bcsGoodsInfoList);
    }
}

void BCSGoodsSelectWidget::slot_updateSelectCount(QList<QString> keyIdList)
{
    OrderCategoryBigInfo* pOrderCategoryBigInfo = getCategoryBigInfo(m_nClickedCategoryBigId);
    int nDefaultSelectedId = c_nNegativeNumber;
    if (m_categoryBigSmallIdMap.contains(m_nClickedCategoryBigId))
    {
        nDefaultSelectedId = m_categoryBigSmallIdMap.value(m_nClickedCategoryBigId);
    }

    QList<int> categorySmallKeyList = m_goodInfoMap.keys();
    int nLen1 = categorySmallKeyList.length();
    int nLen2 = -1;
    int nSmallKeyId = -1;
    QList<BCSGoodsInfo> bcsGoodsInfoList;
    for (int i = 0; i < nLen1; i++)
    {
        nSmallKeyId = categorySmallKeyList[i];
        OrderCategorySmallInfo *pOrderCategorySmallInfo = getCategorySmallInfo(pOrderCategoryBigInfo, nSmallKeyId);
        if (pOrderCategorySmallInfo == NULL)
        {
            continue;
        }
        pOrderCategorySmallInfo->nNumber = 0;
        bcsGoodsInfoList = m_goodInfoMap.value(nSmallKeyId);
        nLen2 = bcsGoodsInfoList.length();
        for (int j = 0; j < nLen2; j++)
        {
            if (keyIdList.contains(bcsGoodsInfoList[j].sKeyId))
            {
                pOrderCategorySmallInfo->nNumber++;
                keyIdList.removeOne(bcsGoodsInfoList[j].sKeyId);
            }
        }
    }

    ui->categorySmallWidget->initData(pOrderCategoryBigInfo->orderCategorySmallInfoList, nDefaultSelectedId);
}

void BCSGoodsSelectWidget::slot_saveGroupGoods(QList<QString> keyIdList)
{
    if (m_pCtrl != NULL)
    {
        m_pCtrl->saveGoodsGroupRequest(m_nGroupId, keyIdList);
    }
}

void BCSGoodsSelectWidget::slot_onGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> orderCategoryBigList)
{
    if (nCode != e_success)
    {
        QMessageBox::information(this, QStringLiteral("提示")
                                 , QString(QStringLiteral("出现异常--错误码:%1, 错误信息:%2")).arg(nCode).arg(sMsg));
        return;
    }

    OrderCategoryBigInfo_s orderCategoryBigInfo_s;
    OrderCategorySmallInfo_s orderCategorySmallInfo_s;
    OrderCategoryBigInfo* pOrderCategoryBigInfo = NULL;
    OrderCategorySmallInfo* pOrderCategorySmallInfo = NULL;
    int nLen1 = orderCategoryBigList.length();
    int nLen2 = 0;
    for (int i = 0; i < nLen1; i++)
    {
        orderCategoryBigInfo_s = orderCategoryBigList[i];
        pOrderCategoryBigInfo = new OrderCategoryBigInfo;
        pOrderCategoryBigInfo->nId = orderCategoryBigInfo_s.nId;
        pOrderCategoryBigInfo->sName = orderCategoryBigInfo_s.sName;
        pOrderCategoryBigInfo->orderCategorySmallInfoList.clear();
        nLen2 = orderCategoryBigInfo_s.smallCategoryList.length();
        if (nLen2 > 0)
        {
            for (int j = 0; j < nLen2; j++)
            {
                orderCategorySmallInfo_s = orderCategoryBigInfo_s.smallCategoryList[j];
                pOrderCategorySmallInfo = new OrderCategorySmallInfo;
                pOrderCategorySmallInfo->nId = orderCategorySmallInfo_s.nId;
                pOrderCategorySmallInfo->sName = orderCategorySmallInfo_s.sName;
                pOrderCategorySmallInfo->leafCategoryIdList = orderCategorySmallInfo_s.leafCategoryIdList;
                pOrderCategorySmallInfo->nNumber = 0;
                pOrderCategorySmallInfo->bFakeSmallCategory = false;
                pOrderCategorySmallInfo->orderGoodsInfoList.clear();
                pOrderCategoryBigInfo->orderCategorySmallInfoList.append(pOrderCategorySmallInfo);
            }
            pOrderCategoryBigInfo->nNumber = pOrderCategoryBigInfo->orderCategorySmallInfoList.length();
        }
        else // 只有一级分类，无二级分类的情况
        {
            pOrderCategorySmallInfo = new OrderCategorySmallInfo;
            pOrderCategorySmallInfo->nId = orderCategoryBigInfo_s.nId;
            pOrderCategorySmallInfo->sName = orderCategoryBigInfo_s.sName;
            pOrderCategorySmallInfo->leafCategoryIdList.append(orderCategoryBigInfo_s.nId);
            pOrderCategorySmallInfo->nNumber = 0;
            pOrderCategorySmallInfo->bFakeSmallCategory = true; // 创建一个假的二级分类
            pOrderCategorySmallInfo->orderGoodsInfoList.clear();
            pOrderCategoryBigInfo->orderCategorySmallInfoList.append(pOrderCategorySmallInfo);
            pOrderCategoryBigInfo->nNumber = 0;
        }
        m_orderCategoryBigInfoList.append(pOrderCategoryBigInfo);
    }
    ui->categoryBigWidget->initData(m_orderCategoryBigInfoList);
}

void BCSGoodsSelectWidget::initConnect()
{
    connect(ui->categoryBigWidget, SIGNAL(sigClickCategoryBig(int)), this, SLOT(slot_clickCategoryBig(int)));
    connect(ui->categorySmallWidget, SIGNAL(sigClickCategorySmall(int)), this, SLOT(slot_clickCategorySmall(int)));
    connect(ui->goodsWidget, SIGNAL(sigUpdateSelectCount(QList<QString>)), this, SLOT(slot_updateSelectCount(QList<QString>)));
    connect(ui->goodsWidget, SIGNAL(sigSaveGroupGoods(QList<QString>)), this, SLOT(slot_saveGroupGoods(QList<QString>)));
//    connect(ui->orderGoodsWidget, SIGNAL(sigOrderGoodsChanged()), this, SLOT(slot_orderGoodsChanged()));
//    connect(ui->orderGoodsWidget, SIGNAL(sigClickReturn(int, int, int)), this, SLOT(slot_orderGoodsWidgetClickReturn(int, int, int)));
//    qRegisterMetaType<QList<OrderGoodsInfo*> >("QList<OrderGoodsInfo*>");
//    connect(ui->orderGoodsWidget, SIGNAL(sigCreateOrderCard(QList<OrderGoodsInfo*>)), this, SLOT(slot_createOrderCard(QList<OrderGoodsInfo*>)));
//    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
    connect(ui->titleWidget, SIGNAL(sigReturnClicked()), this, SIGNAL(sigReturnClicked()));
}

OrderCategoryBigInfo *BCSGoodsSelectWidget::getCategoryBigInfo(int nCategoryBigId)
{
    OrderCategoryBigInfo* pOrderCategoryBigInfo = NULL;
    int nLen = m_orderCategoryBigInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        pOrderCategoryBigInfo = m_orderCategoryBigInfoList[i];
        if (pOrderCategoryBigInfo->nId == nCategoryBigId)
        {
            return pOrderCategoryBigInfo;
        }
    }

    return NULL;
}

OrderCategorySmallInfo *BCSGoodsSelectWidget::getCategorySmallInfo(OrderCategoryBigInfo *pOrderCategoryBigInfo, int nCategorySmallId)
{
    if (pOrderCategoryBigInfo == NULL)
    {
        return NULL;
    }
    int nLen = pOrderCategoryBigInfo->orderCategorySmallInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (pOrderCategoryBigInfo->orderCategorySmallInfoList[i]->nId == nCategorySmallId)
        {
            return pOrderCategoryBigInfo->orderCategorySmallInfoList[i];
        }
    }
    return NULL;
}
