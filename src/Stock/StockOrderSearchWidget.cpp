#include "StockOrderSearchWidget.h"
#include "ui_StockOrderSearchWidget.h"
#include <QDebug>

StockOrderSearchWidget::StockOrderSearchWidget(QWidget *parent)
    : QWidget(parent)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui= new Ui::StockOrderSearchWidget();
    ui->setupUi(this);
//    test();
    initConnect();
}

StockOrderSearchWidget::~StockOrderSearchWidget()
{
    delete ui;
}

//void StockOrderSearchWidget::test()
//{
//    QList<StockOrderSearchInfo> orderInfoList;
//    StockOrderSearchInfo stockOrderSearchInfo;
//    for (int i = 0; i < 20; i++)
//    {
//        stockOrderSearchInfo.sSeq = QString("%1").arg(i + 1); // 序号
//        stockOrderSearchInfo.nId = i + 1; // 商品id
//        stockOrderSearchInfo.sName = QStringLiteral("无籽沙瓤苹果%1").arg(i); // 商品名称
//        stockOrderSearchInfo.sCode = QString("123456789%1").arg(i); // 商品编码
//        stockOrderSearchInfo.sBelongCategory = QStringLiteral("水果%1").arg(i); // 所属分类
//        stockOrderSearchInfo.sBarCode = QString("123456789%1").arg(i); // 商品条码/plu码
//        stockOrderSearchInfo.sShortName = "xyz"; // 商品简称
//        stockOrderSearchInfo.sPinYinName = "adc"; // 拼音助记码
//        stockOrderSearchInfo.sWuBiName = "blibli"; // 五笔助记码
//        stockOrderSearchInfo.sWeighUnit = QStringLiteral("公斤"); // 称重单位
//        stockOrderSearchInfo.fShouldStockNum = 7.0f; // 账盘数量
//        stockOrderSearchInfo.fRealStockNum = 6.0f; // 实盘数量
//        stockOrderSearchInfo.fStockDifferNum = -1.0f; // 差异数量
//        stockOrderSearchInfo.fBuyDifferPrice = 100.0f; // 进价差异金额
////        stockOrderSearchInfo.fSaleDifferPrice = 100.0f; // 售价差异金额
//        orderInfoList.append(stockOrderSearchInfo);
//    }
//    initData(orderInfoList);
//}

void StockOrderSearchWidget::initData(const QList<StockOrderSearchInfo> &orderInfoList)
{
    m_backUpOrderInfoList = orderInfoList;
    int nLen = m_backUpOrderInfoList.length();
    float fTotalDifferNum = 0.0f;
    for (int i = 0; i < nLen; i++)
    {
        fTotalDifferNum += m_backUpOrderInfoList[i].fBuyDifferPrice;
    }
    ui->totalDifferPriceLabel->setText(QString("￥%1").arg(QString::number(fTotalDifferNum, 'f', 2)));

    initSearchData(orderInfoList);
}

void StockOrderSearchWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void StockOrderSearchWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void StockOrderSearchWidget::slot_searchChanged(QString searchText)
{
    if (searchText.isEmpty())
    {
        initSearchData(m_backUpOrderInfoList);
    }
    else
    {
        QList<StockOrderSearchInfo> orderInfoList;
        StockOrderSearchInfo searchInfo;
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

void StockOrderSearchWidget::slot_sortSixthCol(bool m_bSixthArrowDown)
{
    //差异数量排序
    for(int i = 0; i < m_orderInfoList.length(); i++)
    {
        for (int j = 0; j < m_orderInfoList.length() - i - 1; j++)
        {
            if(m_bSixthArrowDown){
                if(m_orderInfoList.at(j).fStockDifferNum < m_orderInfoList.at(j+1).fStockDifferNum )
                {
                    m_orderInfoList.swap(j, j+1);
                }
            }
            else{
                if(m_orderInfoList.at(j).fStockDifferNum > m_orderInfoList.at(j+1).fStockDifferNum )
                {
                    m_orderInfoList.swap(j, j+1);
                }
            }
        }
    }

    generateUI();
}

void StockOrderSearchWidget::slot_sortSeventhCol(bool m_bSeventhArrowDown)
{
    //进差价金额排序

    for(int i = 0; i < m_orderInfoList.length(); i++)
    {
        for (int j = 0; j < m_orderInfoList.length() - i - 1; j++)
        {
            if((m_orderInfoList.at(j).fBuyDifferPrice < m_orderInfoList.at(j+1).fBuyDifferPrice) == m_bSeventhArrowDown)
            {
                m_orderInfoList.swap(j, j+1);
            }
        }
    }

    generateUI();
}

void StockOrderSearchWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_orderInfoList.length();
    for (int i = nStartPos; (i < nEndPos) && (i < nCount); i++)
    {
        m_orderInfoList[i].sSeq = QString::number(i+1);
        ui->listView->appendItem(m_orderInfoList[i]);
    }
}

void StockOrderSearchWidget::checkCurPageButtonState()
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

void StockOrderSearchWidget::initConnect()
{
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
    connect(ui->titleWidget, SIGNAL(sigSortSixthCol(bool)), this, SLOT(slot_sortSixthCol(bool)));
    connect(ui->titleWidget, SIGNAL(sigSortSeventhCol(bool)), this, SLOT(slot_sortSeventhCol(bool)));
}

void StockOrderSearchWidget::initSearchData(const QList<StockOrderSearchInfo> &orderInfoList)
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
