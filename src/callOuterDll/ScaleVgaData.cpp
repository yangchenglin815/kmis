#include "ScaleVgaData.h"

ScaleVgaData::ScaleVgaData():
    m_serialPort(new QSerialPort()),
    m_baudRate(9600),
    m_portName("com1")
{

}

QString ScaleVgaData::getScaleData()
{
    open();
    m_serialPort->write("$");
    QByteArray requestData = m_serialPort->readAll();

    QString request = requestData;


    return request;
}

void ScaleVgaData::setBaudRate(int baud)
{
    if(m_baudRate != baud){
         m_baudRate = baud;
         clear();
    }
}

void ScaleVgaData::setPortName(QString port)
{
    if(m_portName != port){
         m_portName = port;
         clear();
    }

}

//打开串口
bool ScaleVgaData::open()
{
    if (m_serialPort->isOpen())
    {
        return true;
    }
    m_serialPort->setPortName(m_portName);    //端口号
    m_serialPort->setBaudRate(m_baudRate);    //波特率
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
    return m_serialPort->open(QSerialPort::ReadWrite);

}

//关闭串口
void ScaleVgaData::close()
{
    if (m_serialPort->isOpen())
    {
        m_serialPort->close();
    }
}

//重启串口,清除数据
bool ScaleVgaData::clear()
{
    if (m_serialPort->isOpen())
    {
        m_serialPort->clear();
        this->close();
        return this->open();
    }
    return false;
}

//用来接收串口发来的数据
int ScaleVgaData::readData(char *buffer, int count, int timeout)
{
    int len = 0;
    forever
    {
        int n = m_serialPort->read(&buffer[len], count - len);
        if (n == -1)
        {
            return -1;
        }
        else if (n == 0 && !m_serialPort->waitForReadyRead(timeout))
        {
            return -2;
        }
        else
        {
            len += n;
            if (count == len)
                break;
        }
    }
    return len;
}

//发送数据到串口  比如发送协议
int ScaleVgaData::writeData(char *data, int size)
{


    int len = 0;
    forever
    {
        int n = m_serialPort->write(&data[len], size - len);
        if (n == -1)
        {
            return -1;
        }
        else
        {
            len += n;
            if (size == len)
                break;
        }
    }
    return len;
}



