#ifndef BCSGROUPMANAGERIGHTTITLEWIGET_H
#define BCSGROUPMANAGERIGHTTITLEWIGET_H

#include <QWidget>

class BCSGroupManageRightTitleWiget : public QWidget
{
    Q_OBJECT
public:
    explicit BCSGroupManageRightTitleWiget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // BCSGROUPMANAGERIGHTTITLEWIGET_H
