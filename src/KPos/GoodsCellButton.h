#ifndef GOODSCELLBUTTON_H
#define GOODSCELLBUTTON_H

#include <QPushButton>
#include <QTimer>
#include "enumData.h"

class GoodsCellButton : public QPushButton
{
    Q_OBJECT

public:
    explicit GoodsCellButton(QWidget *parent = 0);
    void setGoodsInfo(QString strGoodsName, QString strPriceName, QString strBarCode, int nGoodsId, int nGoodsPosition);
    void setSelectedSelf();
    void setUnSelectedSelf();
    void setGoodsWidget(int nGoodsWidgetType);
    void setFontSize( int nPixSize );
    int getGoodsId();

protected:
    void paintEvent(QPaintEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    void initConnect();
    void showAdjustWidget();

private slots:
    void slot_onClicked();
    void slot_otherGoodsCellButtonClicked( QString strBarCode, GoodsWidgetType goodsWidgetType);
    void slot_checkClickType();

private:
    bool m_bSelected;
    int m_nGoodsId;
    QString m_sBarCode;
    int m_nGoodsWidgetType;
    int m_nPixSize;
    QString m_sGoodsName;
    QString m_sPriceName;
    int m_nGoodsPosition;
    QTimer m_timer;
    bool m_bDbClick;
};

#endif // GOODSCELLBUTTON_H
