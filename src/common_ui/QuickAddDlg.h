#ifndef QUICKADDDLG_H
#define QUICKADDDLG_H

#include <QDialog>
#include "structData.h"
#include "../Bussiness/SaleCtrl.h"

namespace Ui {
class QuickAddDlg;
}

class QuickAddDlg : public QDialog
{
    Q_OBJECT

public:
    explicit QuickAddDlg(QWidget *parent = 0);
    ~QuickAddDlg();
    void setCtrl(SaleCtrl* pSaleCtrl);
    void getCategoryNodeList();

protected:
    void showEvent(QShowEvent *);

private slots:
    void on_submitBtn_clicked();
    void on_closeButton_clicked();
    void on_bKindcBox_currentIndexChanged(int index);
    void on_mKindcBox_currentIndexChanged(int index);
    void on_sKindcBox_currentIndexChanged(int index);
    void on_weighTypeCBox_currentIndexChanged(int index);

    void slot_onGetQuickGoodsInfo(int nCode, QString sMsg, QString plu, QString goodCode, QString unit, QString sBigCategoryCode);
    void slot_onCreateQuickGoods(int nCode , QString sMsg);
    void on_basicUnitCBox_currentTextChanged(const QString &arg1);

    void slot_Text(QString sText);
    void slot_Delete();
    void slot_Clear();
    void slot_Confirm();

private:
    void initConnect();
    void initUI();
    void initComBox();
    void initBigComboBox();
    void initMiddleComboBox();
    void initSamllComboBox();
    void initUnitsBox();
    bool checkSubmit();

private:
    Ui::QuickAddDlg *ui;
    ProductInfo m_info;
    SaleCtrl* m_pSaleCtrl;
    QMap<QString,QString> unitMap;
    QList<CategoryInfoNode> m_categoryNodeList;
    CategoryInfoNode* m_pBigNode;
    CategoryInfoNode* m_pMiddleNode;
    CategoryInfoNode* m_pSmallNode;
    QString m_goodsCode;
    QMap<QString, QString> m_bigCategoryGoodsCodeMap; // 大类和新建商品code的Map
    QString m_units; // 商品规格单位
    QString m_sPlu;
};


#endif // QUICKADDDLG_H
