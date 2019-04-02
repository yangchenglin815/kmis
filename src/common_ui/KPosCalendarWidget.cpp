#include "KPosCalendarWidget.h"
#include "ui_KPosCalendarWidget.h"
#include "commonuidata.h"
#include "../util/CommonFun.h"
#include "../data/constData.h"
#include <QDateTime>

KPosCalendarWidget::KPosCalendarWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::KPosCalendarWidget)
    , m_nYear(0)
    , m_nMonth(0)
    , m_nDay(0)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
    init();
    initConnect();
}

KPosCalendarWidget::~KPosCalendarWidget()
{
    delete ui;
}

void KPosCalendarWidget::on_yearLeftButton_clicked()
{
    m_nYear--;
    if (m_nYear < 1990)
    {
        m_nYear = 1990;
    }
    ui->yearLabel->setText(QString::number(m_nYear));
    generateUI();
}

void KPosCalendarWidget::on_yearRightButton_clicked()
{
    m_nYear++;
    if (m_nYear > 2099)
    {
        m_nYear = 2099;
    }
    ui->yearLabel->setText(QString::number(m_nYear));
    generateUI();
}

void KPosCalendarWidget::on_monthLeftButton_clicked()
{
    m_nMonth--;
    if (m_nMonth < 1)
    {
        m_nMonth = 12;
    }
    ui->monthLabel->setText(QString(QStringLiteral("%1月")).arg(m_nMonth));
    generateUI();
}

void KPosCalendarWidget::on_monthRightButton_clicked()
{
    m_nMonth++;
    if (m_nMonth > 12)
    {
        m_nMonth = 1;
    }
    ui->monthLabel->setText(QString(QStringLiteral("%1月")).arg(m_nMonth));
    generateUI();
}

void KPosCalendarWidget::init()
{
    m_nYear = QDateTime::currentDateTime().date().year();
    m_nMonth = QDateTime::currentDateTime().date().month();
    m_nDay = QDateTime::currentDateTime().date().day();
    ui->yearLabel->setText(QString::number(m_nYear));
    ui->monthLabel->setText(QString(QStringLiteral("%1月")).arg(m_nMonth));
    ui->listView->setDefualtDate(m_nYear, m_nMonth, m_nDay);
    generateUI();
}

void KPosCalendarWidget::generateUI()
{
    ui->listView->setYearAndMonth(m_nYear, m_nMonth);
    ui->listView->clearItems();
    int nMonthDay = CommonFun::getMonthDay(m_nYear, m_nMonth);
    int nStartWeek = CommonFun::getWeekDay(m_nYear, m_nMonth, 1);
    CalendarInfo calendarInfo;
    for (int i = 0; i < nStartWeek; i++)
    {
        calendarInfo.nDay = c_nNegativeNumber - i;
        ui->listView->appendItem(calendarInfo);
    }
    for (int i = 1; i <= nMonthDay; i++)
    {
        calendarInfo.nDay = i;
        ui->listView->appendItem(calendarInfo);
    }
}

void KPosCalendarWidget::initConnect()
{
    connect(ui->listView, SIGNAL(sigClickDate(int,int,int)), this, SIGNAL(sigClickDate(int,int,int)));
}
