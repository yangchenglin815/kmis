#include "ReportLossGoodsWidget.h"
#include "ui_ReportLossGoodsWidget.h"
#include "../data/constData.h"

ReportLossGoodsWidget::ReportLossGoodsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportLossGoodsWidget)
  , m_nCurPage(1)
  , m_nTotalPage(1)
  , m_nOnePageCount(25)
  , m_pUpPageButton(NULL)
  , m_pDownPageButton(NULL)
{
    ui->setupUi(this);
    initConnect();
}

ReportLossGoodsWidget::~ReportLossGoodsWidget()
{
    delete ui;
}

void ReportLossGoodsWidget::setUpDownPageButton(QPushButton *pUpPageButton, QPushButton *pDownPageButton)
{
    m_pUpPageButton = pUpPageButton;
    m_pDownPageButton = pDownPageButton;
    connect(m_pUpPageButton, SIGNAL(clicked()), this, SLOT(slot_upPage()));
    connect(m_pDownPageButton, SIGNAL(clicked()), this, SLOT(slot_downPage()));
}

void ReportLossGoodsWidget::initData(QList<GoodsInfo> goodsInfoList)
{
    m_goodsInfoList = goodsInfoList;

    m_nCurPage = 1;
    int nCount = m_goodsInfoList.size();
    m_nTotalPage = nCount/m_nOnePageCount + ((nCount%m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void ReportLossGoodsWidget::slot_upPage()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void ReportLossGoodsWidget::slot_downPage()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void ReportLossGoodsWidget::resizeEvent(QResizeEvent *)
{
    int width = this->width();

    int num = width/82;

    if(num > 6)
    {
        num = 6;
    }

    m_nOnePageCount = num * 5;
    int newItemWidth = width/num;
    ui->listView->setWidth(newItemWidth);

    int height = this->height();
    int newItemHeight = height/5;

    ui->listView->setHeight(newItemHeight);

    generateUI();
}

void ReportLossGoodsWidget::generateUI()
{
    if (m_pDownPageButton == NULL)
    {
        return;
    }
    m_pDownPageButton->setText(QString("%1/%2页").arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_goodsInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(m_goodsInfoList[i]);
    }

    int nLen = nEndPos - nCount;
    for (int i = 0; i < nLen; i++)
    {
        GoodsInfo goodsInfo;
        goodsInfo.nId = c_nNegativeNumber - i;
        ui->listView->appendItem(goodsInfo);
    }
}

void ReportLossGoodsWidget::checkCurPageButtonState()
{
    if ((m_pUpPageButton == NULL) || (m_pDownPageButton == NULL))
    {
        return;
    }

    if (m_nCurPage <= 1)
    {
        m_nCurPage = 1;
        m_pUpPageButton->setEnabled(false);
    }
    else
    {
        m_pUpPageButton->setEnabled(true);
    }

    if (m_nCurPage < m_nTotalPage)
    {
        m_pDownPageButton->setEnabled(true);
    }
    else
    {
        m_nCurPage = m_nTotalPage;
        m_pDownPageButton->setEnabled(false);
    }
}

void ReportLossGoodsWidget::initConnect()
{
    qRegisterMetaType<GoodsInfo>("GoodsInfo");
    connect(ui->listView, SIGNAL(sigClickItem(GoodsInfo)), this, SIGNAL(sigClickItem(GoodsInfo)));
}
