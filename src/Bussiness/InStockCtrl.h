#ifndef INSTOCKCTRL_H
#define INSTOCKCTRL_H

#include <QObject>

#include "../data/stockdata.h"
#include "structData.h"
#include "setstructdata.h"

class InStockCtrl : public QObject
{
    Q_OBJECT
public:
    explicit InStockCtrl(QObject *parent = 0);
    void getInStockOrderListRequest(QString sStartDate, QString sEndDate, QString sSearchPatter);
    void checkInStockOrderRequest(int nOrderId);
    void removeInStockOrderRequest(int nOrderId); // 删除入库单
    void searchInStockOrderRequest(int nOrderId); // 查看入库单
    void editInStockOrderRequest(int nOrderId); // 编辑入库单
    void printInStockOrderRequest(int nOrderId); // 打印入库单
    void saveInStockOrderRequest(int nOrderId, const QList<InStockSelectGoodsInfo>& selectGoodsInfoList);
    void getStockGoodsInfoRequest(int nGoodsId);

private:
    void initConnect();

signals:
    void sigOnGetInStockOrderList(int nCode, QString sMsg, QList<InStockOrderInfo> orderInfoList);
    void sigOnCheckInStockOrder(int nCode, QString sMsg);
    void sigOnRemoveInStockOrder(int nCode, QString sMsg, int nOrderId);
    void sigOnSearchInStockOrder(int nCode, QString sMsg, QString sTotal,QList<InStockOrderSearchInfo> searchInfoList);
    void sigOnEditInStockOrder(int nCode, QString sMsg, QList<InStockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnPrintInStockOrder(int nCode, QString sMsg, QList<InStockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnSaveInStockOrder(int nCode, QString sMsg);
};

#endif // INSTOCKCTRL_H
