#include "StockGoodsSelectListView.h"
#include "../data/constData.h"
#include <QPainter>
#include <QMouseEvent>

enum StockGoodsSelectItemType
{
    e_stockGoodsSelectInfo = Qt::UserRole + 1,
};

StockGoodsSelectDelegate::StockGoodsSelectDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void StockGoodsSelectDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_stockGoodsSelectInfo);
    if (v_itemInfo.canConvert<StockSelectGoodsInfo>())
    {
        bool bSelected = false;
        if (option.state & QStyle::State_Selected)
        {
            bSelected = true;
            QRect rect = option.rect;
            rect.setX(rect.x() + 1);
            rect.setWidth(rect.width() - 2);
            painter->fillRect(rect, QBrush(QColor(c_sThemeColor)));
        }
        StockSelectGoodsInfo selectGoodsInfo = v_itemInfo.value<StockSelectGoodsInfo>();
        paintContent(painter, option, selectGoodsInfo, bSelected);
    }

    painter->restore();
}

void StockGoodsSelectDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const StockSelectGoodsInfo &rInfo, bool bSelected) const
{
    paintSeqCol(painter, option, rInfo, bSelected);
    paintGoodsNameCol(painter, option, rInfo, bSelected);
    paintOtherCol(painter, option, rInfo, bSelected);
    paintLine(painter, option);
}

void StockGoodsSelectDelegate::paintSeqCol(QPainter *painter, const QStyleOptionViewItem &option, const StockSelectGoodsInfo &rInfo, bool bSelected) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    const int fontSize = 14*g_heightRate;
    QFont font;
    font.setPixelSize(fontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected?"#ffffff":"#333333");
    painter->setPen(pen);
    const int c_nColWidth = 36*g_heightRate;
    QRect textRec(xPos, yPos, c_nColWidth, option.rect.height());
    painter->drawText(textRec, Qt::AlignCenter, rInfo.sSeq);
}

void StockGoodsSelectDelegate::paintGoodsNameCol(QPainter *painter, const QStyleOptionViewItem &option, const StockSelectGoodsInfo &rInfo, bool bSelected) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    const int nLeftSpace = 36*g_heightRate;
    const int nTopSpace = 12*g_heightRate;
    int startXPos = xPos + nLeftSpace;
    int startYPos = yPos + nTopSpace;
    const int fontSize = 14*g_heightRate;
    QFont font;
    font.setPixelSize(fontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected ? "#ffffff" : "#333333");
    painter->setPen(pen);

    QString strName = "";
    if( rInfo.sShortName.isEmpty() ) {
        strName = rInfo.sName;
    } else {
        strName = rInfo.sShortName;
    }

    int goodsNameWidth = painter->fontMetrics().width(strName);
    QRect goodsNameRect(startXPos, startYPos, goodsNameWidth, fontSize);
    painter->drawText(goodsNameRect, Qt::AlignLeft | Qt::AlignVCenter, strName);
    pen.setColor(bSelected ? "#ffffff" : "#999999");
    painter->setPen(pen);
    startXPos += goodsNameWidth + 2;
    QRect goodsUnitRect(startXPos, startYPos, option.rect.width(), fontSize);
    painter->drawText(goodsUnitRect, Qt::AlignLeft | Qt::AlignVCenter, QString("( %1 )").arg(rInfo.sWeighUnit));
}

void StockGoodsSelectDelegate::paintOtherCol(QPainter *painter, const QStyleOptionViewItem &option, const StockSelectGoodsInfo &rInfo, bool bSelected) const
{
    const int fontSize = 12*g_heightRate;
    QFont font;
    font.setPixelSize(fontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected ? "#ffffff" : "#ea8852");
    painter->setPen(pen);

    int xPos = option.rect.x();
    int yPos = option.rect.y();
    const int nLeftSpace = 124*g_heightRate;
    const int nTopSpace = 32*g_heightRate;
    int nStartXPos = xPos + nLeftSpace;
    int nStartYPos = yPos + nTopSpace;

    const int nFirstColWidth = 80*g_heightRate;
    const int nSecondColWidth = 80*g_heightRate;
    // 实盘数量
    QRect rec11(nStartXPos, nStartYPos, nFirstColWidth, fontSize);
    painter->drawText(rec11, Qt::AlignLeft | Qt::AlignVCenter, QString::number(rInfo.fRealStockNum, 'f', 2));

    // 进价差异金额
    nStartXPos += nFirstColWidth;
    QRect rect12(nStartXPos, nStartYPos, nSecondColWidth, fontSize);
    painter->drawText(rect12, Qt::AlignLeft | Qt::AlignVCenter, QString("￥%1").arg(QString::number(rInfo.fBuyDifferPrice, 'f', 2)));
}

void StockGoodsSelectDelegate::paintLine(QPainter *painter, const QStyleOptionViewItem &option) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    QPen pen;
    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + option.rect.height(), xPos + option.rect.width(), yPos + option.rect.height());
}

StockGoodsSelectListView::StockGoodsSelectListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51*g_heightRate)
    , m_nSelectKeyId(-1)
{
    init();
}

void StockGoodsSelectListView::appendItem(const StockSelectGoodsInfo &selectGoodsInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(selectGoodsInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(selectGoodsInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(selectGoodsInfo.nId);
    }

    QVariant variant;
    variant.setValue(selectGoodsInfo);
    pItem->setData(variant, e_stockGoodsSelectInfo);

    if (m_nSelectKeyId == selectGoodsInfo.nId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void StockGoodsSelectListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

bool StockGoodsSelectListView::isExistItem(int nKeyId)
{
    return m_ItemKeyIdMap.contains(nKeyId);
}

int StockGoodsSelectListView::getSelectKeyId()
{
    return m_nSelectKeyId;
}

void StockGoodsSelectListView::setSelectKeyId(int nKeyId)
{
    m_nSelectKeyId = nKeyId;
}

bool StockGoodsSelectListView::getSelectItem(StockSelectGoodsInfo &selectGoodsInfo)
{
    if ((m_nSelectKeyId > 0) && m_ItemKeyIdMap.contains(m_nSelectKeyId))
    {
        QStandardItem* pItem = m_ItemKeyIdMap.value(m_nSelectKeyId);
        QVariant v_itemInfo = pItem->data(e_stockGoodsSelectInfo);
        if (v_itemInfo.canConvert<StockSelectGoodsInfo>())//可以转换
        {
            selectGoodsInfo = v_itemInfo.value<StockSelectGoodsInfo>();
            return true;
        }
        return false;
    }
    return false;
}

void StockGoodsSelectListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    StockSelectGoodsInfo selectGoodsInfo;
    QVariant v_itemInfo = index.data(e_stockGoodsSelectInfo);
    if (v_itemInfo.canConvert<StockSelectGoodsInfo>())//可以转换
    {
        selectGoodsInfo = v_itemInfo.value<StockSelectGoodsInfo>();
        m_nSelectKeyId = selectGoodsInfo.nId;
        emit sigClickItem(selectGoodsInfo);
    }
}

void StockGoodsSelectListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new StockGoodsSelectDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}



