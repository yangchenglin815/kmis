#include "ResetKeyWgt.h"
#include "ui_ResetKeyWgt.h"
#include "ScreenInfo.h"
#include "KPosIni.h"
#include "KPosLog.h"
#include "PosDBFactory.h"
#include <QDebug>
#include "TipsDlg.h"

#define WidthSpace 20

ResetKeyWgt::ResetKeyWgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResetKeyWgt), m_pCtrl(NULL)
{
    ui->setupUi(this);
    setWindowFlags( Qt::FramelessWindowHint );//去掉标题栏
    m_pCtrl = new ResetKeyCtrl;
    initConnect();
    ui->oldKey->setMaxLength(6);
    ui->newKey->setMaxLength(6);
    ui->newKeyRepeat->setMaxLength(6);
}

ResetKeyWgt::~ResetKeyWgt()
{
    delete ui;
}

void ResetKeyWgt::on_backButton_clicked(){
    clearData();
    emit sig_backHomePage();
}

void ResetKeyWgt::initConnect(){
    connect(ui->titleWgt, SIGNAL(sigReturnClicked()), this, SLOT(on_backButton_clicked()));
    connect(ui->keyboardWgt, SIGNAL(sigText(QString)), this, SLOT(slot_setText(QString)));
    connect(ui->keyboardWgt, SIGNAL(sigClear()), this, SLOT(slot_clear()));
    connect(ui->keyboardWgt, SIGNAL(sigConfirm()), this, SLOT(slot_confirm()));
    connect(ui->keyboardWgt, SIGNAL(sigDelete()), this, SLOT(slot_delete()));
    connect(ui->confirmBtn, SIGNAL(clicked()), this, SLOT(slot_confirm_clicked()));
    connect(m_pCtrl, SIGNAL(sigResetPasswd(int,QString)), this, SLOT(slot_resetPasswd(int,QString)));
}

void ResetKeyWgt::slot_resetPasswd(int nCode, QString sMsg){
    if(nCode != e_success)
    {
         ui->tipLabel->setText(QStringLiteral("服务器无响应,修改失败！"));
         KPosLog::instance()->writeErrorLog(QString("reset passwd failed:%1").arg(sMsg));
    }
    else
    {
         ui->tipLabel->setText(QStringLiteral("修改成功！"));
         KPosIni::setPassword(ui->newKey->text());
         QString user = KPosIni::getUserCode();
         QString newkey = KPosIni::getPassword();
         PosDBFactory::getPosDB()->m_pSalesmanInfoTable->updateSalemanPasswd(user, newkey);
         TipsDlg::instance()->releaseCtrl(QStringLiteral("密码修改成功!"));
         emit sig_backHomePage();
    }
}

void ResetKeyWgt::slot_setText(QString str){
    if (ui->oldKey->hasFocus())
    {
        QString sText = ui->oldKey->text();
        ui->oldKey->setText(sText.append(str));
    }
    else if (ui->newKey->hasFocus())
    {
        QString sText = ui->newKey->text();
        ui->newKey->setText(sText.append(str));
    }
    else if (ui->newKeyRepeat->hasFocus())
    {
        QString sText = ui->newKeyRepeat->text();
        ui->newKeyRepeat->setText(sText.append(str));
    }
}

void ResetKeyWgt::slot_clear(){
    if (ui->oldKey->hasFocus())
    {
        ui->oldKey->clear();
    }
    else if (ui->newKey->hasFocus())
    {
        ui->newKey->clear();
    }
    else if (ui->newKeyRepeat->hasFocus())
    {
        ui->newKeyRepeat->clear();
    }
}

void ResetKeyWgt::slot_confirm(){
    slot_confirm_clicked();
}

void ResetKeyWgt::slot_delete(){
    if (ui->oldKey->hasFocus())
    {
        QString sText = ui->oldKey->text();
        sText.remove(sText.length() - 1, 1);
        ui->oldKey->setText(sText);
    }
    else if (ui->newKey->hasFocus())
    {
        QString sText = ui->newKey->text();
        sText.remove(sText.length() - 1, 1);
        ui->newKey->setText(sText);
    }
    else if (ui->newKeyRepeat->hasFocus())
    {
        QString sText = ui->newKeyRepeat->text();
        sText.remove(sText.length() - 1, 1);
        ui->newKeyRepeat->setText(sText);
    }
}

void ResetKeyWgt::slot_confirm_clicked(){
    ui->tipLabel->setText( "" );

    if (ui->oldKey->text().isEmpty())
    {
        ui->oldKey->setFocus();
        ui->tipLabel->setText(QStringLiteral("请输入原密码！"));
        ui->tipLabel->show();
        return;
    }
    else if (ui->newKey->text().isEmpty())
    {
        ui->newKey->setFocus();
        ui->tipLabel->setText(QStringLiteral("请输入新密码！"));
        ui->tipLabel->show();
        return;
    }
    else if (ui->newKeyRepeat->text().isEmpty())
    {
        ui->newKeyRepeat->setFocus();
        ui->tipLabel->setText(QStringLiteral("请再次输入新密码！"));
        ui->tipLabel->show();
        return;
    }
    if(ui->oldKey->text() != KPosIni::getPassword()){
        clearData();
        ui->tipLabel->setText(QStringLiteral("原密码错误,请重新输入！"));
        return;
    }
    else if(ui->newKey->text() != ui->newKeyRepeat->text()){
        ui->tipLabel->setText(QStringLiteral("两次密码不一致,请重新输入！"));
        ui->newKey->setText("");
        ui->newKeyRepeat->setText("");
        return;
    }
    else if(ui->oldKey->text() == ui->newKey->text()){
        ui->tipLabel->setText(QStringLiteral("新密码与原密码一致,请重新输入！"));
        ui->newKey->setText("");
        ui->newKeyRepeat->setText("");
        return;
    }

    ui->tipLabel->setText(QStringLiteral("提交中..."));
    QString oldkey = ui->oldKey->text();
    QString newkey = ui->newKey->text();

    m_pCtrl->resetKeyRequest(oldkey, newkey);
}

void ResetKeyWgt::clearData(){
    ui->oldKey->setText("");
    ui->newKey->setText("");
    ui->newKeyRepeat->setText("");
    ui->tipLabel->setText("");
}

void ResetKeyWgt::showEvent(QShowEvent *)
{
    int nCentorX = getCentorPosX();

    setLoginInfoWidgetPos();
    setKeyBoardPos();

}

int ResetKeyWgt::getCentorPosX()
{
    int nWidth = width();

    return nWidth/2;
}

void ResetKeyWgt::setLoginInfoWidgetPos()
{
    int nHeight = height();

    int nInfoWidth = ui->resetKeyInfoWgt->width();
    int nInfoHeight = ui->resetKeyInfoWgt->height();

    int nCentorX = getCentorPosX();

    int nInfoX = nCentorX - WidthSpace - nInfoWidth;
    int nInfoY = ( nHeight - nInfoHeight )/2;
    ui->resetKeyInfoWgt->move( nInfoX, nInfoY );
}

void ResetKeyWgt::setKeyBoardPos()
{
    int nHeight = height();
    int nKeyHeight = ui->keyboardWgt->height();

    int nCentorX = getCentorPosX();

    int nKeyX = nCentorX + WidthSpace;
    int nKeyY = ( nHeight - nKeyHeight )/2;
    ui->keyboardWgt->move( nKeyX, nKeyY );
}
