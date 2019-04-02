#ifndef GOODSSELECTWIDGET_H
#define GOODSSELECTWIDGET_H

#include <QWidget>
#include "../data/stockdata.h"

namespace Ui {
class GoodsSelectWidget;
}

class GoodsSelectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GoodsSelectWidget(QWidget *parent = 0);
    ~GoodsSelectWidget();
private:
    Ui::GoodsSelectWidget *ui;
    QList<InStockSelectGoodsInfo> m_goodsInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    QString curTotal;
    float m_Total;//总价
    QMap<int, InStockSelectGoodsInfo> m_initedGoodsInfoMap; // 原始的
    QList<int> m_removedGoodsIdList; // 原始移除的
    QList<int> m_updatedGoodsIdList; // 原始更新的
    QMap<int, InStockSelectGoodsInfo> m_addedGoodsInfoMap; // 新增的

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();

public:
    void updateUI(bool bToEndPage = false);
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();
    void initData(const QList<InStockSelectGoodsInfo>& goodsInfoList);
    void appendData(const InStockSelectGoodsInfo& goodsInfo);
    void removeSelectItem();
    int getGoodsPosition(int nId);
    bool getSelectGoodsInfo(int nId, InStockSelectGoodsInfo& goodsInfo);
    int getGoodsListLength();
    bool getSeletedItem(InStockSelectGoodsInfo& selectGoodsInfo);
    void getGoodsInfoList(QList<InStockSelectGoodsInfo>& goodsInfoList);
    void clearData();
    void getAddedGoods(QList<InStockSelectGoodsInfo>& addedGoodsList);
    void getRemovedGoods(QList<InStockSelectGoodsInfo>& removedGoodsList);
    void getUpdatedGoods(QList<InStockSelectGoodsInfo>& updatedGoodsList);

signals:
    //    void sigClickItem(InStockSelectGoodsInfo selectGoodsInfo);
    void sig_Focus();

};

#endif // GOODSSELECTWIDGET_H
