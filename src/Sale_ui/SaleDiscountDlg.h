#ifndef SALEDISCOUNTDLG_H
#define SALEDISCOUNTDLG_H

#include <QDialog>
#include "structData.h"
#include <QLineEdit>
#include "enumData.h"

namespace Ui {
class SaleDiscountDlg;
}

class SaleDiscountDlg : public QDialog
{
    Q_OBJECT
public:
    explicit SaleDiscountDlg(QWidget *parent = 0);
    ~SaleDiscountDlg();

    void initData();
    void setSaleDetails( const QList<SaleDetails> &listSaleDetails );
    void setMember( bool bMember );
    void setSaleHeadDis( bool bSaleHeadDis );
signals:
    void sig_commit( QList<SaleDetails> m_listSaleDetails, bool bSaleHeadDis );
private:
    void initCtrl();
    void initConnect();

    void firstClick();
    bool getCurFocusWnd(QLineEdit *&pEditWnd);
    int findDecimalsNum();
    bool findPoint();
    void updateOrgSum();//更新商品原总价
    void updateDiscount();//更新折扣
    void updateNowDiscount();//更新现折扣显示

    void updateSwapAmt();//更新单品成交金额
    void updateDiscountAmt();//更新单品优惠金额
    void updateTotalSwapAmt();//更新所有商品成交金额
    void updateTotalDiscountAmt();//更新所有商品优惠金额
private slots:
    void slot_setText(QString strText);
    void slot_deleteValue();
    void slot_clearZero();
    void slot_enter();
    void slot_rediscountChanged(QString strText);
private:
    Ui::SaleDiscountDlg *ui;

    QList<SaleDetails> m_listSaleDetails;
    bool m_bFirst;
    bool m_bMember;//是否会员登录
    bool m_bSaleHeadDis;//整单折扣
};

#endif // SALEDISCOUNTDLG_H
