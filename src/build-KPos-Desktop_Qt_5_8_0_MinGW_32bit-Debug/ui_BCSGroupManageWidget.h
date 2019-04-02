/********************************************************************************
** Form generated from reading UI file 'BCSGroupManageWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSGROUPMANAGEWIDGET_H
#define UI_BCSGROUPMANAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "BCSGroupManageLeftWidget.h"
#include "BCSGroupManageRightWidget.h"

QT_BEGIN_NAMESPACE

class Ui_BCSGroupManageWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    BCSGroupManageLeftWidget *bcsLeftWidget;
    QWidget *widget;
    BCSGroupManageRightWidget *bcsRightWidget;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *relateButton;
    QPushButton *deleteButton;
    QPushButton *editButton;
    QPushButton *addButton;

    void setupUi(QWidget *BCSGroupManageWidget)
    {
        if (BCSGroupManageWidget->objectName().isEmpty())
            BCSGroupManageWidget->setObjectName(QStringLiteral("BCSGroupManageWidget"));
        BCSGroupManageWidget->resize(760, 480);
        BCSGroupManageWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(BCSGroupManageWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        bcsLeftWidget = new BCSGroupManageLeftWidget(BCSGroupManageWidget);
        bcsLeftWidget->setObjectName(QStringLiteral("bcsLeftWidget"));
        bcsLeftWidget->setMinimumSize(QSize(240, 0));
        bcsLeftWidget->setMaximumSize(QSize(240, 16777215));
        bcsLeftWidget->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(bcsLeftWidget);

        widget = new QWidget(BCSGroupManageWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(1, 0));
        widget->setMaximumSize(QSize(1, 16777215));
        widget->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));

        horizontalLayout->addWidget(widget);

        bcsRightWidget = new BCSGroupManageRightWidget(BCSGroupManageWidget);
        bcsRightWidget->setObjectName(QStringLiteral("bcsRightWidget"));
        bcsRightWidget->setMinimumSize(QSize(0, 0));
        bcsRightWidget->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(bcsRightWidget);


        verticalLayout_3->addLayout(horizontalLayout);

        bottomWidget = new QWidget(BCSGroupManageWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 82));
        bottomWidget->setMaximumSize(QSize(16777215, 82));
        bottomWidget->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(bottomWidget);
        horizontalLayout_3->setSpacing(16);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 20, 16, 20);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        widget_3 = new QWidget(bottomWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        widget_3->setMinimumSize(QSize(350, 0));
        widget_3->setMaximumSize(QSize(350, 16777215));
        horizontalLayout_6 = new QHBoxLayout(widget_3);
        horizontalLayout_6->setSpacing(4);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        relateButton = new QPushButton(widget_3);
        relateButton->setObjectName(QStringLiteral("relateButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(relateButton->sizePolicy().hasHeightForWidth());
        relateButton->setSizePolicy(sizePolicy1);
        relateButton->setMinimumSize(QSize(0, 0));
        relateButton->setMaximumSize(QSize(16777215, 16777215));
        relateButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_6->addWidget(relateButton);

        deleteButton = new QPushButton(widget_3);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        sizePolicy1.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy1);
        deleteButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_6->addWidget(deleteButton);

        editButton = new QPushButton(widget_3);
        editButton->setObjectName(QStringLiteral("editButton"));
        sizePolicy1.setHeightForWidth(editButton->sizePolicy().hasHeightForWidth());
        editButton->setSizePolicy(sizePolicy1);
        editButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_6->addWidget(editButton);

        addButton = new QPushButton(widget_3);
        addButton->setObjectName(QStringLiteral("addButton"));
        sizePolicy1.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy1);
        addButton->setMinimumSize(QSize(0, 0));
        addButton->setMaximumSize(QSize(16777215, 16777215));
        addButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:16px;\n"
"	color:#ffffff;\n"
"	border-image: url(:/adjustPrice/orangeButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/adjustPrice/OrangeButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_6->addWidget(addButton);


        horizontalLayout_3->addWidget(widget_3);


        verticalLayout_3->addWidget(bottomWidget);


        retranslateUi(BCSGroupManageWidget);

        QMetaObject::connectSlotsByName(BCSGroupManageWidget);
    } // setupUi

    void retranslateUi(QWidget *BCSGroupManageWidget)
    {
        BCSGroupManageWidget->setWindowTitle(QApplication::translate("BCSGroupManageWidget", "Form", Q_NULLPTR));
        relateButton->setText(QApplication::translate("BCSGroupManageWidget", "\345\205\263\350\201\224\346\235\241\347\240\201\347\247\244", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("BCSGroupManageWidget", "\345\210\240\351\231\244", Q_NULLPTR));
        editButton->setText(QApplication::translate("BCSGroupManageWidget", "\347\274\226\350\276\221", Q_NULLPTR));
        addButton->setText(QApplication::translate("BCSGroupManageWidget", "\346\226\260\345\242\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSGroupManageWidget: public Ui_BCSGroupManageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSGROUPMANAGEWIDGET_H
