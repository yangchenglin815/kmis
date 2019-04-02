#ifndef ADDGOODSTOCUSTOMCATEGORYWIDGET_H
#define ADDGOODSTOCUSTOMCATEGORYWIDGET_H

#include <QWidget>
#include "structData.h"

namespace Ui {
class AddGoodsToCustomCategoryWidget;
}

class AddGoodsToCustomCategoryWidget : public QWidget
{
    Q_OBJECT

public:
    ~AddGoodsToCustomCategoryWidget();
    static AddGoodsToCustomCategoryWidget* instance();
    void initData(const QList<CategoryInfo *> &categoryInfoList, const CategoryInfo &categoryInfo);
    void setTitleText(QString title);

private slots:
    void slot_saveGoodsIdList(QList<int> deletedList, QList<int> addedList);
    void slot_close_wnd();

private:
    explicit AddGoodsToCustomCategoryWidget(QWidget *parent = 0);
    void initConnect();

signals:
    void sigSaveGoodsIdList(QString sCategoryKeyId, QList<int> deletedList, QList<int> addedList);
    void sigUpdateCategoryGoods(QString sCategoryKeyId);

private:
    Ui::AddGoodsToCustomCategoryWidget *ui;
    static AddGoodsToCustomCategoryWidget* m_pInstance;
    QString m_sCategoryKeyId;
};

#endif // ADDGOODSTOCUSTOMCATEGORYWIDGET_H
