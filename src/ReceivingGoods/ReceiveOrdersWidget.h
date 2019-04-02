#ifndef RECEIVEORDERSWIDGET_H
#define RECEIVEORDERSWIDGET_H

#include <QWidget>
#include "CreateDeliveryOrderDlg.h"
#include "../data/recievinggoodsdata.h"
#include "../Bussiness/DeliveryOrderCtrl.h"

namespace Ui {
class ReceiveOrdersWidget;
}

class ReceiveOrdersWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiveOrdersWidget(QWidget *parent = 0);
    ~ReceiveOrdersWidget();
    void test();
    QString createTestOrderId(int i);
    void getDeliveryOrderList(); // 获取送货单列表
    void clearData();

private slots:
    void slot_search(QString providerText,QString receiptTypeText, QString dateStartText, QString dateEndText);
    void slot_checkReceiveOrder(int nOrderId);
    void slot_back();
    void slot_returnClicked();
    void slot_createOrder(ReceiveProviderInfo receiveProviderInfo);
    void slot_createDeliveryOrder();

    void slot_onGetDeliveryOrderList(int nCode, QString sMsg, QList<DeliveryOrderInfo_s> deliveryOrderInfoList);
    void slot_onStartReceiveGoods(int nCode, QString sMsg, int nDeliveryId);
    void slot_onGetDeliveryDetail(int nCode, QString sMsg, QList<DeliveryOrderDetailInfo_s> deliveryOrderDetailInfoList, int nDeliveryId);

private:
    void initConnect();

signals:
    void sigReturnClicked();

private:
    Ui::ReceiveOrdersWidget *ui;
    QList<ReceiveOrderInfo*> m_receiveOrderInfoList;
    CreateDeliveryOrderDlg* m_pCreateDeliveryOrderDlg;
    QString m_sSearchStartDate;
    QString m_sSearchEndDate;
    DeliveryOrderCtrl* m_pDeliveryOrderCtrl;
};

#endif // RECEIVEORDERSWIDGET_H
