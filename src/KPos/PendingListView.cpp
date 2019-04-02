#include "PendingListView.h"
#include <QPainter>
#include <QMouseEvent>

static const int c_nOrderItemHeight = 54;
static int nUnpendingButtonLeftXPos;
static int nUnpendingButtonRightXPos;
static int nDeleteButtonLeftXPos;
static int nDeleteButtonRightXpos;
static int nTopSpace = 10;
static int nMidSpace = 4;
static int nTextHeight = 14;
static QString strCreatTimeText = "创建时间:";

enum OrderItemROLE
{
    e_OrderItemInfo = Qt::UserRole + 1
};


PendingListDelegate::PendingListDelegate()
{

}

void PendingListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_OrderItemInfo);
    if (v_itemInfo.canConvert<OrderInfo>())
    {
        bool bSelected = false;
        OrderInfo orderInfo = v_itemInfo.value<OrderInfo>();
        if ( orderInfo.bSelect )
        {
            bSelected = true;
            painter->drawPixmap(option.rect, QPixmap(":/saleImage/rect.png"));
        }
        else
        {
           bSelected = false;
        }
        paintOrderInfo(painter, option, orderInfo, bSelected);
    }

    painter->restore();
}

void PendingListDelegate::paintOrderInfo(QPainter *painter, const QStyleOptionViewItem &option, const OrderInfo &rInfo, bool bSelected) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    static const int c_nLeftMargin = 10;
    const int c_nFirstStartX = xPos + c_nLeftMargin;
    static const int c_nFirstColWidth = 88;
    QFont font;
    font.setPixelSize(12);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    if (bSelected)
    {
       pen.setColor("#ffffff");
    }
    else
    {
        pen.setColor("#666666");
    }
    painter->setPen(pen);

    // 第一列流水号
    static const int c_nSecondColWidth = 91;
    QRect textRect(c_nFirstStartX, yPos+nTopSpace, c_nFirstColWidth + c_nSecondColWidth, nTextHeight);
    painter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, rInfo.sOrderSequence);

    // 第二列订单创建时间
    const int c_nSecondStartX = c_nFirstStartX + c_nFirstColWidth;
    QRect textRect2(c_nFirstStartX, textRect.y()+textRect.height()+nMidSpace, c_nFirstColWidth + c_nSecondColWidth, nTextHeight);
    QString strCreatDt = strCreatTimeText + rInfo.sCreateTime;
    painter->drawText(textRect2, Qt::AlignLeft | Qt::AlignVCenter, strCreatDt );

    // 第三列解单按钮
    const int c_nThirdStartX = c_nSecondStartX + c_nSecondColWidth;

    static const int c_nThirdColWidth = 45;
    static const int c_nThirdColHeight = 38;
    static const int c_nButtonTopMargin = (c_nOrderItemHeight - c_nThirdColHeight)/2 + 4;
    const int c_nThirdStartY = yPos + c_nButtonTopMargin;
    QRect pixmapRect3(c_nThirdStartX, c_nThirdStartY, c_nThirdColWidth, c_nThirdColHeight);
    QPixmap thirdButtonPixmap(":/pendingImage/unPending.png");
    thirdButtonPixmap = thirdButtonPixmap.scaled(c_nThirdColWidth, c_nThirdColHeight);
    painter->drawPixmap(pixmapRect3, thirdButtonPixmap);

    QFont buttonFont;
    buttonFont.setPixelSize(12);
    buttonFont.setFamily("微软雅黑");
    painter->setFont(buttonFont);
    QPen buttonPen;
    buttonPen.setColor("#ffffff");
    painter->setPen(buttonPen);
    static const int c_nTwoButtonSpace = 5;
    QRect textRect3(c_nThirdStartX, yPos, c_nThirdColWidth - c_nTwoButtonSpace, c_nOrderItemHeight);
    painter->drawText(textRect3, Qt::AlignHCenter | Qt::AlignVCenter, QStringLiteral("解单"));
    nUnpendingButtonLeftXPos = c_nThirdStartX;
    nUnpendingButtonRightXPos = c_nThirdStartX + c_nThirdColWidth - c_nTwoButtonSpace;

    // 第四列删除订单按钮
    const int c_nFourthStartX = c_nThirdStartX + c_nThirdColWidth;
    const int c_nFourthSatrtY = c_nThirdStartY;
    const int c_nFourthColWidth = c_nThirdColWidth;
    const int c_nFourthColHeight = c_nThirdColHeight;
    QRect pixmapRect4(c_nFourthStartX, c_nFourthSatrtY, c_nFourthColWidth, c_nFourthColHeight);
    QPixmap fourthButtonPixmap(":/pendingImage/deleteOrder.png");
    fourthButtonPixmap = fourthButtonPixmap.scaled(c_nThirdColWidth, c_nThirdColHeight);
    painter->drawPixmap(pixmapRect4, fourthButtonPixmap);

    QRect textRect4(c_nFourthStartX, yPos, c_nFourthColWidth - c_nTwoButtonSpace, c_nOrderItemHeight);
    painter->drawText(textRect4, Qt::AlignHCenter | Qt::AlignVCenter, QStringLiteral("删除"));
    nDeleteButtonLeftXPos = c_nFourthStartX;
    nDeleteButtonRightXpos = c_nFourthStartX + c_nFourthColWidth - c_nTwoButtonSpace;

    // 分割线
    QPen linePen;
    linePen.setColor("#ededed");
    painter->setPen(linePen);
    painter->drawLine(xPos, yPos + c_nOrderItemHeight -1, xPos + option.rect.width(), yPos + c_nOrderItemHeight -1);
}

PendingListView::PendingListView(QWidget *parent)
    : QListView(parent),
      m_pStandardItemModel(NULL)
{
    init();
}

PendingListView::~PendingListView()
{
    clearItem();
}

void PendingListView::appendItem(const OrderInfo &rInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (m_ItemKeyIdMap.contains(rInfo.sOrderSequence))// 更新
    {
        pItem = m_ItemKeyIdMap.value(rInfo.sOrderSequence);
    }
    else // 添加
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(rInfo.sOrderSequence, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, c_nOrderItemHeight));
    }

    QVariant variant;
    variant.setValue(rInfo);
    pItem->setData(variant, e_OrderItemInfo);
}

void PendingListView::removeItem( const QString &strOrderNum )
{
    if( !m_ItemKeyIdMap.contains( strOrderNum ) ) return;

    QStandardItem *pItem = m_ItemKeyIdMap.value( strOrderNum );
    int nRow = pItem->row();
    if( pItem == NULL || nRow < 0 ) return;

    m_pStandardItemModel->removeRow( nRow );
    m_ItemKeyIdMap.remove( strOrderNum );
}

bool PendingListView::findItem( const QString &strOrderNum )
{
    if( !m_ItemKeyIdMap.contains( strOrderNum ) ) {
        return false;
    }

    QStandardItem *pItem = m_ItemKeyIdMap.value( strOrderNum );
    int nRow = pItem->row();
    if( pItem == NULL || nRow < 0 ) return false;

    return true;
}

void PendingListView::clearItem()
{
    if (m_pStandardItemModel != NULL)
    {
        m_pStandardItemModel->clear();
    }
    m_ItemKeyIdMap.clear();
}

int PendingListView::getItemsNum()
{
    return m_ItemKeyIdMap.size();
}

int PendingListView::getItemHeight()
{
    return c_nOrderItemHeight;
}

void PendingListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    QModelIndex index = indexAt(event->pos());
    QVariant v_orderItemInfo = index.data(e_OrderItemInfo);
    if (!v_orderItemInfo.canConvert<OrderInfo>())
    {
        return;
    }

    OrderInfo orderItemInfo = v_orderItemInfo.value<OrderInfo>();
    if (event->pos().x() >= nUnpendingButtonLeftXPos && event->pos().x() <= nUnpendingButtonRightXPos)
    {
        emit sigUnPending(orderItemInfo.sOrderSequence);
        init();
    }
    else if (event->pos().x() >= nDeleteButtonLeftXPos && event->pos().x() <= nDeleteButtonRightXpos)
    {
        emit sigDeleteOrder(orderItemInfo.sOrderSequence);
    } else {
        if( !orderItemInfo.bSelect ) {
            emit sig_selectPending( orderItemInfo );
        }
    }
}

void PendingListView::init()
{
    setItemDelegateForColumn(0, new PendingListDelegate);
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}
