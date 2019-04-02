#ifndef TITLEWITHRETURNWIDGET_H
#define TITLEWITHRETURNWIDGET_H

#include <QWidget>

namespace Ui {
class TitleWithReturnWidget;
}

class TitleWithReturnWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TitleWithReturnWidget(QWidget *parent = 0);
    ~TitleWithReturnWidget();

private slots:
    void on_backButton_clicked();

signals:
    void sigReturnClicked();

private:
    Ui::TitleWithReturnWidget *ui;
};

#endif // TITLEWITHRETURNWIDGET_H
