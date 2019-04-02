#ifndef RESETKEYCTRL_H
#define RESETKEYCTRL_H

#include <QObject>
#include <QString>

class ResetKeyCtrl : public QObject
{
    Q_OBJECT
public:
    explicit ResetKeyCtrl(QObject *parent = 0);
    void resetKeyRequest(QString oldkey, QString newkey);//修改密码

signals:
    void sigResetPasswd(int nCode, QString sMsg);//修改密码

private:
    void initConnect();
};

#endif // RESETKEYCTRL_H
