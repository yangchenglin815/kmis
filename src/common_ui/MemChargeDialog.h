#ifndef MEMCHARGEDIALOG_H
#define MEMCHARGEDIALOG_H

#include <QDialog>
#include <QKeyEvent>
#include "enumData.h"
#include <QTimer>

namespace Ui {
class MemChargeDialog;
}

class MemChargeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MemChargeDialog(QWidget *parent = 0, EPayMethod ePayMethod = PayCash );
    ~MemChargeDialog();

    void keyPressEvent(QKeyEvent *event);

    void setAmtLabelText( QString strText );
    void setContext( QString strChargeAmt, EStatementStatus eChargeStatus );
    void setStatus( const EStatementStatus eChargeStatus );
signals:
    void sig_memChargeInfo( EPayMethod ePayMethod, QString strBarCode, QString strChargeAmt );
    void sig_refreshCharge();
    void sig_closeWnd();
    void sig_barCode();
private slots:
    void slot_BarCodeTimer();
    void slot_closeWnd();
    void slot_barCode();
private:
    void initCtrl();
    void initConnect();
    void initTitle();

    QString enumToString( const EStatementStatus &eChargeStatus );
    void setStatusStyle( const EStatementStatus &eChargeStatus );
    void setTitle( QString strTitle );
    void startTimer();
    void stopTimer();
private:
    Ui::MemChargeDialog *ui;

    EPayMethod m_ePayMethod;//支付方式
    EStatementStatus m_eChargeStatus;//充值状态

    QString m_sBarCode;//支付码（扫码）
    QString m_sOldCode;//
    QString m_sPayOrderNum;//内部支付码
    QString m_sChargeAmt;//充值金额
    QString m_sGiftAmt;//赠送金额

    QTimer *m_pBarCodeTimer;//扫码枪使用定时
    int m_nTime;
    int m_nTimerId;

    QTimer *m_pCloseWndTimer;
};

#endif // MEMCHARGEDIALOG_H
