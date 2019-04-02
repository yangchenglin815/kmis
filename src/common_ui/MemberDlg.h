#ifndef MEMBERDLG_H
#define MEMBERDLG_H

#include <QDialog>
#include <QLineEdit>
#include "httpstructdata.h"
#include "enumData.h"
#include "PayMethodButton.h"
#include "httpstructdata.h"
#include "MemChargeDialog.h"
#include "BirthdayCalendarDlg.h"

namespace Ui {
class MemberDlg;
}

class MemberDlg : public QDialog
{
    Q_OBJECT

public:
    explicit MemberDlg(QWidget *parent = 0);
    ~MemberDlg();

    void initData();
    //会员充值
    void setMemRechargeMethod(QList<PayWayInfoSet> listMemRechargeMethod );
    void setMemRegInfo( MemRegisterInfo_s stMemRegInfo );
    void clearData();

protected:
    void keyPressEvent(QKeyEvent *event);
    void showEvent(QShowEvent *);

signals:
    void sig_memInfo( MemRegisterInfo_s stMemRegInfo );
    void sig_replaceMemCard( QString strOldCardId, QString strNewCardId );
private:
    void initCtrl();
    void initConnect();
    void initQueryWnd();
    void initRechargeWnd();
    void initDocumentType();
    void initResigterWnd();
    void initPwdModify();
    void initPayMethodButton();
    void initICReadCard();
    void initPayMethod();

    void firstClick();
    bool getCurFocusWnd( QLineEdit *&pEditWnd );
    int findDecimalsNum();
    bool findPoint();
    void setHundredButtonEnabled( bool bEnabled );
    void setMemQueryButtonEnabled( bool bEnabled );
    int memTypeToInt( QString strMemType );
    int memGradeToInt( QString strMemGrade );//会员等级
    int getOperatorId( QString strOPeratorName );
    void clearMemfunBtn();//清除会员功能按钮
    void updateMemQueryWnd( const MemRegisterInfo_s &stMemRegInfo );
    void updateMemRechargeWnd( const MemRegisterInfo_s &stMemRegInfo );
    void updateDataBtn( bool bShow );
private slots:
    void slot_closeWnd();
    void slot_showMemQueryWnd();
    void slot_showMemRechargeWnd();
    void slot_showMemRegisterWnd();
    void slot_showModifyPasswdWnd();

    void slot_memConsume();//会员消费
    void slot_memSwingCard();//刷卡
    void slot_memCardLoss();//挂失

    void slot_recharge();//充值
    void slot_readCard();//读卡
    void slot_pwdModifyCommit();//密码修改提交

    //注册时间
    void slot_sex();
    void slot_memTypeChanged( QString strMemType );
    void slot_commitReg();//注册提交
    void slot_documentTypeIndexChange( QString strText );//证件类型

    void slot_setText( QString strText );
    void slot_deleteValue();
    void slot_clearZero();
    void slot_enter();

    void slot_hundred();
    void slot_twoHundred();
    void slot_threeHundred();
    void slot_fiveHundred();

    void slot_memInfoQuery( int nCode, QString sMsg, MemRegisterInfo_s stMemRegInfo );
    void slot_memCardStatus( int nCode, QString sMsg, QString strCardNo, int nCardStatus );
    void slot_memRecharge(int nCode, QString sMsg, QString strCardNo, QString strAccountBalance, QString strTradeNo , int nIntegral, QString strGiftAmt);
    void slot_memRegister( int nCode, QString sMsg, QString strCardNo, int nStatus , MemRegisterInfo_s stMemRegisterInfo);
    void slot_memPwdModify( int nCode, QString sMsg, QString strCardNo, int nStatus );

    //查询界面
    void slot_operatorList( int nCode, QString sMsg, QList<OperatorInfo_s> listOperator );

    void slot_payMethodSelected();

    void slot_memTypeList(int nCode, QString sMsg, QList<MemGradeInfo_s> listMemGrade );
    void slot_curIndexChanged( int nIndex );

    //充值
    void slot_memChargeInfo( EPayMethod ePayMethod, QString strBarCode, QString strChargeAmt );
    void slot_refreshRecharge();
    //充值状态查询
    void slot_getRechargeStatus( int nCode, QString sMsg, QString strOrderNumS, int nTradeState );
    void slot_giftAmtChanged( QString strRechargeAmt );
    //换卡
    void slot_replaceMemCard( QString strOldCardId, QString strNewCardId );

    void slot_payInfoChanged();
    void slot_OnlineState( bool bOnline );//支付方式按钮状态
private:
    Ui::MemberDlg *ui;

    bool m_bFirst;
    MemRegisterInfo_s m_stMemRegInfo;

    QList<QPushButton*> m_listMemTypeBtn;
    QList<PayMethodButton*> m_listPayMethodBtn;
    QList<PayWayInfoSet> m_listPayInfo;//支付方式列表
    PayWayInfoSet m_stCurPayInfo;
    int m_nOperatorId;//选择的操作员id

    QMap<int, MemTypeInfo_s> m_mapMemType;
    QList<MemGradeInfo_s> m_listMemGrade;
    QMap<int, OperatorInfo_s> m_mapOperatorInfo;//业务员信息 key：id
    ESex m_eSex;

    MemChargeDialog *m_pMemCharge;
    QString m_sOrderRechargeCode;//内部定义的充值码
    bool m_bMemLogin;//会员登录
    bool m_bOnline;
};

#endif // MEMBERDLG_H
