#ifndef RECEIVEPROVIDERWIDGET_H
#define RECEIVEPROVIDERWIDGET_H

#include <QWidget>
#include "../data/recievinggoodsdata.h"

namespace Ui {
class ReceiveProviderWidget;
}

class ReceiveProviderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiveProviderWidget(QWidget *parent = 0);
    ~ReceiveProviderWidget();
    void test();

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void slot_searchChanged(QString searchText);
    void slot_clickProveder(int nProviderId);

private:
    void initConnect();
    void generateUI();
    void checkCurPageButtonState();

signals:
    void sigClickProvider(ReceiveProviderInfo receiveProviderInfo);

private:
    Ui::ReceiveProviderWidget *ui;
    ReceiveProviderInfo m_rootReceiveProviderInfo;
    QList<ReceiveProviderInfo> m_receiveProviderInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // RECEIVEPROVIDERWIDGET_H
