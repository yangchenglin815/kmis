#include "AdjustPositionWidget.h"
#include "ui_AdjustPositionWidget.h"
#include <QMessageBox>

AdjustPositionWidget* AdjustPositionWidget::m_pInstance = NULL;

AdjustPositionWidget::AdjustPositionWidget()
    : ui(new Ui::AdjustPositionWidget)
    , m_curText("0")
    , m_nPosition(-1)
    , m_nOwnerType(-1)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::FramelessWindowHint/*|Qt::WindowStaysOnTopHint|Qt::Popup*/|Qt::Tool);
    ui->lineEdit->setText(m_curText);
    ui->lineEdit->setValidator(new QIntValidator(0, 100000, this));
}

AdjustPositionWidget::~AdjustPositionWidget()
{
    delete ui;
}

void AdjustPositionWidget::setPosition(int nPosition)
{
    m_nPosition = nPosition;
    m_curText = QString::number(m_nPosition);
    ui->lineEdit->setText(m_curText);
}

void AdjustPositionWidget::setOwnerType(int nOwnerType)
{
    m_nOwnerType = nOwnerType;
}

AdjustPositionWidget *AdjustPositionWidget::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new AdjustPositionWidget;
    }
    return m_pInstance;
}

void AdjustPositionWidget::on_num0Button_clicked()
{
    setLineEditText("0");
}

void AdjustPositionWidget::on_num1Button_clicked()
{
    setLineEditText("1");
}

void AdjustPositionWidget::on_num2Button_clicked()
{
    setLineEditText("2");
}

void AdjustPositionWidget::on_num3Button_clicked()
{
    setLineEditText("3");
}

void AdjustPositionWidget::on_num4Button_clicked()
{
    setLineEditText("4");
}

void AdjustPositionWidget::on_num5Button_clicked()
{
    setLineEditText("5");
}

void AdjustPositionWidget::on_num6Button_clicked()
{
    setLineEditText("6");
}

void AdjustPositionWidget::on_num7Button_clicked()
{
    setLineEditText("7");
}

void AdjustPositionWidget::on_num8Button_clicked()
{
    setLineEditText("8");
}

void AdjustPositionWidget::on_num9Button_clicked()
{
    setLineEditText("9");
}

void AdjustPositionWidget::on_deleteButton_clicked()
{
    QString sNum = ui->lineEdit->text();
    m_curText = sNum.remove(sNum.length() - 1, 1);
    ui->lineEdit->setText(m_curText);
}

void AdjustPositionWidget::on_enterButton_clicked()
{
    QString sNum = ui->lineEdit->text().trimmed();
    int nNum = sNum.toInt();
    emit sigMovePosition(nNum, m_nPosition, m_nOwnerType);
    this->hide();
}

void AdjustPositionWidget::on_leftArrowButton_clicked()
{
    QString sNum = ui->lineEdit->text().trimmed();
    int nNum = sNum.toInt();
    nNum--;
    if (nNum < 0)
    {
        nNum = 0;
    }
    m_curText = QString::number(nNum);
    ui->lineEdit->setText(m_curText);
}

void AdjustPositionWidget::on_rightArrowButton_clicked()
{
    QString sNum = ui->lineEdit->text().trimmed();
    int nNum = sNum.toInt();
    nNum++;
    m_curText = QString::number(nNum);
    ui->lineEdit->setText(m_curText);
}

void AdjustPositionWidget::setLineEditText(QString sNum)
{
    if (m_curText == "0")
    {
        m_curText = sNum;
    }
    else
    {
        m_curText.append(sNum);
    }

    ui->lineEdit->setText(m_curText);
}
