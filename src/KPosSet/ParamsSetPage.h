#ifndef PARAMSSETPAGE_H
#define PARAMSSETPAGE_H

#include <QWidget>
#include "../data/setstructdata.h"
#include "WndDigitalKeyboardDlg.h"

namespace Ui {
class ParamsSetPage;
}

class ParamsSetPage : public QWidget
{
    Q_OBJECT

public:
    explicit ParamsSetPage(QWidget *parent = 0);
    ~ParamsSetPage();
    void initData(const ParamsSet& paramsSet);
    void initSystemParams(const ParamsSet &paramsSet);
    void uploadData(KPosSet& kPosSet);

//protected:
//    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    // 小键盘
//    void slot_Text(QString sNum);
//    void slot_Delete();
//    void slot_Clear();
//    void slot_Confirm();

private:
    Ui::ParamsSetPage *ui;
    ParamsSet m_defaultParamsSet;
//    WndDigitalKeyboardDlg* m_pKeyboardDlg;
};

#endif // PARAMSSETPAGE_H
