#ifndef LABEL_H
#define LABEL_H
#include <QLabel>

class Label : public QLabel
{
    Q_OBJECT
public:
    explicit Label( QWidget *parent = 0 );
    ~Label();
public:
    void mousePressEvent( QMouseEvent *event );
    void mouseReleaseEvent( QMouseEvent *event );

    void setBackGroundImage( QString strNormalImage , QString strPressImage );
signals:
    void sig_clicked();
private:
    bool m_bImage;
    QString m_sNormalImage;
    QString m_sPressImage;
};

#endif // LABEL_H
