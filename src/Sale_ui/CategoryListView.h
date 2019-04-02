#ifndef CATEGORYLISTVIEW_H
#define CATEGORYLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "structData.h"
#include <QMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QPushButton>

class CategoryDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    CategoryDelegate(QWidget* parent = NULL);
    ~CategoryDelegate();
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
    void setSetPageFlag(bool bSetPage);

protected:
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option, CategoryInfo &stCategory) const;
    void init();

signals:
    void sigItemClicked(QString strCategoryKeyId);
    void sigItemDbClicked(QString sCategoryKeyId);
    void sigDeleteCategory(QString sCategoryKeyId);

private:
    QPushButton* m_pButton;
    int m_nPicLen;
    bool m_bSetPage;
};

class CategoryListView : public QListView
{
    Q_OBJECT
public:
    explicit CategoryListView(QWidget *parent = 0);
    ~CategoryListView();
    void appendItem(const CategoryInfo& stCategoryInfo);
    void clearItems();
    void setSelectedKeyId(QString strCurCategoryKeyId);
    bool isSelectedEmptyKeyId();
    QString getSelectedKeyId();
    void setSetPageFlag(bool bSetPage);
    void setStartPosition(int nStartPosition);
    void setWidth(int width);
    void setHeight(int height);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

private slots:
    void slot_itemClicked(QString strCategoryKeyId);
    void slot_itemDbClicked(QString strCategoryKeyId);
    void slot_deleteCategory(QString strCategoryKeyId);
    void slot_checkClickType();

private:
    void init();
    void initConnect();
    void showAdjustWidget();

signals:
    void sigItemClicked(QString strCategoryKeyId);
    void sigItemDbClicked(QString sCategoryKeyId);
    void sigDeleteCategory(QString sCategoryKeyId);

private:
    QStandardItemModel* m_pStandardItemModel;
    CategoryDelegate* m_pCategoryDelegate;
    QMap<QString, QStandardItem*> m_ItemKeyIdMap;//key：分类id
    int m_nItemHeight;
    int m_nItemWidth;
    QString m_sSelectedKeyId; // 选中的分类主键
    int m_nSelectedPos; // 选中的位置
    int m_nStartPosition;
    bool m_bSetPage; // 是否是分类的设置界面
    QTimer m_timer;
    bool m_bDbClick;
};

#endif // CATEGORYLISTVIEW_H
