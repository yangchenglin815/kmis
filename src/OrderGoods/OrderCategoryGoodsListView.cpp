#include "OrderCategoryGoodsListView.h"
#include <QPainter>
#include <QMouseEvent>
#include <QLineEdit>
#include <QDebug>

static int nLeftArrowStartXPos = -1;
static int nLeftArrowEndXPos = -1;
static int nRightArrowStartXPos = -1;
static int nRightArrowEndXPos = -1;

enum OrderCategoryGoodsType
{
    e_orderGoodsInfo
};

OrderCategoryGoodsDelegate::OrderCategoryGoodsDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{

}

void OrderCategoryGoodsDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_orderGoodsInfo);
    if (v_itemInfo.canConvert<OrderGoodsInfo>())
    {
        OrderGoodsInfo orderGoodsInfo = v_itemInfo.value<OrderGoodsInfo>();
        paintFirstColumn(painter, option, orderGoodsInfo);
        paintOtherColumn(painter, option, orderGoodsInfo);
    }

    painter->restore();
}

void OrderCategoryGoodsDelegate::paintFirstColumn(QPainter *painter, const QStyleOptionViewItem &option, const OrderGoodsInfo &orderGoodsInfo) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int nWidth = option.rect.width();
    int nHeight = option.rect.height();

    const int nFirstRowFontSize = 14;
    QFont font;
    font.setPixelSize(nFirstRowFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor("#333333");
    painter->setPen(pen);

    // 商品 -- 商品名称
    const int nLeftSpace = 12;
    const int nTopSpace = 8;
    int nFirstRowXPos = xPos + nLeftSpace;
    int nFirstRowYPos = yPos + nTopSpace;
    QRect firstRowRect(nFirstRowXPos, nFirstRowYPos, nWidth, nFirstRowFontSize);
    painter->drawText(firstRowRect, Qt::AlignLeft | Qt::AlignVCenter, orderGoodsInfo.sName);

    // 商品--商品编号(商品单位)
    const int nSecondFontSize = 12;
    const int nTwoRowSpace = 8;
    font.setPixelSize(nSecondFontSize);
    painter->setFont(font);
    pen.setColor("#999999");
    painter->setPen(pen);
    int nSecondRowXPos = nFirstRowXPos;
    int nSecondRowYPos = nFirstRowYPos + nFirstRowFontSize + nTwoRowSpace;
    QRect secondRowRect(nSecondRowXPos, nSecondRowYPos, nWidth, nSecondFontSize);
    QString secondText = QString("%1(%2)").arg(orderGoodsInfo.sCode).arg(orderGoodsInfo.sUnitSpecification);
    painter->drawText(secondRowRect, Qt::AlignLeft | Qt::AlignVCenter, secondText);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

void OrderCategoryGoodsDelegate::paintOtherColumn(QPainter *painter, const QStyleOptionViewItem &option, const OrderGoodsInfo &orderGoodsInfo) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
//    int nWidth = option.rect.width();
    const int nHeight = option.rect.height();

    const int nFirstRowFontSize = 14;
    QFont font;
    font.setPixelSize(nFirstRowFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);

    // 今日已订
    QPen pen;
    pen.setColor((orderGoodsInfo.nSaleNumberToday == 0) ? "#333333" : "#ea8852");
    painter->setPen(pen);
    const int nLeftSpace = 204;
    int nSecondColXPos = xPos + nLeftSpace;
    int nSecondColWidth = 76;
    QRect secondColRect(nSecondColXPos, yPos, nSecondColWidth, nHeight);
    painter->drawText(secondColRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(orderGoodsInfo.nSaleNumberToday));
    pen.setColor("#333333");
    painter->setPen(pen);

    // 订销差率
    int nThirdWidth = 74;
    int nThirdColXPos = nSecondColXPos + nSecondColWidth;
    QRect thirdColRect(nThirdColXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdColRect, Qt::AlignLeft | Qt::AlignVCenter, QString("%1%").arg(orderGoodsInfo.nOrderSaleRate));

    // 库存数量
    int nFourthColWidth = 70;
    int nFourthColXPos = nThirdColXPos + nThirdWidth;
    QRect fourthColRect(nFourthColXPos, yPos, nFourthColWidth, nHeight);
    painter->drawText(fourthColRect, Qt::AlignLeft | Qt::AlignVCenter, orderGoodsInfo.sStockNumber);

    // 上日/周销售数量
    int nFifthWidth = 90;
    int nFifthColXPos = nFourthColXPos + nFourthColWidth;
    QRect fifthColRect(nFifthColXPos, yPos, nFifthWidth, nHeight);
    double dSaleNumberLastweek = orderGoodsInfo.sSaleNumberLastweek.toDouble();
    QString sSaleNumberLastweek = QString::number(dSaleNumberLastweek, 'f', 2);
    painter->drawText(fifthColRect, Qt::AlignLeft | Qt::AlignVCenter, QString("%1/%2").arg(orderGoodsInfo.sSaleNumberYesterday).arg(sSaleNumberLastweek));

    // 单价
    int nSixColWidth = 60;
    int nSixColXPos = nFifthColXPos + nFifthWidth;
    QRect sixColRect(nSixColXPos, yPos, nSixColWidth, nHeight);
    painter->drawText(sixColRect, Qt::AlignLeft | Qt::AlignVCenter, QString("￥%1").arg(QString::number(orderGoodsInfo.fPrice, 'f', 2)));

    // 左箭头
    const int nArrowWidth = 15;
    const int nArrowHeight = 18;
    int nLeftArrowXPos = nSixColXPos + nSixColWidth;
    int nLeftArrowYPos = yPos + (nHeight - nArrowHeight)/2;
    QRect leftArrowRect(nLeftArrowXPos, nLeftArrowYPos, nArrowWidth, nArrowHeight);
    QPixmap leftArrowPixmap(":/orderGoodsImage/leftArrow.png");
    painter->drawPixmap(leftArrowRect, leftArrowPixmap.scaled(nArrowWidth, nArrowHeight));

    // 要货量
    const int nOrderNumberWidth = 40;
    int nOrderNumberXPos = nLeftArrowXPos + nArrowWidth;
    QRect orderNumberRect(nOrderNumberXPos, yPos, nOrderNumberWidth, nHeight);
    painter->drawText(orderNumberRect, Qt::AlignCenter, QString::number(orderGoodsInfo.nOrderGoodsNumber));

    // 右键头
    int nRightArrowXPos = nOrderNumberXPos + nOrderNumberWidth;
    int nRightArrowYPos = nLeftArrowYPos;
    QRect rightArrowRect(nRightArrowXPos, nRightArrowYPos, nArrowWidth, nArrowHeight);
    QPixmap rightArrowPixmap(":/orderGoodsImage/rightArrow.png");
    painter->drawPixmap(rightArrowRect, rightArrowPixmap.scaled(nArrowWidth, nArrowHeight));

    nLeftArrowStartXPos = nLeftArrowXPos;
    nLeftArrowEndXPos = nLeftArrowXPos + nArrowWidth;
    nRightArrowStartXPos = nRightArrowXPos;
    nRightArrowEndXPos = nRightArrowXPos + nArrowWidth;
}

OrderCategoryGoodsListView::OrderCategoryGoodsListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51)
    , m_pChangeOrderNumberWidget(NULL)
{
    init();
}

OrderCategoryGoodsListView::~OrderCategoryGoodsListView()
{
    if (m_pChangeOrderNumberWidget != NULL)
    {
        m_pChangeOrderNumberWidget->deleteLater();
    }
}

void OrderCategoryGoodsListView::appendItem(const OrderGoodsInfo &orderGoodsInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(orderGoodsInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(orderGoodsInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(orderGoodsInfo.nId);
    }
    QVariant variant;
    variant.setValue(orderGoodsInfo);
    pItem->setData(variant, e_orderGoodsInfo);
}

void OrderCategoryGoodsListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void OrderCategoryGoodsListView::mousePressEvent(QMouseEvent *event)
{
    //获取选中状态
    QModelIndex index = indexAt(event->pos());
    OrderGoodsInfo orderGoodsInfo;
    QVariant v_itemInfo = index.data(e_orderGoodsInfo);
    if (!v_itemInfo.canConvert<OrderGoodsInfo>())//可以转换
    {
        return;
    }
    orderGoodsInfo = v_itemInfo.value<OrderGoodsInfo>();
    m_curOrderGoodsInfo = orderGoodsInfo;
    int nXPos = event->pos().x();
    if (nXPos >= nLeftArrowStartXPos && nXPos <= nLeftArrowEndXPos)
    {
        orderGoodsInfo.nOrderGoodsNumber--;
//        if (orderGoodsInfo.nOrderGoodsNumber >= 0)
//        {
            emit sigOrderNumberAdded(orderGoodsInfo.nId, -1, orderGoodsInfo.fUnitSpecificationValue, orderGoodsInfo.fPrice);
            this->appendItem(orderGoodsInfo);
//        }
    }
    else if (nXPos >= nRightArrowStartXPos && nXPos <= nRightArrowEndXPos)
    {
        orderGoodsInfo.nOrderGoodsNumber++;
//        if (orderGoodsInfo.nOrderGoodsNumber >= 0)
//        {
            emit sigOrderNumberAdded(orderGoodsInfo.nId, 1, orderGoodsInfo.fUnitSpecificationValue, orderGoodsInfo.fPrice);
            this->appendItem(orderGoodsInfo);
//        }
    }
    else if (nXPos > nLeftArrowEndXPos && nXPos < nRightArrowStartXPos)
    {
        int nRow = index.row();
        int nItemYPos = nRow * m_nItemHeight;
        QPoint globalPoint = this->mapToGlobal(QPoint(nLeftArrowStartXPos, nItemYPos));
        int nWidth = nRightArrowEndXPos - nLeftArrowStartXPos;
        if (m_pChangeOrderNumberWidget == NULL)
        {
            m_pChangeOrderNumberWidget = new ChangeOrderNumberWidget;
            connect(m_pChangeOrderNumberWidget, SIGNAL(sigChangeNum(int)), this, SLOT(slot_changeNum(int)));
        }
        m_pChangeOrderNumberWidget->initOrderNumber(orderGoodsInfo.nOrderGoodsNumber);
        m_pChangeOrderNumberWidget->resize(nWidth, m_nItemHeight-1);
        m_pChangeOrderNumberWidget->move(globalPoint);
        m_pChangeOrderNumberWidget->activateWindow();
        m_pChangeOrderNumberWidget->showNormal();
        m_pChangeOrderNumberWidget->showKeyBoard();
    }

    //    QListView::mousePressEvent(event);
}

void OrderCategoryGoodsListView::slot_changeNum(int nNum)
{
    int oldOrderNum = m_curOrderGoodsInfo.nOrderGoodsNumber;
    int nAddedOrderNum = nNum - oldOrderNum;
    m_curOrderGoodsInfo.nOrderGoodsNumber = nNum;
    this->appendItem(m_curOrderGoodsInfo);
    emit sigOrderNumberAdded(m_curOrderGoodsInfo.nId, nAddedOrderNum, m_curOrderGoodsInfo.fUnitSpecificationValue, m_curOrderGoodsInfo.fPrice);
}

void OrderCategoryGoodsListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new OrderCategoryGoodsDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}


