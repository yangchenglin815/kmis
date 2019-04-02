#ifndef ADDREPORTLOSSDLG_H
#define ADDREPORTLOSSDLG_H

#include <QDialog>
#include <QButtonGroup>
#include "httpstructdata.h"

namespace Ui {
class AddReportLossDlg;
}

class AddReportLossDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddReportLossDlg(QWidget *parent = 0);
    ~AddReportLossDlg();
    void setGoodsInfo(const AddReportLossSelectInfo& lossInfo);
    void initMode(int mode);


private slots:
    // 小键盘
    void slot_Text(QString sNum);
    void slot_Delete();
    void slot_Clear();
    void slot_Confirm();
    void on_saveButton_clicked();

signals:
    void sigModifyLossNumber(AddReportLossSelectInfo lossInfo);
    void sigSendDlgMode(int mode);

private:
    void init();
    void initconnect();

private:
    Ui::AddReportLossDlg *ui;
    QButtonGroup *buttonGroup;
    AddReportLossSelectInfo m_info;
    int dlgMode; // 1:新增 2:编辑
};

#endif // ADDREPORTLOSSDLG_H
