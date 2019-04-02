#ifndef SETBUTTONGUIDEWIDGET_H
#define SETBUTTONGUIDEWIDGET_H

#include <QWidget>

namespace Ui {
class SetButtonGuideWidget;
}

class SetButtonGuideWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SetButtonGuideWidget(QWidget *parent = 0);
    ~SetButtonGuideWidget();
signals:
    void sigOnShowGoodsPage();
private slots:
    void on_pushButton_clicked();

private:
    Ui::SetButtonGuideWidget *ui;
};

#endif // SETBUTTONGUIDEWIDGET_H
