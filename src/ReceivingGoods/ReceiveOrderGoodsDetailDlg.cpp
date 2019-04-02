#include "ReceiveOrderGoodsDetailDlg.h"
#include "ui_ReceiveOrderGoodsDetailDlg.h"
#include "../data/enumData.h"
#include "../data/constData.h"
#include "../callOuterDll/MTComAPIMananger.h"
#include <QIntValidator>
#include <QDoubleValidator>

static QString s_sNormalQss = "font-family:'微软雅黑';font-size:14px;color:#ffffff;border-image: url(:/receivingGoodsImage/bigTopTab.png);";
static QString s_sSelectedQss = "font-family:'微软雅黑';font-size:14px;color:#333333;border-image: url(:/receivingGoodsImage/bigTopTab_Press.png);";

ReceiveOrderGoodsDetailDlg::ReceiveOrderGoodsDetailDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReceiveOrderGoodsDetailDlg)
    , m_pSelectedButton(NULL)
    , m_pReceiveOrderGoodsInfo(NULL)
    , m_pDlgCommon(NULL)
    , m_bWeighStable(true)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    init();
    initConnect();
    on_stableButton_clicked();
}

ReceiveOrderGoodsDetailDlg::~ReceiveOrderGoodsDetailDlg()
{
    if (m_pDlgCommon != NULL)
    {
        m_pDlgCommon->deleteLater();
    }
    delete ui;
}

void ReceiveOrderGoodsDetailDlg::initCtrl(DeliveryOrderCtrl *pDeliveryOrderCtrl)
{
    m_pDeliveryOrderCtrl = pDeliveryOrderCtrl;
}

void ReceiveOrderGoodsDetailDlg::initData(ReceiveOrderGoodsInfo *pReceiveOrderGoodsInfo, const ReceiveGoodsDetail_s &receiveGoodsDetail)
{
    m_receiveGoodsDetailChanged.nId = pReceiveOrderGoodsInfo->nId;
    m_pReceiveOrderGoodsInfo = pReceiveOrderGoodsInfo;
    m_ReceiveGoodsDetail = receiveGoodsDetail;
    ui->goodsNameLabel->setText(QString("商品名称:%1").arg(pReceiveOrderGoodsInfo->sGoodName));
    QString sGoodsIntroduction = QString("规格编号:%1(%2)").arg(pReceiveOrderGoodsInfo->sGoodsCode).arg(pReceiveOrderGoodsInfo->sUnitSpecification);
    ui->goodsIntroductionLabel->setText(sGoodsIntroduction);
    QString sNeedReceive = QString("%1/%2").arg(pReceiveOrderGoodsInfo->nNeedReceiveSumNum).arg(QString::number(pReceiveOrderGoodsInfo->fNeedReceiveSumValue, 'f', 2));
    ui->needReceiveLabel->setText(sNeedReceive);

    if (receiveGoodsDetail.bStandardGoods)
    {
        ui->changeTabWidget->hide();
        ui->stackedWidget->setCurrentWidget(ui->standardGoodsPage);
        ui->standardWeightLineEdit->setText(QString::number(receiveGoodsDetail.standardInfo.fStandardWeight, 'f', 2));
        ui->receiveNumLineEdit->setText(QString::number(receiveGoodsDetail.standardInfo.nReceiveNum));
        ui->receiveSumValueLineEdit->setText(QString::number(receiveGoodsDetail.standardInfo.fReciveSumValue, 'f', 2));
        ui->receivePriceLineEdit->setText(QString::number(receiveGoodsDetail.standardInfo.fPrice, 'f', 2));
    }
    else
    {
        if (receiveGoodsDetail.bDisperseWeight)
        {
            MTComAPIMananger::instance()->startCheckWeight();
            ui->receiveSumValue3LineEdit->setText(QString::number(receiveGoodsDetail.disperseInfo.fReciveSumValue, 'f', 2));
            ui->receivePrice3LineEdit->setText(QString::number(receiveGoodsDetail.disperseInfo.fPrice, 'f', 2));
            on_disperseButton_clicked();
        }
        else
        {
            ui->allWeightlineEdit->setText(QString::number(receiveGoodsDetail.noStandardInfo.fAllWeidght, 'f', 2));
            ui->peelWeightlineEdit->setText(QString::number(receiveGoodsDetail.noStandardInfo.fPeelWeight, 'f', 2));
            ui->receiveNum2LineEdit->setText(QString::number(receiveGoodsDetail.noStandardInfo.nReceiveNum));
            ui->receivePrice2LineEdit->setText(QString::number(receiveGoodsDetail.noStandardInfo.fPrice, 'f', 2));
            if (receiveGoodsDetail.bFixWeight)
            {
                on_stableButton_clicked();
            }
            else
            {
                on_unStableButton_clicked();
            }
        }
        ui->changeTabWidget->show();
        ui->stackedWidget->setCurrentWidget(ui->noStandardGoodsPage);
    }
}

void ReceiveOrderGoodsDetailDlg::on_stableButton_clicked()
{
    MTComAPIMananger::instance()->stopCheckWeight();

    setButtonQss(ui->stableButton);
    ui->stackedWidget->setCurrentWidget(ui->noStandardGoodsPage);
    ui->hintLabel->hide();
}

void ReceiveOrderGoodsDetailDlg::on_unStableButton_clicked()
{
    MTComAPIMananger::instance()->stopCheckWeight();

    setButtonQss(ui->unStableButton);
    ui->stackedWidget->setCurrentWidget(ui->noStandardGoodsPage);
    ui->hintLabel->show();
}

void ReceiveOrderGoodsDetailDlg::on_disperseButton_clicked()
{
    MTComAPIMananger::instance()->startCheckWeight();

    setButtonQss(ui->disperseButton);
    ui->stackedWidget->setCurrentWidget(ui->disperseGoodsPage);
}

void ReceiveOrderGoodsDetailDlg::on_saveButton_clicked()
{
//    ReceiveGoodsDetail_s oldReceiveGoodsDetail_s = m_ReceiveGoodsDetail;

//    ReceiveOrderGoodsInfo oldReceiveOrderGoodsInfo = *m_pReceiveOrderGoodsInfo;
    QString sHintText = QStringLiteral("每一项都不为空才可以保存！");
    bool bInputOk = true;
    if (ui->stackedWidget->currentWidget() == ui->standardGoodsPage)// 标品计件
    {
        if (ui->standardWeightLineEdit->text().isEmpty()// 规格
                || ui->receiveNumLineEdit->text().isEmpty()// 采购件数
                || ui->receiveSumValueLineEdit->text().isEmpty()// 采购数量
                || ui->receivePriceLineEdit->text().isEmpty())// 单价
        {
            bInputOk = false;
        }
        else
        {         
//            float fStandardWeight = ui->standardWeightLineEdit->text().toFloat();
            int nReceiveNum = ui->receiveNumLineEdit->text().toInt();
            float fReciveSumValue = ui->receiveSumValueLineEdit->text().toFloat();
            float fPrice = ui->receivePriceLineEdit->text().toFloat();

            m_receiveGoodsDetailChanged.nRealReceiveSumNum = nReceiveNum;
            m_receiveGoodsDetailChanged.fRealReceiveSumValue = fReciveSumValue;
            m_receiveGoodsDetailChanged.fSumPrice = nReceiveNum * fPrice;

            float oldSumPrice = m_ReceiveGoodsDetail.standardInfo.nReceiveNum * m_ReceiveGoodsDetail.standardInfo.fPrice;
            m_receiveGoodsDetailChanged.fAddedSumPrice = m_receiveGoodsDetailChanged.fSumPrice - oldSumPrice;
            m_receiveGoodsDetailChanged.fAddedRealReceiveSumValue = m_receiveGoodsDetailChanged.fRealReceiveSumValue - m_ReceiveGoodsDetail.standardInfo.fReciveSumValue;
            m_receiveGoodsDetailChanged.nAddedRealReceiveSumNum = m_receiveGoodsDetailChanged.nRealReceiveSumNum - m_ReceiveGoodsDetail.standardInfo.nReceiveNum;

            // 更新新值
            m_ReceiveGoodsDetail.standardInfo.nReceiveNum = nReceiveNum; // 采购件数
            m_ReceiveGoodsDetail.standardInfo.fReciveSumValue = fReciveSumValue; // 采购数量
            m_ReceiveGoodsDetail.standardInfo.fPrice = fPrice; // 单价
        }
    }
    else if (ui->stackedWidget->currentWidget() == ui->noStandardGoodsPage)// 非标品计件
    {

        if (ui->allWeightlineEdit->text().isEmpty()// 毛重
                || ui->peelWeightlineEdit->text().isEmpty()// 皮重
                || ui->receiveNum2LineEdit->text().isEmpty()// 采购件数
                || ui->receivePrice2LineEdit->text().isEmpty())// 单价
        {
            bInputOk = false;
        }
        else
        {

            float fAllWeidght = ui->allWeightlineEdit->text().toFloat();
            float fPeelWeight = ui->peelWeightlineEdit->text().toFloat();
            if (fPeelWeight > fAllWeidght)
            {
                sHintText = QStringLiteral("皮重大于毛重，不正常！");
                bInputOk = false;
            }
            else
            {
                int nReceiveNum = ui->receiveNum2LineEdit->text().toInt();
                float fPrice = ui->receivePrice2LineEdit->text().toFloat();

                m_receiveGoodsDetailChanged.nRealReceiveSumNum = nReceiveNum;
                m_receiveGoodsDetailChanged.fRealReceiveSumValue = nReceiveNum * (fAllWeidght - fPeelWeight);
                m_receiveGoodsDetailChanged.fSumPrice = nReceiveNum * fPrice;

                float fOldSumPrice = 0.0f;
                float fOldSumValue = 0.0f;
                int nOldSumNumber = 0;
                if (m_ReceiveGoodsDetail.bDisperseWeight)
                {
                    fOldSumPrice = m_ReceiveGoodsDetail.disperseInfo.fReciveSumValue * m_ReceiveGoodsDetail.disperseInfo.fPrice;
                    fOldSumValue = m_ReceiveGoodsDetail.disperseInfo.fReciveSumValue;
                    nOldSumNumber = 0;
                }
                else
                {            
                    fOldSumPrice = m_ReceiveGoodsDetail.noStandardInfo.nReceiveNum * m_ReceiveGoodsDetail.noStandardInfo.fPrice;
                    fOldSumValue = m_ReceiveGoodsDetail.noStandardInfo.nReceiveNum * (m_ReceiveGoodsDetail.noStandardInfo.fAllWeidght - m_ReceiveGoodsDetail.noStandardInfo.fPeelWeight);
                    nOldSumNumber = m_ReceiveGoodsDetail.noStandardInfo.nReceiveNum;
                }
                m_receiveGoodsDetailChanged.fAddedSumPrice = m_receiveGoodsDetailChanged.fSumPrice - fOldSumPrice;
                m_receiveGoodsDetailChanged.fAddedRealReceiveSumValue = m_receiveGoodsDetailChanged.fRealReceiveSumValue - fOldSumValue;
                m_receiveGoodsDetailChanged.nAddedRealReceiveSumNum = m_receiveGoodsDetailChanged.nRealReceiveSumNum - nOldSumNumber;

                // 更新新值
                if (m_pSelectedButton == ui->stableButton)
                {
                    m_ReceiveGoodsDetail.bFixWeight = true;
                }
                else
                {
                    m_ReceiveGoodsDetail.bFixWeight = false;
                }
                m_ReceiveGoodsDetail.bDisperseWeight = false;
                m_ReceiveGoodsDetail.noStandardInfo.fAllWeidght = fAllWeidght; // 毛重
                m_ReceiveGoodsDetail.noStandardInfo.fPeelWeight = fPeelWeight; // 皮重
                m_ReceiveGoodsDetail.noStandardInfo.nReceiveNum = nReceiveNum; // 采购件数
                m_ReceiveGoodsDetail.noStandardInfo.fPrice = fPrice; // 单价
            }
        }
    }
    else if(ui->stackedWidget->currentWidget() == ui->disperseGoodsPage)// 非标品散斤
    {

        if (ui->receivePrice3LineEdit->text().isEmpty() // 单价
                || ui->receiveSumValue3LineEdit->text().isEmpty()) // 采购数量
        {
            bInputOk = false;
        }
        else
        {
            if (!m_bWeighStable)
            {
                bInputOk = false;
                sHintText = QStringLiteral("称重尚不稳定，等一下...");
            }
            else
            {
                float fPrice = ui->receivePrice3LineEdit->text().toFloat();
                float fReciveSumValue = ui->receiveSumValue3LineEdit->text().toFloat();

                m_receiveGoodsDetailChanged.nRealReceiveSumNum = 0;
                m_receiveGoodsDetailChanged.fRealReceiveSumValue = fReciveSumValue;
                m_receiveGoodsDetailChanged.fSumPrice = fPrice * fReciveSumValue;
                float fOldSumPrice = 0.0f;
                float fOldSumValue = 0.0f;
                int nOldSumNumber = 0;
                if (m_ReceiveGoodsDetail.bDisperseWeight)
                {
                    fOldSumPrice = m_ReceiveGoodsDetail.disperseInfo.fReciveSumValue * m_ReceiveGoodsDetail.disperseInfo.fPrice;
                    fOldSumValue = m_ReceiveGoodsDetail.disperseInfo.fReciveSumValue;
                    nOldSumNumber = 0;
                }
                else
                {
                    fOldSumPrice = m_ReceiveGoodsDetail.noStandardInfo.nReceiveNum * m_ReceiveGoodsDetail.noStandardInfo.fPrice;
                    fOldSumValue = m_ReceiveGoodsDetail.noStandardInfo.nReceiveNum * (m_ReceiveGoodsDetail.noStandardInfo.fAllWeidght - m_ReceiveGoodsDetail.noStandardInfo.fPeelWeight);
                    nOldSumNumber = m_ReceiveGoodsDetail.noStandardInfo.nReceiveNum;
                }
                m_receiveGoodsDetailChanged.fAddedSumPrice = m_receiveGoodsDetailChanged.fSumPrice - fOldSumPrice;
                m_receiveGoodsDetailChanged.fAddedRealReceiveSumValue = m_receiveGoodsDetailChanged.fRealReceiveSumValue - fOldSumValue;
                m_receiveGoodsDetailChanged.nAddedRealReceiveSumNum = m_receiveGoodsDetailChanged.nRealReceiveSumNum - nOldSumNumber;

                // 更新新值
                m_ReceiveGoodsDetail.bDisperseWeight = true;
                m_ReceiveGoodsDetail.disperseInfo.fPrice = fPrice; // 单价
                m_ReceiveGoodsDetail.disperseInfo.fReciveSumValue = fReciveSumValue; // 实采数量
            }
        }
    }

    if (bInputOk)
    {
        MTComAPIMananger::instance()->stopCheckWeight();
        this->hide();
//        m_pReceiveOrderGoodsInfo->bGoodsRecieveFinish = true;
//        m_pReceiveOrderGoodsInfo->fRealReceiveSumValue
//        emit sigSaveReceiveGoods(&m_ReceiveGoodsDetail, m_pReceiveOrderGoodsInfo);
        if (m_pDeliveryOrderCtrl != NULL)
        {
            m_pDeliveryOrderCtrl->saveReceiveGoodsRequest(m_ReceiveGoodsDetail, m_pReceiveOrderGoodsInfo->nId);
        }
    }
    else
    {
        if (m_pDlgCommon == NULL)
        {
            m_pDlgCommon = new DlgCommon;
            m_pDlgCommon->hideBottomWidget();
            connect(m_pDlgCommon, SIGNAL(sig_dlg_close()), this, SLOT(slot_closeDlgCommon()));
            connect(m_pDlgCommon, SIGNAL(sig_btn_cancel()), this, SLOT(slot_closeDlgCommon()));
        }
        m_pDlgCommon->set_title(QStringLiteral("提示"));
        m_pDlgCommon->set_content(sHintText);
        m_pDlgCommon->exec();
    }
}

void ReceiveOrderGoodsDetailDlg::on_standardWeightLineEdit_textChanged(const QString &text)
{
    if (text.isEmpty() || ui->receiveNumLineEdit->text().isEmpty())
    {
        ui->receiveSumValueLineEdit->setText("");
    }
    else
    {
        float fStandardWeight = text.toFloat();
        int nReceiveNum = ui->receiveNumLineEdit->text().toInt();
        float fSumWeight = nReceiveNum * fStandardWeight;
        ui->receiveSumValueLineEdit->setText(QString::number(fSumWeight, 'f', 2));
    }
}

void ReceiveOrderGoodsDetailDlg::on_receiveNumLineEdit_textChanged(const QString &text)
{
    if (text.isEmpty() || ui->standardWeightLineEdit->text().isEmpty())
    {
        ui->receiveSumValueLineEdit->setText("");
    }
    else
    {
        float fStandardWeight = ui->standardWeightLineEdit->text().toFloat();
        int nReceiveNum = text.toInt();
        float fSumWeight = nReceiveNum * fStandardWeight;
        ui->receiveSumValueLineEdit->setText(QString::number(fSumWeight, 'f', 2));
    }
}

void ReceiveOrderGoodsDetailDlg::slot_closeDlgCommon()
{
    m_pDlgCommon->hide();
}

void ReceiveOrderGoodsDetailDlg::slot_closeWnd()
{
    MTComAPIMananger::instance()->stopCheckWeight();
    this->hide();
    emit sigCloseWnd();
}

void ReceiveOrderGoodsDetailDlg::slot_stableInfo(EBalanceStandard_Ex balanceStandard_Ex, bool bStable)
{
    m_bWeighStable = bStable;
    ui->receiveSumValue3LineEdit->setText(balanceStandard_Ex.sWeight);
}

void ReceiveOrderGoodsDetailDlg::setButtonQss(QPushButton *pPushButton)
{
    if (m_pSelectedButton != pPushButton)
    {
        if (pPushButton != NULL)
        {
           pPushButton->setStyleSheet(s_sSelectedQss);
        }
        if (m_pSelectedButton != NULL)
        {
            m_pSelectedButton->setStyleSheet(s_sNormalQss);
        }
        m_pSelectedButton = pPushButton;
    }
}

void ReceiveOrderGoodsDetailDlg::init()
{
    ui->titleWidget->hideTitleText();

    // 标品计件
    ui->standardWeightLineEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this)); // 规格
    ui->receiveNumLineEdit->setValidator(new QIntValidator(0, 10000, this)); // 采购件数
    ui->receiveSumValueLineEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this)); // 采购数量
    ui->receiveSumValueLineEdit->setReadOnly(true);
    ui->receivePriceLineEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this)); // 单价

    // 非标品计件
    ui->allWeightlineEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this)); // 毛重
    ui->peelWeightlineEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this)); // 皮重
    ui->receiveNum2LineEdit->setValidator(new QIntValidator(0, 10000, this)); // 采购件数
    ui->receivePrice2LineEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this)); // 单价

    // 非标品散斤
    ui->receivePrice3LineEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this)); // 单价
    ui->receiveSumValue3LineEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this)); // 采购数量
}

void ReceiveOrderGoodsDetailDlg::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(slot_closeWnd()));
    connect(MTComAPIMananger::instance(), SIGNAL(sig_stableInfo(EBalanceStandard_Ex,bool))
            , this, SLOT(slot_stableInfo(EBalanceStandard_Ex,bool)));
}

