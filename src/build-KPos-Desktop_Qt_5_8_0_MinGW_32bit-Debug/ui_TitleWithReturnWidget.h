/********************************************************************************
** Form generated from reading UI file 'TitleWithReturnWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEWITHRETURNWIDGET_H
#define UI_TITLEWITHRETURNWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TitleWithReturnWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *titleBarWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *logoLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *backButton;

    void setupUi(QWidget *TitleWithReturnWidget)
    {
        if (TitleWithReturnWidget->objectName().isEmpty())
            TitleWithReturnWidget->setObjectName(QStringLiteral("TitleWithReturnWidget"));
        TitleWithReturnWidget->resize(800, 52);
        TitleWithReturnWidget->setSizeIncrement(QSize(80, 5));
        TitleWithReturnWidget->setBaseSize(QSize(800, 52));
        horizontalLayout = new QHBoxLayout(TitleWithReturnWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        titleBarWidget = new QWidget(TitleWithReturnWidget);
        titleBarWidget->setObjectName(QStringLiteral("titleBarWidget"));
        titleBarWidget->setMinimumSize(QSize(0, 0));
        titleBarWidget->setMaximumSize(QSize(16777215, 16777215));
        titleBarWidget->setSizeIncrement(QSize(80, 5));
        titleBarWidget->setBaseSize(QSize(800, 52));
        titleBarWidget->setStyleSheet(QLatin1String("QWidget#titleBarWidget {\n"
"	border-image: url(:/shareImages/dlg_titlebar.png);\n"
"}\n"
""));
        horizontalLayout_2 = new QHBoxLayout(titleBarWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        logoLabel = new QLabel(titleBarWidget);
        logoLabel->setObjectName(QStringLiteral("logoLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logoLabel->sizePolicy().hasHeightForWidth());
        logoLabel->setSizePolicy(sizePolicy);
        logoLabel->setMinimumSize(QSize(64, 0));
        logoLabel->setMaximumSize(QSize(16777215, 20));
        logoLabel->setStyleSheet(QStringLiteral("border-image: url(:/saleImage/logo_sale.png);"));

        horizontalLayout_2->addWidget(logoLabel);

        horizontalSpacer = new QSpacerItem(638, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        backButton = new QPushButton(titleBarWidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy1);
        backButton->setMinimumSize(QSize(65, 0));
        backButton->setMaximumSize(QSize(16777215, 16777215));
        backButton->setFocusPolicy(Qt::NoFocus);
        backButton->setStyleSheet(QLatin1String("QPushButton#backButton {\n"
"	border-image: url(:/shareImages/btn_back_normal.png);\n"
"}\n"
"\n"
"QPushButton#backButton:press {\n"
"	border-image: url(:/shareImages/btn_back_press.png);\n"
"}"));

        horizontalLayout_2->addWidget(backButton);


        horizontalLayout->addWidget(titleBarWidget);


        retranslateUi(TitleWithReturnWidget);

        QMetaObject::connectSlotsByName(TitleWithReturnWidget);
    } // setupUi

    void retranslateUi(QWidget *TitleWithReturnWidget)
    {
        TitleWithReturnWidget->setWindowTitle(QApplication::translate("TitleWithReturnWidget", "Form", Q_NULLPTR));
        logoLabel->setText(QString());
        backButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TitleWithReturnWidget: public Ui_TitleWithReturnWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEWITHRETURNWIDGET_H
