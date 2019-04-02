#include "RefundKeySortDlg.h"
#include "ui_RefundKeySortDlg.h"
#include "../data/enumData.h"
#include "../util/EnumToString.h"
#include <QDebug>

RefundKeySortDlg::RefundKeySortDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RefundKeySortDlg)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint/*|Qt::WindowStaysOnTopHint|Qt::Popup*/|Qt::Tool);
    init();
}

RefundKeySortDlg::~RefundKeySortDlg()
{
    delete ui;
}

void RefundKeySortDlg::reInit()
{
    m_keyIDList.clear();
    m_sortKeyIDList.clear();
    m_pushButtonList.clear();
    init();
}

void RefundKeySortDlg::on_key1Button_clicked()
{
    buttonClick(0);
}

void RefundKeySortDlg::on_key2Button_clicked()
{
    buttonClick(1);
}

void RefundKeySortDlg::on_key3Button_clicked()
{
    buttonClick(2);
}

void RefundKeySortDlg::init()
{
    m_pushButtonList.append(ui->key1Button);
    m_pushButtonList.append(ui->key2Button);
    m_pushButtonList.append(ui->key3Button);

    int nLen = m_pushButtonList.length();
    int nStart = e_refundGoods;
    int nEnd = e_refundGoods + nLen;
    for (int i = nStart; i < nEnd; i++)
    {
        m_keyIDList.append(i);
        m_pushButtonList[i-nStart]->setText(EnumToString::keySetTypeToString(i));
        m_pushButtonList[i-nStart]->show();
    }
}

void RefundKeySortDlg::initUI()
{
    int nLen = m_pushButtonList.length();
    if (nLen != m_keyIDList.length())
    {
        return;
    }

    for (int i = 0; i < nLen; i++)
    {
        m_pushButtonList[i]->setText(EnumToString::keySetTypeToString((m_keyIDList[i])));
    }
}

void RefundKeySortDlg::buttonClick(int nPos)
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
