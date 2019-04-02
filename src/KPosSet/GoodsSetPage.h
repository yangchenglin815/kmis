#ifndef GOODSSETPAGE_H
#define GOODSSETPAGE_H

#include <QWidget>
#include "../data/structData.h"
#include "AddCustomCategoryDlg.h"
#include "../Bussiness/KPosSetCtrl.h"

namespace Ui {
class GoodsSetPage;
}

class GoodsSetPage : public QWidget
{
    Q_OBJECT

public:
    explicit GoodsSetPage(QWidget *parent = 0);
    ~GoodsSetPage();
    void setCategoryInfoList( const QList<CategoryInfo *> &categoryInfoList );
    void setKPosSetCtrl(KPosSetCtrl *pKPosSetCtrl);
    void uploadData(KPosSet &stKPosSet );

private slots:
    void slot_getGoodsList(QString sCategoryKeyId);
    void slot_movePosition(int nNewPosition, int nOldPosition, int nOwnerType);
    void slot_categoryDbClicked(QString sCategoryKeyId);
    void slot_saveGoodsIdList(QString sCategoryKeyId, QList<int> deletedList, QList<int> addedList);
    void slot_addCategory(QString sCategoryName, int nPos);
    void slot_deleteCategory(int nCategoryId );
    void on_newCategoryButton_clicked();
    void slot_onAddCustomCategory(int nCode, QString sMsg, int nCategoryId);

private:
    void initConnect();
    void getGoodsList(QList<GoodsInfo>& goodsInfoList, QString sCategoryKeyId);

private:
    Ui::GoodsSetPage *ui;
    int m_nCategoryOnePageCount;
    int m_nGoodsOnePageCount;
    QList<CategoryInfo*> m_categoryInfoList;
    QString m_sSelectedCategoryKeyId;
    AddCustomCategoryDlg* m_pAddCustomCategoryDlg;
    KPosSetCtrl* m_pKPosSetCtrl;
    GoodSet m_curGoodSet;
};

#endif // GOODSSETPAGE_H
