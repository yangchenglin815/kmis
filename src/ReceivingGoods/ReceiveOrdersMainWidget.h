#ifndef RECEIVEORDERSMAINWIDGET_H
#define RECEIVEORDERSMAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "../data/recievinggoodsdata.h"

namespace Ui {
class ReceiveOrdersMainWidget;
}

class ReceiveOrdersMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiveOrdersMainWidget(QWidget *parent = 0);
    ~ReceiveOrdersMainWidget();
    void initData(const QList<ReceiveOrderInfo*>& receiveOrdersInfoList);
    void updateData();
    void appendData(ReceiveOrderInfo* pReceiveOrderInfo);

private slots:
    void on_allRecieveButton_clicked();
    void on_noFinishReciveButton_clicked();
    void on_finishedRecieveButton_clicked();
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void on_createDeliveryOrderButton_clicked();
    void slot_checkReceiveOrder(int nOrderId);
    void slot_createOrder(ReceiveProviderInfo receiveProviderInfo);

private:
    void setButtonQss(QPushButton* pPushButton);
    void init();
    void initConnect();
    void generateUI();
    void checkCurPageButtonState();
    void setFinishAndNotList();
    void updateClick();

signals:
    void sigCheckReceiveOrder(int nOrderId);
    void sigCreateOrder(ReceiveOrderInfo* pReceiveOrderInfo);
    void sigCreateDeliveryOrder();

private:
    Ui::ReceiveOrdersMainWidget *ui;
    QPushButton* m_pSelectedButton;
    QList<ReceiveOrderInfo*> m_receiveOrdersInfoList;
    QList<ReceiveOrderInfo*> m_allOrdersInfoList;
    QList<ReceiveOrderInfo*> m_notFinishOrdersInfoList;
    QList<ReceiveOrderInfo*> m_finishOrdersInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // RECEIVEORDERSMAINWIDGET_H
