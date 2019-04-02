#ifndef MTSCALEXML_H
#define MTSCALEXML_H

#include <QDomDocument>
#include "MTScaleAPIDll.h"

class MTScaleXML
{
public:
    explicit MTScaleXML();
    static void createTask(QString sTaskID);
    static void createDeviceList(BarCodeScaleInfo sendInfo);
    static void createTestScaleDataFile();
    static void createTestCommandDataFile(QList<BCSGroupManageRightInfo> groupList);
    static void createTaskResult();
    static QString ceadTaskResult();

private:
    void createXML(QDomDocument doc,QString fileName);
};

#endif // MTSCALEXML_H
