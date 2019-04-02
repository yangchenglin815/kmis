#include "AddReportLossDlg.h"
#include "ui_AddReportLossDlg.h"

AddReportLossDlg::AddReportLossDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddReportLossDlg)
    , buttonGroup(NULL)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->titleWidget->setTitleText(QStringLiteral("报损数量"));
    init();
    initconnect();
}

AddReportLossDlg::~AddReportLossDlg()
{
    delete ui;
}

void AddReportLossDlg::setGoodsInfo(const AddReportLossSelectInfo &lossInfo)
{
    m_info = lossInfo;

    ui->goodsNameLabel->setText("商品名称: " + m_info.sName);
    ui->goodsCodeLabel->setText("商品编号: " + m_info.sCode);
    ui->lossNoLineEdit->setText(QString::number(m_info.sNumber, 'f', 2));
    buttonGroup->button(m_info.sReason)->setChecked(true);
}

void AddReportLossDlg::initMode(int mode)
{
    dlgMode = mode;
}

void AddReportLossDlg::slot_Text(QString sNum)
{
    if (ui->lossNoLineEdit->hasFocus())
    {
        QString sText = ui->lossNoLineEdit->text();
        ui->lossNoLineEdit->setText(sText.append(sNum));
    }
}

void AddReportLossDlg::slot_Delete()
{
    if (ui->lossNoLineEdit->hasFocus())
    {
        QString sText = ui->lossNoLineEdit->text();
        sText.remove(sText.length() - 1, 1);
        ui->lossNoLineEdit->setText(sText);
    }
}

void AddReportLossDlg::slot_Clear()
{
    if (ui->lossNoLineEdit->hasFocus())
    {
        ui->lossNoLineEdit->clear();
    }
}

void AddReportLossDlg::slot_Confirm()
{
    on_saveButton_clicked();
}

void AddReportLossDlg::on_saveButton_clicked()
{
    if(ui->lossNoLineEdit->text().isEmpty()){
        ui->hintLabel->setText(QStringLiteral("报损数量不能为空!"));
        ui->lossNoLineEdit->setFocus();
        return;
    }
    if(dlgMode == 1){
        if(buttonGroup->checkedId() == -1){
            ui->hintLabel->setText(QStringLiteral("请选择报损原因!"));
            return;
        }
        else
        {
            switch (buttonGroup->checkedId())
            {
            case 0:
                m_info.sReason = 0;
                break;
            case 1:
                m_info.sReason = 1;
                break;
            case 2:
                m_info.sReason = 2;
                break;
            default:
                m_info.sReason = 3;
                break;
            }
        }
    }
    ui->hintLabel->setText("");
    m_info.sNumber = ui->lossNoLineEdit->text().toFloat();
    m_info.sMoney = m_info.fPrice * m_info.sNumber;
    emit sigSendDlgMode(dlgMode);
    emit sigModifyLossNumber(m_info);
    this->hide();
}

void AddReportLossDlg::init()
{
    buttonGroup = new QButtonGroup;
    buttonGroup->addButton(ui->outofdateBtn, 0);
    buttonGroup->addButton(ui->badBtn, 1);
    buttonGroup->addButton(ui->lossBtn, 2);
    buttonGroup->addButton(ui->anotherBtn, 3);
    ui->outofdateBtn->setChecked(true);
    ui->badBtn->setChecked(false);
    ui->lossBtn->setChecked(false);
    ui->anotherBtn->setChecked(false);
}

void AddReportLossDlg::initconnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(hide()));
    connect(ui->keyboardWidget, SIGNAL(sigText(QString)), this, SLOT(slot_Text(QString)));
    connect(ui->keyboardWidget, SIGNAL(sigDelete()), this, SLOT(slot_Delete()));
    connect(ui->keyboardWidget, SIGNAL(sigClear()), this, SLOT(slot_Clear()));
    connect(ui->keyboardWidget, SIGNAL(sigConfirm()), this, SLOT(slot_Confirm()));
}
