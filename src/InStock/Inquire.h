#ifndef INQUIRE_H
#define INQUIRE_H

#include <QWidget>
#include "stockdata.h"

namespace Ui {
class Inquire;
}

class Inquire : public QWidget
{
    Q_OBJECT

public:
    explicit Inquire(QWidget *parent = 0);
    ~Inquire();
    void initData(QString sTotal,const QList<InStockOrderSearchInfo>& orderInfoList);

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void slot_searchChanged(QString searchText);

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();
    void initSearchData(const QList<InStockOrderSearchInfo>& orderInfoList);

private:
    Ui::Inquire *ui;
    QList<InStockOrderSearchInfo> m_orderInfoList;
    QList<InStockOrderSearchInfo> m_backUpOrderInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // INQUIRE_H
