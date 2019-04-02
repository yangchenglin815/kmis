#include "GoodsSelectWidget.h"
#include "ui_GoodsSelectWidget.h"
#include "../util/CommonFun.h"

GoodsSelectWidget::GoodsSelectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoodsSelectWidget)
  , m_nOnePageCount(7)
  , m_nTotalPage(1)
  , m_nCurPage(1)
  , curTotal("")
  , m_Total(0.00)
{
    ui->setupUi(this);
    initConnect();
}

GoodsSelectWidget::~GoodsSelectWidget()
{
    delete ui;
}

void GoodsSelectWidget::initData(const QList<InStockSelectGoodsInfo> &goodsInfoList)
{
    m_goodsInfoList = goodsInfoList;
    int nLen = m_goodsInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        m_initedGoodsInfoMap.insert(goodsInfoList[i].nId, goodsInfoList[i]);
    }
    m_removedGoodsIdList.clear(); // 原始移除的
    m_updatedGoodsIdList.clear(); // 原始更新的
    m_addedGoodsInfoMap.clear(); // 新增的
    updateUI();
}

void GoodsSelectWidget::appendData(const InStockSelectGoodsInfo &goodsInfo)
{
    int nPosition = getGoodsPosition(goodsInfo.nId);
    if (nPosition < 0)
    {
        m_goodsInfoList.append(goodsInfo);
        updateUI(true);
        if (m_initedGoodsInfoMap.contains(goodsInfo.nId))
        {
            if (!m_updatedGoodsIdList.contains(goodsInfo.nId))
            {
                m_updatedGoodsIdList.append(goodsInfo.nId);
            }
            if (m_removedGoodsIdList.contains(goodsInfo.nId))
            {
                m_removedGoodsIdList.removeAll(goodsInfo.nId);
            }
        }
        else
        {
            m_addedGoodsInfoMap[goodsInfo.nId]=goodsInfo;
        }
    }
    else
    {
        m_goodsInfoList[nPosition] = goodsInfo;
        updateUI();
        if (m_initedGoodsInfoMap.contains(goodsInfo.nId))
        {
            if (!m_updatedGoodsIdList.contains(goodsInfo.nId))
            {
                m_updatedGoodsIdList.append(goodsInfo.nId);
            }
            if (m_removedGoodsIdList.contains(goodsInfo.nId))
            {
                m_removedGoodsIdList.removeAll(goodsInfo.nId);
            }
        }
    }
}

void GoodsSelectWidget::removeSelectItem()
{
    int nKeyId = ui->listView->getSelectKeyId();
    int nPosition = getGoodsPosition(nKeyId);
    if (nPosition >= 0)
    {
        m_goodsInfoList.removeAt(nPosition);
        if (m_initedGoodsInfoMap.contains(nKeyId))
        {
            if (!m_removedGoodsIdList.contains(nKeyId))
            {
                m_removedGoodsIdList.append(nKeyId);
            }
            if (m_updatedGoodsIdList.contains(nKeyId))
            {
                m_updatedGoodsIdList.removeAll(nKeyId);
            }
        }
        updateUI();
    }
}

int GoodsSelectWidget::getGoodsPosition(int nId)
{
    if (nId <= 0)
    {
        return -1;
    }

    int nLen = m_goodsInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_goodsInfoList[i].nId == nId)
        {
            return i;
        }
    }
    return -1;
}

bool GoodsSelectWidget::getSelectGoodsInfo(int nId, InStockSelectGoodsInfo &goodsInfo)
{
    if (nId <= 0)
    {
        return false;
    }

    int nLen = m_goodsInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_goodsInfoList[i].nId == nId)
        {
            goodsInfo = m_goodsInfoList[i];
            return true;
        }
    }
    return false;
}

int GoodsSelectWidget::getGoodsListLength()
{
    return m_goodsInfoList.length();
}

bool GoodsSelectWidget::getSeletedItem(InStockSelectGoodsInfo &selectGoodsInfo)
{
    return ui->listView->getSelectItem(selectGoodsInfo);
}

void GoodsSelectWidget::getGoodsInfoList(QList<InStockSelectGoodsInfo> &goodsInfoList)
{
    goodsInfoList = m_goodsInfoList;
}

void GoodsSelectWidget::clearData()
{
    m_goodsInfoList.clear();
    m_initedGoodsInfoMap.clear();
    m_removedGoodsIdList.clear(); // 原始移除的
    m_updatedGoodsIdList.clear(); // 原始更新的
    m_addedGoodsInfoMap.clear(); // 新增的
    m_nCurPage = 1;
    m_nTotalPage = 1;
    checkCurPageButtonState();
    generateUI();
}

void GoodsSelectWidget::getAddedGoods(QList<InStockSelectGoodsInfo> &addedGoodsList)
{
    addedGoodsList = m_addedGoodsInfoMap.values();
}

void GoodsSelectWidget::getRemovedGoods(QList<InStockSelectGoodsInfo> &removedGoodsList)
{
    int nLen = m_removedGoodsIdList.length();
    for (int i = 0; i < nLen; i++)
    {
        removedGoodsList.append(m_initedGoodsInfoMap.value(m_removedGoodsIdList[i]));
    }
}

void GoodsSelectWidget::getUpdatedGoods(QList<InStockSelectGoodsInfo> &updatedGoodsList)
{
    int nLen = m_updatedGoodsIdList.length();
    for (int i = 0; i < nLen; i++)
    {
        updatedGoodsList.append(m_initedGoodsInfoMap.value(m_updatedGoodsIdList[i]));
    }
}

void GoodsSelectWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void GoodsSelectWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void GoodsSelectWidget::updateUI(bool bToEndPage)
{
    int nLen = m_goodsInfoList.length();
    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    if (bToEndPage)
    {
        m_nCurPage = m_nTotalPage;
    }

    checkCurPageButtonState();
    generateUI();
}

void GoodsSelectWidget::generateUI()
{
    m_Total=0.00;
    bool ok;
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_goodsInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        m_goodsInfoList[i].sSeq = QString::number(i+1);
        ui->listView->appendItem(m_goodsInfoList[i]);
        if(m_goodsInfoList[i].isEdited)
            m_Total+=m_goodsInfoList[i].fShouldTotal;
        else
            m_Total+=m_goodsInfoList[i].sSubTotal.toFloat(&ok);
    }
    curTotal=CommonFun::floatToString(m_Total);
    ui->totalLabel->setText(curTotal);
}

void GoodsSelectWidget::checkCurPageButtonState()
{
    if (m_nCurPage <= 1)
    {
        m_nCurPage = 1;
        ui->lastPageButton->setEnabled(false);
    }
    else
    {
        ui->lastPageButton->setEnabled(true);
    }

    if (m_nCurPage < m_nTotalPage)
    {
        ui->nextPageButton->setEnabled(true);
    }
    else
    {
        m_nCurPage = m_nTotalPage;
        ui->nextPageButton->setEnabled(false);
    }
}

void GoodsSelectWidget::initConnect()
{
    qRegisterMetaType<InStockSelectGoodsInfo>("InStockSelectGoodsInfo");
    connect(ui->listView, &InStockGoodsSelectListView::clicked,[=](){
        emit sig_Focus();
    });
}

