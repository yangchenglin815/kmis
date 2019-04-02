#ifndef OGOODSSELECTWIDGET_H
#define OGOODSSELECTWIDGET_H

#include <QWidget>
#include "../data/stockdata.h"

namespace Ui {
class OGoodsSelectWidget;
}

class OGoodsSelectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OGoodsSelectWidget(QWidget *parent = 0);
    ~OGoodsSelectWidget();
private:
    Ui::OGoodsSelectWidget *ui;
    QList<OutStockSelectGoodsInfo> m_goodsInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    QString curTotal;
    float m_Total;//总价
    QMap<int, OutStockSelectGoodsInfo> m_initedGoodsInfoMap; // 原始的
    QList<int> m_removedGoodsIdList; // 原始移除的
    QList<int> m_updatedGoodsIdList; // 原始更新的
    QMap<int, OutStockSelectGoodsInfo> m_addedGoodsInfoMap; // 新增的

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();

public:
    void updateUI(bool bToEndPage = false);
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();
    void initData(const QList<OutStockSelectGoodsInfo>& goodsInfoList);
    void appendData(const OutStockSelectGoodsInfo& goodsInfo);
    void removeSelectItem();
    int getGoodsPosition(int nId);
    bool getSelectGoodsInfo(int nId, OutStockSelectGoodsInfo& goodsInfo);
    int getGoodsListLength();
    bool getSeletedItem(OutStockSelectGoodsInfo& selectGoodsInfo);
    void getGoodsInfoList(QList<OutStockSelectGoodsInfo>& goodsInfoList);
    void clearData();
    void getAddedGoods(QList<OutStockSelectGoodsInfo>& addedGoodsList);
    void getRemovedGoods(QList<OutStockSelectGoodsInfo>& removedGoodsList);
    void getUpdatedGoods(QList<OutStockSelectGoodsInfo>& updatedGoodsList);

signals:
    //    void sigClickItem(OutStockSelectGoodsInfo selectGoodsInfo);
    void sig_Focus();

};

#endif // OGoodsSelectWidget_H
