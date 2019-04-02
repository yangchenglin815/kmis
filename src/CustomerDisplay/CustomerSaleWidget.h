#ifndef CUSTOMERSALEWIDGET_H
#define CUSTOMERSALEWIDGET_H

#include <QWidget>
#include "structData.h"

namespace Ui {
class CustomerSaleWidget;
}

class CustomerSaleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerSaleWidget(QWidget *parent = 0);
    ~CustomerSaleWidget();

    void addGoodsToSaleList( SaleDetails stSaleDetailsInfo );
    void updateGoodsToSaleList( SaleDetails stSaleDetailsInfo );
    void delGoodsToSaleList( int nSaleDetailsPos );
    void clearGoodsToSaleList();
    void updateGoodsList();
    int getSaleDetailsNum();

    void loginMember( bool bMember );
    bool isGoods( int nGoodsId );
private:
    void generateSellList();
    void updateGoodsSumPrice();
    int getCurPageNum( int nGoodsPos );
    int getTotalPageNum( int nGoodsPos );
private:
    Ui::CustomerSaleWidget *ui;

    QMap< int, SaleDetails > m_mapSaleDetailInfo;//key:nPos

    int m_nCurPage;
    int m_nTotalPage;
    int m_nOnePageCount;
    bool m_bMemSell;
};

#endif // CUSTOMERSALEWIDGET_H
