/********************************************************************************
** Form generated from reading UI file 'AddCustomCategoryDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCUSTOMCATEGORYDLG_H
#define UI_ADDCUSTOMCATEGORYDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>

QT_BEGIN_NAMESPACE

class Ui_AddCustomCategoryDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *skinWidget;
    QWidget *mainWidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *positionLineEdit;
    QPushButton *confirmButton;
    QLabel *hintLabel;
    QLineEdit *nameLineEdit;

    void setupUi(QDialog *AddCustomCategoryDlg)
    {
        if (AddCustomCategoryDlg->objectName().isEmpty())
            AddCustomCategoryDlg->setObjectName(QStringLiteral("AddCustomCategoryDlg"));
        AddCustomCategoryDlg->resize(400, 274);
        verticalLayout = new QVBoxLayout(AddCustomCategoryDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(AddCustomCategoryDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 46));
        titleWidget->setMaximumSize(QSize(16777215, 46));

        verticalLayout->addWidget(titleWidget);

        skinWidget = new QWidget(AddCustomCategoryDlg);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"background-color: #505050;\n"
"}"));
        mainWidget = new QWidget(skinWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setGeometry(QRect(40, 24, 320, 180));
        mainWidget->setMinimumSize(QSize(320, 180));
        mainWidget->setMaximumSize(QSize(320, 180));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        label = new QLabel(mainWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 20, 76, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(mainWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 70, 76, 30));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        positionLineEdit = new QLineEdit(mainWidget);
        positionLineEdit->setObjectName(QStringLiteral("positionLineEdit"));
        positionLineEdit->setGeometry(QRect(90, 70, 210, 30));
        positionLineEdit->setFont(font);
        positionLineEdit->setMaxLength(4);
        confirmButton = new QPushButton(mainWidget);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(18, 120, 284, 44));
        QFont font1;
        confirmButton->setFont(font1);
        confirmButton->setStyleSheet(QLatin1String("QPushButton{\n"
"color:#ffffff;\n"
"font-size:16px;\n"
"border-image: url(:/loginImage/commonButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/loginImage/commonButtonPressed.png);\n"
"}"));
        hintLabel = new QLabel(mainWidget);
        hintLabel->setObjectName(QStringLiteral("hintLabel"));
        hintLabel->setGeometry(QRect(93, 50, 201, 20));
        nameLineEdit = new QLineEdit(mainWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(90, 19, 210, 30));
        nameLineEdit->setFont(font);
        nameLineEdit->setMaxLength(8);

        verticalLayout->addWidget(skinWidget);


        retranslateUi(AddCustomCategoryDlg);

        QMetaObject::connectSlotsByName(AddCustomCategoryDlg);
    } // setupUi

    void retranslateUi(QDialog *AddCustomCategoryDlg)
    {
        AddCustomCategoryDlg->setWindowTitle(QApplication::translate("AddCustomCategoryDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("AddCustomCategoryDlg", "\345\210\206\347\261\273\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddCustomCategoryDlg", "\344\275\215\347\275\256\357\274\232", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("AddCustomCategoryDlg", "\347\241\256\350\256\244", Q_NULLPTR));
        hintLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddCustomCategoryDlg: public Ui_AddCustomCategoryDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCUSTOMCATEGORYDLG_H
