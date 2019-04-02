#ifndef SINGLEDISCOUNTDLG_H
#define SINGLEDISCOUNTDLG_H

#include <QDialog>
#include "structData.h"
#include <QLineEdit>
#include "enumData.h"

namespace Ui {
class SingleDiscountDlg;
}

class SingleDiscountDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SingleDiscountDlg(QWidget *parent = 0);
    ~SingleDiscountDlg();

    void initData();
    void setSaleDetails( SaleDetails stSaleDetails );
    void setMember( bool bMember );
signals:
    void sig_commit( SaleDetails stSaleDetails );
private:
    void initCtrl();
    void initConnect();

    void firstClick();
    bool getCurFocusWnd(QLineEdit *&pEditWnd);
    int findDecimalsNum();
    bool findPoint();
    void updateDiscount();//更新折扣显示
    void updateSwapAmt();//更新成交金额
    void updateDiscountAmt();//更新优惠金额
    void disChangeToAmt();//折扣改变更新显示金额
    void amtChangeToDis();//金额改变更新显示折扣
private slots:
    void slot_setText(QString strText);
    void slot_deleteValue();
    void slot_clearZero();
    void slot_enter();
    void slot_twenty();
    void slot_fifty();
    void slot_hundred();
    void slot_twoHundred();
    void slot_rediscountChanged( QString strText );
    void slot_amtChanged( QString strText );
private:
    Ui::SingleDiscountDlg *ui;

    SaleDetails m_stSaleDetails;
    bool m_bFirst;
    bool m_bMember;//是否会员登录
};

#endif // SINGLEDISCOUNTDLG_H
