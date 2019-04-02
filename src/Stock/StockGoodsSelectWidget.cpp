#include "StockGoodsSelectWidget.h"
#include "ui_StockGoodsSelectWidget.h"

StockGoodsSelectWidget::StockGoodsSelectWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StockGoodsSelectWidget)
    , m_nOnePageCount(8)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
    initConnect();
//    test();
}

StockGoodsSelectWidget::~StockGoodsSelectWidget()
{
    delete ui;
}

//void StockGoodsSelectWidget::test()
//{
//    StockSelectGoodsInfo selectGoodsInfo;
//    for (int i = 0; i < 20; i++)
//    {
//        selectGoodsInfo.sSeq = QString::number(i+1); // 序号
//        selectGoodsInfo.nId = i;
//        selectGoodsInfo.sName = QStringLiteral("无籽沙瓤大西瓜%1").arg(i); // 商品名称
//        selectGoodsInfo.sCode = QString("19880324003%1").arg(i); // 商品条码
//        selectGoodsInfo.sWeighUnit = QStringLiteral("公斤"); // 称量单位
//        selectGoodsInfo.sBelongCategory = ""; // 所属分类
//        selectGoodsInfo.sBarCode = ""; // 商品条码/plu码
//        selectGoodsInfo.sShortName = ""; // 商品简称
//        selectGoodsInfo.sPinYinName = ""; // 拼音助记码
//        selectGoodsInfo.sWuBiName = ""; // 五笔助记码
//        selectGoodsInfo.sWeighUnit = ""; // 称重单位
//        selectGoodsInfo.fShouldStockNum = 100.00f; // 账盘数量
//        selectGoodsInfo.fRealStockNum = 100.00f; // 实盘数量
//        selectGoodsInfo.fStockDifferNum = 100.00f; // 差异数量
//        selectGoodsInfo.fBuyDifferPrice = 100.00f; // 进价差异金额
////        selectGoodsInfo.fSaleDifferPrice = 100.00f; // 售价差异金额
//        m_goodsInfoList.append(selectGoodsInfo);
//    }
//    initData(m_goodsInfoList);
//}

void StockGoodsSelectWidget::initData(const QList<StockSelectGoodsInfo> &goodsInfoList)
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

void StockGoodsSelectWidget::appendData(const StockSelectGoodsInfo &goodsInfo)
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
            m_addedGoodsInfoMap.insert(goodsInfo.nId, goodsInfo);
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

void StockGoodsSelectWidget::removeSelectItem()
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

int StockGoodsSelectWidget::getGoodsPosition(int nId)
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

bool StockGoodsSelectWidget::getSelectGoodsInfo(int nId, StockSelectGoodsInfo &goodsInfo)
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

int StockGoodsSelectWidget::getGoodsListLength()
{
    return m_goodsInfoList.length();
}

bool StockGoodsSelectWidget::getSeletedItem(StockSelectGoodsInfo &selectGoodsInfo)
{
    return ui->listView->getSelectItem(selectGoodsInfo);
}

void StockGoodsSelectWidget::getGoodsInfoList(QList<StockSelectGoodsInfo> &goodsInfoList)
{
    goodsInfoList = m_goodsInfoList;
}

void StockGoodsSelectWidget::clearData()
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

void StockGoodsSelectWidget::getAddedGoods(QList<StockSelectGoodsInfo> &addedGoodsList)
{
    addedGoodsList = m_addedGoodsInfoMap.values();
}

void StockGoodsSelectWidget::getRemovedGoods(QList<StockSelectGoodsInfo> &removedGoodsList)
{
    int nLen = m_removedGoodsIdList.length();
    for (int i = 0; i < nLen; i++)
    {
        removedGoodsList.append(m_initedGoodsInfoMap.value(m_removedGoodsIdList[i]));
    }
}

void StockGoodsSelectWidget::getUpdatedGoods(QList<StockSelectGoodsInfo> &updatedGoodsList)
{
    int nLen = m_updatedGoodsIdList.length();
    for (int i = 0; i < nLen; i++)
    {
        updatedGoodsList.append(m_initedGoodsInfoMap.value(m_updatedGoodsIdList[i]));
    }
}

void StockGoodsSelectWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void StockGoodsSelectWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void StockGoodsSelectWidget::updateUI(bool bToEndPage)
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

void StockGoodsSelectWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_goodsInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        m_goodsInfoList[i].sSeq = QString::number(i+1);
        ui->listView->appendItem(m_goodsInfoList[i]);
    }
}

void StockGoodsSelectWidget::checkCurPageButtonState()
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

void StockGoodsSelectWidget::initConnect()
{
    qRegisterMetaType<StockSelectGoodsInfo>("StockSelectGoodsInfo");
    connect(ui->listView, SIGNAL(sigClickItem(StockSelectGoodsInfo)), this, SIGNAL(sigClickItem(StockSelectGoodsInfo)));
}
