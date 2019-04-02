/********************************************************************************
** Form generated from reading UI file 'CategoryBigWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATEGORYBIGWIDGET_H
#define UI_CATEGORYBIGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "categorybiglistview.h"

QT_BEGIN_NAMESPACE

class Ui_CategoryBigWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    CategoryBigListView *listView;
    QHBoxLayout *horizontalLayout;
    QPushButton *lastPageButton;
    QWidget *widget;
    QPushButton *nextPageButton;

    void setupUi(QWidget *CategoryBigWidget)
    {
        if (CategoryBigWidget->objectName().isEmpty())
            CategoryBigWidget->setObjectName(QStringLiteral("CategoryBigWidget"));
        CategoryBigWidget->resize(605, 69);
        horizontalLayout_2 = new QHBoxLayout(CategoryBigWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        listView = new CategoryBigListView(CategoryBigWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setMinimumSize(QSize(0, 0));
        listView->setMaximumSize(QSize(16777215, 16777215));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"border:none;\n"
"background-color: rgb(81, 80, 80);\n"
"}"));

        horizontalLayout_2->addWidget(listView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lastPageButton = new QPushButton(CategoryBigWidget);
        lastPageButton->setObjectName(QStringLiteral("lastPageButton"));
        lastPageButton->setMinimumSize(QSize(15, 18));
        lastPageButton->setMaximumSize(QSize(15, 18));
        lastPageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/setImage/left.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/setImage/left_press.png);\n"
"}\n"
""));

        horizontalLayout->addWidget(lastPageButton);

        widget = new QWidget(CategoryBigWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(1, 18));
        widget->setMaximumSize(QSize(1, 18));
        widget->setStyleSheet(QLatin1String("border: 1px solid #383838;\n"
""));

        horizontalLayout->addWidget(widget);

        nextPageButton = new QPushButton(CategoryBigWidget);
        nextPageButton->setObjectName(QStringLiteral("nextPageButton"));
        nextPageButton->setMinimumSize(QSize(15, 18));
        nextPageButton->setMaximumSize(QSize(15, 18));
        nextPageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/setImage/right.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/setImage/right_press.png);\n"
"}\n"
""));

        horizontalLayout->addWidget(nextPageButton);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(CategoryBigWidget);

        QMetaObject::connectSlotsByName(CategoryBigWidget);
    } // setupUi

    void retranslateUi(QWidget *CategoryBigWidget)
    {
        CategoryBigWidget->setWindowTitle(QApplication::translate("CategoryBigWidget", "Form", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CategoryBigWidget: public Ui_CategoryBigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATEGORYBIGWIDGET_H
