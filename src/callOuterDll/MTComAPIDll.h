#ifndef MTCOMAPIDLL_H
#define MTCOMAPIDLL_H

#include <QWidget>
#include "windows.h"
#include "../data/ebalancedata.h"

class MTComAPIDll : public QWidget
{
    Q_OBJECT
public:
    static void openMTCom();
    static void closeMTCom();
    static void readWeight(EBalanceStandard_Ex &balanceStandard_Ex);
    static bool isOpen();

private:
    static HANDLE m_handle;
};

#endif // MTCOMAPIDLL_H
