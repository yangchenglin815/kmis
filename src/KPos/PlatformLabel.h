#ifndef PLATFORMLABEL_H
#define PLATFORMLABEL_H
#include <QLabel>
#include <QPaintEvent>

/**
 * @brief The PlatformLabel class  台秤数值显示类
 */
class PlatformLabel : public QLabel
{
    Q_OBJECT
public:
    explicit PlatformLabel( QWidget *parent = 0);
    ~PlatformLabel();
public:
    void setfGoodsWeight( QString strGoodsWeight );

    void paintEvent( QPaintEvent *event );//绘图时间
public slots:
signals:
private:
    QString getMinusImage();//负号
    QString getDataImage( int nData );//数字
    QString getPointImage();//小数点
    QString getUnitImage();//单位
private:
    QString m_sGoodsWeight;
};

#endif // PLATFORMLABEL_H
