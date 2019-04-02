#include "CheckDetialWidget.h"
#include "ui_CheckDetialWidget.h"

CheckDetialWidget::CheckDetialWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckDetialWidget)
  , m_nOnePageCount(7)
  , m_nTotalPage(1)
  , m_nCurPage(1)
  , m_selectId(-1)
{
    ui->setupUi(this);
    initconnect();
    init();
//    test();
}

CheckDetialWidget::~CheckDetialWidget()
{
    delete ui;
}

void CheckDetialWidget::initData(const QList<AddReportLossSelectInfo> &itemInfoList)
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

void CheckDetialWidget::getSelectId(int selectId)
{
    m_selectId = selectId;
}

void CheckDetialWidget::showEvent(QShowEvent *)
{
    QPoint globalPoint = ui->topWidget->mapToGlobal(QPoint(0, 0));
    const int nOffx = 11;
    int nXPos = globalPoint.x() - nOffx;
    int nYPos = globalPoint.y() + ui->searchWidget->height();
    ui->searchWidget->setKeyboardPos(nXPos, nYPos);
}

void CheckDetialWidget::slot_last()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void CheckDetialWidget::slot_next()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void CheckDetialWidget::slot_sortFourthCol(bool m_bFourthArrowDown)
{
    for(int i=0; i<m_InfoList.length(); i++){
        for(int j=0; j<m_InfoList.length()-i-1; j++){
            if(m_bFourthArrowDown){
                if(m_InfoList.at(j).sNumber < m_InfoList.at(j+1).sNumber){
                    m_InfoList.swap(j, j+1);
                }
            }
            else{
                if(m_InfoList.at(j).sNumber > m_InfoList.at(j+1).sNumber){
                    m_InfoList.swap(j, j+1);
                }
            }
        }
    }
    generateUI();
}

void CheckDetialWidget::slot_sortFifthCol(bool m_bFifthArrowDown)
{
    for(int i=0; i<m_InfoList.length(); i++){
        for(int j=0; j<m_InfoList.length()-i-1; j++){
            if((m_InfoList.at(j).sMoney < m_InfoList.at(j+1).sMoney) == m_bFifthArrowDown){
                m_InfoList.swap(j, j+1);
            }
        }
    }
    generateUI();
}

void CheckDetialWidget::slot_searchChanged(QString str)
{
    ui->listView->clearItems();
    if(str.isEmpty()){
        initData(m_InfoList);
    }
    else{
        int count = 0;
        QList<CheckDetialInfo> infoList;
        for(int i=0; i<m_InfoList.length(); i++){
            if(m_InfoList[i].sCode == str || m_InfoList[i].sCategoryName == str || m_InfoList[i].sName.contains(str)){
                 count++;
                 infoList.append(m_InfoList[i]);
            }
        }
        int nCount = infoList.length();
        m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
        if (m_nTotalPage <= 0)
        {
            m_nTotalPage = 1;
        }
        checkCurPageButtonState();
        generateUI();
    }
}

void CheckDetialWidget::init()
{
    ui->searchWidget->setHintText("");
}

void CheckDetialWidget::initconnect()
{
   connect(ui->lastPageButton, SIGNAL(clicked()), this, SLOT(slot_last()));
   connect(ui->nextPageButton, SIGNAL(clicked()), this, SLOT(slot_next()));
   connect(ui->titleWidget, SIGNAL(sigSortFoutthCol(bool)), this, SLOT(slot_sortFourthCol(bool)));
   connect(ui->titleWidget, SIGNAL(sigSortFifthCol(bool)), this, SLOT(slot_sortFifthCol(bool)));
   connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
}

void CheckDetialWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_InfoList.length();
    float totalPrice = 0;
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        m_InfoList[i].nId = 1+i;
        ui->listView->appendItem(m_InfoList[i]);
        totalPrice += m_InfoList[i].sMoney;
    }
    ui->totalLabel->setText(QString::number(totalPrice, 'f', 2));
}

void CheckDetialWidget::checkCurPageButtonState()
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

void CheckDetialWidget::test()
{
    int nLen = 20;
    AddReportLossSelectInfo *info = NULL;
    for (int i = 0; i < nLen; i++)
    {
        info = new AddReportLossSelectInfo;
        info->id = i+1;
        info->sCategoryName = "水果";
        info->sCode = "002155661202235";
        info->sMoney = 100.00;
        info->sName = "无籽沙瓤大苹果";
        info->sNumber = 1.00;
        info->sUnit = "(公斤)";
        m_InfoList.append(*info);
    }
    initData(m_InfoList);
}
