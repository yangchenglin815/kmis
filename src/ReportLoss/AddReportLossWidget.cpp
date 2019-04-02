#include "AddReportLossWidget.h"
#include "ui_AddReportLossWidget.h"
#include "TipsDlg.h"

AddReportLossWidget::AddReportLossWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddReportLossWidget)
  , addLossDlg(NULL)
  , m_nOrderId(-1)
  , m_reportLossCtrl(NULL)
  , dlgMode(-1)
  , getDlgMode(-1)
{
    ui->setupUi(this);
    ui->categoryWidget->setUpDownPageButton(ui->categoryFrontButton, ui->categoryNextButton);
    ui->goodsWidget->setUpDownPageButton(ui->goodsFrontButton, ui->goodsNextButton);
    init();
    initButton();
    initconnect();
}

AddReportLossWidget::~AddReportLossWidget()
{
    delete ui;
}

void AddReportLossWidget::setCategoryList(QList<CategoryInfo *> categoryInfoList)
{
    for(int i=0; i<categoryInfoList.length(); i++){
       listGoodsInfo += categoryInfoList[i]->listGoodsInfo;
    }
    ui->categoryWidget->initData(categoryInfoList);
}

void AddReportLossWidget::initReportLossCtrl(ReportLossCtrl *reportLossCtrl)
{
    if(m_reportLossCtrl == NULL){
        m_reportLossCtrl = reportLossCtrl;
        qRegisterMetaType<QList<AddReportLossSelectInfo>>("QList<AddReportLossSelectInfo>");
        connect(m_reportLossCtrl, SIGNAL(sigAddReportLossOrderList(int,QString))
                , this, SLOT(slot_addReportLossOrderList(int,QString)));
        connect(m_reportLossCtrl, SIGNAL(sigOnGetEditReportLossDetialOrder(int,QString,QList<AddReportLossSelectInfo>,int))
                , this, SLOT(slot_getEditReportLossDetialOrder(int,QString,QList<AddReportLossSelectInfo>,int)));
        connect(m_reportLossCtrl, SIGNAL(sigEditReportLossOrderList(int,QString))
                , this, SLOT(slot_editReportLossOrder(int,QString)));
    }
}

void AddReportLossWidget::showEvent(QShowEvent *)
{
    QPoint globalPoint = ui->topWidget->mapToGlobal(QPoint(0, 0));
    const int nOffx = 11;
    int nXPos = globalPoint.x() - nOffx;
    int nYPos = globalPoint.y() + ui->searchWidget->height();
    ui->searchWidget->setKeyboardPos(nXPos, nYPos);
}

void AddReportLossWidget::slot_searchChanged(QString str)
{
    QList<GoodsInfo> goodsInfoList;
    ui->categoryWidget->searchGoods(goodsInfoList, str);
    ui->goodsWidget->initData(goodsInfoList);
}

void AddReportLossWidget::slot_getSendDlgMode(int mode)
{
    getDlgMode = mode;
}

void AddReportLossWidget::slot_editReportLossOrder(int nCode, QString sMsg)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("编辑报损单保存失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        TipsDlg::instance()->workDone();
        ui->saveButton->setEnabled(true);
        emit sigSaveOrderSuccess();//成功
    }
}

void AddReportLossWidget::slot_getEditReportLossDetialOrder(int nCode, QString sMsg, QList<AddReportLossSelectInfo> infoList, int selectId)
{
    m_nOrderId = selectId;
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("获取报损单详情失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        ui->listWidget->initData(infoList);
        if(infoList.length()>0){
            ui->printButton->setEnabled(true);
        }
    }
}

void AddReportLossWidget::slot_clickItem(AddReportLossSelectInfo selectInfo)
{
    Q_UNUSED(selectInfo)
    ui->deleteButton->setEnabled(true);
    ui->modeifyNoButton->setEnabled(true);
}

void AddReportLossWidget::slot_addReportLossOrderList(int nCode, QString sMsg)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("报损单保存失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        TipsDlg::instance()->workDone();
        ui->saveButton->setEnabled(true);
        emit sigSaveOrderSuccess();//成功
    }
}

void AddReportLossWidget::slot_ModifyLossNumber(AddReportLossSelectInfo lossInfo)
{
    AddReportLossSelectInfo oldLossInfo;
    bool flag = ui->listWidget->getSelectGoodsInfo(lossInfo.id, oldLossInfo);
    if(flag && oldLossInfo.sReason == lossInfo.sReason && getDlgMode == 1){
        lossInfo.sMoney += oldLossInfo.sMoney;
        lossInfo.sNumber += oldLossInfo.sNumber;
    }
    ui->listWidget->appendData(lossInfo);
    ui->printButton->setEnabled(true);
    ui->saveButton->setEnabled(true);
}

void AddReportLossWidget::slot_clickGoodsItem(GoodsInfo goodsInfo)
{
    if (addLossDlg == NULL)
    {
        addLossDlg = new AddReportLossDlg;
        connect(addLossDlg, SIGNAL(sigModifyLossNumber(AddReportLossSelectInfo)), this, SLOT(slot_ModifyLossNumber(AddReportLossSelectInfo)));
        connect(addLossDlg, SIGNAL(sigSendDlgMode(int)), this, SLOT(slot_getSendDlgMode(int)));
    }

    AddReportLossSelectInfo SelectGoodsInfo;
    bool bFind = ui->listWidget->getSelectGoodsInfo(goodsInfo.nId, SelectGoodsInfo);
    if (bFind)
    {
        SelectGoodsInfo.sCategoryName = goodsInfo.sCategoryName; // 所属大类
        SelectGoodsInfo.fMarkNum = goodsInfo.fMarkNum; // 量比系数
        SelectGoodsInfo.fPrice = goodsInfo.fPrice;
        SelectGoodsInfo.nId = -1;
        SelectGoodsInfo.sNumber = 0.0f;
        SelectGoodsInfo.goodsId = 0;
    }
    else
    {
        SelectGoodsInfo.id = goodsInfo.nId; // 商品id
        SelectGoodsInfo.sName = goodsInfo.sName; // 商品名称
        SelectGoodsInfo.sCode = goodsInfo.sCode; // 商品编码
        SelectGoodsInfo.sCategoryName = goodsInfo.sCategoryName; // 所属大类
        SelectGoodsInfo.fMarkNum = goodsInfo.fMarkNum; // 量比系数
        SelectGoodsInfo.sUnit = goodsInfo.sSaleUnit; // 销售单位
        SelectGoodsInfo.fPrice = goodsInfo.fPrice;
        SelectGoodsInfo.sMoney = 0.0f;
        SelectGoodsInfo.sNumber = 0.0f;
        SelectGoodsInfo.sReason = 0;
        SelectGoodsInfo.nId = -1;
        SelectGoodsInfo.goodsId = 0;
    }
    addLossDlg->initMode(1);
    addLossDlg->setGoodsInfo(SelectGoodsInfo);
    addLossDlg->activateWindow();
    addLossDlg->exec();
}

void AddReportLossWidget::slot_clickCategoryItem(CategoryInfo categoryInfo)
{
     ui->goodsWidget->initData(categoryInfo.listGoodsInfo);
}

void AddReportLossWidget::init()
{
//    QList<CategoryInfo*> categoryInfoList;
//    CategoryInfo *info = NULL;
//    int nLen = 10;
//    for(int i=0; i<nLen; i++){
//         info = new CategoryInfo;
//         info->nId = i+1;
//         info->sName = "苹果";
//         info->bCustom = false;
//         categoryInfoList.append(info);
//    }
//    ui->categoryWidget->initData(categoryInfoList);
}

void AddReportLossWidget::initconnect()
{
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
    qRegisterMetaType<CategoryInfo>("CategoryInfo");
    connect(ui->categoryWidget, SIGNAL(sigClickItem(CategoryInfo)), this, SLOT(slot_clickCategoryItem(CategoryInfo)));
    qRegisterMetaType<GoodsInfo>("GoodsInfo");
    connect(ui->goodsWidget, SIGNAL(sigClickItem(GoodsInfo)), this, SLOT(slot_clickGoodsItem(GoodsInfo)));
    qRegisterMetaType<AddReportLossSelectInfo>("AddReportLossSelectInfo");
    connect(ui->listWidget, SIGNAL(sigClickItem(AddReportLossSelectInfo)), this, SLOT(slot_clickItem(AddReportLossSelectInfo)));
    connect(ui->listWidget, &AddReportLossSelectWidget::sig_Focus,[=](){
        ui->deleteButton->setEnabled(true);
        ui->modeifyNoButton->setEnabled(true);
    });
    connect(TipsDlg::instance(),&TipsDlg::sig_releaseCtrl,[=](){
        ui->saveButton->setEnabled(true);
    });
    connect(TipsDlg::instance(),&TipsDlg::sig_masked,[=](){
        ui->saveButton->setEnabled(false);
    });
}

void AddReportLossWidget::initButton()
{
    ui->saveButton->setEnabled(false);
    ui->printButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    ui->modeifyNoButton->setEnabled(false);
}

void AddReportLossWidget::on_deleteButton_clicked()
{
    ui->listWidget->removeSelectItem();
    if (ui->listWidget->getGoodsListLength() == 0)
    {
        ui->printButton->setEnabled(false);
        ui->saveButton->setEnabled(false);
        ui->deleteButton->setEnabled(false);
        ui->modeifyNoButton->setEnabled(false);
    }
    else
    {
        ui->saveButton->setEnabled(true);
        ui->deleteButton->setEnabled(true);
        ui->modeifyNoButton->setEnabled(true);
        ui->printButton->setEnabled(true);
    }
}

void AddReportLossWidget::initSelectGoodsData(const QList<AddReportLossSelectInfo> &searchInfoList, int nOrderId)
{
    m_nOrderId = nOrderId;
    ui->listWidget->initData(searchInfoList);
    if (searchInfoList.length() > 0)
    {
        ui->printButton->setEnabled(true);
        ui->saveButton->setEnabled(true);
    }
}

void AddReportLossWidget::initMode(int mode)
{
    dlgMode = mode;
}

float AddReportLossWidget::getGoodsPrice(const AddReportLossSelectInfo &lossInfo)
{
    int nLen = listGoodsInfo.length();
    for(int i=0; i<nLen; i++){
        if(listGoodsInfo[i].nId == lossInfo.id){
            return listGoodsInfo[i].fPrice;
        }
    }
    return 0;
}

void AddReportLossWidget::initEditPage()
{
    QList<AddReportLossSelectInfo> infoList;
    ui->listWidget->initData(infoList);
}

void AddReportLossWidget::on_modeifyNoButton_clicked()
{
    AddReportLossSelectInfo lossInfo;
    bool bExist = ui->listWidget->getSeletedItem(lossInfo);
    if (!bExist)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("请点击选择要修改报损数量的商品！"));
        return;
    }
    if(addLossDlg == NULL){
        addLossDlg = new AddReportLossDlg;
        connect(addLossDlg, SIGNAL(sigModifyLossNumber(AddReportLossSelectInfo)), this, SLOT(slot_ModifyLossNumber(AddReportLossSelectInfo)));
    }
    addLossDlg->initMode(2);
    float price = getGoodsPrice(lossInfo);
    if(price > 0){
        lossInfo.fPrice = price;
        addLossDlg->setGoodsInfo(lossInfo);
        addLossDlg->activateWindow();
        addLossDlg->exec();
    }
    else
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("没有找到商品的单价！"));
        return;
    }
}

void AddReportLossWidget::on_printButton_clicked()
{
   QList<AddReportLossSelectInfo> selectInfoList;
   ui->listWidget->getGoodsInfoList(selectInfoList);
   emit sigPrintReportLossOrder(selectInfoList, m_nOrderId);
}

void AddReportLossWidget::on_saveButton_clicked()
{
    if (m_reportLossCtrl != NULL)
    {
        QList<AddReportLossSelectInfo> selectGoodsInfoList;
        ui->listWidget->getGoodsInfoList(selectGoodsInfoList);
        if(dlgMode == 1){
            m_reportLossCtrl->AddReportLossListRequest(selectGoodsInfoList);
        }
        else if(dlgMode == 2){
            m_reportLossCtrl->editReportLossListRequest(selectGoodsInfoList, m_nOrderId);
        }
        TipsDlg::instance()->maskUI("服务器正在处理请求，请耐心等候...");
    }
}
