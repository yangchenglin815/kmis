/********************************************************************************
** Form generated from reading UI file 'BCSRelateDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSRELATEDLG_H
#define UI_BCSRELATEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "BCSRelateDlgListView.h"
#include "BCSRelateDlgTitleWidget.h"
#include "TitleBarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_BCSRelateDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *skinWidget;
    QVBoxLayout *verticalLayout_2;
    BCSRelateDlgTitleWidget *topWidget;
    BCSRelateDlgListView *listView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *lastPageButton;
    QFrame *frame;
    QPushButton *nextPageButton;
    QLabel *pageLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirmButton;

    void setupUi(QDialog *BCSRelateDlg)
    {
        if (BCSRelateDlg->objectName().isEmpty())
            BCSRelateDlg->setObjectName(QStringLiteral("BCSRelateDlg"));
        BCSRelateDlg->resize(654, 355);
        BCSRelateDlg->setMinimumSize(QSize(654, 355));
        BCSRelateDlg->setMaximumSize(QSize(654, 355));
        verticalLayout = new QVBoxLayout(BCSRelateDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(BCSRelateDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 38));
        titleWidget->setMaximumSize(QSize(16777215, 38));

        verticalLayout->addWidget(titleWidget);

        skinWidget = new QWidget(BCSRelateDlg);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"	background-color:#505050;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(skinWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        topWidget = new BCSRelateDlgTitleWidget(skinWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setMinimumSize(QSize(0, 36));

        verticalLayout_2->addWidget(topWidget);

        listView = new BCSRelateDlgListView(skinWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setMinimumSize(QSize(0, 0));
        listView->setMaximumSize(QSize(16777215, 16777215));
        listView->setFocusPolicy(Qt::NoFocus);
        listView->setStyleSheet(QLatin1String("QListView{\n"
"	border:none;\n"
"	background-color: #ffffff;\n"
"}\n"
""));
        listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_2->addWidget(listView);

        widget = new QWidget(skinWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 64));
        widget->setMaximumSize(QSize(16777215, 64));
        widget->setStyleSheet(QStringLiteral("background-color: #ffffff;;"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 9, 0);
        lastPageButton = new QPushButton(widget);
        lastPageButton->setObjectName(QStringLiteral("lastPageButton"));
        lastPageButton->setMinimumSize(QSize(87, 37));
        lastPageButton->setMaximumSize(QSize(87, 37));
        lastPageButton->setFocusPolicy(Qt::NoFocus);
        lastPageButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border:none;\n"
"	background-image: url(:/saleImage/btn-up-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-image: url(:/saleImage/btn-up-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"background-image: url(:/saleImage/btn-up-disable.png);\n"
"}"));

        horizontalLayout->addWidget(lastPageButton);

        frame = new QFrame(widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 22));
        frame->setMaximumSize(QSize(16777215, 22));
        frame->setFrameShape(QFrame::VLine);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame);

        nextPageButton = new QPushButton(widget);
        nextPageButton->setObjectName(QStringLiteral("nextPageButton"));
        nextPageButton->setMinimumSize(QSize(87, 37));
        nextPageButton->setMaximumSize(QSize(87, 37));
        nextPageButton->setFocusPolicy(Qt::NoFocus);
        nextPageButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border:none;\n"
"	background-image: url(:/saleImage/btn-down-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-image: url(:/saleImage/btn-down-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"background-image: url(:/saleImage/btn-down-disabled.png);\n"
"}"));

        horizontalLayout->addWidget(nextPageButton);

        pageLabel = new QLabel(widget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setMaximumSize(QSize(410, 16777215));

        horizontalLayout->addWidget(pageLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        confirmButton = new QPushButton(widget);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(confirmButton->sizePolicy().hasHeightForWidth());
        confirmButton->setSizePolicy(sizePolicy);
        confirmButton->setMinimumSize(QSize(121, 42));
        confirmButton->setMaximumSize(QSize(16777215, 42));
        confirmButton->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout->addWidget(confirmButton);


        verticalLayout_2->addWidget(widget);


        verticalLayout->addWidget(skinWidget);


        retranslateUi(BCSRelateDlg);

        QMetaObject::connectSlotsByName(BCSRelateDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSRelateDlg)
    {
        BCSRelateDlg->setWindowTitle(QApplication::translate("BCSRelateDlg", "Dialog", Q_NULLPTR));
        lastPageButton->setText(QString());
        nextPageButton->setText(QString());
        pageLabel->setText(QApplication::translate("BCSRelateDlg", "1/2\351\241\265", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("BCSRelateDlg", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSRelateDlg: public Ui_BCSRelateDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSRELATEDLG_H
