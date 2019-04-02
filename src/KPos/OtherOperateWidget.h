#ifndef OTHEROPERATEWIDGET_H
#define OTHEROPERATEWIDGET_H

#include <QWidget>
#include "setstructdata.h"
#include "OperatorButton.h"
#include <QEvent>

namespace Ui {
class OtherOperateWidget;
}
/**
 * @brief The OtherOperateWidget class 其他操作按钮窗口
 */
class OtherOperateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OtherOperateWidget(QWidget *parent = 0);
    ~OtherOperateWidget();

    void updateOperateList( QList<KeySetInfo> &listHomeKey );//更新操作按钮列表
    bool getOperateList();
signals:
    void sig_clicked( int nKeyId );
    void sig_wndHide();
protected:
    bool event(QEvent *e);
private:
    void initCtrl();
    void initConnect();
    void test();

    void clearBtnInfo();
    void setOPerateList( QList<KeySetInfo> listHomeKey );
private:
    Ui::OtherOperateWidget *ui;
    QList<OperatorButton*> m_listOtherKeyBtn;
    //QList<QSt
};

#endif // OTHEROPERATEWIDGET_H
