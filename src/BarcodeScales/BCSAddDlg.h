#ifndef BCSADDDLG_H
#define BCSADDDLG_H

#include <QDialog>
#include <QLineEdit>
#include "barcodescaledata.h"

namespace Ui {
class BCSAddDlg;
}

class BCSAddDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSAddDlg(QWidget *parent = 0);
    ~BCSAddDlg();
    void setBcsCode(QString sBcsCode);
    void setLeftInfo(QList<BCSGroupManageLeftInfo> m_leftInfoList);

private slots:
    void on_pushFrom_clicked();
    void slot_setText(QString strText);
    void slot_deleteValue();
    void slot_clearZero();
    void slot_Confirm();

private:
    void firstClick();
    bool getCurFocusWnd(QLineEdit *&pEditWnd);
    void initConnect();

signals:
    void sigAddBarcodeScale(BarCodeScaleInfo bcsInfo);

private:
    Ui::BCSAddDlg *ui;
    QList<BCSGroupManageLeftInfo> m_infoList;
    bool m_bFirst;
    QMap<QString, int> m_groupNameIDMap;
};

#endif // BCSADDDLG_H
