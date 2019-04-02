#ifndef PENDINGLISTWIDGET_H
#define PENDINGLISTWIDGET_H

#include <QWidget>
#include "../data/structData.h"

namespace Ui {
class PendingListWidget;
}
/**
 * @brief The PendingListWidget class  挂单列表窗口
 */
class PendingListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PendingListWidget(QWidget *parent = 0);
    ~PendingListWidget();
    void setTitleMinHeight(int minHeight);

    void init();
    void initData( QMap< int, SaleHead> &mapSaleHead );
    int getItemHeight();

public slots:
    void slot_unPending( QString strOrderNum );//解单
    void slot_deleteOrder( QString strOrderNum );//删除订单
    void slot_selectPending( OrderInfo rInfo );//选中订单
signals:
    void sig_selectSaleHead( QString strOrderNum, int nPosition );
    void sig_unPending( QString strOrderNum );
    void sig_deleteOrder( QString strOrderNum, bool bSelect );
private slots:
    void slot_upPageButton_clicked();//上一页
    void slot_downPageButton_clicked();//下一页
private:
    void initConnect();
    void generateSellList();
    void showFirstPending();
    void setCurPage( int nCurPage, int nTotalPage );
    int getPageNum( int nSaleHeadNum );
    void clearOrderList();
private:
    Ui::PendingListWidget *ui;
    QList<OrderInfo *> m_orderList;

    int m_nCurPageNum;
    int m_nTotalPageNum;
    int m_nOnePageCount;
};

#endif // PENDINGLISTWIDGET_H
