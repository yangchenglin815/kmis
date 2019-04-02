#include "CheckOrderGoodsListView.h"
#include <QPainter>
#include <QMouseEvent>

static int nLeftArrowStartXPos = -1;
static int nLeftArrowEndXPos = -1;
static int nRightArrowStartXPos = -1;
static int nRightArrowEndXPos = -1;
static bool bUploadFinished = false;

enum CheckOrderGoodsType
{
    e_checkOrderGoodsType
};

CheckOrderGoodsDelegate::CheckOrderGoodsDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{

}

void CheckOrderGoodsDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_checkOrderGoodsType);
    if (v_itemInfo.canConvert<CheckOrderGoodsInfo>())
    {
        CheckOrderGoodsInfo checkOrderGoodsInfo = v_itemInfo.value<CheckOrderGoodsInfo>();
        paintFirstColumn(painter, option, checkOrderGoodsInfo);
        paintOtherColumn(painter, option, checkOrderGoodsInfo);

    }

    painter->restore();
}

void CheckOrderGoodsDelegate::paintFirstColumn(QPainter *painter, const QStyleOptionViewItem &option, const CheckOrderGoodsInfo &checkOrderGoodsInfo) const
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

    const int nLeftSpace = 24;
    const int nTopSpace = 8;
    // 商品--商品名称
    int nFirstRowXPos = xPos + nLeftSpace;
    int nFirstRowYPos = yPos + nTopSpace;
    QRect firstRowRect(nFirstRowXPos, nFirstRowYPos, nWidth, nFirstRowFontSize);
    QString showName = checkOrderGoodsInfo.sShortName;
    if (showName.isEmpty())
    {
        showName = checkOrderGoodsInfo.sName;
    }
    painter->drawText(firstRowRect, Qt::AlignLeft | Qt::AlignVCenter, showName);
    // 商品--商品编码(商品单位)
    const int nSecondFontSize = 12;
    const int nTwoRowSpace = 8;
    font.setPixelSize(nSecondFontSize);
    painter->setFont(font);
    pen.setColor("#999999");
    painter->setPen(pen);
    int nSecondRowXPos = nFirstRowXPos;
    int nSecondRowYPos = nFirstRowYPos + nFirstRowFontSize + nTwoRowSpace;
    QRect secondRowRect(nSecondRowXPos, nSecondRowYPos, nWidth, nSecondFontSize);
    QString secondText = QString("%1(%2)").arg(checkOrderGoodsInfo.sCode).arg(checkOrderGoodsInfo.sUnitSpecification);
    painter->drawText(secondRowRect, Qt::AlignLeft | Qt::AlignVCenter, secondText);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

void CheckOrderGoodsDelegate::paintOtherColumn(QPainter *painter, const QStyleOptionViewItem &option, const CheckOrderGoodsInfo &checkOrderGoodsInfo) const
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

    // 要货件数/数量
    QPen pen;
    pen.setColor("#333333");
    painter->setPen(pen);
    int nLeftSpace = 200;
    if (bUploadFinished)
    {
        nLeftSpace = 210;
    }
    int nSecondColXPos = xPos + nLeftSpace;
    int nSecondColWidth = 94;
    if (bUploadFinished)
    {
        nSecondColWidth = 120;
    }
    QRect secondColRect(nSecondColXPos, yPos, nSecondColWidth, nHeight);
    double fSumNumber = checkOrderGoodsInfo.nOrderGoodsNumber * checkOrderGoodsInfo.fUnitSpecificationValue;
    QString sSumNumber;
    sSumNumber.sprintf("%.2f", fSumNumber);
    QString sSecondText = QString("%1/%2").arg(checkOrderGoodsInfo.nOrderGoodsNumber).arg(sSumNumber);
    painter->drawText(secondColRect, Qt::AlignLeft | Qt::AlignVCenter, sSecondText);

    // 审核件数/数量
    int nThirdWidth = 100;
    if (bUploadFinished)
    {
        nThirdWidth = 130;
    }
    int nThirdColXPos = nSecondColXPos + nSecondColWidth;
    QRect thirdColRect(nThirdColXPos, yPos, nThirdWidth, nHeight);
    fSumNumber = checkOrderGoodsInfo.nCheckOrderGoodsNumber * checkOrderGoodsInfo.fUnitSpecificationValue;
    sSumNumber.sprintf("%.2f", fSumNumber);
    QString sThirdText = QString("%1/%2").arg(checkOrderGoodsInfo.nCheckOrderGoodsNumber).arg(sSumNumber);
    painter->drawText(thirdColRect, Qt::AlignLeft | Qt::AlignVCenter, sThirdText);

    // 单件单价
    int nFourthColWidth = 80;
    if (bUploadFinished)
    {
        nFourthColWidth = 105;
    }
    int nFourthColXPos = nThirdColXPos + nThirdWidth;
    QRect fourthColRect(nFourthColXPos, yPos, nFourthColWidth, nHeight);
    painter->drawText(fourthColRect, Qt::AlignLeft | Qt::AlignVCenter,
                      QString("￥%1").arg(QString::number(checkOrderGoodsInfo.fPrice, 'f', 2)));

    // 金额
    int nFifthWidth = 90;
    if (bUploadFinished)
    {
        nFifthWidth = 90;
    }
    int nFifthColXPos = nFourthColXPos + nFourthColWidth;
    QRect fifthColRect(nFifthColXPos, yPos, nFifthWidth, nHeight);
    double fSumPrice = checkOrderGoodsInfo.nCheckOrderGoodsNumber * checkOrderGoodsInfo.fUnitSpecificationValue * checkOrderGoodsInfo.fPrice;
    QString fifthText = QString("￥%1").arg(QString::number(fSumPrice, 'f', 2));
    painter->drawText(fifthColRect, Qt::AlignLeft | Qt::AlignVCenter, fifthText);

    if (!bUploadFinished)
    {
        // 左箭头
        const int nArrowWidth = 15;
        const int nArrowHeight = 18;
        int nLeftArrowXPos = nFifthColXPos + nFifthWidth;
        int nLeftArrowYPos = yPos + (nHeight - nArrowHeight)/2;
        QRect leftArrowRect(nLeftArrowXPos, nLeftArrowYPos, nArrowWidth, nArrowHeight);
        QPixmap leftArrowPixmap(":/orderGoodsImage/leftArrow.png");
        painter->drawPixmap(leftArrowRect, leftArrowPixmap.scaled(nArrowWidth, nArrowHeight));

        // 要货量
        const int nOrderNumberWidth = 40;
        int nOrderNumberXPos = nLeftArrowXPos + nArrowWidth;
        QRect orderNumberRect(nOrderNumberXPos, yPos, nOrderNumberWidth, nHeight);
        painter->drawText(orderNumberRect, Qt::AlignCenter, QString::number(checkOrderGoodsInfo.nCheckOrderGoodsNumber));

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
}

CheckOrderGoodsListView::CheckOrderGoodsListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(50)
    , m_pChangeOrderNumberWidget(NULL)
{
    init();
}

CheckOrderGoodsListView::~CheckOrderGoodsListView()
{
    if (m_pChangeOrderNumberWidget != NULL)
    {
        m_pChangeOrderNumberWidget->deleteLater();
    }
}

void CheckOrderGoodsListView::appendItem(const CheckOrderGoodsInfo &checkOrderGoodsInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(checkOrderGoodsInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(checkOrderGoodsInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(checkOrderGoodsInfo.nId);
    }
    QVariant variant;
    variant.setValue(checkOrderGoodsInfo);
    pItem->setData(variant, e_checkOrderGoodsType);

//    m_checkOrderGoodsInfoMap.insert(checkOrderGoodsInfo.nId, checkOrderGoodsInfo);
}

void CheckOrderGoodsListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void CheckOrderGoodsListView::setUploadFinishedFlag(bool bFinished)
{
    bUploadFinished = bFinished;
}

//void CheckOrderGoodsListView::clearCheckOrderGoodsInfoMap()
//{
//    m_checkOrderGoodsInfoMap.clear();
//}

//QMap<int, CheckOrderGoodsInfo> CheckOrderGoodsListView::getCheckOrderGoodsInfoMap()
//{
//    return m_checkOrderGoodsInfoMap;
//}

void CheckOrderGoodsListView::mousePressEvent(QMouseEvent *event)
{
    //获取选中状态
    QModelIndex index = indexAt(event->pos());
    CheckOrderGoodsInfo checkOrderGoodsInfo;
    QVariant v_itemInfo = index.data(e_checkOrderGoodsType);
    if (!v_itemInfo.canConvert<CheckOrderGoodsInfo>())//可以转换
    {
        return;
    }
    checkOrderGoodsInfo = v_itemInfo.value<CheckOrderGoodsInfo>();
    m_curCheckOrderGoodsInfo = checkOrderGoodsInfo;
    int nXPos = event->pos().x();
    if (nXPos >= nLeftArrowStartXPos && nXPos <= nLeftArrowEndXPos)
    {
        checkOrderGoodsInfo.nCheckOrderGoodsNumber--;
//        if (checkOrderGoodsInfo.nCheckOrderGoodsNumber >= 0)
//        {
            this->appendItem(checkOrderGoodsInfo);
            emit sigOrderNumberAdded(checkOrderGoodsInfo.nId, -1, checkOrderGoodsInfo.fUnitSpecificationValue, m_curCheckOrderGoodsInfo.fPrice);
//        }
    }
    else if (nXPos >= nRightArrowStartXPos && nXPos <= nRightArrowEndXPos)
    {
        checkOrderGoodsInfo.nCheckOrderGoodsNumber++;
//        if (checkOrderGoodsInfo.nCheckOrderGoodsNumber >= 0)
//        {
            this->appendItem(checkOrderGoodsInfo);
            emit sigOrderNumberAdded(checkOrderGoodsInfo.nId, 1, checkOrderGoodsInfo.fUnitSpecificationValue, m_curCheckOrderGoodsInfo.fPrice);
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
        m_pChangeOrderNumberWidget->initOrderNumber(checkOrderGoodsInfo.nCheckOrderGoodsNumber);
        m_pChangeOrderNumberWidget->resize(nWidth, m_nItemHeight-1);
        m_pChangeOrderNumberWidget->move(globalPoint);
        m_pChangeOrderNumberWidget->activateWindow();
        m_pChangeOrderNumberWidget->showNormal();
        m_pChangeOrderNumberWidget->showKeyBoard();
    }

    //    QListView::mousePressEvent(event);
}

void CheckOrderGoodsListView::slot_changeNum(int nNum)
{
    int oldOrderNum = m_curCheckOrderGoodsInfo.nCheckOrderGoodsNumber;
    int nAddedOrderNum = nNum - oldOrderNum;
    m_curCheckOrderGoodsInfo.nCheckOrderGoodsNumber = nNum;
    this->appendItem(m_curCheckOrderGoodsInfo);
    emit sigOrderNumberAdded(m_curCheckOrderGoodsInfo.nId, nAddedOrderNum, m_curCheckOrderGoodsInfo.fUnitSpecificationValue, m_curCheckOrderGoodsInfo.fPrice);
}

void CheckOrderGoodsListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new CheckOrderGoodsDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}




