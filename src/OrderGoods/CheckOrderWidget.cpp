#include "CheckOrderWidget.h"
#include "ui_CheckOrderWidget.h"
#include "../util/EnumToString.h"
#include "../data/enumData.h"
#include <QMessageBox>
#include <QDebug>

#include "TipsDlg.h"

CheckOrderWidget::CheckOrderWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CheckOrderWidget)
    , m_pCheckOrderGoodsDlg(NULL)
    , m_pOrderGoodsCheckCtrl(NULL)
    , m_bNeedRequestOrderCategory(true)
    , m_bNeedRequestOrderCard(true)
    , m_sStartSearchDate("")
    , m_sEndSearchDate("")
    , m_sSearchPattern("")
{
    ui->setupUi(this);
    initConnect();
}

CheckOrderWidget::~CheckOrderWidget()
{
    if (m_pCheckOrderGoodsDlg != NULL)
    {
        m_pCheckOrderGoodsDlg->deleteLater();
    }
    if (m_pOrderGoodsCheckCtrl != NULL)
    {
        m_pOrderGoodsCheckCtrl->deleteLater();
    }
    clearData();
    delete ui;
}

void CheckOrderWidget::getOrderCategory()
{
    if (m_pOrderGoodsCheckCtrl == NULL)
    {
        m_pOrderGoodsCheckCtrl = new OrderGoodsCheckCtrl(this);
        qRegisterMetaType<QList<OrderCategoryBigInfo_s> >("QList<OrderCategoryBigInfo_s>");
        connect(m_pOrderGoodsCheckCtrl, SIGNAL(sigOnGetOrderCategory(int,QString,QList<OrderCategoryBigInfo_s>))
                , this, SLOT(slot_onGetOrderCategory(int,QString,QList<OrderCategoryBigInfo_s>)));
        qRegisterMetaType<QList<OrderCardInfo_s> >("QList<OrderCardlInfo_s>");
        connect(m_pOrderGoodsCheckCtrl, SIGNAL(sigOnGetOrderCardList(int,QString,QList<OrderCardInfo_s>))
                , this, SLOT(slot_onGetOrderCardList(int,QString,QList<OrderCardInfo_s>)));
        qRegisterMetaType<QList<OrderCardDetailInfo_s> >("QList<OrderCardDetailInfo_s>");
        connect(m_pOrderGoodsCheckCtrl, SIGNAL(sigOnGetOrderCardListDetail(int,QString,QList<OrderCardDetailInfo_s>,bool,QList<int>))
                , this, SLOT(slot_onGetOrderCardListDetail(int,QString,QList<OrderCardDetailInfo_s>,bool,QList<int>)));
        connect(m_pOrderGoodsCheckCtrl, SIGNAL(sigOnUploadOrderCard(int,QString,QList<int>)), this, SLOT(slot_onUploadOrderCard(int,QString,QList<int>)));
        connect(m_pOrderGoodsCheckCtrl, SIGNAL(sigOnRemoveOrderCard(int,QString)), this, SLOT(slot_onRemoveOrderCard(int,QString)));
    }

    if (m_bNeedRequestOrderCategory)
    {
        m_bNeedRequestOrderCategory = false;
        m_pOrderGoodsCheckCtrl->getOrderCategoryRequest();
    }
}

void CheckOrderWidget::test()
{
    clearData();
    ui->categoryDetailWidget->clearSelectId();
    getOrderCategory();
}

void CheckOrderWidget::clearData()
{
    m_bNeedRequestOrderCategory = true;
    m_bNeedRequestOrderCard = true;
    m_selectedCategoryIdList.clear();

    int nLen1 = m_categoryInfoList.length();
    int nLen2 = 0;
    CheckOrderCategoryInfo *pCheckOrderCategoryInfo = NULL;
    CheckOrderCategoryDetailInfo* pCheckOrderCategoryDetailInfo = NULL;
    for (int i = 0; i < nLen1; i++)
    {
       pCheckOrderCategoryInfo = m_categoryInfoList[i];
       nLen2 = pCheckOrderCategoryInfo->m_categoryDetailInfoList.length();
       for (int j = 0; j < nLen2; j++)
       {
           pCheckOrderCategoryDetailInfo = pCheckOrderCategoryInfo->m_categoryDetailInfoList[j];
           delete pCheckOrderCategoryDetailInfo;
       }
       pCheckOrderCategoryInfo->m_categoryDetailInfoList.clear();
       delete pCheckOrderCategoryInfo;
    }
    m_categoryInfoList.clear();
}

QString CheckOrderWidget::createTestOrderId(int i)
{
    if (i >= 0 && i <= 9)
    {
        return QString("000%1").arg(i);
    }
    else if (i >= 10 && i <= 99)
    {
        return QString("00%1").arg(i);
    }
    else if (i >= 100 && i <= 999)
    {
        return QString("0%1").arg(i);
    }
    else if (i >= 1000 && i <= 9999)
    {
        return QString("%1").arg(i);
    }
    else
    {
        return QString::number(i);
    }
}

void CheckOrderWidget::slot_searchOrderCard(int nOrderCardId)
{
    if (m_pOrderGoodsCheckCtrl != NULL)
    {
        QList<int> orderCardIdList;
        orderCardIdList.append(nOrderCardId);
        m_pOrderGoodsCheckCtrl->getOrderCardListDetailRequest(orderCardIdList, true);
    }
}

void CheckOrderWidget::slot_editOrderCard(QList<int> orderCardIdList)
{
    if (m_pOrderGoodsCheckCtrl != NULL)
    {
        m_pOrderGoodsCheckCtrl->getOrderCardListDetailRequest(orderCardIdList, false);
    }
}

//void CheckOrderWidget::slot_checkManyOrderCategoryDetailInfo(QList<int> orderCardIdList)
//{
//    if (m_pOrderGoodsCheckCtrl != NULL)
//    {
//        m_pOrderGoodsCheckCtrl->getOrderCardListDetailRequest(orderCardIdList, false);
//    }
//}

void CheckOrderWidget::slot_uploadOrderCard(QList<int> orderCardIdList)
{
    if (m_pOrderGoodsCheckCtrl != NULL)
    {
        m_pOrderGoodsCheckCtrl->uploadOrderCardRequest(orderCardIdList);
    }
}

void CheckOrderWidget::slot_removeOrderCard(QList<int> orderCardIdList)
{
    if (m_pOrderGoodsCheckCtrl != NULL)
    {
        m_pOrderGoodsCheckCtrl->removeOrderCardRequest(orderCardIdList);
    }
}

void CheckOrderWidget::slot_selectAllCategory(bool bSelectAll)
{
    QList<CheckOrderCategoryDetailInfo *> categoryDetailInfoList;
    if (bSelectAll)
    {
        m_selectedCategoryIdList.clear();
        int nLen = m_categoryInfoList.length();
        for (int i = 0; i < nLen; i++)
        {
            m_selectedCategoryIdList.append(m_categoryInfoList[i]->nId);
            categoryDetailInfoList.append(m_categoryInfoList[i]->m_categoryDetailInfoList);
        }
        ui->categoryDetailWidget->initData(categoryDetailInfoList);
    }
    else
    {
        m_selectedCategoryIdList.clear();
        ui->categoryDetailWidget->clearSelectId();
        ui->categoryDetailWidget->initData(categoryDetailInfoList);
    }
}

void CheckOrderWidget::slot_addSelectCategory(int nCategoryId, bool bAdded)
{
    if (bAdded)
    {
        m_selectedCategoryIdList.append(nCategoryId);
        int nLen = m_categoryInfoList.length();
        for (int i = 0; i < nLen; i++)
        {
            if (m_categoryInfoList[i]->nId == nCategoryId)
            {
                ui->categoryDetailWidget->appendCategory(m_categoryInfoList[i]->m_categoryDetailInfoList);
                break;
            }
        }
    }
    else
    {
        m_selectedCategoryIdList.removeAll(nCategoryId);
        ui->categoryDetailWidget->removeCategory(nCategoryId);
    }
}

void CheckOrderWidget::slot_searchDate(QString sStartDate, QString sEndDate, QString sSearchText)
{
    m_sStartSearchDate = sStartDate;
    m_sEndSearchDate = sEndDate;
    m_sSearchPattern = sSearchText;
    clearData();
    getOrderCategory();
}

void CheckOrderWidget::slot_onGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> categoryInfoList)
{
    if (nCode != e_success)
    {
        QMessageBox::information(this, QStringLiteral("提示")
                                 , QString(QStringLiteral("出现异常--错误码:%1, 错误信息:%2")).arg(nCode).arg(sMsg));
        return;
    }

    CheckOrderCategoryInfo *pCheckOrderCategoryInfo = NULL;
    OrderCategoryBigInfo_s orderCategoryBigInfo_s;
    int nLen = categoryInfoList.length();
    QList<int> categoryIdList;
    for (int i = 0; i < nLen; i++)
    {
        orderCategoryBigInfo_s = categoryInfoList[i];
        pCheckOrderCategoryInfo = new CheckOrderCategoryInfo;
        pCheckOrderCategoryInfo->nId = orderCategoryBigInfo_s.nId;
        pCheckOrderCategoryInfo->sName = orderCategoryBigInfo_s.sName;
        m_categoryInfoList.append(pCheckOrderCategoryInfo);
        categoryIdList.append(orderCategoryBigInfo_s.nId);
    }

    ui->categoryWidget->initData(m_categoryInfoList);

    if (m_bNeedRequestOrderCard)
    {
        m_bNeedRequestOrderCard = false;
        if (m_pOrderGoodsCheckCtrl != NULL)
        {
            m_pOrderGoodsCheckCtrl->getOrderCardListRequest(categoryIdList, m_sStartSearchDate, m_sEndSearchDate, m_sSearchPattern);
        }
    }
}

void CheckOrderWidget::slot_onGetOrderCardList(int nCode, QString sMsg, QList<OrderCardInfo_s> orderCardlInfoList)
{
    if (nCode != e_success)
    {
        QMessageBox::information(this, QStringLiteral("提示")
                                 , QString(QStringLiteral("出现异常--错误码:%1, 错误信息:%2")).arg(nCode).arg(sMsg));
        return;
    }

    CheckOrderCategoryInfo *pCheckOrderCategoryInfo = NULL;
    CheckOrderCategoryDetailInfo* pCheckOrderCategoryDetailInfo = NULL;
    OrderCardInfo_s orderCardInfo_s;
    int nLen1 = m_categoryInfoList.length();
    int nLen2 = 0;
    QList<CheckOrderCategoryDetailInfo *> categoryDetailInfoList;
    for (int i = 0; i < nLen1; i++)
    {
        pCheckOrderCategoryInfo = m_categoryInfoList[i];
        nLen2 = orderCardlInfoList.length();
        for (int j = nLen2 - 1; j >= 0; j--)
        {
            orderCardInfo_s = orderCardlInfoList[j];
            if (orderCardInfo_s.nCategoryId == pCheckOrderCategoryInfo->nId)
            {
                orderCardlInfoList.removeAt(j);
                pCheckOrderCategoryDetailInfo = new CheckOrderCategoryDetailInfo;
                pCheckOrderCategoryDetailInfo->bSelected = false;
                pCheckOrderCategoryDetailInfo->nOrderCardId = orderCardInfo_s.nOrderCardId;
                pCheckOrderCategoryDetailInfo->sCardOrOrderId = orderCardInfo_s.sCardOrOrderId;
                pCheckOrderCategoryDetailInfo->bUploadFinish = orderCardInfo_s.bUploadFinish;
                pCheckOrderCategoryDetailInfo->nCategoryId = orderCardInfo_s.nCategoryId;
                pCheckOrderCategoryDetailInfo->sCategoryName = orderCardInfo_s.sCategoryName;
                pCheckOrderCategoryDetailInfo->sOrderMaker = orderCardInfo_s.sOrderMaker;
                pCheckOrderCategoryDetailInfo->sUploader = orderCardInfo_s.sUploader;
                pCheckOrderCategoryDetailInfo->sUpdateTime = orderCardInfo_s.sUpdateTime;
                pCheckOrderCategoryDetailInfo->sCreateTime = orderCardInfo_s.sCreateTime;
                pCheckOrderCategoryDetailInfo->sWantState = EnumToString::orderCardTypeToString(orderCardInfo_s.nWantState);
                pCheckOrderCategoryDetailInfo->nCategoryNum = orderCardInfo_s.nCategoryNum;
                pCheckOrderCategoryInfo->m_categoryDetailInfoList.append(pCheckOrderCategoryDetailInfo);
                if (m_selectedCategoryIdList.contains(orderCardInfo_s.nCategoryId))
                {
                    categoryDetailInfoList.append(pCheckOrderCategoryDetailInfo);
                }
            }
        }
    }

    ui->categoryDetailWidget->appendCategory(categoryDetailInfoList);
}

void CheckOrderWidget::slot_onGetOrderCardListDetail(int nCode, QString sMsg, QList<OrderCardDetailInfo_s> orderCardDetailInfoList, bool bUploadFinish, QList<int> orderCardIdList)
{
    if (nCode == e_success)
    {
        if (m_pCheckOrderGoodsDlg == NULL)
        {
            m_pCheckOrderGoodsDlg = new CheckOrderGoodsDlg;
        }
        QPoint globalPoint = this->mapToGlobal(QPoint(0, 0));
        int nXPos = globalPoint.x() + (this->width() - m_pCheckOrderGoodsDlg->width()) / 2;
        int nYPos = globalPoint.y() + (this->height() - m_pCheckOrderGoodsDlg->height()) / 2;
        m_pCheckOrderGoodsDlg->move(nXPos, nYPos);
        m_pCheckOrderGoodsDlg->initData(orderCardDetailInfoList, bUploadFinish, orderCardIdList, m_pOrderGoodsCheckCtrl);
        m_pCheckOrderGoodsDlg->exec();
    }
    else
    {
        QMessageBox::information(this, QStringLiteral("提示")
                                 , QString(QStringLiteral("出现异常--错误码:%1, 错误信息:%2")).arg(nCode).arg(sMsg));
    }
}

void CheckOrderWidget::slot_onUploadOrderCard(int nCode, QString sMsg, QList<int> orderCardIdList)
{
    if (nCode == e_success)
    {
        test();
    }
    else
    {
        QMessageBox::information(this, QStringLiteral("提示")
                                 , QString(QStringLiteral("出现异常--错误码:%1, 错误信息:%2")).arg(nCode).arg(sMsg));
    }
}

void CheckOrderWidget::slot_onRemoveOrderCard(int nCode, QString sMsg)
{
    if (nCode == e_success)
    {
        test();
    }
    else
    {
        QMessageBox::information(this, QStringLiteral("提示")
                                 , QString(QStringLiteral("出现异常--错误码:%1, 错误信息:%2")).arg(nCode).arg(sMsg));
    }
}

void CheckOrderWidget::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sigReturnClicked()) , this, SIGNAL(sigReturnClicked()));
    connect(ui->categoryDetailWidget, SIGNAL(sigSearchOrderCard(int)), this, SLOT(slot_searchOrderCard(int))); // 查看要货卡
    connect(ui->categoryDetailWidget, SIGNAL(sigEditOrderCard(QList<int>)), this, SLOT(slot_editOrderCard(QList<int>))); // 编辑要货卡
//    connect(ui->categoryDetailWidget, SIGNAL(sigCheckManyOrderCategoryDetailInfo(QList<int>)), this, SLOT(slot_checkManyOrderCategoryDetailInfo(QList<int>)));
    connect(ui->categoryDetailWidget, SIGNAL(sigUploadOrderCard(QList<int>)), this, SLOT(slot_uploadOrderCard(QList<int>))); // 上传要货卡
    connect(ui->categoryDetailWidget, SIGNAL(sigRemoveOrderCard(QList<int>)), this, SLOT(slot_removeOrderCard(QList<int>)));
    connect(ui->categoryDetailWidget, SIGNAL(sigAddCheckOrder()), this, SIGNAL(sigAddCheckOrder()));
    connect(ui->categoryWidget, SIGNAL(sigSelectAllCategory(bool)), this ,SLOT(slot_selectAllCategory(bool)));
    connect(ui->categoryWidget, SIGNAL(sigAddSelectCategory(int,bool)), this, SLOT(slot_addSelectCategory(int,bool)));
    connect(ui->categoryWidget, SIGNAL(sigSearch(QString,QString,QString)), this, SLOT(slot_searchDate(QString,QString,QString)));
}
