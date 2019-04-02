/********************************************************************************
** Form generated from reading UI file 'ChangeOrderNumberWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEORDERNUMBERWIDGET_H
#define UI_CHANGEORDERNUMBERWIDGET_H

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

class Ui_ChangeOrderNumberWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *skinWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *leftArrowButton;
    QLineEdit *lineEdit;
    QPushButton *rightArrowButton;

    void setupUi(QWidget *ChangeOrderNumberWidget)
    {
        if (ChangeOrderNumberWidget->objectName().isEmpty())
            ChangeOrderNumberWidget->setObjectName(QStringLiteral("ChangeOrderNumberWidget"));
        ChangeOrderNumberWidget->resize(79, 38);
        horizontalLayout_2 = new QHBoxLayout(ChangeOrderNumberWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        skinWidget = new QWidget(ChangeOrderNumberWidget);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        horizontalLayout = new QHBoxLayout(skinWidget);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leftArrowButton = new QPushButton(skinWidget);
        leftArrowButton->setObjectName(QStringLiteral("leftArrowButton"));
        leftArrowButton->setMinimumSize(QSize(15, 18));
        leftArrowButton->setMaximumSize(QSize(15, 18));
        leftArrowButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image:url(:/orderGoodsImage/leftArrow.png)\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/orderGoodsImage/leftArrow_press.png);\n"
"}"));

        horizontalLayout->addWidget(leftArrowButton);

        lineEdit = new QLineEdit(skinWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit->setLayoutDirection(Qt::RightToLeft);
        lineEdit->setStyleSheet(QLatin1String("border: 1px solid #ea8852;\n"
"padding: 0 0 0 0 ;"));
        lineEdit->setMaxLength(4);

        horizontalLayout->addWidget(lineEdit);

        rightArrowButton = new QPushButton(skinWidget);
        rightArrowButton->setObjectName(QStringLiteral("rightArrowButton"));
        rightArrowButton->setMinimumSize(QSize(15, 18));
        rightArrowButton->setMaximumSize(QSize(15, 18));
        rightArrowButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/orderGoodsImage/rightArrow.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/orderGoodsImage/rightArrow_press.png);\n"
"}"));

        horizontalLayout->addWidget(rightArrowButton);


        horizontalLayout_2->addWidget(skinWidget);


        retranslateUi(ChangeOrderNumberWidget);

        QMetaObject::connectSlotsByName(ChangeOrderNumberWidget);
    } // setupUi

    void retranslateUi(QWidget *ChangeOrderNumberWidget)
    {
        ChangeOrderNumberWidget->setWindowTitle(QApplication::translate("ChangeOrderNumberWidget", "Form", Q_NULLPTR));
        leftArrowButton->setText(QString());
        rightArrowButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChangeOrderNumberWidget: public Ui_ChangeOrderNumberWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEORDERNUMBERWIDGET_H
