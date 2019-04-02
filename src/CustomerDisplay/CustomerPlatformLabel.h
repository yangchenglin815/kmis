#ifndef CUSTOMERPLATFORMLABEL_H
#define CUSTOMERPLATFORMLABEL_H

#include <QLabel>

class CustomerPlatformLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CustomerPlatformLabel( QWidget *parent = 0 );
    ~CustomerPlatformLabel();
public:
    void setText( QString strText );
    void paintEvent(QPaintEvent *event);
private:
    QString m_sText;
};

#endif // CUSTOMERPLATFORMLABEL_H
