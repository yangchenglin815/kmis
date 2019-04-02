#ifndef REPORTLOSSCATEGORYWIDGET_H
#define REPORTLOSSCATEGORYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "../data/structData.h"

namespace Ui {
class ReportLossCategoryWidget;
}

class ReportLossCategoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReportLossCategoryWidget(QWidget *parent = 0);
    ~ReportLossCategoryWidget();
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
    Ui::ReportLossCategoryWidget *ui;
    QList<CategoryInfo*> m_categoryInfoList;
    int m_nCurPage;
    int m_nTotalPage;
    int m_nOnePageCount;
    QPushButton *m_pUpPageButton;
    QPushButton *m_pDownPageButton;
};

#endif // REPORTLOSSCATEGORYWIDGET_H
