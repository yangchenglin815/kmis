#include "StockDlg.h"
#include "ui_StockDlg.h"
#include "../data/enumData.h"
#include "WarningDlg.h"
StockDlg::StockDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StockDlg)
    , m_pStockCtrl(NULL)
    , m_fBuyPrice(0.0f)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->titleWidget->setTitleText(QStringLiteral("盘点数量"));
    ui->realStockEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this));
    ui->addStockNumEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this));
    ui->reduceStockNumEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this));
    initConnect();
}

StockDlg::~StockDlg()
{
    delete ui;
}

void StockDlg::setGoodsInfo(const StockSelectGoodsInfo &goodsInfo)
{
    m_goodsInfo = goodsInfo;

    QString strName = "";
    if( goodsInfo.sShortName.isEmpty() ) {
        strName = goodsInfo.sName;
    } else {
        strName = goodsInfo.sShortName;
    }

    ui->goodsNameLabel->setText(QStringLiteral("%1(%2)").arg(strName).arg(goodsInfo.sWeighUnit));
    ui->goodsCodeLabel->setText(goodsInfo.sCode);
    ui->hintLabel->setText(QStringLiteral("正在查询商品的库存信息..."));
    ui->saveButton->hide();
}

void StockDlg::showAddPage()
{
    ui->stackedWidget->setCurrentWidget(ui->addPage);
    ui->realStockEdit->setText("");
    ui->realStockEdit->setFocus();
    ui->hintLabel->setText(QStringLiteral("正在查询商品的库存信息..."));
    ui->saveButton->hide();
}

void StockDlg::showModifyPage(float fShouldStockNum, float fLastRealStockNum)
{
    ui->stackedWidget->setCurrentWidget(ui->modifyPage);
    ui->shoudStock2Label->setText(QString::number(fShouldStockNum, 'f', 2));
    ui->lastRealStockLabel->setText(QString::number(fLastRealStockNum, 'f', 2));
    ui->addStockNumEdit->setText("");
    ui->addStockNumEdit->setFocus();
    ui->reduceStockNumEdit->setText("");

}

void StockDlg::setStockCtrl(StockCtrl *pStockCtrl)
{
    if (m_pStockCtrl == NULL)
    {
        m_pStockCtrl = pStockCtrl;
        qRegisterMetaType<GoodsStockInfo>("GoodsStockInfo");
        connect(m_pStockCtrl, SIGNAL(sigOnGetStockGoodsInfo(int,QString,GoodsStockInfo))
                , this, SLOT(slot_onGetStockGoodsInfo(int,QString,GoodsStockInfo)));
    }
}

void StockDlg::slot_Text(QString sNum)
{
    if (ui->stackedWidget->currentWidget() == ui->addPage)
    {
        QString sText = ui->realStockEdit->text().append(sNum);
        if(sText.section('.', 1, 1).length() > 2)return;
        if(sText.section('.', 0, 0).length() > 6)return;
        ui->realStockEdit->setText(sText);
    }
    else
    {
        if(ui->addStockNumEdit->hasFocus()){
            QString sText = ui->addStockNumEdit->text().append(sNum);
            if(sText.section('.', 1, 1).length() > 2)return;
            if(sText.section('.', 0, 0).length() > 6)return;

            ui->addStockNumEdit->setText(sText);
        }

        if(ui->reduceStockNumEdit->hasFocus()){
            QString sText = ui->reduceStockNumEdit->text().append(sNum);
            if(sText.section('.', 1, 1).length() > 2)return;
            if(sText.section('.', 0, 0).length() > 6)return;
            ui->reduceStockNumEdit->setText(sText);
        }
    }
}

void StockDlg::slot_Delete()
{
    if (ui->stackedWidget->currentWidget() == ui->addPage)
    {
        QString sText = ui->realStockEdit->text();
        sText.remove(sText.length() - 1, 1);
        ui->realStockEdit->setText(sText);
    }
    else
    {
        if(ui->addStockNumEdit->hasFocus()){
            QString sText = ui->addStockNumEdit->text();
            sText.remove(sText.length() - 1, 1);
            ui->addStockNumEdit->setText(sText);
        }
        if(ui->reduceStockNumEdit->hasFocus()){
            QString sText = ui->reduceStockNumEdit->text();
            sText.remove(sText.length() - 1, 1);
            ui->reduceStockNumEdit->setText(sText);
        }
    }
}

void StockDlg::slot_Clear()
{
    if (ui->stackedWidget->currentWidget() == ui->addPage)
    {
        ui->realStockEdit->clear();
    }
    else
    {
        ui->addStockNumEdit->clear();
        ui->reduceStockNumEdit->clear();
    }
}

void StockDlg::slot_Confirm()
{
    on_saveButton_clicked();
}

void StockDlg::on_saveButton_clicked()
{
    ui->hintLabel->setText("");

    if (ui->stackedWidget->currentWidget() == ui->addPage)
    {
        if (ui->realStockEdit->text().isEmpty())
        {
            ui->hintLabel->setText(QStringLiteral("实盘数量不能为空"));
            return;
        }

        m_goodsInfo.fRealStockNum = ui->realStockEdit->text().toFloat();
    }
    else
    {
        if (ui->addStockNumEdit->text().isEmpty()&&ui->reduceStockNumEdit->text().isEmpty())
        {
            ui->hintLabel->setText(QStringLiteral("增加减少数量不能都为空"));
            return;
        }
        float newRealStockNum = ui->lastRealStockLabel->text().toFloat() + ui->addStockNumEdit->text().toFloat()
                - ui->reduceStockNumEdit->text().toFloat() ;

        if(newRealStockNum < 0){
            ui->hintLabel->setText(QStringLiteral("数量不能少于0"));
            return;
        }

        m_goodsInfo.fRealStockNum = newRealStockNum;
    }
    m_goodsInfo.fBuyDifferPrice = (m_goodsInfo.fRealStockNum - m_goodsInfo.fShouldStockNum) * m_goodsInfo.fBatchPrice; // 进价差异金额
    emit sigAddStockGoods(m_goodsInfo);
    this->hide();
}

void StockDlg::slot_onGetStockGoodsInfo(int nCode, QString sMsg, GoodsStockInfo goodsStockInfo)
{
    Q_UNUSED( sMsg )

    if (nCode != e_success)
    {
        ui->hintLabel->setText(QStringLiteral("未获取到商品的库存信息！"));
    }
    else
    {
        ui->hintLabel->setText("");
        m_goodsInfo.fShouldStockNum = goodsStockInfo.fShouldStockNum; // 账盘数量
        m_goodsInfo.fBatchPrice = goodsStockInfo.fBuyPrice;
        m_goodsInfo.nBatchId = goodsStockInfo.nBatchId; // 最新批次ID
        if (ui->stackedWidget->currentWidget() == ui->addPage)
        {
            ui->shoudStockLabel->setText(QString::number(goodsStockInfo.fShouldStockNum, 'f', 2));
        }
        else
        {
            ui->shoudStock2Label->setText(QString::number(goodsStockInfo.fShouldStockNum, 'f', 2));
        }
        ui->saveButton->show();
    }
}

void StockDlg::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(hide()));
    connect(ui->keyboardWidget, SIGNAL(sigText(QString)), this, SLOT(slot_Text(QString)));
    connect(ui->keyboardWidget, SIGNAL(sigDelete()), this, SLOT(slot_Delete()));
    connect(ui->keyboardWidget, SIGNAL(sigClear()), this, SLOT(slot_Clear()));
    connect(ui->keyboardWidget, SIGNAL(sigConfirm()), this, SLOT(slot_Confirm()));
   }
