#ifndef ADDOUTSTKDLG_H
#define ADDOUTSTKDLG_H

#include <QDialog>
#include "stockData.h"
#include "../Bussiness/OutStockCtrl.h"

namespace Ui {
class AddOutStkDlg;
}

class AddOutStkDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddOutStkDlg(QWidget *parent = 0);
    ~AddOutStkDlg();
    void setGoodsInfo(const OutStockSelectGoodsInfo& goodsInfo);
//    void showModifyPage(float fShouldStockNum, float fShouldTotal,float fShouldPrice,const QString& fNum);
    void setOutStockCtrl(OutStockCtrl* pStockCtrl);
private slots:
    // 小键盘
    void slot_Text(QString sNum);
    void slot_Delete();
    void slot_Clear();
    void slot_Confirm();
    void on_saveButton_clicked();
    void slot_onGetStockGoodsInfo(QString sMsg, float fBuyPrice);
public slots:
    void slot_onEdited();
    void slot_onMark();//匹配件数与箱数

private:
    void initConnect();
    void resetUI();
signals:
    void sigAddOutStockGoods(OutStockSelectGoodsInfo goodsInfo);

private:
    Ui::AddOutStkDlg *ui;
    OutStockSelectGoodsInfo m_goodsInfo;
    OutStockCtrl* m_pStockCtrl;
    QString m_sMarkUnit;
    float m_fBuyPrice;
    float m_fMarkNum=0.0f;
    float boxNum=0.0f;
    float countNum=0.0f;
    float price=0.0f;
    float subTotal=0.0f;
    float newRealStockNum=0.0f;
};

#endif // ADDOutStkDLG_H
