#ifndef BCSMANAGEWIDGET_H
#define BCSMANAGEWIDGET_H

#include <QWidget>
#include "barcodescaledata.h"
#include "BCSAddDlg.h"
#include "../Bussiness/BarCodeScalesCtrl.h"

namespace Ui {
class BCSManageWidget;
}

class BCSManageWidget : public QWidget
{
    Q_OBJECT 
public:
    explicit BCSManageWidget(QWidget *parent = 0);
    ~BCSManageWidget();
    void init();
    void setCtrl(BarCodeScalesCtrl* pBarCodeScalesCtrl);
    void getInfoList(QList<BarCodeScaleInfo> &infoList);
    void getLeftInfoList(QList<BCSGroupManageLeftInfo> &leftInfoList);
//    void getLeftInfo(BCSGroupManageLeftInfo &m_leftInfo ,QString sGoodsGroup);

private slots:
    void on_deleteButton_clicked(); // 删除
    void on_forbidButton_clicked(); // 禁用
    void on_startUseButton_clicked(); // 启用
    void on_addButton_clicked(); // 新增
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();

    void slot_clickListItem(BarCodeScaleInfo itemInfo);
//    void slot_updateAloneState(QString ip,QString keyId);

    void slot_onCheckBcsState(QString sKeyId, bool bState);
    void slot_onCheckBcsStateFinish();
    void slot_onGetBarcodeScaleCode(int nCode, QString sMsg, QString sBcsCode);
    void slot_onGetGoodsGroupList(int nCode, QString sMsg, QList<BCSGroupManageLeftInfo> leftInfoList);
    void slot_onGetBarcodeScaleList(int nCode, QString sMsg, QList<BarCodeScaleInfo> scaleInfoList);
    void slot_onAddBarcodeScale(int nCode, QString sMsg);
    void slot_onDeleteScale(int nCode, QString sMsg, QString scaleId);
    void slot_addBarcodeScale(BarCodeScaleInfo bcsInfo);
    void on_updateButton_clicked();
//    void slot_addInfoList(BarCodeScaleInfo scaleInfo);

private:
    void generateUI();
    void checkCurPageButtonState();
    void initButtons();
    void initConnect();
    void updateInfoState(QString sKeyId, bool bState);

private:
    Ui::BCSManageWidget *ui;
    QList<BarCodeScaleInfo> m_infoList;
    QList<BCSGroupManageLeftInfo> m_leftInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    BCSAddDlg* m_pBCSAddDlg;
    bool pingScale(QString ip);
    BarCodeScalesCtrl* m_pCtrl;

};

#endif // BCSMANAGEWIDGET_H
