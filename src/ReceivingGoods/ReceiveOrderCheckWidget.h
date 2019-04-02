#ifndef RECEIVEORDERCHECKWIDGET_H
#define RECEIVEORDERCHECKWIDGET_H

#include <QWidget>
#include "../data/recievinggoodsdata.h"
#include "../Bussiness/DeliveryOrderCtrl.h"

namespace Ui {
class ReceiveOrderCheckWidget;
}

class ReceiveOrderCheckWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiveOrderCheckWidget(QWidget *parent = 0);
    ~ReceiveOrderCheckWidget();
//    void initData(ReceiveOrderInfo* pReceiveOrderInfo, bool isFinished);
    void initCtrl(DeliveryOrderCtrl* pDeliveryOrderCtrl);
    void initData(const QList<DeliveryOrderDetailInfo_s>& deliveryOrderDetailInfoList, ReceiveOrderInfo* pReceiveOrderInfo);

private slots:
    void on_backButton_clicked();
    void slot_saveReceiveGoods(ReceiveOrderGoodsInfo *pReceiveOrderGoodsInfo, ReceiveOrderGoodsInfo receiveOrderGoodsInfo);
    void slot_finishReceiveOrderGoods();

private:
    void initConnect();

signals:
    void sigBack();

private:
    Ui::ReceiveOrderCheckWidget *ui;
    ReceiveOrderInfo* m_pReceiveOrderInfo;
};

#endif // RECEIVEORDERCHECKWIDGET_H
