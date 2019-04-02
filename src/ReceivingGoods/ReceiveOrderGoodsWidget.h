#ifndef RECEIVEORDERGOODSWIDGET_H
#define RECEIVEORDERGOODSWIDGET_H

#include <QWidget>
#include "../data/recievinggoodsdata.h"
#include "../Bussiness/DeliveryOrderCtrl.h"
#include "ReceiveOrderGoodsDetailDlg.h"

namespace Ui {
class ReceiveOrderGoodsWidget;
}

class ReceiveOrderGoodsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiveOrderGoodsWidget(QWidget *parent = 0);
    ~ReceiveOrderGoodsWidget();
    void initCtrl(DeliveryOrderCtrl* pDeliveryOrderCtrl);
    void initData(const QList<DeliveryOrderDetailInfo_s> &deliveryOrderDetailInfoList, bool bReceiveFinish);

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void on_confirmButton_clicked();
    void slot_receiveOrderGoodsDetail(int nDeliverGoodId);
    void slot_saveReceiveGoods(ReceiveGoodsDetail_s* pReceiveGoodsDetail, ReceiveOrderGoodsInfo* pReceiveOrderGoodsInfo);

    void slot_onGetReceiveGoodsDetail(int nCode, QString sMsg, ReceiveGoodsDetail_s receiveGoodsDetail_s, int nDeliveryGoodId);

private:
    void initConnect();
    void generateUI();
    void checkCurPageButtonState();
    ReceiveOrderGoodsInfo* findReceiveOrderGoodsInfo(int nDeliverGoodId);

signals:
    void sigSaveReceiveGoods(ReceiveOrderGoodsInfo *pReceiveOrderGoodsInfo, ReceiveOrderGoodsInfo oldReceiveOrderGoodsInfo);
    void sigFinishReceiveOrderGoods();

private:
    Ui::ReceiveOrderGoodsWidget *ui;
    QList<ReceiveOrderGoodsInfo> m_receiveOrderGoodsInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    ReceiveOrderGoodsDetailDlg* m_pReceiveOrderGoodsDetailDlg;
    float m_fSumPrice;
    DeliveryOrderCtrl* m_pDeliveryOrderCtrl;
};

#endif // RECEIVEORDERGOODSWIDGET_H
