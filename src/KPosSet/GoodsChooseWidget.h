#ifndef GOODSCHOOSEWIDGET_H
#define GOODSCHOOSEWIDGET_H

#include <QWidget>
#include <QList>
#include "structData.h"

namespace Ui {
class GoodsChooseWidget;
}

class GoodsChooseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GoodsChooseWidget(QWidget *parent = 0);
    ~GoodsChooseWidget();
//    void test();

private slots:
    void slot_chooseCategory(CategoryChooseInfo categoryChooseInfo);
    void slot_upPage();
    void slot_downPage();
    void on_confirmButton_clicked();

private:
    void initConnect();
    void generateUIData();
    void checkCurPageButtonState();

signals:
    void sigSaveGoodsIdList(QList<int> deletedList, QList<int> addedList);

private:
    Ui::GoodsChooseWidget *ui;
    QList<GoodsChooseInfo> m_goodsChooseInfoList;
    int m_nOnePageCount;
    int m_nCurPage; // 当前页
    int m_nTotalPage; // 总页数
    bool m_bRoot;
    QList<int> m_defaultSelectedGoodsIdList;
};

#endif // GOODSCHOOSEWIDGET_H
