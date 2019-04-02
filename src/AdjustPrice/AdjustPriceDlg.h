#ifndef ADJUSTPRICEDLG_H
#define ADJUSTPRICEDLG_H

#include <QDialog>
#include "../data/adjustpricedata.h"

namespace Ui {
class AdjustPriceDlg;
}

class AdjustPriceDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AdjustPriceDlg(QWidget *parent = 0);
    ~AdjustPriceDlg();    
    void setGoodsInfo(const AdjustPriceSelectGoodsInfo& goodsInfo);

private slots:
    // 小键盘
    void slot_Text(QString sNum);
    void slot_Delete();
    void slot_Clear();
    void slot_Confirm();
    void on_saveButton_clicked();

private:
    void initConnect();

signals:
    void sigModifyGoodsPrice(AdjustPriceSelectGoodsInfo goodsInfo);

private:
    Ui::AdjustPriceDlg *ui;
    AdjustPriceSelectGoodsInfo m_goodsInfo;
};

#endif // ADJUSTPRICEDLG_H
