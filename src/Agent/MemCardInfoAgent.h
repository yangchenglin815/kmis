#ifndef MEMCARDINFOAGENT_H
#define MEMCARDINFOAGENT_H

#include <QObject>
#include <QMap>
#include "httpstructdata.h"

class MemCardInfoAgent : public QObject
{
    Q_OBJECT
public:
    static MemCardInfoAgent* instance();

    void memTypeListRequest();
    void memGradeListRequest();
    void getOPeratorListRequest();
    void memQueryRequest( QString strMemCardId );
    void memQueryForRefundRequest(QString strMemCardId);
    void memRechargeRequest(QString strMemCardId, QString strRechargeAmt, int nPayMethod, int nOperatorId, QString strPayCode, bool bVirtual);
    void memRechargeStatusRequest( int nPayMethod, QString strRechargeOrderNum );
    void memRegisterRequest( MemRegisterInfo_s stMemRegister );
    void memPwdModifyRequest( QString strCardId, QString strOldPwd, QString strNewPwd );
    void replaceMemCardRequest( QString strOldCardId, QString strNewCardId );
    void memSetStatusRequest( QString strCardId, int nStatus );
    /**
     * @brief printMemRechargeReceipt
     * @param strSequence 充值流水号
     * @param stMemInfo   会员信息
     * @param strRechargeAmt  充值金额
     * @param strPayMethod 支付方式
     */
    void printMemRechargeReceipt( QString strSequence, MemRegisterInfo_s stMemInfo, QString strRechargeAmt, QString strGiftAmt, QString strPayMethod);//打印会员充值小票
    //插入会员充值表
    void insertMemRechargeTable(QString strCardNo, QString strRechargeAmt, QString strGiftAmt, int nGiftIntegral, EPayMethod ePayMethod, int nUserId, QString strPayCode, int nStatus );
    void deleteMemReChargeDetailsTable( int nSaveDay );

signals:
    void sigOnMemInfoQuery( int nCode, QString sMsg, MemRegisterInfo_s stMemRegInfo );
    void sigOnMemInfoQueryForRefund(int nCode, QString sMsg, MemRegisterInfo_s stMemRegInfo);
    void sigOnMemRecharge( int nCode, QString sMsg, QString strCardNo, QString strAccountBalance, QString strTradeNo, int nIntegral, QString strGiftAmt );
    void sigOnGetPayStatus( int nCode, QString sMsg, QString strOrderNumS, int nTradeState );
    void sigOnMemRegister( int nCode, QString strMsg, QString strCardNo, int nStatus, MemRegisterInfo_s stMemRegisterInfo );
    void sigOnMemPwdModify( int nCode, QString sMsg, QString strCardNo, int nStatus );
    void sigOnMemStatus( int nCode, QString sMsg, QString strCardNo, int nCardStatus );
    void sigOnReplaceMemCard(int nCode, QString sMsg, QString strOldCardId, QString strNewCardId );
    void sigOnMemTypeList( int nCode, QString sMsg, QList<MemGradeInfo_s> listMemGrade );
    void sigOnOperatorList( int nCode, QString sMsg, QList<OperatorInfo_s> listOperator );
public slots:
    void slot_memTypeList(int nCode, QString sMsg, QList<MemTypeInfo_s> listMemType );
    void slot_memGradeList( int nCode, QString sMsg, QList<MemGradeInfo_s> listMemGrade );
private:
    explicit MemCardInfoAgent();

    void initConnect();
private:
    static MemCardInfoAgent *m_pMemCardInfoAgent;
    QMap<int, MemTypeInfo_s> m_mapMemTypeInfo;
};

#endif // MEMCARDINFOAGENT_H
