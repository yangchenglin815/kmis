#include "StockOrderCheckWidget.h"
#include "ui_StockOrderCheckWidget.h"
#include <QMessageBox>
#include "TipsDlg.h"

StockOrderCheckWidget::StockOrderCheckWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StockOrderCheckWidget)
    , m_pStockDlg(NULL)
    , m_pStockCtrl(NULL)
{
    ui->setupUi(this);
    ui->categoryWidget->setUpDownPageButton(ui->categoryFrontButton, ui->categoryNextButton);
    ui->goodsWidget->setUpDownPageButton(ui->goodsFrontButton, ui->goodsNextButton);
    initButtons();
    initConnect();
}

StockOrderCheckWidget::~StockOrderCheckWidget()
{
    delete ui;
}

void StockOrderCheckWidget::setCategoryList(QList<CategoryInfo *> categoryInfoList)
{
    ui->categoryWidget->initData(categoryInfoList);
}

void StockOrderCheckWidget::initSelectGoodsData(const QList<StockSelectGoodsInfo> &searchInfoList, int nOrderId)
{
    m_nOrderId = nOrderId;
    ui->goodsSelectWidget->initData(searchInfoList);
    if (searchInfoList.length() > 0)
    {
        ui->printAllButton->setEnabled(true);
        ui->printAddedButton->setEnabled(true);
        ui->saveButton->setEnabled(true);
    }
}

void StockOrderCheckWidget::initStockCtrl(StockCtrl *pStockCtrl)
{
    if (m_pStockCtrl == NULL)
    {
        m_pStockCtrl = pStockCtrl;
        connect(m_pStockCtrl, SIGNAL(sigOnSaveStockOrder(int,QString)), this, SLOT(slot_onSaveStockOrder(int,QString)));
    }
}

void StockOrderCheckWidget::clearGoodsSelectWidgetData()
{
    ui->goodsSelectWidget->clearData();
    initButtons();
}

void StockOrderCheckWidget::setOrderId(int nOrderId)
{
    m_nOrderId = nOrderId;
}

void StockOrderCheckWidget::slot_clickCategoryItem(CategoryInfo categoryInfo)
{
    ui->goodsWidget->initData(categoryInfo.listGoodsInfo);
}

void StockOrderCheckWidget::slot_clickGoodsItem(GoodsInfo goodsInfo)
{
    if (m_pStockDlg == NULL)
    {
        m_pStockDlg = new StockDlg;
        m_pStockDlg->setStockCtrl(m_pStockCtrl);
        connect(m_pStockDlg, SIGNAL(sigAddStockGoods(StockSelectGoodsInfo)) , this, SLOT(slot_addStockGoods(StockSelectGoodsInfo)));
    }
    StockSelectGoodsInfo stockSelectGoodsInfo;
    bool bFind = ui->goodsSelectWidget->getSelectGoodsInfo(goodsInfo.nId, stockSelectGoodsInfo);
    if (bFind)
    {
        m_pStockDlg->showModifyPage(stockSelectGoodsInfo.fShouldStockNum, stockSelectGoodsInfo.fRealStockNum);
    }
    else
    {
        stockSelectGoodsInfo.nId = goodsInfo.nId; // 商品id
        stockSelectGoodsInfo.sName = goodsInfo.sName; // 商品名称
        stockSelectGoodsInfo.sCode = goodsInfo.sCode; // 商品编码
        stockSelectGoodsInfo.sBelongCategory = "无无"; // 所属分类
        stockSelectGoodsInfo.sBarCode = goodsInfo.sBarCode; // 商品条码/plu码
        stockSelectGoodsInfo.sShortName = goodsInfo.sShortName; // 商品简称
        stockSelectGoodsInfo.sPinYinName = goodsInfo.sPinYinName; // 拼音助记码
        stockSelectGoodsInfo.sWuBiName = goodsInfo.sWuBiName; // 五笔助记码
        stockSelectGoodsInfo.sWeighUnit = goodsInfo.sSaleUnit; // 称重单位
        stockSelectGoodsInfo.bStandard = goodsInfo.bStandard;
        stockSelectGoodsInfo.fShouldStockNum = 0.0f; // 账盘数量
        stockSelectGoodsInfo.fRealStockNum = 0.0f; // 实盘数量
        stockSelectGoodsInfo.fStockDifferNum = 0.0f; // 差异数量
        stockSelectGoodsInfo.fBuyDifferPrice = 0.0f; // 进价差异金额
        stockSelectGoodsInfo.nBatchId = -1; // 最新批次ID
        stockSelectGoodsInfo.fBatchPrice = 0.0f; //最新批次进价
        m_pStockDlg->showAddPage();
    }

    if (m_pStockCtrl != NULL)
    {
        m_pStockCtrl->getStockGoodsInfoRequest(stockSelectGoodsInfo.nId);
    }

    m_pStockDlg->setGoodsInfo(stockSelectGoodsInfo);
    m_pStockDlg->activateWindow();
    m_pStockDlg->exec();
}

void StockOrderCheckWidget::slot_clickGoodsSelectItem(StockSelectGoodsInfo stockOrderSearchInfo)
{
    Q_UNUSED( stockOrderSearchInfo )

    ui->deleteButton->setEnabled(true);
    ui->modifyNumButton->setEnabled(true);
}

void StockOrderCheckWidget::on_deleteButton_clicked()
{
    ui->goodsSelectWidget->removeSelectItem();
    ui->deleteButton->setEnabled(false);
    ui->modifyNumButton->setEnabled(false);
    if (ui->goodsSelectWidget->getGoodsListLength() == 0)
    {
        ui->printAllButton->setEnabled(false);
        ui->printAddedButton->setEnabled(false);
        ui->saveButton->setEnabled(false);
    }
}

void StockOrderCheckWidget::on_modifyNumButton_clicked()
{
    StockSelectGoodsInfo selectGoodsInfo;
    bool bExist = ui->goodsSelectWidget->getSeletedItem(selectGoodsInfo);
    if (!bExist)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("请点击选择要改价的商品！"));
        return;
    }
    if (m_pStockDlg == NULL)
    {
        m_pStockDlg = new StockDlg;
        m_pStockDlg->setStockCtrl(m_pStockCtrl);
        connect(m_pStockDlg, SIGNAL(sigAddStockGoods(StockSelectGoodsInfo)), this, SLOT(slot_addStockGoods(StockSelectGoodsInfo)));
    }

    m_pStockDlg->showModifyPage(selectGoodsInfo.fShouldStockNum, selectGoodsInfo.fRealStockNum);
    if (m_pStockCtrl != NULL)
    {
        m_pStockCtrl->getStockGoodsInfoRequest(selectGoodsInfo.nId);
    }

    m_pStockDlg->setGoodsInfo(selectGoodsInfo);
    m_pStockDlg->activateWindow();
    m_pStockDlg->exec();
}

void StockOrderCheckWidget::on_printAllButton_clicked()
{
    QList<StockSelectGoodsInfo> goodsInfoList;
    ui->goodsSelectWidget->getGoodsInfoList(goodsInfoList);
    emit sigPrintAll(goodsInfoList, m_nOrderId);
}

void StockOrderCheckWidget::on_printAddedButton_clicked()
{
    QList<StockSelectGoodsInfo> addedGoodsList;
    QList<StockSelectGoodsInfo> removedGoodsList;
    QList<StockSelectGoodsInfo> updatedGoodsList;
    ui->goodsSelectWidget->getAddedGoods(addedGoodsList);
    ui->goodsSelectWidget->getRemovedGoods(removedGoodsList);
    ui->goodsSelectWidget->getUpdatedGoods(updatedGoodsList);
    emit sigPrintAdded(addedGoodsList, removedGoodsList, updatedGoodsList, m_nOrderId);
}

void StockOrderCheckWidget::on_saveButton_clicked()
{
    if (m_pStockCtrl != NULL)
    {
        QList<StockSelectGoodsInfo> selectGoodsInfoList;
        ui->goodsSelectWidget->getGoodsInfoList(selectGoodsInfoList);
        m_pStockCtrl->saveStockOrderRequest(m_nOrderId, selectGoodsInfoList);
    }
}

void StockOrderCheckWidget::slot_onSaveStockOrder(int nCode, QString sMsg)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("盘点单保存失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        emit sigSaveOrderSuccess();
    }
}

void StockOrderCheckWidget::slot_searchChanged(QString sSearchText)
{
    QList<GoodsInfo> goodsInfoList;
    ui->categoryWidget->searchGoods(goodsInfoList, sSearchText);
    ui->goodsWidget->initData(goodsInfoList);
}

void StockOrderCheckWidget::slot_addStockGoods(StockSelectGoodsInfo stockSelectGoodsInfo)
{
    ui->goodsSelectWidget->appendData(stockSelectGoodsInfo);
    ui->printAllButton->setEnabled(true);
    ui->printAddedButton->setEnabled(true);
    ui->saveButton->setEnabled(true);
}

void StockOrderCheckWidget::initConnect()
{
    qRegisterMetaType<CategoryInfo>("CategoryInfo");
    connect(ui->categoryWidget, SIGNAL(sigClickItem(CategoryInfo)), this, SLOT(slot_clickCategoryItem(CategoryInfo)));
    qRegisterMetaType<GoodsInfo>("GoodsInfo");
    connect(ui->goodsWidget, SIGNAL(sigClickItem(GoodsInfo)), this, SLOT(slot_clickGoodsItem(GoodsInfo)));
    qRegisterMetaType<StockSelectGoodsInfo>("StockSelectGoodsInfo");
    connect(ui->goodsSelectWidget, SIGNAL(sigClickItem(StockSelectGoodsInfo))
            , this, SLOT(slot_clickGoodsSelectItem(StockSelectGoodsInfo)));
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
}

void StockOrderCheckWidget::initButtons()
{
    ui->deleteButton->setEnabled(false);
    ui->modifyNumButton->setEnabled(false);
    ui->printAllButton->setEnabled(false);
    ui->printAddedButton->setEnabled(false);
    ui->saveButton->setEnabled(false);
}
