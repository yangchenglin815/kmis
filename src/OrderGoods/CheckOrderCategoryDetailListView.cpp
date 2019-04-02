#include "CheckOrderCategoryDetailListView.h"
#include "../data/constData.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include "CommonFun.h"

static int nCheckBoxStartXPos = -1;
static int nCheckBoxEndXPos = -1;

enum CheckOrderCategoryDetailType
{
    e_checkOrderCategoryDetail,
};

CheckOrderCategoryDetailDelegate::CheckOrderCategoryDetailDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{

}

void CheckOrderCategoryDetailDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_checkOrderCategoryDetail);
    if (v_itemInfo.canConvert<CheckOrderCategoryDetailInfo>())
    {
        CheckOrderCategoryDetailInfo orderCategoryInfo = v_itemInfo.value<CheckOrderCategoryDetailInfo>();
        bool bSelected = false;
        if (option.state & QStyle::State_Selected)
        {
            if (orderCategoryInfo.bUploadFinish)
            {
                bSelected = true;
                QRect rect = option.rect;
                rect.setX(rect.x() + 1);
                rect.setWidth(rect.width() - 2);
                painter->fillRect(rect, QBrush(QColor(c_sThemeColor)));
            }
        }
        paintContent(painter, option, orderCategoryInfo, bSelected);
    }

    painter->restore();
}

void CheckOrderCategoryDetailDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                                                    const CheckOrderCategoryDetailInfo &checkOrderCategoryDetailInfo, bool bSelected) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
    const int nWidth = option.rect.width();
    const int nHeight = option.rect.height();

    // 选择列
    const int checkBoxSideLenght = 16;
    const int nLeftSpace = 30;
    int nFirstXPos = xPos + nLeftSpace;
    if (!checkOrderCategoryDetailInfo.bUploadFinish)
    {
        int nFirstYPos = yPos + (nHeight - checkBoxSideLenght) / 2;
        QRect firstRect(nFirstXPos, nFirstYPos, checkBoxSideLenght, checkBoxSideLenght);
        QPixmap checkBoxPixmap;
        if (checkOrderCategoryDetailInfo.bSelected)
        {
            checkBoxPixmap.load(":/orderGoodsImage/checkBoxPress.png");
        }
        else
        {
            checkBoxPixmap.load(":/orderGoodsImage/checkBoxWithSide.png");
        }
        painter->drawPixmap(firstRect, checkBoxPixmap);

        nCheckBoxStartXPos = nFirstXPos - checkBoxSideLenght; // 扩大些范围
        nCheckBoxEndXPos = nFirstXPos + 2*checkBoxSideLenght; // 扩大些范围
    }
    else
    {
        nCheckBoxStartXPos = -1;
        nCheckBoxEndXPos = -1;
    }

    // 类别列
    // 类别名称
    const int nSecondWidth = 102;
    const int nNameFontSize = 14;
    int offX = 14;
    int nCategoryNameXPos = nFirstXPos + checkBoxSideLenght + offX;
    QFont font;
    font.setPixelSize(nNameFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected?"#ffffff":"#333333");
    painter->setPen(pen);
    int nCategoryNameWidth = painter->fontMetrics().width(checkOrderCategoryDetailInfo.sCategoryName);
    QRect categoryNameRect(nCategoryNameXPos, yPos, nCategoryNameWidth, nHeight);
    painter->drawText(categoryNameRect, Qt::AlignCenter, checkOrderCategoryDetailInfo.sCategoryName);

    // 类别数量
    const int nCategoryNumberFontSize = 12;
    font.setPixelSize(nCategoryNumberFontSize);
    painter->setFont(font);
    pen.setColor(bSelected?"#ffffff":"#999999");
    painter->setPen(pen);
    int nCategoryNumXPos = nCategoryNameXPos + nCategoryNameWidth;
    int nOffY = nNameFontSize - nCategoryNumberFontSize;// 类别数量与名称垂直方向相差nOffY像素
    QRect categoryNumRect(nCategoryNumXPos, yPos + nOffY/2, nSecondWidth, nHeight);
    QString sCategoryNumText = QString("(%1)").arg(checkOrderCategoryDetailInfo.nCategoryNum);
    painter->drawText(categoryNumRect, Qt::AlignLeft | Qt::AlignVCenter, sCategoryNumText);

    // 单号
    const int nThirdWidth = 143;
    font.setPixelSize(nNameFontSize);
    painter->setFont(font);
    pen.setColor(bSelected?"#ffffff":"#333333");
    painter->setPen(pen);
    int nThirdXPos = nCategoryNameXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, checkOrderCategoryDetailInfo.sCardOrOrderId);

    // 制单时间
    const int nFourthWidth = 132;
    int nFourthXPos = nThirdXPos + nThirdWidth;
    QRect fourthRect(nFourthXPos, yPos, nFourthWidth, nHeight);
    painter->drawText(fourthRect, Qt::AlignLeft | Qt::AlignVCenter, CommonFun::trunkDateTime(checkOrderCategoryDetailInfo.sCreateTime));

    // 制单人/上传人
    const int nFifthWidth = 132;
    int nFifthXPos = nFourthXPos + nFourthWidth;
    QRect fifthRect(nFifthXPos, yPos, nFifthWidth, nHeight);
    QString sMakerText = QString("%1/%2").arg(checkOrderCategoryDetailInfo.sOrderMaker).arg(checkOrderCategoryDetailInfo.sUploader);
    painter->drawText(fifthRect, Qt::AlignLeft | Qt::AlignVCenter, sMakerText);

    // 上传时间
    const int nSixthWidth = 134;
    int nSixthXPos = nFifthXPos + nFifthWidth;
    QRect sixthRect(nSixthXPos, yPos, nSixthWidth, nHeight);
    painter->drawText(sixthRect, Qt::AlignLeft | Qt::AlignVCenter, CommonFun::trunkDateTime(checkOrderCategoryDetailInfo.sUpdateTime));


    // 状态
    QString sStateText;
    if (checkOrderCategoryDetailInfo.bUploadFinish)
    {
        sStateText = QStringLiteral("已上传");
        pen.setColor(bSelected?"#ffffff":"#75ab57");
    }
    else
    {
        sStateText = QStringLiteral("未上传");
        pen.setColor(bSelected?"#ffffff":"#999999");
    }
    painter->setPen(pen);
    const int nSeventhWidth = 80;
    int nSeventhXPos = nSixthXPos + nSixthWidth;
    QRect seventhRect(nSeventhXPos, yPos, nSeventhWidth, nHeight);
    painter->drawText(seventhRect, Qt::AlignLeft | Qt::AlignVCenter, sStateText);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

CheckOrderCategoryDetailListView::CheckOrderCategoryDetailListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nChooseId(-1)
    , m_nItemHeight(48)
{
    init();
}

void CheckOrderCategoryDetailListView::appendItem(const CheckOrderCategoryDetailInfo &checkOrderCategoryDetailInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(checkOrderCategoryDetailInfo.nOrderCardId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(checkOrderCategoryDetailInfo.nOrderCardId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(checkOrderCategoryDetailInfo.nOrderCardId);
    }

    QVariant variant;
    variant.setValue(checkOrderCategoryDetailInfo);
    pItem->setData(variant, e_checkOrderCategoryDetail);

    if (m_nChooseId == checkOrderCategoryDetailInfo.nOrderCardId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void CheckOrderCategoryDetailListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void CheckOrderCategoryDetailListView::setDefaultSelectedIdList(QList<int> selectedList)
{
    m_selectedIdList = selectedList;
}

void CheckOrderCategoryDetailListView::clearId()
{
    m_selectedIdList.clear();
    m_nChooseId = -1;
}

QList<int> CheckOrderCategoryDetailListView::getSelectedIdList()
{
    return m_selectedIdList;
}

void CheckOrderCategoryDetailListView::removeId(int nId)
{
    m_selectedIdList.removeAll(nId);
    if (m_nChooseId == nId)
    {
        m_nChooseId = -1;
    }
}

int CheckOrderCategoryDetailListView::getChooseId()
{
    return m_nChooseId;
}

void CheckOrderCategoryDetailListView::mousePressEvent(QMouseEvent *event)
{


    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    CheckOrderCategoryDetailInfo checkOrderCategoryDetailInfo;
    QVariant v_itemInfo = index.data(e_checkOrderCategoryDetail);
    if (v_itemInfo.canConvert<CheckOrderCategoryDetailInfo>())//可以转换
    {
        checkOrderCategoryDetailInfo = v_itemInfo.value<CheckOrderCategoryDetailInfo>();
        if (checkOrderCategoryDetailInfo.bUploadFinish)
        {
            if(m_selectedIdList.size() > 0)
            {
                QListView::mousePressEvent(event);
                return;
            }

            if(m_nChooseId == checkOrderCategoryDetailInfo.nOrderCardId){
                m_nChooseId = -1;
                emit sigClickItem(false);

            }
            else{
                m_nChooseId = checkOrderCategoryDetailInfo.nOrderCardId;
                emit sigClickItem(true);
            }


            QListView::mousePressEvent(event);
        }
        else
        {
            //            int xPos = event->pos().x();
            //            if ((xPos >= nCheckBoxStartXPos) && (xPos <= nCheckBoxEndXPos))
            //            {
            if(m_nChooseId != -1)
            {
                return;
            }

            checkOrderCategoryDetailInfo.bSelected = !checkOrderCategoryDetailInfo.bSelected;
            if (m_selectedIdList.contains(checkOrderCategoryDetailInfo.nOrderCardId))
            {
                m_selectedIdList.removeAll(checkOrderCategoryDetailInfo.nOrderCardId);
            }
            else
            {
                m_selectedIdList.append(checkOrderCategoryDetailInfo.nOrderCardId);
            }
            this->appendItem(checkOrderCategoryDetailInfo);
            emit sigSelectId(checkOrderCategoryDetailInfo.nOrderCardId, checkOrderCategoryDetailInfo.bSelected);

            //            }
        }
    }
}

void CheckOrderCategoryDetailListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new CheckOrderCategoryDetailDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}
