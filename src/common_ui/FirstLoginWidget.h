#ifndef FIRSTLOGINWIDGET_H
#define FIRSTLOGINWIDGET_H

#include <QDialog>
#include "../Bussiness/PosRegisterCtr.h"
#include "ShopInfoDlg.h"

namespace Ui {
class FirstLoginWidget;
}

class FirstLoginWidget : public QDialog
{
    Q_OBJECT

public:
    explicit FirstLoginWidget(QWidget *parent = 0);
    ~FirstLoginWidget();
    void setPosRegisterCtr(PosRegisterCtr* posRegisterCtr);
    void setHintText(QString str);
    void hideHintText();
    void showRegistPage(bool isShow);
    void setEditEnabled( bool bEnabled );

protected:
//    void resizeEvent( QResizeEvent *event );
    void keyPressEvent(QKeyEvent *event);

signals:
    void sig_close_login_widget();
    void sig_minimize_login_widget();
    //void sig_upload();//上传申请 

private slots:
    void on_uploadButton_clicked();
    // 小键盘
    void slot_Text(QString sNum);
    void slot_Delete();
    void slot_Clear();
    void slot_Confirm();
    //
    void slot_onGetShopInfo(int nCode, QString sMsg, ShopInfo shopInfo);
    void slot_confirmRegist();
    void slot_cancel();
    void slot_onRegisterPos(int nCode, QString sMsg);

private:
//    int getCentorPosX();
//    void setLoginInfoWidgetPos();
//    void setKeyBoardPos();
    void initConnect();
    void init();
    void showWidget(bool bRegistPage);

private:
    Ui::FirstLoginWidget *ui;
    PosRegisterCtr* m_pPosRegisterCtr;
    ShopInfoDlg* m_pShopInfoDlg; // 门店信息提示框
};

#endif // FIRSTLOGINWIDGET_H
