#include "FirstLoginWidget.h"
#include "ui_FirstLoginWidget.h"
#include "../data/enumData.h"
#include "KPosIni.h"
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QDebug>

#define WidthSpace 20
#define ButtonSpace 10


FirstLoginWidget::FirstLoginWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstLoginWidget),
    m_pPosRegisterCtr(NULL),
    m_pShopInfoDlg(NULL)
{
    ui->setupUi(this);

    setWindowTitle("首次登录");
    setWindowFlags( Qt::FramelessWindowHint );//去掉标题栏
    this->setStyleSheet( "background-color: rgb(81, 80, 80);" );
    init();
    //获取屏幕size
//    QDesktopWidget* p_desktopWidget = QApplication::desktop();
//    this->setFixedSize( p_desktopWidget->width(), p_desktopWidget->height() );
}

FirstLoginWidget::~FirstLoginWidget()
{
    if (m_pShopInfoDlg != NULL)
    {
        m_pShopInfoDlg->deleteLater();
        m_pShopInfoDlg = NULL;
    }
    delete ui;
}

void FirstLoginWidget::setPosRegisterCtr(PosRegisterCtr *posRegisterCtr)
{
    m_pPosRegisterCtr = posRegisterCtr;
    initConnect();
}

void FirstLoginWidget::setHintText(QString str)
{
    ui->hintLabel->setText(str);
    ui->hintLabel->show();
}

void FirstLoginWidget::hideHintText()
{
    ui->hintLabel->setText( "" );
}

void FirstLoginWidget::showRegistPage(bool isShow)
{
    showWidget(isShow);

    if (isShow)
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->splitLine->show();
        ui->keyboardWidget->show();
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->splitLine->hide();
        ui->keyboardWidget->hide();

        static int i = 0;
        ui->waitTimeLabel->setText(QString(QStringLiteral("%1分钟")).arg(i++));
        ui->corpNameLabel->setText(QString(QStringLiteral("企业名称：%1")).arg(KPosIni::getCorpName()));
        ui->shopNameLabel->setText(QString(QStringLiteral("门店名称：%1")).arg(KPosIni::getShopName()));
    }
}

void FirstLoginWidget::setEditEnabled( bool bEnabled )
{
    ui->shopIDEdit->setEnabled( bEnabled );
    ui->corpIDEdit->setEnabled( bEnabled );
    ui->uploadButton->setEnabled( bEnabled );
}

void FirstLoginWidget::initConnect()
{
    connect( ui->closedButton, SIGNAL( clicked()), this, SIGNAL( sig_close_login_widget() ) );
//    connect( ui->minimizeButton, SIGNAL( clicked()), this, SIGNAL( sig_minimize_login_widget() ) );
//    connect( ui->uploadButton, SIGNAL( clicked()), this, SIGNAL( sig_upload() ) );

    connect(ui->keyboardWidget, SIGNAL(sigText(QString)), this, SLOT(slot_Text(QString)));
    connect(ui->keyboardWidget, SIGNAL(sigDelete()), this, SLOT(slot_Delete()));
    connect(ui->keyboardWidget, SIGNAL(sigClear()), this, SLOT(slot_Clear()));
    connect(ui->keyboardWidget, SIGNAL(sigConfirm()), this, SLOT(slot_Confirm()));

    connect(m_pPosRegisterCtr, SIGNAL(sigOnGetShopInfo(int, QString, ShopInfo)), this, SLOT(slot_onGetShopInfo(int, QString, ShopInfo)));
    connect(m_pPosRegisterCtr, SIGNAL(sigOnRegisterPos(int, QString)), this, SLOT(slot_onRegisterPos(int, QString)));
}

void FirstLoginWidget::init()
{
    ui->hintLabel->setText( "" );
}

void FirstLoginWidget::showWidget(bool bRegistPage)
{
    int nWidth = this->width();
    int nCloseXPos = nWidth - ButtonSpace - ui->closedButton->width();
    ui->closedButton->move(nCloseXPos, ButtonSpace);
    int nMiddleXPos = nWidth/2;

    if (bRegistPage)
    {
        ui->splitLine->move(nMiddleXPos, 0);
        ui->splitLine->resize(5, height());

        int nLeftX = nMiddleXPos - WidthSpace - ui->stackedWidget->width();
        int nLeftY = (this->height() - ui->stackedWidget->height())/2;
        ui->stackedWidget->move(nLeftX, nLeftY);

        int nRightX = nMiddleXPos + WidthSpace;
        int nRightY = (this->height() - ui->keyboardWidget->height())/2;
        ui->keyboardWidget->move(nRightX, nRightY);
    }
    else
    {
        int nX = (this->width() - ui->stackedWidget->width())/2;
        int nY = (this->height() - ui->stackedWidget->height())/2;
        ui->stackedWidget->move(nX, nY);
    }
}

//void FirstLoginWidget::resizeEvent( QResizeEvent *event )
//{
//    Q_UNUSED( event )

////    int nCentorX = getCentorPosX();
////    ui->splitLine->move( nCentorX, 0 );
////    ui->splitLine->resize( 5, height() );

////    setLoginInfoWidgetPos();
////    setKeyBoardPos();

////    int nButtonWidth = ui->closedButton->width();
////    int nX = width() - ButtonSpace - nButtonWidth;
////    ui->closedButton->move( nX, ButtonSpace );
////    nX = nX - ButtonSpace - nButtonWidth;
////    ui->minimizeButton->move( nX, ButtonSpace );

//    int nWidth = this->width();
//    int nCloseXPos = nWidth - ButtonSpace - ui->closedButton->width();
//    ui->closedButton->move(nCloseXPos, ButtonSpace);
//    int nMiddleXPos = nWidth/2;

//    if (ui->splitLine->isVisible())
//    {
//        ui->splitLine->move(nMiddleXPos, 0);
//        ui->splitLine->resize(5, height());

//        int nLeftX = nMiddleXPos - WidthSpace - ui->stackedWidget->width();
//        int nLeftY = (this->height() - ui->stackedWidget->height())/2;
//        ui->stackedWidget->move(nLeftX, nLeftY);

//        int nRightX = nMiddleXPos + WidthSpace;
//        int nRightY = (this->height() - ui->keyboardWidget->height())/2;
//        ui->keyboardWidget->move(nRightX, nRightY);
//    }
//    else
//    {
//        int nX = (this->width() - ui->stackedWidget->width())/2;
//        int nY = (this->height() - ui->stackedWidget->height())/2;
//        ui->stackedWidget->move(nX, nY);
//    }
//}

void FirstLoginWidget::keyPressEvent(QKeyEvent *event)
{
    if ((event->key() == Qt::Key_Return) || (event->key() == Qt::Key_Enter))
    {
        if (ui->stackedWidget->currentWidget() == ui->registPage)
        {
            if (m_pShopInfoDlg && m_pShopInfoDlg->isVisible())
            {
                slot_confirmRegist();
            }
            else
            {
                on_uploadButton_clicked();
            }
        }
    }
}

//int FirstLoginWidget::getCentorPosX()
//{
//    int nWidth = width();

//    return nWidth/2;
//}

//void FirstLoginWidget::setLoginInfoWidgetPos()
//{
//    int nHeight = height();

//    int nInfoWidth = ui->stackedWidget->width();
//    int nInfoHeight = ui->stackedWidget->height();

//    int nCentorX = getCentorPosX();

//    int nInfoX = nCentorX - WidthSpace - nInfoWidth;
//    int nInfoY = ( nHeight - nInfoHeight )/2;
//    ui->stackedWidget->move( nInfoX, nInfoY );
//}

//void FirstLoginWidget::setKeyBoardPos()
//{
//    int nHeight = height();
//    int nKeyHeight = ui->keyboardWidget->height();

//    int nCentorX = getCentorPosX();

//    int nKeyX = nCentorX + WidthSpace;
//    int nKeyY = ( nHeight - nKeyHeight )/2;
//    ui->keyboardWidget->move( nKeyX, nKeyY );
//}


void FirstLoginWidget::on_uploadButton_clicked()
{
    //KPosIni::DelIniFile();

    ui->hintLabel->setText( "" );
    if (ui->corpIDEdit->text().isEmpty())
    {
        ui->corpIDEdit->setFocus();
        ui->hintLabel->show();
        return;
    }
    else if (ui->shopIDEdit->text().isEmpty())
    {
        ui->shopIDEdit->setFocus();
        ui->hintLabel->show();
        return;
    }

    m_pPosRegisterCtr->getShopInfoRequest(ui->corpIDEdit->text(), ui->shopIDEdit->text());
}

void FirstLoginWidget::slot_Text(QString sNum)
{
    if (ui->corpIDEdit->hasFocus())
    {
        QString sText = ui->corpIDEdit->text();
        ui->corpIDEdit->setText(sText.append(sNum));
    }
    else if (ui->shopIDEdit->hasFocus())
    {
        QString sText = ui->shopIDEdit->text();
        ui->shopIDEdit->setText(sText.append(sNum));
    }
}

void FirstLoginWidget::slot_Delete()
{
    if (ui->corpIDEdit->hasFocus())
    {
        QString sText = ui->corpIDEdit->text();
        sText.remove(sText.length() - 1, 1);
        ui->corpIDEdit->setText(sText);
    }
    else if (ui->shopIDEdit->hasFocus())
    {
        QString sText = ui->shopIDEdit->text();
        sText.remove(sText.length() - 1, 1);
        ui->shopIDEdit->setText(sText);
    }
}

void FirstLoginWidget::slot_Clear()
{
    if (ui->corpIDEdit->hasFocus())
    {
        ui->corpIDEdit->clear();
    }
    else if (ui->shopIDEdit->hasFocus())
    {
        ui->shopIDEdit->clear();
    }
}

void FirstLoginWidget::slot_Confirm()
{
    on_uploadButton_clicked();
}

void FirstLoginWidget::slot_onGetShopInfo(int nCode, QString sMsg, ShopInfo shopInfo)
{
    ui->hintLabel->setText( "" );
    if (nCode == e_success)
    {
        // 显示门店信息
        if (m_pShopInfoDlg == NULL)
        {
            m_pShopInfoDlg = new ShopInfoDlg;
            connect(m_pShopInfoDlg, SIGNAL(sigConfirm()), this, SLOT(slot_confirmRegist()));
            connect(m_pShopInfoDlg, SIGNAL(sigCanncel()), this, SLOT(slot_cancel()));
        }
        KPosIni::setCorpName(shopInfo.sCorpName);
        KPosIni::setShopName(shopInfo.sShopName);
        m_pShopInfoDlg->setShopInfo(shopInfo.sCorpName, shopInfo.sShopName);
        m_pShopInfoDlg->show();
    }
    else
    {
        ui->hintLabel->setText(sMsg);
        ui->hintLabel->show();
    }
}

void FirstLoginWidget::slot_confirmRegist()
{
    if (m_pPosRegisterCtr != NULL)
    {
        m_pPosRegisterCtr->registerPosRequest(ui->corpIDEdit->text(), ui->shopIDEdit->text());
        setEditEnabled( false );
    }
}

void FirstLoginWidget::slot_cancel()
{
    setEditEnabled( true );
    if (m_pPosRegisterCtr != NULL) {
        m_pShopInfoDlg->hide();
    }
}

void FirstLoginWidget::slot_onRegisterPos(int nCode, QString sMsg)
{
    ui->hintLabel->setText( "" );
    if (nCode == e_success || nCode == e_posRegisted)
    {
        if (nCode == e_posRegisted)
        {
            ui->hintLabel->setText(sMsg);
            ui->hintLabel->show();
        }

        if (m_pPosRegisterCtr != NULL)
        {
            m_pPosRegisterCtr->checkRegisterResultRequest();
        }
        if (m_pShopInfoDlg != NULL)
        {
            m_pShopInfoDlg->deleteLater();
            m_pShopInfoDlg = NULL;
        }
    }
    else
    {
        ui->hintLabel->setText(QString(QStringLiteral("%1，请重试一次。")).arg(sMsg));
        setEditEnabled( true );
        ui->hintLabel->show();
        if (m_pShopInfoDlg != NULL)
        {
            m_pShopInfoDlg->hide();
        }
    }

}
