#ifndef SETPARAMGUIDEWIDGET_H
#define SETPARAMGUIDEWIDGET_H

#include <QWidget>

namespace Ui {
class SetParamGuideWidget;
}

class SetParamGuideWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SetParamGuideWidget(QWidget *parent = 0);
    ~SetParamGuideWidget();
signals:
    void sigOnShowHomePage();
private slots:
    void on_pushButton_clicked();

private:
    Ui::SetParamGuideWidget *ui;
};

#endif // SETPARAMGUIDEWIDGET_H
