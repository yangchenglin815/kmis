#include "MainView.h"
#include "ui_MainView.h"
#include "../data/enumData.h"
#include "../callOuterDll/ReceiptPictureMaker.h"
#include "../util/KPosIni.h"
#include "../util/CommonFun.h"
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include "TipsDlg.h"

MainView::MainView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainView)
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
    ui->startDateEdit->installEventFilter(this);
    ui->endDateEdit->installEventFilter(this);
    //    ui->searchWidget->startSearchTimer(); // 延迟搜索时间
    initConnect();
    initButtons();
}

MainView::~MainView()
{
    if (m_pKPosCalendarWidget != NULL)
    {
        m_pKPosCalendarWidget->deleteLater();
        m_pKPosCalendarWidget = NULL;
    }

    delete ui;
}

void MainView::initInStockCtrl(InStockCtrl *pStockCtrl)
{
    if (m_pStockCtrl == NULL)
    {
        m_pStockCtrl = pStockCtrl;
        connect(m_pStockCtrl, SIGNAL(sigOnGetInStockOrderList(int,QString,QList<InStockOrderInfo>))
                , this, SLOT(slot_onGetInStockOrderList(int,QString,QList<InStockOrderInfo>)));
        connect(m_pStockCtrl, SIGNAL(sigOnPrintInStockOrder(int,QString,QList<InStockOrderSearchInfo>,int))
                , this, SLOT(slot_onPrintInStockOrder(int,QString,QList<InStockOrderSearchInfo>,int)));
        connect(m_pStockCtrl, SIGNAL(sigOnCheckInStockOrder(int,QString)), this, SLOT(slot_onCheckInStockOrder(int,QString)));
        connect(m_pStockCtrl, SIGNAL(sigOnRemoveInStockOrder(int,QString,int)), this, SLOT(slot_onRemoveInStockOrder(int,QString,int)));
    }
}

void MainView::getInStockOrderListRequest()
{
    qDebug()<<"getInStockOrderListRequest";
    if (m_pStockCtrl != NULL)
    {
        m_pStockCtrl->getInStockOrderListRequest(m_sStartDate, m_sEndDate, m_sSearchPattern);
    }
}

void MainView::initData(const QList<InStockOrderInfo> &orderInfoList)
{
    qDebug()<<"before";
    m_orderInfoList = orderInfoList;
    qDebug()<<"after";
    updateData();
}

void MainView::printAllInStockOrder(const QList<InStockSelectGoodsInfo> &goodsInfoList, int nOrderId)
{
    InStockPrintData stockPrintData;
    m_Total=0;
    foreach (InStockSelectGoodsInfo info, goodsInfoList) {
        m_Total+=info.fShouldTotal;
    }
    qDebug()<<"计算总金额为："<<m_Total;
    stockPrintData.stockInfoList = goodsInfoList;
    stockPrintData.sTotal = CommonFun::floatToString(m_Total);
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

    ReceiptPictureMaker::instance()->printInStockInfoReceipt(stockPrintData);
}

//void MainView::printAddedInStockOrder(QList<InStockSelectGoodsInfo> addedGoodsList, QList<InStockSelectGoodsInfo> removedGoodsList, QList<InStockSelectGoodsInfo> updatedGoodsList, int nOrderId)
//{
//    StockPrintData stockPrintData;
//        stockPrintData.addedInfoList = addedGoodsList;
//        stockPrintData.removedInfoList = removedGoodsList;
//        stockPrintData.updateInfoList = updatedGoodsList;
//        stockPrintData.sPrintTime = CommonFun::getCurDateTime();
//        stockPrintData.sShopName = KPosIni::getReceiptShopName();
//        stockPrintData.sShopCode = KPosIni::getShopCode();
//        stockPrintData.stockOrderInfo.nOrderId = nOrderId;
//        stockPrintData.stockOrderInfo.sOrderNum = "";
//        stockPrintData.stockOrderInfo.sMaker = "";
//        stockPrintData.stockOrderInfo.sChecker = "";
//        stockPrintData.stockOrderInfo.sMakeTime = "";
//        stockPrintData.stockOrderInfo.nState = e_stockOrderAdd;

//        if (nOrderId > 0)
//        {
//            int nLen = m_orderInfoList.length();
//            for (int i = 0; i < nLen; i++)
//            {
//                if(m_orderInfoList[i].nOrderId == nOrderId)
//                {
//                    stockPrintData.stockOrderInfo = m_orderInfoList[i];
//                    break;
//                }
//            }
//        }

//        ReceiptPictureMaker::instance()->printAddedStockInfoReceipt(stockPrintData);
//}

void MainView::hideCalendarWidget()
{
    if (m_pKPosCalendarWidget != NULL)
    {
        m_pKPosCalendarWidget->hide();
    }
}
void MainView::slot_clickDate(int nYear, int nMonth, int nDay)
{
    QString text = QString("%1.%2.%3").arg(nYear).arg(nMonth).arg(nDay);
    if (m_bInStartDate)
    {
        ui->startDateEdit->setText(text);
        m_sStartDate = CommonFun::getFormatDate(nYear,nMonth,nDay);
    }
    else
    {
        ui->endDateEdit->setText(text);
        m_sEndDate = CommonFun::getFormatDate(nYear,nMonth,nDay+1);
    }

    if (!m_sStartDate.isEmpty() && !m_sEndDate.isEmpty())
    {
        if(m_sStartDate > m_sEndDate)
        {
            TipsDlg::instance()->releaseCtrl(QStringLiteral("搜索起始日期大于结束日期，请重新输入！"));
        }
        else
        {
            getInStockOrderListRequest();
        }
    }
}

bool MainView::eventFilter(QObject *watched, QEvent *event)
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

void MainView::inputStartDate()
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

void MainView::inputEndDate()
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

void MainView::initConnect()
{
    qRegisterMetaType<InStockOrderInfo>("InStockOrderInfo");
    connect(ui->listView, SIGNAL(sigClickItem(InStockOrderInfo)), this, SLOT(slot_clickAdjustItem(InStockOrderInfo)));
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
}

void MainView::slot_clickAdjustItem(InStockOrderInfo stockOrderInfo)
{
    setButtonsState(stockOrderInfo.nState);
}

void MainView::slot_onGetInStockOrderList(int nCode, QString sMsg, QList<InStockOrderInfo> orderInfoList)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("入库单列表获取失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        initData(orderInfoList);
    }
}

void MainView::slot_onCheckInStockOrder(int nCode, QString sMsg)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("入库单审核失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        emit sigCheckInStockSuccess();
    }
}

void MainView::slot_onRemoveInStockOrder(int nCode, QString sMsg, int nOrderId)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("入库单删除失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
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

void MainView::slot_onPrintInStockOrder(int nCode, QString sMsg, QList<InStockOrderSearchInfo> orderInfoList, int nOrderId)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("入库单打印失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        printAllInStockOrder(orderInfoList, nOrderId);
    }
}

void MainView::slot_searchChanged(QString searchText)
{
    bool bShowHint = false;
    if (!m_sStartDate.isEmpty() && !m_sEndDate.isEmpty())
    {
        if (m_sStartDate > m_sEndDate)
        {
            bShowHint = true;
        }
    }

    if (bShowHint)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("搜索起始日期大于结束日期，请重新输入！"));
    }
    else
    {
        m_sSearchPattern = searchText;
        getInStockOrderListRequest();
    }
}

void MainView::updateData()
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

void MainView::generateUI()
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

void MainView::checkCurPageButtonState()
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
void MainView::setButtonsState(int nState)
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

void MainView::initButtons()
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
    //        ui->addButton->setEnabled(!bFindNotCheck);
    ui->printButton->setEnabled(bFindSelectId);
    ui->deleteButton->setEnabled(bFindSelectId && bSelectNotCheck);
    ui->checkButton->setEnabled(bFindSelectId && bSelectNotCheck);
    ui->editButton->setEnabled(bFindSelectId && bSelectNotCheck);
    ui->searchButton->setEnabled(bFindSelectId && !bSelectNotCheck);
}
void MainView::on_deleteButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pStockCtrl != NULL)
        {
            m_pStockCtrl->removeInStockOrderRequest(nSelectKeyId);
        }
    }
}

void MainView::on_checkButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pStockCtrl != NULL)
        {
            m_pStockCtrl->checkInStockOrderRequest(nSelectKeyId);
        }
    }
}

void MainView::on_printButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pStockCtrl != NULL)
        {
            m_pStockCtrl->printInStockOrderRequest(nSelectKeyId);
        }
    }
}

void MainView::on_searchButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pStockCtrl != NULL)
        {
            m_pStockCtrl->searchInStockOrderRequest(nSelectKeyId);
        }
    }

    //    emit sig_InquireView();
}

void MainView::on_editButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pStockCtrl != NULL)
        {
            m_pStockCtrl->editInStockOrderRequest(nSelectKeyId);
        }
    }
    //        emit sig_EditView();
}

void MainView::on_addButton_clicked()
{
    hideCalendarWidget();
    emit sigAddInStockOrder();
}

void MainView::on_lastPageButton_clicked()
{
    hideCalendarWidget();
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void MainView::on_nextPageButton_clicked()
{
    hideCalendarWidget();
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

