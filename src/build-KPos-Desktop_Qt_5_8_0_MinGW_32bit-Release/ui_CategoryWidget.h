/********************************************************************************
** Form generated from reading UI file 'CategoryWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATEGORYWIDGET_H
#define UI_CATEGORYWIDGET_H

#include <CategoryListView.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CategoryWidget
{
public:
    QGridLayout *gridLayout;
    CategoryListView *categoryListView;

    void setupUi(QWidget *CategoryWidget)
    {
        if (CategoryWidget->objectName().isEmpty())
            CategoryWidget->setObjectName(QStringLiteral("CategoryWidget"));
        CategoryWidget->resize(418, 107);
        gridLayout = new QGridLayout(CategoryWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        categoryListView = new CategoryListView(CategoryWidget);
        categoryListView->setObjectName(QStringLiteral("categoryListView"));
        categoryListView->setMinimumSize(QSize(418, 108));
        categoryListView->setFocusPolicy(Qt::NoFocus);
        categoryListView->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);/*\350\203\214\346\231\257\351\200\217\346\230\216*/\n"
"border:0px;"));

        gridLayout->addWidget(categoryListView, 0, 0, 1, 1);


        retranslateUi(CategoryWidget);

        QMetaObject::connectSlotsByName(CategoryWidget);
    } // setupUi

    void retranslateUi(QWidget *CategoryWidget)
    {
        CategoryWidget->setWindowTitle(QApplication::translate("CategoryWidget", "CategoryWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CategoryWidget: public Ui_CategoryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATEGORYWIDGET_H
