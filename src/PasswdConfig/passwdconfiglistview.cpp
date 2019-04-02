#include "passwdconfiglistview.h"
#include <QPainter>
#include <QMouseEvent>
#include "../data/constData.h"

enum ItemType
{
    e_itemInfo = Qt::UserRole + 1,
};

PasswdConfigDelegate::PasswdConfigDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void PasswdConfigDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<AccountInfo>())
    {
        bool bSelected = false;
        if (option.state & QStyle::State_Selected)
        {
            bSelected = true;
        }
        AccountInfo accountInfo = v_itemInfo.value<AccountInfo>();
        paintContent(painter, option, accountInfo, bSelected);
    }
    painter->restore();
}

void PasswdConfigDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const AccountInfo &accountInfo, bool bSelected) const
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

    const int nLeftSpace = 28*g_widthRate;
    // 选择列
    const int checkBoxSideLenght = 16*g_widthRate;
    int nSelectBoxXPos = xPos + nLeftSpace;
    int nSelectBoxYPos = yPos + (nHeight - checkBoxSideLenght) / 2 + 2*g_widthRate;
    QRect selectBoxRect(nSelectBoxXPos, nSelectBoxYPos, checkBoxSideLenght, checkBoxSideLenght);
    QPixmap checkBoxPixmap;
    checkBoxPixmap.load(bSelected ? ":/orderGoodsImage/checkBoxPress.png" : ":/orderGoodsImage/checkBoxWithSide.png");
    painter->drawPixmap(selectBoxRect, checkBoxPixmap);

    // 序号
    const int nFirstWidth = 80*g_widthRate;
    int nFirstXPos = nSelectBoxXPos + checkBoxSideLenght + nLeftSpace;
    QRect firstRect1(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect1, Qt::AlignLeft | Qt::AlignVCenter, QString::number(accountInfo.keyId));

    // 员工工号
    const int mWidth = 130*g_widthRate;
    nFirstXPos = nFirstXPos + nFirstWidth;
    QRect firstRect2(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect2, Qt::AlignLeft | Qt::AlignVCenter, accountInfo.sAccountID);

    // 员工名称
    const int nSecondWidth = 130*g_widthRate;
    int nSecondXPos = nFirstXPos + mWidth;
    QRect secondRect(nSecondXPos, yPos, nSecondWidth, nHeight);
    painter->drawText(secondRect, Qt::AlignLeft | Qt::AlignVCenter, accountInfo.sName);

    // 手机号码
    const int nThirdWidth = 152*g_widthRate;
    int nThirdXPos = nSecondXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, accountInfo.sTelnumber);

    // 角色
    QString Power;
    if(accountInfo.sPower == c_sShopKeeper){
        Power = QStringLiteral("店长");
    }
    else if(accountInfo.sPower == c_sSaleman){
        Power = QStringLiteral("收银员");
    }
    else if(accountInfo.sPower == c_sSaleGuide){
        Power = QStringLiteral("导购员");
    }
    const int nFourthWidth = 128*g_widthRate;
    int nFourthXPos = nThirdXPos + nThirdWidth;
    QRect fourthRect(nFourthXPos, yPos, nFourthWidth, nHeight);
    painter->drawText(fourthRect, Qt::AlignLeft | Qt::AlignVCenter, Power);

    // 状态
    QString status;
    if(!accountInfo.status){
        pen.setColor(QColor(f_fontColorGray));
        status = QStringLiteral("禁用");
    }
    else{
        pen.setColor(QColor(f_fontColorGreen));
        status = QStringLiteral("正常");
    }
    painter->setPen(pen);
    const int nfifthWidth = 92*g_widthRate;
    int nFifthXPos = nFourthXPos + nFourthWidth;
    QRect fifthRect(nFifthXPos, yPos, nfifthWidth, nHeight);
    painter->drawText(fifthRect, Qt::AlignLeft | Qt::AlignVCenter, status);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

PasswdConfigListView::PasswdConfigListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51)
{
    init();
}

void PasswdConfigListView::appendItem(const AccountInfo &accountInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(accountInfo.id))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(accountInfo.id, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(accountInfo.id);
    }

    QVariant variant;
    variant.setValue(accountInfo);
    pItem->setData(variant, e_itemInfo);

    if (m_sSelectKeyIdList.contains(accountInfo.id))
    {
        this->setCurrentIndex(pItem->index());
    }
}

void PasswdConfigListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void PasswdConfigListView::appendSelectKeyIds(const QList<int> &keyIdList)
{
    int nLen = keyIdList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (!m_sSelectKeyIdList.contains(keyIdList[i]))
        {
            m_sSelectKeyIdList.append(keyIdList[i]);
        }
    }
}

void PasswdConfigListView::removeSelectKeyIds(const QList<int> &keyIdList)
{
    int nLen = keyIdList.length();
    for (int i = 0; i < nLen; i++)
    {
        m_sSelectKeyIdList.removeOne(keyIdList[i]);
    }
}

void PasswdConfigListView::getSelectIdList(QList<int> &keyIdList)
{
    keyIdList = m_sSelectKeyIdList;
}

void PasswdConfigListView::clearSecectIdList()
{
    m_sSelectKeyIdList.clear();
}

void PasswdConfigListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    AccountInfo accountInfo;
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<AccountInfo>())//可以转换
    {
        accountInfo = v_itemInfo.value<AccountInfo>();
        if (m_sSelectKeyIdList.contains(accountInfo.id))
        {
            m_sSelectKeyIdList.removeOne(accountInfo.id);
        }
        else
        {
            m_sSelectKeyIdList.append(accountInfo.id);
        }
        emit sigClickItem();
    }
}

void PasswdConfigListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new PasswdConfigDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    setSelectionMode(MultiSelection);
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}
