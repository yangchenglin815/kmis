#include "AdjustPriceGoodsWidget.h"
#include "ui_AdjustPriceGoodsWidget.h"
#include "../data/constData.h"
#include <QDebug>

AdjustPriceGoodsWidget::AdjustPriceGoodsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdjustPriceGoodsWidget)
    , m_nCurPage(1)
    , m_nTotalPage(1)
    , m_nOnePageCount(25)
    , m_pUpPageButton(NULL)
    , m_pDownPageButton(NULL)
{
    ui->setupUi(this);
    initConnect();
}

AdjustPriceGoodsWidget::~AdjustPriceGoodsWidget()
{
    delete ui;
}

void AdjustPriceGoodsWidget::setUpDownPageButton(QPushButton *pUpPageButton, QPushButton *pDownPageButton)
{
    m_pUpPageButton = pUpPageButton;
    m_pDownPageButton = pDownPageButton;
    connect(m_pUpPageButton, SIGNAL(clicked()), this, SLOT(slot_upPage()));
    connect(m_pDownPageButton, SIGNAL(clicked()), this, SLOT(slot_downPage()));
}

void AdjustPriceGoodsWidget::initData(QList<GoodsInfo> goodsInfoList)
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

void AdjustPriceGoodsWidget::slot_upPage()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void AdjustPriceGoodsWidget::slot_downPage()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void AdjustPriceGoodsWidget::resizeEvent(QResizeEvent *)
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

void AdjustPriceGoodsWidget::generateUI()
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

void AdjustPriceGoodsWidget::checkCurPageButtonState()
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

void AdjustPriceGoodsWidget::initConnect()
{
    qRegisterMetaType<GoodsInfo>("GoodsInfo");
    connect(ui->listView, SIGNAL(sigClickItem(GoodsInfo)), this, SIGNAL(sigClickItem(GoodsInfo)));
}
