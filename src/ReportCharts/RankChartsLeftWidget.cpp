#include "RankChartsLeftWidget.h"
#include "ui_RankChartsLeftWidget.h"

RankChartsLeftWidget::RankChartsLeftWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RankChartsLeftWidget)
    , m_nOnePageCount(8)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
    test();
}

RankChartsLeftWidget::~RankChartsLeftWidget()
{
    delete ui;
}

void RankChartsLeftWidget::test()
{   
    RankChartsInfo* pRankChartsInfo = NULL;
    float fSaleSumMoney = 0.0f;
    float fSaleSumNumber = 0.0f;
    for (int i = 0; i < 20; i++)
    {
        pRankChartsInfo = new RankChartsInfo;
        pRankChartsInfo->nGoodsId = i; // 商品id
        pRankChartsInfo->nPosition = i+1; // 排序位置
        pRankChartsInfo->sGoodsName = QString(QStringLiteral("超级无敌大西瓜%1")).arg(i); // 商品名称
        pRankChartsInfo->sGoodsCode = QString("2000222225%1").arg(i); // 商品编号
        pRankChartsInfo->fSaleMoney = QString("%1.%2").arg(qrand()%1000).arg(qrand()%100).toFloat(); // 销售额
        fSaleSumMoney += pRankChartsInfo->fSaleMoney;
        pRankChartsInfo->fSaleNumber = QString("%1.%2").arg(qrand()/100).arg(qrand()%100).toFloat(); // 销售量
        pRankChartsInfo->fGoodsPrice = pRankChartsInfo->fSaleMoney / pRankChartsInfo->fSaleNumber; // 单价
        fSaleSumNumber += pRankChartsInfo->fSaleNumber;
        pRankChartsInfo->nPeopleNumber = QString("%1").arg(qrand()%100).toInt(); // 客流
        m_rankChartsInfoList.append(pRankChartsInfo);
    }

    ui->saleSumMoneyLabel->setText(QString::number(fSaleSumMoney, 'f', 2));
    ui->saleSumNumberLabel->setText(QString::number(fSaleSumNumber, 'f', 2));

    m_nCurPage = 1;
    int nCount = m_rankChartsInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void RankChartsLeftWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void RankChartsLeftWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void RankChartsLeftWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_rankChartsInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(*(m_rankChartsInfoList[i]));
    }
}

void RankChartsLeftWidget::checkCurPageButtonState()
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
