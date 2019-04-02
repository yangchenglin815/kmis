#ifndef STOCKDLG_H
#define STOCKDLG_H

#include <QDialog>
#include "../Bussiness/StockCtrl.h"

namespace Ui {
class StockDlg;
}

class StockDlg : public QDialog
{
    Q_OBJECT

public:
    explicit StockDlg(QWidget *parent = 0);
    ~StockDlg();
    void setGoodsInfo(const StockSelectGoodsInfo& goodsInfo);
    void showAddPage();
    void showModifyPage(float fShouldStockNum, float fLastRealStockNum);
    void setStockCtrl(StockCtrl* pStockCtrl);

private slots:
    // 小键盘
    void slot_Text(QString sNum);
    void slot_Delete();
    void slot_Clear();
    void slot_Confirm();
    void on_saveButton_clicked();
    void slot_onGetStockGoodsInfo(int nCode, QString sMsg, GoodsStockInfo goodsStockInfo);

private:
    void initConnect();

signals:
    void sigAddStockGoods(StockSelectGoodsInfo goodsInfo);

private:
    Ui::StockDlg *ui;
    StockSelectGoodsInfo m_goodsInfo;
    StockCtrl* m_pStockCtrl;
    float m_fBuyPrice;
};

#endif // STOCKDLG_H
