#ifndef STANDBYADVERTWIDGET_H
#define STANDBYADVERTWIDGET_H

#include <QWidget>
#include <QMap>
#include <QTimer>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QHBoxLayout>

namespace Ui {
class StandbyAdvertWidget;
}

class StandbyAdvertWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StandbyAdvertWidget(QWidget *parent = 0);
    ~StandbyAdvertWidget();
public:
    void setFileList( QList<QString> listFilePath );
//    void setFileList( QMap<int, QString> mapFilePath );
    bool getFileList( QList<QString> &listFilePath );

    void paintEvent(QPaintEvent *event);

    void startTimer();
    void stopTimer();
private:
    void initCtrl();
    void updatePlayFile();


private slots:
    void slot_updateImage();
    void slot_mediaStatusChanged(QMediaPlayer::MediaStatus status);

private:
    Ui::StandbyAdvertWidget *ui;

    QMap<int, QString> m_mapFilePath; //需要播放的文件列表

    QTimer *m_pTimer;
    int m_nTimerId;

    QImage m_image;
    QMediaPlayer *m_media;
    int m_Filetype;//播放到的文件类型 1视频 2图片
    int m_nCurFilePos; //播放到的文件key

    QVideoWidget *m_videoWidget;
    QVBoxLayout *m_layout;
};

#endif // STANDBYADVERTWIDGET_H
