#ifndef PENDINGLISTTITLEWIDGET_H
#define PENDINGLISTTITLEWIDGET_H

#include <QWidget>

class PendingListTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PendingListTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // PENDINGLISTTITLEWIDGET_H
