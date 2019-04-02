#ifndef OPERATEWIDGET_H
#define OPERATEWIDGET_H

#include <QWidget>
#include "enumData.h"
#include "OperatorButton.h"
#include "setstructdata.h"

namespace Ui {
class OperateWidget;
}

class OperateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OperateWidget(QWidget *parent = 0);
    ~OperateWidget();

    void setColumn( int nColumn );
    void setUnSelectStatus( HomeKeyType eHomeKeyType );//设置没有选中的状态
    void updateOperateList( QList<KeySetInfo> &listKeyInfo );//更新操作按钮列表
    void updatePendingNum();

public:

signals:
    void sig_showOtherButton();
    void sig_showMemDlg();
    void sig_showPendingDlg();
    void sig_deleteSelectGoods();
    void sig_modifyNum();//修改数量
    void sig_clearAllGoods();
    void sig_peeling();
    void sig_clicked( int nKeyId );
private slots:
    void slot_clicked( int nKeyId );
private:
    void initCtrl();
    void initConnect();
    void clearBtnInfo();

    void test();
    void setKeyInfo( QList<KeySetInfo> listKeyInfo );
private:
    Ui::OperateWidget *ui;

    int m_nColumn;
    QList<OperatorButton*> m_listOperatorBtn;
};

#endif // OPERATEWIDGET_H
