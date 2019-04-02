#include "NumberLineEdit.h"
#include <QDebug>

NumberLineEdit::NumberLineEdit(QWidget *parent)
    : QLineEdit(parent)
    , m_nReservePoint(2)
{

}

void NumberLineEdit::setNumberText(QString numText)
{
    bool bIsNumber = false;
    if (numText.contains("."))
    {
        qDebug()<<numText.toDouble(&bIsNumber);
    }
    else
    {
        qDebug()<<numText.toInt(&bIsNumber);
    }
    qDebug()<<bIsNumber;
    if (!bIsNumber)
    {
        return;
    }

    QStringList strList = numText.split(".");
    QString sLeftNum = strList[0];
    QString sRightNum = "0";
    if (strList.size() >= 2)
    {
        sRightNum = strList[1];
    }

    QString sDesNum = "";
    if (m_nReservePoint == 0)
    {
        sDesNum = sLeftNum;
    }
    else if (m_nReservePoint == 1)
    {
        sDesNum = sLeftNum + "." + sRightNum.append("0").left(1);
    }
    else if (m_nReservePoint == 2)
    {
        sDesNum = sLeftNum + "." + sRightNum.append("00").left(2);
    }

    qDebug()<<"sDesNum -- "<<sDesNum;
    this->setText(sDesNum);
}

void NumberLineEdit::appendNumberText(QString numText)
{
    QString sOldText = this->text();
    bool bContainsPoint = sOldText.contains(".");
    if (numText == ".")
    {
        if (bContainsPoint || sOldText.isEmpty())
        {
            return;
        }
        else if (m_nReservePoint > 0)
        {
            this->setText(sOldText.append(numText));
        }
        return;
    }
    else
    {
        if (bContainsPoint)
        {
            QStringList strList = sOldText.split(".");
            QString sLeftNum = strList[0];
            QString sRightNum = strList[1];
            if (sRightNum.length() < m_nReservePoint)
            {
                sRightNum.append(numText);
                QString sDesNum = sLeftNum + "." + sRightNum;
                this->setText(sDesNum);
                return;
            }
        }
        else
        {
            this->setText(sOldText.append(numText));
            return;
        }
    }
}

void NumberLineEdit::setReservePoint(int nReservPoint)
{
    m_nReservePoint = nReservPoint;
}

