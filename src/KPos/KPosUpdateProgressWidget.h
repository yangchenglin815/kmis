#ifndef KPOSUPDATEPROGRESSWIDGET_H
#define KPOSUPDATEPROGRESSWIDGET_H

#include <QWidget>

namespace Ui {
class KPosUpdateProgressWidget;
}

class KPosUpdateProgressWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KPosUpdateProgressWidget(QWidget *parent = 0);
    ~KPosUpdateProgressWidget();
    void setProgressValue(int nProgressValue);

private:
    Ui::KPosUpdateProgressWidget *ui;
};

#endif // KPOSUPDATEPROGRESSWIDGET_H
