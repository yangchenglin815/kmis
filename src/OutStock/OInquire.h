#ifndef OINQUIRE_H
#define OINQUIRE_H

#include <QWidget>
#include "stockdata.h"

namespace Ui {
class OInquire;
}

class OInquire : public QWidget
{
    Q_OBJECT

public:
    explicit OInquire(QWidget *parent = 0);
    ~OInquire();
    void initData(QString sTotal,const QList<OutStockOrderSearchInfo>& orderInfoList);

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void slot_searchChanged(QString searchText);

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();
    void initSearchData(const QList<OutStockOrderSearchInfo>& orderInfoList);

private:
    Ui::OInquire *ui;
    QList<OutStockOrderSearchInfo> m_orderInfoList;
    QList<OutStockOrderSearchInfo> m_backUpOrderInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // OInquire_H
