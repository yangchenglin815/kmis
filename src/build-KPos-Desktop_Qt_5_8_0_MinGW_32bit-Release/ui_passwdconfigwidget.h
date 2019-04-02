/********************************************************************************
** Form generated from reading UI file 'passwdconfigwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWDCONFIGWIDGET_H
#define UI_PASSWDCONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitleWithReturnWidget.h"
#include "passwdconfiglistview.h"
#include "searchmemberedit.h"
#include "titlememberwidget.h"

QT_BEGIN_NAMESPACE

class Ui_PasswdConfigWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    TitleWithReturnWidget *titleBarWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    SearchMemberEdit *searchWidget;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout_2;
    TitleMemberWidget *titleWidget;
    PasswdConfigListView *listView;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *leftWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *lastPageButton;
    QWidget *widget_6;
    QPushButton *nextPageButton;
    QSpacerItem *horizontalSpacer_3;
    QLabel *pageLabel;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *deleteButton;
    QPushButton *stopButton;
    QPushButton *startButton;
    QPushButton *editButton;
    QPushButton *addButton;

    void setupUi(QWidget *PasswdConfigWidget)
    {
        if (PasswdConfigWidget->objectName().isEmpty())
            PasswdConfigWidget->setObjectName(QStringLiteral("PasswdConfigWidget"));
        PasswdConfigWidget->resize(800, 600);
        PasswdConfigWidget->setSizeIncrement(QSize(76, 52));
        PasswdConfigWidget->setBaseSize(QSize(766, 523));
        verticalLayout_3 = new QVBoxLayout(PasswdConfigWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        titleBarWidget = new TitleWithReturnWidget(PasswdConfigWidget);
        titleBarWidget->setObjectName(QStringLiteral("titleBarWidget"));
        titleBarWidget->setMinimumSize(QSize(0, 52));
        titleBarWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(titleBarWidget);

        widget = new QWidget(PasswdConfigWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("QWidget#widget{\n"
"background-color: rgb(81, 80, 80);\n"
"}"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, 0, 20, 10);
        topWidget = new QWidget(widget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setMinimumSize(QSize(0, 62));
        topWidget->setMaximumSize(QSize(16777215, 62));
        topWidget->setSizeIncrement(QSize(76, 6));
        topWidget->setBaseSize(QSize(766, 62));
        horizontalLayout = new QHBoxLayout(topWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(215, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        searchWidget = new SearchMemberEdit(topWidget);
        searchWidget->setObjectName(QStringLiteral("searchWidget"));
        searchWidget->setMinimumSize(QSize(262, 32));
        searchWidget->setMaximumSize(QSize(262, 32));

        horizontalLayout->addWidget(searchWidget);


        verticalLayout->addWidget(topWidget);

        mainWidget = new QWidget(widget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"        background-color:#ffffff;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(mainWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleMemberWidget(mainWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 30));
        titleWidget->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(titleWidget);

        listView = new PasswdConfigListView(mainWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView{\n"
"border:none;\n"
"}"));

        verticalLayout_2->addWidget(listView);

        bottomWidget = new QWidget(mainWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 62));
        bottomWidget->setMaximumSize(QSize(16777215, 62));
        bottomWidget->setStyleSheet(QLatin1String("QWidget#bottomWidget{\n"
"        background-color:#ffffff;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(bottomWidget);
        horizontalLayout_3->setSpacing(16);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 16, 20);
        leftWidget = new QWidget(bottomWidget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        leftWidget->setMinimumSize(QSize(200, 0));
        leftWidget->setMaximumSize(QSize(200, 16777215));
        horizontalLayout_4 = new QHBoxLayout(leftWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        widget_5 = new QWidget(leftWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        lastPageButton = new QPushButton(widget_5);
        lastPageButton->setObjectName(QStringLiteral("lastPageButton"));
        lastPageButton->setEnabled(false);
        lastPageButton->setMinimumSize(QSize(87, 37));
        lastPageButton->setMaximumSize(QSize(87, 37));
        lastPageButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"        border-image: url(:/saleImage/btn-up-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"        border-image: url(:/saleImage/btn-up-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"border-image: url(:/saleImage/btn-up-disable.png);\n"
"}"));

        horizontalLayout_5->addWidget(lastPageButton);

        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(1, 18));
        widget_6->setMaximumSize(QSize(1, 18));
        widget_6->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));

        horizontalLayout_5->addWidget(widget_6);

        nextPageButton = new QPushButton(widget_5);
        nextPageButton->setObjectName(QStringLiteral("nextPageButton"));
        nextPageButton->setEnabled(false);
        nextPageButton->setMinimumSize(QSize(87, 37));
        nextPageButton->setMaximumSize(QSize(87, 37));
        nextPageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"        border-image: url(:/saleImage/btn-down-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"        border-image: url(:/saleImage/btn-down-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"        border-image: url(:/saleImage/btn-down-disabled.png);\n"
"}"));

        horizontalLayout_5->addWidget(nextPageButton);


        horizontalLayout_4->addWidget(widget_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pageLabel = new QLabel(leftWidget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"color:#999999;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-top:6px;"));

        horizontalLayout_4->addWidget(pageLabel);


        horizontalLayout_3->addWidget(leftWidget);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        widget_3 = new QWidget(bottomWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        widget_3->setMinimumSize(QSize(431, 0));
        widget_3->setMaximumSize(QSize(431, 16777215));
        horizontalLayout_6 = new QHBoxLayout(widget_3);
        horizontalLayout_6->setSpacing(4);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        deleteButton = new QPushButton(widget_3);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy1);
        deleteButton->setMinimumSize(QSize(0, 0));
        deleteButton->setMaximumSize(QSize(16777215, 16777215));
        deleteButton->setStyleSheet(QLatin1String("QPushButton{\n"
"        font-size:16px;\n"
"        color:#ffffff;\n"
"        border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"        border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"        border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_6->addWidget(deleteButton);

        stopButton = new QPushButton(widget_3);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        sizePolicy1.setHeightForWidth(stopButton->sizePolicy().hasHeightForWidth());
        stopButton->setSizePolicy(sizePolicy1);
        stopButton->setStyleSheet(QLatin1String("QPushButton{\n"
"        font-size:16px;\n"
"        color:#ffffff;\n"
"        border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"        border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"        border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_6->addWidget(stopButton);

        startButton = new QPushButton(widget_3);
        startButton->setObjectName(QStringLiteral("startButton"));
        sizePolicy1.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy1);
        startButton->setStyleSheet(QLatin1String("QPushButton{\n"
"        font-size:16px;\n"
"        color:#ffffff;\n"
"        border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"        border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"        border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_6->addWidget(startButton);

        editButton = new QPushButton(widget_3);
        editButton->setObjectName(QStringLiteral("editButton"));
        sizePolicy1.setHeightForWidth(editButton->sizePolicy().hasHeightForWidth());
        editButton->setSizePolicy(sizePolicy1);
        editButton->setStyleSheet(QLatin1String("QPushButton{\n"
"        font-size:16px;\n"
"        color:#ffffff;\n"
"        border-image: url(:/adjustPrice/blueButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"        border-image: url(:/adjustPrice/blueButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"        border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_6->addWidget(editButton);

        addButton = new QPushButton(widget_3);
        addButton->setObjectName(QStringLiteral("addButton"));
        sizePolicy1.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy1);
        addButton->setMinimumSize(QSize(0, 0));
        addButton->setMaximumSize(QSize(16777215, 16777215));
        addButton->setStyleSheet(QLatin1String("QPushButton{\n"
"        font-size:16px;\n"
"        color:#ffffff;\n"
"        border-image: url(:/adjustPrice/orangeButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"        border-image: url(:/adjustPrice/OrangeButtonPress.png);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"        border-image: url(:/adjustPrice/buttonDisable.png);\n"
"}"));

        horizontalLayout_6->addWidget(addButton);


        horizontalLayout_3->addWidget(widget_3);


        verticalLayout_2->addWidget(bottomWidget);


        verticalLayout->addWidget(mainWidget);


        verticalLayout_3->addWidget(widget);

        verticalLayout_3->setStretch(0, 52);
        verticalLayout_3->setStretch(1, 548);

        retranslateUi(PasswdConfigWidget);

        QMetaObject::connectSlotsByName(PasswdConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *PasswdConfigWidget)
    {
        PasswdConfigWidget->setWindowTitle(QApplication::translate("PasswdConfigWidget", "Form", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("PasswdConfigWidget", "1/1\351\241\265", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("PasswdConfigWidget", "\345\210\240\351\231\244", Q_NULLPTR));
        stopButton->setText(QApplication::translate("PasswdConfigWidget", "\347\246\201\347\224\250", Q_NULLPTR));
        startButton->setText(QApplication::translate("PasswdConfigWidget", "\345\220\257\347\224\250", Q_NULLPTR));
        editButton->setText(QApplication::translate("PasswdConfigWidget", "\347\274\226\350\276\221", Q_NULLPTR));
        addButton->setText(QApplication::translate("PasswdConfigWidget", "\346\226\260\345\273\272\345\221\230\345\267\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PasswdConfigWidget: public Ui_PasswdConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWDCONFIGWIDGET_H
