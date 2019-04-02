#include "OEditView.h"
#include "ui_OEditView.h"
#include "TipsDlg.h"
#include <QDebug>
#include <QMessageBox>
//#ifdef Q_OS_WIN
//#pragma execution_character_set("utf-8")
//#endif

OEditView::OEditView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OEditView)
  , m_pOutStockDlg(NULL)
  , m_pOutStockCtrl(NULL)
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

OEditView::~OEditView()
{
    delete ui;
}

void OEditView::setCategoryList(QList<CategoryInfo *> categoryInfoList)
{
    ui->categoryWidget->initData(categoryInfoList);
}

void OEditView::initSelectGoodsData(const QList<OutStockSelectGoodsInfo> &searchInfoList, int nOrderId)
{
    m_nOrderId = nOrderId;
    ui->goodsSelectWidget->initData(searchInfoList);
    if (searchInfoList.length() > 0)
    {
        ui->printBtn->setEnabled(true);
        ui->saveButton->setEnabled(true);
    }
}

void OEditView::initOutStockCtrl(OutStockCtrl *pOutStockCtrl)
{
    if (m_pOutStockCtrl == NULL)
    {
        m_pOutStockCtrl = pOutStockCtrl;
        connect(m_pOutStockCtrl, SIGNAL(sigOnSaveOutStockOrder(int,QString)), this, SLOT(slot_onSaveOutStockOrder(int,QString)));
    }
}

void OEditView::clearGoodsSelectWidgetData()
{
    ui->goodsSelectWidget->clearData();
    initButtons();
}

void OEditView::setOrderId(int nOrderId)
{
    m_nOrderId = nOrderId;
}

void OEditView::slot_clickCategoryItem(CategoryInfo categoryInfo)
{
    ui->goodsWidget->initData(categoryInfo.listGoodsInfo);
}

void OEditView::slot_clickGoodsItem(GoodsInfo goodsInfo)
{
    if (m_pOutStockDlg == NULL)
    {
        m_pOutStockDlg = new AddOutStkDlg;
        m_pOutStockDlg->setOutStockCtrl(m_pOutStockCtrl);
        connect(m_pOutStockDlg, SIGNAL(sigAddOutStockGoods(OutStockSelectGoodsInfo)) , this, SLOT(slot_addOutStockGoods(OutStockSelectGoodsInfo)));
    }

    OutStockSelectGoodsInfo outStockSelectGoodsInfo;
    bool bFind = ui->goodsSelectWidget->getSelectGoodsInfo(goodsInfo.nId, outStockSelectGoodsInfo);
    if (bFind)
    {
        outStockSelectGoodsInfo.sBelongCategory = goodsInfo.sCategoryName; // 所属大类
        outStockSelectGoodsInfo.fMarkNum = goodsInfo.fMarkNum; // 量比系数
        //        QString tmp=QString::number(outStockSelectGoodsInfo.fPackage);
        //        outStockSelectGoodsInfo.sBoxNum=tmp;
        //        m_pOutStockDlg->showModifyPage(outStockSelectGoodsInfo.fShouldCount,outStockSelectGoodsInfo.fShouldTotal,outStockSelectGoodsInfo.fBatchPrice,outStockSelectGoodsInfo.sBoxNum);
    }
    else
    {
        outStockSelectGoodsInfo.nId = goodsInfo.nId; // 商品id
        outStockSelectGoodsInfo.sName = goodsInfo.sName; // 商品名称
        outStockSelectGoodsInfo.sCode = goodsInfo.sCode; // 商品编码
        outStockSelectGoodsInfo.sBelongCategory = goodsInfo.sCategoryName; // 所属大类
        outStockSelectGoodsInfo.sBarCode = goodsInfo.sBarCode; // 商品条码/plu码
        outStockSelectGoodsInfo.sPinYinName = goodsInfo.sPinYinName; // 拼音助记码
        outStockSelectGoodsInfo.sWuBiName = goodsInfo.sWuBiName; // 五笔助记码
        outStockSelectGoodsInfo.fMarkNum = goodsInfo.fMarkNum; // 量比系数
        outStockSelectGoodsInfo.sWeighUnit = goodsInfo.sSpeUnit; // 要货规格单位
        outStockSelectGoodsInfo.sSellUnit = goodsInfo.sSaleUnit; // 销售单位
        outStockSelectGoodsInfo.bStandard = goodsInfo.bStandard;
        outStockSelectGoodsInfo.sBoxNum = "0.0"; // 变更入单数量数量
        outStockSelectGoodsInfo.fShouldCount = 0.0f; // 变更入单数量数量
        outStockSelectGoodsInfo.fShouldTotal = 0.0f; // 单品小计金额
        outStockSelectGoodsInfo.fBatchPrice = 0.0f; //最新批次进价
        outStockSelectGoodsInfo.fPackage = 0.0f; //最新批次进价
    }

    if (m_pOutStockCtrl != NULL)
    {
        m_pOutStockCtrl->getStockGoodsInfoRequest(outStockSelectGoodsInfo.nId);
    }

    m_pOutStockDlg->setGoodsInfo(outStockSelectGoodsInfo);
    m_pOutStockDlg->activateWindow();
    m_pOutStockDlg->exec();
}

void OEditView::on_deleteButton_clicked()
{
    ui->goodsSelectWidget->removeSelectItem();
    ui->deleteButton->setEnabled(false);
    ui->modifyButton->setEnabled(false);
    if (ui->goodsSelectWidget->getGoodsListLength() == 0)
    {
        ui->printBtn->setEnabled(false);
        ui->saveButton->setEnabled(false);
    }
}

void OEditView::on_modifyButton_clicked()
{
    OutStockSelectGoodsInfo selectGoodsInfo;
    bool bExist = ui->goodsSelectWidget->getSeletedItem(selectGoodsInfo);

    if (!bExist)
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("请点击选择要改价的商品！"));
        return;
    }

    int gid=selectGoodsInfo.nId;
    if (m_pOutStockDlg == NULL)
    {
        m_pOutStockDlg = new AddOutStkDlg;
        m_pOutStockDlg->setOutStockCtrl(m_pOutStockCtrl);
        connect(m_pOutStockDlg, SIGNAL(sigAddOutStockGoods(OutStockSelectGoodsInfo)), this, SLOT(slot_addOutStockGoods(OutStockSelectGoodsInfo)));
    }

    GoodsInfo goodsInfo;
    ui->categoryWidget->searchGood(goodsInfo,gid);
    selectGoodsInfo.sBelongCategory = goodsInfo.sCategoryName; // 所属大类
    selectGoodsInfo.fMarkNum = goodsInfo.fMarkNum; // 量比系数
    selectGoodsInfo.sSellUnit = goodsInfo.sSaleUnit; //销售单位
    //    QString tmp=QString::number(selectGoodsInfo.fPackage);
    //    selectGoodsInfo.sBoxNum=tmp;
    //    m_pOutStockDlg->showModifyPage(selectGoodsInfo.fShouldCount,selectGoodsInfo.fShouldTotal,selectGoodsInfo.fBatchPrice,selectGoodsInfo.sBoxNum);

    if (m_pOutStockCtrl != NULL)
    {
        m_pOutStockCtrl->getStockGoodsInfoRequest(selectGoodsInfo.nId);
    }

    m_pOutStockDlg->setGoodsInfo(selectGoodsInfo);
    m_pOutStockDlg->activateWindow();
    m_pOutStockDlg->exec();
}

void OEditView::on_printBtn_clicked()
{
    QList<OutStockSelectGoodsInfo> goodsInfoList;
    ui->goodsSelectWidget->getGoodsInfoList(goodsInfoList);
    emit sigPrintAll(goodsInfoList, m_nOrderId);
}

void OEditView::on_saveButton_clicked()
{
    if (m_pOutStockCtrl != NULL)
    {
        QList<OutStockSelectGoodsInfo> selectGoodsInfoList;
        ui->goodsSelectWidget->getGoodsInfoList(selectGoodsInfoList);
        m_pOutStockCtrl->saveOutStockOrderRequest(m_nOrderId, selectGoodsInfoList);
        TipsDlg::instance()->maskUI("服务器正在处理出库单修改请求，请耐心等候...");
    }
}

void OEditView::slot_onSaveOutStockOrder(int nCode, QString sMsg)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("出库单保存失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        TipsDlg::instance()->workDone();
        ui->saveButton->setEnabled(true);
        emit sigSaveOrderSuccess();//成功
    }
}

void OEditView::slot_searchChanged(QString sSearchText)
{
    QList<GoodsInfo> goodsInfoList;
    ui->categoryWidget->searchGoods(goodsInfoList, sSearchText);
    ui->goodsWidget->initData(goodsInfoList);
}

void OEditView::slot_addOutStockGoods(OutStockSelectGoodsInfo outStockSelectGoodsInfo)
{
    ui->goodsSelectWidget->appendData(outStockSelectGoodsInfo);
    ui->printBtn->setEnabled(true);
    ui->saveButton->setEnabled(true);
}

void OEditView::initConnect()
{
    m_pOutStockDlg = new AddOutStkDlg;
    m_pOutStockDlg->setOutStockCtrl(m_pOutStockCtrl);
    connect(m_pOutStockDlg, SIGNAL(sigAddOutStockGoods(OutStockSelectGoodsInfo)) , this, SLOT(slot_addOutStockGoods(OutStockSelectGoodsInfo)));

    qRegisterMetaType<CategoryInfo>("CategoryInfo");
    connect(ui->categoryWidget, SIGNAL(sigClickItem(CategoryInfo)), this, SLOT(slot_clickCategoryItem(CategoryInfo)));
    qRegisterMetaType<GoodsInfo>("GoodsInfo");
    connect(ui->goodsWidget, SIGNAL(sigClickItem(GoodsInfo)), this, SLOT(slot_clickGoodsItem(GoodsInfo)));
    qRegisterMetaType<OutStockSelectGoodsInfo>("OutStockSelectGoodsInfo");
    connect(ui->goodsSelectWidget, &OGoodsSelectWidget::sig_Focus,[=](){
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

void OEditView::initButtons()
{
    ui->deleteButton->setEnabled(false);
    ui->modifyButton->setEnabled(false);
    ui->printBtn->setEnabled(false);
    ui->saveButton->setEnabled(false);
}
