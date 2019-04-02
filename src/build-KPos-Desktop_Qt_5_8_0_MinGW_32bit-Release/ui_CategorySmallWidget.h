/********************************************************************************
** Form generated from reading UI file 'CategorySmallWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATEGORYSMALLWIDGET_H
#define UI_CATEGORYSMALLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "categorysmalllistview.h"

QT_BEGIN_NAMESPACE

class Ui_CategorySmallWidget
{
public:
    QVBoxLayout *verticalLayout;
    CategorySmallListView *listView;
    QPushButton *lastPageButton;
    QPushButton *nextPageButton;

    void setupUi(QWidget *CategorySmallWidget)
    {
        if (CategorySmallWidget->objectName().isEmpty())
            CategorySmallWidget->setObjectName(QStringLiteral("CategorySmallWidget"));
        CategorySmallWidget->resize(102, 474);
        verticalLayout = new QVBoxLayout(CategorySmallWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listView = new CategorySmallListView(CategorySmallWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"border:none;\n"
"background-color: rgb(81, 80, 80);\n"
"}"));

        verticalLayout->addWidget(listView);

        lastPageButton = new QPushButton(CategorySmallWidget);
        lastPageButton->setObjectName(QStringLiteral("lastPageButton"));
        lastPageButton->setMinimumSize(QSize(0, 36));
        lastPageButton->setMaximumSize(QSize(16777215, 36));
        lastPageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/orderGoodsImage/changePageUp.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/orderGoodsImage/changePageUp_press.png);\n"
"}"));

        verticalLayout->addWidget(lastPageButton);

        nextPageButton = new QPushButton(CategorySmallWidget);
        nextPageButton->setObjectName(QStringLiteral("nextPageButton"));
        nextPageButton->setMinimumSize(QSize(0, 36));
        nextPageButton->setMaximumSize(QSize(16777215, 36));
        nextPageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/orderGoodsImage/changePage.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/orderGoodsImage/changePage_press.png);\n"
"}"));

        verticalLayout->addWidget(nextPageButton);


        retranslateUi(CategorySmallWidget);

        QMetaObject::connectSlotsByName(CategorySmallWidget);
    } // setupUi

    void retranslateUi(QWidget *CategorySmallWidget)
    {
        CategorySmallWidget->setWindowTitle(QApplication::translate("CategorySmallWidget", "Form", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CategorySmallWidget: public Ui_CategorySmallWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATEGORYSMALLWIDGET_H
