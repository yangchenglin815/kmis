#ifndef BCSGROUPMANAGEWIDGET_H
#define BCSGROUPMANAGEWIDGET_H

#include <QWidget>
#include "../Bussiness/BarCodeScalesCtrl.h"
#include "BCSRelateDlg.h"
#include "BCSAddGoodsGroupDlg.h"

namespace Ui {
class BCSGroupManageWidget;
}

class BCSGroupManageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BCSGroupManageWidget(QWidget *parent = 0);
    ~BCSGroupManageWidget();
    void setCtrl(BarCodeScalesCtrl* pCtrl);
    void init();

private slots:
    void on_relateButton_clicked(); // 关联条码秤
    void on_deleteButton_clicked(); // 删除
    void on_editButton_clicked(); // 编辑
    void on_addButton_clicked(); // 新增
    void slot_clickLeftItem(QList<BCSGroupManageRightInfo> rightInfoList);
    void slot_addGoodsGroup(QString sName);

    void slot_onCreateGoodsGroup(int nCode, QString sMsg, BCSGroupManageLeftInfo bcsGroupManageLeftInfo); // 创建商品组
    void slot_onGetGoodsGroupList(int nCode, QString sMsg, QList<BCSGroupManageLeftInfo> leftInfoList); // 获取商品组列表

private:
    void initConnect();

signals:
    void sigEditBcsGroup(int nGroupId);
//    void sigAddBcsGroup();

private:
    Ui::BCSGroupManageWidget *ui;
    BarCodeScalesCtrl* m_pCtrl;
    BCSRelateDlg* m_pBCSRelateDlg;
    BCSAddGoodsGroupDlg* m_pBCSAddGoodsGroupDlg;
    QList<BarCodeScaleInfo> m_infoScaleList;
};

#endif // BCSGROUPMANAGEWIDGET_H
