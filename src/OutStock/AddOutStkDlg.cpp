#include "AddOutStkDlg.h"
#include "ui_AddOutStkDlg.h"
#include "../data/enumData.h"
#include "CommonFun.h"
#include "HttpSignal.h"
#include "TipsDlg.h"
#include <QDebug>
#include <QValidator>

AddOutStkDlg::AddOutStkDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddOutStkDlg)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    setModal(true);
    ui->titleWidget->setTitleText(QStringLiteral("新增出库"));
    ui->countLedit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this));
    ui->boxNumLedit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this));
    ui->priceLedit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this));
    ui->priceLedit->setFocus();
    initConnect();
    resetUI();
}

AddOutStkDlg::~AddOutStkDlg()
{
    delete ui;
}

void AddOutStkDlg::setGoodsInfo(const OutStockSelectGoodsInfo &goodsInfo)
{
    m_goodsInfo = goodsInfo;//进行一份拷贝
    QString strName = goodsInfo.sName;
    ui->goodsNameLabel->setText("商品名称:"+strName);
    ui->goodsCodeLabel->setText("商品编号:"+goodsInfo.sCode);
    ui->goodsKindLabel->setText("大类:"+goodsInfo.sBelongCategory);
    strName=goodsInfo.sWeighUnit;
    m_sMarkUnit=CommonFun::getRealInStr(strName);//取出规格单位的数字部分用于替换
    ui->goodsUnitLabel->setText("规格单位:"+m_sMarkUnit);
    ui->priceLedit->setText(CommonFun::floatToString(goodsInfo.fBatchPrice));
    ui->priceLedit->setEnabled(false);
    ui->countLedit->setText(CommonFun::floatToString(goodsInfo.fShouldCount));
    ui->subTotalLb->setText(CommonFun::floatToString(goodsInfo.fShouldTotal));
    ui->boxNumLedit->setText(goodsInfo.sBoxNum);
    ui->priceLedit->setFocus();
}

//void AddOutStkDlg::showModifyPage(float fShouldStockNum, float fShouldTotal, float fShouldPrice,const QString& fNum)
//{
//    qDebug()<<"update:"<<fNum;
//    QString tmp=fNum;
//    qDebug()<<"after:"<<tmp;
//    ui->priceLedit->setText(CommonFun::floatToString(fShouldPrice));
//    ui->countLedit->setText(CommonFun::floatToString(fShouldStockNum));
//    ui->subTotalLb->setText(CommonFun::floatToString(fShouldTotal));
//    ui->boxNumLedit->setText(tmp);
//    ui->priceLedit->setFocus();
//}

void AddOutStkDlg::setOutStockCtrl(OutStockCtrl *pStockCtrl)
{
    if (m_pStockCtrl == NULL)
    {
        m_pStockCtrl = pStockCtrl;
    }
}

void AddOutStkDlg::resetUI()
{
    ui->priceLedit->clear();
    ui->boxNumLedit->clear();
    ui->countLedit->clear();
    ui->subTotalLb->clear();
    ui->boxNumLedit->setText("0.00");
    ui->priceLedit->setText("0.00");
    ui->countLedit->setText("0.00");
}

void AddOutStkDlg::slot_Text(QString sNum)
{
    if(ui->priceLedit->hasFocus()){
        QString sText = ui->priceLedit->text().append(sNum);
        if(sText.section('.', 1, 1).length() > 2)return;
        if(sText.section('.', 0, 0).length() > 6)return;
        ui->priceLedit->setText(sText);
    }else
        slot_onEdited();
    if(ui->boxNumLedit->hasFocus()){
        QString sText = ui->boxNumLedit->text().append(sNum);
        if(sText.section('.', 1, 1).length() > 2)return;
        if(sText.section('.', 0, 0).length() > 6)return;

        ui->boxNumLedit->setText(sText);
    }else
        slot_onEdited();
    if(ui->countLedit->hasFocus()){
        QString sText = ui->countLedit->text().append(sNum);
        if(sText.section('.', 1, 1).length() > 2)return;
        if(sText.section('.', 0, 0).length() > 6)return;
        ui->countLedit->setText(sText);
    }else
        slot_onEdited();
}

void AddOutStkDlg::slot_Delete()
{

    if(ui->priceLedit->hasFocus()){
        QString sText = ui->priceLedit->text();
        sText.remove(sText.length() - 1, 1);
        ui->priceLedit->setText(sText);
    }if(ui->boxNumLedit->hasFocus()){
        QString sText = ui->boxNumLedit->text();
        sText.remove(sText.length() - 1, 1);
        ui->boxNumLedit->setText(sText);
    }
    if(ui->countLedit->hasFocus()){
        QString sText = ui->countLedit->text();
        sText.remove(sText.length() - 1, 1);
        ui->countLedit->setText(sText);
    }
}

void AddOutStkDlg::slot_Clear()
{
    if(ui->priceLedit->hasFocus()){
        ui->priceLedit->clear();
        return;
    }
    if(ui->boxNumLedit->hasFocus()){
        ui->boxNumLedit->clear();
        return;
    }
    if(ui->countLedit->hasFocus()){
        ui->countLedit->clear();
        return;
    }
}

void AddOutStkDlg::slot_Confirm()
{
    if(ui->priceLedit->hasFocus()){
        ui->countLedit->setFocus();
        return;
    }else if(ui->boxNumLedit->hasFocus()){
        ui->countLedit->setFocus();
        return;
    }else if(ui->countLedit->hasFocus()){
        on_saveButton_clicked();
    }
}

void AddOutStkDlg::on_saveButton_clicked()
{
    if(ui->boxNumLedit->text().isEmpty())
    {
        ui->boxNumLedit->setFocus();
    }
    else if(ui->priceLedit->text().isEmpty())
    {
        ui->priceLedit->setFocus();
    }else if(ui->countLedit->text().isEmpty())
    {
        ui->countLedit->setFocus();
    }else{
        m_goodsInfo.fPackage=boxNum;
        m_goodsInfo.fShouldCount=countNum;
        m_goodsInfo.fBatchPrice=price;
        m_goodsInfo.fShouldCount = newRealStockNum;
        m_goodsInfo.fShouldTotal=subTotal;
        m_goodsInfo.isEdited=true;
        emit sigAddOutStockGoods(m_goodsInfo);
        this->hide();
    }
}

void AddOutStkDlg::slot_onGetStockGoodsInfo(QString sMsg, float fBuyPrice)
{
    bool ok;
    ui->priceLedit->setText(QString::number(fBuyPrice, 'f', 2));
    ui->boxNumLedit->setText(QString::number(m_goodsInfo.fPackage, 'f', 2));
    ui->countLedit->setText(QString::number(m_goodsInfo.fShouldCount, 'f', 2));
    m_fMarkNum=sMsg.toFloat(&ok);//获取当前的量比参数
    ui->goodsUnitLabel->setText("规格单位:"+sMsg+m_sMarkUnit);
    ui->saveButton->show();
}

void AddOutStkDlg::slot_onEdited()
{//计算当前小计金额
    bool ok;
    boxNum=ui->boxNumLedit->text().toFloat(&ok);
    countNum=ui->countLedit->text().toFloat(&ok);
    newRealStockNum=countNum;
    price=ui->priceLedit->text().toFloat(&ok);;
    subTotal=price*newRealStockNum;
    ui->subTotalLb->setText(CommonFun::floatToString(subTotal));
}

void AddOutStkDlg::slot_onMark()
{
    if(ui->goodsUnitLabel->text().isEmpty())
    {//确认有规格参数进行匹配计算
        slot_onEdited();
        return;
    }

    bool ok;
    float rst(0.0f),tmp(0.0f);
    if(ui->boxNumLedit->hasFocus()){
        tmp = ui->boxNumLedit->text().toFloat(&ok);
        rst=tmp*m_fMarkNum;
        ui->countLedit->setText(CommonFun::floatToString(rst));
        slot_onEdited();
    }
    else
    {
        tmp = ui->countLedit->text().toFloat(&ok);
        rst=tmp/m_fMarkNum;
        if(tmp == 0 && m_fMarkNum == 0){
            rst = 0.0f;
        }
        ui->boxNumLedit->setText(CommonFun::floatToString(rst));
        slot_onEdited();
    }
}

void AddOutStkDlg::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(hide()));
    connect(ui->keyboardWidget, SIGNAL(sigText(QString)), this, SLOT(slot_Text(QString)));
    connect(ui->keyboardWidget, SIGNAL(sigDelete()), this, SLOT(slot_Delete()));
    connect(ui->keyboardWidget, SIGNAL(sigClear()), this, SLOT(slot_Clear()));
    connect(ui->keyboardWidget, SIGNAL(sigConfirm()), this, SLOT(slot_Confirm()));
    connect(ui->boxNumLedit,&QLineEdit::textChanged,this,&AddOutStkDlg::slot_onMark);
    connect(ui->priceLedit,&QLineEdit::textChanged,this,&AddOutStkDlg::slot_onEdited);
    connect(ui->countLedit,&QLineEdit::textChanged,this,&AddOutStkDlg::slot_onMark);
    connect(HttpSignal::instance(),&HttpSignal::sigOnGetOutStockGoodsInfo,this,&AddOutStkDlg::slot_onGetStockGoodsInfo);
}
