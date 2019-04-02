#ifndef ENUMTOSTRING_H
#define ENUMTOSTRING_H

#include <QString>
#include "enumData.h"

class EnumToString
{
public:
    static QString keySetTypeToString(int type);
    static QString recieveGoodsStateToString(int type);
    static QString stockingTypeToString(int type); // 盘点类型
    static QString stockingStateToString(int type); // 盘点状态
    static QString stockSateToString(int type); // 盘点状态
    static QString adjustPriceStateToString(int type); // 调价状态
    static QString orderCardTypeToString(int type);
    static QString bcsLinkStateToString(int type); // 条码秤连接状态
    static QString bcsSendDownState(int type); // 条码秤下发状态

    static QString sexToString( int nSex );
    static QString payMethodToString(int nPayMethod);
    static EPayMethod payMethodToEnum( QString strPayMethod );
    static QString documentTypeToString( EDocumentType eDocumentType );
    static EDocumentType documentTypeToInt(QString strDocumentType );
    static EDropType dropTypeToInt(QString strDropType);
    static QString dropTypeToString(int nDropType);
};

#endif // ENUMTOSTRING_H
