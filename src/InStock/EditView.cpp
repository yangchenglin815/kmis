#include "EditView.h"
#include "ui_EditView.h"
#include "TipsDlg.h"
#include "HttpClient.h"
#include <QDebug>
#include <QMessageBox>

EditView::EditView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditView)
  , m_pInStockDlg(NULL)
  , m_pInStockCtrl(NULL)
  ,m_nOrderId(0)
{
    ui->setupUi(this);

    ui->categoryWidget->setUpDownPageButton(ui->categoryFrontButton, ui->categoryNextButton);
    ui->goodsWidget->setUpDownPageButton(ui->goodsFrontButton, ui->goodsNextButton);
    ui->categoryWidget->setUpDownPageButton(ui->categoryFrontButton, ui->categoryNextButton);
    ui->goodsWidget->setUpDownPageButton(ui->goodsFrontButton, ui->goodsNextButton);
    initButtons();
    initConnect();
}

EditView::~EditView()
{
    delete ui;
}

void EditView::setCategoryList(QList<CategoryInfo *> categoryInfoList)
{
    ui->categoryWidget->initData(categoryInfoList);
}

void EditView::initSelectGoodsData(const QList<InStockSelectGoodsInfo> &searchInfoList, int nOrderId)
{
    m_nOrderId = nOrderId;
    ui->goodsSelectWidget->initData(searchInfoList);
    if (searchInfoList.length() > 0)
    {
        ui->quickAddButton->setEnabled(true);
        ui->printBtn->setEnabled(true);
        ui->saveButton->setEnabled(true);
    }
}

void EditView::initInStockCtrl(InStockCtrl *pInStockCtrl)
{
    if (m_pInStockCtrl == NULL)
    {
        m_pInStockCtrl = pInStockCtrl;
        connect(m_pInStockCtrl, SIGNAL(sigOnSaveInStockOrder(int,QString)), this, SLOT(slot_onSaveInStockOrder(int,QString)));
    }
}

void EditView::clearGoodsSelectWidgetData()
{
    ui->goodsSelectWidget->clearData();
    initButtons();
}

void EditView::setOrderId(int nOrderId)
{
    m_nOrderId = nOrderId;
}

void EditView::slot_clickCategoryItem(CategoryInfo categoryInfo)
{
    ui->goodsWidget->initData(categoryInfo.listGoodsInfo);
}

void EditView::slot_clickGoodsItem(GoodsInfo goodsInfo)
{
    if (m_pInStockDlg == NULL)
    {
        m_pInStockDlg = new AddInStkDlg;
        m_pInStockDlg->setInStockCtrl(m_pInStockCtrl);
        connect(m_pInStockDlg, SIGNAL(sigAddInStockGoods(InStockSelectGoodsInfo)) , this, SLOT(slot_addInStockGoods(InStockSelectGoodsInfo)));
    }

    InStockSelectGoodsInfo inStockSelectGoodsInfo;
    bool bFind = ui->goodsSelectWidget->getSelectGoodsInfo(goodsInfo.nId, inStockSelectGoodsInfo);
    if (bFind)
    {
        inStockSelectGoodsInfo.sBelongCategory = goodsInfo.sCategoryName; // 所属大类
    }
    else
    {
        inStockSelectGoodsInfo.nId = goodsInfo.nId; // 商品id
        inStockSelectGoodsInfo.sName = goodsInfo.sName; // 商品名称
        inStockSelectGoodsInfo.sCode = goodsInfo.sCode; // 商品编码
        inStockSelectGoodsInfo.sBelongCategory = goodsInfo.sCategoryName; // 所属大类
        inStockSelectGoodsInfo.sBarCode = goodsInfo.sBarCode; // 商品条码/plu码
        inStockSelectGoodsInfo.sPinYinName = goodsInfo.sPinYinName; // 拼音助记码
        inStockSelectGoodsInfo.sWuBiName = goodsInfo.sWuBiName; // 五笔助记码
        inStockSelectGoodsInfo.sWeighUnit = goodsInfo.sSpeUnit; // 要货规格单位
        inStockSelectGoodsInfo.sSellUnit = goodsInfo.sSaleUnit; // 销售单位
        inStockSelectGoodsInfo.bStandard = goodsInfo.bStandard;
        inStockSelectGoodsInfo.sBoxNum = "0.0"; //件数
        inStockSelectGoodsInfo.fShouldCount = 0.0f; // 变更入单数量数量
        inStockSelectGoodsInfo.fShouldTotal = 0.0f; // 单品小计金额
        inStockSelectGoodsInfo.fBatchPrice = 0.0f; //最新批次进价
        inStockSelectGoodsInfo.fPackage = 0.0f; //最新批次进价
    }

    if (m_pInStockCtrl != NULL)
    {
        m_pInStockCtrl->getStockGoodsInfoRequest(inStockSelectGoodsInfo.nId);
    }

    m_pInStockDlg->setGoodsInfo(inStockSelectGoodsInfo);
    m_pInStockDlg->activateWindow();
    m_pInStockDlg->exec();
}

//void EditView::slot_clickGoodsSelectItem(InStockSelectGoodsInfo inStockOrderSearchInfo)
//{
//    Q_UNUSED(inStockOrderSearchInfo )

//}

void EditView::on_deleteButton_clicked()
{

    ui->goodsSelectWidget->removeSelectItem();
    ui->deleteButton->setEnabled(false);
    ui->modifyButton->setEnabled(false);
    if (ui->goodsSelectWidget->getGoodsListLength() == 0)
    {
        ui->quickAddButton->setEnabled(false);
        ui->printBtn->setEnabled(false);
        ui->saveButton->setEnabled(false);
    }
}

void EditView::on_modifyButton_clicked()
{

    if (m_pInStockDlg == NULL)
    {
        m_pInStockDlg = new AddInStkDlg;
        m_pInStockDlg->setInStockCtrl(m_pInStockCtrl);
        connect(m_pInStockDlg, SIGNAL(sigAddInStockGoods(InStockSelectGoodsInfo)) , this, SLOT(slot_addInStockGoods(InStockSelectGoodsInfo)));
    }

    InStockSelectGoodsInfo selectGoodsInfo;
    bool bExist = ui->goodsSelectWidget->getSeletedItem(selectGoodsInfo);
    if (!bExist)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("请点击选择要改价的商品！"));
        return;
    }

    int gid=selectGoodsInfo.nId;
    GoodsInfo goodsInfo;
    ui->categoryWidget->searchGood(goodsInfo,gid);
    selectGoodsInfo.sBelongCategory = goodsInfo.sCategoryName; // 所属大类
    selectGoodsInfo.sSellUnit = goodsInfo.sSaleUnit; //销售单位


    if (m_pInStockCtrl != NULL)
    {
        m_pInStockCtrl->getStockGoodsInfoRequest(selectGoodsInfo.nId);
    }
    m_pInStockDlg->setGoodsInfo(selectGoodsInfo);
    m_pInStockDlg->activateWindow();
    m_pInStockDlg->exec();
}

void EditView::on_printBtn_clicked()
{

    QList<InStockSelectGoodsInfo> goodsInfoList;
    ui->goodsSelectWidget->getGoodsInfoList(goodsInfoList);
    emit sigPrintAll(goodsInfoList, m_nOrderId);
}

void EditView::on_saveButton_clicked()
{


    if (m_pInStockCtrl != NULL)
    {
        QList<InStockSelectGoodsInfo> selectGoodsInfoList;
        ui->goodsSelectWidget->getGoodsInfoList(selectGoodsInfoList);
        m_pInStockCtrl->saveInStockOrderRequest(m_nOrderId, selectGoodsInfoList);
        TipsDlg::instance()->maskUI("服务器正在处理入库单修改请求，请耐心等候...");
    }
}

void EditView::slot_onSaveInStockOrder(int nCode, QString sMsg)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("入库单保存失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        TipsDlg::instance()->workDone();
        ui->saveButton->setEnabled(true);
        emit sigSaveOrderSuccess();//成功
    }
}

void EditView::slot_searchChanged(QString sSearchText)
{
    QList<GoodsInfo> goodsInfoList;
    ui->categoryWidget->searchGoods(goodsInfoList, sSearchText);
    ui->goodsWidget->initData(goodsInfoList);
}

void EditView::slot_addInStockGoods(InStockSelectGoodsInfo inStockSelectGoodsInfo)
{
    ui->goodsSelectWidget->appendData(inStockSelectGoodsInfo);
    ui->quickAddButton->setEnabled(true);
    ui->printBtn->setEnabled(true);
    ui->saveButton->setEnabled(true);
}


void EditView::on_quickAddButton_clicked()//以下快速建档
{
    emit sigAddQuickGoods();
}

void EditView::initConnect()
{
    m_pInStockDlg = new AddInStkDlg;
    m_pInStockDlg->setInStockCtrl(m_pInStockCtrl);
    connect(m_pInStockDlg, SIGNAL(sigAddInStockGoods(InStockSelectGoodsInfo)), this, SLOT(slot_addInStockGoods(InStockSelectGoodsInfo)));
    qRegisterMetaType<CategoryInfo>("CategoryInfo");
    connect(ui->categoryWidget, SIGNAL(sigClickItem(CategoryInfo)), this, SLOT(slot_clickCategoryItem(CategoryInfo)));
    qRegisterMetaType<GoodsInfo>("GoodsInfo");
    connect(ui->goodsWidget, SIGNAL(sigClickItem(GoodsInfo)), this, SLOT(slot_clickGoodsItem(GoodsInfo)));
    qRegisterMetaType<InStockSelectGoodsInfo>("InStockSelectGoodsInfo");
    connect(ui->goodsSelectWidget, &GoodsSelectWidget::sig_Focus,[=](){
        ui->deleteButton->setEnabled(true);
        ui->modifyButton->setEnabled(true);
    });
    connect(TipsDlg::instance(),&TipsDlg::sig_releaseCtrl,[=](){
        ui->saveButton->setEnabled(true);
    });
    connect(TipsDlg::instance(),&TipsDlg::sig_masked,[=](){
        ui->saveButton->setEnabled(false);
    });
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));

}

void EditView::initButtons()
{
    ui->deleteButton->setEnabled(false);
    ui->modifyButton->setEnabled(false);
    ui->quickAddButton->setEnabled(true);
    ui->printBtn->setEnabled(false);
    ui->saveButton->setEnabled(false);
}
