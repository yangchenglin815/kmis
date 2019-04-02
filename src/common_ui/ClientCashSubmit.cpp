#include "ClientCashSubmit.h"
#include "ui_ClientCashSubmit.h"
#include "../util/CommonFun.h"
#include "../util/KPosIni.h"
#include "../util/KPosServerIni.h"
#include "../HttpClient/HttpClient.h"
#include "PosInfoAgent.h"
#include <QDebug>
#include <QMessageBox>
#include <stdio.h>
#include "DlgCommon.h"
#include "PosDBFactory.h"

ClientCashSubmit::ClientCashSubmit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ClientCashSubmit)
    , m_pPosRegisterCtr(NULL)
    , m_sSubmitAmount("")
{
    ui->setupUi(this);
    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    //    setAttribute( Qt::WA_DeleteOnClose );
    init_connect();

    ui->bills_100->setValidator(new QIntValidator(0, 100000, this));
    ui->bills_50->setValidator(new QIntValidator(0, 100000, this));
    ui->bills_20->setValidator(new QIntValidator(0, 100000, this));
    ui->bills_10->setValidator(new QIntValidator(0, 100000, this));
    ui->bills_5->setValidator(new QIntValidator(0, 100000, this));
    ui->bills_1->setValidator(new QIntValidator(0, 100000, this));
    ui->bills_0_5->setValidator(new QIntValidator(0, 100000, this));
    ui->bills_0_1->setValidator(new QIntValidator(0, 100000, this));
}

ClientCashSubmit::~ClientCashSubmit()
{
    delete ui;
}

void ClientCashSubmit::init_connect()
{
    connect( ui->deleteBtn, SIGNAL(clicked()), this, SLOT( slot_dlg_close() ) );
    connect( ui->pushFrom, SIGNAL(clicked()), this, SLOT( slot_push_from() ) );

    //数字键盘
    connect( ui->DigitalKeyWnd, SIGNAL( sigText(QString)), this, SLOT( slot_setText(QString) ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigDelete()), this, SLOT( slot_deleteValue() ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigClear()), this, SLOT( slot_clearZero() ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigConfirm()), this, SLOT( slot_Confirm() ) );

    //
    QString sShopCode = KPosIni::getShopCode();
    QString sShopName = KPosIni::getShopName();
    QString sUserCode = KPosIni::getUserCode();
    QString sUserName = KPosIni::getUserName();
    QString sPosCode = KPosIni::getPosCode();
    QString sPosType = KPosServerIni::getCurPosEBalanceName();
    QString sOperateAt = KPosIni::getLoginTime();
    QString sLastSubmitAt = KPosIni::getLastHandPurseTime();
    if(sLastSubmitAt == ""){
        sLastSubmitAt = PosDBFactory::getPosDB()->m_pClientCashSubmitTable->getLastSubmitAt(sUserCode);
    }

    ui->shop_code->setText(sShopCode);
    ui->shop_name->setText(sShopName);
    ui->user_code->setText(sUserCode);
    ui->user_name->setText(sUserName);
    ui->pos_code->setText(sPosCode);
    ui->pos_type->setText(sPosType);
    ui->operate_at->setText(sOperateAt);
    ui->last_submit_at->setText(sLastSubmitAt);

}

void ClientCashSubmit::setCtrl(PosRegisterCtr *pPosRegisterCtr)
{
    if (m_pPosRegisterCtr == NULL)
    {
        m_pPosRegisterCtr = pPosRegisterCtr;
        connect(m_pPosRegisterCtr, SIGNAL(sigOnUploadClientCashSubmit(int,QString))
                , this, SLOT(slot_onUploadClientCashSubmit(int,QString)));
    }
}

QString ClientCashSubmit::getSumMoney()
{
    return m_sSubmitAmount;
}

void ClientCashSubmit::clearData()
{
    m_sSubmitAmount = "";
    ui->bills_100->setText(NULL);
    ui->bills_50->setText(NULL);
    ui->bills_20->setText(NULL);
    ui->bills_10->setText(NULL);
    ui->bills_5->setText(NULL);
    ui->bills_1->setText(NULL);
    ui->bills_0_5->setText(NULL);
    ui->bills_0_1->setText(NULL);

    QString sShopCode = KPosIni::getShopCode();
    QString sShopName = KPosIni::getShopName();
    QString sUserCode = KPosIni::getUserCode();
    QString sUserName = KPosIni::getUserName();
    QString sPosCode = KPosIni::getPosCode();
    QString sPosType = KPosServerIni::getCurPosEBalanceName();
    QString sOperateAt = KPosIni::getLoginTime();
    QString sLastSubmitAt = KPosIni::getLastHandPurseTime();
    if(sLastSubmitAt == ""){
        sLastSubmitAt = PosDBFactory::getPosDB()->m_pClientCashSubmitTable->getLastSubmitAt(sUserCode);
    }

    ui->shop_code->setText(sShopCode);
    ui->shop_name->setText(sShopName);
    ui->user_code->setText(sUserCode);
    ui->user_name->setText(sUserName);
    ui->pos_code->setText(sPosCode);
    ui->pos_type->setText(sPosType);
    ui->operate_at->setText(sOperateAt);
    ui->last_submit_at->setText(sLastSubmitAt);
}

//点击关闭按钮
void ClientCashSubmit::slot_dlg_close()
{
    DlgCommon *pDlg = new DlgCommon();
    pDlg->set_title("" );
    pDlg->set_content( "未交款是否退出?" );
    pDlg->set_btn_sure_text("退出");
    pDlg->set_btn_cancel_text("关闭交款窗口");
    connect( pDlg, SIGNAL( sig_btn_sure()), this, SLOT( mian_close()) );
    connect( pDlg, SIGNAL( sig_btn_cancel() ), this, SLOT( client_wnd_close() ) );
    connect( pDlg, SIGNAL( sig_dlg_close()), pDlg, SLOT(hide()));
    pDlg->show();
}

//点击交款按钮
void ClientCashSubmit::slot_push_from()
{
    DlgCommon *pDlg = new DlgCommon();
    pDlg->set_title( "" );
    pDlg->set_content("是否交款并退出?" );
    pDlg->set_btn_sure_text("确认");
    pDlg->set_btn_cancel_text("取消");
    connect( pDlg, SIGNAL( sig_btn_sure()), this, SLOT( push_and_close()) );
    connect( pDlg, SIGNAL( sig_btn_cancel() ), this, SLOT( client_wnd_close() ) );
    connect( pDlg, SIGNAL( sig_dlg_close()), this, SLOT( client_wnd_close()));
    pDlg->show();
    //    PosInfoAgent::instance()->pushClientCash();
}

//交款并退出
void ClientCashSubmit::push_and_close()
{
    QString sSubmitAmount =  ui->cashSum->text();
    m_sSubmitAmount = sSubmitAmount;
    QObject *pObj = QObject::sender();
    if( pObj ) {
        delete pObj;
        pObj = NULL;
    }

    if (m_pPosRegisterCtr != NULL)
    {
        m_pPosRegisterCtr->uploadClientCashSubmitRequest(sSubmitAmount);
        //         connect(m_pPosRegisterCtr, SIGNAL(sigOnUploadClientCashSubmit(int,QString))
        //                 , this, SLOT(slot_onUploadClientCashSubmit(int,QString)));
    }

    //     emit sigClose();
}

//直接退出
void ClientCashSubmit::mian_close()
{
    QObject *obj = QObject::sender();
    if( obj ) {
        delete obj;
        obj = NULL;
    }
    emit sigClose();
    //    QObject *pObj = QObject::sender();
    //    if( pObj ) {
    //        delete pObj;
    //        pObj = NULL;
    //    }
}

//关闭交款窗口
void ClientCashSubmit::client_wnd_close()
{
    QObject *obj = QObject::sender();
    if( obj ) {
        delete obj;
        obj = NULL;
    }

    this->close();
}


void ClientCashSubmit::slot_setText( QString strText )
{
    firstClick();
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if(strText == "." ) return;

    QString sText = p_wnd->text();
    QString newText = sText.append( strText );
    int nText = newText.toInt();
    if(nText > 100000){
        return;
    }
    p_wnd->setText( newText );
    calculateTotalAmount();
}

void ClientCashSubmit::slot_deleteValue()
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
    calculateTotalAmount();
}

void ClientCashSubmit::slot_clearZero()
{
    firstClick();

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    p_wnd->setText( "" );
    calculateTotalAmount();
}

void ClientCashSubmit::slot_Confirm()
{
    //    qDebug()<<"event12313";
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( ui->bills_100 == p_wnd ){
        ui->bills_50->setFocus();
    }
    if( ui->bills_50 == p_wnd ){
        ui->bills_20->setFocus();
    }
    if( ui->bills_20 == p_wnd ){
        ui->bills_10->setFocus();
    }
    if( ui->bills_10 == p_wnd ){
        ui->bills_5->setFocus();
    }
    if( ui->bills_5 == p_wnd ){
        ui->bills_1->setFocus();
    }
    if( ui->bills_1 == p_wnd ){
        ui->bills_0_5->setFocus();
    }
    if( ui->bills_0_5 == p_wnd ){
        ui->bills_0_1->setFocus();
    }
    if( ui->bills_0_1 == p_wnd ){

    }
}

void ClientCashSubmit::keyPressEvent(QKeyEvent *event)
{

    //    qDebug()<<"event12313";
    QDialog::keyPressEvent(event);
}

//软键盘输入
void ClientCashSubmit::firstClick()
{
    if( m_bFirst ) {
        QLineEdit *p_wnd = NULL;
        bool b_has_focus = getCurFocusWnd( p_wnd );
        if( !b_has_focus ) return;

        p_wnd->setText( "" );

        m_bFirst = false;
    }
}

bool ClientCashSubmit::getCurFocusWnd( QLineEdit *&pEditWnd )
{
    pEditWnd = (QLineEdit*)focusWidget();

    if( pEditWnd == ui->bills_100
            ||pEditWnd == ui->bills_50
            ||pEditWnd == ui->bills_20
            ||pEditWnd == ui->bills_10
            ||pEditWnd == ui->bills_5
            ||pEditWnd == ui->bills_1
            ||pEditWnd == ui->bills_0_5
            ||pEditWnd == ui->bills_0_1)
    {
        return true;
    }

    return false;
}

//计算上交的现金是多少
void ClientCashSubmit::calculateTotalAmount(){

    QString bills_100 = ui->bills_100->text();
    QString bills_50 = ui->bills_50->text();
    QString bills_20 = ui->bills_20->text();
    QString bills_10 = ui->bills_10->text();
    QString bills_5 = ui->bills_5->text();
    QString bills_1 = ui->bills_1->text();
    QString bills_0_5 = ui->bills_0_5->text();
    QString bills_0_1 = ui->bills_0_1->text();

    double icashSum = bills_100.toFloat() * 100
            + bills_50.toFloat() * 50
            + bills_20.toFloat() * 20
            + bills_10.toFloat() * 10
            + bills_5.toFloat() * 5
            + bills_1.toFloat() * 1
            + bills_0_5.toFloat() * 0.5
            + bills_0_1.toFloat() * 0.1;
    QString cashSum =  QString::number(icashSum, 'f', 2);

    cashSum = "￥" + cashSum ;
    ui->cashSum->setText(cashSum);
}




void ClientCashSubmit::on_bills_100_textChanged(const QString &arg1)
{
    calculateTotalAmount();
}

void ClientCashSubmit::on_bills_50_textChanged(const QString &arg1)
{
    calculateTotalAmount();
}

void ClientCashSubmit::on_bills_20_textChanged(const QString &arg1)
{
    calculateTotalAmount();
}

void ClientCashSubmit::on_bills_10_textChanged(const QString &arg1)
{
    calculateTotalAmount();
}

void ClientCashSubmit::on_bills_5_textChanged(const QString &arg1)
{
    calculateTotalAmount();
}

void ClientCashSubmit::on_bills_1_textChanged(const QString &arg1)
{
    calculateTotalAmount();
}

void ClientCashSubmit::on_bills_0_5_textChanged(const QString &arg1)
{
    calculateTotalAmount();
}

void ClientCashSubmit::on_bills_0_1_textChanged(const QString &arg1)
{
    calculateTotalAmount();
}

void ClientCashSubmit::slot_onUploadClientCashSubmit(int nCode, QString sMsg)
{
    //    if (nCode != e_success)
    //    {
    //        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("交款失败,nCode=%1,sMsg=%2").arg(nCode).arg(sMsg));
    //        emit sigClose();
    //    }
    //    else
    //    {
    //        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("交款成功"));
    QString sSubmitAmount =  ui->cashSum->text();
    m_sSubmitAmount = sSubmitAmount;
    emit sigClose();
    //    }
}


