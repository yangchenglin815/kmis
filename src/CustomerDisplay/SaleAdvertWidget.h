#ifndef SALEADVERTWIDGET_H
#define SALEADVERTWIDGET_H

#include <QWidget>
#include "structData.h"
#include "BalanceManage.h"

namespace Ui {
class SaleAdvertWidget;
}

class SaleAdvertWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SaleAdvertWidget(QWidget *parent = 0);
    ~SaleAdvertWidget();

    void addGoodsToSaleList( SaleDetails stSaleDetailsInfo );
    void delGoodsToSaleList( int nSaleDetailsPos );
    void clearGoodsToSaleList();
    void loginMember( bool bMember );
    int getSaleDetailsNum();
    void setFileList(QList<QString> adList);
public slots:
    void slot_stableInfo( EBalanceStandard_Ex balanceStandard_Ex, bool bStable );
private:
    void updateAddGoodsInfo( SaleDetails stSaleDetailsInfo );
private:
    Ui::SaleAdvertWidget *ui;
};

#endif // SALEADVERTWIDGET_H
