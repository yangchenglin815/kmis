#ifndef SCREENSETPAGE_H
#define SCREENSETPAGE_H

#include <QWidget>
#include "../data/setstructdata.h"

namespace Ui {
class ScreenSetPage;
}

class ScreenSetPage : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenSetPage(QWidget *parent = 0);
    ~ScreenSetPage();
    void somePlacePressed(const QPoint& globalPoint = QPoint(0,0));
    void initData(const ScreenSet& screenSet);
    void setDefultData(ScreenSet screenSet);
    void uploadData(KPosSet& kPosSet);

private slots:
    void on_printerTestButton_clicked();
    void on_clientScreenPortTestButton_clicked();
    void on_cardReaderTestButton_clicked();
    void on_noScreenRButton_clicked();
    void on_numberScreenRButton_clicked();
    void on_englishScreenRButton_clicked();
    void on_chineseScreenRButton_clicked();
    void on_colorScreenRButton_clicked();

private:
    void init();
    void initConnect();

private:
    Ui::ScreenSetPage *ui;
    ScreenSet m_screenSet;
};

#endif // SCREENSETPAGE_H
