#ifndef REFUNDGOODSREASONDLG_H
#define REFUNDGOODSREASONDLG_H

#include <QDialog>
#include <QLineEdit>
#include "../data/httpstructdata.h"

namespace Ui {
class RefundGoodsReasonDlg;
}

class RefundGoodsReasonDlg : public QDialog
{
    Q_OBJECT

public:
    explicit RefundGoodsReasonDlg(QWidget *parent = 0);
    ~RefundGoodsReasonDlg();
    void setReasonList(const QList<RefundGoodsReason>& reasonList);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    void clickReason(int nPos);
    void initConnect();

signals:
    void sigClickReason(int nReasonId);

private:
    Ui::RefundGoodsReasonDlg *ui;
    QList<QLineEdit*> m_lineEditList;
    QList<RefundGoodsReason> m_reasonList;
};

#endif // REFUNDGOODSREASONDLG_H
