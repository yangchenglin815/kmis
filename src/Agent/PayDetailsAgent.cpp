#include "PayDetailsAgent.h"
#include "PosDBFactory.h"

PayDetailsAgent *PayDetailsAgent::m_pInstance = NULL;

PayDetailsAgent::PayDetailsAgent( QObject *parent )
    : QObject(parent)
{

}

PayDetailsAgent::~PayDetailsAgent()
{

}

PayDetailsAgent *PayDetailsAgent::Instance()
{
    if( m_pInstance == NULL ) {
        m_pInstance = new PayDetailsAgent();
    }

    return m_pInstance;
}

void PayDetailsAgent::Release()
{
    if( m_pInstance ) {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

void PayDetailsAgent::insertData( PayDetail_s &stPayDetails )
{
    PosDBFactory::getPosDB()->m_pPayDetailsTable->insertPayDetails( stPayDetails );
}

void PayDetailsAgent::updateData( QString strPayOrderNum, QString strPayOrderNumS, EPaymentState ePayStatus, QDateTime dtComplete )
{
    PosDBFactory::getPosDB()->m_pPayDetailsTable->updateData( strPayOrderNum, strPayOrderNumS, ePayStatus, dtComplete );
}

void PayDetailsAgent::findData( QString strPayOrderNumS, PayDetail_s &stPayDetails )
{
    PosDBFactory::getPosDB()->m_pPayDetailsTable->findData( strPayOrderNumS, stPayDetails );
}

void PayDetailsAgent::findData( QString strOrderNum, QList<PayDetail_s> &listPayDetails )
{
    PosDBFactory::getPosDB()->m_pPayDetailsTable->findData( strOrderNum, listPayDetails );
}

void PayDetailsAgent::deletePayDetailsTable( QString strOrderNum )
{
    PosDBFactory::getPosDB()->m_pPayDetailsTable->deleteData( strOrderNum );
}
