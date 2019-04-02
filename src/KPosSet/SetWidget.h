#ifndef SETWIDGET_H
#define SETWIDGET_H

#include <QWidget>
class QPushButton;
#include "../Bussiness/KPosSetCtrl.h"
#include "../data/structData.h"
#include "../data/setstructdata.h"
#include "SetGuideWidget.h"

namespace Ui {
class SetWidget;
}

class SetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SetWidget(QWidget *parent = 0);
    ~SetWidget();
    void setCategoryInfoList(const QList<CategoryInfo *> &categoryInfoList);
    void init();
    KPosSet getKPosSet();
    void initSetGuideObj(SetGuideWidget* setGuideWidget);
protected:
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_keySetButton_clicked();
    void on_goodsSetButton_clicked();
    void on_posInfoSetButton_clicked();
    void on_screenSetButton_clicked();
    void on_payWaySetButton_clicked();
    void on_paramsSetButton_clicked();
    void on_backButton_clicked();

    void on_deviceSetButton_clicked();

private:
    void setButtonsQss(QPushButton* selectedButton);
    void uploadData(QPushButton* selectedButton);
    void pingbi();

signals:
    void sig_backHomePage();
    void sigPressedPoint(QPoint globalPoint);

private:
    Ui::SetWidget *ui;
    KPosSetCtrl* m_pKPosSetCtrl;
    KPosSet m_kPosSet;
    QPushButton* m_pLastClickButton;
    SetGuideWidget* m_setGuideWidget;
};

#endif // SETWIDGET_H
