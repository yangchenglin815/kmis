#include "ResetKeyCtrl.h"
#include "../data/constData.h"
#include "../Agent/ResetKeyAgent.h"

ResetKeyCtrl::ResetKeyCtrl(QObject *parent) : QObject(parent)
{
    initConnect();
}

void ResetKeyCtrl::initConnect()
{
    connect(ResetKeyAgent::instance(), SIGNAL(sigResetPasswd(int,QString))
             , this, SIGNAL(sigResetPasswd(int,QString)));

}

void ResetKeyCtrl::resetKeyRequest(QString oldkey, QString newkey){
    ResetKeyAgent::instance()->resetKeyRequest(oldkey, newkey);
}

