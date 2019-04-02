#include "BirthdayLineEdit.h"

BirthdayLineEdit::BirthdayLineEdit(QWidget *parent)
    : QLineEdit(parent)
    , m_pBirthdayCalendarDlg( NULL )
{
    initCtrl();
}

BirthdayLineEdit::~BirthdayLineEdit()
{
    if( m_pBirthdayCalendarDlg ) {
        delete m_pBirthdayCalendarDlg;
        m_pBirthdayCalendarDlg = NULL;
    }
}

bool BirthdayLineEdit::isCalendarHidden()
{
    return m_pBirthdayCalendarDlg->isHidden();
}

void BirthdayLineEdit::setCalendarHidden( bool bHidden )
{
    m_pBirthdayCalendarDlg->setHidden( bHidden );
}

void BirthdayLineEdit::initCtrl()
{
    this->installEventFilter( this );

    m_pBirthdayCalendarDlg = new BirthdayCalendarDlg(  );
    m_pBirthdayCalendarDlg->activateWindow();
    m_pBirthdayCalendarDlg->show();
    m_pBirthdayCalendarDlg->hide();
}

void BirthdayLineEdit::initConnect()
{

}

bool BirthdayLineEdit::eventFilter( QObject *watched, QEvent *event )
{
    if( event->type() == QEvent::MouseButtonPress ) {
        QPoint globalPos = this->mapToGlobal(QPoint(0,0));
        int nXPos = globalPos.x() + this->width(); /*- (m_pBirthdayCalendarDlg->width() - this->width());*/
        int nYPos = globalPos.y() + this->height() + 10;
        //qDebug()<<"nXPos:"<<nXPos<<"--nYPos:"<<nYPos;
        m_pBirthdayCalendarDlg->move(nXPos, nYPos);

        m_pBirthdayCalendarDlg->activateWindow();
        m_pBirthdayCalendarDlg->show();
    }

    return QLineEdit::eventFilter( watched, event );
}
