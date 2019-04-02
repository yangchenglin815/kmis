#include "MTScaleAPIDll.h"
#include "MTScaleAPI.h"
#include "FilePathManage.h"
#include "MTScaleXML.h"
#include <QMessageBox>
#include <QLibrary>
#include <QStandardPaths>
#include <QDebug>
#include <QDir>

//下发XML文件到秤
void MTScaleAPIDll::IssuedMTScale(QString sTaskID)
{
//    QString m_sDocumentsPath = FilePathManage::instance()->getXMLPath();

//    QString sInputFile = m_sDocumentsPath + "Input/Task.xml";
//    QByteArray bInputFile = (sInputFile).toLatin1();
//    const char *szInputFile = bInputFile.data();
    const char *szInputFile = "C:/Task.xml";
//    QDir szInputFileDir("./Task.xml");
//    QString str = "szInputFileDir.absolutePath()";
//    const char *szInputFile = "str.toStdString().c_str()";
//    qDebug()<<szInputFile;

//    QByteArray bOutputFile = (m_sDocumentsPath + "/Output/TaskResult.xml").toLatin1();
//    const char *szOutputFile =  bOutputFile.data();
//    QDir szOutputFileDir("./TaskResult.xml");
    const char *szOutputFile = "C:/TaskResult.xml";
//    const char *szOutputFile = szOutputFileDir.absolutePath().toStdString().c_str();

    QByteArray bTaskID = sTaskID.toLatin1();
    const char *szTaskID = bTaskID.data();
    ExecuteTaskInFile(szTaskID, szInputFile, szOutputFile, true);
//    QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("下发完成"));
}

//创建下发的XML文件
void MTScaleAPIDll::createScaleXML(QString sTaskID, BarCodeScaleInfo sendInfo, QList<BCSGroupManageRightInfo> groupList)
{
    MTScaleXML::createTask(sTaskID);
    MTScaleXML::createDeviceList(sendInfo);
    MTScaleXML::createTestScaleDataFile();
    MTScaleXML::createTestCommandDataFile(groupList);
    MTScaleXML::createTaskResult();
}

//识别条码秤打印的条形码
MTBarcodeProductData_s MTScaleAPIDll::verifyBarcode(QString sBarcode)
{
    MTBarcodeProductData_s ProductData;

    if(sBarcode.length() != 13){
        return ProductData;
    }

    QString headcode = sBarcode.mid(0,2);
    if(headcode != "21"){
        return ProductData;
    }

    QString plu = sBarcode.mid(2,5);
    float weight = sBarcode.mid(7,5).toFloat();

    ProductData.plu = plu;
    ProductData.weight = QString("%1").arg(weight/1000);

    return ProductData;
}

//读取返回文件的值
bool MTScaleAPIDll::ceadResultXML()
{
    QString State = MTScaleXML::ceadTaskResult();
//    qDebug()<<State<<"11111111111111111";
    if(State == "OK")
    {
        return true;
    }
    else
    {
        return false;
    }


}

