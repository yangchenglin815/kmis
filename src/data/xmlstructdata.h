#ifndef XMLSTRUCTDATA_H
#define XMLSTRUCTDATA_H

#include <QString>

struct BaseInfoXml
{
    int nSreenWidth;
    int nScreenHeight;
};

struct SaleWidget_TopTitle
{
    int nHeight;
};

struct SaleWidget_mainBody_leftWidget_topWidget
{
    int nHeight;
};

struct SaleWidget_mainBody_leftWidget_goodsSellListWidget
{
    int nTitleHeight;
    int nBottomHeight;
};

struct SaleWidget_mainBody_leftWidget_bottomWidget
{
    int nHeight;
};

struct SaleWidget_mainBody_leftWidget
{
    int nWidth;
    SaleWidget_mainBody_leftWidget_topWidget topWidget;
    SaleWidget_mainBody_leftWidget_goodsSellListWidget goodsSellListWidget;
    SaleWidget_mainBody_leftWidget_bottomWidget bottomWidget;
};

struct SaleWidget_mainBody_middleWidget
{
    int nWidth;
};

struct SaleWidget_mainBody_rightWidget
{
    int nWidth;
};

struct SaleWidget_mainBody
{
    int nTopSpace;
    int nBottomSpace;
    int nLeftSpace;
    int nRightSpace;
    int nMiddleSpace;
    SaleWidget_mainBody_leftWidget leftWidget;
    SaleWidget_mainBody_middleWidget middleWidget;
    SaleWidget_mainBody_rightWidget rightWidget;
};

struct SaleWidgetXml
{
    SaleWidget_TopTitle topTitle;
    SaleWidget_mainBody mainBody;
};

struct KPosXMLData
{
    BaseInfoXml baseInfo;
    SaleWidgetXml saleWidget;
};

#endif // XMLSTRUCTDATA_H
