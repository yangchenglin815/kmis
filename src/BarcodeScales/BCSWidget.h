#ifndef BCSWIDGET_H
#define BCSWIDGET_H

#include <QWidget>
#include "BCSSendDownDlg.h"
#include "../Bussiness/BarCodeScalesCtrl.h"

namespace Ui {
class BCSWidget;
}

class BCSWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BCSWidget(QWidget *parent = 0);
    ~BCSWidget();
    void setCtrl(BarCodeScalesCtrl* pCtrl);
    void init();

private slots:
    void on_bcsManageButton_clicked(); // 条码秤管理
    void on_bcsGoodsGroupButton_clicked(); // 商品组管理
    void on_bcsSendDownButton_clicked(); // 下发条码秤

private:
    void initConnect();
    void setButtonQss(QPushButton* pButton);

signals:
    void sigReturnClicked();
    void sigEditBcsGroup(int nGroupId);
//    void sigAddBcsGroup();

private:
    Ui::BCSWidget *ui;
    QPushButton* m_pSelectedButton;
    BCSSendDownDlg* m_pBCSSendDownDlg;
    BarCodeScalesCtrl* m_pCtrl;
    QList<BarCodeScaleInfo> m_infoScaleList;
};

#endif // BCSWIDGET_H
