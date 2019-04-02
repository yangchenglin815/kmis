#include "InStockWid.h"
#include "ui_InStockWid.h"

#include <QDebug>
#include <QMessageBox>
#include "TipsDlg.h"

//#ifdef Q_OS_WIN
//#pragma execution_character_set("utf-8")

//#endif

InStockWid::InStockWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InStockWid)
  , m_pInStockCtrl(NULL)
{
    ui->setupUi(this);
    initConnect();
    init();
}

InStockWid::~InStockWid()
{
    delete ui;
}

void InStockWid::test()
{
    if (m_pInStockCtrl == NULL)
    {
        m_pInStockCtrl = new InStockCtrl;
        qRegisterMetaType<QList<InStockOrderSearchInfo> >("QList<InStockOrderSearchInfo>");
        connect(m_pInStockCtrl, SIGNAL(sigOnSearchInStockOrder(int,QString,QString,QList<InStockOrderSearchInfo>))
                , this, SLOT(slot_onSearchInStockOrder(int,QString,QString,QList<InStockOrderSearchInfo>)));
        connect(m_pInStockCtrl, SIGNAL(sigOnEditInStockOrder(int,QString,QList<InStockOrderSearchInfo>,int))
                , this, SLOT(slot_onEditInStockOrder(int,QString,QList<InStockOrderSearchInfo>,int)));
        ui->mainPage->initInStockCtrl(m_pInStockCtrl);
        ui->editPage->initInStockCtrl(m_pInStockCtrl);
    }
    ui->mainPage->getInStockOrderListRequest();
}

void InStockWid::setCategoryList(QList<CategoryInfo *> categoryInfoList)
{
    ui->editPage->setCategoryList(categoryInfoList);
}

void InStockWid::slot_returnClicked()
{
    if (ui->stackedWidget->currentWidget() == ui->mainPage)
    {
        ui->mainPage->hideCalendarWidget();
        emit sigReturnClicked();
    }
    else
    {
        ui->stackedWidget->setCurrentWidget(ui->mainPage);
    }
}

void InStockWid::slot_addInStockOrder()
{
    ui->editPage->setOrderId(-1);
    ui->editPage->clearGoodsSelectWidgetData();
    ui->stackedWidget->setCurrentWidget(ui->editPage);
}

void InStockWid::slot_onSearchInStockOrder(int nCode, QString sMsg,QString sTotal, QList<InStockOrderSearchInfo> searchInfoList)
{
    if(nCode != e_success)
    {
         TipsDlg::instance()->releaseCtrl(QStringLiteral("入库单查看失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        ui->inquirePage->initData(sTotal,searchInfoList);
        ui->stackedWidget->setCurrentWidget(ui->inquirePage);
         TipsDlg::instance()->workDone();
    }
}

void InStockWid::slot_onEditInStockOrder(int nCode, QString sMsg, QList<InStockOrderSearchInfo> searchInfoList, int nOrderId)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("入库单修改失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        ui->editPage->initSelectGoodsData(searchInfoList, nOrderId);
        ui->stackedWidget->setCurrentWidget(ui->editPage);
        TipsDlg::instance()->workDone();
    }
}

void InStockWid::slot_updateOrder()
{
    test();
    ui->stackedWidget->setCurrentWidget(ui->mainPage);
}

void InStockWid::slot_printAll(QList<InStockSelectGoodsInfo> goodsInfoList, int nOrderId)
{
    ui->mainPage->printAllInStockOrder(goodsInfoList, nOrderId);
}

void InStockWid::init()
{
    ui->stackedWidget->setCurrentWidget(ui->mainPage);
}

void InStockWid::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sigReturnClicked()), this, SLOT(slot_returnClicked()));
    connect(ui->mainPage, SIGNAL(sigAddInStockOrder()), this, SLOT(slot_addInStockOrder()));
    connect(ui->mainPage,&MainView::sig_EditView,[=](){
        ui->stackedWidget->setCurrentWidget(ui->editPage);
    });
    connect(ui->mainPage, SIGNAL(sigCheckInStockSuccess()), this, SLOT(slot_updateOrder()));
    connect(ui->editPage, SIGNAL(sigSaveOrderSuccess()), this, SLOT(slot_updateOrder()));
    connect(ui->editPage, SIGNAL(sigPrintAll(QList<InStockSelectGoodsInfo>, int))
            , this, SLOT(slot_printAll(QList<InStockSelectGoodsInfo>, int)));
    connect(ui->editPage, SIGNAL(sigAddQuickGoods()), this, SIGNAL(sigAddQuickGoods()));
}
