/********************************************************************************
** Form generated from reading UI file 'StringListWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRINGLISTWIDGET_H
#define UI_STRINGLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "StringListView.h"

QT_BEGIN_NAMESPACE

class Ui_StringListWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *skinWidget;
    QVBoxLayout *verticalLayout_2;
    StringListView *listView;

    void setupUi(QWidget *StringListWidget)
    {
        if (StringListWidget->objectName().isEmpty())
            StringListWidget->setObjectName(QStringLiteral("StringListWidget"));
        StringListWidget->resize(400, 300);
        StringListWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(StringListWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        skinWidget = new QWidget(StringListWidget);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"	\n"
"	border-image: url(:/shareImages/strlistBg.png);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(skinWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 9, 9, 14);
        listView = new StringListView(skinWidget);
        listView->setObjectName(QStringLiteral("listView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy);
        listView->setFocusPolicy(Qt::NoFocus);
        listView->setStyleSheet(QLatin1String("QListView{\n"
"	border:none;\n"
"}"));

        verticalLayout_2->addWidget(listView);


        verticalLayout->addWidget(skinWidget);


        retranslateUi(StringListWidget);

        QMetaObject::connectSlotsByName(StringListWidget);
    } // setupUi

    void retranslateUi(QWidget *StringListWidget)
    {
        StringListWidget->setWindowTitle(QApplication::translate("StringListWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StringListWidget: public Ui_StringListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRINGLISTWIDGET_H
