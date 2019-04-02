#ifndef UPLOADSUCCESSWIDGET_H
#define UPLOADSUCCESSWIDGET_H

#include <QWidget>

namespace Ui {
class UploadSuccessWidget;
}

class UploadSuccessWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UploadSuccessWidget(QWidget *parent = 0);
    ~UploadSuccessWidget();

private:
    Ui::UploadSuccessWidget *ui;
};

#endif // UPLOADSUCCESSWIDGET_H
