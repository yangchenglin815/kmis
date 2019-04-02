#include "ReceiptListView.h"
#include <QPainter>
#include <QMouseEvent>
#include "constData.h"

enum ItemType
{
    e_itemInfo = Qt::UserRole + 1,
};

ReceiptListDelegate::ReceiptListDelegate(QObject *parent)
 : QStyledItemDelegate(parent)
{

}

void ReceiptListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
   painter->save();
   QVariant v_itemInfo = index.data(e_itemInfo);
   if(v_itemInfo.canConvert<ReceiptInfo>()){
       bool bSelected = false;
       if(option.state & QStyle::State_Selected){
           bSelected = true;
           QRect rect = option.rect;
           rect.setX(rect.x() + 1);
           rect.setWidth(rect.width() -2);
           painter->fillRect(rect, QBrush(QColor(c_sThemeColor)));
       }
       ReceiptInfo receiptInfo = v_itemInfo.value<ReceiptInfo>();
       paintContent(painter, option, receiptInfo, bSelected);
   }
   painter->restore();
}

void ReceiptListDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const ReceiptInfo &receiptInfo, bool bSelected) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
    const int nWidth = option.rect.width();
    const int nHeight = option.rect.height();

    QFont font;
    font.setPixelSize(f_fontSizeMode1);
    font.setFamily(f_fontStyle);
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected?QColor(f_fontColorWhite):QColor(f_fontColorBlack));
    painter->setPen(pen);

    const int nLeftSpace = 32*g_widthRate;

    // 小票编号
    const int nFirstWidth = 175*g_widthRate;
    int nFirstXPos = xPos + nLeftSpace;
    QRect firstRect(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect, Qt::AlignLeft | Qt::AlignVCenter, receiptInfo.bScode);

    // 收银员
    const int nSecondWidth = 96*g_widthRate;
    int nSecondXPos = nFirstXPos + nFirstWidth;
    QRect secondRect(nSecondXPos, yPos, nSecondWidth, nHeight);
    painter->drawText(secondRect, Qt::AlignLeft | Qt::AlignVCenter, receiptInfo.bSaleman);

    // 导购员
    const int nThirdWidth = 106*g_widthRate;
    int nThirdXPos = nSecondXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, receiptInfo.bSaleGuide);

    // 交易时间
    const int nFourthWidth = 170*g_widthRate;
    int nFourthXPos = nThirdXPos + nThirdWidth;
    QRect fourthRect(nFourthXPos, yPos, nFourthWidth, nHeight);
    painter->drawText(fourthRect, Qt::AlignLeft | Qt::AlignVCenter, receiptInfo.bDealTime);


    //类型
    const int nFifthWidth = 120*g_widthRate;
    int nFifthXPos = nFourthXPos + nFourthWidth;
    QRect fifthRect(nFifthXPos, yPos, nFifthWidth, nHeight);
    QString type;
    if(receiptInfo.type == 0){
        type = "销售";
    }
    else if(receiptInfo.type == 1){
        type = "退货";
    }
    else if(receiptInfo.type == 2){
        type = "会员充值";
    }
    else if(receiptInfo.type == 3){
        type = "储蓄卡充值";
    }
    else if(receiptInfo.type == 4){
        type = "退充值";
    }
    painter->drawText(fifthRect, Qt::AlignLeft | Qt::AlignVCenter, type);

    // 状态
    pen.setColor(f_fontColorOrange);
    painter->setPen(pen);
    const int nSixthWidth = 100*g_widthRate;
    int nSixthXPos = nFifthXPos + nFifthWidth;
    QRect sixthRect(nSixthXPos, yPos, nSixthWidth, nHeight);
    QString state;
    if(receiptInfo.state == -1){
        state = "已取消";
        pen.setColor(QColor(f_fontColorOrange));
    }
    else if(receiptInfo.state == 1){
        state = "正常";
        pen.setColor(QColor(f_fontColorGreen));
    }
    painter->setPen(pen);
    painter->drawText(sixthRect, Qt::AlignLeft | Qt::AlignVCenter, state);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}


ReceiptListView::ReceiptListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51)
    , m_nSelectKeyId("")
{
   init();
}

void ReceiptListView::appendItems(const ReceiptInfo &receiptInfo)
{
    if(m_pStandardItemModel == NULL){
        return;
    }

    QStandardItem* pItem = NULL;
    if(!m_ItemKeyIdMap.contains(receiptInfo.bScode)){
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(receiptInfo.bScode, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(receiptInfo.bScode);
    }

    QVariant variant;
    variant.setValue(receiptInfo);
    pItem->setData(variant, e_itemInfo);

    if(m_nSelectKeyId == receiptInfo.bScode){
        this->setCurrentIndex(pItem->index());
    }
}

void ReceiptListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

QString ReceiptListView::getSelectIdList()
{
    return m_nSelectKeyId;
}

void ReceiptListView::setSelectKeyId(QString nKeyId)
{
    m_nSelectKeyId = nKeyId;
}

void ReceiptListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    ReceiptInfo receiptInfo;
    QVariant v_itemInfo = index.data(e_itemInfo);
    if(v_itemInfo.canConvert<ReceiptInfo>()){
        receiptInfo = v_itemInfo.value<ReceiptInfo>();
        m_nSelectKeyId = receiptInfo.bScode;
        emit sigClickItem(receiptInfo);
    }
}

void ReceiptListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new ReceiptListDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}

