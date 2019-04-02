#include "passwdconfigwidget.h"
#include "ui_passwdconfigwidget.h"
#include "../data/enumData.h"
#include "../callOuterDll/ReceiptPictureMaker.h"
#include "../util/KPosIni.h"
#include "../util/CommonFun.h"
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include "TipsDlg.h"
#include "constData.h"

//弹出对话框大小及间距
const int dlgWith = 700;
const int dlgHeight = 460;
const int dlgSpace = 42;

PasswdConfigWidget::PasswdConfigWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasswdConfigWidget)
    , dlg(NULL)
    , dlgx(-1)
    , dlgy(-1)
  , m_nOnePageCount(7)
  , m_nTotalPage(1)
  , m_nCurPage(1)
  , m_pEmployeeManageCtrl(NULL)
  , m_sSearchPattern("")
{
    ui->setupUi(this);
    initConnect();
    initButton();
//    test();
}

PasswdConfigWidget::~PasswdConfigWidget()
{
    delete ui;
}

void PasswdConfigWidget::initData(const QList<AccountInfo> &itemInfoList)
{
    m_InfoList = itemInfoList;
    int nCount = m_InfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();

}

void PasswdConfigWidget::on_backButton_clicked()
{
    emit sig_backHomePage();
}

void PasswdConfigWidget::initConnect(){
    connect(ui->titleBarWidget, SIGNAL(sigReturnClicked()), this, SLOT(on_backButton_clicked()));
    connect(ui->listView, SIGNAL(sigClickItem()), this, SLOT(slot_clickItem()));
    connect(ui->titleWidget, SIGNAL(sigSelectBox(bool)), this, SLOT(slot_selectCurPageAllBox(bool)));
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
}

void PasswdConfigWidget::initButton()
{
    ui->deleteButton->setEnabled(false);
    ui->stopButton->setEnabled(false);
    ui->startButton->setEnabled(false);
    ui->editButton->setEnabled(false);
}

void PasswdConfigWidget::init()
{
    ui->searchWidget->clearText();
    ui->searchWidget->setSearchFocus();
}

void PasswdConfigWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_InfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        m_InfoList[i].keyId = i + 1;
        ui->listView->appendItem(m_InfoList[i]);
    }
}

void PasswdConfigWidget::checkCurPageButtonState()
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

//测试数据
void PasswdConfigWidget::test()
{
    int nLen = 20;
    AccountInfo *accountInfo = NULL;
    for (int i = 0; i < nLen; i++)
    {
        accountInfo = new AccountInfo;
        accountInfo->id = i+1;
        accountInfo->sAccountID = QString("0000%1").arg(i+1);
        accountInfo->sName = QString("小小明%1").arg(i+1);
        accountInfo->sTelnumber = QString("1589652112%1").arg(i);
        if(i%2 == 0){
            accountInfo->sPower = "003";
            accountInfo->status = false;
        }else{
            accountInfo->sPower = "004";
            accountInfo->status = true;
        }
        m_InfoList.append(*accountInfo);
    }
    initData(m_InfoList);
}

void PasswdConfigWidget::initEmployeeList()
{
    if(m_pEmployeeManageCtrl == NULL){
        m_pEmployeeManageCtrl = new EmployeeManageCtrl;
        qRegisterMetaType<QList<AccountInfo> >("QList<AccountInfo>");
        connect(m_pEmployeeManageCtrl, SIGNAL(sigOnGetEmployeeManageList(int,QString,QList<AccountInfo>)), this, SLOT(slot_getEmployeeManageList(int,QString,QList<AccountInfo>)));
        connect(m_pEmployeeManageCtrl, SIGNAL(sigChangeEmployeeStatusOrder(int,QString,QList<int>,int)), this, SLOT(slot_changeEmployeeStatusOrder(int,QString,QList<int>,int)));
        connect(m_pEmployeeManageCtrl, SIGNAL(sigOnGetEmployeeScodeOrder(int,QString,QString)), this, SLOT(slot_getEmployeeScodeOrder(int,QString,QString)));
    }
    m_pEmployeeManageCtrl->getEmployeeManageListRequest(m_sSearchPattern);
}

void PasswdConfigWidget::setCheckedBtnStatus()
{
    ui->deleteButton->setEnabled(true);
    ui->stopButton->setEnabled(true);
    ui->startButton->setEnabled(true);
}

void PasswdConfigWidget::setUncheckedBtnStatus()
{
    ui->deleteButton->setEnabled(false);
    ui->stopButton->setEnabled(false);
    ui->startButton->setEnabled(false);
    ui->editButton->setEnabled(false);
}

void PasswdConfigWidget::showEvent(QShowEvent *)
{
    QPoint globalPoint = ui->topWidget->mapToGlobal(QPoint(0, 0));
    const int nOffx = 11;
    int nXPos = globalPoint.x() - nOffx;
    int nYPos = globalPoint.y() + ui->searchWidget->height();
    ui->searchWidget->setKeyboardPos(nXPos, nYPos);
    dlgx = nXPos + dlgSpace;
    dlgy = nYPos;
}

void PasswdConfigWidget::slot_employeeListChanged()
{
    if(m_pEmployeeManageCtrl != NULL){
        m_pEmployeeManageCtrl->getEmployeeManageListRequest("");
        generateUI();
    }
}

void PasswdConfigWidget::slot_getEmployeeManageList(int nCode, QString sMsg, QList<AccountInfo> orderInfoList)
{
    if(nCode != e_success){
        TipsDlg::instance()->releaseCtrl(QStringLiteral("员工管理列表获取失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
        {
        initData(orderInfoList);
    }
}

void PasswdConfigWidget::slot_changeEmployeeStatusOrder(int nCode, QString sMsg, QList<int> orderList, int status)
{
    if(nCode != e_success)
    {
        if(status == c_sRemoveEmployee){
            TipsDlg::instance()->releaseCtrl(QStringLiteral("员工删除失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
        }
        else if(status == c_sStartEmployee){
            TipsDlg::instance()->releaseCtrl(QStringLiteral("员工启用失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
        }
        else if(status == c_sStopEmployee){
            TipsDlg::instance()->releaseCtrl(QStringLiteral("员工禁用失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
        }
    }
    else
    {
        QList<int> numList;
        int nLen = m_InfoList.length();
        for (int i = 0; i < nLen; i++)
        {
            if (orderList.contains(m_InfoList[i].id))
            {
                if(status == c_sRemoveEmployee){
                    numList.append(i);
                }
                else if(status == c_sStartEmployee){
                    m_InfoList[i].status = 1;
                }
                else if(status == c_sStopEmployee){
                    m_InfoList[i].status = 0;
                }
            }
        }
        if(status == c_sRemoveEmployee){
            for(int i=0; i<numList.length(); i++){
                m_InfoList.removeAt(numList.at(i)-i);

            }
        }
        ui->listView->clearSecectIdList();
        generateUI();
    }
}

void PasswdConfigWidget::slot_getEmployeeScodeOrder(int nCode, QString sMsg, QString nScode)
{
    if(nCode != e_success){
        TipsDlg::instance()->releaseCtrl(QStringLiteral("员工编号获取失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        if(dlg != NULL){
             dlg->setEmployeeScode(nScode);
        }
    }
}

void PasswdConfigWidget::slot_selectCurPageAllBox(bool bSelectAll)
{
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_InfoList.length();
    QList<int> keyIdList;
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        keyIdList.append(m_InfoList[i].id);
    }

    if (bSelectAll)
    {
        ui->listView->appendSelectKeyIds(keyIdList);
        setCheckedBtnStatus();
    }
    else
    {
        ui->listView->removeSelectKeyIds(keyIdList);
        setUncheckedBtnStatus();
    }

    generateUI();

    slot_clickItem();
}

void PasswdConfigWidget::updateUI(int count)
{
    m_nTotalPage = count / m_nOnePageCount + ((count % m_nOnePageCount == 0) ? 0 : 1);
    if(m_nTotalPage <= 0){
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
}

void PasswdConfigWidget::slot_searchChanged(QString str)
{
    ui->listView->clearItems();
    int nLen = m_InfoList.length();
    if(!str.isEmpty()){
        int count = 0;
        for(int i=0; i<nLen; i++){
            if(m_InfoList[i].sName.contains(str)){
                count++;
                ui->listView->appendItem(m_InfoList[i]);
            }
            else if(m_InfoList[i].sAccountID == str){
                count++;
                ui->listView->appendItem(m_InfoList[i]);
            }
        }
        updateUI(count);
        return;
    }
    else{
        m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
        if(m_nTotalPage <= 0){
            m_nTotalPage = 1;
        }
        checkCurPageButtonState();
        generateUI();
    }
}

void PasswdConfigWidget::slot_clickItem()
{
    QList<int> keyIdList;
    ui->listView->getSelectIdList(keyIdList);
    switch (keyIdList.length()) {
    case 0:
        setUncheckedBtnStatus();
        break;
    case 1:
        setCheckedBtnStatus();
        ui->editButton->setEnabled(true);
        break;
    default:
        setCheckedBtnStatus();
        ui->editButton->setEnabled(false);
        break;
    }
    int nStartCount = 0; // 被选中的启用项数量
    int nStopCount = 0; // 被选中的禁用项数量
    for(int i=0; i<m_InfoList.length(); i++){
        if(keyIdList.contains(m_InfoList[i].id)){
            if(m_InfoList[i].status == 1){
               nStartCount++;
            }
            else if(m_InfoList[i].status == 0){
                nStopCount++;
            }
        }
    }
    // 通过启用和禁用状态设置按钮状态
    if(nStartCount != 0 && nStartCount == keyIdList.length()){
        ui->startButton->setEnabled(false);
        ui->stopButton->setEnabled(true);
        ui->deleteButton->setEnabled(false);
    }
    else if(nStopCount != 0 && nStopCount == keyIdList.length()){
        ui->startButton->setEnabled(true);
        ui->stopButton->setEnabled(false);
        ui->deleteButton->setEnabled(true);
    }
    else{
        ui->startButton->setEnabled(false);
        ui->stopButton->setEnabled(false);
        ui->deleteButton->setEnabled(false);
    }
    emit sigUpdateSelectCount(keyIdList);
}

void PasswdConfigWidget::on_addButton_clicked()
{
    ui->searchWidget->hideKeyboard();
    if(dlg == NULL){
        dlg = new FuncDlg();
        connect(dlg, SIGNAL(sigEmployeeListChanged()), this, SLOT(slot_employeeListChanged()));
    }
    if(m_pEmployeeManageCtrl != NULL){
        dlg->initEmployeeManageCtrl(m_pEmployeeManageCtrl);
        m_pEmployeeManageCtrl->getEmployeeScodeOrderRequest();
    }
    dlg->initEditStatus(1);
    dlg->activateWindow();
    dlg->setFixedSize(dlgWith, dlgHeight);
    dlg->move(dlgx, dlgy);
    dlg->setTitleText("新建员工");
    dlg->clearData();
    dlg->show();
}

void PasswdConfigWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void PasswdConfigWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void PasswdConfigWidget::on_deleteButton_clicked()
{
    ui->searchWidget->hideKeyboard();
    QList<int> idSelectedList;
    ui->listView->getSelectIdList(idSelectedList);
    if(idSelectedList.length() > 0 ){
        if(m_pEmployeeManageCtrl != NULL){
            m_pEmployeeManageCtrl->changeEmployeeStatusOrderRequest(idSelectedList, c_sRemoveEmployee);
        }
    }
}

void PasswdConfigWidget::on_stopButton_clicked()
{
    ui->searchWidget->hideKeyboard();
    QList<int> idSelectedList;
    ui->listView->getSelectIdList(idSelectedList);
    if(idSelectedList.length() > 0 ){
        if(m_pEmployeeManageCtrl != NULL){
            m_pEmployeeManageCtrl->changeEmployeeStatusOrderRequest(idSelectedList, c_sStopEmployee);
        }
    }
}

void PasswdConfigWidget::on_startButton_clicked()
{
    ui->searchWidget->hideKeyboard();
    QList<int> idSelectedList;
    ui->listView->getSelectIdList(idSelectedList);
    if(idSelectedList.length() > 0 ){
        if(m_pEmployeeManageCtrl != NULL){
            m_pEmployeeManageCtrl->changeEmployeeStatusOrderRequest(idSelectedList, c_sStartEmployee);
        }
    };
}

void PasswdConfigWidget::on_editButton_clicked()
{
    ui->searchWidget->hideKeyboard();
    QList<int> idSelectedList;
    ui->listView->getSelectIdList(idSelectedList);
    if(idSelectedList.length() == 1 ){
        AccountInfo info;
        int selectId = idSelectedList.at(0);
        for(int i=0; i<m_InfoList.length(); i++){
            if(m_InfoList[i].id == selectId){
                info.id = m_InfoList[i].id;
                info.sAccountID = m_InfoList[i].sAccountID;
                info.sName = m_InfoList[i].sName;
                info.sPower = m_InfoList[i].sPower;
                info.sTelnumber = m_InfoList[i].sTelnumber;
            }
        }
        if(dlg == NULL){
            dlg = new FuncDlg();
            connect(dlg, SIGNAL(sigEmployeeListChanged()), this, SLOT(slot_employeeListChanged()));
        }
        if(m_pEmployeeManageCtrl != NULL){
            dlg->initEmployeeManageCtrl(m_pEmployeeManageCtrl);
        }
        dlg->initEditContent(info);
        dlg->initEditStatus(0);
        dlg->activateWindow();
        dlg->setFixedSize(dlgWith, dlgHeight);
        dlg->move(dlgx, dlgy);
        dlg->setTitleText("编辑员工");
        dlg->show();
    }
}

