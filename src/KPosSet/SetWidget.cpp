#include "SetWidget.h"
#include "ui_SetWidget.h"
#include "AdjustPositionWidget.h"
#include <QMouseEvent>
#include <QDebug>

SetWidget::SetWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SetWidget)
    , m_pKPosSetCtrl(NULL)
    , m_pLastClickButton(NULL)
    , m_setGuideWidget(NULL)
{
    ui->setupUi(this);
    pingbi();
    if (m_pKPosSetCtrl == NULL)
    {
        m_pKPosSetCtrl = new KPosSetCtrl(this);
    }
}

SetWidget::~SetWidget()
{
    delete ui;
}

void SetWidget::setCategoryInfoList(const QList<CategoryInfo*> &categoryInfoList)
{
    m_kPosSet.goodSet.bChanged = false;
    ui->goodSetPage->setCategoryInfoList(categoryInfoList);
    ui->goodSetPage->setKPosSetCtrl(m_pKPosSetCtrl);
    if (m_pLastClickButton == NULL)
    {
        on_posInfoSetButton_clicked();
    }
}

void SetWidget::mousePressEvent(QMouseEvent *event)
{
    QPoint globalPoint = this->mapToGlobal(QPoint(event->pos().x(), event->pos().y()));
    ui->screenSetPage->somePlacePressed(globalPoint);
    ui->payWaySetPage->somePlacePressed(globalPoint);
}

void SetWidget::on_posInfoSetButton_clicked()
{
    uploadData(ui->posInfoSetButton);
    setButtonsQss(ui->posInfoSetButton);
    ui->stackedWidget->setCurrentWidget(ui->posInfoSetPage);
    ui->screenSetPage->somePlacePressed();
    ui->payWaySetPage->somePlacePressed();
//    ui->posInfoSetPage->initData(m_kPosSet.posInfoSet);
//    ui->posInfoSetPage->setDefultData(m_kPosSet.posInfoSet);
}

void SetWidget::on_keySetButton_clicked()
{
    uploadData(ui->keySetButton);
    setButtonsQss(ui->keySetButton);
    ui->stackedWidget->setCurrentWidget(ui->keySetPage);
    ui->screenSetPage->somePlacePressed();
    ui->payWaySetPage->somePlacePressed();
//    ui->keySetPage->setDefultData(m_kPosSet.keySet);
}

void SetWidget::on_goodsSetButton_clicked()
{
    uploadData(ui->goodsSetButton);
    setButtonsQss(ui->goodsSetButton);
    ui->stackedWidget->setCurrentWidget(ui->goodSetPage);
    ui->screenSetPage->somePlacePressed();
    ui->payWaySetPage->somePlacePressed();
}

void SetWidget::on_screenSetButton_clicked()
{
    uploadData(ui->screenSetButton);
    setButtonsQss(ui->screenSetButton);
    ui->stackedWidget->setCurrentWidget(ui->screenSetPage);
    ui->payWaySetPage->somePlacePressed();
    ui->screenSetPage->setDefultData(m_kPosSet.screenSet);
}

void SetWidget::on_payWaySetButton_clicked()
{
    uploadData(ui->payWaySetButton);
    setButtonsQss(ui->payWaySetButton);
    ui->stackedWidget->setCurrentWidget(ui->payWaySetPage);
    ui->screenSetPage->somePlacePressed();
}

void SetWidget::on_paramsSetButton_clicked()
{
    uploadData(ui->paramsSetButton);
    setButtonsQss(ui->paramsSetButton);
    ui->stackedWidget->setCurrentWidget(ui->paramsSetPage);
    ui->screenSetPage->somePlacePressed();
    ui->payWaySetPage->somePlacePressed();
//    ui->paramsSetPage->setDefultData(m_kPosSet.paramsSet);
}

void SetWidget::on_backButton_clicked()
{
    uploadData(ui->backButton);
    emit sig_backHomePage();
    ui->screenSetPage->somePlacePressed();
    ui->payWaySetPage->somePlacePressed();

    AdjustPositionWidget::instance()->hide();
}

void SetWidget::on_deviceSetButton_clicked()
{
//    uploadData(ui->deviceSetButton);
//    setButtonsQss(ui->deviceSetButton);
//    ui->stackedWidget->setCurrentWidget(ui->deviceSetPage);
    ui->screenSetPage->somePlacePressed();
    ui->payWaySetPage->somePlacePressed();
}

void SetWidget::setButtonsQss(QPushButton *selectedButton)
{
    if (selectedButton == m_pLastClickButton)
    {
        return;
    }

    QString sNormalQss = "QPushButton{font-size:15px; color: #ffffff;border-image: url(:/setImage/tab_button_normal.png);}";
    QString sSelectedQss = "QPushButton{font-size:15px; color: #000000;border-image: url(:/setImage/tab_button_press.png);}";
    selectedButton->setStyleSheet(sSelectedQss);
    if (m_pLastClickButton != NULL)
    {
        m_pLastClickButton->setStyleSheet(sNormalQss);
    }
    m_pLastClickButton = selectedButton;
}

void SetWidget::init()
{
    if (m_pKPosSetCtrl == NULL)
    {
        return;
    }

    m_pKPosSetCtrl->getKPosSetInfo(m_kPosSet);

    if (m_kPosSet.posInfoSet.bChanged)
    {
        ui->posInfoSetPage->initData(m_kPosSet.posInfoSet); // Pos机基础信息
        m_kPosSet.posInfoSet.bChanged = false;
    }
    if (m_kPosSet.keySet.bChanged)
    {
        ui->keySetPage->initData(m_kPosSet.keySet); // 按键设置
        m_kPosSet.keySet.bChanged = false;
    }
    if (m_kPosSet.payWaySet.bChanged)
    {
        ui->payWaySetPage->initData(m_kPosSet.payWaySet); // 支付设置
        m_kPosSet.payWaySet.bChanged = false;
    }
    if (m_kPosSet.paramsSet.bChanged)
    {
        ui->paramsSetPage->initData(m_kPosSet.paramsSet); // 参数设置
        m_kPosSet.paramsSet.bChanged = false;
    }

    if (m_pLastClickButton == NULL)
    {
        on_posInfoSetButton_clicked();
    }
}

KPosSet SetWidget::getKPosSet()
{
    return m_kPosSet;
}

void SetWidget::initSetGuideObj(SetGuideWidget *setGuideWidget)
{
    if((m_setGuideWidget == NULL) && (setGuideWidget != NULL)){
        m_setGuideWidget = setGuideWidget;
        connect(m_setGuideWidget, SIGNAL(sigOnShowSetButtonPage()), this, SLOT(on_keySetButton_clicked()));
        connect(m_setGuideWidget, SIGNAL(sigOnShowSetDevicePage()), this, SLOT(on_deviceSetButton_clicked()));
        connect(m_setGuideWidget, SIGNAL(sigOnShowSetGoodsPage()), this, SLOT(on_goodsSetButton_clicked()));
        connect(m_setGuideWidget, SIGNAL(sigOnShowSetParamPage()), this, SLOT(on_paramsSetButton_clicked()));
        connect(m_setGuideWidget, SIGNAL(sigOnShowSetPaymentPage()), this, SLOT(on_payWaySetButton_clicked()));
    }
}

void SetWidget::uploadData(QPushButton* selectedButton)
{
    if (m_pLastClickButton == NULL || m_pLastClickButton == selectedButton)
    {
        return;
    }

    if (m_pLastClickButton == ui->posInfoSetButton)
    {
        ui->posInfoSetPage->uploadData(m_kPosSet);
        if (m_kPosSet.posInfoSet.bChanged)
        {
            if (m_pKPosSetCtrl != NULL)
            {
                m_pKPosSetCtrl->uploadKPosSet(m_kPosSet, false);
            }
            m_kPosSet.posInfoSet.bChanged = false;
        }
    }
    else if (m_pLastClickButton == ui->keySetButton)
    {
        ui->keySetPage->uploadData(m_kPosSet);
        if (m_kPosSet.keySet.bChanged)
        {
            if (m_pKPosSetCtrl != NULL)
            {
                m_pKPosSetCtrl->uploadKPosSet(m_kPosSet, false);
            }
            m_kPosSet.keySet.bChanged = false;
        }
    }
    else if (m_pLastClickButton == ui->goodsSetButton)
    {
        ui->goodSetPage->uploadData(m_kPosSet);
        if(m_kPosSet.goodSet.bChanged)
        {
            if( m_pKPosSetCtrl )
            {
                m_pKPosSetCtrl->uploadKPosSet(m_kPosSet, false);
            }
            m_kPosSet.goodSet.bChanged = false;
        }
    }
    else if (m_pLastClickButton == ui->screenSetButton)
    {
        //
    }
    else if (m_pLastClickButton == ui->payWaySetButton)
    {
        ui->payWaySetPage->uploadData(m_kPosSet);
        if(m_kPosSet.payWaySet.bChanged)
        {
            if(m_pKPosSetCtrl != NULL)
            {
                m_pKPosSetCtrl->uploadKPosSet(m_kPosSet, false);
            }
            m_kPosSet.payWaySet.bChanged = false;
        }
    }
    else if (m_pLastClickButton == ui->paramsSetButton)
    {
        ui->paramsSetPage->uploadData(m_kPosSet);
        if (m_kPosSet.paramsSet.bChanged)
        {
            if (m_pKPosSetCtrl != NULL)
            {
                m_pKPosSetCtrl->uploadKPosSet(m_kPosSet, false);
            }
            m_kPosSet.paramsSet.bChanged = false;
        }
    }
}

void SetWidget::pingbi()
{
    ui->screenSetButton->hide();
    ui->deviceSetPage->hide();
}


