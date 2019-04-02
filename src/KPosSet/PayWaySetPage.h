#ifndef PAYWAYSETPAGE_H
#define PAYWAYSETPAGE_H

#include <QWidget>
#include <QLabel>
#include "SwitchButton.h"
#include "KPosComboBox.h"
#include "../data/setstructdata.h"
#include "../Bussiness/KPosSetCtrl.h"

namespace Ui {
class PayWaySetPage;
}

class PayWaySetPage : public QWidget
{
    Q_OBJECT

public:
    explicit PayWaySetPage(QWidget *parent = 0);
    ~PayWaySetPage();
    void somePlacePressed(const QPoint& globalPoint = QPoint(0,0));
    void uploadData(KPosSet& kPosSet);
    void initData(const PayWaySet &payWaySet);

private:
    void init();
    void pingbi();

private:
    Ui::PayWaySetPage *ui;
    PayWaySet m_defaultPayWay;
};

#endif // PAYWAYSETPAGE_H
