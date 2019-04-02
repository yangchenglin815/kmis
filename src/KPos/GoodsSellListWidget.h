#ifndef GOODSSELLLISTWIDGET_H
#define GOODSSELLLISTWIDGET_H

#include <QWidget>
#include <QList>
#include "../data/structData.h"
#include "enumData.h"

class ModifyGoodsNumDlg;

namespace Ui {
class GoodsSellListWidget;
}

class GoodsSellListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GoodsSellListWidget(QWidget *parent = 0);
    ~GoodsSellListWidget();

    void initData();
    void generateSellList();
    void addGoodsInfo( GoodsInfo st_goodsInfo , QString strNum );
    void addGoodsInfo( SaleDetails &stSaleDetails , bool bSelect = true );
    void updateGoodsInfo( GoodsInfo st_goodsInfo );
    void clearGoodsInfo();//清除所有商品信息
    void cancelAllSelectGoods();//取消所有选中商品
    bool getSelectGoodsInfo( QList<int> &listSelectGoodsInfo );
    bool getSelectGoodsInfo( QList<SaleDetails> &listSaleDetails );
    bool getAllGoodsInfo( QList<SaleDetails> &listSaleDetails );
    void updateGoodsList();//更新商品列表
    void addSaleHead( const QString &strOrderNum );//加载订单信息

    void setSelectStatus( bool bSelect );
    bool isGoods( const QString sKeyId );
    int getSelectGoodsNum();
    int getGoodsNum();
    bool getSaleHead( SaleHead &stSaleHead );
    void setSaleHead( SaleHead stSaleHead );
    void setSaleHeadStatus( ESaleHeadStatus e_saleHeadStatus );
    void setMemStatus( bool bMemStatus );
    bool getMemStatus();
    void setSingleMaxNum( int nSingleMaxNum );
public slots:
    void slot_deleteSelectGoods();//删除选中商品
    void slot_clearAllGoods();//清除所有商品
    void slot_updateGoodsInfo( SaleDetails stSaleDetails );//更新商品信息
    void slot_updateGoodsInfo( const QList<SaleDetails> &listSaleDetails , bool bSaleHeadDis);
    void slot_ModifyGoodsNum();//修改商品数量
signals:
    /**
     * @brief sig_updateGoodsSumPrice
     * @param strSumPrice   显示总金额
     * @param strDisAmt     优惠总金额
     */
    void sig_updateGoodsSumPrice(QString strSumPrice, QString strDisAmt );
    void sig_addGoodsToSaleList( SaleDetails stSaleDetails );
private slots:
    void on_upPageButton_clicked();
    void on_downPageButton_clicked();
    void slot_selectGoods( GoodsDetailInfo st_goodsInfo );
    void slot_showModifyNumDlg( GoodsDetailInfo st_goodsInfo );
    void slot_ModifyGoodsNum( int nSaleDetailPos, QString strGoodsNum );
    void slot_showPromotionDlg();

private:
    void initCtrl();
    void initConnect();
    void initSaleHead();
    void setCurPage( int nCurPage, int nTotalPage );

    void updateSelectGoods();//更新选中的商品
    void deleteSelectGoods();//删除选中的商品
    void clearAllGoodsStatus();//清除所有商品的选中状态
    int findNoSelectGoods();//查找没有选中的商品数量
    void updateSaleHeadSumPrice();//更新商品显示总金额
    void updateSaleHeadDisPrice();//更新订单优惠金额
    void updateSaleHeadMemPrice();//更新订单会员优惠金额
    void updateSaleHeadDisRate();//更新订单折扣

    int getPageNum( int nGoodsPos );
    void goodsToSaleDetail( GoodsDetailInfo &stGoodsDetail, const GoodsInfo& stGoodsInfo );
    void saleDetailToGoods( GoodsInfo &stGoodsInfo, const GoodsDetailInfo &stGoodsDetail );
    void parsePromotion(PromotionDetails * PromotionInfo);
private:
    Ui::GoodsSellListWidget *ui;

    ModifyGoodsNumDlg *m_pModifyGoodsNumDlg;

    int m_nCurPage;
    int m_nTotalPage;
    SaleHead m_stSaleHead;
    QMap< int, SaleDetails > m_mapSaleDetailInfo;//key:序号，nPos
    QList<PromotionDetails * > m_listPromotionInfo;
    QList<int> m_listSelectGoodsInfo;//商品加入序列号，值不变：nSaleDetailPos
    int m_nOnePageCount;
    int m_nSaleDetailPos;//商品序号
    bool m_bMemSell;//会员销售状态

    bool m_bPromotioned;//是否享受满减优惠
    int m_nSingleMaxNum;//销售时单品最大数量
};

#endif // GOODSSELLLISTWIDGET_H
