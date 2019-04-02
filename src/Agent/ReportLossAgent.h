#ifndef REPORTLOSSAGENT_H
#define REPORTLOSSAGENT_H

#include <QObject>
#include "../data/httpstructdata.h"

class ReportLossAgent : public QObject
{
    Q_OBJECT
public:
    static ReportLossAgent* instance();
    void getReportLossOrderListRequest(QString sStartDate, QString sEndDate, QString searchPatter);
    void AddReportLossListRequest(QList<AddReportLossSelectInfo> infoList);
    void editReportLossListRequest(QList<AddReportLossSelectInfo> infoList, int selectId);
    void deleteReportLossListRequest(int selectId);
    void checkReportLossListRequest(int selectId);
    void getReportLossDetialRequest(int selectId, int mode);

private:
    explicit ReportLossAgent(QObject *parent = 0);
    void initConnect();

signals:
    void sigOnGetReportLossOrderList(int nCode, QString sMsg, QList<ReportLossInfo> orderInfoList);
    void sigAddReportLossOrderList(int nCode, QString sMsg);
    void sigEditReportLossOrderList(int nCode, QString sMsg);
    void sigDeleteReportLossOrderList(int nCode, QString sMsg);
    void sigCheckReportLossOrderList(int nCode, QString sMsg);
    void sigOnGetReportLossDeitalOrderList(int nCode, QString sMsg, QList<AddReportLossSelectInfo> infoList);
    void sigOnGetEditReportLossDetialOrder(int nCode, QString sMsg, QList<AddReportLossSelectInfo> infoList, int selectId);
    void sigOnGetPrintReportLossDetialOrder(int nCode, QString sMsg, QList<AddReportLossSelectInfo> infoList, int selectId);

private:
    static ReportLossAgent* m_pInstance;
};

#endif // REPORTLOSSAGENT_H
