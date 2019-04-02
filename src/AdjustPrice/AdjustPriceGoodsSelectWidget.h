#ifndef ADJUSTPRICEGOODSSELECTWIDGET_H
#define ADJUSTPRICEGOODSSELECTWIDGET_H

#include <QWidget>
#include "../data/adjustpricedata.h"

namespace Ui {
class AdjustPriceGoodsSelectWidget;
}

class AdjustPriceGoodsSelectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdjustPriceGoodsSelectWidget(QWidget *parent = 0);
    ~AdjustPriceGoodsSelectWidget();
//    void test();
    void initData(const QList<AdjustPriceSelectGoodsInfo>& goodsInfoList);
    void appendData(const AdjustPriceSelectGoodsInfo& goodsInfo);
    void removeSelectItem();
    int getGoodsPosition(int nId);
    int getGoodsListLength();
    bool getSeletedItem(AdjustPriceSelectGoodsInfo& selectGoodsInfo);
    void getGoodsInfoList(QList<AdjustPriceSelectGoodsInfo>& goodsInfoList);
    void clearData();

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();

private:
    void updateUI(bool bToEndPage = false);
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();

signals:
    void sigClickItem(AdjustPriceSelectGoodsInfo selectGoodsInfo);

private:
    Ui::AdjustPriceGoodsSelectWidget *ui;
    QList<AdjustPriceSelectGoodsInfo> m_goodsInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // ADJUSTPRICEGOODSSELECTWIDGET_H
