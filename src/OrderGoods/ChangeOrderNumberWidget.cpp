#include "ChangeOrderNumberWidget.h"
#include "ui_ChangeOrderNumberWidget.h"
#include <QMouseEvent>
#include <QDebug>

ChangeOrderNumberWidget::ChangeOrderNumberWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChangeOrderNumberWidget)
    , m_pOrderNumberKeyboardDlg(NULL)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    this->setWindowModality(Qt::ApplicationModal);
    ui->lineEdit->setValidator(new QIntValidator(-1000, 10000, this));
    ui->lineEdit->installEventFilter(this);
    ui->lineEdit->setText("0");
}

ChangeOrderNumberWidget::~ChangeOrderNumberWidget()
{
    if (m_pOrderNumberKeyboardDlg != NULL)
    {
        m_pOrderNumberKeyboardDlg->deleteLater();
    }

    delete ui;
}

void ChangeOrderNumberWidget::initOrderNumber(int num)
{
    ui->lineEdit->setText(QString::number(num));
}

//bool ChangeOrderNumberWidget::eventFilter(QObject *watched, QEvent *event)
//{
//    if (watched != ui->leftArrowButton && watched != ui->rightArrowButton)
//    {
//        if (event->type() == QEvent::MouseButtonPress)
//        {
//            showKeyBoard();
//        }
//    }
//    return QWidget::eventFilter(watched, event);
//}

void ChangeOrderNumberWidget::slot_clickNumber(QString sNum)
{
    QString text = ui->lineEdit->text();
    if (text.toInt() != 0)
    {
        ui->lineEdit->setText(text.append(sNum));
    }
    else
    {
        ui->lineEdit->setText(sNum);
    }
}

void ChangeOrderNumberWidget::slot_clickDelete()
{
    QString text = ui->lineEdit->text();
    text.remove(text.length() - 1, 1);
    if (text.isEmpty())
    {
       text = "0";
    }
    ui->lineEdit->setText(text);
}

void ChangeOrderNumberWidget::slot_clickEnter()
{
    this->hide();
    emit sigChangeNum(ui->lineEdit->text().toInt());
}

void ChangeOrderNumberWidget::on_leftArrowButton_clicked()
{
    QString text = ui->lineEdit->text();
    int nNum = text.toInt();
    nNum--;
//    if (nNum < 0)
//    {
//        nNum = 0;
//    }
    ui->lineEdit->setText(QString::number(nNum));
    slot_clickEnter();
}

void ChangeOrderNumberWidget::on_rightArrowButton_clicked()
{
    QString text = ui->lineEdit->text();
    int nNum = text.toInt();
    nNum++;
    ui->lineEdit->setText(QString::number(nNum));
    slot_clickEnter();
}

void ChangeOrderNumberWidget::showKeyBoard()
{
    if (m_pOrderNumberKeyboardDlg == NULL)
    {
        m_pOrderNumberKeyboardDlg = new OrderNumberKeyboardDlg;
        connect(m_pOrderNumberKeyboardDlg, SIGNAL(sigClickNumber(QString)), this, SLOT(slot_clickNumber(QString)));
        connect(m_pOrderNumberKeyboardDlg, SIGNAL(sigClickDelete()), this, SLOT(slot_clickDelete()));
        connect(m_pOrderNumberKeyboardDlg, SIGNAL(sigClickEnter()), this, SLOT(slot_clickEnter()));
    }

    const int nScreenHeight = 600;
    int nXPos = this->x() - m_pOrderNumberKeyboardDlg->width();
    int nYPos = this->y();
    if (nYPos + m_pOrderNumberKeyboardDlg->height() > nScreenHeight)
    {
        nYPos = nScreenHeight - m_pOrderNumberKeyboardDlg->height();
    }

    m_pOrderNumberKeyboardDlg->move(nXPos, nYPos);
    m_pOrderNumberKeyboardDlg->exec();
}


