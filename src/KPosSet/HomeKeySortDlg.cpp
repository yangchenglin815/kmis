#include "HomeKeySortDlg.h"
#include "ui_HomeKeySortDlg.h"
#include "../data/enumData.h"
#include "../util/EnumToString.h"
#include <QDebug>

HomeKeySortDlg::HomeKeySortDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomeKeySortDlg)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint/*|Qt::WindowStaysOnTopHint|Qt::Popup*/|Qt::Tool);
    init();
}

HomeKeySortDlg::~HomeKeySortDlg()
{
    delete ui;
}

void HomeKeySortDlg::reInit()
{
    m_keyIDList.clear();
    m_sortKeyIDList.clear();
    m_pushButtonList.clear();
    init();
}


void HomeKeySortDlg::on_key1Button_clicked()
{
    buttonClick(0);
}

void HomeKeySortDlg::on_key2Button_clicked()
{
    buttonClick(1);
}

void HomeKeySortDlg::on_key3Button_clicked()
{
    buttonClick(2);
}

void HomeKeySortDlg::on_key4Button_clicked()
{
    buttonClick(3);
}

void HomeKeySortDlg::on_key5Button_clicked()
{
    buttonClick(4);
}

void HomeKeySortDlg::on_key6Button_clicked()
{
    buttonClick(5);
}

void HomeKeySortDlg::on_key7Button_clicked()
{
    buttonClick(6);
}

void HomeKeySortDlg::on_key8Button_clicked()
{
    buttonClick(7);
}

void HomeKeySortDlg::on_key9Button_clicked()
{
    buttonClick(8);
}

void HomeKeySortDlg::on_key10Button_clicked()
{
    buttonClick(9);
}

void HomeKeySortDlg::on_key11Button_clicked()
{
    buttonClick(10);
}

void HomeKeySortDlg::on_key12Button_clicked()
{
    buttonClick(11);
}

void HomeKeySortDlg::on_key13Button_clicked()
{
    buttonClick(12);
}

void HomeKeySortDlg::init()
{
    m_pushButtonList.append(ui->key1Button);
    m_pushButtonList.append(ui->key2Button);
    m_pushButtonList.append(ui->key3Button);
    m_pushButtonList.append(ui->key4Button);
    m_pushButtonList.append(ui->key5Button);
    m_pushButtonList.append(ui->key6Button);
    m_pushButtonList.append(ui->key7Button);
    m_pushButtonList.append(ui->key8Button);
    m_pushButtonList.append(ui->key9Button);
    m_pushButtonList.append(ui->key10Button);
    m_pushButtonList.append(ui->key11Button);
    m_pushButtonList.append(ui->key12Button);
    m_pushButtonList.append(ui->key13Button);

    int nLen = m_pushButtonList.length();
    int nStart = e_homeMember;
    int nEnd = e_homeMember + nLen;
    for (int i = nStart; i < nEnd; i++)
    {
        m_keyIDList.append(i);
        m_pushButtonList[i-nStart]->setText(EnumToString::keySetTypeToString(i));
        m_pushButtonList[i-nStart]->show();
    }
}

void HomeKeySortDlg::initUI()
{
    int nLen = m_pushButtonList.length();
    if (nLen != m_keyIDList.length())
    {
        return;
    }

    for (int i = 0; i < nLen; i++)
    {
        m_pushButtonList[i]->setText(EnumToString::keySetTypeToString(m_keyIDList[i]));
    }
}

void HomeKeySortDlg::buttonClick(int nPos)
{
    int nLen = m_keyIDList.length();
    m_sortKeyIDList.append(m_keyIDList[nPos]);
    m_keyIDList.removeAt(nPos);
    m_pushButtonList[nLen - 1]->hide();
    m_pushButtonList.removeAt(nLen - 1);
    initUI();
    int nSortKeyLen = m_sortKeyIDList.length();
    emit sigClickKeyId(m_sortKeyIDList[nSortKeyLen - 1], nSortKeyLen - 1);//
    if (m_keyIDList.length() == 0)
    {
        emit sigFinished(m_sortKeyIDList);
    }
}


