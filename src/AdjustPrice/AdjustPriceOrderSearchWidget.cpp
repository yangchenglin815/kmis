#include "AdjustPriceOrderSearchWidget.h"
#include "ui_AdjustPriceOrderSearchWidget.h"

AdjustPriceOrderSearchWidget::AdjustPriceOrderSearchWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdjustPriceOrderSearchWidget)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
    initConnect();
}

AdjustPriceOrderSearchWidget::~AdjustPriceOrderSearchWidget()
{
    delete ui;
}

//void AdjustPriceOrderSearchWidget::test()
//{
//    QList<AdjustPriceOrderSearchInfo> orderInfoList;
//    AdjustPriceOrderSearchInfo adjustPriceOrderInfo;
//    for (int i = 0; i < 20; i++)
//    {
//        adjustPriceOrderInfo.sSeq = QString("%1").arg(i+1); // 序号
//        adjustPriceOrderInfo.sName = QStringLiteral("无籽沙瓤苹果%1").arg(i); // 商品名称
//        adjustPriceOrderInfo.sCode = QString("2233555411222%1").arg(i); // 商品条码
//        adjustPriceOrderInfo.fOldPrice = 12.00; // 原售价
//        adjustPriceOrderInfo.fNowPrice = 13.00; // 现售价
//        adjustPriceOrderInfo.fOldMemberPrice = 8.00; // 原会员价
//        adjustPriceOrderInfo.fNowMemberPrice = 9.00; // 现会员价
//        orderInfoList.append(adjustPriceOrderInfo);
//    }
//    initData(orderInfoList);
//}

void AdjustPriceOrderSearchWidget::initData(const QList<AdjustPriceOrderSearchInfo> &orderInfoList)
{
    m_backUpOrderInfoList = orderInfoList;
    initSearchData(orderInfoList);
}

void AdjustPriceOrderSearchWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void AdjustPriceOrderSearchWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void AdjustPriceOrderSearchWidget::slot_searchChanged(QString searchText)
{
    if (searchText.isEmpty())
    {
        initSearchData(m_backUpOrderInfoList);
    }
    else
    {
        QList<AdjustPriceOrderSearchInfo> orderInfoList;
        AdjustPriceOrderSearchInfo searchInfo;
        int nLen = m_backUpOrderInfoList.length();
        for (int i = 0; i < nLen; i++)
        {
            searchInfo = m_backUpOrderInfoList[i];
            if ((searchInfo.sCode == searchText)
                    || (searchInfo.sBarCode == searchText)
                    || searchInfo.sName.contains(searchText)
                    || searchInfo.sShortName.contains(searchText)
                    || searchInfo.sPinYinName.contains(searchText)
                    || searchInfo.sWuBiName.contains(searchText))
            {
                orderInfoList.append(searchInfo);
            }
        }
        initSearchData(orderInfoList);
    }
}

void AdjustPriceOrderSearchWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_orderInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        m_orderInfoList[i].sSeq = QString::number(i + 1);
        ui->listView->appendItem(m_orderInfoList[i]);
    }
}

void AdjustPriceOrderSearchWidget::checkCurPageButtonState()
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

void AdjustPriceOrderSearchWidget::initConnect()
{
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
}

void AdjustPriceOrderSearchWidget::initSearchData(const QList<AdjustPriceOrderSearchInfo> &orderInfoList)
{
    m_orderInfoList = orderInfoList;
    int nLen = m_orderInfoList.length();
    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}
