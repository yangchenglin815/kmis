#include "URFCard.h"
#include "ui_URFCard.h"
#include <QByteArray>
#include <QDebug>

URFCard::URFCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::URFCard)
{
    ui->setupUi(this);

    initCtrl();
    initConnect();

    QRegExp regExp("[A-Fa-f0-9]{12}");
    QRegExp regExp2("[A-Za-z0-9]{32}");

    ui->readPwdEdit->setValidator(new QRegExpValidator(regExp, this));
    ui->writePwdEdit->setValidator(new QRegExpValidator(regExp, this));
    ui->modifyPwdEdit->setValidator(new QRegExpValidator(regExp, this));
    ui->writeCardEdit->setValidator( new QRegExpValidator(regExp2, this) );
}

URFCard::~URFCard()
{
    delete ui;
}

void URFCard::initCtrl()
{
    m_Port = -1;
    m_Sector = 0;
    m_key = "FFFFFFFFFFFF";
    m_OpMode = 0;
    m_Data = "";
    icdev = NULL;
}

void URFCard::initConnect()
{
    connect( ui->connectBtn, SIGNAL(clicked()), this, SLOT( slot_connect() ) );
    connect( ui->disConnectBtn, SIGNAL(clicked()), this, SLOT( slot_disConnect() ) );
    connect( ui->readBtn, SIGNAL(clicked()), this, SLOT( slot_read() ) );
    connect( ui->writeBtn, SIGNAL(clicked()), this, SLOT( slot_write() ) );
    connect( ui->modifyPwdBtn, SIGNAL(clicked()), this, SLOT( slot_modifyPwd() ) );
}

void URFCard::init()
{
    unsigned char Sec = ui->sectorEdit->text().toInt()/*m_Sector*/;
    __int16 st;
    unsigned __int16 TagType;
    unsigned long Snr;
    unsigned char Size;

    st = rf_reset(icdev,5 );//射频读写模块复位

    st = rf_request(icdev,1,&TagType);//寻卡模式
    if(st)
    {
        ui->warningLabel->setText( "寻卡失败!" );
        return;
    }
    st = rf_anticoll(icdev,0, &Snr);//卡防冲突，返回卡的序列号
    if(st)
    {
        ui->warningLabel->setText( "防冲突失败!" );
        return;
    }
    st = rf_select(icdev,Snr,&Size);
    if(st)
    {
        ui->warningLabel->setText( "选卡失败!" );
        return;
    }
    unsigned char key[7];
    memset(key,0,7);
    if( m_OpMode == 0 ) {
        m_key = ui->readPwdEdit->text();
    } else if( m_OpMode == 1 ) {
        m_key = ui->writePwdEdit->text();
    }
    a_hex( m_key.toLatin1().data(),key,12);
    //m_key = "";
    unsigned char m_keymode;
//    if(m_KeyModeCtrl.GetCurSel()==0)
        m_keymode = 0;
//    else
//        m_keymode = 4;
    st = rf_load_key(icdev,m_keymode,Sec,key);
    if(st)
    {
        ui->warningLabel->setText( "装载密码失败!" );
        return;
    }

    //Int16 at = IC.rf_authentication(icdev, 0, 8);//0为验证模式，表示密码A；8表示8号扇区
    //Int16 at = IC.rf_authentication_2(icdev, 0, 8, 0);//验证8号扇区0号块
    st = rf_authentication(icdev,m_keymode,Sec);
    if(st)
    {
        ui->warningLabel->setText( "认证失败!" );
        return;
    }
}

void URFCard::slot_connect()
{
    initCtrl();


    __int16 st;
    unsigned char _Status[30];
    memset(_Status,0,30);
    if( icdev != NULL || icdev > 0 ) {
        rf_exit(icdev);
    }
    icdev = rf_init( 0, 115200 );//初始化，设置端口和波特率
    st = rf_get_status(icdev,_Status);
    if(icdev<0 || st) {
        ui->warningLabel->setText( "连接失败!" );
    } else {
        //rf_beep(icdev,10);
        ui->warningLabel->setText( "连接成功!" );
    }
}

void URFCard::slot_disConnect()
{
    __int16 st;

    if(icdev == NULL || icdev <0) {
        ui->warningLabel->setText( "端口未初始化!" );
        return;
    }

    st = rf_exit(icdev);
    if(st)
        ui->warningLabel->setText( "断开连接失败!" );
    else {
        ui->warningLabel->setText( "断开连接成功!" );
        icdev = NULL;
    }
}

void URFCard::slot_read()
{
    ui->blockEdit_0->setText( "" );
    ui->blockEdit_1->setText( "" );
    ui->blockEdit_2->setText( "" );
    ui->warningLabel->setText( "" );

    init();

    m_OpMode = 0;
    unsigned char Sec = ui->sectorEdit->text().toInt()/*m_Sector*/;
    __int16 st;
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
            return;
        }

        hex_a(data,(char*)temp,16);
        m_Data.sprintf("%s",temp);

        switch( i ) {
        case 0:
        {
            ui->blockEdit_0->setText( m_Data );

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

            ui->readEdit->setText( strText );
        }
            break;
        case 1:
            ui->blockEdit_1->setText( m_Data );
            break;
        case 2:
            ui->blockEdit_2->setText( m_Data );
            break;
        }
    }

    ui->warningLabel->setText( "读数据成功!" );

    //rf_beep(icdev,10);

    st = rf_halt(icdev);
}

void URFCard::slot_write()
{
    m_OpMode = 1;
    unsigned char Sec = ui->sectorEdit->text().toInt()/*m_Sector*/;
    __int16 st;
    unsigned char data[33];
    memset(data,0,33);

    init();

    m_Data = ui->writeCardEdit->text();

    if(m_Data == "" )
    {
        ui->warningLabel->setText( "数据为空!" );
        return;
    }

    if( m_Data.size() <16 ) {
        int i = 32 - m_Data.size();
        QString strZero = "";
        for( int j =1; j<=i; ++j ) {
            strZero += "0";
        }
        m_Data = strZero + m_Data;
    }

    unsigned char temp[33];
    memset(temp,0,33);
    memset(data,0,33);
    QByteArray ba;
    qDebug()<<"URFCard::slot_write"<<ba.append(m_Data).toHex();
    //a_hex( ba.append(m_Data).toHex().data(),temp,32);
    a_hex( m_Data.toLatin1().data(), temp,32);
    m_Data= "";
    memcpy(data,temp,16);

    //_Adr：M1卡——块地址（0～63）
    st = rf_write(icdev,Sec*4 + ui->blockNumEdit->text().toInt(),data);

    if(st)
    {
        ui->warningLabel->setText( "写数据失败!" );
        return;
    }

    ui->warningLabel->setText( "写数据成功!" );
    //rf_beep(icdev,10);

    st = rf_halt(icdev);
}

void URFCard::slot_modifyPwd()
{
    init();

    __int16 st;
    unsigned char keya[12];
    unsigned char keyb[6];
    memset(keyb,0xff,6);

    QString strKeyA = ui->modifyPwdEdit->text();
    a_hex( strKeyA.toLatin1().data(), keya, 12 );//十进制转成16进制
    //密码修改
    st = rf_changeb3( icdev, ui->sectorEdit->text().toInt(), keya, 0x00, 0x00, 0x00, 0x01, 0, keyb );
    if( st != 0 ) {
        ui->warningLabel->setText( "密码修改错误！");
        return;
    }
    ui->warningLabel->setText( "密码修改成功！");
}

void URFCard::slot_init()
{
    init();
}

long URFCard::GetBaund()
{
    switch( 9 )
    {
    case 0:
        return 9600;
    case 1:
        return 14400;
    case 2:
        return 19200;
    case 3:
        return 28800;
    case 4:
        return 38400;
    case 5:
        return 57600;
    case 6:
        return 115200;
    }

    return 9600;
}
