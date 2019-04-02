#ifndef PASSWDCONFIGWIDGET_H
#define PASSWDCONFIGWIDGET_H

#include <QWidget>
#include "FuncDlg.h"
#include "../Bussiness/EmployeeManageCtrl.h"

namespace Ui {
class PasswdConfigWidget;
}

class PasswdConfigWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PasswdConfigWidget(QWidget *parent = 0);
    ~PasswdConfigWidget();
     void initData(const QList<AccountInfo>& itemInfoList);
     void initEmployeeList();

signals:
    void sig_backHomePage();
    void sigUpdateSelectCount(QList<int> keyIdList);

protected:
    void showEvent(QShowEvent *);

private slots:
    void slot_employeeListChanged();
    void slot_getEmployeeManageList(int nCode, QString sMsg, QList<AccountInfo> orderInfoList);
    void slot_changeEmployeeStatusOrder(int nCode, QString sMsg, QList<int> orderList, int status);
    void slot_getEmployeeScodeOrder(int nCode, QString sMsg, QString nScode);
    void slot_selectCurPageAllBox(bool bSelectAll);
    void slot_searchChanged(QString str);
    void slot_clickItem();

    void on_backButton_clicked();

    void on_addButton_clicked();

    void on_lastPageButton_clicked();

    void on_nextPageButton_clicked();

    void on_deleteButton_clicked();

    void on_stopButton_clicked();

    void on_startButton_clicked();

    void on_editButton_clicked();

private:
    Ui::PasswdConfigWidget *ui;    
    FuncDlg *dlg;
    int dlgx;
    int dlgy;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    EmployeeManageCtrl* m_pEmployeeManageCtrl;
    QList<AccountInfo> m_InfoList;
    QString m_sSearchPattern;
private:
    void initConnect();
    void initButton();
    void init();
    void generateUI();
    void checkCurPageButtonState();
    void test();
    void setCheckedBtnStatus();
    void setUncheckedBtnStatus();
    void updateUI(int count);
};

#endif // PASSWDCONFIGWIDGET_H
