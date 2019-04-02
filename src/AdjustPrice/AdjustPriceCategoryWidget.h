#ifndef ADJUSTPRICECATEGORYWIDGET_H
#define ADJUSTPRICECATEGORYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "../data/structData.h"

namespace Ui {
class AdjustPriceCategoryWidget;
}

class AdjustPriceCategoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdjustPriceCategoryWidget(QWidget *parent = 0);
    ~AdjustPriceCategoryWidget();
    void setUpDownPageButton(QPushButton* pUpPageButton, QPushButton* pDownPageButton);
    void initData(QList<CategoryInfo*> categoryInfoList);
    void searchGoods(QList<GoodsInfo> &goodsInfoList, QString searchText);
    void searchGood(GoodsInfo &info,int goodsId);

private slots:
    void slot_upPage();
    void slot_downPage();
protected:
    void resizeEvent(QResizeEvent *);

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();

signals:
    void sigClickItem(CategoryInfo categoryInfo);

private:
    Ui::AdjustPriceCategoryWidget *ui;
    QList<CategoryInfo*> m_categoryInfoList;
    int m_nCurPage;
    int m_nTotalPage;
    int m_nOnePageCount;
    QPushButton *m_pUpPageButton;
    QPushButton *m_pDownPageButton;
};

#endif // ADJUSTPRICECATEGORYWIDGET_H
