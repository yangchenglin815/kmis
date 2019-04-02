#ifndef RECEIVEPROVIDERFORCREATEWIDGET_H
#define RECEIVEPROVIDERFORCREATEWIDGET_H

#include <QWidget>
#include "../data/recievinggoodsdata.h"

namespace Ui {
class ReceiveProviderForCreateWidget;
}

class ReceiveProviderForCreateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiveProviderForCreateWidget(QWidget *parent = 0);
    ~ReceiveProviderForCreateWidget();
    void initData(const QList<ReceiveProviderInfo*>& receiveProviderInfoList);

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
    void sigClickProvider(int nProviderId);
    void sigSearchChanged(QString sSearchText);

private:
    Ui::ReceiveProviderForCreateWidget *ui;
    QList<ReceiveProviderInfo*> m_receiveProviderInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // RECEIVEPROVIDERFORCREATEWIDGET_H
