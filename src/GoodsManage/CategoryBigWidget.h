#ifndef CATEGORYBIGWIDGET_H
#define CATEGORYBIGWIDGET_H

#include <QWidget>
#include "goodsmanagedata.h"

namespace Ui {
class CategoryBigWidget;
}

class CategoryBigWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CategoryBigWidget(QWidget *parent = 0);
    ~CategoryBigWidget();
    void initData(const QList<sCategoryBigInfo*> &categoryBigInfoList);
    void clickCategoryBigId(int nCategoryId);

private slots:
    void slot_clickCategoryBig(int nCategoryId);

    void on_lastPageButton_clicked();

    void on_nextPageButton_clicked();

private:
    void generateUI();
    void initConnect();
    void checkCurPageButtonState();

signals:
    void sigClickCategoryBig(int categoryBigId);

private:
    Ui::CategoryBigWidget *ui;
    QList<sCategoryBigInfo*> m_categoryBigInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    int m_nSelectedBigCategoryId;
};

#endif // CATEGORYBIGWIDGET_H
