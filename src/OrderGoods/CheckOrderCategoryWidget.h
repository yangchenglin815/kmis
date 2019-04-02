#ifndef CHECKORDERCATEGORYWIDGET_H
#define CHECKORDERCATEGORYWIDGET_H

#include <QWidget>
#include "../data/ordergoodsdata.h"
#include "../common_ui/KPosCalendarWidget.h"

namespace Ui {
class CheckOrderCategoryWidget;
}

class CheckOrderCategoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CheckOrderCategoryWidget(QWidget *parent = 0);
    ~CheckOrderCategoryWidget();
    void initData(const QList<CheckOrderCategoryInfo*> checkOrderCategoryInfoList);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_nextPageButton_clicked();
    void slot_selectAllCategory(bool bSelectAll);
    void slot_addSelectCategory(int nCategoryId, bool bAdded);
    void slot_clickDate(int nYear, int nMonth, int nDay);
    void slot_searchChanged(QString searchText);

private:
    void generateUI();
    void initConnect();
    void inputStartDate();
    void inputEndDate();

signals:
    void sigSelectAllCategory(bool bSelectAll);
    void sigAddSelectCategory(int nCategoryId, bool bAdded);
    void sigSearch(QString sStartDate, QString sEndDate, QString sSearchText);

private:
    Ui::CheckOrderCategoryWidget *ui;
    QList<CheckOrderCategoryInfo*> m_checkOrderCategoryInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    KPosCalendarWidget* m_pKPosCalendarWidget;
    bool m_bInStartDate;
    QString m_sStartDate;
    QString m_sEndDate;
    QString m_sSearchPattern;
};

#endif // CHECKORDERCATEGORYWIDGET_H
