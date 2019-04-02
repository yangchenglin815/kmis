/********************************************************************************
** Form generated from reading UI file 'SearchEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHEDIT_H
#define UI_SEARCHEDIT_H

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

class Ui_SearchEdit
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *searchSkinWidget;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *searchLineEdit;
    QPushButton *keyboardButton;

    void setupUi(QWidget *SearchEdit)
    {
        if (SearchEdit->objectName().isEmpty())
            SearchEdit->setObjectName(QStringLiteral("SearchEdit"));
        SearchEdit->resize(176, 30);
        horizontalLayout = new QHBoxLayout(SearchEdit);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        searchSkinWidget = new QWidget(SearchEdit);
        searchSkinWidget->setObjectName(QStringLiteral("searchSkinWidget"));
        searchSkinWidget->setMinimumSize(QSize(0, 30));
        searchSkinWidget->setMaximumSize(QSize(16777215, 16777215));
        searchSkinWidget->setStyleSheet(QLatin1String("QWidget#searchSkinWidget{ \n"
"	background-color:#ffffff;\n"
"	border-radius: 3px;\n"
"	border-color: red;\n"
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
"	border-image:url();	\n"
"}"));

        horizontalLayout_6->addWidget(searchLineEdit);

        keyboardButton = new QPushButton(searchSkinWidget);
        keyboardButton->setObjectName(QStringLiteral("keyboardButton"));
        keyboardButton->setMinimumSize(QSize(30, 21));
        keyboardButton->setMaximumSize(QSize(30, 21));
        keyboardButton->setFocusPolicy(Qt::NoFocus);
        keyboardButton->setStyleSheet(QLatin1String("border-image: url(:/saleImage/keyboard.png);\n"
""));
        keyboardButton->setFlat(false);

        horizontalLayout_6->addWidget(keyboardButton);


        horizontalLayout->addWidget(searchSkinWidget);


        retranslateUi(SearchEdit);

        QMetaObject::connectSlotsByName(SearchEdit);
    } // setupUi

    void retranslateUi(QWidget *SearchEdit)
    {
        SearchEdit->setWindowTitle(QApplication::translate("SearchEdit", "Form", Q_NULLPTR));
        searchLineEdit->setText(QString());
        searchLineEdit->setPlaceholderText(QApplication::translate("SearchEdit", "\350\257\267\350\276\223\345\205\245\345\225\206\345\223\201\344\277\241\346\201\257", Q_NULLPTR));
        keyboardButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SearchEdit: public Ui_SearchEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHEDIT_H
