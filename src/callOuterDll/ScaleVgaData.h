#ifndef SCALEVGADATA_H
#define SCALEVGADATA_H
#include <QtSerialPort/QtSerialPort>


class ScaleVgaData
{
public:
    ScaleVgaData();
    QString getScaleData();
    void setBaudRate(int baud);
    void setPortName(QString port);

private:
    QSerialPort *m_serialPort;
    int m_baudRate;//码率
    QString m_portName;//端口名称

private:
    bool open();

    void close();
    bool clear();

    int readData(char *buffer, int count, int timeout);
    int writeData(char *data, int size);
};

#endif // SCALEVGADATA_H
