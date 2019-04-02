/********************************************************************************
** Form generated from reading UI file 'TitleBarWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEBARWIDGET_H
#define UI_TITLEBARWIDGET_H

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

class Ui_TitleBarWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *titleWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QWidget *TitleBarWidget)
    {
        if (TitleBarWidget->objectName().isEmpty())
            TitleBarWidget->setObjectName(QStringLiteral("TitleBarWidget"));
        TitleBarWidget->resize(800, 40);
        TitleBarWidget->setMinimumSize(QSize(0, 40));
        TitleBarWidget->setMaximumSize(QSize(16777215, 16777215));
        TitleBarWidget->setSizeIncrement(QSize(80, 4));
        TitleBarWidget->setBaseSize(QSize(800, 40));
        TitleBarWidget->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(TitleBarWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new QWidget(TitleBarWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setStyleSheet(QLatin1String("QWidget#titleWidget{\n"
"	border-image: url(:/shareImages/title_bar.png);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(titleWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(30, 4, 13, 5);
        titleLabel = new QLabel(titleWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("QLabel#titleLabel {\n"
"	font-size: 16px;\n"
"	color: rgb(255, 255, 255);\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));

        horizontalLayout_2->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(912, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        closeButton = new QPushButton(titleWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(31, 31));
        closeButton->setMaximumSize(QSize(31, 31));
        closeButton->setFocusPolicy(Qt::NoFocus);
        closeButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/shareImages/close.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	\n"
"	border-image: url(:/shareImages/close_press.png);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(closeButton);


        horizontalLayout->addWidget(titleWidget);


        retranslateUi(TitleBarWidget);

        QMetaObject::connectSlotsByName(TitleBarWidget);
    } // setupUi

    void retranslateUi(QWidget *TitleBarWidget)
    {
        TitleBarWidget->setWindowTitle(QApplication::translate("TitleBarWidget", "TitleBarWidget", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("TitleBarWidget", "TextLabel", Q_NULLPTR));
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TitleBarWidget: public Ui_TitleBarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEBARWIDGET_H
