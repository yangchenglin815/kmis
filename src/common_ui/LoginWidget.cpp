#include "LoginWidget.h"
#include "ui_LoginWidget.h"
#include <QDesktopWidget>
#include "KPosIni.h"
#include "ScreenInfo.h"

#include "../data/enumData.h"

#define WidthSpace 20
#define ButtonSpace 10

LoginWidget::LoginWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginWidget)
    , m_pLoginKPosCtr(NULL)
    , m_pDlgCommon(NULL)
    , m_bUploadReceipSuccess(false)
{
    ui->setupUi(this);

    setModal( true );
    setWindowTitle("登录");
    setWindowIcon( QIcon( ":/shareImages/kpos_logo.png" ) );
    setWindowFlags( Qt::FramelessWindowHint );//去掉标题栏
    this->setStyleSheet( "background-color: rgb(81, 80, 80);" );
    m_pLoginKPosCtr = new LoginKPosCtr;
    init();
    initConnect();

    //获取屏幕size
    this->setFixedSize(ScreenInfo::width(), ScreenInfo::height());
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::showLoginPage()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->loginButton->setText(QStringLiteral("登录"));
    ui->userNameEdit->setReadOnly(false);
    ui->userNameEdit->setFocusPolicy( Qt::WheelFocus );
    ui->closedButton->show();
}

void LoginWidget::showLockPage()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->loginButton->setText(QStringLiteral("提交"));
    ui->userNameEdit->setReadOnly(true);
    ui->userNameEdit->setFocusPolicy( Qt::NoFocus );
    ui->passwordEdit->setText("");
    ui->closedButton->hide();
    ui->hintLabel->setText( "" );
}

void LoginWidget::initUserName()
{
    int nCloseWnd = KPosIni::getCloseAppStatus();
    ui->userNameEdit->setText(KPosIni::getUserCode());
    if(nCloseWnd != 1)
    {
        ui->userNameEdit->setReadOnly(true);
        ui->userNameEdit->setFocusPolicy(Qt::NoFocus);
    }
    if (!ui->userNameEdit->text().isEmpty())
    {
        ui->passwordEdit->setFocus();
    }
}

void LoginWidget::checkUploadAllReceipt()
{
    if (m_pDlgCommon == NULL)
    {
        m_pDlgCommon = new DlgCommon;
        m_pDlgCommon->set_title(QStringLiteral("检查小票上传"));
        connect(m_pDlgCommon, SIGNAL(sig_btn_sure()), this, SLOT(slot_dlgCanncel()));
        connect(m_pDlgCommon, SIGNAL(sig_dlg_close()), this, SLOT(slot_dlgConfirm()));
        connect(m_pDlgCommon, SIGNAL(sig_btn_cancel()), this, SLOT(slot_dlgConfirm()));
    }
    m_pDlgCommon->set_content(QStringLiteral("正在检查小票是否上传完毕..."));
    m_pDlgCommon->hideBottomWidget();
    m_pDlgCommon->activateWindow();
    m_pDlgCommon->showNormal();

    if (m_pLoginKPosCtr != NULL)
    {
        m_pLoginKPosCtr->checkUploadAllReceipt();
    }
}

void LoginWidget::logout(QString sSubmitMoney)
{
    if (m_pLoginKPosCtr != NULL)
    {
        m_pLoginKPosCtr->logoutRequest(sSubmitMoney);
    }
}

void LoginWidget::clearData()
{
    ui->passwordEdit->setText("");
    ui->hintLabel->setText("");
}

void LoginWidget::sethintLabel(QString sText)
{
     ui->hintLabel->setText(sText);
}

void LoginWidget::initConnect()
{
    connect( ui->closedButton, SIGNAL( clicked()), this, SIGNAL( sig_close_login_widget() ) );
//    connect( ui->minimizeButton, SIGNAL( clicked()), this, SIGNAL( sig_minimize_login_widget() ) );
    connect(ui->keyboardWidget, SIGNAL(sigText(QString)), this, SLOT(slot_Text(QString)));
    connect(ui->keyboardWidget, SIGNAL(sigDelete()), this, SLOT(slot_Delete()));
    connect(ui->keyboardWidget, SIGNAL(sigClear()), this, SLOT(slot_Clear()));
    connect(ui->keyboardWidget, SIGNAL(sigConfirm()), this, SLOT(slot_Confirm()));
    connect(m_pLoginKPosCtr, SIGNAL(sigOnLoginKPos(int, QString, bool)), this, SLOT(slot_onLoginKPos(int, QString, bool)));
    connect(m_pLoginKPosCtr, SIGNAL(sigOnGetAllGoods(int, QString)), this, SLOT(slot_onGetAllGoods(int, QString)));
    connect(m_pLoginKPosCtr, SIGNAL(sigOnGetAllGoodsPrice(int,QString)), this, SLOT(slot_onGetAllGoodsPrice(int,QString)));
    connect(m_pLoginKPosCtr, SIGNAL(sigOnGetCategory(int, QString)), this, SLOT(slot_onGetCategory(int, QString)));
    connect(m_pLoginKPosCtr, SIGNAL(sigDownloadKPosSetFinished()), this, SLOT(slot_downloadKPosSetFinished()));
    connect(m_pLoginKPosCtr, SIGNAL(sigRemoteADChanged(QList<QString>)), this, SIGNAL(sigRemoteADChanged(QList<QString>)));
    connect(m_pLoginKPosCtr, SIGNAL(sigOnLogoutKPos(int,QString)), this, SLOT(slot_onLogoutKPos(int,QString)));
    connect(m_pLoginKPosCtr, SIGNAL(sigFinisReceipUpload(bool)), this, SLOT(slot_onFinisReceipUpload(bool)));
}

void LoginWidget::init()
{
    ui->hintLabel->setText( "" );
    showLoginPage();
}

//获取所有用户信息请求
void LoginWidget::getAllUserInfoRequest()
{
    m_pLoginKPosCtr->getAllUserInfoRequest();
}

//void LoginWidget::resizeEvent( QResizeEvent *event )
//{
//    Q_UNUSED( event )

//    int nCentorX = getCentorPosX();
//    ui->splitLine->move( nCentorX, 0 );
//    ui->splitLine->resize( 5, height() );

//    setLoginInfoWidgetPos();
//    setKeyBoardPos();

//    int nButtonWidth = ui->closedButton->width();
//    int nX = width() - ButtonSpace - nButtonWidth;
//    ui->closedButton->move( nX, ButtonSpace );
//    nX = nX - ButtonSpace - nButtonWidth;
//    //    ui->minimizeButton->move( nX, ButtonSpace );
//}

void LoginWidget::showEvent(QShowEvent *)
{
    int nCentorX = getCentorPosX();
    ui->splitLine->move( nCentorX, 0 );
    ui->splitLine->resize( 5, height() );

    setLoginInfoWidgetPos();
    setKeyBoardPos();

    int nButtonWidth = ui->closedButton->width();
    int nX = width() - ButtonSpace - nButtonWidth;
    ui->closedButton->move( nX, ButtonSpace );
    nX = nX - ButtonSpace - nButtonWidth;
}

int LoginWidget::getCentorPosX()
{
    int nWidth = width();

    return nWidth/2;
}

void LoginWidget::setLoginInfoWidgetPos()
{
    int nHeight = height();

    int nInfoWidth = ui->loginInfoWidget->width();
    int nInfoHeight = ui->loginInfoWidget->height();

    int nCentorX = getCentorPosX();

    int nInfoX = nCentorX - WidthSpace - nInfoWidth;
    int nInfoY = ( nHeight - nInfoHeight )/2;
    ui->loginInfoWidget->move( nInfoX, nInfoY );
}

void LoginWidget::setKeyBoardPos()
{
    int nHeight = height();
    int nKeyHeight = ui->keyboardWidget->height();

    int nCentorX = getCentorPosX();

    int nKeyX = nCentorX + WidthSpace;
    int nKeyY = ( nHeight - nKeyHeight )/2;
    ui->keyboardWidget->move( nKeyX, nKeyY );
}

//按Enter键也可以进入该槽函数
void LoginWidget::on_loginButton_clicked()
{
    ui->hintLabel->setText( "" );

    if (ui->userNameEdit->text().isEmpty())
    {
        ui->userNameEdit->setFocus();
        ui->hintLabel->setText(QStringLiteral("用户名不能为空！"));
        ui->hintLabel->show();
        return;
    }
    else if (ui->passwordEdit->text().isEmpty())
    {
        ui->passwordEdit->setFocus();
        ui->hintLabel->setText(QStringLiteral("密码不能为空！"));
        ui->hintLabel->show();
        return;
    }

    if (m_pLoginKPosCtr != NULL)
    {
        ui->hintLabel->setText("正在登陆中...");
        m_pLoginKPosCtr->loginKPosRequest(ui->userNameEdit->text(), ui->passwordEdit->text());
    }
}

void LoginWidget::slot_onLoginKPos(int nCode, QString sMsg, bool isAllowLocalLogin)
{
    ui->hintLabel->show();
    if (nCode == e_success || (nCode == e_connectServerError && isAllowLocalLogin))
    {
        if (ui->stackedWidget->currentIndex() == 0)
        {
            ui->hintLabel->setText(QStringLiteral("登录成功，正在初始化数据..."));
            KPosIni::setUserCode( ui->userNameEdit->text() );
            KPosIni::setPassword( ui->passwordEdit->text() );

            //发送获取当前门店所有人员的信息请求
            getAllUserInfoRequest();
        }
        else   //锁屏
        {
            ui->stackedWidget->setCurrentIndex(0);
            emit sigLoginSuccess();
        }
    }
    else
    {
        ui->hintLabel->setText(sMsg);
    }
}

void LoginWidget::slot_onGetCategory(int nCode, QString sMsg)
{
    ui->hintLabel->show();
    if (nCode == e_success)
    {
        ui->hintLabel->setText(QStringLiteral("%1").arg(sMsg));
    }
    else
    {
        ui->hintLabel->setText(QString("%1:%2，取本地分类").arg(nCode).arg(sMsg));
    }
}

void LoginWidget::slot_onLogoutKPos(int nCode, QString sMsg)
{
    if (m_pLoginKPosCtr != NULL)
    {
        m_pLoginKPosCtr->printLogoutReceipt();
    }

    emit sigLogout();
}

void LoginWidget::slot_onGetAllGoods(int nCode, QString sMsg)
{
    ui->hintLabel->show();
    if (nCode == e_success)
    {
        ui->hintLabel->setText(QStringLiteral("商品初始化成功"));
    }
    else
    {
        ui->hintLabel->setText(QStringLiteral("%1:%2，取本地商品").arg(nCode).arg(sMsg));
    }
}

void LoginWidget::slot_onGetAllGoodsPrice(int nCode, QString sMsg)
{
    ui->hintLabel->show();
    if (nCode == e_success)
    {
        ui->hintLabel->setText(QStringLiteral("商品价格初始化成功"));
    }
    else
    {
        ui->hintLabel->setText(QString("%1:%2，取本地价格").arg(nCode).arg(sMsg));
    }
}

void LoginWidget::slot_downloadKPosSetFinished()
{
    ui->hintLabel->setText(QStringLiteral("设置信息获取完成"));
    emit sigLoginSuccess();
}

void LoginWidget::slot_onFinisReceipUpload(bool bSuccess)
{
    m_bUploadReceipSuccess = bSuccess;
    if (m_pDlgCommon != NULL)
    {
        if (bSuccess)
        {
            m_pDlgCommon->set_content(QStringLiteral("小票上传完毕！是否继续注销？"));
            m_pDlgCommon->set_btn_sure_text(QStringLiteral("关闭提示"));
            m_pDlgCommon->set_btn_cancel_text(QStringLiteral("继续注销"));
        }
        else
        {
            m_pDlgCommon->set_content(QStringLiteral("小票没有上传完毕，是否重试?"));
            m_pDlgCommon->set_btn_sure_text(QStringLiteral("继续上传"));
            m_pDlgCommon->set_btn_cancel_text(QStringLiteral("直接注销"));
        }
        m_pDlgCommon->showBottomWidget();
        m_pDlgCommon->activateWindow();
        m_pDlgCommon->showNormal();
    }
}

void LoginWidget::slot_dlgConfirm()
{
    emit sigConfirmLogout();
}

void LoginWidget::slot_dlgCanncel()
{
    if (m_bUploadReceipSuccess)
    {

    }
    else
    {
        checkUploadAllReceipt();
    }
}

void LoginWidget::slot_Text(QString sNum)
{
    if (ui->userNameEdit->hasFocus())
    {
        QString sText = ui->userNameEdit->text();
        ui->userNameEdit->setText(sText.append(sNum));
    }
    else if (ui->passwordEdit->hasFocus())
    {
        QString sText = ui->passwordEdit->text();
        ui->passwordEdit->setText(sText.append(sNum));
    }
}

void LoginWidget::slot_Delete()
{
    if (ui->userNameEdit->hasFocus())
    {
        QString sText = ui->userNameEdit->text();
        sText.remove(sText.length() - 1, 1);
        ui->userNameEdit->setText(sText);
    }
    else if (ui->passwordEdit->hasFocus())
    {
        QString sText = ui->passwordEdit->text();
        sText.remove(sText.length() - 1, 1);
        ui->passwordEdit->setText(sText);
    }
}

void LoginWidget::slot_Clear()
{
    if (ui->userNameEdit->hasFocus())
    {
        ui->userNameEdit->clear();
    }
    else if (ui->passwordEdit->hasFocus())
    {
        ui->passwordEdit->clear();
    }
}

void LoginWidget::slot_Confirm()
{
    on_loginButton_clicked();
}
