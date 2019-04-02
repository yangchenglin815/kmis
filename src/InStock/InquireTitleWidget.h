#ifndef INQUIRETITLEWIDGET_H
#define INQUIRETITLEWIDGET_H

#include <QWidget>
#include <QMap>

class InquireTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InquireTitleWidget(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // STOCKORDERTITLEWIDGET_H
