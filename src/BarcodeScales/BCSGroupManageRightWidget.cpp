#include "BCSGroupManageRightWidget.h"
#include "ui_BCSGroupManageRightWidget.h"

BCSGroupManageRightWidget::BCSGroupManageRightWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BCSGroupManageRightWidget)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
//    test();
    initConnect();
}

BCSGroupManageRightWidget::~BCSGroupManageRightWidget()
{
    delete ui;
}

//void BCSGroupManageRightWidget::test()
//{
//    BCSGroupManageRightInfo itemInfo;
//    for (int i = 0; i < 20; i++)
//    {
//        itemInfo.sKeyId = QString::number(i+1);
////        QString sSeq; // 序号
//        itemInfo.sGoodsName = QStringLiteral("胖头三文鱼%1").arg(i+1); // 商品名称
//        itemInfo.sGoodsCode = QString("2123%1").arg(i+1);// 商品编号
//        itemInfo.sGoodsUnit = QStringLiteral("公斤"); // 商品单位
//        itemInfo.sGoodsPlu = QString("1234%1").arg(i+1); // 商品plu码
//        itemInfo.sGoodsPrice = "20.99"; // 商品价格
//        itemInfo.sGoodsMemberPrice = "19.99"; // 商品会员价
//        m_infoList.append(itemInfo);
//    }

//    int nLen = m_infoList.length();
//    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
//    if (m_nTotalPage <= 0)
//    {
//        m_nTotalPage = 1;
//    }

//    generateUI();
//}

void BCSGroupManageRightWidget::initData(const QList<BCSGroupManageRightInfo> &infoList)
{
    m_infoList = infoList;
    int nLen = m_infoList.length();
    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }

    generateUI();
}

void BCSGroupManageRightWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void BCSGroupManageRightWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void BCSGroupManageRightWidget::slot_clickListItem(BCSGroupManageRightInfo itemInfo)
{

}

void BCSGroupManageRightWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_infoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        m_infoList[i].sSeq = QString::number(i+1);
        ui->listView->appendItem(m_infoList[i]);
    }
}

void BCSGroupManageRightWidget::checkCurPageButtonState()
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

void BCSGroupManageRightWidget::initConnect()
{
    qRegisterMetaType<BCSGroupManageRightInfo>("BCSGroupManageRightInfo");
    connect(ui->listView, SIGNAL(sigClickItem(BCSGroupManageRightInfo)), this, SLOT(slot_clickListItem(BCSGroupManageRightInfo)));
    checkCurPageButtonState();
}
