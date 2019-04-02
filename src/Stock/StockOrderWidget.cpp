#include "StockOrderWidget.h"
#include "ui_StockOrderWidget.h"
#include "../data/enumData.h"
#include "../callOuterDll/ReceiptPictureMaker.h"
#include "../util/KPosIni.h"
#include "../util/CommonFun.h"
#include "TipsDlg.h"
#include <QDebug>

StockOrderWidget::StockOrderWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StockOrderWidget)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
    , m_pKPosCalendarWidget(NULL)
    , m_pStockCtrl(NULL)
    , m_sStartDate("")
    , m_sEndDate("")
    , m_sSearchPattern("")
{
    ui->setupUi(this);
//        test();
    ui->startDateEdit->installEventFilter(this);
    ui->endDateEdit->installEventFilter(this);
    //    ui->searchWidget->startSearchTimer(); // 延迟搜索时间
    initConnect();
    initButtons();
}

StockOrderWidget::~StockOrderWidget()
{
    if (m_pKPosCalendarWidget != NULL)
    {
        m_pKPosCalendarWidget->deleteLater();
        m_pKPosCalendarWidget = NULL;
    }

    delete ui;
}

//void StockOrderWidget::test()
//{
//    QList<StockOrderInfo> orderInfoList;
//    StockOrderInfo stockOrderInfo;
//    for (int i = 0; i < 20; i++)
//    {
//        stockOrderInfo.nOrderId = i;
//        stockOrderInfo.sOrderNum = QString("23322555222%1").arg(i); // 单号
//        stockOrderInfo.sMaker = QString("陈冬冬"); // 制单人
//        stockOrderInfo.sChecker = QStringLiteral("咚咚晨"); // 审核人
//        stockOrderInfo.sMakeTime = "1988-03-24 17:15:16"; // 修改时间yyyy-MM-dd HH:mm:ss
//        stockOrderInfo.sCreateTime = stockOrderInfo.sMakeTime;
//        if (i % 2 == 1)
//        {
//            stockOrderInfo.nState = 0; // 状态
//        }
//        else
//        {
//            stockOrderInfo.nState = 1; // 状态
//        }
//        orderInfoList.append(stockOrderInfo);
//    }
//    initData(orderInfoList);
//}

void StockOrderWidget::initStockCtrl(StockCtrl *pStockCtrl)
{
    if (m_pStockCtrl == NULL)
    {
        m_pStockCtrl = pStockCtrl;
        connect(m_pStockCtrl, SIGNAL(sigOnGetStockOrderList(int,QString,QList<StockOrderInfo>))
                , this, SLOT(slot_onGetStockOrderList(int,QString,QList<StockOrderInfo>)));
        connect(m_pStockCtrl, SIGNAL(sigOnPrintStockOrder(int,QString,QList<StockOrderSearchInfo>,int))
                , this, SLOT(slot_onPrintStockOrder(int,QString,QList<StockOrderSearchInfo>,int)));
        connect(m_pStockCtrl, SIGNAL(sigOnCheckStockOrder(int,QString)), this, SLOT(slot_onCheckStockOrder(int,QString)));
        connect(m_pStockCtrl, SIGNAL(sigOnRemoveStockOrder(int,QString,int)), this, SLOT(slot_onRemoveStockOrder(int,QString,int)));
    }
}

void StockOrderWidget::getStockOrderListRequest()
{
    if (m_pStockCtrl != NULL)
    {
        m_pStockCtrl->getStockOrderListRequest(m_sStartDate, m_sEndDate, m_sSearchPattern);
    }
}

void StockOrderWidget::initData(const QList<StockOrderInfo> &orderInfoList)
{
    m_orderInfoList = orderInfoList;
    updateData();
}

void StockOrderWidget::printAllStockOrder(const QList<StockSelectGoodsInfo> &goodsInfoList, int nOrderId)
{
    StockPrintData stockPrintData;
    stockPrintData.stockInfoList = goodsInfoList;
    stockPrintData.sPrintTime = CommonFun::getCurDateTime();
    stockPrintData.sShopName = KPosIni::getReceiptShopName();
    stockPrintData.sShopCode = KPosIni::getShopCode();
    stockPrintData.stockOrderInfo.nOrderId = nOrderId;
    stockPrintData.stockOrderInfo.sOrderNum = "";
    stockPrintData.stockOrderInfo.sMaker = "";
    stockPrintData.stockOrderInfo.sChecker = "";
    stockPrintData.stockOrderInfo.sMakeTime = "";
    stockPrintData.stockOrderInfo.nState = e_stockOrderAdd;

    if (nOrderId > 0)
    {
        int nLen = m_orderInfoList.length();
        for (int i = 0; i < nLen; i++)
        {
            if(m_orderInfoList[i].nOrderId == nOrderId)
            {
                stockPrintData.stockOrderInfo = m_orderInfoList[i];
                break;
            }
        }
    }

    ReceiptPictureMaker::instance()->printAllStockInfoReceipt(stockPrintData);
}

void StockOrderWidget::printAddedStockOrder(QList<StockSelectGoodsInfo> addedGoodsList, QList<StockSelectGoodsInfo> removedGoodsList
                                            , QList<StockSelectGoodsInfo> updatedGoodsList, int nOrderId)
{
    StockPrintData stockPrintData;
    stockPrintData.addedInfoList = addedGoodsList;
    stockPrintData.removedInfoList = removedGoodsList;
    stockPrintData.updateInfoList = updatedGoodsList;
    stockPrintData.sPrintTime = CommonFun::getCurDateTime();
    stockPrintData.sShopName = KPosIni::getReceiptShopName();
    stockPrintData.sShopCode = KPosIni::getShopCode();
    stockPrintData.stockOrderInfo.nOrderId = nOrderId;
    stockPrintData.stockOrderInfo.sOrderNum = "";
    stockPrintData.stockOrderInfo.sMaker = "";
    stockPrintData.stockOrderInfo.sChecker = "";
    stockPrintData.stockOrderInfo.sMakeTime = "";
    stockPrintData.stockOrderInfo.nState = e_stockOrderAdd;

    if (nOrderId > 0)
    {
        int nLen = m_orderInfoList.length();
        for (int i = 0; i < nLen; i++)
        {
            if(m_orderInfoList[i].nOrderId == nOrderId)
            {
                stockPrintData.stockOrderInfo = m_orderInfoList[i];
                break;
            }
        }
    }

    ReceiptPictureMaker::instance()->printAddedStockInfoReceipt(stockPrintData);
}

void StockOrderWidget::hideCalendarWidget()
{
    if (m_pKPosCalendarWidget != NULL)
    {
        m_pKPosCalendarWidget->hide();
    }
}

bool StockOrderWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->startDateEdit)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            inputStartDate();
        }
    }
    else if (watched == ui->endDateEdit)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            inputEndDate();
        }

    }
    return QWidget::eventFilter(watched, event);
}

void StockOrderWidget::on_deleteButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pStockCtrl != NULL)
        {
            m_pStockCtrl->removeStockOrderRequest(nSelectKeyId);
        }
    }
}

void StockOrderWidget::on_checkButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pStockCtrl != NULL)
        {
            m_pStockCtrl->checkStockOrderRequest(nSelectKeyId);
        }
    }
}

void StockOrderWidget::on_printButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pStockCtrl != NULL)
        {
            m_pStockCtrl->printStockOrderRequest(nSelectKeyId);
        }
    }
}

void StockOrderWidget::on_searchButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pStockCtrl != NULL)
        {
            m_pStockCtrl->searchStockOrderRequest(nSelectKeyId);
        }
    }
}

void StockOrderWidget::on_editButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pStockCtrl != NULL)
        {
            m_pStockCtrl->editStockOrderRequest(nSelectKeyId);
        }
    }
}

void StockOrderWidget::on_addButton_clicked()
{
    hideCalendarWidget();
    if(tipsDlg.isNull())
    {
        tipsDlg =new DlgCommon(nullptr,false);
        tipsDlg->set_title("敬告");
        tipsDlg->set_content("请在出入库单据录入后再进行盘点，否则会造成库存信息不准确");
        connect(tipsDlg,&DlgCommon::sig_btn_sure,[=](){
            emit sigAddStockOrder();
        });
    }
    tipsDlg->show();
    tipsDlg->raise();
}

void StockOrderWidget::on_lastPageButton_clicked()
{
    hideCalendarWidget();
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void StockOrderWidget::on_nextPageButton_clicked()
{
    hideCalendarWidget();
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void StockOrderWidget::slot_clickDate(int nYear, int nMonth, int nDay)
{
    QString text = QString("%1.%2.%3").arg(nYear).arg(nMonth).arg(nDay);
    if (m_bInStartDate)
    {
        ui->startDateEdit->setText(text);
        m_sStartDate = CommonFun::getFormatDate(nYear, nMonth, nDay);
    }
    else
    {
        ui->endDateEdit->setText(text);
        m_sEndDate = CommonFun::getFormatDate(nYear, nMonth, nDay + 1);
    }

    if (!m_sStartDate.isEmpty() && !m_sEndDate.isEmpty())
    {
        if (m_sStartDate >= m_sEndDate)
        {
            TipsDlg::instance()->releaseCtrl( QStringLiteral("搜索起始日期大于结束日期，请重新输入！"));
        }
        else
        {
            getStockOrderListRequest();
        }
    }
}

void StockOrderWidget::slot_clickAdjustItem(StockOrderInfo stockOrderInfo)
{
    setButtonsState(stockOrderInfo.nState);
}

void StockOrderWidget::slot_onGetStockOrderList(int nCode, QString sMsg, QList<StockOrderInfo> orderInfoList)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("盘点单列表获取失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        initData(orderInfoList);
    }
}

void StockOrderWidget::slot_onCheckStockOrder(int nCode, QString sMsg)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("改价单审核失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        emit sigCheckStockSuccess();
    }
}

void StockOrderWidget::slot_onRemoveStockOrder(int nCode, QString sMsg, int nOrderId)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("盘点单删除失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        int nLen = m_orderInfoList.length();
        for (int i = 0; i < nLen; i++)
        {
            if (m_orderInfoList[i].nOrderId == nOrderId)
            {
                m_orderInfoList.removeAt(i);
                ui->listView->setSelectKeyId(-1);
                updateData();
                return;
            }
        }
    }
}

void StockOrderWidget::slot_onPrintStockOrder(int nCode, QString sMsg, QList<StockOrderSearchInfo> orderInfoList, int nOrderId)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("盘点单打印失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        printAllStockOrder(orderInfoList, nOrderId);
    }
}

//void StockOrderWidget::slot_onGetAdjustPriceOrderList(int nCode, QString sMsg, QList<AdjustPriceOrderInfo> orderInfoList)
//{

//}

//void StockOrderWidget::slot_onCheckAdjustPriceOrder(int nCode, QString sMsg, int nOrderId)
//{

//}

//void StockOrderWidget::slot_onRemoveAdjustPriceOrder(int nCode, QString sMsg, int nOrderId)
//{

//}

//void StockOrderWidget::slot_onPrintAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> orderInfoList, int nOrderId)
//{

//}

void StockOrderWidget::slot_searchChanged(QString searchText)
{
    if (!m_sStartDate.isEmpty() && !m_sEndDate.isEmpty())
    {
        if (m_sStartDate >= m_sEndDate)
        {
            TipsDlg::instance()->releaseCtrl( QStringLiteral("搜索起始日期大于结束日期，请重新输入！"));
            return;
        }
    }

    m_sSearchPattern = searchText;
    getStockOrderListRequest();
}

void StockOrderWidget::updateData()
{
    int nLen = m_orderInfoList.length();
    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }

    initButtons();
    checkCurPageButtonState();
    generateUI();
}

void StockOrderWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_orderInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(m_orderInfoList[i]);
    }
}

void StockOrderWidget::checkCurPageButtonState()
{
    if (m_nCurPage <= 1)
    {
        m_nCurPage = 1;
        ui->lastPageButton->setEnabled(false);
    }
    else
    {
        ui->lastPageButton->setEnabled(true);
    }

    if (m_nCurPage < m_nTotalPage)
    {
        ui->nextPageButton->setEnabled(true);
    }
    else
    {
        m_nCurPage = m_nTotalPage;
        ui->nextPageButton->setEnabled(false);
    }
}

void StockOrderWidget::inputStartDate()
{
    m_bInStartDate = true;

    if (m_pKPosCalendarWidget == NULL)
    {
        m_pKPosCalendarWidget = new KPosCalendarWidget;
        connect(m_pKPosCalendarWidget, SIGNAL(sigClickDate(int,int,int)), this, SLOT(slot_clickDate(int,int,int)));
    }
    QPoint globalPos = ui->startDateEdit->mapToGlobal(QPoint(0,0));

    int nXPos = globalPos.x();
    int nYPos = globalPos.y() + ui->startDateEdit->height() + 10;
    m_pKPosCalendarWidget->move(nXPos, nYPos);
    m_pKPosCalendarWidget->activateWindow();
    m_pKPosCalendarWidget->showNormal();
}

void StockOrderWidget::inputEndDate()
{
    m_bInStartDate = false;

    if (m_pKPosCalendarWidget == NULL)
    {
        m_pKPosCalendarWidget = new KPosCalendarWidget;
        connect(m_pKPosCalendarWidget, SIGNAL(sigClickDate(int,int,int)), this, SLOT(slot_clickDate(int,int,int)));
    }
    QPoint globalPos = ui->endDateEdit->mapToGlobal(QPoint(0,0));

    int nXPos = globalPos.x();
    int nYPos = globalPos.y() + ui->endDateEdit->height() + 10;
    m_pKPosCalendarWidget->move(nXPos, nYPos);
    m_pKPosCalendarWidget->activateWindow();
    m_pKPosCalendarWidget->showNormal();
}

void StockOrderWidget::initConnect()
{
    qRegisterMetaType<StockOrderInfo>("StockOrderInfo");
    connect(ui->listView, SIGNAL(sigClickItem(StockOrderInfo)), this, SLOT(slot_clickAdjustItem(StockOrderInfo)));
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
}

void StockOrderWidget::setButtonsState(int nState)
{
    if (nState == e_stockOrderCheckFinish)
    {
        ui->deleteButton->setEnabled(false);
        ui->checkButton->setEnabled(false);
        ui->searchButton->setEnabled(true);
        ui->editButton->setEnabled(false);
    }
    else if (nState == e_stockOrderNotCheck)
    {
        ui->deleteButton->setEnabled(true);
        ui->checkButton->setEnabled(true);
        ui->searchButton->setEnabled(false);
        ui->editButton->setEnabled(true);
    }
    ui->printButton->setEnabled(true);
}

void StockOrderWidget::initButtons()
{
    int nSelectId = ui->listView->getSelectKeyId();
    bool bFindNotCheck = false;
    bool bFindSelectId = false;
    bool bSelectNotCheck = false;
    int nLen = m_orderInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (!bFindNotCheck && m_orderInfoList[i].nState == e_adjustPriceOrderNotCheck)
        {
            bFindNotCheck = true;
        }
        if (!bFindSelectId && (nSelectId > 0) && m_orderInfoList[i].nOrderId == nSelectId)
        {
            bFindSelectId = true;
            if (m_orderInfoList[i].nState == e_adjustPriceOrderNotCheck)
            {
                bSelectNotCheck = true;
            }
        }
        if (bFindNotCheck && bFindSelectId)
        {
            break;
        }
    }
    ui->addButton->setEnabled(!bFindNotCheck);
    ui->printButton->setEnabled(bFindSelectId);
    ui->deleteButton->setEnabled(bFindSelectId && bSelectNotCheck);
    ui->checkButton->setEnabled(bFindSelectId && bSelectNotCheck);
    ui->editButton->setEnabled(bFindSelectId && bSelectNotCheck);
    ui->searchButton->setEnabled(bFindSelectId && !bSelectNotCheck);
}


