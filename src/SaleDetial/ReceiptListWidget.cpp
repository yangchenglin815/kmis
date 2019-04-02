#include "ReceiptListWidget.h"
#include "ui_ReceiptListWidget.h"
#include "CommonFun.h"
#include "TipsDlg.h"

ReceiptListWidget::ReceiptListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReceiptListWidget)
  , m_nOnePageCount(7)
  , m_nTotalPage(1)
  , m_nCurPage(1)
  , m_sStartDate("")
  , m_sEndDate("")
  , m_pKPosCalendarWidget(NULL)
  , m_saleDetialCtrl(NULL)
{
    ui->setupUi(this);
    ui->startDateEdit->installEventFilter(this);
    ui->endDateEdit->installEventFilter(this);
    ui->searchWidget->setHintText("搜索小票编号、员工编号、姓名");
    initconnect();
//    test();
}

ReceiptListWidget::~ReceiptListWidget()
{
    if (m_pKPosCalendarWidget != NULL)
    {
        m_pKPosCalendarWidget->deleteLater();
        m_pKPosCalendarWidget = NULL;
    }
    delete ui;
}

void ReceiptListWidget::initData(const QList<ReceiptInfo> &itemInfoList)
{
    m_InfoList = itemInfoList;
    initButton();
    int nCount = m_InfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if(m_nTotalPage <= 0){
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void ReceiptListWidget::hideCalendarWidget()
{
    if (m_pKPosCalendarWidget != NULL)
    {
        m_pKPosCalendarWidget->hide();
    }
}

void ReceiptListWidget::initContent()
{
    ui->searchWidget->setText("");
    ui->startDateEdit->setText("");
    ui->endDateEdit->setText("");
}

void ReceiptListWidget::initSaleDetialCtrl(SaleDetialCtrl *ctrl)
{
    if(m_saleDetialCtrl == NULL){
        m_saleDetialCtrl = ctrl;
        qRegisterMetaType<QList<SaleDetails> >("QList<SaleDetails>");
        connect(m_saleDetialCtrl, SIGNAL(sigOnGetSaleReceiptOrder(int,QString,SaleHead,QList<SaleDetails>,QList<PaymentDetailInfo>))
                , this, SLOT(slot_getSaleReceiptOrder(int,QString,SaleHead,QList<SaleDetails>,QList<PaymentDetailInfo>)));
    }
}

void ReceiptListWidget::showEvent(QShowEvent *)
{
    QPoint globalPoint = ui->topWidget->mapToGlobal(QPoint(0, 0));
    const int nOffx = 11;
    int nXPos = globalPoint.x() - nOffx;
    int nYPos = globalPoint.y() + ui->searchWidget->height();
    ui->searchWidget->setKeyboardPos(nXPos, nYPos);
}

bool ReceiptListWidget::eventFilter(QObject *watched, QEvent *event)
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

void ReceiptListWidget::slot_ClickItem(ReceiptInfo receiptInfo)
{
    int state = receiptInfo.state;
    if(state > 0){
        ui->checkButton->setEnabled(true);
    }
    else
    {
        ui->checkButton->setEnabled(false);
    }
}

void ReceiptListWidget::slot_getSaleReceiptOrder(int nCode, QString sMsg, SaleHead saleHead, QList<SaleDetails> infoList, QList<PaymentDetailInfo> paymentInfoList)
{
   emit sigGetSaleReceiptOrder(nCode, sMsg, saleHead, infoList, paymentInfoList);
}

void ReceiptListWidget::slot_clickDate(int nYear, int nMonth, int nDay)
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
            QString str;
            slot_searchChanged(str);
        }
    }
}

void ReceiptListWidget::slot_searchChanged(QString keyStr)
{
    int nLen = m_InfoList.length();
    ui->listView->clearItems();
    if(keyStr.isEmpty() && m_sStartDate.isEmpty() && m_sEndDate.isEmpty()){
        m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
        if(m_nTotalPage <= 0){
            m_nTotalPage = 1;
        }
        checkCurPageButtonState();
        generateUI();
        return;
    }
    else if(keyStr.isEmpty()){
        int count = 0;
        for(int i=0; i<nLen; i++){
            if(m_InfoList[i].bDealTime >= m_sStartDate && m_InfoList[i].bDealTime <= m_sEndDate){
                ui->listView->appendItems(m_InfoList[i]);
                count++;
            }
        }
        updateUI(count);
    }
    else if(m_sStartDate.isEmpty() || m_sEndDate.isEmpty()){
        int count = 0;
        for(int i=0; i<nLen; i++){
            if(m_InfoList[i].bSaleman.contains(keyStr) || m_InfoList[i].salemanId == keyStr
                    || m_InfoList[i].bSaleGuide.contains(keyStr) || m_InfoList[i].saleGuideId == keyStr
                    || m_InfoList[i].bScode == keyStr){
                ui->listView->appendItems(m_InfoList[i]);
                count++;
            }
        }
        updateUI(count);
    }
    else{
        int count = 0;
        for(int i=0; i<nLen; i++){
            if(m_InfoList[i].bDealTime >= m_sStartDate && m_InfoList[i].bDealTime <= m_sEndDate){
                if(m_InfoList[i].bSaleman.contains(keyStr) || m_InfoList[i].salemanId == keyStr
                        || m_InfoList[i].bSaleGuide.contains(keyStr) || m_InfoList[i].saleGuideId == keyStr
                        || m_InfoList[i].bScode == keyStr){
                    ui->listView->appendItems(m_InfoList[i]);
                    count++;
                }
            }
        }
        updateUI(count);
    }
}

void ReceiptListWidget::test()
{
    int nLen = 20;
    ReceiptInfo *receiptInfo = NULL;
    for(int i=0;i<nLen;i++){
        receiptInfo = new ReceiptInfo;
        receiptInfo->bScode = QString("000215152123455%1").arg(i);
        receiptInfo->bSaleman = "小明";
        receiptInfo->bSaleGuide = "隔壁老王";
        receiptInfo->bDealTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        receiptInfo->type = 3;
        receiptInfo->state = 1;
        m_InfoList.append(*receiptInfo);
    }
    initData(m_InfoList);
}

void ReceiptListWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_InfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        m_InfoList[i].id = i+1;
        ui->listView->appendItems(m_InfoList[i]);
    }
}

void ReceiptListWidget::checkCurPageButtonState()
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

void ReceiptListWidget::inputStartDate()
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

void ReceiptListWidget::inputEndDate()
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

void ReceiptListWidget::updateUI(int count)
{
    m_nTotalPage = count / m_nOnePageCount + ((count % m_nOnePageCount == 0) ? 0 : 1);
    if(m_nTotalPage <= 0){
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
}

void ReceiptListWidget::on_lastPageButton_clicked()
{
    hideCalendarWidget();
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void ReceiptListWidget::on_nextPageButton_clicked()
{
    hideCalendarWidget();
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void ReceiptListWidget::initconnect()
{
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
    connect(ui->listView, SIGNAL(sigClickItem(ReceiptInfo)), this, SLOT(slot_ClickItem(ReceiptInfo)));
}

void ReceiptListWidget::initButton()
{
    QString nSelectId = ui->listView->getSelectIdList();
    bool bFindSelectId = false;
    int nLen = m_InfoList.length();
    for (int i = 0; i < nLen; i++)
    {
       if(m_InfoList[i].state > 0 && m_InfoList[i].bScode == nSelectId){
           bFindSelectId = true;
       }
    }
    ui->checkButton->setEnabled(bFindSelectId);
}

void ReceiptListWidget::on_checkButton_clicked()
{
    hideCalendarWidget();
    QString selectId = ui->listView->getSelectIdList();
    if(m_saleDetialCtrl != NULL){
        m_saleDetialCtrl->getSaleReceiptListRequest(selectId);
    }
    emit sigShowDetialPage();
}
