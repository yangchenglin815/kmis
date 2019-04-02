#ifndef REPORTLOSSCTRL_H
#define REPORTLOSSCTRL_H

#include <QObject>
#include "../data/httpstructdata.h"

class ReportLossCtrl : public QObject
{
    Q_OBJECT
public:
    explicit ReportLossCtrl(QObject *parent = 0);
    void getReportLossOrderListRequest(QString sStartDate, QString sEndDate, QString searchPatter);
    void AddReportLossListRequest(QList<AddReportLossSelectInfo> infoList);
    void editReportLossListRequest(QList<AddReportLossSelectInfo> infoList, int selectId);
    void deleteReportLossListRequest(int selectId);
    void checkReportLossListRequest(int selectId);
    void getReportLossDetialRequest(int selectId, int mode);

private slots:
    void slot_categoryGoodsChanged();

signals:
    void sigCategoryGoodsChanged();

private:
    void initConnect();

signals:
    void sigOnGetReportLossOrderList(int nCode, QString sMsg, QList<ReportLossInfo> infoList);
    void sigAddReportLossOrderList(int nCode, QString sMsg);
    void sigEditReportLossOrderList(int nCode, QString sMsg);
    void sigDeleteReportLossOrderList(int nCode, QString sMsg);
    void sigCheckReportLossOrderList(int nCode, QString sMsg);
    void sigOnGetReportLossDetialOrderList(int nCode, QString sMsg, QList<AddReportLossSelectInfo> infoList);
    void sigOnGetEditReportLossDetialOrder(int nCode, QString sMsg, QList<AddReportLossSelectInfo> infoList, int selectId);
    void sigOnGetPrintReportLossDetialOrder(int nCode, QString sMsg, QList<AddReportLossSelectInfo> infoList, int selectId);
};

#endif // REPORTLOSSCTRL_H
