#include "AdjustPriceOrderWidget.h"
#include "ui_AdjustPriceOrderWidget.h"
#include "../data/enumData.h"
#include "../util/CommonFun.h"
#include "../util/KPosIni.h"
#include "../callOuterDll/ReceiptPictureMaker.h"
#include <QMessageBox>
#include <QDebug>
#include "TipsDlg.h"

AdjustPriceOrderWidget::AdjustPriceOrderWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdjustPriceOrderWidget)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
    , m_pKPosCalendarWidget(NULL)
    , m_pAdjustPriceCtrl(NULL)
    , m_sStartDate("")
    , m_sEndDate("")
    , m_sSearchPattern("")
{
    ui->setupUi(this);
    ui->startDateEdit->installEventFilter(this);
    ui->endDateEdit->installEventFilter(this);
//    ui->searchWidget->startSearchTimer(); // 延迟搜索时间
//    test();
    initConnect();
    initButtons();
}

AdjustPriceOrderWidget::~AdjustPriceOrderWidget()
{
    if (m_pKPosCalendarWidget != NULL)
    {
        m_pKPosCalendarWidget->deleteLater();
        m_pKPosCalendarWidget = NULL;
    }

    delete ui;
}

//void AdjustPriceOrderWidget::test()
//{
//    QList<AdjustPriceOrderInfo> orderInfoList;
//    AdjustPriceOrderInfo adjustPriceOrderInfo;
//    for (int i = 0; i < 20; i++)
//    {
//        adjustPriceOrderInfo.sOrderNum = QString("23322555222%1").arg(i); // 单号
//        adjustPriceOrderInfo.sMakerAndChecker = QString("陈冬冬/咚咚晨"); // 制单人/审核人
//        adjustPriceOrderInfo.sMakeTime = "02.15 17:15"; // 修改时间
//        adjustPriceOrderInfo.sEffectTime = "02.16 17:15"; // 生效时间
//        if (i % 2 == 1)
//        {
//            adjustPriceOrderInfo.nState = 0; // 状态
//        }
//        else
//        {
//            adjustPriceOrderInfo.nState = 1; // 状态
//        }
//        orderInfoList.append(adjustPriceOrderInfo);
//    }
//    initData(orderInfoList);
//}

void AdjustPriceOrderWidget::initAdjustPriceCtrl(AdjustPriceCtrl *pAdjustPriceCtrl)
{
    m_pAdjustPriceCtrl = pAdjustPriceCtrl;
    qRegisterMetaType<QList<AdjustPriceOrderInfo> >("QList<AdjustPriceOrderInfo>");
    connect(m_pAdjustPriceCtrl, SIGNAL(sigOnGetAdjustPriceOrderList(int,QString,QList<AdjustPriceOrderInfo>))
            , this, SLOT(slot_onGetAdjustPriceOrderList(int,QString,QList<AdjustPriceOrderInfo>)));
    connect(m_pAdjustPriceCtrl, SIGNAL(sigOnCheckAdjustPriceOrder(int,QString,int))
            , this, SLOT(slot_onCheckAdjustPriceOrder(int,QString,int)));
    connect(m_pAdjustPriceCtrl, SIGNAL(sigOnRemoveAdjustPriceOrder(int,QString,int))
            , this, SLOT(slot_onRemoveAdjustPriceOrder(int,QString,int)));
    connect(m_pAdjustPriceCtrl, SIGNAL(sigOnPrintAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>,int))
            , this, SLOT(slot_onPrintAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>,int)));
}

void AdjustPriceOrderWidget::getAdjustPriceOrderListRequest()
{
    if (m_pAdjustPriceCtrl != NULL)
    {
        m_pAdjustPriceCtrl->getAdjustPriceOrderListRequest(m_sStartDate, m_sEndDate, m_sSearchPattern);
    }
}

void AdjustPriceOrderWidget::initData(const QList<AdjustPriceOrderInfo> &orderInfoList)
{
    m_orderInfoList = orderInfoList;
    updateData();
}

void AdjustPriceOrderWidget::printAdjustOrder(const QList<AdjustPriceSelectGoodsInfo> &goodsInfoList, int nOrderId)
{
    AdjustPricePrintData adjustPricePrintData;
    adjustPricePrintData.adjustPriceInfoList = goodsInfoList;
    adjustPricePrintData.sPrintTime = CommonFun::getCurDateTime();
    adjustPricePrintData.sShopName = KPosIni::getReceiptShopName();
    adjustPricePrintData.sShopCode = KPosIni::getShopCode();
    adjustPricePrintData.adjustOrderInfo.nOrderId = nOrderId;
    adjustPricePrintData.adjustOrderInfo.sOrderNum = "";
    adjustPricePrintData.adjustOrderInfo.sEffectTime = "";
    adjustPricePrintData.adjustOrderInfo.sMaker = "";
    adjustPricePrintData.adjustOrderInfo.sChecker = "";
    adjustPricePrintData.adjustOrderInfo.sMakeTime = "";
    adjustPricePrintData.adjustOrderInfo.nState = e_adjustPriceOrderAdd;

    if (nOrderId > 0)
    {
        int nLen = m_orderInfoList.length();
        for (int i = 0; i < nLen; i++)
        {
            if(m_orderInfoList[i].nOrderId == nOrderId)
            {
                adjustPricePrintData.adjustOrderInfo = m_orderInfoList[i];
                break;
            }
        }
    }

    ReceiptPictureMaker::instance()->printAdjustPriceInfoReceipt(adjustPricePrintData);
}

void AdjustPriceOrderWidget::hideCalendarWidget()
{
    if (m_pKPosCalendarWidget != NULL)
    {
        m_pKPosCalendarWidget->hide();
    }
}

void AdjustPriceOrderWidget::updateData()
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

bool AdjustPriceOrderWidget::eventFilter(QObject *watched, QEvent *event)
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

void AdjustPriceOrderWidget::on_deleteButton_clicked()
{
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pAdjustPriceCtrl != NULL)
        {
            m_pAdjustPriceCtrl->removeAdjustPriceOrder(nSelectKeyId);
        }
    }
}

void AdjustPriceOrderWidget::on_checkButton_clicked()
{
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pAdjustPriceCtrl != NULL)
        {
             m_pAdjustPriceCtrl->checkAdjustPriceOrderRequest(nSelectKeyId);
        }
    }
}

void AdjustPriceOrderWidget::on_printButton_clicked()
{
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pAdjustPriceCtrl != NULL)
        {
             m_pAdjustPriceCtrl->printAdjustPriceOrder(nSelectKeyId);
        }
    }
}

void AdjustPriceOrderWidget::on_searchButton_clicked()
{
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pAdjustPriceCtrl != NULL)
        {
             m_pAdjustPriceCtrl->searchAdjustPriceOrder(nSelectKeyId);
        }
    }
}

void AdjustPriceOrderWidget::on_editButton_clicked()
{
    int nSelectKeyId = ui->listView->getSelectKeyId();
    if (nSelectKeyId > 0)
    {
        if (m_pAdjustPriceCtrl != NULL)
        {
             m_pAdjustPriceCtrl->editAdjustPriceOrder(nSelectKeyId);
        }
    }
}

void AdjustPriceOrderWidget::on_addButton_clicked()
{
    emit sigAddAdjustOrder();
}

void AdjustPriceOrderWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void AdjustPriceOrderWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void AdjustPriceOrderWidget::slot_clickDate(int nYear, int nMonth, int nDay)
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
            TipsDlg::instance()->releaseCtrl(QStringLiteral("搜索起始日期大于结束日期，请重新输入！"));
        }
        else
        {
           getAdjustPriceOrderListRequest();
        }
    }
}

void AdjustPriceOrderWidget::slot_clickAdjustItem(AdjustPriceOrderInfo adjustPriceOrderInfo)
{
    setButtonsState(adjustPriceOrderInfo.nState);
}

void AdjustPriceOrderWidget::slot_onGetAdjustPriceOrderList(int nCode, QString sMsg, QList<AdjustPriceOrderInfo> orderInfoList)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("改价单列表获取失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        initData(orderInfoList);
//        if (orderInfoList.length() == 0)
//        {
//            TipsDlg::instance()->releaseCtrl(QStringLiteral("检测到改价单列表数量为0"));
//        }
    }
}

void AdjustPriceOrderWidget::slot_onCheckAdjustPriceOrder(int nCode, QString sMsg, int nOrderId)
{
    Q_UNUSED( nOrderId )

    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("改价单审核失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        emit sigCheckAdjustSuccess();
    }
}

void AdjustPriceOrderWidget::slot_onRemoveAdjustPriceOrder(int nCode, QString sMsg, int nOrderId)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("改价单删除失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
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

void AdjustPriceOrderWidget::slot_onPrintAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> orderInfoList, int nOrderId)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("改价单打印失败, nCode:%1, sMsg:%2, nOrderId:%3").arg(nCode).arg(sMsg).arg(nOrderId));
    }
    else
    {
        printAdjustOrder(orderInfoList, nOrderId);
    }
}

void AdjustPriceOrderWidget::slot_searchChanged(QString searchText)
{
    if (!m_sStartDate.isEmpty() && !m_sEndDate.isEmpty())
    {
        if (m_sStartDate >= m_sEndDate)
        {
            TipsDlg::instance()->releaseCtrl(QStringLiteral("搜索起始日期大于结束日期，请重新输入！"));
            return;
        }
    }

    m_sSearchPattern = searchText;
    getAdjustPriceOrderListRequest();
}

void AdjustPriceOrderWidget::generateUI()
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

void AdjustPriceOrderWidget::checkCurPageButtonState()
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

void AdjustPriceOrderWidget::inputStartDate()
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

void AdjustPriceOrderWidget::inputEndDate()
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

void AdjustPriceOrderWidget::initConnect()
{
    qRegisterMetaType<AdjustPriceOrderInfo>("AdjustPriceOrderInfo");
    connect(ui->listView, SIGNAL(sigClickItem(AdjustPriceOrderInfo)), this, SLOT(slot_clickAdjustItem(AdjustPriceOrderInfo)));
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
}

void AdjustPriceOrderWidget::setButtonsState(int nState)
{
    if (nState == e_adjustPriceOrderCheckFinish)
    {
        ui->deleteButton->setEnabled(false);
        ui->checkButton->setEnabled(false);
        ui->searchButton->setEnabled(true);
        ui->editButton->setEnabled(false);
    }
    else if (nState == e_adjustPriceOrderNotCheck)
    {
        ui->deleteButton->setEnabled(true);
        ui->checkButton->setEnabled(true);
        ui->searchButton->setEnabled(false);
        ui->editButton->setEnabled(true);
    }
    ui->printButton->setEnabled(true);
}

void AdjustPriceOrderWidget::initButtons()
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
//    ui->addButton->setEnabled(!bFindNotCheck);
    ui->printButton->setEnabled(bFindSelectId);
    ui->deleteButton->setEnabled(bFindSelectId && bSelectNotCheck);
    ui->checkButton->setEnabled(bFindSelectId && bSelectNotCheck);
    ui->editButton->setEnabled(bFindSelectId && bSelectNotCheck);
    ui->searchButton->setEnabled(bFindSelectId && !bSelectNotCheck);
}
