#ifndef BCSGROUPMANAGERIGHTWIDGET_H
#define BCSGROUPMANAGERIGHTWIDGET_H

#include <QWidget>
#include "barcodescaledata.h"

namespace Ui {
class BCSGroupManageRightWidget;
}

class BCSGroupManageRightWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BCSGroupManageRightWidget(QWidget *parent = 0);
    ~BCSGroupManageRightWidget();
//    void test();
    void initData(const QList<BCSGroupManageRightInfo>& infoList);

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void slot_clickListItem(BCSGroupManageRightInfo itemInfo);

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();

private:
    Ui::BCSGroupManageRightWidget *ui;
    QList<BCSGroupManageRightInfo> m_infoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // BCSGROUPMANAGERIGHTWIDGET_H
