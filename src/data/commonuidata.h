#ifndef COMMONUIDATA_H
#define COMMONUIDATA_H

#include <QVariant>

struct StrInfo
{
    QString sText;
    bool bDrawLine;
};
Q_DECLARE_METATYPE(StrInfo)

struct CalendarInfo
{
    int nDay;
};
Q_DECLARE_METATYPE(CalendarInfo)

#endif // COMMONUIDATA_H
