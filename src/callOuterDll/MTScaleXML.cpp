#include "MTScaleXML.h"
#include "FilePathManage.h"
#include "MTScaleAPIDll.h"
#include <QDomDocument>
#include <QTextStream>
#include <QStandardPaths>
#include <QFile>
#include <QDebug>

MTScaleXML::MTScaleXML()
{

}

//创建任务信息文件
void MTScaleXML::createTask(QString sTaskID)
{
    QString fileName = "Task.xml";

    QDomDocument doc;

    QDomElement root = doc.createElement("MTTask");
    doc.appendChild(root);

    //任务类型
    QDomElement TaskType = doc.createElement("TaskType");
    root.appendChild(TaskType);
    QDomText TaskType_text = doc.createTextNode("0");
    TaskType.appendChild(TaskType_text);

    //任务编号
    QDomElement TaskID = doc.createElement("TaskID");
    root.appendChild(TaskID);
    QDomText TaskID_text = doc.createTextNode(sTaskID);
    TaskID.appendChild(TaskID_text);

    //电子秤列表文件名
    QDomElement DataFile = doc.createElement("DataFile");
    root.appendChild(DataFile);
    QDomText DataFile_text = doc.createTextNode("DeviceList.xml");
    DataFile.appendChild(DataFile_text);

    MTScaleXML scaleXML;
    scaleXML.createXML(doc, fileName);
}

//创建电子秤信息文件
void MTScaleXML::createDeviceList(BarCodeScaleInfo sendInfo)
{
    QString fileName = "DeviceList.xml";

    QDomDocument doc;

    QDomElement root = doc.createElement("Devices");
    doc.appendChild(root);

    QDomElement Scale = doc.createElement("Scale");
    root.appendChild(Scale);

    //设备号
    QDomElement DeviceID = doc.createElement("DeviceID");
    Scale.appendChild(DeviceID);
    QDomText DeviceID_text = doc.createTextNode(sendInfo.sCode);
    DeviceID.appendChild(DeviceID_text);

    //秤号
    QDomElement ScaleNo = doc.createElement("ScaleNo");
    Scale.appendChild(ScaleNo);
    QDomText ScaleNo_text = doc.createTextNode(sendInfo.sCode);
    ScaleNo.appendChild(ScaleNo_text);

    //电子秤类型
    QDomElement ScaleType = doc.createElement("ScaleType");
    Scale.appendChild(ScaleType);
    QDomText ScaleType_text = doc.createTextNode("RL00");
    ScaleType.appendChild(ScaleType_text);

    //通讯类型
    QDomElement ConnectType = doc.createElement("ConnectType");
    Scale.appendChild(ConnectType);
    QDomText ConnectType_text = doc.createTextNode("Network");
    ConnectType.appendChild(ConnectType_text);

    //通讯参数
    QDomElement ConnectParams = doc.createElement("ConnectParams");
    Scale.appendChild(ConnectParams);

    //局域网连接参数
    QDomElement NetworkParams = doc.createElement("NetworkParams");
    ConnectParams.appendChild(NetworkParams);
    QDomAttr NetworkParams_Type = doc.createAttribute("Type");
    NetworkParams_Type.setValue("Network");
    NetworkParams.setAttributeNode(NetworkParams_Type);
    QDomAttr NetworkParams_Address = doc.createAttribute("Address");
    NetworkParams_Address.setValue(sendInfo.sIP);
    NetworkParams.setAttributeNode(NetworkParams_Address);
    QDomAttr NetworkParams_Port = doc.createAttribute("Port");
    NetworkParams_Port.setValue("3001");
    NetworkParams.setAttributeNode(NetworkParams_Port);


    //小数点位数
    QDomElement DecimalDigits = doc.createElement("DecimalDigits");
    Scale.appendChild(DecimalDigits);
    QDomText DecimalDigits_text = doc.createTextNode("2");
    DecimalDigits.appendChild(DecimalDigits_text);

    //命令信息文件名
    QDomElement DataFile = doc.createElement("DataFile");
    Scale.appendChild(DataFile);
    QDomText DataFile_text = doc.createTextNode("TestScaleDataFile.xml");
    DataFile.appendChild(DataFile_text);

    MTScaleXML scaleXML;
    scaleXML.createXML(doc, fileName);
}

//创建命令信息文件
void MTScaleXML::createTestScaleDataFile()
{
    QString fileName = "TestScaleDataFile.xml";

    QDomDocument doc;

    QDomElement root = doc.createElement("Commands");
    doc.appendChild(root);

    QDomElement Command = doc.createElement("Command");
    root.appendChild(Command);

    //命令字
    QDomElement CommandText = doc.createElement("CommandText");
    Command.appendChild(CommandText);
    QDomText CommandText_text = doc.createTextNode("Item");
    CommandText.appendChild(CommandText_text);

    //命令字编号
    QDomElement CommandID = doc.createElement("CommandID");
    Command.appendChild(CommandID);
    QDomText CommandID_text = doc.createTextNode("TestCommandID");
    CommandID.appendChild(CommandID_text);

    //命令控制字 Update：更新数据
    QDomElement Control = doc.createElement("Control");
    Command.appendChild(Control);
    QDomText Control_text = doc.createTextNode("Update");
    Control.appendChild(Control_text);

    //标志下发前是否清空数据
    QDomElement ClearData = doc.createElement("ClearData");
    Command.appendChild(ClearData);
    QDomText ClearData_text = doc.createTextNode("true");
    ClearData.appendChild(ClearData_text);

    //命令信息文件名
    QDomElement DataFile = doc.createElement("DataFile");
    Command.appendChild(DataFile);
    QDomText DataFile_text = doc.createTextNode("TestCommandDataFile.xml");
    DataFile.appendChild(DataFile_text);

    MTScaleXML scaleXML;
    scaleXML.createXML(doc, fileName);
}


//创建数据内容信息文件(商品数据)
void MTScaleXML::createTestCommandDataFile(QList<BCSGroupManageRightInfo> groupList)
{
    QString fileName = "TestCommandDataFile.xml";

    QDomDocument doc;

    QDomElement root = doc.createElement("data");
    doc.appendChild(root);

    int nLen = groupList.length();

    for(int i = 0; i < nLen; i++)
    {
        QDomElement Item = doc.createElement("Item");
        root.appendChild(Item);

        BCSGroupManageRightInfo groupInfo = groupList[i];
        //商品号
        QDomElement PLU = doc.createElement("PLU");
        Item.appendChild(PLU);
        QDomText PLU_text = doc.createTextNode(groupInfo.sGoodsPlu);
        PLU.appendChild(PLU_text);

        //部门号
        QDomElement DepartmentID = doc.createElement("DepartmentID");
        Item.appendChild(DepartmentID);
        QDomText DepartmentID_text = doc.createTextNode("0");
        DepartmentID.appendChild(DepartmentID_text);

        //货号列表
        QDomElement AlternativeItemIDs = doc.createElement("AlternativeItemIDs");
        Item.appendChild(AlternativeItemIDs);
        //货号
        QDomElement AlternativeItemID = doc.createElement("AlternativeItemID");
        AlternativeItemIDs.appendChild(AlternativeItemID);
        QDomText AlternativeItemID_text = doc.createTextNode(groupInfo.sGoodsCode);
        AlternativeItemID.appendChild(AlternativeItemID_text);

        //商品描述列表
        QDomElement Descriptions = doc.createElement("Descriptions");
        Item.appendChild(Descriptions);
        //商品描述文本
        QDomElement Description = doc.createElement("Description");
        QDomAttr Description_ID = doc.createAttribute("ID");
        Description_ID.setValue("0");
        Description.setAttributeNode(Description_ID);
        QDomAttr Description_Language = doc.createAttribute("Language");
        Description_Language.setValue("zho");
        Description.setAttributeNode(Description_Language);
        QDomAttr Description_Type = doc.createAttribute("Type");
        Description_Type.setValue("ItemName");
        Description.setAttributeNode(Description_Type);
        QDomAttr Description_Index = doc.createAttribute("Index");
        Description_Index.setValue("0");
        Description.setAttributeNode(Description_Index);
        QDomText Description_text = doc.createTextNode(groupInfo.sGoodsName);
        Description.appendChild(Description_text);
        Descriptions.appendChild(Description);

        //商品价格列表
        QDomElement ItemPrices = doc.createElement("ItemPrices");
        Item.appendChild(ItemPrices);
        //商品价格信息
        QDomElement ItemPrice = doc.createElement("ItemPrice");
        QDomAttr ItemPrice_Index = doc.createAttribute("Index");
        ItemPrice_Index.setValue("0");
        ItemPrice.setAttributeNode(ItemPrice_Index);
        QDomAttr ItemPrice_UnitOfMeasureCode = doc.createAttribute("UnitOfMeasureCode");
        ItemPrice_UnitOfMeasureCode.setValue("KGM");
        ItemPrice.setAttributeNode(ItemPrice_UnitOfMeasureCode);
        QDomAttr ItemPrice_PriceOverrideFlag = doc.createAttribute("PriceOverrideFlag");
        ItemPrice_PriceOverrideFlag.setValue("true");
        ItemPrice.setAttributeNode(ItemPrice_PriceOverrideFlag);
        QDomAttr ItemPrice_DiscountFlag = doc.createAttribute("DiscountFlag");
        ItemPrice_DiscountFlag.setValue("true");
        ItemPrice.setAttributeNode(ItemPrice_DiscountFlag);
        QDomAttr ItemPrice_Quantity = doc.createAttribute("Quantity");
        ItemPrice_Quantity.setValue("0");
        ItemPrice.setAttributeNode(ItemPrice_Quantity);
        QDomAttr ItemPrice_Currency = doc.createAttribute("Currency");
        ItemPrice_Currency.setValue("CNY");
        ItemPrice.setAttributeNode(ItemPrice_Currency);
        ItemPrices.appendChild(ItemPrice);
        QDomText ItemPrice_text = doc.createTextNode(groupInfo.sGoodsPrice);
        ItemPrice.appendChild(ItemPrice_text);
        ItemPrices.appendChild(ItemPrice);

        //商品标签号
        QDomElement LabelFormats = doc.createElement("LabelFormats");
        Item.appendChild(LabelFormats);
        QDomElement LabelFormatID = doc.createElement("LabelFormatID ");
        QDomAttr LabelFormatID_Index = doc.createAttribute("Index");
        LabelFormatID_Index.setValue("0");
        LabelFormatID.setAttributeNode(LabelFormatID_Index);
        QDomText LabelFormatID_text = doc.createTextNode("1");
        LabelFormatID.appendChild(LabelFormatID_text);
        LabelFormats.appendChild(LabelFormatID);


    }
    MTScaleXML scaleXML;
    scaleXML.createXML(doc, fileName);
}

//创建返回文件
void MTScaleXML::createTaskResult()
{
    QString fileName = "TaskResult.xml";

    QDomDocument doc;

    QDomElement root = doc.createElement("MTTaskResult");
    doc.appendChild(root);


//    QDomText text = doc.createTextNode(" ");

    //任务编号
    QDomElement TaskID = doc.createElement("TaskID");
    root.appendChild(TaskID);
    QDomText TaskID_text = doc.createTextNode(" ");
    TaskID.appendChild(TaskID_text);

    //任务类型。
    QDomElement TaskType = doc.createElement("TaskType");
    root.appendChild(TaskType);
    QDomText TaskType_text = doc.createTextNode(" ");
    TaskType.appendChild(TaskType_text);

    //任务开始时间。
    QDomElement StartTime = doc.createElement("StartTime");
    root.appendChild(StartTime);
    QDomText StartTime_text = doc.createTextNode(" ");
    StartTime.appendChild(StartTime_text);

    //任务结束时间。
    QDomElement EndTime = doc.createElement("EndTime");
    root.appendChild(EndTime);
    QDomText EndTime_text = doc.createTextNode(" ");
    EndTime.appendChild(EndTime_text);

    //任务执行的进度百分比。
    QDomElement ProcessPercent = doc.createElement("ProcessPercent");
    root.appendChild(ProcessPercent);
    QDomText ProcessPercent_text = doc.createTextNode(" ");
    ProcessPercent.appendChild(ProcessPercent_text);

    //任务执行的返回代码
    QDomElement ReturnCode = doc.createElement("ReturnCode");
    root.appendChild(ReturnCode);
    QDomText ReturnCode_text = doc.createTextNode(" ");
    ReturnCode.appendChild(ReturnCode_text);

    //任务状态
    QDomElement TaskStatus = doc.createElement("TaskStatus");
    root.appendChild(TaskStatus);
    QDomText TaskStatus_text = doc.createTextNode(" ");
    TaskStatus.appendChild(TaskStatus_text);

    //存放查询状态或设置参数的结果
    QDomElement ScaleResults = doc.createElement("ScaleResults");
    root.appendChild(ScaleResults);
        QDomElement ScaleResult = doc.createElement("ScaleResult");
        ScaleResults.appendChild(ScaleResult);
            QDomElement ScaleResult_DeviceID = doc.createElement("DeviceID");
            ScaleResult.appendChild(ScaleResult_DeviceID);
            QDomText ScaleResult_DeviceID_text = doc.createTextNode(" ");
            ScaleResult_DeviceID.appendChild(ScaleResult_DeviceID_text);

            QDomElement ScaleResult_ScaleNo = doc.createElement("ScaleNo");
            ScaleResult.appendChild(ScaleResult_ScaleNo);
            QDomText ScaleResult_ScaleNo_text = doc.createTextNode(" ");
            ScaleResult_ScaleNo.appendChild(ScaleResult_ScaleNo_text);

            QDomElement ScaleResult_ScaleType = doc.createElement("ScaleType");
            ScaleResult.appendChild(ScaleResult_ScaleType);
            QDomText ScaleResult_ScaleType_text = doc.createTextNode(" ");
            ScaleResult_ScaleType.appendChild(ScaleResult_ScaleType_text);

            QDomElement ScaleResult_StartTime = doc.createElement("StartTime");
            ScaleResult.appendChild(ScaleResult_StartTime);
            QDomText ScaleResult_StartTime_text = doc.createTextNode(" ");
            ScaleResult_StartTime.appendChild(ScaleResult_StartTime_text);

            QDomElement ScaleResult_EndTime = doc.createElement("EndTime");
            ScaleResult.appendChild(ScaleResult_EndTime);
            QDomText ScaleResult_EndTime_text = doc.createTextNode(" ");
            ScaleResult_EndTime.appendChild(ScaleResult_EndTime_text);

            QDomElement ScaleResult_ReturnCode = doc.createElement("ReturnCode");
            ScaleResult.appendChild(ScaleResult_ReturnCode);
            QDomText ScaleResult_ReturnCode_text = doc.createTextNode(" ");
            ScaleResult_ReturnCode.appendChild(ScaleResult_ReturnCode_text);

            QDomElement ScaleResult_ProcessPercent = doc.createElement("ProcessPercent");
            ScaleResult.appendChild(ScaleResult_ProcessPercent);
            QDomText ScaleResult_ProcessPercent_text = doc.createTextNode(" ");
            ScaleResult_ProcessPercent.appendChild(ScaleResult_ProcessPercent_text);

            QDomElement ScaleResult_TaskStatus = doc.createElement("TaskStatus");
            ScaleResult.appendChild(ScaleResult_TaskStatus);
            QDomText ScaleResult_TaskStatus_text = doc.createTextNode(" ");
            ScaleResult_TaskStatus.appendChild(ScaleResult_TaskStatus_text);

            QDomElement ScaleResult_CommandResults = doc.createElement("CommandResults");
            ScaleResult.appendChild(ScaleResult_CommandResults);

                QDomElement CommandResult = doc.createElement("CommandResult");
                ScaleResult_CommandResults.appendChild(CommandResult);

                    QDomElement CommandID = doc.createElement("CommandID");
                    CommandResult.appendChild(CommandID);
                    QDomText CommandID_text = doc.createTextNode(" ");
                    CommandID.appendChild(CommandID_text);

                    QDomElement CommandText = doc.createElement("CommandText");
                    CommandResult.appendChild(CommandText);
                    QDomText CommandText_text = doc.createTextNode(" ");
                    CommandText.appendChild(CommandText_text);

                    QDomElement Control = doc.createElement("Control");
                    CommandResult.appendChild(Control);
                    QDomText Control_text = doc.createTextNode(" ");
                    Control.appendChild(Control_text);

                    QDomElement Command_TaskStatus = doc.createElement("TaskStatus");
                    CommandResult.appendChild(Command_TaskStatus);
                    QDomText Command_TaskStatus_text = doc.createTextNode(" ");
                    Command_TaskStatus.appendChild(Command_TaskStatus_text);

                    QDomElement Command_StartTime = doc.createElement("StartTime");
                    CommandResult.appendChild(Command_StartTime);
                    QDomText Command_StartTime_text = doc.createTextNode(" ");
                    Command_StartTime.appendChild(Command_StartTime_text);

                    QDomElement Command_EndTime = doc.createElement("EndTime");
                    CommandResult.appendChild(Command_EndTime);
                    QDomText Command_EndTime_text = doc.createTextNode(" ");
                    Command_EndTime.appendChild(Command_EndTime_text);

                    QDomElement Command_ProcessPercent = doc.createElement("ProcessPercent");
                    CommandResult.appendChild(Command_ProcessPercent);
                    QDomText Command_ProcessPercent_text = doc.createTextNode(" ");
                    Command_ProcessPercent.appendChild(Command_ProcessPercent_text);

                    QDomElement Succeeded = doc.createElement("Succeeded");
                    CommandResult.appendChild(Succeeded);
                    QDomText Succeeded_text = doc.createTextNode(" ");
                    Succeeded.appendChild(Succeeded_text);

                    QDomElement Failed = doc.createElement("Failed");
                    CommandResult.appendChild(Failed);
                    QDomText Failed_text = doc.createTextNode(" ");
                    Failed.appendChild(Failed_text);

                    QDomElement Total = doc.createElement("Total");
                    CommandResult.appendChild(Total);
                    QDomText Total_text = doc.createTextNode(" ");
                    Total.appendChild(Total_text);

                    QDomElement Command_ReturnCode = doc.createElement("ReturnCode");
                    CommandResult.appendChild(Command_ReturnCode);
                    QDomText Command_ReturnCode_text = doc.createTextNode(" ");
                    Command_ReturnCode.appendChild(Command_ReturnCode_text);

    MTScaleXML scaleXML;
    scaleXML.createXML(doc, fileName);
}

//读取返回文件
QString MTScaleXML::ceadTaskResult()
{
    QDomDocument doc;
    QFile *file = new QFile("C:/TaskResult.xml");
    if (!file->open(QIODevice::ReadOnly))
    {
        return "";
    }
    else
    {
        doc.setContent(file);
    }
    QDomNodeList taskStatus=doc.elementsByTagName("ReturnCode");
    return taskStatus.item(0).toElement().text();
}

//创建xml
void MTScaleXML::createXML(QDomDocument doc, QString fileName)
{
    QString m_sDocumentsPath = FilePathManage::instance()->getXMLPath()  + "Input/";
    m_sDocumentsPath = "C:/";
//    qDebug()<<m_sDocumentsPath;
    QFile file(m_sDocumentsPath + fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate |QIODevice::Text))
        return ;

    QTextStream out(&file);

    out.setCodec("UTF-8");

    doc.save(out,4,QDomNode::EncodingFromTextStream);

    file.close();

}
