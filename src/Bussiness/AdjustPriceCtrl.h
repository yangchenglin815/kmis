#ifndef ADJUSTPRICECTRL_H
#define ADJUSTPRICECTRL_H

#include <QObject>
#include "../data/adjustpricedata.h"

class AdjustPriceCtrl : public QObject
{
    Q_OBJECT
public:
    explicit AdjustPriceCtrl(QObject *parent = 0);
    void getAdjustPriceOrderListRequest(QString sStartDate, QString sEndDate, QString searchPatter);
    void checkAdjustPriceOrderRequest(int nOrderId);
    void removeAdjustPriceOrder(int nOrderId); // 删除改价单
    void searchAdjustPriceOrder(int nOrderId); // 查看改价单
    void editAdjustPriceOrder(int nOrderId); // 编辑改价单
    void printAdjustPriceOrder(int nOrderId); // 打印改价单
    void saveAdjustPriceOrder(int nOrderId, const QList<AdjustPriceSelectGoodsInfo>& selectGoodsInfoList);
    void startUpdateThread(); // 启动更新线程

private:
    void initConnect();

signals:
    void sigOnGetAdjustPriceOrderList(int nCode, QString sMsg, QList<AdjustPriceOrderInfo> orderInfoList);
    void sigOnCheckAdjustPriceOrder(int nCode, QString sMsg, int nOrderId);
    void sigOnRemoveAdjustPriceOrder(int nCode, QString sMsg, int nOrderId);
    void sigOnSearchAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> searchInfoList);
    void sigOnEditAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnPrintAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnSaveAdjustPriceOrder(int nCode, QString sMsg);
};

#endif // ADJUSTPRICECTRL_H
