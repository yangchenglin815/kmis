#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QDialog>
#include "LoginKPosCtr.h"
#include "DlgCommon.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();
    void showLoginPage(); // 登录页
    void showLockPage(); // 锁屏页
    void initUserName();
    void checkUploadAllReceipt(); // 检查上传所有小票
    void logout(QString sSubmitMoney); // 注销
    void clearData();
    void sethintLabel(QString sText); //设置提示问题

protected:
//    void resizeEvent( QResizeEvent *event );
    void showEvent(QShowEvent *);

signals:
    void sig_close_login_widget();
    void sig_minimize_login_widget();

private slots:
    void on_loginButton_clicked();
    void slot_onLoginKPos(int nCode, QString sMsg, bool isAllowLocalLogin);    
    void slot_onGetAllGoods(int nCode, QString sMsg);
    void slot_onGetAllGoodsPrice(int nCode, QString sMsg);
    void slot_onGetCategory(int nCode, QString sMsg);
    void slot_onLogoutKPos(int nCode, QString sMsg);
    void slot_downloadKPosSetFinished(); 
    void slot_onFinisReceipUpload(bool bSuccess);
    void slot_dlgConfirm();
    void slot_dlgCanncel();

    // 小键盘
    void slot_Text(QString sNum);
    void slot_Delete();
    void slot_Clear();
    void slot_Confirm();

private:
    int getCentorPosX();
    void setLoginInfoWidgetPos();
    void setKeyBoardPos();
    void initConnect();
    void init();
    void getAllUserInfoRequest();

signals:
    void sigLoginSuccess();
    void sigRemoteADChanged(QList<QString> remoteADList);
    void sigLogout();
    void sigConfirmLogout();

private:
    Ui::LoginWidget *ui;
    LoginKPosCtr* m_pLoginKPosCtr;
    DlgCommon* m_pDlgCommon;
    bool m_bUploadReceipSuccess;
};

#endif // LOGINWIDGET_H
