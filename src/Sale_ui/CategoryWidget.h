#ifndef CATEGORYWIDGET_H
#define CATEGORYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "structData.h"
#include "enumData.h"

namespace Ui {
class CategoryWidget;
}

class CategoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CategoryWidget(QWidget *parent = 0);
    ~CategoryWidget();
    void initCategoryInfoList(QList<CategoryInfo *> categoryInfoList, int nMovePosition );
    void setCategoryWidgetType( CategoryWidgetType eCategoryWidgetType);
    void setUpDownPageButton( QPushButton* pUpPageButton, QPushButton* pDownPageButton );
    void initData(QList<CategoryInfo *> categoryInfoList);
    QString getCurCategory();
public slots:
    void slot_addCategoryInfo(const QList<CategoryInfo *> &categoryInfoList);
    void slot_deleteCategory(QString strCategoryKeyId);

protected:
    void resizeEvent(QResizeEvent *);

private slots:
    void slot_upPage();
    void slot_downPage();

private:
    void initCtrl();
    void initConnect();
    void clearText();
    void setCurPage( int nCurPage, int nTotalPage );
    void generateCategoryList();
    void checkCurPageButtonState();

signals:
    void sig_getGoodsList(QString strCategoryKeyId);
    void sigItemDbClicked(QString sCategoryKeyId);
    void sigDeleteCategory( int nCategoryId );

private:
    Ui::CategoryWidget *ui;

    QList<CategoryInfo*> m_listCategoryInfo;

    CategoryWidgetType m_eCategoryWidgetType;
    int m_nCurPage;
    int m_nTotalPage;
    int m_nOnePageCount;
    QPushButton *m_pUpPageButton;
    QPushButton *m_pDownPageButton;
};

#endif // CATEGORYWIDGET_H
