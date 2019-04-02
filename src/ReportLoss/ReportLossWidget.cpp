#include "ReportLossWidget.h"
#include "ui_ReportLossWidget.h"
#include "../util/CommonFun.h"
#include "../util/KPosIni.h"
#include "TipsDlg.h"
#include "CheckDetialWidget.h"
#include "../callOuterDll/ReceiptPictureMaker.h"

ReportLossWidget::ReportLossWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportLossWidget)
  , m_nOnePageCount(7)
  , m_nTotalPage(1)
  , m_nCurPage(1)
  , m_pKPosCalendarWidget(NULL)
  , m_sStartDate("")
  , m_sEndDate("")
  , m_sSearchPattern("")
  , m_reportLossCtrl(NULL)
{
    ui->setupUi(this);
    ui->startDateEdit->installEventFilter(this);
    ui->endDateEdit->installEventFilter(this);
    initButton();
    initConnect();
    init();
//    test();
}

ReportLossWidget::~ReportLossWidget()
{
    if (m_pKPosCalendarWidget != NULL)
    {
        m_pKPosCalendarWidget->deleteLater();
        m_pKPosCalendarWidget = NULL;
    }
    delete ui;
}

void ReportLossWidget::hideCalendarWidget()
{
    if (m_pKPosCalendarWidget != NULL)
    {
        m_pKPosCalendarWidget->hide();
    }
}

void ReportLossWidget::initReportLossCtrl(ReportLossCtrl *pReportLossCtrl)
{
    if(m_reportLossCtrl == NULL){
        m_reportLossCtrl = pReportLossCtrl;
        qRegisterMetaType<QList<ReportLossInfo> >("QList<ReportLossInfo>");
        connect(m_reportLossCtrl, SIGNAL(sigOnGetReportLossOrderList(int,QString,QList<ReportLossInfo>))
                , this, SLOT(slot_onGetReportLossOrderList(int,QString,QList<ReportLossInfo>)));
        connect(m_reportLossCtrl, SIGNAL(sigDeleteReportLossOrderList(int,QString))
                , this, SLOT(slot_deleteReportLossOrderList(int,QString)));
        connect(m_reportLossCtrl, SIGNAL(sigCheckReportLossOrderList(int,QString))
                , this, SLOT(slot_checkReportLossOrderList(int,QString)));
        qRegisterMetaType<QList<AddReportLossSelectInfo>>("QList<AddReportLossSelectInfo>");
        connect(m_reportLossCtrl, SIGNAL(sigOnGetReportLossDetialOrderList(int,QString,QList<AddReportLossSelectInfo>))
                , this, SLOT(slot_getReportLossDetialOrderList(int,QString,QList<AddReportLossSelectInfo>)));
        connect(m_reportLossCtrl, SIGNAL(sigOnGetPrintReportLossDetialOrder(int,QString,QList<AddReportLossSelectInfo>,int))
                , this, SLOT(slot_printReportLossDetialOrder(int,QString,QList<AddReportLossSelectInfo>,int)));
    }
}

void ReportLossWidget::printReportLossOrder(const QList<AddReportLossSelectInfo> &InfoList, int nOrderId)
{
    ReportLossPrintData reportLossData;
    reportLossData.reportLossInfoList = InfoList;
    reportLossData.sPrintTime = CommonFun::getCurDateTime();
    reportLossData.sShopName = KPosIni::getReceiptShopName();
    reportLossData.sShopCode = KPosIni::getShopCode();
    reportLossData.reportLossInfo.id = nOrderId;

    if(nOrderId > 0){
        int nLen = m_InfoList.length();
        for(int i=0; i<nLen; i++){
            if(m_InfoList[i].id == nOrderId){
                reportLossData.reportLossInfo = m_InfoList[i];
                break;
            }
        }
    }
    ReceiptPictureMaker::instance()->printReportLossInfoReceipt(reportLossData);
}

void ReportLossWidget::getReportLossOrder()
{
    m_reportLossCtrl->getReportLossOrderListRequest(m_sStartDate, m_sEndDate, m_sSearchPattern);
}

void ReportLossWidget::initData(const QList<ReportLossInfo> &itemInfoList)
{
    m_InfoList = itemInfoList;
    initButton();
    int nCount = m_InfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void ReportLossWidget::showEvent(QShowEvent *)
{
    QPoint globalPoint = ui->topWidget->mapToGlobal(QPoint(0, 0));
    const int nOffx = 11;
    int nXPos = globalPoint.x() - nOffx;
    int nYPos = globalPoint.y() + ui->searchWidget->height();
    ui->searchWidget->setKeyboardPos(nXPos, nYPos);
}

bool ReportLossWidget::eventFilter(QObject *watched, QEvent *event)
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

void ReportLossWidget::slot_onGetReportLossOrderList(int nCode, QString sMsg, QList<ReportLossInfo> orderInfoList)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("报损单列表获取失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        initData(orderInfoList);
    }
}

void ReportLossWidget::slot_deleteReportLossOrderList(int nCode, QString sMsg)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("报损单列表删除失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        getReportLossOrder();
    }
}

void ReportLossWidget::slot_checkReportLossOrderList(int nCode, QString sMsg)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("报损单列表审核失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        getReportLossOrder();
    }
}

void ReportLossWidget::slot_getReportLossDetialOrderList(int nCode, QString sMsg, QList<AddReportLossSelectInfo> orderInfoList)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("报损单明细列表获取失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        emit getReportLossDetialOrder(orderInfoList);
    }
}

void ReportLossWidget::slot_printReportLossDetialOrder(int nCode, QString sMsg, QList<AddReportLossSelectInfo> orderInfoList, int orderId)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("报损单打印明细列表获取失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        printReportLossOrder(orderInfoList, orderId);
    }
}

void ReportLossWidget::slot_clickDate(int nYear, int nMonth, int nDay)
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
            getReportLossOrder();
        }
    }
}

void ReportLossWidget::slot_clickAdjustItem(ReportLossInfo reportLossInfo)
{
    setButtonsState(reportLossInfo.status);
}

void ReportLossWidget::slot_searchChanged(QString str)
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
        m_sSearchPattern = str;
        getReportLossOrder();
    }
}

void ReportLossWidget::initConnect()
{

    qRegisterMetaType<OutStockOrderInfo>("OutStockOrderInfo");
    connect(ui->listView, SIGNAL(sigClickItem(ReportLossInfo)), this, SLOT(slot_clickAdjustItem(ReportLossInfo)));
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
}

void ReportLossWidget::initButton()
{
    int nSelectId = ui->listView->getSelectIdList();
    bool bFindNotCheck = false;
    bool bFindSelectId = false;
    bool bSelectNotCheck = false;
    int nLen = m_InfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (!bFindNotCheck && !m_InfoList[i].status)
        {
            bFindNotCheck = true;
        }
        if (!bFindSelectId && (nSelectId > 0) && m_InfoList[i].id == nSelectId)
        {
            bFindSelectId = true;
            if (!m_InfoList[i].status)
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
    ui->reviewButton->setEnabled(bFindSelectId && bSelectNotCheck);
    ui->editButton->setEnabled(bFindSelectId && bSelectNotCheck);
    ui->checkButton->setEnabled(bFindSelectId && !bSelectNotCheck);
}

void ReportLossWidget::init()
{
    ui->searchWidget->setHintText("");
}

void ReportLossWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_InfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(m_InfoList[i]);
    }
}

void ReportLossWidget::checkCurPageButtonState()
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

void ReportLossWidget::test()
{
//    int nLen = 7;
//    ReportLossInfo *reportLossInfo = NULL;
//    for (int i = 0; i < nLen; i++)
//    {
//        reportLossInfo = new ReportLossInfo;
//        reportLossInfo->id = i+1;
//        reportLossInfo->InfoID = QString("02551212522%1").arg(i+1);
//        reportLossInfo->createName = QString("小小明%1").arg(i+1);
//        reportLossInfo->createTime = QDateTime::currentDateTime().toString("MM.dd hh:mm");
//        reportLossInfo->checkName = "隔壁老王";
//        reportLossInfo->checkTime = "03.16 09:15";
//        if(i%2 == 0){
//            reportLossInfo->status = false;
//        }else{
//            reportLossInfo->status = true;
//        }
//        reportLossInfo->status = true;
//        m_InfoList.append(*reportLossInfo);
//    }
//    initData(m_InfoList);
}

void ReportLossWidget::inputStartDate()
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

void ReportLossWidget::inputEndDate()
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

void ReportLossWidget::setButtonsState(bool nState)
{
    if (nState)
    {
        ui->deleteButton->setEnabled(false);
        ui->reviewButton->setEnabled(false);
        ui->checkButton->setEnabled(true);
        ui->editButton->setEnabled(false);
    }
    else
    {
        ui->deleteButton->setEnabled(true);
        ui->reviewButton->setEnabled(true);
        ui->checkButton->setEnabled(false);
        ui->editButton->setEnabled(true);
    }
    ui->printButton->setEnabled(true);
}

void ReportLossWidget::on_nextPageButton_clicked()
{
    hideCalendarWidget();
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void ReportLossWidget::on_lastPageButton_clicked()
{
    hideCalendarWidget();
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void ReportLossWidget::on_deleteButton_clicked()
{
    hideCalendarWidget();
    int selectId = ui->listView->getSelectIdList();
    if(selectId > 0){
        if(m_reportLossCtrl != NULL){
             m_reportLossCtrl->deleteReportLossListRequest(selectId);
        }
    }
}

void ReportLossWidget::on_reviewButton_clicked()
{
    hideCalendarWidget();
    int selectId = ui->listView->getSelectIdList();
    if(selectId > 0){
        if(m_reportLossCtrl != NULL){
             m_reportLossCtrl->checkReportLossListRequest(selectId);
        }
    }
}

void ReportLossWidget::on_printButton_clicked()
{
    hideCalendarWidget();
    int nSelectKeyId = ui->listView->getSelectIdList();
    if(nSelectKeyId > 0){
        if(m_reportLossCtrl != NULL){
            m_reportLossCtrl->getReportLossDetialRequest(nSelectKeyId, 2);
        }

    }
}

void ReportLossWidget::on_checkButton_clicked()
{
    hideCalendarWidget();
    int selectId = ui->listView->getSelectIdList();
    if(selectId > 0 ){
        if(m_reportLossCtrl != NULL){
            m_reportLossCtrl->getReportLossDetialRequest(selectId, 1);
        }
        emit showDetialPage();
    }
}

void ReportLossWidget::on_editButton_clicked()
{
    hideCalendarWidget();
    int selectId = ui->listView->getSelectIdList();
    if(selectId > 0 ){
        if(m_reportLossCtrl != NULL){
            m_reportLossCtrl->getReportLossDetialRequest(selectId, 0);
        }
        emit showEditReportLossPage();
    }
}

void ReportLossWidget::on_addButton_clicked()
{
    hideCalendarWidget();
    emit showAddReportLossPage();
}
