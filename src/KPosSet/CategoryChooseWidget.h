#ifndef CATEGORYCHOOSEWIDGET_H
#define CATEGORYCHOOSEWIDGET_H

#include <QWidget>
#include "structData.h"

namespace Ui {
class CategoryChooseWidget;
}

class CategoryChooseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CategoryChooseWidget(QWidget *parent = 0);
    ~CategoryChooseWidget();
//    void test();
    void initData(const QList<CategoryInfo *> &categoryInfoList, const CategoryInfo &rootCategoryInfo);

private slots:
    void slot_chooseCategory(CategoryChooseInfo categoryChooseInfo);
    void slot_upPage();
    void slot_downPage();

private:
    void initConnect();
    void generateUIData();
    void checkCurPageButtonState();
    QList<int> getSelectedGoodsId(CategoryInfo categoryInfo, CategoryInfo rootCategoryInfo);

signals:
    void sigChooseCategory(CategoryChooseInfo categoryChooseInfo);

private:
    Ui::CategoryChooseWidget *ui;
    QString m_sCategoryName;
    QList<CategoryChooseInfo> m_categoryChooseInfoList;
    CategoryChooseInfo m_rootCategoryChooseInfo;
    int m_nOnePageCount;
    int m_nCurPage; // 当前页
    int m_nTotalPage; // 总页数
};

#endif // CATEGORYCHOOSEWIDGET_H
