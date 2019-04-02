#include "AddGoodsToCustomCategoryWidget.h"
#include "ui_AddGoodsToCustomCategoryWidget.h"
#include <QDebug>

AddGoodsToCustomCategoryWidget* AddGoodsToCustomCategoryWidget::m_pInstance = NULL;

AddGoodsToCustomCategoryWidget::AddGoodsToCustomCategoryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddGoodsToCustomCategoryWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
    initConnect();
}

AddGoodsToCustomCategoryWidget::~AddGoodsToCustomCategoryWidget()
{
    delete ui;
}

AddGoodsToCustomCategoryWidget *AddGoodsToCustomCategoryWidget::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new AddGoodsToCustomCategoryWidget;
    }
    return m_pInstance;
}

void AddGoodsToCustomCategoryWidget::initData(const QList<CategoryInfo*> &categoryInfoList, const CategoryInfo &categoryInfo)
{
    m_sCategoryKeyId = categoryInfo.sKeyId;
    qDebug()<<"m_sCategoryKeyId--"<<m_sCategoryKeyId;
    ui->categoryWidget->initData(categoryInfoList, categoryInfo);
}

void AddGoodsToCustomCategoryWidget::setTitleText(QString title)
{
    ui->titleWidget->setTitleText(title);
}

void AddGoodsToCustomCategoryWidget::slot_saveGoodsIdList(QList<int> deletedList, QList<int> addedList)
{
    emit sigSaveGoodsIdList(m_sCategoryKeyId, deletedList, addedList);
}

void AddGoodsToCustomCategoryWidget::slot_close_wnd()
{
    this->hide();
    emit sigUpdateCategoryGoods(m_sCategoryKeyId);
}

void AddGoodsToCustomCategoryWidget::initConnect()
{
    connect(ui->categoryWidget, SIGNAL(sigChooseCategory(CategoryChooseInfo)),
            ui->goodsWidget, SLOT(slot_chooseCategory(CategoryChooseInfo)));
    connect(ui->goodsWidget, SIGNAL(sigSaveGoodsIdList(QList<int>, QList<int>)),
            this, SLOT(slot_saveGoodsIdList(QList<int>, QList<int>)));
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(slot_close_wnd()));
}
