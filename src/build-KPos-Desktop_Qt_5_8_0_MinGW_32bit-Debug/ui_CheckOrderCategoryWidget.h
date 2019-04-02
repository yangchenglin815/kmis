/********************************************************************************
** Form generated from reading UI file 'CheckOrderCategoryWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKORDERCATEGORYWIDGET_H
#define UI_CHECKORDERCATEGORYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CheckOrderCategoryListView.h"
#include "SearchEdit.h"

QT_BEGIN_NAMESPACE

class Ui_CheckOrderCategoryWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *startDateEdit;
    QWidget *widget_2;
    QLineEdit *endDateEdit;
    QSpacerItem *horizontalSpacer;
    SearchEdit *searchWidget;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    CheckOrderCategoryListView *listView;
    QPushButton *nextPageButton;

    void setupUi(QWidget *CheckOrderCategoryWidget)
    {
        if (CheckOrderCategoryWidget->objectName().isEmpty())
            CheckOrderCategoryWidget->setObjectName(QStringLiteral("CheckOrderCategoryWidget"));
        CheckOrderCategoryWidget->resize(764, 92);
        verticalLayout = new QVBoxLayout(CheckOrderCategoryWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(CheckOrderCategoryWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(16777215, 16777215));
        widget->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QLatin1String("font-size:14px;\n"
"color:#999999;"));

        horizontalLayout_2->addWidget(label);

        startDateEdit = new QLineEdit(widget);
        startDateEdit->setObjectName(QStringLiteral("startDateEdit"));
        startDateEdit->setMinimumSize(QSize(88, 0));
        startDateEdit->setMaximumSize(QSize(88, 16777215));
        startDateEdit->setStyleSheet(QLatin1String("font-size:12px;\n"
"color:#999999;"));
        startDateEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(startDateEdit);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(16, 1));
        widget_2->setMaximumSize(QSize(16, 1));
        widget_2->setStyleSheet(QStringLiteral("border: 1px solid #6c6c6c;"));

        horizontalLayout_2->addWidget(widget_2);

        endDateEdit = new QLineEdit(widget);
        endDateEdit->setObjectName(QStringLiteral("endDateEdit"));
        endDateEdit->setMinimumSize(QSize(88, 0));
        endDateEdit->setMaximumSize(QSize(88, 16777215));
        endDateEdit->setStyleSheet(QLatin1String("font-size:12px;\n"
"color:#999999;"));
        endDateEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(endDateEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        searchWidget = new SearchEdit(widget);
        searchWidget->setObjectName(QStringLiteral("searchWidget"));
        searchWidget->setMinimumSize(QSize(262, 32));
        searchWidget->setMaximumSize(QSize(262, 32));

        horizontalLayout_2->addWidget(searchWidget);


        verticalLayout->addWidget(widget);

        widget_3 = new QWidget(CheckOrderCategoryWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 42));
        widget_3->setMaximumSize(QSize(16777215, 42));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("font-size:14px;\n"
"color:#999999;"));

        horizontalLayout->addWidget(label_2);

        listView = new CheckOrderCategoryListView(widget_3);
        listView->setObjectName(QStringLiteral("listView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy1);
        listView->setStyleSheet(QLatin1String("QListView{\n"
"border:none;\n"
"background-color:transparent;\n"
"}\n"
""));

        horizontalLayout->addWidget(listView);

        nextPageButton = new QPushButton(widget_3);
        nextPageButton->setObjectName(QStringLiteral("nextPageButton"));
        nextPageButton->setMinimumSize(QSize(15, 18));
        nextPageButton->setMaximumSize(QSize(15, 18));
        nextPageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/setImage/right.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/setImage/right_press.png);\n"
"}"));

        horizontalLayout->addWidget(nextPageButton);


        verticalLayout->addWidget(widget_3);


        retranslateUi(CheckOrderCategoryWidget);

        QMetaObject::connectSlotsByName(CheckOrderCategoryWidget);
    } // setupUi

    void retranslateUi(QWidget *CheckOrderCategoryWidget)
    {
        CheckOrderCategoryWidget->setWindowTitle(QApplication::translate("CheckOrderCategoryWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("CheckOrderCategoryWidget", "\346\227\245\346\234\237\347\255\233\351\200\211\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("CheckOrderCategoryWidget", "\347\261\273\345\210\253\357\274\232", Q_NULLPTR));
        nextPageButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CheckOrderCategoryWidget: public Ui_CheckOrderCategoryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKORDERCATEGORYWIDGET_H
