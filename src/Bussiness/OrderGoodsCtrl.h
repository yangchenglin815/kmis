#ifndef ORDERGOODSCTRL_H
#define ORDERGOODSCTRL_H

#include <QObject>
#include "../data/ordergoodsdata.h"

class OrderGoodsCtrl : public QObject
{
    Q_OBJECT
public:
    explicit OrderGoodsCtrl(QObject *parent = 0);
    void getOrderCategoryRequest();
    void getOrderGoodsRequest(int nCategoryBigId);
    void createOrderCardRequest(const QList<OrderGoodsInfo *>& orderGoodsInfoList);

private slots:
    void slot_onGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> categoryBigInfoList);

private:
    void initConnect();

signals:
    void sigOnGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s>);
    void sigOnGetOrderGoods(int nCode, QString sMsg, QList<OrderGoodsInfo_s>, int nCategoryBigId);
    void sigOnCreateOrderCard(int,QString);
};

#endif // ORDERGOODSCTRL_H
