#include "StringListWidget.h"
#include "ui_StringListWidget.h"

StringListWidget::StringListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StringListWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    initConnect();
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool/*| Qt::WindowStaysOnTopHint*/);
}

StringListWidget::~StringListWidget()
{
    delete ui;
}

void StringListWidget::initData(QList<QString> strList, int nItemHeight, int nWidth)
{
    ui->listView->setItemHeight(nItemHeight);
    this->setFixedWidth(nWidth);
    int nLen = strList.length();
    StrInfo strInfo;
    if (nLen == 0)
    {
       strInfo.sText = "";
       strInfo.bDrawLine = false;
       ui->listView->appendItem(strInfo);
    }
    else
    {
        for (int i = 0; i < nLen; i++)
        {
            strInfo.sText = strList[i];
            if (i != (nLen - 1))
            {
                strInfo.bDrawLine = true;
            }
            else
            {
                strInfo.bDrawLine = false;
            }
            ui->listView->appendItem(strInfo);
        }
    }

    this->setFixedHeight(ui->listView->height()+25);
}

void StringListWidget::setFontSize(int nFontSize)
{
    ui->listView->setFontSize(nFontSize);
}

void StringListWidget::initConnect()
{
    connect(ui->listView, SIGNAL(sigClicked(QString)), this, SIGNAL(sigClicked(QString)));
}
