#ifndef REPORTLOSSWID_H
#define REPORTLOSSWID_H

#include <QWidget>
#include "../Bussiness/ReportLossCtrl.h"
#include "structData.h"

namespace Ui {
class ReportLossWid;
}

class ReportLossWid : public QWidget
{
    Q_OBJECT

public:
    explicit ReportLossWid(QWidget *parent = 0);
    ~ReportLossWid();
    void initReportLossCtrl();
    void setCategoryList(QList<CategoryInfo*> categoryInfoList);

signals:
    void sigReturnClicked();

private slots:
    void slot_showDetialPage();
    void slot_showAddReportLossPage();
    void slot_ReturnClicked();
    void slot_printReportLossOrder(QList<AddReportLossSelectInfo> infoList, int nOrderId);
    void slot_updateOrder();
    void slot_getReportLossDetial(QList<AddReportLossSelectInfo> orderInfoList);
    void slot_showEditReportLossPage();

private:
    Ui::ReportLossWid *ui;
    void init();
    void initconnect();
    ReportLossCtrl* m_reportLossCtrl;
};

#endif // REPORTLOSSWID_H
