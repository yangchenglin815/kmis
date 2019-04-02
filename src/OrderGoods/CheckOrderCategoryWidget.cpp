#include "CheckOrderCategoryWidget.h"
#include "ui_CheckOrderCategoryWidget.h"
#include "../data/constData.h"
#include "../util/CommonFun.h"
#include <QDebug>
#include <QMessageBox>

#include "TipsDlg.h"

CheckOrderCategoryWidget::CheckOrderCategoryWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CheckOrderCategoryWidget)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
    , m_pKPosCalendarWidget(NULL)
    , m_bInStartDate(false)
    , m_sStartDate("")
    , m_sEndDate("")
    , m_sSearchPattern("")
{
    ui->setupUi(this);
    initConnect();
    ui->startDateEdit->installEventFilter(this);
    ui->endDateEdit->installEventFilter(this);
//    ui->searchWidget->startSearchTimer();
}

CheckOrderCategoryWidget::~CheckOrderCategoryWidget()
{
    delete ui;
}

void CheckOrderCategoryWidget::initData(const QList<CheckOrderCategoryInfo *> checkOrderCategoryInfoList)
{
    m_checkOrderCategoryInfoList = checkOrderCategoryInfoList;
    m_nCurPage = 1;
    int nCount = m_checkOrderCategoryInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }

    slot_selectAllCategory(true);
}

bool CheckOrderCategoryWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->startDateEdit)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            inputStartDate();
        }
    }
    else if (watched == ui->endDateEdit)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            inputEndDate();
        }

    }
    return QWidget::eventFilter(watched, event);
}

void CheckOrderCategoryWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    if (m_nCurPage > m_nTotalPage || m_nCurPage < 0)
    {
        m_nCurPage = 1;
    }
    generateUI();
}

void CheckOrderCategoryWidget::slot_selectAllCategory(bool bSelectAll)
{
    QList<int> selectIdList;
    if (bSelectAll)
    {
        int nLen = m_checkOrderCategoryInfoList.length();
        for (int i = 0; i < nLen; i++)
        {
            selectIdList.append(m_checkOrderCategoryInfoList[i]->nId);
        }
        selectIdList.append(c_nNegativeNumber);
        ui->listView->setDefaultSelectedIdList(selectIdList);
    }
    else
    {
        ui->listView->setDefaultSelectedIdList(selectIdList);
    }
    generateUI();
    emit sigSelectAllCategory(bSelectAll);
}

void CheckOrderCategoryWidget::slot_addSelectCategory(int nCategoryId, bool bAdded)
{
    generateUI();
    emit sigAddSelectCategory(nCategoryId, bAdded);
}

void CheckOrderCategoryWidget::slot_clickDate(int nYear, int nMonth, int nDay)
{
    QString text = QString("%1.%2.%3").arg(nYear).arg(nMonth).arg(nDay);
    if (m_bInStartDate)
    {
        ui->startDateEdit->setText(text);
        m_sStartDate = CommonFun::getFormatDate(nYear, nMonth, nDay);
    }
    else
    {
        ui->endDateEdit->setText(text);
        m_sEndDate = CommonFun::getFormatDate(nYear, nMonth, nDay + 1);
    }

    if (!m_sStartDate.isEmpty() && !m_sEndDate.isEmpty())
    {
        if (m_sStartDate >= m_sEndDate)
        {
            TipsDlg::instance()->releaseCtrl(QStringLiteral("搜索起始日期大于结束日期，请重新输入！"));
        }
        else
        {
           emit sigSearch(m_sStartDate, m_sEndDate, m_sSearchPattern);
        }
    }
}

void CheckOrderCategoryWidget::slot_searchChanged(QString searchText)
{
    if (!m_sStartDate.isEmpty() && !m_sEndDate.isEmpty())
    {
        if (m_sStartDate >= m_sEndDate)
        {
            TipsDlg::instance()->releaseCtrl(QStringLiteral("搜索起始日期大于结束日期，请重新输入！"));
            return;
        }
    }

    m_sSearchPattern = searchText;
    emit sigSearch(m_sStartDate, m_sEndDate, m_sSearchPattern);
}

void CheckOrderCategoryWidget::generateUI()
{
    ui->listView->clearItems();
    CheckOrderCategoryInfo rootCheckOrderCategoryInfo;
    rootCheckOrderCategoryInfo.nId = c_nNegativeNumber;
    rootCheckOrderCategoryInfo.sName = QStringLiteral("全部");
    ui->listView->appendItem(rootCheckOrderCategoryInfo);

    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_checkOrderCategoryInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(*(m_checkOrderCategoryInfoList[i]));
    }
}

void CheckOrderCategoryWidget::initConnect()
{
    connect(ui->listView, SIGNAL(sigSelectAllCategory(bool)), this, SLOT(slot_selectAllCategory(bool)));
    connect(ui->listView, SIGNAL(sigAddSelectCategory(int,bool)), this, SLOT(slot_addSelectCategory(int,bool)));
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
}

void CheckOrderCategoryWidget::inputStartDate()
{
    m_bInStartDate = true;

    if (m_pKPosCalendarWidget == NULL)
    {
        m_pKPosCalendarWidget = new KPosCalendarWidget;
        connect(m_pKPosCalendarWidget, SIGNAL(sigClickDate(int,int,int)), this, SLOT(slot_clickDate(int,int,int)));
    }
    QPoint globalPos = ui->startDateEdit->mapToGlobal(QPoint(0,0));

    int nXPos = globalPos.x();
    int nYPos = globalPos.y() + ui->startDateEdit->height() + 10;
    m_pKPosCalendarWidget->move(nXPos, nYPos);
    m_pKPosCalendarWidget->activateWindow();
    m_pKPosCalendarWidget->showNormal();
}

void CheckOrderCategoryWidget::inputEndDate()
{
    m_bInStartDate = false;

    if (m_pKPosCalendarWidget == NULL)
    {
        m_pKPosCalendarWidget = new KPosCalendarWidget;
        connect(m_pKPosCalendarWidget, SIGNAL(sigClickDate(int,int,int)), this, SLOT(slot_clickDate(int,int,int)));
    }
    QPoint globalPos = ui->endDateEdit->mapToGlobal(QPoint(0,0));

    int nXPos = globalPos.x();
    int nYPos = globalPos.y() + ui->endDateEdit->height() + 10;
    m_pKPosCalendarWidget->move(nXPos, nYPos);
    m_pKPosCalendarWidget->activateWindow();
    m_pKPosCalendarWidget->showNormal();
}
