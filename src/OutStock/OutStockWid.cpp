#include "OutStockWid.h"
#include "ui_OutStockWid.h"

#include <QDebug>
#include <QMessageBox>
#include "TipsDlg.h"
//#ifdef Q_OS_WIN
//#pragma execution_character_set("utf-8")
//#endif

OutStockWid::OutStockWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OutStockWid)
  , m_pOutStockCtrl(NULL)
{
    ui->setupUi(this);
    initConnect();
    init();
}

OutStockWid::~OutStockWid()
{
    delete ui;
}

void OutStockWid::test()
{
    if (m_pOutStockCtrl == NULL)
    {
        m_pOutStockCtrl = new OutStockCtrl;
        qRegisterMetaType<QList<OutStockOrderSearchInfo> >("QList<OutStockOrderSearchInfo>");
        connect(m_pOutStockCtrl, SIGNAL(sigOnSearchOutStockOrder(int,QString,QString,QList<OutStockOrderSearchInfo>))
                , this, SLOT(slot_onSearchOutStockOrder(int,QString,QString,QList<OutStockOrderSearchInfo>)));
        connect(m_pOutStockCtrl, SIGNAL(sigOnEditOutStockOrder(int,QString,QList<OutStockOrderSearchInfo>,int))
                , this, SLOT(slot_onEditOutStockOrder(int,QString,QList<OutStockOrderSearchInfo>,int)));
        ui->mainPage->initOutStockCtrl(m_pOutStockCtrl);
        ui->editPage->initOutStockCtrl(m_pOutStockCtrl);
    }
    ui->mainPage->getOutStockOrderListRequest();
}

void OutStockWid::setCategoryList(QList<CategoryInfo *> categoryInfoList)
{
    ui->editPage->setCategoryList(categoryInfoList);
}

void OutStockWid::slot_returnClicked()
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

void OutStockWid::slot_addOutStockOrder()
{
    ui->editPage->setOrderId(-1);
    ui->editPage->clearGoodsSelectWidgetData();
    ui->stackedWidget->setCurrentWidget(ui->editPage);
}

void OutStockWid::slot_onSearchOutStockOrder(int nCode, QString sMsg,QString sTotal, QList<OutStockOrderSearchInfo> searchInfoList)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("出库单查看失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));

    }
    else
    {
        ui->inquirePage->initData(sTotal,searchInfoList);
        ui->stackedWidget->setCurrentWidget(ui->inquirePage);
         TipsDlg::instance()->workDone();
    }
}

void OutStockWid::slot_onEditOutStockOrder(int nCode, QString sMsg, QList<OutStockOrderSearchInfo> searchInfoList, int nOrderId)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("出库单修改失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        ui->editPage->initSelectGoodsData(searchInfoList, nOrderId);
        ui->stackedWidget->setCurrentWidget(ui->editPage);
        TipsDlg::instance()->workDone();
    }
}

void OutStockWid::slot_updateOrder()
{
    test();
    ui->stackedWidget->setCurrentWidget(ui->mainPage);
}

void OutStockWid::slot_printAll(QList<OutStockSelectGoodsInfo> goodsInfoList, int nOrderId)
{
    ui->mainPage->printAllOutStockOrder(goodsInfoList, nOrderId);
}

void OutStockWid::init()
{
    ui->stackedWidget->setCurrentWidget(ui->mainPage);
}

void OutStockWid::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sigReturnClicked()), this, SLOT(slot_returnClicked()));
    connect(ui->mainPage, SIGNAL(sigAddOutStockOrder()), this, SLOT(slot_addOutStockOrder()));
    connect(ui->mainPage,&OMainView::sig_EditView,[=](){
        ui->stackedWidget->setCurrentWidget(ui->editPage);
    });
    connect(ui->mainPage, SIGNAL(sigCheckOutStockSuccess()), this, SLOT(slot_updateOrder()));
    connect(ui->editPage, SIGNAL(sigSaveOrderSuccess()), this, SLOT(slot_updateOrder()));
    connect(ui->editPage, SIGNAL(sigPrintAll(QList<OutStockSelectGoodsInfo>, int))
            , this, SLOT(slot_printAll(QList<OutStockSelectGoodsInfo>, int)));
}
