#ifndef SETBASEGUIDEWIDGET_H
#define SETBASEGUIDEWIDGET_H

#include <QWidget>

namespace Ui {
class SetBaseGuideWidget;
}

class SetBaseGuideWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SetBaseGuideWidget(QWidget *parent = 0);
    ~SetBaseGuideWidget();
signals:
    void sigOnShowSetButtonPage();
private slots:
    void on_pushButton_clicked();

private:
    Ui::SetBaseGuideWidget *ui;
};

#endif // SETBASEGUIDEWIDGET_H
