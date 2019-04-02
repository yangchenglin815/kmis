#include "MemberDlg.h"
#include "ui_MemberDlg.h"
#include "MemCardInfoAgent.h"
#include "DlgCommon.h"
#include "SatementAgent.h"
#include "mwrf32.h"
#include <qDebug>
#include "EnumToString.h"
#include "CommonFun.h"
#include <QRegExp>
#include <QRegExpValidator>
#include "KPosSetAgent.h"
#include "OnlineStateAgent.h"
#include "KPosServerIni.h"
#include "KPosLog.h"

MemberDlg::MemberDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MemberDlg)
    , m_bFirst( true )
    , m_nOperatorId( -1 )
    , m_eSex( e_nullSex )
    , m_pMemCharge( NULL )
    , m_sOrderRechargeCode( "" )
    , m_bMemLogin( false )
    , m_bOnline( true )
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    setModal( false );
    setWindowTitle( "会员" );

    initCtrl();
//    initData();
    initPayMethodButton();
    initPayMethod();
    initConnect();
    slot_payInfoChanged();//会员支付方式初始化

    bool bOnline = OnlineStateAgent::instance()->isOnline();
    slot_OnlineState( bOnline );

    int nUserType = KPosServerIni::getKPosUserType();
    if (nUserType == e_tianMaoVersion)
    {
        ui->memRechargeButton->setEnabled( false );
        ui->memRegisterButton->setEnabled( false );
        ui->modifyPasswdButton->setEnabled( false );
    }
    else if (nUserType == e_commonVersion)
    {
        // 什么也不做
    }
}

MemberDlg::~MemberDlg()
{
    delete ui;
}

void MemberDlg::initData()
{
    m_bFirst = true;
    slot_showMemQueryWnd();

    initQueryWnd();
    initRechargeWnd();
    initResigterWnd();
    initPwdModify();

    MemCardInfoAgent::instance()->memTypeListRequest();
    //MemCardInfoAgent::instance()->memGradeListRequest();
    MemCardInfoAgent::instance()->getOPeratorListRequest();

    MemRegisterInfo_s stMemRegInfo;
    m_stMemRegInfo = stMemRegInfo;

    updateDataBtn( false );
}

void MemberDlg::initPayMethod()
{
    m_listPayInfo.clear();
    PayWayInfoSet stPayWayInfo;
    stPayWayInfo.nPayType = PayCash;
    m_listPayInfo.append( stPayWayInfo );
//    stPayWayInfo.nPayType = UnionPay;
//    m_listPayInfo.append( stPayWayInfo );
//    stPayWayInfo.nPayType = PayMemCard;
//    m_listPayInfo.append( stPayWayInfo );
    stPayWayInfo.nPayType = PayStoreCard;
    m_listPayInfo.append( stPayWayInfo );
    stPayWayInfo.nPayType = PayAlipay;
    m_listPayInfo.append( stPayWayInfo );
    stPayWayInfo.nPayType = PayWeChat;
    m_listPayInfo.append( stPayWayInfo );
    stPayWayInfo.nPayType = ApplePay;
    m_listPayInfo.append( stPayWayInfo );
    stPayWayInfo.nPayType = JdWallet;
    m_listPayInfo.append( stPayWayInfo );

    setMemRechargeMethod( m_listPayInfo );
}

//支付方式配置
void MemberDlg::setMemRechargeMethod( QList<PayWayInfoSet> listMemRechargeMethod )
{
    initPayMethodButton();
    //正常图片，选中图片，Recharge方式，
    QList<PayWayInfoSet>::iterator it = listMemRechargeMethod.begin();
    QList<PayMethodButton*>::iterator itPay = m_listPayMethodBtn.begin();
    for( ; it != listMemRechargeMethod.end(); ++it ) {
        (*itPay)->setPayInfo( *it );

        ++itPay;
        if( itPay == m_listPayMethodBtn.end() ) break;
    }

    if( listMemRechargeMethod.size() == 0 ) return;
    itPay = m_listPayMethodBtn.begin();
    m_stCurPayInfo = (*itPay)->getPayInfo();
    (*itPay)->setPayBtnSelected();
}

void MemberDlg::setMemRegInfo( MemRegisterInfo_s stMemRegInfo )
{
    m_stMemRegInfo = stMemRegInfo;
    if( m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) {
        ui->cardIDQueryEdit->setEnabled( true );
        m_bMemLogin = false;
        initData();
        return;
    } else {
        initRechargeWnd();
        initResigterWnd();
        initPwdModify();

        updateMemQueryWnd( m_stMemRegInfo );

        ui->cardIDQueryEdit->setEnabled( false );
        m_bMemLogin = true;
        //ui->readCardQueryButton->setEnabled( false );
        //ui->reportLossQueryButton->setEnabled( false );
    }
}

void MemberDlg::clearData()
{
    ui->warningLabel->clear();
}

void MemberDlg::keyPressEvent(QKeyEvent *event)
{
    if ((event->key() == Qt::Key_Return) || (event->key() == Qt::Key_Enter))
    {
        slot_enter();
    }
}

void MemberDlg::initCtrl()
{
    ui->titleWidget->setTitleText( "会员" );
    ui->stackedWidget->setCurrentIndex( 0 );
    setMemQueryButtonEnabled( false );

    m_listPayMethodBtn.append( ui->payRecButton_01 );
    m_listPayMethodBtn.append( ui->payRecButton_02 );
    m_listPayMethodBtn.append( ui->payRecButton_03 );
    m_listPayMethodBtn.append( ui->payRecButton_04 );
    m_listPayMethodBtn.append( ui->payRecButton_05 );
    m_listPayMethodBtn.append( ui->payRecButton_06 );

    m_listMemTypeBtn.append( ui->memQueryButton );
    m_listMemTypeBtn.append( ui->memRechargeButton );
    m_listMemTypeBtn.append( ui->memRegisterButton );
    m_listMemTypeBtn.append( ui->modifyPasswdButton );


    QRegExp regx("1[0-9]{10}");
    QRegExpValidator *pReg = new QRegExpValidator( regx, this);
    ui->phoneRegEdit->setValidator( pReg );

    QRegExp regPwd("[0-9]{6}" );
    QRegExpValidator *pRegPwd = new QRegExpValidator( regPwd, this);
    ui->payPasswdRegEdit->setValidator( pRegPwd );
    ui->oldPasswdPwdEdit->setValidator( pRegPwd );
    ui->newPasswdPwdEdit->setValidator( pRegPwd );
    ui->confirmNewpasswdPwdEdit->setValidator( pRegPwd );

//    QRegExp regDocument("[0-9X]{18}");
//    QRegExpValidator *pRegDocument = new QRegExpValidator( regDocument, this);
//    ui->documentIdRegEdit->setValidator( pRegDocument );

    QRegExp regRecharge("[1-9][0-9]{8}");
    QRegExpValidator *pRegRecharge = new QRegExpValidator( regRecharge, this);
    ui->amtChargeRecEdit->setValidator( pRegRecharge );
    ui->giftAmtRecEdit->setValidator( pRegRecharge );
    ui->giftAmtRecEdit->setEnabled( false );

    ui->nameWidget->hideKeyboardButton();
    ui->nameWidget->setHolderText("");
    ui->nameWidget->setOuterLineColor();
}

void MemberDlg::initConnect()
{
    connect( ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT( slot_closeWnd() ) );

    connect( ui->memQueryButton, SIGNAL( clicked()), this, SLOT( slot_showMemQueryWnd() ) );
    connect( ui->memRechargeButton, SIGNAL( clicked()), this, SLOT( slot_showMemRechargeWnd() ) );
    connect( ui->memRegisterButton, SIGNAL( clicked()), this, SLOT( slot_showMemRegisterWnd() ) );
    connect( ui->modifyPasswdButton, SIGNAL( clicked()), this, SLOT( slot_showModifyPasswdWnd() ) );

    //数字键盘
    connect( ui->DigitalKeyWnd, SIGNAL( sigText(QString)), this, SLOT( slot_setText(QString) ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigDelete()), this, SLOT( slot_deleteValue() ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigClear()), this, SLOT( slot_clearZero() ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigConfirm()), this, SLOT( slot_enter()) );

    //百
    connect( ui->hundredButton, SIGNAL(clicked()), this, SLOT( slot_hundred() ) );
    connect( ui->twoHundredButton, SIGNAL(clicked()), this, SLOT( slot_twoHundred() ) );
    connect( ui->threeHundredButton, SIGNAL(clicked()), this, SLOT( slot_threeHundred() ) );
    connect( ui->fiveHundredButton, SIGNAL(clicked()), this, SLOT( slot_fiveHundred() ) );

    connect( MemCardInfoAgent::instance(), SIGNAL(sigOnMemRecharge(int,QString,QString,QString,QString,int,QString)) \
             , this, SLOT( slot_memRecharge(int,QString,QString,QString,QString,int,QString) ) );
    connect( MemCardInfoAgent::instance(), SIGNAL(sigOnMemRegister(int,QString,QString,int, MemRegisterInfo_s)) \
             , this, SLOT( slot_memRegister(int,QString,QString,int, MemRegisterInfo_s)) );
    connect( MemCardInfoAgent::instance(), SIGNAL(sigOnMemPwdModify(int,QString,QString,int)) \
             , this, SLOT( slot_memPwdModify( int,QString,QString,int ) ) );

    //支付方式
    QList<PayMethodButton*>::iterator it = m_listPayMethodBtn.begin();
    for( ; it != m_listPayMethodBtn.end(); ++it ) {
        connect( *it, SIGNAL(clicked()), this, SLOT( slot_payMethodSelected() ) );
    }

    //会员类型和会员等级列表
    connect( MemCardInfoAgent::instance(), SIGNAL(sigOnMemTypeList(int,QString,QList<MemGradeInfo_s>)) \
             , this, SLOT( slot_memTypeList(int,QString,QList<MemGradeInfo_s> ) ) );
    //connect( ui->memTypeRegBox, SIGNAL(currentIndexChanged(int)), this, SLOT( slot_curIndexChanged(int) ) );


    //会员查询界面按钮
    connect( ui->memConsumeQueryButton, SIGNAL(clicked()), this, SLOT( slot_memConsume() ) );
    //connect( ui->readCardQueryButton, SIGNAL(clicked()), this, SLOT( slot_memSwingCard() ) );
    //connect( ui->reportLossQueryButton, SIGNAL(clicked()), this, SLOT( slot_memCardLoss() ) );

    //connect( ui->swingCardButton, SIGNAL(clicked()), this, SLOT( slot_readCard() ) );
    connect( ui->rechargeConfireButton, SIGNAL(clicked()), this, SLOT( slot_recharge() ) );
    connect( ui->commitPwdButton, SIGNAL(clicked()), this, SLOT( slot_pwdModifyCommit() ) );
    connect( MemCardInfoAgent::instance(), SIGNAL(sigOnMemInfoQuery(int,QString,MemRegisterInfo_s)) \
             , this, SLOT( slot_memInfoQuery( int, QString, MemRegisterInfo_s ) ) );
    connect( MemCardInfoAgent::instance(), SIGNAL(sigOnMemStatus(int,QString,QString,int)) \
             , this, SLOT( slot_memCardStatus(int,QString, QString, int)) );
    connect( MemCardInfoAgent::instance(), SIGNAL(sigOnOperatorList(int,QString,QList<OperatorInfo_s>)) \
             , this, SLOT( slot_operatorList(int,QString, QList<OperatorInfo_s> ) ) );
//    connect( ui->cardIDQueryEdit, SIGNAL(sig_keyboardEnter()), this, SLOT( slot_enter() ) );

    //会员充值
    connect( MemCardInfoAgent::instance(), SIGNAL(sigOnGetPayStatus(int,QString,QString,int)) \
             , this, SLOT( slot_getRechargeStatus(int,QString,QString,int) ) );
    connect( ui->amtChargeRecEdit, SIGNAL(textChanged(QString)), this, SLOT( slot_giftAmtChanged(QString) ) );

    //会员注册
    connect( ui->manBtn, SIGNAL(clicked()), this, SLOT( slot_sex() ) );
    connect( ui->womanBtn, SIGNAL(clicked()), this, SLOT( slot_sex() ) );

    //connect( ui->memTypeRegBox, SIGNAL(currentIndexChanged(QString)), this, SLOT( slot_memTypeChanged(QString) ) );
    connect( ui->commitRegButton, SIGNAL(clicked()), this, SLOT( slot_commitReg() ) );
    //connect( ui->documentTypeRegBox, SIGNAL(currentIndexChanged(QString)), this, SLOT( slot_documentTypeIndexChange( QString ) ) );

    //换卡
    connect( MemCardInfoAgent::instance(), SIGNAL(sigOnReplaceMemCard(int,QString, QString,QString)) \
             , ui->replaceCardWidget, SLOT( slot_replaceMemCard( int, QString, QString, QString ) ) );
    connect( ui->replaceCardWidget, SIGNAL(sig_replaceMemCard(QString,QString)), this, SLOT( slot_replaceMemCard(QString,QString)) );
    connect( ui->replaceCardWidget, SIGNAL(sig_replaceQuest()), this, SLOT( slot_enter() ) );

    connect( KPosSetAgent::instance(), SIGNAL(sigPayWaySetChanged()), this, SLOT( slot_payInfoChanged() ) );
    connect( OnlineStateAgent::instance(), SIGNAL(sigOnlineState(bool)), this, SLOT( slot_OnlineState(bool) ) );
}

void MemberDlg::initQueryWnd()
{
    ui->cardIDQueryEdit->setText( "" );
    //ui->cardStatusLabel->setText( "" );
    ui->cardIDValueQueryLabel->setText( "" );
    ui->nameValueQueryLabel->setText( "" );
    ui->sexValueQueryLabel->setText( "" );
    ui->iphoneValueQueryLabel->setText( "" );
    ui->payPwdValueQueryLabel->setText( "" );
    ui->birthdayValueQueryLabel->setText( "" );
    //ui->documentTypeValueQueryLabel->setText( "" );
    //ui->documentIdValueQueryLabel->setText( "" );
    //ui->addressValueQueryLabel->setText( "" );
    //ui->memTypeValueQueryLabel->setText( "" );
    ui->memGradeValueQueryLabel->setText( "" );
    ui->balanceValueQueryLabel->setText( "￥0.00" );
    ui->integValueQueryLabel->setText( "0" );

    setMemQueryButtonEnabled( false );
}

void MemberDlg::initRechargeWnd()
{
    ui->CardIDValueRecLabel->setText( "" );
    ui->memNameValueRecLabel->setText( "" );
    ui->phoneValueRecLabel->setText( "" );
    ui->balanceValueRecLabel->setText( "" );
    ui->integValueRecLabel->setText( "" );
    ui->amtChargeRecEdit->setText( "" );
    ui->giftAmtRecEdit->setText( "" );
}

void MemberDlg::initDocumentType()
{
//    ui->documentTypeRegBox->clear();

//    ui->documentTypeRegBox->addItem( "请选择" );
//    ui->documentTypeRegBox->addItem( "身份证" );
//    ui->documentTypeRegBox->addItem( "军官证" );
//    ui->documentTypeRegBox->addItem( "护照");
//    ui->documentTypeRegBox->addItem( "学生证");
//    ui->documentTypeRegBox->addItem( "其他" );

//    ui->documentIdRegEdit->setText( "" );
//    ui->documentIdRegEdit->setEnabled( false );
}

void MemberDlg::initResigterWnd()
{
    initDocumentType();

    //ui->cardIDRegEdit->setText( "" );
    ui->nameWidget->setText( "" );
    ui->memRegisterButton->setText( "会员注册" );
    ui->warningRegLabel->setText( "" );

    m_eSex = e_man;
    switch( m_eSex ) {
    case e_nullSex:
        break;
    case e_man:
        ui->manBtn->setStyleSheet( "QPushButton{border-image: url(:/member/man_press.png);}");
        //m_eSex = e_nullSex;
        break;
    case e_woman:
        ui->womanBtn->setStyleSheet( "QPushButton{border-image: url(:/member/woman_normal.png);}");
        m_eSex = e_nullSex;
        break;
    default:
        m_eSex = e_nullSex;
        break;
    }

    ui->phoneRegEdit->setText( "" );
    ui->payPasswdRegEdit->setText( "" );
    ui->birthdayRegEdit->initData();
//    if( ui->documentTypeRegBox->count() > 0 ) {
//        ui->documentTypeRegBox->setCurrentIndex( 0 );
//    }
//    ui->documentIdRegEdit->setText( "" );
//    ui->addressRegEdit->setText( "" );
//    if( ui->memTypeRegBox->count() > 0 ) {
//        ui->memTypeRegBox->setCurrentIndex( 0 );
//    }
//    if( ui->memTypeRegBox->count() > 0 ) {
//        ui->memTypeRegBox->setCurrentIndex( 0 );
//    }
}

void MemberDlg::initPwdModify()
{
    ui->cardIDValuePwdLabel->setText( "" );
    ui->oldPasswdPwdEdit->setText( "" );
    ui->newPasswdPwdEdit->setText( "" );
    ui->confirmNewpasswdPwdEdit->setText( "" );
}

void MemberDlg::initPayMethodButton()
{
    PayWayInfoSet stPayInfo;
    QList<PayMethodButton*>::iterator it = m_listPayMethodBtn.begin();
    for( ; it != m_listPayMethodBtn.end(); ++it ) {
        (*it)->setPayInfo( stPayInfo );
        (*it)->hide();
    }
    m_stCurPayInfo = stPayInfo;
}

void MemberDlg::initICReadCard()
{
    ui->warningLabel->setText( "" );

    HANDLE icdev = NULL;
    QString	strKey = "796a6677686a";;//加密
    QString	m_Data;

    __int16 st;
    unsigned char _Status[30];
    memset(_Status,0,30);
    unsigned char Sec = 2;//扇区号
    unsigned __int16 TagType;
    unsigned long Snr;
    unsigned char Size;

    if( icdev != NULL ) {
        rf_exit(icdev);
        icdev = NULL;
    }
    icdev = rf_init( 0, 115200 );//初始化，设置端口和波特率
    st = rf_get_status(icdev,_Status);
    if(icdev == NULL || st) {
        ui->warningLabel->setText( "连接失败!" );
        return;
    }

    st = rf_reset(icdev,5 );//射频读写模块复位0002

    st = rf_request(icdev,1,&TagType);//寻卡模式
    if(st)
    {
        ui->warningLabel->setText( "寻卡失败!" );
        if( icdev != NULL ) {
            rf_exit(icdev);
            icdev = NULL;
        }
        return;
    }
    st = rf_anticoll(icdev,0, &Snr);//卡防冲突，返回卡的序列号
    if(st)
    {
        ui->warningLabel->setText( "防冲突失败!" );
        if( icdev != NULL ) {
            rf_exit(icdev);
            icdev = NULL;
        }
        return;
    }
    st = rf_select(icdev,Snr,&Size);
    if(st)
    {
        ui->warningLabel->setText( "选卡失败!" );
        if( icdev != NULL ) {
            rf_exit(icdev);
            icdev = NULL;
        }
        return;
    }
    unsigned char key[7];
    memset(key,0,7);

    a_hex( strKey.toLatin1().data(),key,12);
    strKey = "";
    unsigned char m_keymode;
    m_keymode = 0;
    st = rf_load_key(icdev,m_keymode,Sec,key);
    if(st)
    {
        ui->warningLabel->setText( "装载密码失败!" );
        if( icdev != NULL ) {
            rf_exit(icdev);
            icdev = NULL;
        }
        return;
    }

    st = rf_authentication(icdev,m_keymode,Sec);
    if(st)
    {
        ui->warningLabel->setText( "认证失败!" );
        if( icdev != NULL ) {
            rf_exit(icdev);
            icdev = NULL;
        }
        return;
    }

    unsigned char data[33];
    memset(data,0,33);

    unsigned char temp[33];
    memset(temp,0,33);

    for( int i =0; i < 3; ++i ) {
        memset(data,0,33);
        st = rf_read(icdev, Sec*4 + i,data);//_Adr：M1卡——块地址（0～63）；

        if(st)
        {
            ui->warningLabel->setText( "读数据失败!" );
            if( icdev != NULL ) {
                rf_exit(icdev);
                icdev = NULL;
            }
            return;
        }

        hex_a(data,(char*)temp,16);
        m_Data.sprintf("%s",temp);

        switch( i ) {
        case 0:
        {
            QString strText = "";
            for (int i = 0; i < 32; )
            {
                QString strOut = m_Data.mid(i,2);
                int nOu = strOut.toInt( 0, 16 );
                char cOut = (char)( nOu );
                qDebug() << "strOut"<<strOut<<nOu<<cOut;
                strText += QString("%1").arg( cOut );
                i = i + 2;
            }
            qDebug() << strText;

            ui->cardIDQueryEdit->setText( strText.trimmed() );
        }
            break;
        case 1:
            //ui->blockEdit_1->setText( m_Data );
            break;
        case 2:
            //ui->blockEdit_2->setText( m_Data );
            break;
        }
    }

    ui->warningLabel->setText( "读数据成功!" );

    if( icdev != NULL ) {
        rf_exit(icdev);
    }
}

void MemberDlg::firstClick()
{
    if( m_bFirst ) {
        QLineEdit *p_wnd = NULL;
        bool b_has_focus = getCurFocusWnd( p_wnd );
        if( !b_has_focus ) return;

        p_wnd->setText( "" );

        m_bFirst = false;
    }
}

void MemberDlg::setHundredButtonEnabled( bool bEnabled )
{
    ui->hundredButton->setEnabled( bEnabled );
    ui->twoHundredButton->setEnabled( bEnabled );
    ui->threeHundredButton->setEnabled( bEnabled );
    ui->fiveHundredButton->setEnabled( bEnabled );
}

void MemberDlg::setMemQueryButtonEnabled( bool bEnabled )
{
    ui->memConsumeQueryButton->setEnabled( bEnabled );
    //ui->readCardQueryButton->setEnabled( bEnabled );
    //ui->reportLossQueryButton->setEnabled( bEnabled );
}

bool MemberDlg::getCurFocusWnd( QLineEdit *&pEditWnd )
{
    pEditWnd = (QLineEdit*)focusWidget();
    if( ui->cardIDQueryEdit == pEditWnd
            || ui->amtChargeRecEdit == pEditWnd \
            || ui->giftAmtRecEdit == pEditWnd \
            || ui->phoneRegEdit == pEditWnd \
            || ui->payPasswdRegEdit == pEditWnd \
            || ui->oldPasswdPwdEdit == pEditWnd \
            || ui->newPasswdPwdEdit == pEditWnd \
            || ui->confirmNewpasswdPwdEdit == pEditWnd \
            || ui->birthdayRegEdit == pEditWnd ) {
        return true;
    }

    return false;
}

//默认为2位小数点
int MemberDlg::findDecimalsNum()
{
    QLineEdit *p_wnd = NULL;
    bool bWndFocus = getCurFocusWnd( p_wnd );
    if( !bWndFocus ) return -1;

    QString str_value = p_wnd->text();
    QStringList str_list = str_value.split( "." );
    if( str_list.size() == 2 ) {
        QString str_dec = str_list[1];
        return str_dec.length();
    }

    return 0;
}

bool MemberDlg::findPoint()
{
    QLineEdit *p_wnd = NULL;
    bool bWndHasFocus = getCurFocusWnd( p_wnd );
    if( !bWndHasFocus ) return true;

    QString str_point = p_wnd->text();
    for( int i = 0; i < str_point.length(); i++ ) {
        if( str_point[i] == '.' ) {
            return true;
        }
    }

    return false;
}

int MemberDlg::memTypeToInt( QString strMemType )
{
    int nMemType = -1;
    QMap<int, MemTypeInfo_s>::iterator it = m_mapMemType.begin();
    for( ; it != m_mapMemType.end(); ++it ) {
        if( it.value().strTypeName == strMemType ) {
            nMemType = it.key();
            break;
        }
    }
    return nMemType;
}

int MemberDlg::memGradeToInt( QString strMemGrade )
{
    int nMemGrade = -1;
//    QString strMemType;// = ui->memTypeRegBox->currentText();
//    QList<MemGradeInfo_s> listMemGrade;
//    QMap<int, MemTypeInfo_s>::iterator it = m_mapMemType.begin();
//    for( ; it != m_mapMemType.end(); ++it ) {
//        if( it.value().strTypeName == strMemType ) {
//            listMemGrade = it.value().listMemGrade;
//            break;
//        }
//    }

//    QList<MemGradeInfo_s>::iterator itGrade = listMemGrade.begin();
//    for( ; itGrade != listMemGrade.end(); ++itGrade ) {
//        if( itGrade->strLevelName == strMemGrade ) {
//            nMemGrade = itGrade->nId;
//            break;
//        }
//    }

    QList<MemGradeInfo_s>::iterator it = m_listMemGrade.begin();
    for( ; it != m_listMemGrade.end(); ++it ) {
        if( it->strLevelName == strMemGrade ) {
            nMemGrade = it->nId;
            break;
        }
    }

    return nMemGrade;
}

int MemberDlg::getOperatorId( QString strOPeratorName )
{
    int nOperatorId = -1;
    QMap<int, OperatorInfo_s>::iterator it = m_mapOperatorInfo.begin();
    for( ; it != m_mapOperatorInfo.end(); ++it ) {
        if( it->strName == strOPeratorName ) {
            nOperatorId = it.key();
            break;
        }
    }

    return nOperatorId;
}

void MemberDlg::clearMemfunBtn()
{
    QList<QPushButton*>::iterator it = m_listMemTypeBtn.begin();
    for( ; it != m_listMemTypeBtn.end(); ++it ) {
        (*it)->setStyleSheet( "QPushButton{border-image: url(:/member/tab.png);}");
    }
}

void MemberDlg::updateMemQueryWnd( const MemRegisterInfo_s &stMemRegInfo )
{
    initQueryWnd();

    ui->cardIDValueQueryLabel->setText( stMemRegInfo.stMemInfo.strCardNo );
    ui->nameValueQueryLabel->setText( stMemRegInfo.stMemInfo.strName );

    QString strSex = EnumToString::sexToString( stMemRegInfo.stMemInfo.nSex );
    ui->sexValueQueryLabel->setText( strSex );
    ui->iphoneValueQueryLabel->setText( stMemRegInfo.stMemInfo.strMobile.left(3) \
                                        + "****" + stMemRegInfo.stMemInfo.strMobile.right(4) );
    ui->payPwdValueQueryLabel->setText( "******" );
    ui->birthdayValueQueryLabel->setText( stMemRegInfo.stMemInfo.dtBirthday.toString( "yyyy.MM.dd"));

    //QString strDocumentType = EnumToString::documentTypeToString( stMemRegInfo.eDocumentType );
//    ui->documentTypeValueQueryLabel->setText( strDocumentType );
//    ui->documentIdValueQueryLabel->setText( stMemRegInfo.strDocumentNum );
//    ui->addressValueQueryLabel->setText( stMemRegInfo.strAddress );

    //会员等级
//    QMap<int, MemTypeInfo_s>::iterator it = m_mapMemType.find( stMemRegInfo.stMemInfo.nMemTypeId );
//    if( it != m_mapMemType.end() ) {
//        //ui->memTypeValueQueryLabel->setText( it->strTypeName );
//        QList<MemGradeInfo_s>::iterator itGrade = it->listMemGrade.begin();
//        for( ; itGrade != it->listMemGrade.end(); ++itGrade ) {
//            if( itGrade->nId == stMemRegInfo.stMemInfo.nMemLevelId ) {
//                ui->memGradeValueQueryLabel->setText( itGrade->strLevelName );
//                break;
//            }
//        }
//    }
    QList<MemGradeInfo_s>::iterator it = m_listMemGrade.begin();
    for( ; it != m_listMemGrade.end(); ++it ) {
        if( it->nId != stMemRegInfo.stMemInfo.nMemLevelId ) continue;

        ui->memGradeValueQueryLabel->setText( it->strLevelName );
        break;
    }

    if( stMemRegInfo.stMemInfo.strAccountBalance.isEmpty() ) {
        ui->balanceValueQueryLabel->setText( stMemRegInfo.stMemInfo.strAccountBalance );
    } else {
        ui->balanceValueQueryLabel->setText( "￥" + stMemRegInfo.stMemInfo.strAccountBalance );
    }
    ui->integValueQueryLabel->setText( QString::number( stMemRegInfo.stMemInfo.nIntegral ) );

    setMemQueryButtonEnabled( true );

//    switch ( stMemRegInfo.stMemInfo.nCardStatus ) {
//    case -1:    //-1：销户
//        ui->reportLossQueryButton->setEnabled( false );
//        ui->cardStatusLabel->setStyleSheet("QLabel{color:#fa7a7a;}");
//        ui->cardStatusLabel->setText( "(已销户)" );
//        ui->memConsumeQueryButton->setEnabled( false );
//        break;
//    case 0: //0-挂失
//        ui->reportLossQueryButton->setText( "解挂" );
//        ui->cardStatusLabel->setStyleSheet("QLabel{color:#ea8852;}");
//        ui->cardStatusLabel->setText( "(已挂失)" );
//        ui->memRechargeButton->setEnabled( false );
//        ui->memConsumeQueryButton->setEnabled( false );
//        ui->memRegisterButton->setEnabled( true );
//        break;
//    case 1: //1-正常
//        ui->reportLossQueryButton->setText( "挂失" );
//        ui->cardStatusLabel->setStyleSheet("QLabel{color:#75ab57;}");
//        ui->cardStatusLabel->setText( "(正常)" );

//        ui->memRechargeButton->setEnabled( true );
//        ui->memConsumeQueryButton->setEnabled( true );
//        ui->memRegisterButton->setEnabled( false );
//        break;
//    default:
//        break;
//    }

    //充值界面
    ui->CardIDValueRecLabel->setText( stMemRegInfo.stMemInfo.strCardNo );
    ui->memNameValueRecLabel->setText( stMemRegInfo.stMemInfo.strName );
    if( !stMemRegInfo.stMemInfo.strMobile.isEmpty() ) {
        ui->phoneValueRecLabel->setText( stMemRegInfo.stMemInfo.strMobile.left(3) \
                                            + "****" + stMemRegInfo.stMemInfo.strMobile.right(4) );
    }
    if( stMemRegInfo.stMemInfo.strAccountBalance.isEmpty() ) {
        ui->balanceValueRecLabel->setText( "0" );
    } else {
        QString strAct = "";
        strAct.sprintf("￥%.2f", stMemRegInfo.stMemInfo.strAccountBalance.toFloat() );
        ui->balanceValueRecLabel->setText( strAct );
    }
    ui->integValueRecLabel->setText( QString::number( stMemRegInfo.stMemInfo.nIntegral ) );

    //注册变为换卡
    //ui->memRegisterButton->setText( "会员换卡" );
}

void MemberDlg::updateMemRechargeWnd( const MemRegisterInfo_s &stMemRegInfo )
{
    initRechargeWnd();

    ui->CardIDValueRecLabel->setText( stMemRegInfo.stMemInfo.strCardNo );
    ui->memNameValueRecLabel->setText( stMemRegInfo.stMemInfo.strName );
    if( !stMemRegInfo.stMemInfo.strMobile.isEmpty() ) {
        ui->phoneValueRecLabel->setText( stMemRegInfo.stMemInfo.strMobile.left(3) \
                                            + "****" + stMemRegInfo.stMemInfo.strMobile.right(4) );
    }
    if( stMemRegInfo.stMemInfo.strAccountBalance.isEmpty() ) {
        ui->balanceValueRecLabel->setText( "0" );
    } else {
        QString strAct = "";
        strAct.sprintf("￥%.2f", stMemRegInfo.stMemInfo.strAccountBalance.toFloat() );
        ui->balanceValueRecLabel->setText( strAct );
    }
    ui->integValueRecLabel->setText( QString::number(stMemRegInfo.stMemInfo.nIntegral ) );
}

void MemberDlg::updateDataBtn( bool bShow )
{
    if( bShow ) {
        ui->hundredButton->setText( "￥100" );
        ui->twoHundredButton->setText( "￥200" );
        ui->threeHundredButton->setText( "￥300" );
        ui->fiveHundredButton->setText( "￥500" );
    } else {
        ui->hundredButton->setText( "" );
        ui->twoHundredButton->setText( "" );
        ui->threeHundredButton->setText( "" );
        ui->fiveHundredButton->setText( "" );
    }
    ui->hundredButton->setEnabled( bShow );
    ui->twoHundredButton->setEnabled( bShow );
    ui->threeHundredButton->setEnabled( bShow );
    ui->fiveHundredButton->setEnabled( bShow );
}

void MemberDlg::slot_closeWnd()
{
    if( m_bMemLogin ) {
        slot_memConsume();
    } else {
        hide();
    }
}

void MemberDlg::slot_showMemQueryWnd()
{
    ui->stackedWidget->setCurrentIndex( 0 );

    setHundredButtonEnabled( false );

    clearMemfunBtn();
    ui->memQueryButton->setStyleSheet( "QPushButton{border-image: url(:/member/tab_press.png);}" );

    if( m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) return;

    updateMemQueryWnd( m_stMemRegInfo );
    updateDataBtn( false );
}

void MemberDlg::slot_showMemRechargeWnd()
{
    ui->nameWidget->setSearchFocus();
    ui->stackedWidget->setCurrentIndex( 1 );
    clearMemfunBtn();
    ui->memRechargeButton->setStyleSheet( "QPushButton{border-image: url(:/member/tab_press.png);}" );

    updateMemRechargeWnd( m_stMemRegInfo );
    updateDataBtn( true );
}

void MemberDlg::slot_showMemRegisterWnd()
{
    QString strText = ui->memRegisterButton->text();
    if( strText == "会员注册" ) {
        ui->stackedWidget->setCurrentIndex( 2 );
    } else if( strText == "会员换卡" ) {
        ui->stackedWidget->setCurrentIndex( 4 );

        if( !m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) {
            ui->replaceCardWidget->setMemTypeInfo( m_mapMemType );
            ui->replaceCardWidget->setMemRegInfo( m_stMemRegInfo );
        }
    }

    clearMemfunBtn();
    ui->memRegisterButton->setStyleSheet( "QPushButton{border-image: url(:/member/tab_press.png);}" );
    updateDataBtn( false );
}

void MemberDlg::slot_showModifyPasswdWnd()
{
    ui->stackedWidget->setCurrentIndex( 3 );

    ui->cardIDValuePwdLabel->setText( ui->cardIDValueQueryLabel->text() );
    clearMemfunBtn();
    ui->modifyPasswdButton->setStyleSheet( "QPushButton{border-image: url(:/member/tab_press.png);}" );
    updateDataBtn( false );
}

void MemberDlg::slot_memConsume()
{
    clearData();

    emit sig_memInfo( m_stMemRegInfo );

    accept();
}

void MemberDlg::slot_memSwingCard()
{
    if (KPosServerIni::getKPosUserType() == e_tianMaoVersion)
    {
        return;
    }

    QLineEdit *pEditWnd = (QLineEdit*)focusWidget();
    if( ui->cardIDQueryEdit == pEditWnd ) {
       //读取卡信息
        initICReadCard();
        QString sCardID = ui->cardIDQueryEdit->text();
        if( sCardID.isEmpty() ) return;
        //发送后台获取会员信息
        KPosLog::instance()->writeErrorLog(QString("MemberDlg::slot_memSwingCard -- %1").arg(sCardID));
        MemCardInfoAgent::instance()->memQueryRequest(sCardID);
    }
}

void MemberDlg::slot_memCardLoss()
{
    ui->warningLabel->setText( "" );

    //1. 如果卡的状态为挂失，则按钮显示为解挂；如果卡的状态为正常，则按钮显示为挂失
    //2. 点击解挂或者挂失，发送后台处理
    switch( m_stMemRegInfo.stMemInfo.nCardStatus ) {//-1.删除(退卡), 0.挂失, 1.启用
    case eRefundedCard:
        break;
    case eReportLossCard:
        MemCardInfoAgent::instance()->memSetStatusRequest( m_stMemRegInfo.stMemInfo.strCardNo, 1 );
        break;
    case eNormalCard:
        MemCardInfoAgent::instance()->memSetStatusRequest( m_stMemRegInfo.stMemInfo.strCardNo, 0 );
        break;
    default:
        break;
    }
}

void MemberDlg::slot_recharge()
{
    if( ui->CardIDValueRecLabel->text().isEmpty() ) return;
    if( ui->amtChargeRecEdit->text().isEmpty() ) return;
    //if( ui->operatorRecBox->currentText().isEmpty() ) return;

    //1. 弹出提示框
    DlgCommon *pDlg = new DlgCommon( 0, true );
    pDlg->set_title( "现金" );
    pDlg->set_content( "是否确认充值?" );
    connect( pDlg, SIGNAL(sig_btn_cancel()), pDlg, SLOT(close()) );
    connect( pDlg, SIGNAL(sig_dlg_close()), pDlg, SLOT( close() ) );
    //ui->titleWidget->setCloseButtonEnabled( false );
    if( pDlg->exec() == QDialog::Accepted ) {
        //点击确定后，弹出支付状态对话框
        switch( m_stCurPayInfo.nPayType ) {
        case PayNull:
            //ui->titleWidget->setCloseButtonEnabled( true );
            break;
        case PayCash:
        {
            int nOperatorId = -1;
            QMap<int, OperatorInfo_s>::iterator it = m_mapOperatorInfo.begin();
            for( ; it != m_mapOperatorInfo.end(); ++it ) {
                if( ui->operatorRecBox->currentText() == it->strName ) {
                    nOperatorId = it->nId;
                    break;
                }
            }

            MemCardInfoAgent::instance()->memRechargeRequest( m_stMemRegInfo.stMemInfo.strCardNo \
                , ui->amtChargeRecEdit->text(), m_stCurPayInfo.nPayType, nOperatorId, "", m_stCurPayInfo.bVirtualPay );
        }
            break;
        case PayStoreCard://储值卡，银联卡
            break;
        case PayAlipay:
        case PayWeChat:
        {
            if( m_stCurPayInfo.bVirtualPay ) {
                int nOperatorId = -1;
                QMap<int, OperatorInfo_s>::iterator it = m_mapOperatorInfo.begin();
                for( ; it != m_mapOperatorInfo.end(); ++it ) {
                    if( ui->operatorRecBox->currentText() == it->strName ) {
                        nOperatorId = it->nId;
                        break;
                    }
                }

                MemCardInfoAgent::instance()->memRechargeRequest( m_stMemRegInfo.stMemInfo.strCardNo \
                    , ui->amtChargeRecEdit->text(), m_stCurPayInfo.nPayType, nOperatorId, "", m_stCurPayInfo.bVirtualPay );
            } else {
                m_pMemCharge = new MemChargeDialog( 0, (EPayMethod)m_stCurPayInfo.nPayType );
                m_pMemCharge->setContext( ui->amtChargeRecEdit->text(), StatementScaning );
                connect( m_pMemCharge, SIGNAL( sig_memChargeInfo(EPayMethod,QString,QString)), this, SLOT( slot_memChargeInfo( EPayMethod,QString,QString ) ) );
                connect( m_pMemCharge, SIGNAL( sig_refreshCharge()), this, SLOT( slot_refreshRecharge() ) );
                if( m_pMemCharge->exec() == QDialog::Accepted ) {
                    delete m_pMemCharge;
                    m_pMemCharge = NULL;

                    m_sOrderRechargeCode = "";
                }
            }
        }
            break;
        case ApplePay:
            break;
        case JdWallet:
            break;
        default:
            //ui->titleWidget->setCloseButtonEnabled( true );
            break;
        }
    }
}

void MemberDlg::slot_readCard()
{
    //QLineEdit *pWnd = (QLineEdit *)this->focusWidget();
    //if( pWnd != ui->cardIDRegEdit ) return;


}

void MemberDlg::slot_commitReg()
{
    ui->warningRegLabel->setText( "" );
//    if( ui->cardIDRegEdit->text().isEmpty() ) {
//        ui->warningRegLabel->setText( "卡号不能为空" );
//        return;
//    }

    if( ui->phoneRegEdit->text().isEmpty() || ui->phoneRegEdit->text().length()!=11 ) {
        ui->warningRegLabel->setText( "手机号码为空，或者长度不等于11" );
        return;
    }

//    if( ui->memTypeRegBox->currentText() == "" ) {
//        ui->warningRegLabel->setText( "会员类型不能为空" );
//        return;
//    }

    if( ui->memGradeRegBox->currentText() == "" ) {
        ui->warningRegLabel->setText( "会员等级不能为空" );
        return;
    }

    if( !ui->payPasswdRegEdit->text().isEmpty() && ui->payPasswdRegEdit->text().size()!=6 ) {
        ui->warningRegLabel->setText( "密码长度应该为6位" );
        return;
    }

    MemRegisterInfo_s stMemRegister;
    if( !ui->payPasswdRegEdit->text().isEmpty() ) {
        stMemRegister.bPaypwd = true;
    } else {
        stMemRegister.bPaypwd = false;
    }

    //stMemRegister.stMemInfo.strCardNo = ui->cardIDRegEdit->text();
    stMemRegister.stMemInfo.strName = ui->nameWidget->getText();
    stMemRegister.stMemInfo.strMobile = ui->phoneRegEdit->text();
    stMemRegister.stMemInfo.nSex = m_eSex;
    stMemRegister.strPayPwd = ui->payPasswdRegEdit->text();

    //
    stMemRegister.stMemInfo.dtBirthday = QDateTime::fromString(ui->birthdayRegEdit->text(), "yyyy.MM.dd");

//    stMemRegister.eDocumentType = EnumToString::documentTypeToInt( ui->documentTypeRegBox->currentText() );
//    stMemRegister.strDocumentNum = ui->documentIdRegEdit->text();
//    stMemRegister.strAddress = ui->addressRegEdit->text();
//    stMemRegister.stMemInfo.nMemTypeId = memTypeToInt( ui->memTypeRegBox->currentText() );
    stMemRegister.stMemInfo.nMemLevelId = memGradeToInt( ui->memGradeRegBox->currentText() );
    stMemRegister.stMemInfo.strAccountBalance = "";
    stMemRegister.stMemInfo.nIntegral = 0;
    stMemRegister.stMemInfo.nCardStatus = 1;
    stMemRegister.nOPeratorId = getOperatorId( ui->operatorRegBox->currentText() );

    MemCardInfoAgent::instance()->memRegisterRequest( stMemRegister );
}

void MemberDlg::slot_documentTypeIndexChange( QString strText )
{
    if( strText == "请选择" ) {
//        ui->documentIdRegEdit->setText( "" );
//        ui->documentIdRegEdit->setEnabled( false );
        return;
    }

    //ui->documentIdRegEdit->setEnabled( true );
}

void MemberDlg::slot_pwdModifyCommit()
{
    QString strCardId = ui->cardIDValuePwdLabel->text();
    if( strCardId.isEmpty() ) {
        ui->pwdModifyWarningLabel->setText( "!卡号不能为空" );
        return;
    }

    QString strOldPwd = ui->oldPasswdPwdEdit->text();//是否需要旧密码，根据具体设置来判断
    QString strNewPwd = ui->newPasswdPwdEdit->text();

    if( strOldPwd == strNewPwd ) {
        ui->pwdModifyWarningLabel->setText( "!新旧密码相同，无需修改" );
        return;
    }

    QString strConfirmNewPwd = ui->confirmNewpasswdPwdEdit->text();
    if( strNewPwd != strConfirmNewPwd ) {
        ui->pwdModifyWarningLabel->setText( "!确认密码错误，请重新输入" );
        return;
    }

    strOldPwd = strOldPwd;
    strNewPwd = strNewPwd;

    MemCardInfoAgent::instance()->memPwdModifyRequest( strCardId, strOldPwd, strNewPwd );
}

void MemberDlg::slot_sex()
{
    QPushButton *pBtn = (QPushButton*)sender();
    if( pBtn == ui->manBtn && m_eSex != e_man ) {
        m_eSex = e_man;
        ui->manBtn->setStyleSheet( "QPushButton{border-image: url(:/member/man_press.png);}");
        ui->womanBtn->setStyleSheet( "QPushButton{border-image: url(:/member/woman_normal.png);}");
    } else if( pBtn == ui->womanBtn && m_eSex != e_woman ) {
        m_eSex = e_woman;
        ui->womanBtn->setStyleSheet( "QPushButton{border-image: url(:/member/woman_press.png);}");
        ui->manBtn->setStyleSheet( "QPushButton{border-image: url(:/member/man_normal.png);}");
    }
}

void MemberDlg::slot_memTypeChanged( QString strMemType )
{
    ui->warningRegLabel->setText( "" );

    QList<MemGradeInfo_s> listMemGrade;
    QMap<int, MemTypeInfo_s>::iterator it = m_mapMemType.begin();
    for( ; it != m_mapMemType.end(); ++it ) {
        if( it->strTypeName != strMemType ) continue;

        listMemGrade = it->listMemGrade;
        break;
    }

    ui->memGradeRegBox->clear();
    QList<MemGradeInfo_s>::iterator itGrade = listMemGrade.begin();
    for( ; itGrade != listMemGrade.end(); ++itGrade ) {
        ui->memGradeRegBox->addItem( itGrade->strLevelName );
    }
}

void MemberDlg::slot_setText( QString strText )
{
    firstClick();

    //非会员卡结算
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( p_wnd == ui->cardIDQueryEdit && strText == "." ) return;
    if( p_wnd == ui->birthdayRegEdit && strText == "." ) return;
    if( p_wnd->text().isEmpty() && strText == "." ) return;

    if( p_wnd == ui->amtChargeRecEdit || p_wnd == ui->giftAmtRecEdit ) {
        if( strText == "." ) return;
//        int nNum = findDecimalsNum();
//        if( nNum >= 2 ) return;
//        if( strText == "00" && nNum >= 1 ) return;
//        if( findPoint() && strText == "." ) return;
    } else if( p_wnd == ui->birthdayRegEdit ) {
        ui->birthdayRegEdit->addValue( strText );
        return;
    }

    QString sText = p_wnd->text();
    p_wnd->setText( sText.append( strText ) );
}

void MemberDlg::slot_deleteValue()
{
    if( m_bFirst ) {
        m_bFirst = false;
    }

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( p_wnd == ui->birthdayRegEdit ) {
        ui->birthdayRegEdit->deleteValue();
        return;
    }

    QString str_value = p_wnd->text();
    str_value.remove( str_value.length() - 1, 1);
    p_wnd->setText( str_value );
}

void MemberDlg::slot_clearZero()
{
    firstClick();

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    p_wnd->setText( "" );
}

void MemberDlg::showEvent(QShowEvent *)
{
    QPoint globalPoint = ui->nameWidget->mapToGlobal(QPoint(0, 0));
    const int nOffx = 11;
    int nXPos = nOffx;
    int nYPos = globalPoint.y() + ui->nameWidget->height();
    ui->nameWidget->setKeyboardPos(nXPos, nYPos);
}

void MemberDlg::slot_enter()
{
    clearData();

    if (ui->stackedWidget->currentWidget() == ui->memQueryWidget)
    {
        ui->warningLabel->setText( "" );
        //发送卡号或手机号给后台处理
        QString strCardId = ui->cardIDQueryEdit->text();
        if( strCardId.isEmpty() ) return;
        KPosLog::instance()->writeErrorLog(QString("MemberDlg::slot_enter() -- %1").arg(strCardId));
        MemCardInfoAgent::instance()->memQueryRequest( strCardId );
    }
    else if (ui->stackedWidget->currentWidget() == ui->memRechargeWidget)
    {
        slot_recharge();
    }
    else if (ui->stackedWidget->currentWidget() == ui->memRegisterWidget)
    {
        slot_commitReg();
    }
    else if (ui->stackedWidget->currentWidget() == ui->modifyPasswdWidget)
    {
        slot_pwdModifyCommit();
    }
    else if (ui->stackedWidget->currentWidget() == ui->replaceCardWidget)
    {
        // 不清楚
    }

//    QLineEdit *pEditWnd = (QLineEdit*)focusWidget();
//    if( ui->cardIDQueryEdit == pEditWnd ) {
//        ui->warningLabel->setText( "" );
//        //发送卡号或手机号给后台处理
//        QString strCardId = ui->cardIDQueryEdit->text();
//        if( strCardId.isEmpty() ) return;
//        KPosLog::instance()->writeErrorLog(QString("MemberDlg::slot_enter() -- %1").arg(strCardId));
//        MemCardInfoAgent::instance()->memQueryRequest( strCardId );
//    } else if( ui->replaceCardWidget->getCardIdEdit() == pEditWnd ) {
//        ui->warningLabel->setText( "" );
//        //发送卡号或手机号给后台处理
//        QString strCardId = ui->replaceCardWidget->getCardId();
//        if( strCardId.isEmpty() ) return;
//        MemCardInfoAgent::instance()->replaceMemCardRequest( m_stMemRegInfo.stMemInfo.strCardNo, strCardId );
//    } else if( ui->birthdayRegEdit == pEditWnd ) {
//        ui->birthdayRegEdit->slot_enter();
//    }
}

void MemberDlg::slot_hundred()
{
    firstClick();

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( (QComboBox*)p_wnd == ui->operatorRecBox ) return;

    p_wnd->setText( "100" );

}

void MemberDlg::slot_twoHundred()
{
    firstClick();

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( (QComboBox*)p_wnd == ui->operatorRecBox ) return;

    p_wnd->setText( "200" );
}

void MemberDlg::slot_threeHundred()
{
    m_bFirst = true;

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( (QComboBox*)p_wnd == ui->operatorRecBox ) return;

    p_wnd->setText( "300" );
}

void MemberDlg::slot_fiveHundred()
{
    firstClick();

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    if( (QComboBox*)p_wnd == ui->operatorRecBox ) return;

    p_wnd->setText( "500" );
}

void MemberDlg::slot_memInfoQuery( int nCode, QString sMsg, MemRegisterInfo_s stMemRegInfo )
{
    if( nCode != 0 ) {
        ui->warningLabel->setText( sMsg );
        return;
    }

    m_stMemRegInfo = stMemRegInfo;
    updateMemQueryWnd( m_stMemRegInfo );
}

void MemberDlg::slot_memCardStatus( int nCode, QString sMsg, QString strCardNo, int nCardStatus )
{
    ui->warningLabel->setText( sMsg );

    if( nCode != 0 ) {
        return;
    }

    QString strCardText = ui->cardIDValueQueryLabel->text();
    if( strCardText != strCardNo ) {
        ui->warningLabel->setText( "后台返回卡号与当前卡号不同,设置卡状态失败" );
        return;
    }

    m_stMemRegInfo.stMemInfo.nCardStatus = nCardStatus;
    if( nCardStatus == 0 ) {
        //ui->reportLossQueryButton->setText( "解挂" );
//        ui->cardStatusLabel->setStyleSheet("QLabel{color:#ea8852;}");
//        ui->cardStatusLabel->setText( "(已挂失)" );

        ui->memRechargeButton->setEnabled( false );
        ui->memConsumeQueryButton->setEnabled( false );
        //ui->memRegisterButton->setEnabled( true );
    } else if( nCardStatus == 1 ) {
        //ui->reportLossQueryButton->setText( "挂失" );
//        ui->cardStatusLabel->setStyleSheet("QLabel{color:#75ab57;}");
//        ui->cardStatusLabel->setText( "(正常)" );

        ui->memRechargeButton->setEnabled( true );
        ui->memConsumeQueryButton->setEnabled( true );
        //ui->memRegisterButton->setEnabled( false );
    }
}

//会员充值
void MemberDlg::slot_memRecharge( int nCode, QString sMsg, QString strCardNo, QString strAccountBalance, QString strTradeNo, int nIntegral, QString strGiftAmt )
{
    m_sOrderRechargeCode = strTradeNo;
    //会员充值小票打印
    QString strRechargeAmt = ui->amtChargeRecEdit->text();
    //QString strGiftAmt = ui->giftAmtRecEdit->text();
    int nUserId = getOperatorId( ui->operatorRecBox->currentText() );

    if( nCode != 0 ) {
        if( m_pMemCharge ) {
            m_pMemCharge->setStatus( StatementFailed );
            MemCardInfoAgent::instance()->insertMemRechargeTable( strCardNo, strRechargeAmt, strGiftAmt, 0, (EPayMethod)m_stCurPayInfo.nPayType, nUserId, strTradeNo, 0 );
        }
        return;
    }

    Q_UNUSED( sMsg )
    Q_UNUSED( strTradeNo )

    if( ui->CardIDValueRecLabel->text() != strCardNo ) {
        MemCardInfoAgent::instance()->insertMemRechargeTable( strCardNo, strRechargeAmt, strGiftAmt, 0, (EPayMethod)m_stCurPayInfo.nPayType, nUserId, strTradeNo, 0 );
        return;
    }

    if( m_pMemCharge ) {
        m_pMemCharge->setStatus( StatementSuc );
    }

    m_stMemRegInfo.stMemInfo.strAccountBalance = strAccountBalance;
    MemCardInfoAgent::instance()->printMemRechargeReceipt( strTradeNo, m_stMemRegInfo, strRechargeAmt, strGiftAmt, "现金" );
    MemCardInfoAgent::instance()->insertMemRechargeTable( strCardNo, strRechargeAmt, strGiftAmt, 0, (EPayMethod)m_stCurPayInfo.nPayType, nUserId, strTradeNo, 1 );

    QString strAct = "";
    strAct.sprintf("￥%.2f", strAccountBalance.toFloat() );
    ui->balanceValueRecLabel->setText( strAct );
    ui->integValueRecLabel->setText( QString::number( nIntegral ) );
    ui->amtChargeRecEdit->setText( "" );
    ui->giftAmtRecEdit->setText( "" );
}

void MemberDlg::slot_memRegister( int nCode, QString sMsg, QString strCardNo, int nStatus, MemRegisterInfo_s stMemRegisterInfo )
{
    Q_UNUSED( strCardNo )
    Q_UNUSED( nStatus )

    ui->warningRegLabel->setText( sMsg );

    if( nCode != 0 ) {
        return;
    }

    m_stMemRegInfo = stMemRegisterInfo;
    initResigterWnd();
    slot_showMemRechargeWnd();//跳转到充值界面
}

void MemberDlg::slot_memPwdModify(int nCode, QString sMsg, QString strCardNo, int nStatus )
{
    Q_UNUSED( nStatus )
    Q_UNUSED( strCardNo )

    ui->pwdModifyWarningLabel->setText( sMsg );
    if( nCode != 0 ) {
        return;
    }

    m_stMemRegInfo.bPaypwd = true;
}

void MemberDlg::slot_operatorList( int nCode, QString sMsg, QList<OperatorInfo_s> listOperator )
{
    Q_UNUSED( sMsg )
    //ui->warningLabel->setText( sMsg );
    if( nCode != 0 ) {
        return;
    }

    ui->operatorRecBox->clear();
    ui->operatorRegBox->clear();
    m_mapOperatorInfo.clear();

    QList<OperatorInfo_s>::iterator it = listOperator.begin();
    for( ; it != listOperator.end(); ++it ) {
        ui->operatorRecBox->addItem( it->strName );
        ui->operatorRegBox->addItem( it->strName );
        m_mapOperatorInfo.insert( it->nId, *it );
    }
}

void MemberDlg::slot_payMethodSelected()
{
    PayMethodButton *pBtn = (PayMethodButton*)sender();
    if( m_stCurPayInfo.nPayType == pBtn->getPayInfo().nPayType ) return;

    QList<PayMethodButton*>::iterator it = m_listPayMethodBtn.begin();
    for( ; it != m_listPayMethodBtn.end(); ++it ) {
        if( (*it)->getPayInfo().nPayType == m_stCurPayInfo.nPayType ) {
            (*it)->setPayBtnUnselected();
            break;
        }
    }
    m_stCurPayInfo = pBtn->getPayInfo();
    pBtn->setPayBtnSelected();
}

void MemberDlg::slot_memTypeList( int nCode, QString sMsg, QList<MemGradeInfo_s> listMemGrade )
{
    Q_UNUSED( sMsg )
    if( nCode != 0 ) {
        return;
    }

    //m_mapMemType = mapMemType;
    m_listMemGrade = listMemGrade;
    //ui->memTypeRegBox->clear();
    ui->memGradeRegBox->clear();

    //QMap<int, MemTypeInfo_s>::iterator it = mapMemType.begin();
    QList<MemGradeInfo_s>::iterator itGrade = listMemGrade.begin();
    for( ; itGrade != listMemGrade.end(); ++itGrade ) {
        ui->memGradeRegBox->addItem( itGrade->strLevelName );
    }

//    for( ; it != mapMemType.end(); ++it ) {
//         ui->memTypeRegBox->addItem( it.value().strTypeName );
//    }
}

void MemberDlg::slot_curIndexChanged( int nIndex )
{
    Q_UNUSED( nIndex )
    //ui->memTypeRegBox->itemData( nIndex ).data();
}

void MemberDlg::slot_memChargeInfo( EPayMethod ePayMethod, QString strBarCode, QString strChargeAmt )
{
    int nOperatorId = getOperatorId( ui->operatorRecBox->currentText() );
    MemCardInfoAgent::instance()->memRechargeRequest( ui->CardIDValueRecLabel->text() \
                                                      , strChargeAmt, ePayMethod, nOperatorId, strBarCode, m_stCurPayInfo.bVirtualPay );
}

void MemberDlg::slot_refreshRecharge()
{
    MemCardInfoAgent::instance()->memRechargeStatusRequest( m_stCurPayInfo.nPayType, m_sOrderRechargeCode );
}

void MemberDlg::slot_getRechargeStatus( int nCode, QString sMsg, QString strOrderNumS, int nTradeState )
{
    if (KPosServerIni::getKPosUserType() == e_tianMaoVersion)
    {
        return;
    }

    Q_UNUSED( sMsg )
    Q_UNUSED( strOrderNumS )
    if( nCode != 0 ) {
        return;
    }

    if( nTradeState != 0 ) return;

    if( m_pMemCharge ) {
        m_pMemCharge->setStatus( StatementSuc );
    }

    QString strCardId = ui->CardIDValueRecLabel->text();
    KPosLog::instance()->writeErrorLog(QString("MemberDlg::slot_getRechargeStatus -- %1").arg(strCardId));
    MemCardInfoAgent::instance()->memQueryRequest( strCardId );
    ui->amtChargeRecEdit->setText( "" );
    ui->giftAmtRecEdit->setText( "" );
}

void MemberDlg::slot_giftAmtChanged( QString strRechargeAmt )
{
    int nMaxGiftAmt = m_stMemRegInfo.strMaxGiftAmt.toInt();
    int nRechargeAmt1 = m_stMemRegInfo.strRechargeAmt1.toInt();
    int nRechargeAmt2 = m_stMemRegInfo.strRechargeAmt2.toInt();
    int nRechargeAmt3 = m_stMemRegInfo.strRechargeAmt3.toInt();
//    if( nRechargeAmt1 == 0 ) return;//被除数不能为0
    int nGiftAmt1 = m_stMemRegInfo.strGiftAmt1.toInt();
    int nGiftAmt2 = m_stMemRegInfo.strGiftAmt2.toInt();
    int nGiftAmt3 = m_stMemRegInfo.strGiftAmt3.toInt();

    int nFactorRechargeAmt = strRechargeAmt.toInt();
    int nAllGiftAmt = 0;

    if ((nRechargeAmt3 != 0) && (nFactorRechargeAmt >= nRechargeAmt3))
    {
        nAllGiftAmt += (nFactorRechargeAmt / nRechargeAmt3 * nGiftAmt3);
        nFactorRechargeAmt = nFactorRechargeAmt % nRechargeAmt3;
    }
    if ((nRechargeAmt2 != 0) && (nFactorRechargeAmt >= nRechargeAmt2))
    {
        nAllGiftAmt += (nFactorRechargeAmt / nRechargeAmt2 * nGiftAmt2);
        nFactorRechargeAmt = nFactorRechargeAmt % nRechargeAmt2;
    }
    if ((nRechargeAmt1 != 0) && (nFactorRechargeAmt >= nRechargeAmt1))
    {
        nAllGiftAmt += (nFactorRechargeAmt / nRechargeAmt1 * nGiftAmt1);
        nFactorRechargeAmt = nFactorRechargeAmt % nRechargeAmt1;
    }

    if( nAllGiftAmt > nMaxGiftAmt ) {
        nAllGiftAmt = nMaxGiftAmt;
    }
    ui->giftAmtRecEdit->setText(QString::number(nAllGiftAmt));
}

void MemberDlg::slot_replaceMemCard( QString strOldCardId, QString strNewCardId )
{
    if( m_stMemRegInfo.stMemInfo.strCardNo != strOldCardId ) return;

    m_stMemRegInfo.stMemInfo.nCardStatus = 1;
    m_stMemRegInfo.stMemInfo.strCardNo = strNewCardId;
    emit ui->memQueryButton->clicked();
    emit sig_replaceMemCard( strOldCardId, strNewCardId );
}

void MemberDlg::slot_payInfoChanged()
{
    m_listPayInfo.clear();
    KPosSet stKPosSet;
    KPosSetAgent::instance()->getKPosSetInfo( stKPosSet );
    QList<PayWayInfoSet> listPayInfo = stKPosSet.payWaySet.payWayInfoSetList;
    int nSize = listPayInfo.size();
    for( int i=0; i<nSize; ++i ) {
        if( !listPayInfo[i].bStartUse ) continue;
        if( !listPayInfo[i].bChargeMember ) continue;
        if( listPayInfo[i].nPayType == PayMemCard ) continue;//会员卡不能充值会员卡

        m_listPayInfo.append( listPayInfo[i] );
    }
    setMemRechargeMethod( m_listPayInfo );
}

//支付方式按钮状态
void MemberDlg::slot_OnlineState( bool bOnline )
{
    if( m_bOnline == bOnline && !bOnline ) return;

    m_bOnline = bOnline;

    int nSize = m_listPayInfo.size();
    if( bOnline ) {
        for( int i=0; i<nSize; ++i ) {
            m_listPayMethodBtn[i]->setEnabled( true );
        }
    } else {
        for( int i=0; i<nSize; ++i ) {
            if( m_listPayMethodBtn[i]->getPayInfo().nPayType != PayCash \
                    && !m_listPayMethodBtn[i]->getPayInfo().bVirtualPay ) {
                m_listPayMethodBtn[i]->setEnabled( false );
            } else if( m_listPayMethodBtn[i]->getPayInfo().nPayType == PayCash ) {
                emit m_listPayMethodBtn[i]->click();
            }
        }
    }


}

