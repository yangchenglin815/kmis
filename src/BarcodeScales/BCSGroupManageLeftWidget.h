#ifndef BCSGROUPMANAGELEFTWIDGET_H
#define BCSGROUPMANAGELEFTWIDGET_H

#include <QWidget>
#include "barcodescaledata.h"

namespace Ui {
class BCSGroupManageLeftWidget;
}

class BCSGroupManageLeftWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BCSGroupManageLeftWidget(QWidget *parent = 0);
    ~BCSGroupManageLeftWidget();
//    void test();
    void appendData(const BCSGroupManageLeftInfo& bcsGroupManageLeftInfo);
    int getSelectGroupId(); // 获取商品组id
    void initData(const QList<BCSGroupManageLeftInfo>& leftInfoList);

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();

    void slot_clickListItem();

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();
    void getRightInfoList(int nGroupId, QList<BCSGroupManageRightInfo> &rightInfoList);

signals:
    void sigClickItem(QList<BCSGroupManageRightInfo> rightInfoList);

private:
    Ui::BCSGroupManageLeftWidget *ui;
    QList<BCSGroupManageLeftInfo> m_infoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // BCSGROUPMANAGELEFTWIDGET_H
