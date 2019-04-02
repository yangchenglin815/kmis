#ifndef RECEIVEORDERSTOPWIDGET_H
#define RECEIVEORDERSTOPWIDGET_H

#include <QWidget>
#include "ReceiveProviderWidget.h"
#include "../common_ui/StringListWidget.h"

namespace Ui {
class ReceiveOrdersTopWidget;
}

class ReceiveOrdersTopWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiveOrdersTopWidget(QWidget *parent = 0);
    ~ReceiveOrdersTopWidget();

private slots:
    void slot_clickProvider();
    void slot_clickReceiptType();
    void slot_clickProviderText(ReceiveProviderInfo receiveProviderInfo);
    void slot_clickedReceiptTypeText(QString text);

private:
    void initConnect();
    void checkCurPageButtonState();

signals:
    void sigSearch(QString sProviderSearchText, QString sReceiptTypeSearchText, QString sDateStartSearchText, QString sDateEndSearchText);

private:
    Ui::ReceiveOrdersTopWidget *ui;
    ReceiveProviderWidget* m_pReceiveProviderWidget;
    StringListWidget* m_pStringListWidget;
    QString m_sProviderSearchText; // 供应商搜索条件
    QString m_sReceiptTypeSearchText; // 单据类型搜索条件
    QString m_sDateStartSearchText; // 日期起始时间搜索条件
    QString m_sDateEndSearchText; // 日期结束时间搜索条件
};

#endif // RECEIVEORDERSTOPWIDGET_H
