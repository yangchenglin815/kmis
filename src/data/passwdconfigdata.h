#ifndef PASSWDCONFIGDATA
#define PASSWDCONFIGDATA

#include <QVariant>

struct AccountInfo
{
    QString id;
    QString sAccountID;  //员工工号
    QString sName;       //账号姓名
    QString sPasswd;     //账号密码
    QString sTelnumber;  //电话号码
    int sPower;          //角色权限  0:店长 1:收银员 2:导购员
    bool status;         //状态  0:禁用 1:启用
};
Q_DECLARE_METATYPE(AccountInfo)

#endif // PASSWDCONFIGDATA

