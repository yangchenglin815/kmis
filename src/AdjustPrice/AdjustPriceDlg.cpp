#include "AdjustPriceDlg.h"
#include "ui_AdjustPriceDlg.h"

AdjustPriceDlg::AdjustPriceDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdjustPriceDlg)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->titleWidget->setTitleText(QStringLiteral("改价"));
    ui->nowPriceEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this));
    ui->nowMemberPriceEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this));
    ui->nowPriceEdit->setFocus();
    initConnect();
}

AdjustPriceDlg::~AdjustPriceDlg()
{
    delete ui;
}

void AdjustPriceDlg::setGoodsInfo(const AdjustPriceSelectGoodsInfo &goodsInfo)
{
    m_goodsInfo = goodsInfo;

    QString strName = "";
    if( m_goodsInfo.sShortName.isEmpty() ) {
        strName = m_goodsInfo.sName;
    } else {
        strName = m_goodsInfo.sShortName;
    }

    ui->goodsNameLabel->setText(QStringLiteral("%1(%2)").arg( strName ).arg(m_goodsInfo.sWeighUnit));
    ui->goodsCodeLabel->setText(m_goodsInfo.sCode);
    ui->oldPriceLabel->setText(QString::number(goodsInfo.fOldPrice, 'f', 2));
    ui->oldMemberPriceLabel->setText(QString::number(goodsInfo.fOldMemberPrice, 'f', 2));
    ui->nowPriceEdit->setText(QString::number(goodsInfo.fNowPrice, 'f', 2));
    ui->nowMemberPriceEdit->setText(QString::number(goodsInfo.fNowMemberPrice, 'f', 2));
}

void AdjustPriceDlg::slot_Text(QString sNum)
{
    if (ui->nowPriceEdit->hasFocus())
    {
        QString sText = ui->nowPriceEdit->text();
        ui->nowPriceEdit->setText(sText.append(sNum));
    }
    else if (ui->nowMemberPriceEdit->hasFocus())
    {
        QString sText = ui->nowMemberPriceEdit->text();
        ui->nowMemberPriceEdit->setText(sText.append(sNum));
    }
}

void AdjustPriceDlg::slot_Delete()
{
    if (ui->nowPriceEdit->hasFocus())
    {
        QString sText = ui->nowPriceEdit->text();
        sText.remove(sText.length() - 1, 1);
        ui->nowPriceEdit->setText(sText);
    }
    else if (ui->nowMemberPriceEdit->hasFocus())
    {
        QString sText = ui->nowMemberPriceEdit->text();
        sText.remove(sText.length() - 1, 1);
        ui->nowMemberPriceEdit->setText(sText);
    }
}

void AdjustPriceDlg::slot_Clear()
{
    if (ui->nowPriceEdit->hasFocus())
    {
        ui->nowPriceEdit->clear();
    }
    else if (ui->nowMemberPriceEdit->hasFocus())
    {
        ui->nowMemberPriceEdit->clear();
    }
}

void AdjustPriceDlg::slot_Confirm()
{
    on_saveButton_clicked();
}

void AdjustPriceDlg::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(hide()));
    connect(ui->keyboardWidget, SIGNAL(sigText(QString)), this, SLOT(slot_Text(QString)));
    connect(ui->keyboardWidget, SIGNAL(sigDelete()), this, SLOT(slot_Delete()));
    connect(ui->keyboardWidget, SIGNAL(sigClear()), this, SLOT(slot_Clear()));
    connect(ui->keyboardWidget, SIGNAL(sigConfirm()), this, SLOT(slot_Confirm()));
}

void AdjustPriceDlg::on_saveButton_clicked()
{
    if (ui->nowPriceEdit->text().trimmed().isEmpty())
    {
        ui->hintLabel->setText(QStringLiteral("现售价不能为空"));
        ui->nowPriceEdit->setFocus();
    }
    else if (ui->nowMemberPriceEdit->text().trimmed().isEmpty())
    {
        ui->hintLabel->setText(QStringLiteral("现会员价不能为空"));
        ui->nowMemberPriceEdit->setFocus();
    }
    else
    {
        ui->hintLabel->setText("");
        m_goodsInfo.fNowPrice = ui->nowPriceEdit->text().toFloat();
        m_goodsInfo.fNowMemberPrice = ui->nowMemberPriceEdit->text().toFloat();
        emit sigModifyGoodsPrice(m_goodsInfo);
        this->hide();
    }
}
