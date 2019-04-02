#include "FuncDlg.h"
#include "ui_FuncDlg.h"
#include "constData.h"
#include "TipsDlg.h"

FuncDlg::FuncDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FuncDlg)
    , m_bFirst(true)
    , RadioBtnGroup(NULL)
    , m_pEmployeeManageCtrl(NULL)
    , m_editStatus(-1)
{
    ui->setupUi(this);
    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    ui->nameWidget->setOuterLineColor(f_fontColorOrange);
    ui->nameWidget->setHolderText("");
    ui->nameWidget->resetStyleSheet();
    ui->nameWidget->setSearchEditMaxLength(8);
    ui->passwdEdit->setMaxLength(6);
    ui->telEdit->setMaxLength(11);
    initButton();
    initConnect();
    init();
}

FuncDlg::~FuncDlg()
{
    delete ui;
}

void FuncDlg::setTitleText(QString Text)
{
    ui->titleWidget->setTitleText(Text);
}

void FuncDlg::clearData()
{
    ui->nameWidget->clearText();
    ui->passwdEdit->setText("");
    ui->telEdit->setText("");
    ui->noValueLabel->setText("");
    ui->radioButton1->setChecked(true);
}

void FuncDlg::setEmployeeScode(QString nScode)
{
    ui->noValueLabel->setText(nScode);
}

void FuncDlg::initEmployeeManageCtrl(EmployeeManageCtrl *pEmployeeManageCtrl)
{
    if(m_pEmployeeManageCtrl == NULL){
        m_pEmployeeManageCtrl = pEmployeeManageCtrl;
        connect(m_pEmployeeManageCtrl, SIGNAL(sigOnEditEmployeeOrder(int,QString))
                , this, SLOT(slot_editEmployeeOrder(int,QString)));
    }
}

void FuncDlg::initEditStatus(int status)
{
    m_editStatus = status;
}

void FuncDlg::initEditContent(AccountInfo info)
{
    m_info = info;
    ui->noValueLabel->setText(info.sAccountID);
    ui->nameWidget->setText(info.sName);
    ui->passwdEdit->setText("******");
    ui->telEdit->setText(info.sTelnumber);
    if(info.sPower == c_sShopKeeper){
        ui->radioButton1->setChecked(true);
    }
    else if(info.sPower == c_sSaleman){
        ui->radioButton2->setChecked(true);
    }
    else if(info.sPower == c_sSaleGuide){
        ui->radioButton3->setChecked(true);
    }
}

void FuncDlg::showEvent(QShowEvent *)
{
    QPoint globalPoint = ui->nameLabel->mapToGlobal(QPoint(0, 0));
    const int nOffx = 11;
    int nXPos = globalPoint.x() - nOffx;
    int nYPos = globalPoint.y() + ui->nameLabel->height() - nOffx;
    ui->nameWidget->setKeyboardPos(nXPos, nYPos);
}

void FuncDlg::slot_close_dlg()
{
    hide();
}

void FuncDlg::slot_setText(QString strText)
{
    firstClick();

    //非会员卡结算
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( p_wnd == ui->telEdit && p_wnd->text().isEmpty() && strText == "." ) return;

    QString sText = p_wnd->text();
    p_wnd->setText( sText.append( strText ) );
}

void FuncDlg::slot_deleteValue()
{
    if( m_bFirst ) {
        m_bFirst = false;
    }

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    QString str_value = p_wnd->text();
    str_value.remove( str_value.length() - 1, 1);
    p_wnd->setText( str_value );
}

void FuncDlg::slot_clearZero()
{
    firstClick();
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;
    p_wnd->setText( "" );
}

void FuncDlg::slot_enter()
{
    on_saveButton_clicked();
}

void FuncDlg::init()
{

}

void FuncDlg::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(slot_close_dlg()));
    connect(ui->keyboardWgt, SIGNAL(sigClear()), this, SLOT(slot_clearZero()));
    connect(ui->keyboardWgt, SIGNAL(sigConfirm()), this, SLOT(slot_enter()));
    connect(ui->keyboardWgt, SIGNAL(sigDelete()), this, SLOT(slot_deleteValue()));
    connect(ui->keyboardWgt, SIGNAL(sigText(QString)), this, SLOT(slot_setText(QString)));
}

void FuncDlg::initButton()
{
    RadioBtnGroup = new QButtonGroup;
    RadioBtnGroup->addButton(ui->radioButton1, 0);
    RadioBtnGroup->addButton(ui->radioButton2, 1);
    RadioBtnGroup->addButton(ui->radioButton3, 2);
    ui->radioButton1->setChecked(false);
    ui->radioButton2->setChecked(false);
    ui->radioButton3->setChecked(false);
}

void FuncDlg::firstClick()
{
    if( m_bFirst ) {
        QLineEdit *p_wnd = NULL;
        bool b_has_focus = getCurFocusWnd( p_wnd );
        if( !b_has_focus ) return;
        p_wnd->setText( "" );
        m_bFirst = false;
    }
}

bool FuncDlg::getCurFocusWnd( QLineEdit *&pEditWnd )
{
    pEditWnd = (QLineEdit*)focusWidget();
    if( ui->passwdEdit == pEditWnd
            || ui->telEdit == pEditWnd ) {
        return true;
    }
    return false;
}

void FuncDlg::clearEditContent()
{
    ui->noValueLabel->setText("");
    ui->nameWidget->clearText();
    ui->passwdEdit->setText("");
    ui->telEdit->setText("");
    ui->radioButton1->setChecked(false);
    ui->radioButton2->setChecked(false);
    ui->radioButton3->setChecked(false);
}

void FuncDlg::on_saveButton_clicked()
{
   ui->tipLabel->setText("");
   if(ui->nameWidget->getText().isEmpty()){
       ui->nameWidget->setSearchFocus();
       ui->tipLabel->setText(QStringLiteral("员工姓名不能为空!"));
       return;
   }
   else if(ui->nameWidget->getText().length()>12){
       ui->nameWidget->setSearchFocus();
       ui->tipLabel->setText(QStringLiteral("员工姓名不能超过12个字符!"));
       ui->nameWidget->clearText();
       return;
   }
   else if(ui->passwdEdit->text().isEmpty()){
       ui->passwdEdit->setFocus();
       ui->tipLabel->setText(QStringLiteral("员工密码不能为空!"));
        return;
   }
   else if(ui->passwdEdit->text().length()>6){
       ui->passwdEdit->setFocus();
       ui->tipLabel->setText(QStringLiteral("员工密码不能超过6位!"));
       ui->passwdEdit->setText("");
        return;
   }
   else if(ui->telEdit->text().isEmpty()){
       ui->telEdit->setFocus();
   }
   else if(ui->telEdit->text().length()>11){
       ui->telEdit->setFocus();
       ui->tipLabel->setText(QStringLiteral("手机号码不能超过11位!"));
       ui->telEdit->setText("");
        return;
   }
   else if(RadioBtnGroup->checkedId() == -1){
       ui->powerLabel->setFocus();
       ui->tipLabel->setText(QStringLiteral("请选择角色权限!"));
        return;
   }
   AccountInfo m_accountInfo;
   m_accountInfo.sName = ui->nameWidget->getText();
   if(ui->passwdEdit->text() == "******"){
       m_accountInfo.sPasswd = "";
   }
   else
   {
       m_accountInfo.sPasswd = ui->passwdEdit->text();
   }
   m_accountInfo.sTelnumber = ui->telEdit->text();
   m_accountInfo.status = false;
   m_accountInfo.sAccountID = ui->noValueLabel->text();
   m_accountInfo.id = m_info.id;
   switch (RadioBtnGroup->checkedId()) {
   case 0:
       m_accountInfo.sPower = c_sShopKeeper;
       break;
   case 1:
       m_accountInfo.sPower = c_sSaleman;
       break;
   case 2:
       m_accountInfo.sPower = c_sSaleGuide;
       break;
   }
   if(m_pEmployeeManageCtrl != NULL){
        m_pEmployeeManageCtrl->EditEmployeeOrderRequest(m_accountInfo, m_editStatus);
   }
   clearEditContent();
   this->hide();
}

void FuncDlg::slot_editEmployeeOrder(int nCode, QString sMsg)
{
    if(nCode != e_success){
        TipsDlg::instance()->releaseCtrl(QStringLiteral("编辑员工信息失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("编辑员工信息成功!"));
        emit sigEmployeeListChanged();
    }
}
