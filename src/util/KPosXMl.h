#ifndef KPOSXML_H
#define KPOSXML_H

#include "../data/xmlstructdata.h"

class KPosXMl
{
public:
    static KPosXMl* instance();
    void release();

private:
    KPosXMl();
    void readKPosXML();

public:
     KPosXMLData m_kPosXMLData;

private:
    static KPosXMl* m_pInstance;
};

#endif // KPOSXML_H
