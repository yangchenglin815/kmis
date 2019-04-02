#ifndef GOODSWIDGET_H
#define GOODSWIDGET_H

#include <QWidget>
#include <QList>
#include <GoodsCellButton.h>
#include "structData.h"
#include "enumData.h"

namespace Ui {
class GoodsWidget;
}

class GoodsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GoodsWidget(QWidget *parent = 0);
    ~GoodsWidget();

public:
    void setUpDownPageButton( QPushButton *pUpPageButton, QPushButton *pDownPageButton );
    void setColumn(int nColumn, int nGoodsWidgetType);
    void initGoodsInfoList(const QList<GoodsInfo > &listGoodsInfo, int nMovePosition);

signals:
    void sig_addGoodsToSaleList( GoodsInfo st_goodsInfo );
public slots:
    void slot_addGoodsInfo( QList<GoodsInfo> listGoodsInfo );//加载商品信息
    void slot_upPage();
    void slot_downPage();
private:
    void init();
    void initConnect();
    void clearText();
    void generateGoodsList();//重新生成商品列表
    int getMaxTasteType( QString strGoodsCode );
    bool getGoodsAllTasteType(QString strGoodsCode, QList<GoodsInfo> &listGoodsTasteType );
    void setCurPage( int nCurPage, int nTotalPage );//设置当前页
    void updateGoodsInfo( QList<GoodsInfo> listGoodsInfo );//更新商品信息
    void updatePluGoodsInfo( QList<GoodsInfo> listPluGoodsInfo );//更新plu商品信息
    void setGoodsWidgetType(int nGoodsWidgetType);//设置窗口类型
    void curPageChanged();

private slots:
    void slot_goodsButtonClicked(QString strBarCode, GoodsWidgetType e_goodsWidget );
    void slot_goodsCellMovePosition(int nPosition);

private:
    Ui::GoodsWidget *ui;

    int m_nGoodsWidgetType;
    //上下页按钮指针
    QPushButton* m_pUpPageButton;
    QPushButton* m_pDownPageButton;
    int m_nCurPage;
    int m_nTotalPage;
    int m_nOnePageCount;//商品一页显示的数量
    bool m_bShowSubGoods;//商品界面显示子商品

    QList<GoodsCellButton *> m_goodsCellButtonList;//商品按钮列表

    QList<GoodsInfo> m_listGoodsInfo;//商品列表
    QString m_sBarCode;//所有商品的唯一标识码
};

#endif // GOODSWIDGET_H
