#include "ReceiveOrdersTopWidget.h"
#include "ui_ReceiveOrdersTopWidget.h"
#include <QDebug>

ReceiveOrdersTopWidget::ReceiveOrdersTopWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReceiveOrdersTopWidget)
    , m_pReceiveProviderWidget(NULL)
    , m_pStringListWidget(NULL)
    , m_sProviderSearchText("")
    , m_sReceiptTypeSearchText("")
    , m_sDateStartSearchText("")
    , m_sDateEndSearchText("")
{
    ui->setupUi(this);
    initConnect();
}

ReceiveOrdersTopWidget::~ReceiveOrdersTopWidget()
{
    if (m_pReceiveProviderWidget != NULL)
    {
        m_pReceiveProviderWidget->deleteLater();
    }
    if (m_pStringListWidget != NULL)
    {
        m_pStringListWidget->deleteLater();
    }
    delete ui;
}

void ReceiveOrdersTopWidget::slot_clickProvider()
{
    if (m_pReceiveProviderWidget == NULL)
    {
        m_pReceiveProviderWidget = new ReceiveProviderWidget;
        qRegisterMetaType<ReceiveProviderInfo>("ReceiveProviderInfo");
        connect(m_pReceiveProviderWidget, SIGNAL(sigClickProvider(ReceiveProviderInfo)), this, SLOT(slot_clickProviderText(ReceiveProviderInfo)));
    }
    if(m_pReceiveProviderWidget->isVisible())
    {
        m_pReceiveProviderWidget->hide();
    }
    else
    {
        m_pReceiveProviderWidget->test();
        QPoint globalPoint = ui->providerComboBox->mapToGlobal(QPoint(0, 0));
        int nXPos = globalPoint.x();
        int nOffY = 5;
        int nYPos = globalPoint.y() + ui->providerComboBox->height() + nOffY;
        m_pReceiveProviderWidget->move(QPoint(nXPos, nYPos));
        m_pReceiveProviderWidget->activateWindow();
        m_pReceiveProviderWidget->showNormal();
    }
}

void ReceiveOrdersTopWidget::slot_clickReceiptType()
{
    if (m_pStringListWidget == NULL)
    {
        m_pStringListWidget = new StringListWidget;
        connect(m_pStringListWidget, SIGNAL(sigClicked(QString))
                , this, SLOT(slot_clickedReceiptTypeText(QString)));
        QStringList strList;
        strList.append(QStringLiteral("全部"));
        strList.append(QStringLiteral("订单"));
        strList.append(QStringLiteral("手工"));
        strList.append(QStringLiteral("返配"));
        strList.append(QStringLiteral("调拨"));
        const int c_nItemHeight = 38;
        m_pStringListWidget->initData(strList, c_nItemHeight, ui->receiptTypeComboBox->width());
        const int c_nFontSize = 14;
        m_pStringListWidget->setFontSize(c_nFontSize);
    }
    if (m_pStringListWidget->isVisible())
    {
        m_pStringListWidget->hide();
    }
    else
    {
        QPoint globalPoint = ui->receiptTypeComboBox->mapToGlobal(QPoint(0, 0));
        int nXPos = globalPoint.x();
        int nOffY = 5;
        int nYPos = globalPoint.y() + ui->receiptTypeComboBox->height() + nOffY;
        m_pStringListWidget->move(QPoint(nXPos, nYPos));
        m_pStringListWidget->activateWindow();
        m_pStringListWidget->showNormal();
    }
}

void ReceiveOrdersTopWidget::slot_clickProviderText(ReceiveProviderInfo receiveProviderInfo)
{
    if (m_pReceiveProviderWidget != NULL)
    {
        m_pReceiveProviderWidget->hide();
    }
    ui->providerComboBox->setContent(receiveProviderInfo.sName);
    m_sProviderSearchText = receiveProviderInfo.sName;
    if (m_sProviderSearchText == QStringLiteral("全部"))
    {
        m_sProviderSearchText = "";
    }

    emit sigSearch(m_sProviderSearchText, m_sReceiptTypeSearchText, m_sDateStartSearchText, m_sDateEndSearchText);
    qDebug()<< "m_sProviderSearchText -- "<<m_sProviderSearchText<<",m_sReceiptTypeSearchText -- "<<m_sReceiptTypeSearchText;
}

void ReceiveOrdersTopWidget::slot_clickedReceiptTypeText(QString text)
{
    if (m_pStringListWidget != NULL)
    {
        m_pStringListWidget->hide();
    }
    ui->receiptTypeComboBox->setContent(text);
    m_sReceiptTypeSearchText = text;
    if (m_sReceiptTypeSearchText == QStringLiteral("全部"))
    {
        m_sReceiptTypeSearchText = "";
    }

    emit sigSearch(m_sProviderSearchText, m_sReceiptTypeSearchText, m_sDateStartSearchText, m_sDateEndSearchText);
    qDebug()<< "m_sProviderSearchText -- "<<m_sProviderSearchText<<",m_sReceiptTypeSearchText -- "<<m_sReceiptTypeSearchText;
}

void ReceiveOrdersTopWidget::initConnect()
{
    connect(ui->providerComboBox, SIGNAL(sigClicked()), this, SLOT(slot_clickProvider()));
    connect(ui->receiptTypeComboBox, SIGNAL(sigClicked()), this, SLOT(slot_clickReceiptType()));
}
