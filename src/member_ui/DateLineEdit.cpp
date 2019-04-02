#include "DateLineEdit.h"
#include <QRegExp>
#include <QRegExpValidator>

DateLineEdit::DateLineEdit(QWidget *parent)
    : QLineEdit(parent)
    , m_sDate( "2000.01.01" )
{
    initCtrl();
    initConnect();
}

void DateLineEdit::initData()
{
    m_sDate = "2000.01.01";
    setText( m_sDate );
}

void DateLineEdit::deleteValue()
{
    int nPos = this->cursorPosition();
    QString strText = text();
    if( nPos == 0 ) return;
    //if( strText[nPos-1] == '.' ) return;

    QString str = strText.left(nPos-1) + strText.mid( nPos );
    setText( str );
    setCursorPosition( nPos-1 );
}

void DateLineEdit::addValue( QString strText )
{
    if( strText == "." ) return;
    int nPos = cursorPosition();
    QString strDate = text();
    //QStringList strList = strDate.split( "." );
    //if( strList.size() != 3 ) return;
    if( strDate.size() == 10 ) return;

    bool bStatus = false;
    if( nPos < 4 ) {
        bStatus = updateYear( strText );
    } else if( nPos >=5 && nPos <7 ) {
        bStatus = updateMonth( strText );
    } else if( nPos>=8){
        bStatus = updateDay( strText );
    }

    if( !bStatus ) return;

//    strDate = text();
    if( text().size() == 10 ) {
        m_sDate = text();
    }

//    nPos = strDate.size();
    //    setCursorPosition( nPos );
}

void DateLineEdit::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED( event )

    return;
}

void DateLineEdit::slot_enter()
{
    if( text().size() != 10 ) {
        setText( m_sDate );
    }
}

//焦点位置移动处理
void DateLineEdit::slot_cursorPosChanged( int nOldPos, int nNewPos )
{
    QString strText = text();

    if( nOldPos > nNewPos ) {
        if( nNewPos!=0 && strText.size()!=10 &&strText[nOldPos-1] == '.' ) {
            setText( m_sDate );
            if( nOldPos-1 <= 4 ) {
                setCursorPosition( 4 );
            } else {
                setCursorPosition( 7 );
            }
        }/* else if( nNewPos != 0 && (nNewPos<8 && nOldPos >8) && strText.size() != 10 ) {
            setText( m_sDate );
            setCursorPosition( nNewPos );
        }*/
    } else if( nOldPos < nNewPos ) {//左边
        if( nOldPos == 0 && strText[nNewPos-1] == '.' ) {
            setText( m_sDate );
            setCursorPosition( 5 );
        } else if( nOldPos!=0 && strText.size()!=10 &&strText[nNewPos-1] == '.' ) {
            setText( m_sDate );
            //确定小数点的位置，然后设置焦点位置
            if( nNewPos-1 <= 4 ) {
                setCursorPosition( 5 );
            } else {
                setCursorPosition( 8 );
            }
        }
    }
}

void DateLineEdit::initCtrl()
{
    //正则表达式
//    QRegExp regx("([1][9]|[2][0])[0-9]{2}.(0[1-9]|1[0-2]).([0-2][1-9]|3[0-1])");
    QRegExp regx("(([19|20][0-9]{2}).(0[1-9]|1[0-2]).([0-2][1-9]|3[0-1]))");
    QRegExpValidator *pReg = new QRegExpValidator( regx, this);
    setValidator( pReg );

    initData();
}

void DateLineEdit::initConnect()
{
    //connect( this, SIGNAL(cursorPositionChanged(int,int)), this, SLOT( slot_cursorPosChanged(int,int) ) );
}

bool DateLineEdit::updateYear(  QString strText )
{
    QString strDate = text();
    QStringList strList = strDate.split( "." );
    //if( strList.size() != 3 ) return false;

    switch( strList[0].size() ) {
    case 0:
    {
        if( strText != "1" && strText != "2" ) return false;
        strDate = strText;
    }
        break;
    case 1:
    {
        if( strList[0] == "1" && strText != "9" ) return false;
        if( strList[0] == "2" && strText != "0" ) return false;

        strDate = strList[0] + strText;
    }
        break;
    case 2:
        strDate = strList[0] + strText;
        break;
    case 3:
        strDate = strList[0] + strText + ".";
        break;
    default:
        break;
    }

    setText( strDate );
    return true;
}

bool DateLineEdit::updateMonth( QString strText )
{
    QString strDate = text();
    QStringList strList = strDate.split( "." );
    //if( strList.size() != 3 ) return false;

    bool bStatus = false;
    switch( strList[1].size() ) {
    case 0:
    {
        if( strText == "0" ) {
            strDate = strList[0] + ".0";
            bStatus = true;
        } else if( strText != "1" ) {
            strDate = strList[0] + ".0" + strText + ".";
            bStatus = true;
        } else {
            strDate = strList[0] + "." + strText;
            bStatus = true;
        }
    }
        break;
    case 1:
    {
        if( strList[1] == "0" ) {
            strDate = strList[0] + "." + strList[1] + strText + ".";
            bStatus = true;
        } else if( strList[1] == "1" ) {
            if( strText == "0" || strText == "1" || strText == "2" ) {
                strDate = strList[0] + "." + strList[1] + strText + ".";
                bStatus = true;
            }
        }
    }
        break;
    default:
        break;
    }

    if( bStatus ) {
        setText( strDate );
        //modifyDayFromMonth();
        return bStatus;
    }

    return bStatus;
}

bool DateLineEdit::updateDay( QString strText )
{
    QString strDate = text();
    QStringList strList = strDate.split( "." );
    if( strList.size() != 3 ) return false;
    int nYear = strList[0].toInt();

    switch( strList[2].size() ) {
    case 0:
    {
        if( strList[1]=="02" && strText == "3" ) return false;
        if( strText != "0" && strText != "1" && strText != "2" && strText != "3" ) return false;
        strDate = strList[0] + "." + strList[1] + "." + strText;
    }
        break;
    case 1:
    {
        if( strList[2] == "3" && ( strText != "0" && strText != "1") ) return false;
        if( (nYear%4==0&& nYear%100!=0) || nYear%400 == 0 ) {
            if( strList[2] == "2" && strText.toInt()>8 ) return false;
        }

        strDate = strList[0] + "." + strList[1] + "." + strList[2]+strText;
    }
        break;
    default:
        break;
    }

    setText( strDate );
    return true;
}
//通过月份来修改天数
void DateLineEdit::modifyDayFromMonth()
{
    QString strDate = text();
    QStringList strList = strDate.split( "." );
    if( strList.size() != 3 ) return;

    int nYear = strList[0].toInt();
    int nMonth = strList[1].toInt();
    QString strDay = strList[2];

    switch( nMonth ) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        if( strDay.toInt() > 31 ) {
            strDay = "31";
        }
    }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
    {
        if( strDay.toInt() > 30 ) {
            strDay = "30";
        }
    }
        break;
    case 2:
        if( (nYear%4==0&& nYear%100!=0) || nYear%400 == 0 ) {
            int nDay = strDay.toInt();
            if( nDay > 28 ) {
                strDay = "28";
            } else if( nDay > 29 ) {
                strDay = "29";
            }
        }
        break;
    default:
        break;
    }

    strDate = strList[0] + "." + strList[1] + "." + strDay;
    setText( strDate );
}

int DateLineEdit::firstPointPos()
{
    QString strDate = text();
    QStringList strList = strDate.split( "." );
    int nPos = strList[0].size() + 1;
    return nPos;
}

int DateLineEdit::secondPointPos()
{
    QString strDate = text();
    QStringList strList = strDate.split( "." );
    int nPos = strList[0].size() + 1 + strList[1].size() + 1;
    return nPos;
}
