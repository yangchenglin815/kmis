#include "ReceiptDetialListView.h"
#include <QPainter>
#include <QMouseEvent>
#include "constData.h"

enum ItemType
{
    e_itemInfo = Qt::UserRole + 1,
};

ReceiptDetialListDelegate::ReceiptDetialListDelegate(QObject *parent)
  : QStyledItemDelegate(parent)
{

}

void ReceiptDetialListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_itemInfo);
    if(v_itemInfo.canConvert<SaleDetails>()){
        SaleDetails receiptInfo = v_itemInfo.value<SaleDetails>();
        paintContent(painter, option, receiptInfo);
    }
    painter->restore();
}

void ReceiptDetialListDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const SaleDetails &detialInfo) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
    const int nWidth = option.rect.width();
    const int nHeight = option.rect.height();

    QFont font;
    font.setPixelSize(f_fontSizeMode1*g_widthRate);
    font.setFamily(f_fontStyle);
    painter->setFont(font);
    QPen pen;
    pen.setColor(QColor(f_fontColorBlack));
    painter->setPen(pen);

    const int nLeftSpace = 21*g_widthRate;

    // 序号
    const int nFirstWidth = 50*g_widthRate;
    int nFirstXPos = xPos + nLeftSpace;
    QRect firstRect1(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect1, Qt::AlignLeft | Qt::AlignVCenter, QString::number(detialInfo.nGoodsId));

    // 商品
    const int nSecondWidth = 130*g_widthRate;
    const int nSecondTwoRowSpace = 6*g_widthRate;
    int nSecondXPos = nFirstXPos + nFirstWidth;
    int nSecondYPos = yPos + (nHeight - (f_fontSizeMode1 + f_fontSizeMode2 + nSecondTwoRowSpace))/2;
    QRect secondRect(nSecondXPos, nSecondYPos, nSecondWidth, f_fontSizeMode1);
    painter->drawText(secondRect, Qt::AlignLeft | Qt::AlignVCenter, detialInfo.strGoodsName);

    // 商品编号
    font.setPixelSize(f_fontSizeMode2);
    painter->setFont(font);
    pen.setColor("#666666");
    painter->setPen(pen);
    nSecondYPos += f_fontSizeMode1 + nSecondTwoRowSpace;
    QRect thirdRect(nSecondXPos, nSecondYPos, nSecondWidth, f_fontSizeMode2);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, detialInfo.strGoodsScode + QString(" (%1)").arg(detialInfo.goodsInfo.sUnit));

    // 单价
    font.setPixelSize(f_fontSizeMode1);
    painter->setFont(font);
    pen.setColor(QColor(f_fontColorBlack));
    painter->setPen(pen);
    const int nFourthWidth = 70*g_widthRate;
    int nFourthXPos = nSecondXPos + nSecondWidth + 40*g_widthRate;
    QRect fourthRect(nFourthXPos, yPos, nFourthWidth, nHeight);
    painter->drawText(fourthRect, Qt::AlignLeft | Qt::AlignVCenter, "¥" + QString::number(detialInfo.goodsInfo.fPrice, 'f', 2));

    // 数量
    const int nFifthWidth = 60*g_widthRate;
    int nFifthXPos = nFourthXPos + nFourthWidth;
    QRect fifththRect(nFifthXPos, yPos, nFifthWidth, nHeight);
    painter->drawText(fifththRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(detialInfo.goodsInfo.fNumber, 'f', 2));

    //金额
    const int nSixthWidth = 110*g_widthRate;
    int nSixthXPos = nFifthXPos + nFifthWidth;
    QRect sixthRect(nSixthXPos, yPos, nSixthWidth, nHeight);
    painter->drawText(sixthRect, Qt::AlignLeft | Qt::AlignVCenter, QString("¥%1").arg(detialInfo.goodsInfo.sSumPrice) );

    // 状态
    pen.setColor(QColor(f_fontColorOrange));
    painter->setPen(pen);
    const int nSeventhWidth = 80*g_widthRate;
    int nSevenXPos = nSixthXPos + nSixthWidth;
    QRect seventhRect(nSevenXPos, yPos, nSeventhWidth, nHeight);
    QString status;
    if(detialInfo.pStatus == 1){
        status = "改价";
    }
    else if(detialInfo.pStatus == 0){
        if(detialInfo.nStatus == -1){
            status = "取消";
        }
        else if(detialInfo.nStatus == 1){
            pen.setColor(QColor(f_fontColorGreen));
            painter->setPen(pen);
            status = "正常";
        }
    }
    painter->drawText(seventhRect, Qt::AlignLeft | Qt::AlignVCenter, status);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

ReceiptDetialListView::ReceiptDetialListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51)
    , m_nSelectKetId("")
{
    init();
}

void ReceiptDetialListView::appendItems(const SaleDetails &receiptInfo)
{
    if(m_pStandardItemModel == NULL){
        return;
    }

    QStandardItem* pItem = NULL;
    if(!m_ItemKeyIdMap.contains(receiptInfo.strGoodsScode)){
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(receiptInfo.strGoodsScode, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(receiptInfo.strGoodsScode);
    }

    QVariant variant;
    variant.setValue(receiptInfo);
    pItem->setData(variant, e_itemInfo);

    if(m_nSelectKetId == receiptInfo.strGoodsScode){
        this->setCurrentIndex(pItem->index());
    }
}

void ReceiptDetialListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void ReceiptDetialListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new ReceiptDetialListDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}

void ReceiptDetialListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());
    SaleDetails checkDetialInfo;
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<SaleDetails>())//可以转换
    {
        checkDetialInfo = v_itemInfo.value<SaleDetails>();
        m_nSelectKetId = checkDetialInfo.strGoodsScode;
    }
}
