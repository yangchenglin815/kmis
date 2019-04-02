#include "ScreenSetPage.h"
#include "ui_ScreenSetPage.h"
#include <QMouseEvent>
#include <QDebug>

ScreenSetPage::ScreenSetPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScreenSetPage)
{
    ui->setupUi(this);
    init();
    initConnect();
    ui->noScreenRButton->setChecked(true);
    on_noScreenRButton_clicked();
}

ScreenSetPage::~ScreenSetPage()
{
    delete ui;
}

void ScreenSetPage::somePlacePressed(const QPoint &globalPoint)
{
    if (!ui->painterModelComBox->geometry().contains(ui->topWidget->mapFromGlobal(globalPoint)))
    {
        ui->painterModelComBox->hideListWidget();
    }
    if (!ui->clientScreenModelComBox->geometry().contains(ui->bottomWidget->mapFromGlobal(globalPoint)))
    {
        ui->clientScreenModelComBox->hideListWidget();
    }
    if (!ui->clientScreenPortComBox->geometry().contains(ui->bottomWidget->mapFromGlobal(globalPoint)))
    {
        ui->clientScreenPortComBox->hideListWidget();
    }
    if (!ui->cardReaderModelComBox->geometry().contains(ui->bottomWidget->mapFromGlobal(globalPoint)))
    {
        ui->cardReaderModelComBox->hideListWidget();
    }
    if (!ui->cardReaderPortComboBox->geometry().contains(ui->bottomWidget->mapFromGlobal(globalPoint)))
    {
        ui->cardReaderPortComboBox->hideListWidget();
    }
    if (!ui->eBalanceModelComboBox->geometry().contains(ui->bottomWidget->mapFromGlobal(globalPoint)))
    {
        ui->eBalanceModelComboBox->hideListWidget();
    }
    if (!ui->eBalancePortComboBox->geometry().contains(ui->bottomWidget->mapFromGlobal(globalPoint)))
    {
        ui->eBalancePortComboBox->hideListWidget();
    }
}

void ScreenSetPage::initData(const ScreenSet &screenSet)
{
    m_screenSet = screenSet;

//    ui->painterModelComBox
}

void ScreenSetPage::setDefultData(ScreenSet screenSet)
{
    m_screenSet = screenSet;
}

void ScreenSetPage::uploadData(KPosSet &kPosSet)
{
    Q_UNUSED( kPosSet )
}

void ScreenSetPage::init()
{
    QList<QString> strList;
    strList<<QStringLiteral("无")<<"NPI1220479"<<"XPS Writer"<<"Microsoft"<<"Fax";
    ui->painterModelComBox->initListWidget(strList);
    strList.clear();
    strList<<QStringLiteral("无")<<QStringLiteral("LED810")<<QStringLiteral("海信VC110");
    ui->clientScreenModelComBox->initListWidget(strList);
    strList.clear();
    strList<<QStringLiteral("无")<<("USB")<<"COM1"<<"COM2"<<"COM3"<<"COM4"<<"COM5"<<"COM6";
    ui->clientScreenPortComBox->initListWidget(strList);
    strList.clear();
    strList<<QStringLiteral("无")<<QStringLiteral("明泰mrf35")<<QStringLiteral("德卡D3")
          <<QStringLiteral("磁卡读卡器")<<QStringLiteral("顶尖Aclas");
    ui->cardReaderModelComBox->initListWidget(strList);
    strList.clear();
    strList<<QStringLiteral("无")<<("USB")<<"COM1"<<"COM2"<<"COM3"<<"COM4"<<"COM5";
    ui->cardReaderPortComboBox->initListWidget(strList);
    strList.clear();
    strList<<QStringLiteral("无")<<"VIVA4111"<<"CASPRPlus"<<QStringLiteral("大华电子秤-ACS")
          <<QStringLiteral("顶尖-PBX");
    ui->eBalanceModelComboBox->initListWidget(strList);
    strList.clear();
    strList<<("USB")<<"COM1"<<"COM2";
    ui->eBalancePortComboBox->initListWidget(strList);
}

void ScreenSetPage::initConnect()
{

}

void ScreenSetPage::on_printerTestButton_clicked()
{

}

void ScreenSetPage::on_clientScreenPortTestButton_clicked()
{

}

void ScreenSetPage::on_cardReaderTestButton_clicked()
{

}

void ScreenSetPage::on_noScreenRButton_clicked()
{
    ui->middleWidget->hide();
}

void ScreenSetPage::on_numberScreenRButton_clicked()
{
    ui->middleWidget->hide();
}

void ScreenSetPage::on_englishScreenRButton_clicked()
{
    ui->middleWidget->hide();
}

void ScreenSetPage::on_chineseScreenRButton_clicked()
{
    ui->middleWidget->hide();
}

void ScreenSetPage::on_colorScreenRButton_clicked()
{
    ui->middleWidget->show();
}
