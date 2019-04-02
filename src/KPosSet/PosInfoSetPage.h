#ifndef POSINFOSETPAGE_H
#define POSINFOSETPAGE_H

#include <QWidget>
#include "../data/setstructdata.h"

namespace Ui {
class PosInfoSetPage;
}

class PosInfoSetPage : public QWidget
{
    Q_OBJECT

public:
    explicit PosInfoSetPage(QWidget *parent = 0);
    ~PosInfoSetPage();
    void initData(const PosInfoSet& posInfoSet);
    void uploadData(KPosSet& kPosSet);

//private slots:
//    void on_balckSkinButton_clicked();
//    void on_flatSkinButton_clicked();
//    void on_smartButton_clicked();

private:
    void pingbi();

private:
    Ui::PosInfoSetPage *ui;
    PosInfoSet m_defaultKPosInfo;
};

#endif // POSINFOSETPAGE_H
