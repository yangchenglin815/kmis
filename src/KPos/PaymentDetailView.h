#ifndef PAYMENTDETAILVIEW_H
#define PAYMENTDETAILVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "../data/structData.h"
#include "enumData.h"
#include <QString>

class PaymentDetailDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit PaymentDetailDelegate();
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintPaymentDetailInfo(QPainter *painter, const QStyleOptionViewItem &option, const PaymentDetailInfo& rInfo, bool bSelected, EButtonStatus eButtonStatus ) const;
    QString PayTypeToString( EPaymentType ePaymentType ) const;
    QString PayStatusToString( EPaymentState ePaymentState ) const;
};

class PaymentDetailView : public QListView
{
    Q_OBJECT
public:
    explicit PaymentDetailView(QWidget *parent = 0);
    ~PaymentDetailView();
    void appendItem(const PaymentDetailInfo& rInfo);
    void clearItem();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent( QMouseEvent *event);
private:
    void init();
signals:
    void sigButtonClicked( EPayMethod ePayMethod,QString sPayOrderNum, float fPayMoney, bool bVirtual );
    void sigButtonRelease( EPayMethod ePayMethod,QString sPayOrderNum );
private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;//key:nPos 序列号作为唯一标识
};

#endif // PAYMENTDETAILVIEW_H
