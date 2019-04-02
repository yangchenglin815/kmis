#ifndef POSDB_H
#define POSDB_H

#include "SalesmanInfoTable.h"
#include "CategoryTable.h"
#include "ClientCashSubmitTable.h"
#include "GoodsInfoTable.h"
#include "SaleHeadTable.h"
#include "SaleDetailsTable.h"
#include "PayDetailsTable.h"
#include "MemRechargeDetailsTable.h"
#include "LoginRecordTable.h"
#include "worddlltable.h"

class PosDB
{
public:
    PosDB();

public:
    SalesmanInfoTable* m_pSalesmanInfoTable;
    CategoryTable* m_pCategoryTable;
    ClientCashSubmitTable* m_pClientCashSubmitTable;
    GoodsInfoTable* m_pGoodsInfoTable;
    SaleHeadTable *m_pSaleHeadTable;
    SaleDetailsTable *m_pSaleDetailsTable;
    PayDetailsTable *m_pPayDetailsTable;
    MemRechargeDetailsTable *m_pMemRechargeDetailsTable;
    LoginRecordTable *m_pLoginRecordTable;
    WordDllTable* m_wordDllTabel;
};

#endif // POSDB_H
