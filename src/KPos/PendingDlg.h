#ifndef PENDINGDLG_H
#define PENDINGDLG_H

#include <QDialog>
#include "structData.h"

namespace Ui {
class PendingDlg;
}
/**
 * @brief The PendingDlg class  挂单解单对话框类
 */

class PendingDlg : public QDialog
{
    Q_OBJECT

public:
    explicit PendingDlg(QWidget *parent = 0);
    ~PendingDlg();
public:
    void initData();

public slots:
    void slot_selectSaleHead( const QString& strOrderNum , int nPosition );//选择订单
    void slot_unPending( const QString &strOrderNum );//解单
    void slot_deleteOrder( const QString& strOrderNum , bool bSelect );//删除选中的订单
    void slot_clearOrder();//清除订单
signals:
    void sig_addSaleHead( QString strOrderNum );
    void sig_hideDlg();
    void sig_pendingChanged();

private:
    void init();
    void initConnect();
    void setArrowPosition( int nPosition );//箭头指向的位置

private:
    Ui::PendingDlg *ui;
    QMap< int, SaleHead > m_mapSaleHead;//key:创建时间
};

#endif // PENDINGDLG_H
