#include "BCSGoodsWidget.h"
#include "ui_BCSGoodsWidget.h"

BCSGoodsWidget::BCSGoodsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BCSGoodsWidget)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
//    test();
    initConnect();
}

BCSGoodsWidget::~BCSGoodsWidget()
{
    delete ui;
}

//void BCSGoodsWidget::test()
//{
//    int nLen = 20;
//    BCSGoodsInfo *pBCSGoodsInfo = NULL;
//    for (int i = 0; i < nLen; i++)
//    {
//        pBCSGoodsInfo = new BCSGoodsInfo;
//        pBCSGoodsInfo->sKeyId = QString("%1").arg(i+1);
//        pBCSGoodsInfo->sName = QStringLiteral("胖头3纹鱼%1").arg(i+1); // 商品名字
//        pBCSGoodsInfo->sCode = QString("0000%1").arg(i+1); // 商品编号
//        pBCSGoodsInfo->sUnit = QStringLiteral("公斤"); // 商品单位
//        pBCSGoodsInfo->sPlu = QString("1234%1").arg(i+1); // 商品PLU码
//        pBCSGoodsInfo->sPrice = "20.99"; // 商品价格
//        pBCSGoodsInfo->sMemberPrice = "19.99"; // 商品会员价
//        m_InfoList.append(pBCSGoodsInfo);
//    }

//    initData(m_InfoList);
//}

void BCSGoodsWidget::initData(const QList<BCSGoodsInfo> &itemInfoList)
{
    m_InfoList = itemInfoList;
    int nCount = m_InfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void BCSGoodsWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void BCSGoodsWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void BCSGoodsWidget::on_saveButton_clicked()
{
    QList<QString> keyIdList;
    ui->listView->getSelectIdList(keyIdList);
    emit sigSaveGroupGoods(keyIdList);
}

void BCSGoodsWidget::slot_selectCurPageAllBox(bool bSelectAll)
{
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_InfoList.length();
    QList<QString> keyIdList;
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        keyIdList.append(m_InfoList[i].sKeyId);
    }

    if (bSelectAll)
    {
        ui->listView->appendSelectKeyIds(keyIdList);
    }
    else
    {
        ui->listView->removeSelectKeyIds(keyIdList);
    }

    generateUI();

    slot_clickItem();
}

void BCSGoodsWidget::slot_clickItem()
{
    QList<QString> keyIdList;
    ui->listView->getSelectIdList(keyIdList);
    ui->countLabel->setText(QString::number(keyIdList.count()));
    emit sigUpdateSelectCount(keyIdList);
}

void BCSGoodsWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_InfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(m_InfoList[i]);
    }
}

void BCSGoodsWidget::checkCurPageButtonState()
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

void BCSGoodsWidget::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sigSelectBox(bool)), this, SLOT(slot_selectCurPageAllBox(bool)));
    connect(ui->listView, SIGNAL(sigClickItem()), this, SLOT(slot_clickItem()));
}
