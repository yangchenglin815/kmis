#include "AdjustPriceGoodsSelectWidget.h"
#include "ui_AdjustPriceGoodsSelectWidget.h"

AdjustPriceGoodsSelectWidget::AdjustPriceGoodsSelectWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdjustPriceGoodsSelectWidget)
    , m_nOnePageCount(6)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
    initConnect();
//    test();
}

AdjustPriceGoodsSelectWidget::~AdjustPriceGoodsSelectWidget()
{
    delete ui;
}

//void AdjustPriceGoodsSelectWidget::test()
//{
////    QList<AdjustPriceSelectGoodsInfo> m_GoodsInfoList;
//    AdjustPriceSelectGoodsInfo adjustPriceSelectGoodsInfo;
//    for (int i = 0; i < 20; i++)
//    {
//        adjustPriceSelectGoodsInfo.sSeq = QString::number(i+1); // 序号
//        adjustPriceSelectGoodsInfo.sName = QStringLiteral("无籽沙瓤大西瓜%1").arg(i); // 商品名称
//        adjustPriceSelectGoodsInfo.sCode = QString("19880324003%1").arg(i); // 商品条码
//        adjustPriceSelectGoodsInfo.sWeighUnit = QStringLiteral("公斤"); // 称量单位
//        adjustPriceSelectGoodsInfo.fOldPrice = 8.11f; // 原单价
//        adjustPriceSelectGoodsInfo.fNowPrice = 9.11f; // 现单价
//        adjustPriceSelectGoodsInfo.fOldMemberPrice = 7.99f; // 原会员价
//        adjustPriceSelectGoodsInfo.fNowMemberPrice = 8.99f; // 现会员价
//        m_goodsInfoList.append(adjustPriceSelectGoodsInfo);
//    }
//    initData(m_goodsInfoList);
//}

void AdjustPriceGoodsSelectWidget::initData(const QList<AdjustPriceSelectGoodsInfo> &goodsInfoList)
{
    m_goodsInfoList = goodsInfoList;
    m_nCurPage = 1;
    updateUI();
}

void AdjustPriceGoodsSelectWidget::appendData(const AdjustPriceSelectGoodsInfo &goodsInfo)
{
    int nPosition = getGoodsPosition(goodsInfo.nId);
    if (nPosition < 0)
    {
        m_goodsInfoList.append(goodsInfo);
        updateUI(true);
    }
    else
    {
        m_goodsInfoList[nPosition] = goodsInfo;
        updateUI();
    }
}

void AdjustPriceGoodsSelectWidget::removeSelectItem()
{
    int nKeyId = ui->listView->getSelectKeyId();
    int nPosition = getGoodsPosition(nKeyId);
    if (nPosition >= 0)
    {
//        ui->listView->setSelectKeyId("");
        m_goodsInfoList.removeAt(nPosition);
        updateUI();
    }
}

int AdjustPriceGoodsSelectWidget::getGoodsPosition(int nId)
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

int AdjustPriceGoodsSelectWidget::getGoodsListLength()
{
    return m_goodsInfoList.length();
}

bool AdjustPriceGoodsSelectWidget::getSeletedItem(AdjustPriceSelectGoodsInfo &selectGoodsInfo)
{
    return ui->listView->getSelectItem(selectGoodsInfo);
}

void AdjustPriceGoodsSelectWidget::getGoodsInfoList(QList<AdjustPriceSelectGoodsInfo> &goodsInfoList)
{
    goodsInfoList = m_goodsInfoList;
}

void AdjustPriceGoodsSelectWidget::clearData()
{
    m_goodsInfoList.clear();
    m_nCurPage = 1;
    m_nTotalPage = 1;
    checkCurPageButtonState();
    generateUI();
}

void AdjustPriceGoodsSelectWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void AdjustPriceGoodsSelectWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void AdjustPriceGoodsSelectWidget::updateUI(bool bToEndPage)
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

void AdjustPriceGoodsSelectWidget::generateUI()
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

void AdjustPriceGoodsSelectWidget::checkCurPageButtonState()
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

void AdjustPriceGoodsSelectWidget::initConnect()
{
    qRegisterMetaType<AdjustPriceSelectGoodsInfo>("AdjustPriceSelectGoodsInfo");
    connect(ui->listView, SIGNAL(sigClickItem(AdjustPriceSelectGoodsInfo)), this, SIGNAL(sigClickItem(AdjustPriceSelectGoodsInfo)));
}
