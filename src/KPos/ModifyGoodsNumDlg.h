#ifndef MODIFYGOODSNUMDLG_H
#define MODIFYGOODSNUMDLG_H

#include <QDialog>
#include <QLineEdit>
#include "structData.h"
#include "ebalancedata.h"

namespace Ui {
class ModifyGoodsNumDlg;
}

class ModifyGoodsNumDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyGoodsNumDlg( QWidget *parent = 0 );
    ~ModifyGoodsNumDlg();
public:
    void setGoodsDetailInfo( GoodsDetailInfo &stGoodsDetailsInfo );
    void setSingleMaxNum( int nSingleMaxNum );
signals:
    void sig_closeWnd();
    void sig_modifyGoodsNum( int nSaleDetailPos, QString strGoodsNum );
private:
    void initCtrl();
    void initConnect();
    int findDecimalsNum();
    bool findPoint();
    void firstClick();
    void updateAmountText();
private slots:
    void slot_commit();
    void slot_setText(QString strText);
    void slot_deleteValue();
    void slot_clearZero();
    void slot_stableInfo(EBalanceStandard_Ex balanceStandard_Ex,bool bStable);

private:
    Ui::ModifyGoodsNumDlg *ui;

    GoodsDetailInfo m_stGoodsDetailInfo;
    bool m_bFirst;
    int m_nSingleMaxNum;
    bool m_bStable;
};

#endif // MODIFYGOODSNUMDLG_H
