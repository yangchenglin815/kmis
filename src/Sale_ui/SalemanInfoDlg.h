#ifndef SALEMANINFODLG_H
#define SALEMANINFODLG_H

#include <QDialog>
#include "httpstructdata.h"

namespace Ui {
class SalemanInfoDlg;
}

class SalemanInfoDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SalemanInfoDlg(QWidget *parent = 0);
    ~SalemanInfoDlg();

    void setSalemanInfo( QList<SalemanInfo> &listSalemanInfo );
    SalemanInfo getCurSalemanInfo();
private slots:
    void slot_upPage();
    void slot_downPage();
    void slot_ItemClicked( int nSalemanUserId );
private:
    void initCtrl();
    void initConnect();
    void clearText();
    void setCurPage( int nCurPage, int nTotalPage );
    void generateSalemanList();
    void checkCurPageButtonState();
private:
    Ui::SalemanInfoDlg *ui;

    QList<SalemanInfo> m_listSalemanInfo;//当前门店所有用户信息
    SalemanInfo m_stCurSalemanInfo;
    int m_nCurPage;
    int m_nTotalPage;
    int m_nOnePageCount;
};

#endif // SALEMANINFODLG_H
