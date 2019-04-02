#ifndef STOCKGOODSSELECTWIDGET_H
#define STOCKGOODSSELECTWIDGET_H

#include <QWidget>
#include "../data/stockdata.h"

namespace Ui {
class StockGoodsSelectWidget;
}

class StockGoodsSelectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StockGoodsSelectWidget(QWidget *parent = 0);
    ~StockGoodsSelectWidget();
//    void test();
    void initData(const QList<StockSelectGoodsInfo>& goodsInfoList);
    void appendData(const StockSelectGoodsInfo& goodsInfo);
    void removeSelectItem();
    int getGoodsPosition(int nId);
    bool getSelectGoodsInfo(int nId, StockSelectGoodsInfo& goodsInfo);
    int getGoodsListLength();
    bool getSeletedItem(StockSelectGoodsInfo& selectGoodsInfo);
    void getGoodsInfoList(QList<StockSelectGoodsInfo>& goodsInfoList);
    void clearData();
    void getAddedGoods(QList<StockSelectGoodsInfo>& addedGoodsList);
    void getRemovedGoods(QList<StockSelectGoodsInfo>& removedGoodsList);
    void getUpdatedGoods(QList<StockSelectGoodsInfo>& updatedGoodsList);

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();

private:
    void updateUI(bool bToEndPage = false);
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();

signals:
    void sigClickItem(StockSelectGoodsInfo selectGoodsInfo);

private:
    Ui::StockGoodsSelectWidget *ui;
    QList<StockSelectGoodsInfo> m_goodsInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    QMap<int, StockSelectGoodsInfo> m_initedGoodsInfoMap; // 原始的
    QList<int> m_removedGoodsIdList; // 原始移除的
    QList<int> m_updatedGoodsIdList; // 原始更新的
    QMap<int, StockSelectGoodsInfo> m_addedGoodsInfoMap; // 新增的
};

#endif // STOCKGOODSSELECTWIDGET_H
