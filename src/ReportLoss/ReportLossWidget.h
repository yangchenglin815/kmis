#ifndef REPORTLOSSWIDGET_H
#define REPORTLOSSWIDGET_H

#include <QWidget>
#include "httpstructdata.h"
#include "KPosCalendarWidget.h"
#include "../data/stockdata.h"
#include "../Bussiness/InStockCtrl.h"
#include "../Bussiness/ReportLossCtrl.h"
#include "../data/httpstructdata.h"

namespace Ui {
class ReportLossWidget;
}

class ReportLossWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReportLossWidget(QWidget *parent = 0);
    ~ReportLossWidget();
    void initData(const QList<ReportLossInfo>& itemInfoList);
    void hideCalendarWidget();
    void initReportLossCtrl(ReportLossCtrl* pReportLossCtrl);
    void printReportLossOrder(const QList<AddReportLossSelectInfo>& InfoList, int nOrderId);
    void getReportLossOrder();

protected:
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *watched, QEvent *event);

signals:
    void showDetialPage();
    void showAddReportLossPage();
    void showEditReportLossPage();
    void getReportLossDetialOrder(QList<AddReportLossSelectInfo> orderInfoList);

private slots:
    void slot_onGetReportLossOrderList(int nCode, QString sMsg, QList<ReportLossInfo> orderInfoList);
    void slot_deleteReportLossOrderList(int nCode, QString sMsg);
    void slot_checkReportLossOrderList(int nCode, QString sMsg);
    void slot_getReportLossDetialOrderList(int nCode, QString sMsg, QList<AddReportLossSelectInfo> orderInfoList);
    void slot_printReportLossDetialOrder(int nCode, QString sMsg, QList<AddReportLossSelectInfo> orderInfoList, int orderId);
    void slot_clickDate(int nYear, int nMonth, int nDay);
    void slot_clickAdjustItem(ReportLossInfo reportLossInfo);
    void slot_searchChanged(QString str);
    void on_nextPageButton_clicked();

    void on_lastPageButton_clicked();

    void on_deleteButton_clicked();

    void on_reviewButton_clicked();

    void on_printButton_clicked();

    void on_checkButton_clicked();

    void on_editButton_clicked();

    void on_addButton_clicked();

private:
    Ui::ReportLossWidget *ui;
    QList<ReportLossInfo> m_InfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    KPosCalendarWidget* m_pKPosCalendarWidget;
    bool m_bInStartDate;
    QString m_sStartDate;
    QString m_sEndDate;
    QString m_sSearchPattern;
    ReportLossCtrl* m_reportLossCtrl;

private:
    void initConnect();
    void initButton();
    void init();
    void generateUI();
    void checkCurPageButtonState();
    void test();
    void inputStartDate();
    void inputEndDate();
    void setButtonsState(bool nState);
};

#endif // REPORTLOSSWIDGET_H
