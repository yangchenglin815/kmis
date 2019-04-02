#ifndef ADDINSTKDLG_H
#define ADDINSTKDLG_H

#include <QDialog>
#include "stockData.h"
#include "../Bussiness/InStockCtrl.h"

namespace Ui {
class AddInStkDlg;
}

class AddInStkDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddInStkDlg(QWidget *parent = 0);
    ~AddInStkDlg();
    void setGoodsInfo(const InStockSelectGoodsInfo& goodsInfo);
//    void showModifyPage(float fShouldStockNum, float fShouldTotal,float fShouldPrice,float fNum );
    void setInStockCtrl(InStockCtrl* pStockCtrl);
private slots:
    // 小键盘
    void slot_Text(QString sNum);
    void slot_Delete();
    void slot_Clear();
    void slot_Confirm();
    void on_saveButton_clicked();
    void slot_onGetStockGoodsInfo(int nCode, QString sMsg, GoodsStockInfo goodsStockInfo);
public slots:
    void slot_onEdited();
    void slot_onMark();//匹配件数与箱数

private:
    void initConnect();
    void resetUI();

signals:
    void sigAddInStockGoods(InStockSelectGoodsInfo goodsInfo);

private:
    Ui::AddInStkDlg *ui;
    InStockSelectGoodsInfo m_goodsInfo;
    InStockCtrl* m_pStockCtrl;
    float m_fBuyPrice=0.0f;
    QString m_sMarkUnit="";
    float m_fMarkNum=0.0f;
    float boxNum=0.0f;
    float countNum=0.0f;
    float price=0.0f;
    float subTotal=0.0f;
    float newRealStockNum=0.0f;
};

#endif // ADDINSTKDLG_H
