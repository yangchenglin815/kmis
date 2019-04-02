#include "StockOrderListView.h"
#include <QMouseEvent>
#include <QPainter>
#include "../data/enumData.h"
#include "../data/constData.h"
#include "../util/CommonFun.h"

enum StockOrderItemType
{
    e_stockOrderInfo = Qt::UserRole + 1,
};

StockOrderDelegate::StockOrderDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void StockOrderDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_stockOrderInfo);
    if (v_itemInfo.canConvert<StockOrderInfo>())
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
        StockOrderInfo stockOrderInfo = v_itemInfo.value<StockOrderInfo>();
        paintContent(painter, option, stockOrderInfo, bSelected);
    }

    painter->restore();
}

void StockOrderDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const StockOrderInfo &stockOrderInfo, bool bSelected) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
    const int nWidth = option.rect.width();
    const int nHeight = option.rect.height();

    const int nfontSize = 14*g_widthRate;
    QFont font;
    font.setPixelSize(nfontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected?"#ffffff":"#333333");
    painter->setPen(pen);

    // 单号
    const int nLeftSpace = 20*g_widthRate;
    const int nFirstWidth = 180*g_widthRate;
    int nFirstXPos = xPos + nLeftSpace;
    QRect firstRect(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect, Qt::AlignLeft | Qt::AlignVCenter, stockOrderInfo.sOrderNum);

    // 制单时间
    const int nSecondWidth = 162*g_widthRate;
    int nSecondXPos = nFirstXPos + nFirstWidth;
    QRect secondRect(nSecondXPos, yPos, nSecondWidth, nHeight);
    painter->drawText(secondRect, Qt::AlignLeft | Qt::AlignVCenter, CommonFun::trunkDateTime(stockOrderInfo.sCreateTime));

    // 制单人/审核人
    const int nThirdWidth = 146*g_widthRate;
    int nThirdXPos = nSecondXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    QString sMakerAndChecker = QString("%1/%2").arg(stockOrderInfo.sMaker).arg(stockOrderInfo.sChecker);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, sMakerAndChecker);

    // 修改时间
    const int nFourthWidth = 172*g_widthRate;
    int nFourthXPos = nThirdXPos + nThirdWidth;
    QRect fourthRect(nFourthXPos, yPos, nFourthWidth, nHeight);
    painter->drawText(fourthRect, Qt::AlignLeft | Qt::AlignVCenter, CommonFun::trunkDateTime(stockOrderInfo.sMakeTime));

    // 状态
    QString fourthText = "";
    if (stockOrderInfo.nState == e_stockOrderNotCheck)
    {
        fourthText = QStringLiteral("未审核");
        pen.setColor(bSelected?"#ffffff":"#999999");
    }
    else
    {
        fourthText = QStringLiteral("已审核");
        pen.setColor(bSelected?"#ffffff":"#75ab57");
    }
    painter->setPen(pen);
    const int nFifthWidth = 78*g_widthRate;
    int nFifthXPos = nFourthXPos + nFourthWidth;
    QRect fifthRect(nFifthXPos, yPos, nFifthWidth, nHeight);
    painter->drawText(fifthRect, Qt::AlignLeft | Qt::AlignVCenter, fourthText);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

StockOrderListView::StockOrderListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51*g_heightRate)
    , m_nSelectKeyId(-1)
{
    init();
}

void StockOrderListView::appendItem(const StockOrderInfo &stockOrderInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(stockOrderInfo.nOrderId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(stockOrderInfo.nOrderId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(stockOrderInfo.nOrderId);
    }

    QVariant variant;
    variant.setValue(stockOrderInfo);
    pItem->setData(variant, e_stockOrderInfo);

    if (m_nSelectKeyId == stockOrderInfo.nOrderId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void StockOrderListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

int StockOrderListView::getSelectKeyId()
{
    return m_nSelectKeyId;
}

void StockOrderListView::setSelectKeyId(int nKeyId)
{
    m_nSelectKeyId = nKeyId;
}

void StockOrderListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    StockOrderInfo stockOrderInfo;
    QVariant v_itemInfo = index.data(e_stockOrderInfo);
    if (v_itemInfo.canConvert<StockOrderInfo>())//可以转换
    {
        stockOrderInfo = v_itemInfo.value<StockOrderInfo>();
        m_nSelectKeyId = stockOrderInfo.nOrderId;
        emit sigClickItem(stockOrderInfo);
    }
}

void StockOrderListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new StockOrderDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}



