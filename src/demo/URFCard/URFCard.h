#ifndef URFCARD_H
#define URFCARD_H

#include <QWidget>
#include "mwrf32.h"

namespace Ui {
class URFCard;
}

class URFCard : public QWidget
{
    Q_OBJECT

public:
    explicit URFCard(QWidget *parent = 0);
    ~URFCard();
public:
    void initCtrl();
    void initConnect();

    void init();
    long GetBaund();
public slots:
    void slot_connect();
    void slot_disConnect();
    void slot_read();
    void slot_write();
    void slot_modifyPwd();
    void slot_init();
private:
    Ui::URFCard *ui;

    long m_baund;
    HANDLE icdev;
    int		m_Port;
    int		m_Sector;//扇区号
    QString	m_key;//加密
    int		m_OpMode;//读写：0：读，1:写
    QString	m_Data;
    HICON m_hIcon;
};

#endif // URFCARD_H
