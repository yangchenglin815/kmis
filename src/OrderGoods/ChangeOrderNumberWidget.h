#ifndef CHANGEORDERNUMBERWIDGET_H
#define CHANGEORDERNUMBERWIDGET_H

#include <QWidget>
#include "OrderNumberKeyboardDlg.h"

namespace Ui {
class ChangeOrderNumberWidget;
}

class ChangeOrderNumberWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeOrderNumberWidget(QWidget *parent = 0);
    ~ChangeOrderNumberWidget();
    void initOrderNumber(int num);
    void showKeyBoard();

//protected:
//    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void slot_clickNumber(QString sNum);
    void slot_clickDelete();
    void slot_clickEnter();
    void on_leftArrowButton_clicked();
    void on_rightArrowButton_clicked();

private:


signals:
    void sigChangeNum(int nNum);

private:
    Ui::ChangeOrderNumberWidget *ui;
    OrderNumberKeyboardDlg* m_pOrderNumberKeyboardDlg;
};

#endif // CHANGEORDERNUMBERWIDGET_H
