#ifndef SELLREFUNDCTR_H
#define SELLREFUNDCTR_H

#include <QWidget>
#include "../data/structData.h"

class SellRefundCtr : public QObject
{
    Q_OBJECT
public:
    explicit SellRefundCtr(QObject *parent = 0);
    void createSaleHead(int nSaleType = 0);
    void convertGoodsDetail(SaleDetails& saleDetails, const GoodsInfo &goodsInfo);

private:
//    int createNewOrderNumber();
//    int createNewSaleHeadId();

private:
    SaleHead m_stSaleHead;
};

#endif // SELLREFUNDCTR_H
