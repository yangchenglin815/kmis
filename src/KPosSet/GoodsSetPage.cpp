#include "GoodsSetPage.h"
#include "ui_GoodsSetPage.h"
#include "../KPosSet/AdjustPositionWidget.h"
#include "../util/GlobalSignal.h"
#include "AddGoodsToCustomCategoryWidget.h"
#include "CategoryInfoAgent.h"
#include <QList>
#include <QThread>
#include <QDebug>

GoodsSetPage::GoodsSetPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GoodsSetPage)
    , m_nCategoryOnePageCount(5)
    , m_nGoodsOnePageCount(25)
    , m_sSelectedCategoryKeyId("")
    , m_pAddCustomCategoryDlg(NULL)
    , m_pKPosSetCtrl(NULL)
{
    ui->setupUi(this);  
    ui->categoryWidget->setUpDownPageButton(ui->categoryFrontButton, ui->categoryNextButton);    
    ui->categoryWidget->setCategoryWidgetType( e_categorySet );
//    ui->categoryWidget->setColumn(m_nCategoryOnePageCount );

    ui->goodsWidget->setUpDownPageButton( ui->goodsFrontButton, ui->goodsNextButton );
    ui->goodsWidget->setColumn(m_nGoodsOnePageCount, e_goodsSet);
    initConnect();
}

GoodsSetPage::~GoodsSetPage()
{
    delete ui;
}

void GoodsSetPage::setCategoryInfoList(const QList<CategoryInfo*> &categoryInfoList)
{
    m_curGoodSet.bChanged = false;
    m_categoryInfoList = categoryInfoList;
    ui->categoryWidget->initData(m_categoryInfoList);
}

void GoodsSetPage::setKPosSetCtrl(KPosSetCtrl *pKPosSetCtrl)
{
    if (m_pKPosSetCtrl == NULL)
    {
        m_pKPosSetCtrl = pKPosSetCtrl;
        connect(m_pKPosSetCtrl, SIGNAL(sigOnAddCustomCategory(int,QString,int)), this, SLOT(slot_onAddCustomCategory(int,QString,int)));
    }
}

void GoodsSetPage::uploadData(KPosSet &stKPosSet)
{
    m_curGoodSet.categorySetList.clear();
    QList<CategoryInfo*>::iterator it = m_categoryInfoList.begin();
    for( ; it != m_categoryInfoList.end(); ++it ) {
        CategoryInfoSet stCategoryInfoSet;
        stCategoryInfoSet.nCategoryId = (*it)->nId;
        stCategoryInfoSet.sCategoryName = (*it)->sName;

        QList<GoodsInfo>::iterator itGoods = (*it)->listGoodsInfo.begin();
        for( ; itGoods != (*it)->listGoodsInfo.end(); ++itGoods ) {
            stCategoryInfoSet.goodsIdList.append( itGoods->nId );
        }
        stCategoryInfoSet.bCustom = (*it)->bCustom;
        m_curGoodSet.categorySetList.append( stCategoryInfoSet );
    }

    stKPosSet.goodSet = m_curGoodSet;
}

void GoodsSetPage::slot_getGoodsList(QString sCategoryKeyId)
{
    m_sSelectedCategoryKeyId = sCategoryKeyId;
    //通过分类id，获取该分类下所有的商品
    QList<GoodsInfo> goodsInfoList;
    getGoodsList(goodsInfoList, sCategoryKeyId);
    ui->goodsWidget->slot_addGoodsInfo(goodsInfoList);
}

void GoodsSetPage::slot_movePosition(int nNewPosition, int nOldPosition, int nOwnerType)
{
    if (nOwnerType == e_categorySet)
    {
//        qDebug()<<"newPosition:"<<nNewPosition<<";oldPosition"<<nOldPosition;
        int nLen = m_categoryInfoList.length();
        if (nNewPosition == nOldPosition || nOldPosition > nLen)
        {
            return;
        }
        if (nNewPosition <= 0)
        {
            nNewPosition = 1;
        }
        if (nNewPosition > nLen)
        {
            nNewPosition = nLen;
        }

        m_categoryInfoList.move(nOldPosition - 1, nNewPosition - 1);
        ui->categoryWidget->initData(m_categoryInfoList);
        m_curGoodSet.bChanged = true;
    }
    else if (nOwnerType == e_goodsSet)
    {
        if (m_sSelectedCategoryKeyId == "")
        {
            return;
        }
        qDebug()<<"newPosition:"<<nNewPosition<<";oldPosition"<<nOldPosition;
        QList<GoodsInfo> goodsInfoList;
        getGoodsList(goodsInfoList, m_sSelectedCategoryKeyId);
        int nLen = goodsInfoList.length();
        if (nNewPosition == nOldPosition || nOldPosition > nLen)
        {
            return;
        }
        if (nNewPosition <= 0)
        {
            nNewPosition = 1;
        }
        if (nNewPosition > nLen)
        {
            nNewPosition = nLen;
        }

        QList<CategoryInfo*>::iterator it = m_categoryInfoList.begin();
        QList<GoodsInfo>::iterator goodsInfoIter;
        for(; it != m_categoryInfoList.end(); it++) {
            if((*it)->sKeyId == m_sSelectedCategoryKeyId)
            {
                goodsInfoIter = (*it)->listGoodsInfo.begin();
                (*it)->listGoodsInfo.move(nOldPosition - 1, nNewPosition - 1);
            }
        }

        getGoodsList(goodsInfoList, m_sSelectedCategoryKeyId);
        ui->goodsWidget->initGoodsInfoList(goodsInfoList, nNewPosition);
        m_curGoodSet.bChanged = true;
    }
}

void GoodsSetPage::slot_categoryDbClicked(QString sCategoryKeyId)
{
    int nLen = m_categoryInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_categoryInfoList[i]->sKeyId == sCategoryKeyId && m_categoryInfoList[i]->bCustom)
        {
            AddGoodsToCustomCategoryWidget::instance()->setTitleText(m_categoryInfoList[i]->sName);
            AddGoodsToCustomCategoryWidget::instance()->initData(m_categoryInfoList, *m_categoryInfoList[i]);
            AddGoodsToCustomCategoryWidget::instance()->activateWindow();
            AddGoodsToCustomCategoryWidget::instance()->showNormal();
            break;
        }
    }
}

void GoodsSetPage::slot_saveGoodsIdList(QString sCategoryKeyId, QList<int> deletedList, QList<int> addedList)
{
    QString str;
    for (int i = 0; i < deletedList.length(); i++)
    {
        str.append(QString::number(deletedList[i])).append(",");
    }
    qDebug()<<"deletedList"<<str;

    str = "";
    for (int i = 0; i < addedList.length(); i++)
    {
        str.append(QString::number(addedList[i])).append(",");
    }
    qDebug()<<"addedList"<<str;


    QList<CategoryInfo*>::iterator it = m_categoryInfoList.begin();
    for( ; it != m_categoryInfoList.end(); ++it ) {
        if( (*it)->sKeyId == sCategoryKeyId )
        {
            for (int i = 0; i < deletedList.length(); i++)
            {
                int findGoodsId = deletedList[i];
                for (int j = 0; j < (*it)->listGoodsInfo.length(); j++)
                {
                    if ((*it)->listGoodsInfo[j].nId == findGoodsId)
                    {
                        qDebug()<<"slot_saveGoodsIdList--"<<findGoodsId;
                        (*it)->listGoodsInfo.removeAt(j);
                        break;
                    }
                }
            }

            for (int i = 0; i < addedList.length(); i++)
            {
                QMap<int, GoodsInfo_s> mapGoodsInfo;
                CategoryInfoAgent::instance()->getGoodsList(mapGoodsInfo);
                GoodsInfo_s  goodsInfo_s = mapGoodsInfo.value(addedList[i]);
                GoodsInfo goodsInfo;
                goodsInfo.nId = goodsInfo_s.nId;
                goodsInfo.sCode = goodsInfo_s.sCode;
                goodsInfo.sBarCode = goodsInfo_s.sBarCode;
                goodsInfo.sName = goodsInfo_s.sName;
                goodsInfo.sShortName = goodsInfo_s.sShortName;
//                goodsInfo.nCategoryId = goodsInfo_s.nCategoryId;
                goodsInfo.fPrice = goodsInfo_s.goodsPriceInfo.fPrice;
                goodsInfo.fMemberPrice = goodsInfo_s.goodsPriceInfo.fMemberPrice;
//                goodsInfo.nTasteType = goodsInfo_s.nTasteType;
                goodsInfo.bStandard = goodsInfo_s.bStandard;
                goodsInfo.sSaleUnit = goodsInfo_s.sSaleUnit;
//                goodsInfo.bAllowSell = goodsInfo_s.bAllowSell;
                (*it)->listGoodsInfo.append(goodsInfo);
            }

            AddGoodsToCustomCategoryWidget::instance()->initData(m_categoryInfoList, **it);
            break;
        }
    }
    m_curGoodSet.bChanged = true;
}

void GoodsSetPage::slot_addCategory(QString sCategoryName, int nPos )
{
    int nLen = m_categoryInfoList.length();
    CategoryInfo* pCategoryInfo = NULL;
    for (int i = 0; i < nLen; i++)
    {
        pCategoryInfo = m_categoryInfoList[i];
        if (pCategoryInfo->sName == sCategoryName)
        {
            if (m_pAddCustomCategoryDlg != NULL)
            {
                m_pAddCustomCategoryDlg->setHintText(QStringLiteral("添加分类名称不可重复！"));
                m_pAddCustomCategoryDlg->activateWindow();
                m_pAddCustomCategoryDlg->showNormal();
            }
            return;
        }
    }

    if (m_pAddCustomCategoryDlg != NULL)
    {
        m_pAddCustomCategoryDlg->setConfirmButtonEnable(false);
    }

    if (m_pKPosSetCtrl != NULL)
    {
        m_pKPosSetCtrl->addCustomCategoryRequest(sCategoryName, nPos);
    }
}

void GoodsSetPage::slot_deleteCategory( int nCategoryId )
{
    m_pKPosSetCtrl->delCustomCategoryRequest( nCategoryId );
}

void GoodsSetPage::on_newCategoryButton_clicked()
{
    if (m_pAddCustomCategoryDlg == NULL)
    {
        m_pAddCustomCategoryDlg = new AddCustomCategoryDlg;
        connect(m_pAddCustomCategoryDlg, SIGNAL(sigAddCategory(QString, int)), this, SLOT(slot_addCategory(QString,int)));
    }
    m_pAddCustomCategoryDlg->clearData();
    m_pAddCustomCategoryDlg->activateWindow();
    m_pAddCustomCategoryDlg->showNormal();
}

void GoodsSetPage::slot_onAddCustomCategory(int nCode, QString sMsg, int nCategoryId)
{
    Q_UNUSED( nCategoryId )

    if (m_pAddCustomCategoryDlg == NULL)
    {
        return;
    }

    if (nCode != e_success)
    {
        static int i = 1;
        m_pAddCustomCategoryDlg->setHintText(QStringLiteral("nCode:%1, sMsg:%2,失败第%1次！").arg(nCode).arg(sMsg).arg(i++));
    }
    else
    {
        m_pAddCustomCategoryDlg->setHintText(QStringLiteral("添加分类成功！"));
        qApp->processEvents();
        QThread::sleep(3);
        m_pAddCustomCategoryDlg->hide();
    }
    m_pAddCustomCategoryDlg->setConfirmButtonEnable(true);
}

void GoodsSetPage::initConnect()
{
    connect(ui->categoryWidget, SIGNAL(sig_getGoodsList(QString)), this, SLOT(slot_getGoodsList(QString)));
    connect(ui->categoryWidget, SIGNAL(sigItemDbClicked(QString)), this, SLOT(slot_categoryDbClicked(QString)));
    connect( ui->categoryWidget, SIGNAL(sigDeleteCategory(int)), this, SLOT( slot_deleteCategory(int)) );

    connect(AdjustPositionWidget::instance(), SIGNAL(sigMovePosition(int, int, int)),
            this, SLOT(slot_movePosition(int, int, int)));
    connect(AddGoodsToCustomCategoryWidget::instance(), SIGNAL(sigSaveGoodsIdList(QString, QList<int>, QList<int>)),
            this, SLOT(slot_saveGoodsIdList(QString, QList<int>, QList<int>)));
    connect(AddGoodsToCustomCategoryWidget::instance(), SIGNAL(sigUpdateCategoryGoods(QString)), this, SLOT(slot_getGoodsList(QString)));
}

void GoodsSetPage::getGoodsList(QList<GoodsInfo> &goodsInfoList, QString sCategoryKeyId)
{
    QList<CategoryInfo*>::iterator it = m_categoryInfoList.begin();
    for( ; it != m_categoryInfoList.end(); ++it ) {
        if( (*it)->sKeyId == sCategoryKeyId ) {
            goodsInfoList = (*it)->listGoodsInfo;
            break;
        }
    }
}


