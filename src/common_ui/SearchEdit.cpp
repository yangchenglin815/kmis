#include "SearchEdit.h"
#include "ui_SearchEdit.h"
#include "../util/CommonFun.h"
#include <QProcess>
#include <QDesktopWidget>
#include <QDebug>

SearchEdit::SearchEdit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchEdit)
//    , bStartSearchTimer(false)
    , m_nInputXPos(-1)
    , m_nInputYPos(-1)
    , m_pInputToolWidget(NULL)
{
    ui->setupUi(this);
    m_pInputToolWidget = new InputToolWidget;
    initConnect();
    ui->searchLineEdit->installEventFilter(this);
}

SearchEdit::~SearchEdit()
{
    delete ui;
}

void SearchEdit::setHintText(QString text)
{
    ui->searchLineEdit->setPlaceholderText(text);
}

//void SearchEdit::startSearchTimer()
//{
//    bStartSearchTimer = true;
//}

QString SearchEdit::getText()
{
    return ui->searchLineEdit->text();
}

void SearchEdit::setText(QString sText)
{
    ui->searchLineEdit->setText(sText);
}

void SearchEdit::clearText()
{
    ui->searchLineEdit->setText("");
}

void SearchEdit::setKeyboardPos(int nXPos, int nYPos, bool bHCenter)
{
    m_nInputXPos = nXPos;
    if (bHCenter)
    {
        m_nInputXPos = (800 - m_pInputToolWidget->width())/2; // 暂时考虑800*600的
    }
    m_nInputYPos = nYPos;
}

void SearchEdit::autoSetKeyboardPos(int nOffX, int nOffY)
{
    QPoint globalPoint = this->mapToGlobal(QPoint(0, 0));
    m_nInputXPos = globalPoint.x() + nOffX;
    m_nInputYPos = globalPoint.y() + this->height() + nOffY;
}

void SearchEdit::hideKeyboard()
{
    m_pInputToolWidget->hide();
}

void SearchEdit::setSearchFocus()
{
    ui->searchLineEdit->setFocus();
}

void SearchEdit::setLength(int length)
{
    ui->searchLineEdit->setMaxLength(length);
}

void SearchEdit::hideKeyboardButton()
{
    ui->keyboardButton->hide();
}

void SearchEdit::setHolderText(QString sText)
{
    ui->searchLineEdit->setPlaceholderText(sText);
}

void SearchEdit::setOuterLineColor(QString sColor)
{
    ui->searchSkinWidget->setStyleSheet(QString("QWidget#searchSkinWidget{border:1px solid %1}").arg(sColor));
}

void SearchEdit::setSearchEditMaxLength(int maxLength)
{
    ui->searchLineEdit->setMaxLength(maxLength);
}

void SearchEdit::resetStyleSheet()
{
   ui->keyboardButton->setStyleSheet("border-image:none;");
   ui->keyboardButton->setFlat(true);
   ui->keyboardButton->setEnabled(false);
}

bool SearchEdit::eventFilter(QObject *watched, QEvent *event)
{
    if (watched==ui->searchLineEdit)         //首先判断控件
    {
        if(event->type()==QEvent::MouseButtonPress )
        {
            if (m_pInputToolWidget->isVisible())
            {
                m_pInputToolWidget->hide();
            }
            else
            {
                m_pInputToolWidget->move(m_nInputXPos, m_nInputYPos);
                m_pInputToolWidget->activateWindow();
                m_pInputToolWidget->clearLabel();
                m_pInputToolWidget->showNormal();
            }
//            timer.start(1000);
        }
    }

    return QWidget::eventFilter(watched, event);
}

//void SearchEdit::on_searchLineEdit_textChanged(const QString &text)
//{
//    sSearchText = text;
//    if (bStartSearchTimer)
//    {
//        searchTimer.stop();
//        searchTimer.start(2*1000);
//    }
//    else
//    {
//        emit sigSearchChanged(text);
//    }
//}

void SearchEdit::on_keyboardButton_clicked()
{
//    QProcess::startDetached("explorer osk.exe");
    m_pInputToolWidget->move(m_nInputXPos, m_nInputYPos);
    m_pInputToolWidget->activateWindow();
    m_pInputToolWidget->showNormal();

//    timer.start(1000);
}

//void SearchEdit::slot_timeout()
//{
//    timer.stop();
//    ui->searchLineEdit->setFocus();
//}

//void SearchEdit::slot_searchTimeout()
//{
//    searchTimer.stop();
//}

void SearchEdit::slot_addWord(QString sWord)
{
    QString sText = ui->searchLineEdit->text();
    ui->searchLineEdit->setText(sText.append(sWord));
//    ui->searchLineEdit->setFocus();
}

void SearchEdit::slot_delete()
{
    QString sText = ui->searchLineEdit->text();
    sText.remove(sText.length() - 1, 1);
    ui->searchLineEdit->setText(sText);
}

void SearchEdit::slot_clear()
{
    ui->searchLineEdit->clear();
}

void SearchEdit::slot_cofirm()
{
    on_searchLineEdit_returnPressed();
}

void SearchEdit::initConnect()
{
//    connect(&timer, SIGNAL(timeout()), this, SLOT(slot_timeout()));
//    connect(&searchTimer, SIGNAL(timeout()), this, SLOT(slot_searchTimeout()));
//    connect(m_pInputToolWidget, SIGNAL(sigWord(QString)), this, SLOT(slot_addWord(QString)));
//    connect(m_pInputToolWidget, SIGNAL(sigDeleteWord()), this, SLOT(slot_delete()));
//    connect(m_pInputToolWidget, SIGNAL(sigClear()), this, SLOT(slot_clear()));
    connect(m_pInputToolWidget, SIGNAL(sigConfirm()), this, SLOT(slot_cofirm()));
}

void SearchEdit::on_searchLineEdit_returnPressed()
{
    emit sigSearchChanged(ui->searchLineEdit->text());
}
