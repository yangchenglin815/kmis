#ifndef BCSSENDDOWNDLG_H
#define BCSSENDDOWNDLG_H

#include <QDialog>
#include "barcodescaledata.h"
#include "../Bussiness/BarCodeScalesCtrl.h"

namespace Ui {
class BCSSendDownDlg;
}

class BCSSendDownDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSSendDownDlg(QWidget *parent = 0);
    ~BCSSendDownDlg();
    void test();
    void setCtrl(BarCodeScalesCtrl* pCtrl);
    void setInfoList(QList<BarCodeScaleInfo> scaleInfo);
    void setLeftInfoList(QList<BCSGroupManageLeftInfo> leftInfoList);

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void on_confirmButton_clicked();
    void slot_onSendDownBcsState(QString sKey, bool bSuccess);
    void slot_onSendDownBcsFinish();

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();
    void updateSendDownData(QString sKey, bool bSuccess);

private:
    Ui::BCSSendDownDlg *ui;
    QList<BarCodeScaleInfo> m_infoList;
    QList<BCSGroupManageLeftInfo> m_leftInfoList;
    QList<QString> m_SuccessScaleId;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    BarCodeScalesCtrl* m_pCtrl;
};

#endif // BCSSENDDOWNDLG_H
