#include "OMainView.h"
#include "ui_OMainView.h"
#include "../data/enumData.h"
#include "../callOuterDll/ReceiptPictureMaker.h"
#include "../util/KPosIni.h"
#include "../util/CommonFun.h"
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include "TipsDlg.h"
//#ifdef Q_OS_WIN
//#pragma execution_character_set("utf-8")
//#endif

OMainView::OMainView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OMainView)
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
    //    test();
    ui->startDateEdit->installEventFilter(this);
    ui->endDateEdit->installEventFilter(this);
    //    ui->searchWidget->startSearchTimer(); // 延迟搜索时间
    initConnect();
    initButtons();
}

OMainView::~OMainView()
{
    if (m_pKPosCalendarWidget != NULL)
    {
        m_pKPosCalendarWidget->deleteLater();
        m_pKPosCalendarWidget = NULL;
    }

    delete ui;
}

void OMainView::initOutStockCtrl(OutStockCtrl *pStockCtrl)
{
    if (m_pStockCtrl == NULL)
    {
        m_pStockCtrl = pStockCtrl;
        connect(m_pStockCtrl, SIGNAL(sigOnGetOutStockOrderList(int,QString,QList<OutStockOrderInfo>))
                , this, SLOT(slot_onGetOutStockOrderList(int,QString,QList<OutStockOrderInfo>)));
        connect(m_pStockCtrl, SIGNAL(sigOnPrintOutStockOrder(int,QString,QList<OutStockOrderSearchInfo>,int))
                , this, SLOT(slot_onPrintOutStockOrder(int,QString,QList<OutStockOrderSearchInfo>,int)));
        connect(m_pStockCtrl, SIGNAL(sigOnCheckOutStockOrder(int,QString)), this, SLOT(slot_onCheckOutStockOrder(int,QString)));
        connect(m_pStockCtrl, SIGNAL(sigOnRemoveOutStockOrder(int,QString,int)), this, SLOT(slot_onRemoveOutStockOrder(int,QString,int)));
    }
}

void OMainView::getOutStockOrderListRequest()
{
    qDebug()<<"getOutStockOrderListRequest";
    if (m_pStockCtrl != NULL)
    {
        m_pStockCtrl->getOutStockOrderListRequest(m_sStartDate, m_sEndDate, m_sSearchPattern);
    }
}

void OMainView::initData(const QList<OutStockOrderInfo> &orderInfoList)
{
    qDebug()<<"before";
    m_orderInfoList = orderInfoList;
    qDebug()<<"after";
    updateData();
}

void OMainView::printAllOutStockOrder(const QList<OutStockSelectGoodsInfo> &goodsInfoList, int nOrderId)
{
    OutStockPrintData stockPrintData;
    m_Total=0;
    foreach (OutStockSelectGoodsInfo info, goodsInfoList) {
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

    ReceiptPictureMaker::instance()->printOutStockInfoReceipt(stockPrintData);
}

//void OMainView::printAddedOutStockOrder(QList<OutStockSelectGoodsInfo> addedGoodsList, QList<OutStockSelectGoodsInfo> removedGoodsList, QList<OutStockSelectGoodsInfo> updatedGoodsList, int nOrderId)
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

void OMainView::hideCalendarWidget()
{
    if (m_pKPosCalendarWidget != NULL)
    {
        m_pKPosCalendarWidget->hide();
    }
}
void OMainView::slot_clickDate(int nYear, int nMonth, int nDay)
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
            getOutStockOrderListRequest();
        }
    }
}

bool OMainView::eventFilter(QObject *watched, QEvent *event)
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

void OMainView::inputStartDate()
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

void OMainView::inputEndDate()
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

void OMainView::initConnect()
{
    qRegisterMetaType<OutStockOrderInfo>("OutStockOrderInfo");
    connect(ui->listView, SIGNAL(sigClickItem(OutStockOrderInfo)), this, SLOT(slot_clickAdjustItem(OutStockOrderInfo)));
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
}

void OMainView::slot_clickAdjustItem(OutStockOrderInfo stockOrderInfo)
{
    setButtonsState(stockOrderInfo.nState);
}

void OMainView::slot_onGetOutStockOrderList(int nCode, QString sMsg, QList<OutStockOrderInfo> orderInfoList)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("出库单列表获取失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        initData(orderInfoList);
    }
}

void OMainView::slot_onCheckOutStockOrder(int nCode, QString sMsg)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("出库单审核失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        emit sigCheckOutStockSuccess();
    }
}

void OMainView::slot_onRemoveOutStockOrder(int nCode, QString sMsg, int nOrderId)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("出库单删除失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
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

void OMainView::slot_onPrintOutStockOrder(int nCode, QString sMsg, QList<OutStockOrderSearchInfo> orderInfoList, int nOrderId)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("出库单打印失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        printAllOutStockOrder(orderInfoList, nOrderId);
    }
}

void OMainView::slot_searchChanged(QString searchText)
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
        getOutStockOrderListRequest();
    }
}

void OMainView::updateData()
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

void OMainView::generateUI()
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

void OMainView::checkCurPageButtonState()
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
void OMainView::setButtonsState(int nState)
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

void OMainView::initButtons()
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
void OMainView::on_deleteButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pStockCtrl != NULL)
        {
            m_pStockCtrl->removeOutStockOrderRequest(nSelectKeyId);
        }
    }
}

void OMainView::on_checkButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pStockCtrl != NULL)
        {
            m_pStockCtrl->checkOutStockOrderRequest(nSelectKeyId);
        }
    }
}

void OMainView::on_printButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pStockCtrl != NULL)
        {
            m_pStockCtrl->printOutStockOrderRequest(nSelectKeyId);
        }
    }
}

void OMainView::on_searchButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pStockCtrl != NULL)
        {
            m_pStockCtrl->searchOutStockOrderRequest(nSelectKeyId);
        }
    }

    //    emit sig_InquireView();
}

void OMainView::on_editButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pStockCtrl != NULL)
        {
            m_pStockCtrl->editOutStockOrderRequest(nSelectKeyId);
        }
    }
    //        emit sig_EditView();
}

void OMainView::on_addButton_clicked()
{
    hideCalendarWidget();
    emit sigAddOutStockOrder();
}

void OMainView::on_lastPageButton_clicked()
{
    hideCalendarWidget();
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void OMainView::on_nextPageButton_clicked()
{
    hideCalendarWidget();
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

