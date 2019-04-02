#ifndef CHECKORDERGOODSWIDGET_H
#define CHECKORDERGOODSWIDGET_H

#include <QWidget>
#include "../data/ordergoodsdata.h"

namespace Ui {
class CheckOrderGoodsWidget;
}

class CheckOrderGoodsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CheckOrderGoodsWidget(QWidget *parent = 0);
    ~CheckOrderGoodsWidget();
    void initData(const QList<OrderCardDetailInfo_s> &orderGoodsInfoList, bool bUploadFinish);

private slots:
    void slot_downSortByPrice(bool bDownSort);
    void slot_downSortByNumber(bool bDownSort);
    void slot_clickPriceText();
    void slot_clickNumberText();
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void on_confirmButton_clicked();
    void slot_orderNumberAdded(int nId, int bAddedOrderNum, float fUnitValue, float fPrice);

private:
    void generateUI();
    void checkCurPageButtonState();
    void init();
    void initConnect();

signals:
    void sigOrderNumberChanged(QMap<int, int> changedMap);

private:
    Ui::CheckOrderGoodsWidget *ui;
    QList<CheckOrderGoodsInfo> m_checkOrderGoodsInfoList;
    QMap<int, int> m_changedOrderMap;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    int m_nOrderGoodsSumNumber;
    double m_rOrderGoodsSumPrice;
    bool m_bSelectSortByPrice;
    bool m_bDownSortByPrice;
    bool m_bDownSortByNumber;
};

#endif // CHECKORDERGOODSWIDGET_H
