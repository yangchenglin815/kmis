#include "AdjustPriceOrderCheckWidget.h"
#include "ui_AdjustPriceOrderCheckWidget.h"
#include <QMessageBox>
#include "TipsDlg.h"

AdjustPriceOrderCheckWidget::AdjustPriceOrderCheckWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdjustPriceOrderCheckWidget)
    , m_pAdjustPriceDlg(NULL)
    , m_pAdjustPriceCtrl(NULL)
    , m_nOrderId(-1)
{
    ui->setupUi(this);
    ui->categoryWidget->setUpDownPageButton(ui->categoryFrontButton, ui->categoryNextButton);
    ui->goodsWidget->setUpDownPageButton(ui->goodsFrontButton, ui->goodsNextButton);
    initButtons();
    initConnect();
}

AdjustPriceOrderCheckWidget::~AdjustPriceOrderCheckWidget()
{
    delete ui;
}

void AdjustPriceOrderCheckWidget::setCategoryList(QList<CategoryInfo *> categoryInfoList)
{
    ui->categoryWidget->initData(categoryInfoList);
}

void AdjustPriceOrderCheckWidget::initSelectGoodsData(const QList<AdjustPriceSelectGoodsInfo> &goodsInfoList, int nOrderId)
{
    m_nOrderId = nOrderId;
    ui->goodsSelectWidget->initData(goodsInfoList);
    if (goodsInfoList.length() > 0)
    {
        ui->printButton->setEnabled(true);
        ui->saveButton->setEnabled(true);
    }
}

void AdjustPriceOrderCheckWidget::initAdjustPriceCtrl(AdjustPriceCtrl *pAdjustPriceCtrl)
{
    if (m_pAdjustPriceCtrl == NULL)
    {
        m_pAdjustPriceCtrl = pAdjustPriceCtrl;
        connect(m_pAdjustPriceCtrl, SIGNAL(sigOnSaveAdjustPriceOrder(int,QString)), this, SLOT(slot_onSaveAdjustPriceOrder(int,QString)));
    }
}

void AdjustPriceOrderCheckWidget::clearGoodsSelectWidgetData()
{
    ui->goodsSelectWidget->clearData();
    initButtons();
}

void AdjustPriceOrderCheckWidget::setOrderId(int nOrderId)
{
    m_nOrderId = nOrderId;
}

void AdjustPriceOrderCheckWidget::slot_clickCategoryItem(CategoryInfo categoryInfo)
{
    ui->goodsWidget->initData(categoryInfo.listGoodsInfo);
}

void AdjustPriceOrderCheckWidget::slot_clickGoodsItem(GoodsInfo goodsInfo)
{
    AdjustPriceSelectGoodsInfo selectGoodsInfo;
    selectGoodsInfo.nId = goodsInfo.nId;
    selectGoodsInfo.sName = goodsInfo.sName; // 商品名称
    selectGoodsInfo.sCode = goodsInfo.sBarCode; // 商品条码
    selectGoodsInfo.sWeighUnit = goodsInfo.sSaleUnit; // 称量单位
    selectGoodsInfo.fOldPrice = goodsInfo.fPrice; // 原单价
    selectGoodsInfo.fNowPrice = 0.0f; // 现单价
    selectGoodsInfo.fOldMemberPrice = goodsInfo.fMemberPrice; // 原会员价
    selectGoodsInfo.fNowMemberPrice = 0.0f; // 现会员价
    selectGoodsInfo.sShortName = goodsInfo.sShortName;

    if (m_pAdjustPriceDlg == NULL)
    {
        m_pAdjustPriceDlg = new AdjustPriceDlg;
        qRegisterMetaType<AdjustPriceSelectGoodsInfo>("AdjustPriceSelectGoodsInfo");
        connect(m_pAdjustPriceDlg, SIGNAL(sigModifyGoodsPrice(AdjustPriceSelectGoodsInfo))
                , this, SLOT(slot_modifyGoodsPrice(AdjustPriceSelectGoodsInfo)));
    }
    m_pAdjustPriceDlg->setGoodsInfo(selectGoodsInfo);
    m_pAdjustPriceDlg->activateWindow();
    m_pAdjustPriceDlg->exec();
}

void AdjustPriceOrderCheckWidget::slot_clickGoodsSelectItem(AdjustPriceSelectGoodsInfo adjustPriceSelectGoodsInfo)
{
    Q_UNUSED( adjustPriceSelectGoodsInfo )

    ui->deleteButton->setEnabled(true);
    ui->modifyPriceButton->setEnabled(true);
}

void AdjustPriceOrderCheckWidget::on_deleteButton_clicked()
{
    ui->goodsSelectWidget->removeSelectItem();
    ui->deleteButton->setEnabled(false);
    ui->modifyPriceButton->setEnabled(false);
    if (ui->goodsSelectWidget->getGoodsListLength() == 0)
    {
        ui->printButton->setEnabled(false);
//        ui->saveButton->setEnabled(false);
    }
}

void AdjustPriceOrderCheckWidget::on_modifyPriceButton_clicked()
{
    AdjustPriceSelectGoodsInfo selectGoodsInfo;
    bool bExist = ui->goodsSelectWidget->getSeletedItem(selectGoodsInfo);
    if (!bExist)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("请点击选择要改价的商品！"));
        return;
    }

    if (m_pAdjustPriceDlg == NULL)
    {
        m_pAdjustPriceDlg = new AdjustPriceDlg;
        qRegisterMetaType<AdjustPriceSelectGoodsInfo>("AdjustPriceSelectGoodsInfo");
        connect(m_pAdjustPriceDlg, SIGNAL(sigModifyGoodsPrice(AdjustPriceSelectGoodsInfo))
                , this, SLOT(slot_modifyGoodsPrice(AdjustPriceSelectGoodsInfo)));
    }
    m_pAdjustPriceDlg->setGoodsInfo(selectGoodsInfo);
    m_pAdjustPriceDlg->activateWindow();
    m_pAdjustPriceDlg->exec();
}

void AdjustPriceOrderCheckWidget::on_printButton_clicked()
{
    QList<AdjustPriceSelectGoodsInfo> selectGoodsInfoList;
    ui->goodsSelectWidget->getGoodsInfoList(selectGoodsInfoList);
    emit sigPrintAdjustOrder(selectGoodsInfoList, m_nOrderId);
}

void AdjustPriceOrderCheckWidget::on_saveButton_clicked()
{
    if (m_pAdjustPriceCtrl != NULL)
    {
        QList<AdjustPriceSelectGoodsInfo> selectGoodsInfoList;
        ui->goodsSelectWidget->getGoodsInfoList(selectGoodsInfoList);
        m_pAdjustPriceCtrl->saveAdjustPriceOrder(m_nOrderId, selectGoodsInfoList);
    }
}

void AdjustPriceOrderCheckWidget::slot_modifyGoodsPrice(AdjustPriceSelectGoodsInfo goodsInfo)
{
    ui->goodsSelectWidget->appendData(goodsInfo);
    ui->printButton->setEnabled(true);
    ui->saveButton->setEnabled(true);
}

void AdjustPriceOrderCheckWidget::slot_onSaveAdjustPriceOrder(int nCode, QString sMsg)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("改价单保存失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        emit sigSaveOrderSuccess();
    }
}

void AdjustPriceOrderCheckWidget::slot_searchChanged(QString sSearchText)
{
    QList<GoodsInfo> goodsInfoList;
    ui->categoryWidget->searchGoods(goodsInfoList, sSearchText);
    ui->goodsWidget->initData(goodsInfoList);
}

void AdjustPriceOrderCheckWidget::initConnect()
{
    qRegisterMetaType<CategoryInfo>("CategoryInfo");
    connect(ui->categoryWidget, SIGNAL(sigClickItem(CategoryInfo)), this, SLOT(slot_clickCategoryItem(CategoryInfo)));
    qRegisterMetaType<GoodsInfo>("GoodsInfo");
    connect(ui->goodsWidget, SIGNAL(sigClickItem(GoodsInfo)), this, SLOT(slot_clickGoodsItem(GoodsInfo)));
    qRegisterMetaType<AdjustPriceSelectGoodsInfo>("AdjustPriceSelectGoodsInfo");
    connect(ui->goodsSelectWidget, SIGNAL(sigClickItem(AdjustPriceSelectGoodsInfo))
            , this, SLOT(slot_clickGoodsSelectItem(AdjustPriceSelectGoodsInfo)));
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
}

void AdjustPriceOrderCheckWidget::initButtons()
{
    ui->deleteButton->setEnabled(false);
    ui->modifyPriceButton->setEnabled(false);
    ui->printButton->setEnabled(false);
    ui->saveButton->setEnabled(false);
}
