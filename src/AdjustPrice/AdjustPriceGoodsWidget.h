#ifndef ADJUSTPRICEGOODSWIDGET_H
#define ADJUSTPRICEGOODSWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "../data/structData.h"

namespace Ui {
class AdjustPriceGoodsWidget;
}

class AdjustPriceGoodsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdjustPriceGoodsWidget(QWidget *parent = 0);
    ~AdjustPriceGoodsWidget();
    void setUpDownPageButton(QPushButton* pUpPageButton, QPushButton* pDownPageButton);
    void initData(QList<GoodsInfo> goodsInfoList);

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
    void sigClickItem(GoodsInfo goodsInfo);

private:
    Ui::AdjustPriceGoodsWidget *ui;
    QList<GoodsInfo> m_goodsInfoList;
    int m_nCurPage;
    int m_nTotalPage;
    int m_nOnePageCount;
    QPushButton *m_pUpPageButton;
    QPushButton *m_pDownPageButton;
};

#endif // ADJUSTPRICEGOODSWIDGET_H
