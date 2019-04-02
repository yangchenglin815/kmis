#ifndef SETHOMEGUIDEPAGE_H
#define SETHOMEGUIDEPAGE_H

#include <QWidget>

namespace Ui {
class SetHomeGuidePage;
}

class SetHomeGuidePage : public QWidget
{
    Q_OBJECT

public:
    explicit SetHomeGuidePage(QWidget *parent = 0);
    ~SetHomeGuidePage();

private:
    Ui::SetHomeGuidePage *ui;
};

#endif // SETHOMEGUIDEPAGE_H
