#include "GoodsChooseWidget.h"
#include "ui_GoodsChooseWidget.h"

GoodsChooseWidget::GoodsChooseWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GoodsChooseWidget)
    , m_nOnePageCount(25)
    , m_nCurPage(1)
    , m_nTotalPage(1)
    , m_bRoot(true)
{
    ui->setupUi(this);
//    test();
    initConnect();
}

GoodsChooseWidget::~GoodsChooseWidget()
{
    delete ui;
}

//void GoodsChooseWidget::test()
//{
//    GoodsChooseInfo goodsChooseInfo;
//    for (int i = 0; i < 30; i++)
//    {
//        goodsChooseInfo.id = i;
//        goodsChooseInfo.name = QString(QStringLiteral("进口超级无籽瓤大西瓜%1")).arg(i);
//        goodsChooseInfo.bRootGoods = false;
//        goodsChooseInfo.price = "12.11";
//        goodsChooseInfo.unit = QStringLiteral("公斤");
//        m_goodsChooseInfoList.append(goodsChooseInfo);
////        ui->listView->appendItem(goodsChooseInfo);
//    }
//    m_nCurPage = 1;
//    int nLen = m_goodsChooseInfoList.length();
//    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
//    checkCurPageButtonState();
//    generateUIData();
//}

void GoodsChooseWidget::slot_chooseCategory(CategoryChooseInfo categoryChooseInfo)
{
    m_bRoot = categoryChooseInfo.bRoot;
    if (categoryChooseInfo.bRoot)
    {
        ui->confirmButton->setText(QStringLiteral("删除"));
        ui->confirmButton->setStyleSheet("QPushButton{border-image: url(:/kPosSetImage/goodsChoose/confirmDeleted.png);"
                                         "color:#ffffff;font-family:'微软雅黑';font-size:14px;}"
                                         "QPushButton:pressed{border-image: url(:/kPosSetImage/goodsChoose/confirmDeletedPress.png);}");
        ui->selectAddLabel->setStyleSheet("QLabel{background-color:#b36767}");
        ui->selectAddContentLabel->setText(QStringLiteral("选择删除商品"));
    }
    else
    {
        ui->confirmButton->setText(QStringLiteral("保存"));
        ui->confirmButton->setStyleSheet("QPushButton{border-image: url(:/kPosSetImage/goodsChoose/confirmSave.png);"
                                         "color:#ffffff;font-family:'微软雅黑';font-size:14px;}"
                                         "QPushButton:pressed{border-image: url(:/kPosSetImage/goodsChoose/confirmSavePress.png);}");
        ui->selectAddLabel->setStyleSheet("QLabel{background-color:#d3865c}");
        ui->selectAddContentLabel->setText(QStringLiteral("选择添加商品"));
    }

    m_goodsChooseInfoList = categoryChooseInfo.goodsChooseInfoList;
    m_nCurPage = 1;
    int nLen = m_goodsChooseInfoList.length();
    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    m_defaultSelectedGoodsIdList = categoryChooseInfo.selectedGoodsIdList;
    ui->listView->setDefaultSelectedGoodsList(m_defaultSelectedGoodsIdList);
    generateUIData();
}

void GoodsChooseWidget::slot_upPage()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUIData();
}

void GoodsChooseWidget::slot_downPage()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUIData();
}

void GoodsChooseWidget::initConnect()
{
    connect(ui->upArrowButton, SIGNAL(sigClick()), this, SLOT(slot_upPage()));
    connect(ui->downArrowButton, SIGNAL(sigClick()), this, SLOT(slot_downPage()));
}

void GoodsChooseWidget::generateUIData()
{
    ui->downArrowButton->setArrowText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));

    ui->listView->clearItems();
    int nStartPos = m_nOnePageCount * (m_nCurPage - 1);
    int nEndPos = m_nOnePageCount * m_nCurPage;
    int nLen = m_goodsChooseInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nLen; i++)
    {
        ui->listView->appendItem(m_goodsChooseInfoList[i]);
    }
}

void GoodsChooseWidget::checkCurPageButtonState()
{
    if (m_nCurPage <= 1)
    {
        m_nCurPage = 1;
        ui->upArrowButton->setArrowDisable();
    }
    else
    {
        ui->upArrowButton->setArrowEnable();
    }

    if (m_nCurPage < m_nTotalPage)
    {
        ui->downArrowButton->setArrowEnable();
    }
    else
    {
        m_nCurPage = m_nTotalPage;
        ui->downArrowButton->setArrowDisable();
    }
}

void GoodsChooseWidget::on_confirmButton_clicked()
{
    QList<int> oldList = m_defaultSelectedGoodsIdList;
    QList<int> nowList = ui->listView->getSelectedGoodsIdList();

    if (oldList != nowList)
    {
        if (!m_bRoot)
        {
            int nOldLen = oldList.length();
            for (int i = nOldLen - 1; i >= 0; i--)
            {
                int nFindId = m_defaultSelectedGoodsIdList[i];
                int nNowLen = nowList.length();
                for (int j = nNowLen - 1; j >= 0; j--)
                {
                    if (nowList[j] == nFindId)
                    {
                       nowList.removeAt(j);
                       oldList.removeAt(i);
                    }
                }
            }
            emit sigSaveGoodsIdList(oldList, nowList);
        }
        else
        {
            emit sigSaveGoodsIdList(nowList, oldList);
        }
    }
}
