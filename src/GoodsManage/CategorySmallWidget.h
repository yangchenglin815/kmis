#ifndef CATEGORYSMALLWIDGET_H
#define CATEGORYSMALLWIDGET_H

#include <QWidget>
#include "../data/constData.h"
#include "goodsmanagedata.h"

namespace Ui {
class CategorySmallWidget;
}

class CategorySmallWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CategorySmallWidget(QWidget *parent = 0);
    ~CategorySmallWidget();
    void initData(const QList<sCategorySmallInfo*>& categorySmallInfoList, int nDefaultSelectedId = c_nNegativeNumber);

private slots:
    void slot_clickCategorySmall(int categorySmallId);
    void slot_lastPage();
    void slot_nextPage();

private:
    void generateUI();
    void initConnect();
    int countRootSelectNumber();
    void checkCurPageButtonState();

signals:
    void sigClickCategorySmall(int categorySmallId);


private:
    Ui::CategorySmallWidget *ui;
    QList<sCategorySmallInfo*> m_categorySmallInfoList;
    sCategorySmallInfo m_rootCategorySmallInfo;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    QList<int> m_selectedCategorySmallIdList;
    int m_nCurCategorySmallId;
};

#endif // CATEGORYSMALLWIDGET_H
