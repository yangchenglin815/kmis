#ifndef REPORTLOSSGOODSWIDGET_H
#define REPORTLOSSGOODSWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "../data/structData.h"


namespace Ui {
class ReportLossGoodsWidget;
}

class ReportLossGoodsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReportLossGoodsWidget(QWidget *parent = 0);
    ~ReportLossGoodsWidget();
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
    Ui::ReportLossGoodsWidget *ui;
    QList<GoodsInfo> m_goodsInfoList;
    int m_nCurPage;
    int m_nTotalPage;
    int m_nOnePageCount;
    QPushButton *m_pUpPageButton;
    QPushButton *m_pDownPageButton;
};

#endif // REPORTLOSSGOODSWIDGET_H
