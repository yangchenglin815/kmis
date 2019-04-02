#ifndef BCSGOODSWIDGET_H
#define BCSGOODSWIDGET_H

#include <QWidget>
#include "barcodescaledata.h"

namespace Ui {
class BCSGoodsWidget;
}

class BCSGoodsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BCSGoodsWidget(QWidget *parent = 0);
    ~BCSGoodsWidget();
//    void test();
    void initData(const QList<BCSGoodsInfo>& itemInfoList);

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void on_saveButton_clicked();
    void slot_selectCurPageAllBox(bool bSelectAll);
    void slot_clickItem();

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();

signals:
    void sigUpdateSelectCount(QList<QString> keyIdList);
    void sigSaveGroupGoods(QList<QString> keyIdList); // 保存要货卡商品
//    void sigSearchOrderCard(int nOrderId); // 查看要货卡
//    void sigEditOrderCard(QList<int> orderIdList); // 编辑要货卡
//    void sigCheckManyOrderCategoryDetailInfo(QList<int> orderCardIdList);
//    void sigUploadOrderCard(QList<int> orderCardIdList); // 上传要货卡
//    void sigRemoveOrderCard(QList<int> orderCardIdList); // 删除要货卡
//    void sigAddCheckOrder(); // 新增要货卡

private:
    Ui::BCSGoodsWidget *ui;
    QList<BCSGoodsInfo> m_InfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // BCSGOODSWIDGET_H
