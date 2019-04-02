#ifndef CUSTOMERDISPLAYDLG_H
#define CUSTOMERDISPLAYDLG_H

#include <QDialog>
#include "structData.h"

namespace Ui {
class CustomerDisplayDlg;
}

class CustomerDisplayDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerDisplayDlg(QWidget *parent = 0);
    ~CustomerDisplayDlg();
    void setRemoteAdList(QList<QString> remoteAdList);

public:
    void setCurrentIndex( int nIndex );

    void addGoodsToSaleList( SaleDetails stSaleDetailsInfo );
    void delGoodsToSaleList( int nSaleDetailsPos );
    void clearGoodsToSaleList();
    void loginMember( bool bMember );
private:
    void initCtrl();
private:
    Ui::CustomerDisplayDlg *ui;
};

#endif // CUSTOMERDISPLAYDLG_H
