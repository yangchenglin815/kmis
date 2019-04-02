#ifndef ADDREPORTLOSSWIDGET_H
#define ADDREPORTLOSSWIDGET_H

#include <QWidget>
#include "../data/httpstructdata.h"
#include "AddReportLossDlg.h"
#include "../data/structData.h"
#include "../Bussiness/ReportLossCtrl.h"

namespace Ui {
class AddReportLossWidget;
}

class AddReportLossWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddReportLossWidget(QWidget *parent = 0);
    ~AddReportLossWidget();
    void setCategoryList(QList<CategoryInfo *> categoryInfoList);
    void initReportLossCtrl(ReportLossCtrl* reportLossCtrl);
    void initSelectGoodsData(const QList<AddReportLossSelectInfo> &searchInfoList, int nOrderId);
    void initMode(int mode);
    float getGoodsPrice(const AddReportLossSelectInfo& lossInfo);
    void initEditPage();

protected:
    void showEvent(QShowEvent *);

private slots:
    void slot_searchChanged(QString str);
    void slot_getSendDlgMode(int mode);
    void slot_editReportLossOrder(int nCode, QString sMsg);
    void slot_getEditReportLossDetialOrder(int nCode, QString sMsg, QList<AddReportLossSelectInfo> infoList, int selectId);
    void slot_clickItem(AddReportLossSelectInfo selectInfo);
    void slot_addReportLossOrderList(int nCode, QString sMsg);
    void slot_ModifyLossNumber(AddReportLossSelectInfo lossInfo);
    void slot_clickGoodsItem(GoodsInfo goodsInfo);
    void slot_clickCategoryItem(CategoryInfo categoryInfo);

    void on_deleteButton_clicked();

    void on_modeifyNoButton_clicked();

    void on_printButton_clicked();

    void on_saveButton_clicked();

signals:
    void sigSaveOrderSuccess();
    void sigPrintReportLossOrder(QList<AddReportLossSelectInfo> selectInfoList, int nOrderId);

private:
    Ui::AddReportLossWidget *ui;
    AddReportLossDlg* addLossDlg;
    ReportLossCtrl* m_reportLossCtrl;
    int m_nOrderId;
    QList<AddReportLossSelectInfo>* m_sreportLossInfoList;
    int dlgMode; // 1:新增 2:编辑
    int getDlgMode; // 弹出对话框类型 1:新增 2:编辑
    QList<GoodsInfo> listGoodsInfo;

private:
    void init();
    void initconnect();
    void initButton();
};

#endif // ADDREPORTLOSSWIDGET_H
