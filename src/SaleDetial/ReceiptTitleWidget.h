#ifndef RECEIPTTITLEWIDGET_H
#define RECEIPTTITLEWIDGET_H

#include <QWidget>

class ReceiptTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ReceiptTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // RECEIPTTITLEWIDGET_H
