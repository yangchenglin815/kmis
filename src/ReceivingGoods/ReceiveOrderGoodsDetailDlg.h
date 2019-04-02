#ifndef RECEIVEORDERGOODSDETAILDLG_H
#define RECEIVEORDERGOODSDETAILDLG_H

#include <QDialog>
#include <QPushButton>
#include "../data/recievinggoodsdata.h"
#include "../data/ebalancedata.h"
#include "../Bussiness/DeliveryOrderCtrl.h"
#include "DlgCommon.h"

namespace Ui {
class ReceiveOrderGoodsDetailDlg;
}

class ReceiveOrderGoodsDetailDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ReceiveOrderGoodsDetailDlg(QWidget *parent = 0);
    ~ReceiveOrderGoodsDetailDlg();
    void initCtrl(DeliveryOrderCtrl* pDeliveryOrderCtrl);
    void initData(ReceiveOrderGoodsInfo* pReceiveOrderGoodsInfo, const ReceiveGoodsDetail_s& receiveGoodsDetail);

private slots:
    void on_stableButton_clicked(); //   标品或非标品 -- 计件(确定)
    void on_unStableButton_clicked(); // 非标品 -- 计件(不确定)
    void on_disperseButton_clicked(); // 非标品 -- 散斤
    void on_saveButton_clicked();
    void on_standardWeightLineEdit_textChanged(const QString &text);
    void on_receiveNumLineEdit_textChanged(const QString &text);
    void slot_closeDlgCommon();
    void slot_closeWnd();
    void slot_stableInfo(EBalanceStandard_Ex balanceStandard_Ex, bool bStable);

private:
    void setButtonQss(QPushButton* pPushButton);
    void init();
    void initConnect();

signals:
    void sigSaveReceiveGoods(ReceiveGoodsDetail_s* pReceiveGoodsDetail, ReceiveOrderGoodsInfo* pReceiveOrderGoodsInfo);
    void sigCloseWnd();

private:
    Ui::ReceiveOrderGoodsDetailDlg *ui;
    QPushButton* m_pSelectedButton;
    ReceiveOrderGoodsInfo* m_pReceiveOrderGoodsInfo;
    DlgCommon* m_pDlgCommon;
    bool m_bWeighStable; // 称重是否稳定
    ReceiveGoodsDetail_s m_ReceiveGoodsDetail;
    ReceiveGoodsDetailChanged m_receiveGoodsDetailChanged;
    DeliveryOrderCtrl* m_pDeliveryOrderCtrl;
};

#endif // RECEIVEORDERGOODSDETAILDLG_H
