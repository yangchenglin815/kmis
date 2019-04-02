/********************************************************************************
** Form generated from reading UI file 'SearchMemberEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHMEMBEREDIT_H
#define UI_SEARCHMEMBEREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchMemberEdit
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *searchSkinWidget;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *searchLineEdit;
    QPushButton *keyboardButton;

    void setupUi(QWidget *SearchMemberEdit)
    {
        if (SearchMemberEdit->objectName().isEmpty())
            SearchMemberEdit->setObjectName(QStringLiteral("SearchMemberEdit"));
        SearchMemberEdit->resize(283, 30);
        horizontalLayout = new QHBoxLayout(SearchMemberEdit);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        searchSkinWidget = new QWidget(SearchMemberEdit);
        searchSkinWidget->setObjectName(QStringLiteral("searchSkinWidget"));
        searchSkinWidget->setMinimumSize(QSize(197, 30));
        searchSkinWidget->setMaximumSize(QSize(16777215, 16777215));
        searchSkinWidget->setStyleSheet(QLatin1String("QWidget#searchSkinWidget{ \n"
"	background-color:#ffffff;\n"
"	border-radius: 3px;\n"
"}"));
        horizontalLayout_6 = new QHBoxLayout(searchSkinWidget);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(1, 0, 9, 0);
        searchLineEdit = new QLineEdit(searchSkinWidget);
        searchLineEdit->setObjectName(QStringLiteral("searchLineEdit"));
        searchLineEdit->setMinimumSize(QSize(0, 28));
        searchLineEdit->setMaximumSize(QSize(16777215, 16777215));
        searchLineEdit->setStyleSheet(QLatin1String("QLineEdit#searchLineEdit{\n"
"	border:none;\n"
"	padding-left:10px;\n"
"	border-image:url();\n"
"}"));

        horizontalLayout_6->addWidget(searchLineEdit);

        keyboardButton = new QPushButton(searchSkinWidget);
        keyboardButton->setObjectName(QStringLiteral("keyboardButton"));
        keyboardButton->setMinimumSize(QSize(30, 21));
        keyboardButton->setMaximumSize(QSize(30, 21));
        keyboardButton->setFocusPolicy(Qt::NoFocus);
        keyboardButton->setStyleSheet(QStringLiteral("border-image: url(:/saleImage/keyboard.png);"));

        horizontalLayout_6->addWidget(keyboardButton);


        horizontalLayout->addWidget(searchSkinWidget);


        retranslateUi(SearchMemberEdit);

        QMetaObject::connectSlotsByName(SearchMemberEdit);
    } // setupUi

    void retranslateUi(QWidget *SearchMemberEdit)
    {
        SearchMemberEdit->setWindowTitle(QApplication::translate("SearchMemberEdit", "Form", Q_NULLPTR));
        searchLineEdit->setText(QString());
        searchLineEdit->setPlaceholderText(QApplication::translate("SearchMemberEdit", "\346\220\234\347\264\242\345\221\230\345\267\245\345\267\245\345\217\267,\345\220\215\347\247\260", Q_NULLPTR));
        keyboardButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SearchMemberEdit: public Ui_SearchMemberEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHMEMBEREDIT_H
