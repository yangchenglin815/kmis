#include "SearchMemberEdit.h"
#include "ui_SearchMemberEdit.h"
#include "../util/CommonFun.h"
#include <QProcess>
#include <QMessageBox>

SearchMemberEdit::SearchMemberEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchMemberEdit)
    , m_nInputXPos(-1)
    , m_nInputYPos(-1)
    , m_pInputToolWidget(NULL)
{
    ui->setupUi(this);
    m_pInputToolWidget = new InputToolWidget;
    initConnect();
    ui->searchLineEdit->installEventFilter(this);
}

SearchMemberEdit::~SearchMemberEdit()
{
    delete ui;
}

bool SearchMemberEdit::eventFilter(QObject *watched, QEvent *event)
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

void SearchMemberEdit::slot_addWord(QString sWord)
{
    QString sText = ui->searchLineEdit->text();
    ui->searchLineEdit->setText(sText.append(sWord));
}

void SearchMemberEdit::slot_delete()
{
    QString sText = ui->searchLineEdit->text();
    sText.remove(sText.length() - 1, 1);
    ui->searchLineEdit->setText(sText);
}

void SearchMemberEdit::slot_clear()
{
     ui->searchLineEdit->clear();
}

void SearchMemberEdit::slot_cofirm()
{
     hideKeyboard();
     emit sigSearchChanged(ui->searchLineEdit->text());
}

void SearchMemberEdit::initConnect()
{
//    connect(m_pInputToolWidget, SIGNAL(sigClear()), this, SLOT(slot_clear()));
    connect(m_pInputToolWidget, SIGNAL(sigConfirm()), this, SLOT(slot_cofirm()));
//    connect(m_pInputToolWidget, SIGNAL(sigDeleteWord()), this, SLOT(slot_delete()));
//    connect(m_pInputToolWidget, SIGNAL(sigWord(QString)), this, SLOT(slot_addWord(QString)));
}

void SearchMemberEdit::setHintText(QString text)
{
    ui->searchLineEdit->setPlaceholderText(text);
}

QString SearchMemberEdit::getText()
{
    return ui->searchLineEdit->text();
}

void SearchMemberEdit::setText(QString sText)
{
    ui->searchLineEdit->setText(sText);
}

void SearchMemberEdit::clearText()
{
    ui->searchLineEdit->setText("");
}

void SearchMemberEdit::setKeyboardPos(int nXPos, int nYPos)
{
    m_nInputXPos = nXPos;
    m_nInputYPos = nYPos;
}

void SearchMemberEdit::autoSetKeyboardPos(int nOffX, int nOffY)
{
    QPoint globalPoint = this->mapToGlobal(QPoint(0, 0));
    m_nInputXPos = globalPoint.x() + nOffX;
    m_nInputYPos = globalPoint.y() + this->height() + nOffY;
}

void SearchMemberEdit::hideKeyboard()
{
    m_pInputToolWidget->hide();
}

void SearchMemberEdit::setSearchFocus()
{
    ui->searchLineEdit->setFocus();
}

void SearchMemberEdit::on_keyboardButton_clicked()
{
    m_pInputToolWidget->move(m_nInputXPos, m_nInputYPos);
    m_pInputToolWidget->activateWindow();
    m_pInputToolWidget->showNormal();
}
