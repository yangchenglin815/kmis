#ifndef ALIPAYRECHARGEDLG_H
#define ALIPAYRECHARGEDLG_H

#include <QDialog>
#include <QKeyEvent>
#include <QTimer>
#include "enumData.h"
#include "DlgCommon.h"

namespace Ui {
class AlipayRechargeDlg;
}

class AlipayRechargeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AlipayRechargeDlg( QWidget *parent = 0, EPayMethod ePayMethod = PayCash, bool bRefund = false, QString strPayOrderNum = "" );
    ~AlipayRechargeDlg();
public:
    void keyPressEvent( QKeyEvent *event );
    void setAmtLabelText( QString strAmtLabelText );
    void setTitle( QString strTitle );
    void setContext( const QString &strAmt, const EStatementStatus &eStatementStatus );
    void setStatus( const EStatementStatus &eStatementStatus );
//    void setRefresh( bool Status);
    EStatementStatus getStatus();
//    void setPayMethod( const EPayMethod &ePayMethod );
    EPayMethod getPayMethod();
    bool getRefund();
    QString getOrderNum();

    void startQueryStatusTimer(bool bStartNow = false);
    void stopQueryStatusTimer();
    void stopAllTimer();
    void setCurPayMethod(EPayMethod ePayMethod);

public slots:
    void slot_GetCreatePayInfo( int nCode, QString strMsg, QString strOrderNumS, QString strAuthCode , EPayMethod ePayMethod);
    void slot_GetPayStatus( int nCode, QString strMsg, QString strOrderNumS, int nTradeState );
signals:
    void sig_closeWnd();
    void sig_barCode();
    void sig_createPayInfo( EPayMethod ePayMethod, QString strBarCode, QString strPayAmt );
    void sig_getPayStatus( int nPayMethod, QString strPayOrderNum );
    void sig_payInfo( QString strOrderNumS, EStatementStatus eStatementStatus, QString sBarCode);
    void sig_payRevoke( QString strOrderNumS );
private:
    void initTitle();
    void initCtrl();
    void initTimer();
    void initConnect();
    void setStatusStyle( const EStatementStatus &eStatementStatus );
    QString enumToString( const EStatementStatus &eStatementStatus );

    void startTimer();
    void stopTimer();
private slots:
    void slot_payInfo();
    void slot_BarCodeTimer();
    void slot_getPayStatus();
    void slot_closeWnd();
    void slot_cancleDlg();
    void slot_closeDlg();
    void slot_sure();
    void slot_barCode();
private:
    Ui::AlipayRechargeDlg *ui;

    EPayMethod m_ePayMethod;
    EStatementStatus m_eStatementStatus;
    QString m_sPayAmt;//支付金额

    QString m_sBarCode;//付款码
    QString m_sOldCode;//老的付款码
    QString m_sPayOrderNum;//内部支付码

    QTimer *m_pBarCodeTimer;//扫码枪使用定时
    int m_nTime;
    int m_nTimerId;

    QTimer *m_pGetPayStatusTimer;
    int m_nPayStatusTimerId;

    QTimer *m_pCloseWndTimer;

    bool m_bRefund;
    DlgCommon *m_pDlg;
    int m_nQueryCount;
};

#endif // ALIPAYRECHARGEDLG_H
