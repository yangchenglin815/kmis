#include "KPosXMl.h"
#include <QDomDocument>
#include <QFile>
#include <QDebug>

KPosXMl* KPosXMl::m_pInstance = NULL;

KPosXMl::KPosXMl()
{
    readKPosXML();
}

KPosXMl *KPosXMl::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new KPosXMl;
    }
    return m_pInstance;
}

void KPosXMl::release()
{
    if (m_pInstance != NULL)
    {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

void KPosXMl::readKPosXML()
{
    QDomDocument doc("KPosUIXML");

    QFile file("KPos800X600.xml");
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }

    if (!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement rootElement = doc.firstChildElement("KPosUIXML");
    QDomElement baseInfoElement = rootElement.firstChildElement("baseInfo");
    m_kPosXMLData.baseInfo.nSreenWidth = baseInfoElement.attribute("sreenWidth").toInt();
    m_kPosXMLData.baseInfo.nScreenHeight = baseInfoElement.attribute("screenHeight").toInt();
    QDomElement SaleWidgetElement = rootElement.firstChildElement("SaleWidget");
    m_kPosXMLData.saleWidget.topTitle.nHeight = SaleWidgetElement.firstChildElement("TopTitle").attribute("height").toInt();
    m_kPosXMLData.saleWidget.mainBody.nLeftSpace = SaleWidgetElement.firstChildElement("mainBody").attribute("leftSpace").toInt();
    m_kPosXMLData.saleWidget.mainBody.nRightSpace = SaleWidgetElement.firstChildElement("mainBody").attribute("rightSpace").toInt();
    m_kPosXMLData.saleWidget.mainBody.nTopSpace = SaleWidgetElement.firstChildElement("mainBody").attribute("topSpace").toInt();
    m_kPosXMLData.saleWidget.mainBody.nBottomSpace = SaleWidgetElement.firstChildElement("mainBody").attribute("bottomSpace").toInt();
    QDomElement saleWidgetMainBodyLeftWidget = SaleWidgetElement.firstChildElement("mainBody").firstChildElement("leftWidget");
    m_kPosXMLData.saleWidget.mainBody.leftWidget.nWidth = saleWidgetMainBodyLeftWidget.attribute("width").toInt();
    m_kPosXMLData.saleWidget.mainBody.leftWidget.topWidget.nHeight
            = saleWidgetMainBodyLeftWidget.firstChildElement("topWidget").attribute("height").toInt();
    m_kPosXMLData.saleWidget.mainBody.leftWidget.goodsSellListWidget.nTitleHeight
            = saleWidgetMainBodyLeftWidget.firstChildElement("goodsSellListWidget").attribute("titleHeight").toInt();
    m_kPosXMLData.saleWidget.mainBody.leftWidget.goodsSellListWidget.nBottomHeight
            = saleWidgetMainBodyLeftWidget.firstChildElement("goodsSellListWidget").attribute("bottomHeight").toInt();
    m_kPosXMLData.saleWidget.mainBody.leftWidget.bottomWidget.nHeight
            = saleWidgetMainBodyLeftWidget.firstChildElement("bottomWidget").attribute("height").toInt();
    QDomElement saleWidgetMainBodyMiddleWidget = SaleWidgetElement.firstChildElement("mainBody").firstChildElement("middleWidget");
    m_kPosXMLData.saleWidget.mainBody.middleWidget.nWidth = saleWidgetMainBodyMiddleWidget.attribute("width").toInt();
    QDomElement saleWidgetMainBodyRightWidget = SaleWidgetElement.firstChildElement("mainBody").firstChildElement("rightWidget");
    m_kPosXMLData.saleWidget.mainBody.rightWidget.nWidth = saleWidgetMainBodyRightWidget.attribute("width").toInt();

}


