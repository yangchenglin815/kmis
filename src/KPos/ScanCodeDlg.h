#ifndef SCANCODEDLG_H
#define SCANCODEDLG_H

#include <QDialog>
#include <QKeyEvent>
#include <QTimer>
#include "enumData.h"

namespace Ui {
class ScanCodeDlg;
}

class ScanCodeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ScanCodeDlg(QWidget *parent = 0, QString strTitle="", EPayMethod ePayMethod = PayNull );
    ~ScanCodeDlg();

    void keyPressEvent( QKeyEvent *event );

    void setTitle( QString strTitle );
    QString getBarCode();
private:
    void initCtrl();
    void initConnect();

    void startTimer();
    void stopTimer();
private slots:
    void slot_barCodeTimer();
private:
    Ui::ScanCodeDlg *ui;

    EPayMethod m_ePayMethod;
    QString m_sBarCode;//扫码

    QTimer *m_pBarCodeTimer;//扫码枪使用定时
    int m_nTime;
    int m_nTimerId;
};

#endif // SCANCODEDLG_H
