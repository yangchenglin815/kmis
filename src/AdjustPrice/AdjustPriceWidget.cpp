#include "AdjustPriceWidget.h"
#include "ui_AdjustPriceWidget.h"
#include <QMessageBox>
#include "TipsDlg.h"

AdjustPriceWidget::AdjustPriceWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdjustPriceWidget)
    , m_pAdjustPriceCtrl(NULL)
{
    ui->setupUi(this);
    initConnect();
    init();
}

AdjustPriceWidget::~AdjustPriceWidget()
{
    delete ui;
}

void AdjustPriceWidget::test()
{
    if (m_pAdjustPriceCtrl == NULL)
    {
        m_pAdjustPriceCtrl = new AdjustPriceCtrl(this);
        qRegisterMetaType<QList<AdjustPriceOrderSearchInfo> >("QList<AdjustPriceOrderSearchInfo>");
        connect(m_pAdjustPriceCtrl, SIGNAL(sigOnSearchAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>))
                , this, SLOT(slot_onSearchAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>)));
        connect(m_pAdjustPriceCtrl, SIGNAL(sigOnEditAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>,int))
                , this, SLOT(slot_onEditAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>,int)));
        ui->adjustPriceOrderPage->initAdjustPriceCtrl(m_pAdjustPriceCtrl);
        ui->adjustPriceOrderCheckPage->initAdjustPriceCtrl(m_pAdjustPriceCtrl);
    }
    ui->adjustPriceOrderPage->getAdjustPriceOrderListRequest();
}

void AdjustPriceWidget::setCategoryList(QList<CategoryInfo *> categoryInfoList)
{
    ui->adjustPriceOrderCheckPage->setCategoryList(categoryInfoList);
}

void AdjustPriceWidget::slot_returnClicked()
{
    if (ui->stackedWidget->currentWidget() == ui->adjustPriceOrderPage)
    {
        ui->adjustPriceOrderPage->hideCalendarWidget();
        emit sigReturnClicked();
    }
    else
    {
        ui->stackedWidget->setCurrentWidget(ui->adjustPriceOrderPage);
    }
}

void AdjustPriceWidget::slot_addAdjustOrder()
{
    ui->adjustPriceOrderCheckPage->setOrderId(-1);
    ui->stackedWidget->setCurrentWidget(ui->adjustPriceOrderCheckPage);
}

void AdjustPriceWidget::slot_onSearchAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> searchInfoList)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("改价单查看失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        ui->adjustPriceOrderSearchPage->initData(searchInfoList);
        ui->stackedWidget->setCurrentWidget(ui->adjustPriceOrderSearchPage);
    }
}

void AdjustPriceWidget::slot_onEditAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> searchInfoList, int nOrderId)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("改价单查看失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        ui->adjustPriceOrderCheckPage->initSelectGoodsData(searchInfoList, nOrderId);
        ui->stackedWidget->setCurrentWidget(ui->adjustPriceOrderCheckPage);
    }
}

void AdjustPriceWidget::slot_updateOrder()
{
    ui->adjustPriceOrderCheckPage->clearGoodsSelectWidgetData();
    ui->stackedWidget->setCurrentWidget(ui->adjustPriceOrderPage);
    test();
}

void AdjustPriceWidget::slot_checkAdjustSuccess()
{
    slot_updateOrder();
    if (m_pAdjustPriceCtrl != NULL)
    {
        m_pAdjustPriceCtrl->startUpdateThread();
    }
}

void AdjustPriceWidget::slot_printAdjustOrder(QList<AdjustPriceSelectGoodsInfo> goodsInfoList, int nOrderId)
{
    ui->adjustPriceOrderPage->printAdjustOrder(goodsInfoList, nOrderId);
}

void AdjustPriceWidget::init()
{
    ui->stackedWidget->setCurrentWidget(ui->adjustPriceOrderPage);
}

void AdjustPriceWidget::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sigReturnClicked()), this, SLOT(slot_returnClicked()));
    connect(ui->adjustPriceOrderPage, SIGNAL(sigAddAdjustOrder()), this, SLOT(slot_addAdjustOrder()));
    connect(ui->adjustPriceOrderPage, SIGNAL(sigCheckAdjustSuccess()), this, SLOT(slot_checkAdjustSuccess()));
    connect(ui->adjustPriceOrderCheckPage, SIGNAL(sigSaveOrderSuccess()), this, SLOT(slot_updateOrder()));
    connect(ui->adjustPriceOrderCheckPage, SIGNAL(sigPrintAdjustOrder(QList<AdjustPriceSelectGoodsInfo>, int))
            , this, SLOT(slot_printAdjustOrder(QList<AdjustPriceSelectGoodsInfo>, int)));
}
