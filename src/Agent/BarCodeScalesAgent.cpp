#include "BarCodeScalesAgent.h"
#include "../util/ThreadManager.h"
#include "../util/HttpSignal.h"
#include "CommonFun.h"
#include "MTScaleAPIDll.h"
#include "HttpClient.h"
#include "enumData.h"
#include "KPosLog.h"
#include <QDateTime>
#include <QDebug>
#include <QTime>
#include <QApplication>
#include <QDir>
#include "KPosLog.h"

BarCodeScalesAgent* BarCodeScalesAgent::m_pInstance = NULL;

BarCodeScalesAgent::BarCodeScalesAgent(QObject *parent)
    : QObject(parent)
//    , m_nCheckStateCount(0)
{
    initConnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

BarCodeScalesAgent *BarCodeScalesAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new BarCodeScalesAgent;
    }
    return m_pInstance;
}

void BarCodeScalesAgent::checkBcsState(const QList<BarCodeScaleInfo> &infoList)
{
    emit sigCheckBcsState(infoList);
}

void BarCodeScalesAgent::sendDownBcs(QList<BarCodeScaleInfo> &infoList , QList<BCSGroupManageLeftInfo> &m_leftInfoList)
{
    QDir szInputFileDir("./Task.xml");
    QString str = szInputFileDir.absolutePath();
    const char *szInputFile = str.toStdString().c_str();
    qDebug()<<szInputFile;

    emit sigSendDownBcs(infoList ,m_leftInfoList);
}

void BarCodeScalesAgent::createGoodsGroupRequest(QString sGroupName)
{
    HttpClient::instance()->createGoodsGroup(sGroupName);
}

void BarCodeScalesAgent::getGoodsGroupListRequest()
{
    HttpClient::instance()->getGoodsGroupList();
}

void BarCodeScalesAgent::saveGoodsGroupRequest(int nGroupId, const QList<QString> &pluList)
{
    HttpClient::instance()->saveGoodsGroup(nGroupId, pluList);
}

void BarCodeScalesAgent::getBarcodeScaleCodeRequest()
{
    HttpClient::instance()->getBarcodeScaleCode();
}

void BarCodeScalesAgent::addBarcodeScaleRequest(QString sCode, QString sType, QString sIp, int nGroupId)
{
    HttpClient::instance()->addBarcodeScale(sCode, sType, sIp, nGroupId);
}

void BarCodeScalesAgent::getBarcodeScaleListRequest()
{
    HttpClient::instance()->getBarcodeScaleList();
}

void BarCodeScalesAgent::updateScaleProductIssueRequest(const QList<QString> &scaleList)
{
    HttpClient::instance()->updateScaleProductIssue(scaleList);
}

void BarCodeScalesAgent::deleteScaleRequestRequest(QString scaleId)
{
    HttpClient::instance()->deleteScale(scaleId);
}

void BarCodeScalesAgent::slot_checkBcsState(QList<BarCodeScaleInfo> infoList)
{
    QTime reachTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime() < reachTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }

    int nLen = infoList.length();
    for(int i = 0; i < nLen; i++)
    {
        if (infoList[i].nState == e_bcsForbidLink)
        {
            continue;
        }
        QString sKey = infoList[i].sKeyId;
        QString sIp = infoList[i].sIP;
        bool bLinkSuccess = CommonFun::pingScale(sIp);
        emit sigOnCheckBcsState(sKey, bLinkSuccess);
    }
    emit sigOnCheckBcsStateFinish();
}

void BarCodeScalesAgent::slot_sendDownBcs(QList<BarCodeScaleInfo> infoList, QList<BCSGroupManageLeftInfo> leftInfoList)
{
    for(int i = 0; i < infoList.length(); i++)
    {
        QString sDateTime= QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
        QString sTaskID = infoList[i].sCode + sDateTime;

        QList<BCSGroupManageRightInfo> groupList;

        for(int j = 0; j < leftInfoList.length(); j++)
        {
            if(infoList[i].sGoodsGroup.toInt() == leftInfoList[j].nGroupId)
            {
                groupList = leftInfoList[j].rightInfoList;
            }
        }

//        for(int j = 0; j<200 ; j++)
//        {
//            BCSGroupManageRightInfo group;
//            group.sGoodsPlu = QString("%1").arg(j+1);
//            group.sGoodsCode = QString("%1").arg(j+1);
//            group.sGoodsName = QString("%1A皮皮虾").arg(j+1);
//            group.sGoodsPrice = QString("1%1.00").arg(j+1);
//            groupList.append(group);
//        }
        QString DebugTime= QDateTime::currentDateTime().toString("hh:mm:ss");
        qDebug()<<DebugTime +  QString("StartCreateXML%1").arg(i+1);

        MTScaleAPIDll::createScaleXML(sTaskID, infoList[i], groupList);//创建下发用XML文件

        MTScaleAPIDll::IssuedMTScale(sTaskID);//下发XML文件

        bool bSuccess =  MTScaleAPIDll::ceadResultXML();//读取返回文件
        KPosLog::instance()->writeErrorLog(QString("slot_sendDownBcs -- %1").arg(bSuccess));
        emit sigOnSendDownBcsState(infoList[i].sKeyId, bSuccess);
    }

    emit sigOnSendDownBcsFinish();
}

//void BarCodeScalesAgent::slot_onGetGoodsGroupList(int nCode, QString sMsg, QList<BCSGroupManageLeftInfo> leftInfoList)
//{
//    if(nCode == e_success)
//    {
//         m_leftInfoList = leftInfoList;
//    }
//    emit sigOnGetGoodsGroupList(nCode,  sMsg, leftInfoList);

//}

//void BarCodeScalesAgent::slot_onGetBarcodeScaleList(int nCode, QString sMsg, QList<BarCodeScaleInfo> scaleInfoList)
//{
//    if(nCode == e_success)
//    {
//         m_infoList = scaleInfoList;
//    }
//    emit sigOnGetBarcodeScaleList(nCode,  sMsg, scaleInfoList);
//}

void BarCodeScalesAgent::initConnect()
{
    qRegisterMetaType<QList<BarCodeScaleInfo> >("QList<BarCodeScaleInfo>");
    connect(this, SIGNAL(sigCheckBcsState(QList<BarCodeScaleInfo>)), this, SLOT(slot_checkBcsState(QList<BarCodeScaleInfo>)));
    qRegisterMetaType<QList<BarCodeScaleInfo> >("QList<BarCodeScaleInfo>");
    connect(this, SIGNAL(sigSendDownBcs(QList<BarCodeScaleInfo>, QList<BCSGroupManageLeftInfo>))
            , this, SLOT(slot_sendDownBcs(QList<BarCodeScaleInfo>, QList<BCSGroupManageLeftInfo>)));
    qRegisterMetaType<BCSGroupManageLeftInfo>("BCSGroupManageLeftInfo");
    connect(HttpSignal::instance(), SIGNAL(sigOnCreateGoodsGroup(int,QString,BCSGroupManageLeftInfo))
            , this, SIGNAL(sigOnCreateGoodsGroup(int,QString,BCSGroupManageLeftInfo)));
    qRegisterMetaType<QList<BCSGroupManageLeftInfo> >("QList<BCSGroupManageLeftInfo>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetGoodsGroupList(int,QString,QList<BCSGroupManageLeftInfo>))
             , this, SIGNAL(sigOnGetGoodsGroupList(int,QString,QList<BCSGroupManageLeftInfo>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnGetBarcodeScaleCode(int,QString,QString)), this, SIGNAL(sigOnGetBarcodeScaleCode(int,QString,QString)));

    connect(HttpSignal::instance(), SIGNAL(sigOnGetBarcodeScaleList(int, QString, QList<BarCodeScaleInfo>))
             , this, SIGNAL(sigOnGetBarcodeScaleList(int, QString, QList<BarCodeScaleInfo>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnAddBarcodeScale(int, QString))
             , this, SIGNAL(sigOnAddBarcodeScale(int, QString)));
    connect(HttpSignal::instance(), SIGNAL(sigOnDeleteScale(int, QString, QString))
             , this, SIGNAL(sigOnDeleteScale(int, QString, QString)));

}
