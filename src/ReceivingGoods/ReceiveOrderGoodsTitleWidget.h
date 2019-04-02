#ifndef RECEIVEORDERGOODSTITLEWIDGET_H
#define RECEIVEORDERGOODSTITLEWIDGET_H

#include <QWidget>

class ReceiveOrderGoodsTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ReceiveOrderGoodsTitleWidget(QWidget *parent = 0);
    void setFinishedFlag(bool bFinished);

protected:
    void paintEvent(QPaintEvent *event);

private:
    bool m_bFinished;
};

#endif // RECEIVEORDERGOODSTITLEWIDGET_H
