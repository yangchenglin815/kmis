/********************************************************************************
** Form generated from reading UI file 'AddCategoryDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCATEGORYDLG_H
#define UI_ADDCATEGORYDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>
#include "InputToolWidget.h"

QT_BEGIN_NAMESPACE

class Ui_AddCategoryDlg
{
public:
    QGridLayout *gridLayout_4;
    TitleBarWidget *widget;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_5;
    QLabel *categoryNameLabel;
    QLabel *positionLabel;
    QLineEdit *categoryNameEdit;
    QLineEdit *positionEdit;
    QPushButton *sureButton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    InputToolWidget *widget_6;

    void setupUi(QDialog *AddCategoryDlg)
    {
        if (AddCategoryDlg->objectName().isEmpty())
            AddCategoryDlg->setObjectName(QStringLiteral("AddCategoryDlg"));
        AddCategoryDlg->resize(998, 660);
        gridLayout_4 = new QGridLayout(AddCategoryDlg);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        widget = new TitleBarWidget(AddCategoryDlg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 60));
        widget->setMaximumSize(QSize(16777215, 60));

        gridLayout_4->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(AddCategoryDlg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QLatin1String("QWidget#widget_2 {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 30, 0, 30);
        horizontalSpacer = new QSpacerItem(245, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(412, 230));
        widget_5->setMaximumSize(QSize(412, 230));
        widget_5->setStyleSheet(QLatin1String("QWidget#widget_5 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        categoryNameLabel = new QLabel(widget_5);
        categoryNameLabel->setObjectName(QStringLiteral("categoryNameLabel"));
        categoryNameLabel->setGeometry(QRect(26, 25, 80, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        categoryNameLabel->setFont(font);
        categoryNameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        positionLabel = new QLabel(widget_5);
        positionLabel->setObjectName(QStringLiteral("positionLabel"));
        positionLabel->setGeometry(QRect(26, 85, 80, 40));
        positionLabel->setFont(font);
        positionLabel->setStyleSheet(QStringLiteral(""));
        positionLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        categoryNameEdit = new QLineEdit(widget_5);
        categoryNameEdit->setObjectName(QStringLiteral("categoryNameEdit"));
        categoryNameEdit->setGeometry(QRect(124, 25, 270, 40));
        categoryNameEdit->setFont(font);
        categoryNameEdit->setStyleSheet(QStringLiteral("padding-left:10px;"));
        positionEdit = new QLineEdit(widget_5);
        positionEdit->setObjectName(QStringLiteral("positionEdit"));
        positionEdit->setGeometry(QRect(124, 85, 270, 40));
        positionEdit->setFont(font);
        positionEdit->setStyleSheet(QStringLiteral("padding-left:10px;"));
        sureButton = new QPushButton(widget_5);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        sureButton->setGeometry(QRect(20, 157, 363, 64));
        sureButton->setFont(font);
        sureButton->setFocusPolicy(Qt::NoFocus);
        sureButton->setStyleSheet(QLatin1String("QPushButton#sureButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#sureButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}"));

        gridLayout->addWidget(widget_5, 0, 1, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(308, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        gridLayout_3->addWidget(widget_3, 0, 0, 1, 1);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(36, 0, 32, 20);
        widget_6 = new InputToolWidget(widget_4);
        widget_6->setObjectName(QStringLiteral("widget_6"));

        gridLayout_2->addWidget(widget_6, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget_4, 1, 0, 1, 1);


        gridLayout_4->addWidget(widget_2, 1, 0, 1, 1);


        retranslateUi(AddCategoryDlg);

        QMetaObject::connectSlotsByName(AddCategoryDlg);
    } // setupUi

    void retranslateUi(QDialog *AddCategoryDlg)
    {
        AddCategoryDlg->setWindowTitle(QApplication::translate("AddCategoryDlg", "AddCategoryDlg", Q_NULLPTR));
        categoryNameLabel->setText(QApplication::translate("AddCategoryDlg", "\345\210\206\347\261\273\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        positionLabel->setText(QApplication::translate("AddCategoryDlg", "\344\275\215\347\275\256\357\274\232", Q_NULLPTR));
        sureButton->setText(QApplication::translate("AddCategoryDlg", "\347\241\256\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddCategoryDlg: public Ui_AddCategoryDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCATEGORYDLG_H
