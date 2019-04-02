#include "StandbyAdvertWidget.h"
#include "ui_StandbyAdvertWidget.h"
#include "../util/KPosIni.h"
#include <QPainter>
#include <QVideoWidget>
#include <QHBoxLayout>
#include "ScreenInfo.h"

StandbyAdvertWidget::StandbyAdvertWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StandbyAdvertWidget)
  , m_pTimer( NULL )
  , m_nTimerId( -1 )
  , m_nCurFilePos( -1 )
  , m_media(new QMediaPlayer)
  , m_videoWidget(new QVideoWidget)
  , m_layout(new QVBoxLayout)
{
    ui->setupUi(this);
    ScreenInfo::resetGrid(this);
    initCtrl();
}

StandbyAdvertWidget::~StandbyAdvertWidget()
{
    stopTimer();

    delete ui;
}

void StandbyAdvertWidget::setFileList( QList<QString> listFilePath )
{
    m_mapFilePath.clear();
    stopTimer();
    QList<QString>::iterator it = listFilePath.begin();

    for( int i=1; it != listFilePath.end(); ++it,++i ) {
        m_mapFilePath.insert( i, *it );
    }
    if( m_mapFilePath.size() > 0 ) {

        m_nCurFilePos = 1;
        updatePlayFile();
        startTimer();
    }
}


bool StandbyAdvertWidget::getFileList(QList<QString> &listFilePath)
{
    Q_UNUSED( listFilePath )
    return true;
}

void StandbyAdvertWidget::paintEvent( QPaintEvent *event )
{
    Q_UNUSED( event )

    QPainter draw( this );

    if(m_Filetype == 1){
        this->setLayout(m_layout);
        m_media->play();
        stopTimer();
    }

    if(m_Filetype == 2){

        draw.drawImage( QRect(0,0, width(), height()), m_image );

        draw.end();
    }
}

void StandbyAdvertWidget::initCtrl()
{
    m_pTimer = new QTimer( this );
    connect( m_pTimer, SIGNAL(timeout()), this, SLOT( slot_updateImage() ) );

    QList<QString> pathList = KPosIni::getRemoteADPathList();
//        QList<QString> pathList;
//        pathList.clear();
    if (pathList.count() <= 0)
    {
        QString str1 = ":/customer/customer1.jpg";
        QString str2 = ":/customer/customer2.jpg";
        QString str3 = ":/customer/customer3.jpg";
//        QString str4 = "D://我的文档/KPos/AD/Local/20170321074.avi";
        pathList<<str1<<str2<<str3;
    }

    setFileList(pathList);


    m_media->setVideoOutput(m_videoWidget);
    m_videoWidget->setAspectRatioMode(Qt::IgnoreAspectRatio);
    m_layout->addWidget(m_videoWidget);
    connect(m_media, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
            this, SLOT(slot_mediaStatusChanged(QMediaPlayer::MediaStatus)));

    m_media->setVolume(0);
}

void StandbyAdvertWidget::updatePlayFile()
{

    QString fileName = m_mapFilePath[m_nCurFilePos]  ;

    QString fileType = fileName.right(3);

    if(fileType == "avi"||fileType == "mp4"){
        m_media->setMedia(QUrl::fromLocalFile(fileName));
        m_Filetype = 1;
    }
    else
    {
        m_image = QImage( fileName );
        m_Filetype = 2;
    }
}

void StandbyAdvertWidget::startTimer()
{
    if( m_nTimerId < 0 ) {
        m_pTimer->start( 5000 );
        m_nTimerId = m_pTimer->timerId();
    }
}

void StandbyAdvertWidget::stopTimer()
{
    if( m_nTimerId> 0 ) {
        m_pTimer->stop();
        m_nTimerId = -1;
    }
}

void StandbyAdvertWidget::slot_updateImage()
{
    ++m_nCurFilePos;
    if( m_nCurFilePos > m_mapFilePath.size() )
    {
        m_nCurFilePos = 1;
    }

    updatePlayFile();
    update();
}

void StandbyAdvertWidget::slot_mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    qDebug()<<"233333333333333333"<<status;
    if(status == QMediaPlayer::EndOfMedia
            ||status == QMediaPlayer::UnknownMediaStatus){
        startTimer();
        slot_updateImage();
    }
}

