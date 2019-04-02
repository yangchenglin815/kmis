#include "CheckOrderCategoryDetailWidget.h"
#include "ui_CheckOrderCategoryDetailWidget.h"
#include <QDebug>
#include <QMessageBox>

#include "TipsDlg.h"

CheckOrderCategoryDetailWidget::CheckOrderCategoryDetailWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CheckOrderCategoryDetailWidget)
    , m_pCheckOrderGoodsDlg(NULL)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
//    test();
    initConnect();
}

CheckOrderCategoryDetailWidget::~CheckOrderCategoryDetailWidget()
{
    if (m_pCheckOrderGoodsDlg != NULL)
    {
        m_pCheckOrderGoodsDlg->deleteLater();
    }
    delete ui;
}

void CheckOrderCategoryDetailWidget::clearSelectId()
{
    ui->listView->clearId();
}

void CheckOrderCategoryDetailWidget::initData(const QList<CheckOrderCategoryDetailInfo *> categoryDetailInfoList)
{
    m_checkOrderCategoryDetailInfoList = categoryDetailInfoList;
    m_nCurPage = 1;
    int nCount = m_checkOrderCategoryDetailInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
    initButtons();
}

void CheckOrderCategoryDetailWidget::removeCategory(int nCategoryId)
{
    int nCount = m_checkOrderCategoryDetailInfoList.length();
    for (int i = nCount - 1; i >= 0; i--)
    {
        if (m_checkOrderCategoryDetailInfoList[i]->nCategoryId == nCategoryId)
        {
            ui->listView->removeId(m_checkOrderCategoryDetailInfoList[i]->nOrderCardId);
            m_checkOrderCategoryDetailInfoList.removeAt(i); 
        }
    }
    initData(m_checkOrderCategoryDetailInfoList);
}

void CheckOrderCategoryDetailWidget::appendCategory(const QList<CheckOrderCategoryDetailInfo *> categoryDetailInfoList)
{
    m_checkOrderCategoryDetailInfoList.append(categoryDetailInfoList);
    initData(m_checkOrderCategoryDetailInfoList);
}

void CheckOrderCategoryDetailWidget::updateData()
{
    generateUI();
}

void CheckOrderCategoryDetailWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void CheckOrderCategoryDetailWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

//void CheckOrderCategoryDetailWidget::on_checkManyButton_clicked()
//{
//    QList<int> selectedIdList = ui->listView->getSelectedIdList();
////    int nLen = m_checkOrderCategoryDetailInfoList.length();
////    QList<CheckOrderCategoryDetailInfo*> selectCheckOrderCategoryDetailInfoList;
////    CheckOrderCategoryDetailInfo* pCheckOrderCategoryDetailInfo = NULL;
////    for (int i = 0; i < nLen; i++)
////    {
////        pCheckOrderCategoryDetailInfo = m_checkOrderCategoryDetailInfoList[i];
////        if (selectedIdList.contains(pCheckOrderCategoryDetailInfo->sCardOrOrderId))
////        {
////            selectCheckOrderCategoryDetailInfoList.append(pCheckOrderCategoryDetailInfo);
////        }
////    }
//    emit sigCheckManyOrderCategoryDetailInfo(selectedIdList);
//}

void CheckOrderCategoryDetailWidget::slot_selectId(int nOrderCardId, bool bSelected)
{
    int nLen = m_checkOrderCategoryDetailInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_checkOrderCategoryDetailInfoList[i]->nOrderCardId == nOrderCardId)
        {
            m_checkOrderCategoryDetailInfoList[i]->bSelected = bSelected;

            break;
        }
    }
    bool bIsSelected = ui->listView->getSelectedIdList().length() > 0;
    ui->deleteButton->setEnabled(bIsSelected );
    ui->uploadButton->setEnabled(bIsSelected );
    ui->editButton->setEnabled(bIsSelected );
    ui->searchButton->setEnabled(false);
}

void CheckOrderCategoryDetailWidget::slot_clickItem(bool search)
{
    ui->searchButton->setEnabled(search);

    ui->deleteButton->setEnabled(false);
    ui->uploadButton->setEnabled(false);
    ui->editButton->setEnabled(false);
}

void CheckOrderCategoryDetailWidget::on_deleteButton_clicked()
{
    QList<int> selectedIdList = ui->listView->getSelectedIdList();
    emit sigRemoveOrderCard(selectedIdList);
}

void CheckOrderCategoryDetailWidget::on_uploadButton_clicked()
{
    QList<int> selectedIdList = ui->listView->getSelectedIdList();
    emit sigUploadOrderCard(selectedIdList);
}

void CheckOrderCategoryDetailWidget::on_searchButton_clicked()
{
    int nChooseId = ui->listView->getChooseId();
    if (nChooseId > 0)
    {
        emit sigSearchOrderCard(nChooseId);
    }
    else
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("没有选中"));
    }
}

void CheckOrderCategoryDetailWidget::on_editButton_clicked()
{
    QList<int> seletedIdList = ui->listView->getSelectedIdList();
    if (seletedIdList.length())
    {
        emit sigEditOrderCard(seletedIdList);
    }
    else
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("没有勾选中"));
    }
}

void CheckOrderCategoryDetailWidget::on_addButton_clicked()
{
    emit sigAddCheckOrder();
}

void CheckOrderCategoryDetailWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_checkOrderCategoryDetailInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(*(m_checkOrderCategoryDetailInfoList[i]));
    }
}

void CheckOrderCategoryDetailWidget::checkCurPageButtonState()
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

void CheckOrderCategoryDetailWidget::initConnect()
{
    connect(ui->listView, SIGNAL(sigClickItem(bool)), this, SLOT(slot_clickItem(bool)));
    connect(ui->listView, SIGNAL(sigSelectId(int,bool)), this, SLOT(slot_selectId(int,bool)));
}

void CheckOrderCategoryDetailWidget::initButtons()
{
    ui->deleteButton->setEnabled(ui->listView->getSelectedIdList().length() > 0);
    ui->uploadButton->setEnabled(ui->listView->getSelectedIdList().length() > 0);
    ui->editButton->setEnabled(ui->listView->getSelectedIdList().length() > 0);
    ui->searchButton->setEnabled(ui->listView->getChooseId() > 0);
}


