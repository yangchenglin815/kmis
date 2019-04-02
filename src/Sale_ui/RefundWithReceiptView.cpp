#include "RefundWithReceiptView.h"
#include <QMouseEvent>
#include <QPainter>

static int nbuttonLeftXPos = -1;
static int nbuttonRightXPos = -1;

enum RefundWithReceipItemROLE
{
    e_RefundWithReceipItemInfo = Qt::UserRole + 1
};

ReceipRefundDelegate::ReceipRefundDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void ReceipRefundDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_RefundWithReceipItemInfo);
    if (v_itemInfo.canConvert<RefundWithReceiptInfo>())
    {
        RefundWithReceiptInfo refundInfo = v_itemInfo.value<RefundWithReceiptInfo>();
        paintContent(painter, option, refundInfo);
    }

    painter->restore();
}

void ReceipRefundDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const RefundWithReceiptInfo &rInfo) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int nHeight = option.rect.height();
    static const int c_nLeftMargin = 26;
    const int c_nFirstStartX = xPos + c_nLeftMargin;
    static const int c_nFirstColWidth = 50;
    QFont font;
    font.setPixelSize(12);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor("#666666");
    painter->setPen(pen);

    // 第一列序号
    QRect textRect(c_nFirstStartX, yPos, c_nFirstColWidth, nHeight);
    painter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(rInfo.nPos));

    // 第二列退款方式
    const int c_nSecondStartX = c_nFirstStartX + c_nFirstColWidth;
    static const int c_nSecondColWidth = 98;
    QRect textRect2(c_nSecondStartX, yPos, c_nSecondColWidth, nHeight);
    painter->drawText(textRect2, Qt::AlignLeft | Qt::AlignVCenter, rInfo.sRefundWay);

    // 第三列退款金额
    const int c_nThirdStartX = c_nSecondStartX + c_nSecondColWidth;
    static const int c_nThirdColWidth = 101;
    QRect textRect3(c_nThirdStartX, yPos, c_nThirdColWidth, nHeight);
    painter->drawText(textRect3, Qt::AlignLeft | Qt::AlignVCenter, QString("￥%1").arg(rInfo.nRefundSum));

    // 第四列退款状态
    const int c_nFourthStartX = c_nThirdStartX + c_nThirdColWidth;
    static const int c_nFourthColWidth = 112;
    QRect textRect4(c_nFourthStartX, yPos, c_nFourthColWidth, nHeight);
    painter->drawText(textRect4, Qt::AlignLeft | Qt::AlignVCenter, rInfo.sRefundState);

    // 第五列操作按钮
    const int c_nButtonPicWidth = 75;
    const int c_nButtonPicHeight = 36;
    const int c_nFifthStartX = c_nFourthStartX + c_nFourthColWidth;
    const int c_nFifthStartY = yPos + (nHeight - c_nButtonPicHeight)/2;
    QRect pixmapRect5(c_nFifthStartX, c_nFifthStartY, c_nButtonPicWidth, c_nButtonPicHeight);
    QPixmap buttonPixmap(":/paymentImage/refund_nomal.png");
    painter->drawPixmap(pixmapRect5, buttonPixmap.scaled(c_nButtonPicWidth, c_nButtonPicHeight));

    QFont buttonFont;
    buttonFont.setPixelSize(12);
    buttonFont.setFamily("微软雅黑");
    painter->setFont(buttonFont);
    QPen buttonPen;
    buttonPen.setColor("#ffffff");
    painter->setPen(buttonPen);
    QRect textRect5(c_nFifthStartX, yPos, c_nButtonPicWidth, nHeight);
    painter->drawText(textRect5, Qt::AlignHCenter | Qt::AlignVCenter, QStringLiteral("退款"));
    nbuttonLeftXPos = c_nFifthStartX;
    nbuttonRightXPos = c_nFifthStartX + c_nButtonPicWidth;

    // 分割线
    QPen linePen;
    linePen.setColor("#ededed");
    painter->setPen(linePen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + option.rect.width(), yPos + nHeight - 1);
}

RefundWithReceiptView::RefundWithReceiptView(QWidget *parent)
    :QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(54)
{
    init();
}

void RefundWithReceiptView::appendItem(const RefundWithReceiptInfo &rInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (m_ItemKeyIdMap.contains(rInfo.sRefundSequence))// 更新
    {
        pItem = m_ItemKeyIdMap.value(rInfo.sRefundSequence);
    }
    else // 添加
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(rInfo.sRefundSequence, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }

    QVariant variant;
    variant.setValue(rInfo);
    pItem->setData(variant, e_RefundWithReceipItemInfo);
}

void RefundWithReceiptView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void RefundWithReceiptView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    QModelIndex index = indexAt(event->pos());
    QVariant v_orderItemInfo = index.data(e_RefundWithReceipItemInfo);
    if (!v_orderItemInfo.canConvert<RefundWithReceiptInfo>())
    {
        return;
    }

    RefundWithReceiptInfo refundWithReceiptInfo = v_orderItemInfo.value<RefundWithReceiptInfo>();
    if (event->pos().x() >= nbuttonLeftXPos && event->pos().x() <= nbuttonRightXPos)
    {
        emit sigButtonClicked(refundWithReceiptInfo.sRefundSequence);
    }
}

void RefundWithReceiptView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new ReceipRefundDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    setSelectionMode(NoSelection);
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}


