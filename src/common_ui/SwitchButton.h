#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include <QPushButton>

class SwitchButton : public QPushButton
{
    Q_OBJECT
public:
    explicit SwitchButton(QWidget *parent = 0);
    void setOpenState(bool bOpen);
    bool isOpen();

private slots:
    void slot_clicked();

private:
    void initConnect();

private:
    bool m_bOpen;
};

#endif // SWITCHBUTTON_H
