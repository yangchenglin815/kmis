#ifndef CREATEDELIVERYORDERDLG_H
#define CREATEDELIVERYORDERDLG_H

#include <QDialog>
#include "../data/recievinggoodsdata.h"

namespace Ui {
class CreateDeliveryOrderDlg;
}

class CreateDeliveryOrderDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CreateDeliveryOrderDlg(QWidget *parent = 0);
    ~CreateDeliveryOrderDlg();
    void showProviderPage();
    void test();
    QString createTestOrderId(int i);

private slots:
    void slot_clickProvider(int nProviderId);
    void slot_lastStep();
    void slot_searchChanged(QString text);
    void slot_confirmCreateOrder(QList<GoodsForCreateInfo*> goodsForCreateInfoList);

private:
    void initConnect();
    void clearData();

signals:
    void sigCreateOrder(ReceiveProviderInfo receiveProviderInfo);

private:
    Ui::CreateDeliveryOrderDlg *ui;
    QList<ReceiveProviderInfo*> m_receiveProviderInfoList;
    ReceiveProviderInfo* m_pSelectedReceiveProviderInfo;
};

#endif // CREATEDELIVERYORDERDLG_H
