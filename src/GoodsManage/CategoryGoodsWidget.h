#ifndef CATEGORYGOODSWIDGET_H
#define CATEGORYGOODSWIDGET_H

#include <QWidget>
#include "goodsmanagedata.h"

namespace Ui {
class CategoryGoodsWidget;
}

class CategoryGoodsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CategoryGoodsWidget(QWidget *parent = 0);
    ~CategoryGoodsWidget();
    void initData(const QList<sGoodsInfo*>& sGoodsInfoList);
    void findGoodsPage(int nGoodsId);
signals:
    void sigFastCreateDocument();
private slots:
    void slot_lastPage();
    void slot_nextPage();
    void slot_confirmPage();
private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();
    sGoodsInfo* getFirstSearchOrderGoods();
private:
    Ui::CategoryGoodsWidget *ui;
    QList<sGoodsInfo*> m_GoodsInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // CATEGORYGOODSWIDGET_H
