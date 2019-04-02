#ifndef OUTSTOCKCTRL_H
#define OUTSTOCKCTRL_H

#include <QObject>

#include "../data/stockdata.h"

class OutStockCtrl : public QObject
{
    Q_OBJECT
public:
    explicit OutStockCtrl(QObject *parent = 0);
    void getOutStockOrderListRequest(QString sStartDate, QString sEndDate, QString sSearchPatter);
    void checkOutStockOrderRequest(int nOrderId);
    void removeOutStockOrderRequest(int nOrderId); // 删除出库单
    void searchOutStockOrderRequest(int nOrderId); // 查看出库单
    void editOutStockOrderRequest(int nOrderId); // 编辑出库单
    void printOutStockOrderRequest(int nOrderId); // 打印出库单
    void saveOutStockOrderRequest(int nOrderId, const QList<OutStockSelectGoodsInfo>& selectGoodsInfoList);
    void getStockGoodsInfoRequest(int nGoodsId);

private:
    void initConnect();

signals:
    void sigOnGetOutStockOrderList(int nCode, QString sMsg, QList<OutStockOrderInfo> orderInfoList);
    void sigOnCheckOutStockOrder(int nCode, QString sMsg);
    void sigOnRemoveOutStockOrder(int nCode, QString sMsg, int nOrderId);
    void sigOnSearchOutStockOrder(int nCode, QString sMsg, QString sTotal,QList<OutStockOrderSearchInfo> searchInfoList);
    void sigOnEditOutStockOrder(int nCode, QString sMsg, QList<OutStockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnPrintOutStockOrder(int nCode, QString sMsg, QList<OutStockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnSaveOutStockOrder(int nCode, QString sMsg);
//    void sigOnGetOutStockGoodsInfo(const  QString& sMsg, float fBuyPrice);
};

#endif // OutStockCTRL_H
