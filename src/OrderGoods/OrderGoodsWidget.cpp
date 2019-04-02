#include "OrderGoodsWidget.h"
#include "ui_OrderGoodsWidget.h"
#include "../data/enumData.h"
#include <QMap>
#include <QDebug>
#include "TipsDlg.h"

//// 测试用结构体
//struct SmallCateInfo
//{
//    QString sName;
//    QList<QString> nameList;
//    QList<QString> priceList;
//    void clear()
//    {
//        nameList.clear();
//        priceList.clear();
//    }
//};
//// 测试用结构体
//struct BigCateInfo
//{
//    QString sName;
//    QList<SmallCateInfo> smallCateInfoList;
//};

OrderGoodsWidget::OrderGoodsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OrderGoodsWidget)
    , m_nClickedCategoryBigId(-1)
    , m_pOrderGoodsCtrl(NULL)
    , m_pDlgCommon(NULL)
    , m_bOrderCardChanged(false)
    , m_bReInitData(true)
{
    ui->setupUi(this);
    initConnect();
}

OrderGoodsWidget::~OrderGoodsWidget()
{
    clearData();
    if (m_pDlgCommon != NULL)
    {
        m_pDlgCommon->deleteLater();
    }
    delete ui;
}

void OrderGoodsWidget::setReInitData()
{
    m_bReInitData = true;
}

void OrderGoodsWidget::getOrderCategory()
{
    if (m_pOrderGoodsCtrl == NULL)
    {
        m_pOrderGoodsCtrl = new OrderGoodsCtrl(this);
        qRegisterMetaType<QList<OrderCategoryBigInfo_s> >("QList<OrderCategoryBigInfo_s>");
        connect(m_pOrderGoodsCtrl, SIGNAL(sigOnGetOrderCategory(int,QString,QList<OrderCategoryBigInfo_s>))
                , this, SLOT(slot_onGetOrderCategory(int,QString,QList<OrderCategoryBigInfo_s>)));

        qRegisterMetaType<QList<OrderGoodsInfo_s> >("QList<OrderGoodsInfo_s>");
        connect(m_pOrderGoodsCtrl, SIGNAL(sigOnGetOrderGoods(int,QString,QList<OrderGoodsInfo_s>,int))
                , this, SLOT(slot_onGetOrderGoods(int,QString,QList<OrderGoodsInfo_s>,int)));

        connect(m_pOrderGoodsCtrl, SIGNAL(sigOnCreateOrderCard(int,QString))
                , this, SLOT(slot_onCreateOrderCard(int,QString)));
    }
    m_pOrderGoodsCtrl->getOrderCategoryRequest();
}

void OrderGoodsWidget::test()
{
    if (m_bReInitData)
    {
        m_bReInitData = false;
        clearData();
        getOrderCategory();
    }
}

void OrderGoodsWidget::clearData()
{
    m_nRequestCategoryIdList.clear();

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

void OrderGoodsWidget::clearChooseGoods()
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
            pOrderCategorySmallInfo->nNumber = 0;
            nLen3 = pOrderCategorySmallInfo->orderGoodsInfoList.length();
            for (int k = 0; k < nLen3; k++)
            {
                pOrderGoodsInfo = pOrderCategorySmallInfo->orderGoodsInfoList[k];
                pOrderGoodsInfo->nOrderGoodsNumber = 0;
            }
        }
    }
    ui->orderGoodsWidget->clearChooseGoods();
}

void OrderGoodsWidget::slot_clickCategoryBig(int nCategoryBigId)
{
    OrderCategoryBigInfo* pOrderCategoryBigInfo = getCategoryBigInfo(nCategoryBigId);
    m_nClickedCategoryBigId = nCategoryBigId;
    int nDefaultSelectedId = c_nNegativeNumber;
    if (m_categoryBigSmallIdMap.contains(m_nClickedCategoryBigId))
    {
        nDefaultSelectedId = m_categoryBigSmallIdMap.value(m_nClickedCategoryBigId);
    }
    int nLen1 = pOrderCategoryBigInfo->orderCategorySmallInfoList.length();
    OrderCategorySmallInfo* pOrderCategorySmallInfo = NULL;
    OrderGoodsInfo* pOrderGoodsInfo;
    int nLen2 = 0;
    for (int i = 0; i < nLen1; i++)
    {
        pOrderCategorySmallInfo = pOrderCategoryBigInfo->orderCategorySmallInfoList[i];
        nLen2 = pOrderCategorySmallInfo->orderGoodsInfoList.length();
        int nSelectedCategoryNumber = 0;
        for (int j = 0; j < nLen2; j++)
        {
            pOrderGoodsInfo = pOrderCategorySmallInfo->orderGoodsInfoList[j];
            if (pOrderGoodsInfo->nOrderGoodsNumber > 0)
            {
                nSelectedCategoryNumber++;
            }
        }
        pOrderCategorySmallInfo->nNumber = nSelectedCategoryNumber;
    }
    ui->categorySmallWidget->initData(pOrderCategoryBigInfo->orderCategorySmallInfoList, nDefaultSelectedId);

    if (m_pOrderGoodsCtrl != NULL)
    {
        if (!m_nRequestCategoryIdList.contains(nCategoryBigId))
        {
            m_nRequestCategoryIdList.append(nCategoryBigId);
            m_pOrderGoodsCtrl->getOrderGoodsRequest(nCategoryBigId);
        }
    }

}

void OrderGoodsWidget::slot_clickCategorySmall(int nCategorySmallId)
{
    int nLen = m_orderCategoryBigInfoList.length();
    int nLen2 = 0;
    OrderCategoryBigInfo* pOrderCategoryBigInfo = NULL;
    OrderCategorySmallInfo* pOrderCategorySmallInfo = NULL;

    if (nCategorySmallId >= 0)
    {
        for (int i = 0; i < nLen; i++)
        {
            pOrderCategoryBigInfo = m_orderCategoryBigInfoList[i];
            nLen2 = pOrderCategoryBigInfo->orderCategorySmallInfoList.length();
            for (int j = 0; j < nLen2; j++)
            {
                pOrderCategorySmallInfo = pOrderCategoryBigInfo->orderCategorySmallInfoList[j];
                if (pOrderCategorySmallInfo->nId == nCategorySmallId)
                {
                    m_categoryBigSmallIdMap.insert(m_nClickedCategoryBigId, nCategorySmallId);
                    ui->orderGoodsWidget->initData(pOrderCategorySmallInfo->orderGoodsInfoList);
                    return;
                }
            }
        }
    }
    else
    {
        m_categoryBigSmallIdMap.insert(m_nClickedCategoryBigId, nCategorySmallId);
        int nLen3 = 0;
        QMap<int, OrderGoodsInfo*> rootMap;
        OrderGoodsInfo* pOrderGoodsInfo = NULL;
        for (int i = 0; i < nLen; i++)
        {
            pOrderCategoryBigInfo = m_orderCategoryBigInfoList[i];
            if (pOrderCategoryBigInfo->nId == m_nClickedCategoryBigId)
            {
                nLen2 = pOrderCategoryBigInfo->orderCategorySmallInfoList.length();
                for (int j = 0; j < nLen2; j++)
                {
                    pOrderCategorySmallInfo = pOrderCategoryBigInfo->orderCategorySmallInfoList[j];
                    nLen3 = pOrderCategorySmallInfo->orderGoodsInfoList.length();
                    for (int k = 0; k < nLen3; k++)
                    {
                        pOrderGoodsInfo = pOrderCategorySmallInfo->orderGoodsInfoList[k];
                        rootMap.insert(pOrderGoodsInfo->nId, pOrderGoodsInfo);
                    }
                }
                break;
            }
        }
        ui->orderGoodsWidget->initData(rootMap.values());
    }
}

void OrderGoodsWidget::slot_orderGoodsChanged()
{
    slot_clickCategoryBig(m_nClickedCategoryBigId);

}

void OrderGoodsWidget::slot_searchChanged(QString searchText)
{
    if (searchText.isEmpty())
    {
        return;
    }

    int nLen = m_orderCategoryBigInfoList.length();
    int nLen2 = 0;
    int nLen3 = 0;
    OrderCategoryBigInfo* pOrderCategoryBigInfo = NULL;
    OrderCategorySmallInfo* pOrderCategorySmallInfo = NULL;

    QMap<int, OrderGoodsInfo*> rootMap;
    OrderGoodsInfo* pOrderGoodsInfo = NULL;
    for (int i = 0; i < nLen; i++)
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
                if (pOrderGoodsInfo->sName.contains(searchText))
                {
                    rootMap.insert(pOrderGoodsInfo->nId, pOrderGoodsInfo);
                }
            }
        }
    }
    ui->orderGoodsWidget->initData(rootMap.values());
    ui->orderGoodsWidget->setConfirmButtonText(true);
}

void OrderGoodsWidget::slot_orderGoodsWidgetClickReturn(int nGoodsId, int nCategoryBigId, int nCategorySmallId)
{
    ui->categoryBigWidget->clickCategoryBigId(nCategoryBigId);
    m_nClickedCategoryBigId = nCategoryBigId;
    m_categoryBigSmallIdMap.insert(nCategoryBigId, nCategorySmallId);
    slot_clickCategoryBig(nCategoryBigId);
    slot_clickCategorySmall(nCategorySmallId);
    ui->orderGoodsWidget->findGoodsPage(nGoodsId);
}

void OrderGoodsWidget::slot_createOrderCard(QList<OrderGoodsInfo *> orderGoodsInfoList)
{    
    if (m_pOrderGoodsCtrl != NULL)
    {
        m_pOrderGoodsCtrl->createOrderCardRequest(orderGoodsInfoList);
    }
    if (m_pDlgCommon == NULL)
    {
        m_pDlgCommon = new DlgCommon;
        m_pDlgCommon->hideBottomWidget();
    }
    m_pDlgCommon->hideDeleteButton();
    m_pDlgCommon->set_title(QStringLiteral("提示"));
    m_pDlgCommon->set_content(QStringLiteral("正在上传要货卡..."));
    m_pDlgCommon->exec();
}

void OrderGoodsWidget::slot_returnClicked()
{
    emit sigReturnClicked(m_bOrderCardChanged);
    m_bOrderCardChanged = false;
}

void OrderGoodsWidget::slot_onGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> orderCategoryBigList)
{
    if (nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QString(QStringLiteral("出现异常--错误码:%1, 错误信息:%2")).arg(nCode).arg(sMsg));
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

void OrderGoodsWidget::slot_onGetOrderGoods(int nCode, QString sMsg, QList<OrderGoodsInfo_s> orderGoodsInfoList, int nCategoryBigId)
{
    if (nCode != e_success)
    {
        m_nRequestCategoryIdList.removeAll(nCategoryBigId);
        TipsDlg::instance()->releaseCtrl(QString(QStringLiteral("出现异常--错误码:%1, 错误信息:%2")).arg(nCode).arg(sMsg));
        return;
    }

    OrderCategoryBigInfo* pOrderCategoryBigInfo = NULL;
    OrderCategorySmallInfo* pOrderCategorySmallInfo = NULL;
    OrderGoodsInfo_s orderGoodsInfo_s;
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
            nLen3 = orderGoodsInfoList.length();
            for (int k = 0; k < nLen3; k++)
            {
                orderGoodsInfo_s = orderGoodsInfoList[k];
                if (pOrderCategorySmallInfo->leafCategoryIdList.contains(orderGoodsInfo_s.nCategoryId))
                {
                    pOrderGoodsInfo = new OrderGoodsInfo;
                    pOrderGoodsInfo->nId = orderGoodsInfo_s.nId;// 商品ID
                    pOrderGoodsInfo->sCode = orderGoodsInfo_s.sCode;// 商品编码
                    pOrderGoodsInfo->sName = orderGoodsInfo_s.sName;// 商品名称
                    pOrderGoodsInfo->sUnitSpecification = orderGoodsInfo_s.sUnitSpecification;// 规格单位
                    pOrderGoodsInfo->fUnitSpecificationValue = orderGoodsInfo_s.fUnitSpecificationValue;// 规格单位量
                    pOrderGoodsInfo->sStockNumber = orderGoodsInfo_s.sStockNumber;// 库存数量
                    pOrderGoodsInfo->nSaleNumberToday = orderGoodsInfo_s.nSaleNumberToday; // 当日已定
                    pOrderGoodsInfo->fPrice = orderGoodsInfo_s.fPrice; // 单件单价
                    pOrderGoodsInfo->sSaleNumberYesterday = orderGoodsInfo_s.sSaleNumberYesterday; // 上日销售数量
                    pOrderGoodsInfo->sSaleNumberLastweek = orderGoodsInfo_s.sSaleNumberLastweek; // 上周销售数量
                    pOrderGoodsInfo->sSuggestOrderNumber = orderGoodsInfo_s.sSuggestOrderNumber; //	建议要货件数
                    pOrderGoodsInfo->nOrderSaleRate = orderGoodsInfo_s.nOrderSaleRate; // 订销差率
                    pOrderGoodsInfo->nOrderGoodsNumber = 0; // 要货量
                    pOrderGoodsInfo->nBelongCategoryBigId = pOrderCategoryBigInfo->nId; // 所属的大类id
                    pOrderGoodsInfo->nBelongCategorySmallId = pOrderCategorySmallInfo->nId; // 所属的类id
                    pOrderCategorySmallInfo->orderGoodsInfoList.append(pOrderGoodsInfo);
                }
            }
        }
    }
    ui->categoryBigWidget->initData(m_orderCategoryBigInfoList);
}

void OrderGoodsWidget::slot_onCreateOrderCard(int nCode, QString sMsg)
{
    if (m_pDlgCommon == NULL)
    {
        m_pDlgCommon = new DlgCommon;
        m_pDlgCommon->hideBottomWidget();
    }
    m_pDlgCommon->showDeleteButton();
    m_pDlgCommon->set_title(QStringLiteral("提示"));

    if (nCode == e_success)
    {
        m_pDlgCommon->set_content(QStringLiteral("要货卡创建成功"));
        m_bOrderCardChanged = true;
    }
    else
    {
        m_pDlgCommon->set_content(QString(QStringLiteral("要货卡创建失败，%1")).arg(sMsg));
    }
    clearChooseGoods();
}

void OrderGoodsWidget::initConnect()
{
    connect(ui->categoryBigWidget, SIGNAL(sigClickCategoryBig(int)), this, SLOT(slot_clickCategoryBig(int)));
    connect(ui->categorySmallWidget, SIGNAL(sigClickCategorySmall(int)), this, SLOT(slot_clickCategorySmall(int)));
    connect(ui->orderGoodsWidget, SIGNAL(sigOrderGoodsChanged()), this, SLOT(slot_orderGoodsChanged()));
    connect(ui->orderGoodsWidget, SIGNAL(sigClickReturn(int, int, int)), this, SLOT(slot_orderGoodsWidgetClickReturn(int, int, int)));
    qRegisterMetaType<QList<OrderGoodsInfo*> >("QList<OrderGoodsInfo*>");
    connect(ui->orderGoodsWidget, SIGNAL(sigCreateOrderCard(QList<OrderGoodsInfo*>)), this, SLOT(slot_createOrderCard(QList<OrderGoodsInfo*>)));
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
    connect(ui->titleWidget, SIGNAL(sigReturnClicked()), this, SLOT(slot_returnClicked()));
}

OrderCategoryBigInfo *OrderGoodsWidget::getCategoryBigInfo(int nCategoryBigId)
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
