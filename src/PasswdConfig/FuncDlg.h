#ifndef FUNCDLG_H
#define FUNCDLG_H

#include <QDialog>
#include <QLineEdit>
#include <QButtonGroup>
#include "httpstructdata.h"
#include "EmployeeManageCtrl.h"

namespace Ui {
class FuncDlg;
}

class FuncDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FuncDlg(QWidget *parent = 0);
    ~FuncDlg();
    void setTitleText(QString Text);
    void clearData();
    void setEmployeeScode(QString nScode);
    void initEmployeeManageCtrl(EmployeeManageCtrl* pEmployeeManageCtrl);
    void initEditStatus(int status);
    void initEditContent(AccountInfo info);

protected:
    void showEvent(QShowEvent *);

private slots:
    void slot_close_dlg();
    //键盘
    void slot_setText( QString strText );
    void slot_deleteValue();
    void slot_clearZero();
    void slot_enter();

    void on_saveButton_clicked();
    void slot_editEmployeeOrder(int nCode, QString sMsg);

signals:
    void sigEmployeeListChanged();
private:
    Ui::FuncDlg *ui;
    bool m_bFirst;
    QButtonGroup *RadioBtnGroup;
    EmployeeManageCtrl* m_pEmployeeManageCtrl;
    AccountInfo m_info;    
    void init();
    void initConnect();
    void initButton();
    void firstClick();
    bool getCurFocusWnd( QLineEdit *&pEditWnd );
    int m_editStatus;
    void clearEditContent();
};

#endif // FUNCDLG_H
