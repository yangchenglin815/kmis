#ifndef REFUNDPAYDLG_H
#define REFUNDPAYDLG_H

#include <QDialog>
#include <QKeyEvent>
#include <QTimer>
#include "enumData.h"

namespace Ui {
class RefundPayDlg;
}

class RefundPayDlg : public QDialog
{
    Q_OBJECT

public:
    explicit RefundPayDlg(QWidget *parent = 0, EPayMethod ePayMethod = PayCash, QString strPayOrderNum = "");
    ~RefundPayDlg();
public:
    void setAmtLabelText( QString strAmtLabelText );
    void setTitle( QString strTitle );
    void setContext( const QString &strAmt, const ERefundStatus &eRefundStatus );
    void setStatus( const ERefundStatus &eRefundStatus );
    ERefundStatus getStatus();
    void setPayMethod( const EPayMethod &ePayMethod );
    EPayMethod getPayMethod();
    QString getOrderNum();

    void startQueryStatusTimer();
    void stopQueryStatusTimer();
public slots:
    void slot_GetCreatePayInfo( int nCode, QString strMsg, QString strOrderNumS, QString strAuthCode );
    void slot_RevokePay( int nCode, QString strMsg, QString strOrderNumS, int nRevokeStatus );
    void slot_MemRevokePay(int nCode, QString strMsg, QString strOrderNumS, int nRevokeStatus, QString strMemCardBalance, int nMemCardIntegral);
    void slot_GetPayStatus( int nCode, QString strMsg, QString strOrderNumS, int nTradeState );
signals:
    void sig_closeWnd();
    void sig_createPayInfo( EPayMethod ePayMethod, QString strBarCode, QString strPayAmt );
    void sig_getPayStatus( int nPayMethod, QString strPayOrderNum );
    void sig_payInfo( QString strOrderNumS, ERefundStatus eRefundStatus );
    void sig_payRevoke( QString strOrderNumS );
private:
    void initTitle();
    void initCtrl();
    void initTimer();
    void initConnect();
    void setStatusStyle( const ERefundStatus &eRefundStatus );
    QString enumToString( const ERefundStatus &eRefundStatus );
private slots:
    void slot_payInfo();
    void slot_getPayStatus();
    void slot_closeWnd();
    void slot_closeDlg();
    void slot_sure();
private:
    Ui::RefundPayDlg *ui;
    EPayMethod m_ePayMethod;
    ERefundStatus m_eRefundStatus;
    QString m_sPayAmt;//支付金额

    QString m_sBarCode;//付款码
    QString m_sPayOrderNum;//内部支付码

    QTimer *m_pGetPayStatusTimer;
    int m_nPayStatusTimerId;

    QTimer *m_pCloseWndTimer;
};

#endif // REFUNDPAYDLG_H
