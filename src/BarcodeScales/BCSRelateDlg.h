#ifndef BCSRELATEDLG_H
#define BCSRELATEDLG_H

#include <QDialog>
#include "barcodescaledata.h"

namespace Ui {
class BCSRelateDlg;
}

class BCSRelateDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSRelateDlg(QWidget *parent = 0);
    ~BCSRelateDlg();
    void test();
    void setInfoList(QList<BarCodeScaleInfo> infoList);

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void on_confirmButton_clicked();
    void slot_selectBox(bool bSelectAll);

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();

private:
    Ui::BCSRelateDlg *ui;
    QList<BarCodeScaleInfo> m_infoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // BCSRELATEDLG_H
