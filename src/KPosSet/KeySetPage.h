#ifndef KEYSETPAGE_H
#define KEYSETPAGE_H

#include <QWidget>
#include "PressKeyWidget.h"
#include "../data/setstructdata.h"
#include "HomeKeySortDlg.h"
#include "RefundKeySortDlg.h"

namespace Ui {
class KeySetPage;
}

class KeySetPage : public QWidget
{
    Q_OBJECT

public:
    explicit KeySetPage(QWidget *parent = 0);
    ~KeySetPage();

    void initData(const KeySet& keySet);
    void uploadData(KPosSet &kPosSet);

private slots:
    void on_homeKeySortButton_clicked();
    void on_refundKeySortButton_clicked();
    void slot_clickHomeKeyId(int nKeyId, int nKeyPos);
    void slot_HomeKeyFinished(QList<int> keyIdList);
    void slot_clickRefundKeyId(int nKeyId, int nKeyPos);
    void slot_RefundKeyFinished(QList<int> keyIdList);

private:
    void init();
    void initConnect();
    void initKeyWidgetList(QList<KeySetInfo> keySetInfolist);
    void checkIsChanged(KPosSet& kPosSet);

private:
    Ui::KeySetPage *ui;
    QList<PressKeyWidget*> m_keyWidgetList;
    KeySet m_defaultKeySet;
    HomeKeySortDlg *m_pHomeKeySortDlg;
    RefundKeySortDlg *m_pRefundKeySortDlg; 
};

#endif // KEYSETPAGE_H
