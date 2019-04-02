#ifndef CHECKDETIALWIDGET_H
#define CHECKDETIALWIDGET_H

#include <QWidget>
#include "httpstructdata.h"
#include "../data/stockdata.h"

namespace Ui {
class CheckDetialWidget;
}

class CheckDetialWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CheckDetialWidget(QWidget *parent = 0);
    ~CheckDetialWidget();
    void initData(const QList<AddReportLossSelectInfo> &itemInfoList);
    void getSelectId(int selectId);

protected:
    void showEvent(QShowEvent *);

private slots:
    void slot_last();
    void slot_next();
    void slot_sortFourthCol(bool m_bFourthArrowDown);
    void slot_sortFifthCol(bool m_bFifthArrowDown);
    void slot_searchChanged(QString str);

private:
    Ui::CheckDetialWidget *ui;
    QList<CheckDetialInfo> m_InfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    int m_selectId;

private:
    void init();
    void initconnect();
    void generateUI();
    void checkCurPageButtonState();
    void test();
};

#endif // CHECKDETIALWIDGET_H
