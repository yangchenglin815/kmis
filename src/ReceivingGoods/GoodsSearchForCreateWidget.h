#ifndef GOODSSEARCHFORCREATEWIDGET_H
#define GOODSSEARCHFORCREATEWIDGET_H

#include <QWidget>
#include "../data/recievinggoodsdata.h"

namespace Ui {
class GoodsSearchForCreateWidget;
}

class GoodsSearchForCreateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GoodsSearchForCreateWidget(QWidget *parent = 0);
    ~GoodsSearchForCreateWidget();
    void initData(const QList<GoodsForCreateInfo*>& goodsForCreateInfoList);
    void appendOneInfo(GoodsForCreateInfo* pGoodsForCreateInfo);

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void slot_clickSearchItem(int nGoodsId);

private:
    void generateUI();
    void checkCurPageButtonState();
    void removeOneInfo(int nGoodsId);
    void initConnect();

signals:
    void sigSearchChanged(QString);
    void sigClickSearchItem(int nGoodsId);

private:
    Ui::GoodsSearchForCreateWidget *ui;
    QList<GoodsForCreateInfo*> m_goodsForCreateInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // GOODSSEARCHFORCREATEWIDGET_H
