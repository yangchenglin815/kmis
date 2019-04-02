/********************************************************************************
** Form generated from reading UI file 'TitleBarLabel.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEBARLABEL_H
#define UI_TITLEBARLABEL_H

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

QT_BEGIN_NAMESPACE

class Ui_TitleBarLabel
{
public:
    QHBoxLayout *horizontalLayout_5;
    QWidget *skintWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *logoLabel;
    QPushButton *stableButton;
    QPushButton *overWeightButton;
    QPushButton *memberButton;
    QPushButton *onlineStateButton;
    QPushButton *lessWeightButton;
    QPushButton *zeroButton;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *shopLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *storeLabel;
    QLabel *storeNameLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *posLabel;
    QLabel *posIDLabel;
    QSpacerItem *horizontalSpacer_4;
    QLabel *cashierLabel;
    QLabel *cashierNameLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *backButton;

    void setupUi(QWidget *TitleBarLabel)
    {
        if (TitleBarLabel->objectName().isEmpty())
            TitleBarLabel->setObjectName(QStringLiteral("TitleBarLabel"));
        TitleBarLabel->resize(801, 51);
        TitleBarLabel->setMinimumSize(QSize(800, 51));
        TitleBarLabel->setMaximumSize(QSize(16777215, 16777215));
        TitleBarLabel->setStyleSheet(QStringLiteral(""));
        horizontalLayout_5 = new QHBoxLayout(TitleBarLabel);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        skintWidget = new QWidget(TitleBarLabel);
        skintWidget->setObjectName(QStringLiteral("skintWidget"));
        skintWidget->setStyleSheet(QLatin1String("QWidget#skintWidget {\n"
"	border-image: url(:/shareImages/title_bar.png);\n"
"}"));
        horizontalLayout_7 = new QHBoxLayout(skintWidget);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(18, 0, 18, 0);
        logoLabel = new QLabel(skintWidget);
        logoLabel->setObjectName(QStringLiteral("logoLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logoLabel->sizePolicy().hasHeightForWidth());
        logoLabel->setSizePolicy(sizePolicy);
        logoLabel->setMinimumSize(QSize(64, 19));
        logoLabel->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(10);
        logoLabel->setFont(font);
        logoLabel->setStyleSheet(QLatin1String("/*border-image: url(:/shareImages/logo.png);*/\n"
"image: url(:/saleImage/logo_sale.png);"));

        horizontalLayout_7->addWidget(logoLabel);

        stableButton = new QPushButton(skintWidget);
        stableButton->setObjectName(QStringLiteral("stableButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stableButton->sizePolicy().hasHeightForWidth());
        stableButton->setSizePolicy(sizePolicy1);
        stableButton->setMinimumSize(QSize(0, 19));
        stableButton->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        stableButton->setFont(font1);
        stableButton->setFocusPolicy(Qt::NoFocus);
        stableButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:none;\n"
"font-size:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icoImage/stable_light.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/icoImage/stable.png"), QSize(), QIcon::Disabled, QIcon::Off);
        stableButton->setIcon(icon);
        stableButton->setIconSize(QSize(35, 32));
        stableButton->setFlat(true);

        horizontalLayout_7->addWidget(stableButton);

        overWeightButton = new QPushButton(skintWidget);
        overWeightButton->setObjectName(QStringLiteral("overWeightButton"));
        sizePolicy1.setHeightForWidth(overWeightButton->sizePolicy().hasHeightForWidth());
        overWeightButton->setSizePolicy(sizePolicy1);
        overWeightButton->setMinimumSize(QSize(0, 19));
        overWeightButton->setMaximumSize(QSize(16777215, 16777215));
        overWeightButton->setFont(font1);
        overWeightButton->setFocusPolicy(Qt::NoFocus);
        overWeightButton->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border: none;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icoImage/overload_light.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/icoImage/overload.png"), QSize(), QIcon::Disabled, QIcon::Off);
        overWeightButton->setIcon(icon1);
        overWeightButton->setIconSize(QSize(35, 32));
        overWeightButton->setFlat(true);

        horizontalLayout_7->addWidget(overWeightButton);

        memberButton = new QPushButton(skintWidget);
        memberButton->setObjectName(QStringLiteral("memberButton"));
        sizePolicy1.setHeightForWidth(memberButton->sizePolicy().hasHeightForWidth());
        memberButton->setSizePolicy(sizePolicy1);
        memberButton->setMinimumSize(QSize(0, 19));
        memberButton->setMaximumSize(QSize(16777215, 16777215));
        memberButton->setFont(font1);
        memberButton->setFocusPolicy(Qt::NoFocus);
        memberButton->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border: none;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icoImage/member_light.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/icoImage/member.png"), QSize(), QIcon::Disabled, QIcon::Off);
        memberButton->setIcon(icon2);
        memberButton->setIconSize(QSize(35, 32));
        memberButton->setFlat(true);

        horizontalLayout_7->addWidget(memberButton);

        onlineStateButton = new QPushButton(skintWidget);
        onlineStateButton->setObjectName(QStringLiteral("onlineStateButton"));
        sizePolicy1.setHeightForWidth(onlineStateButton->sizePolicy().hasHeightForWidth());
        onlineStateButton->setSizePolicy(sizePolicy1);
        onlineStateButton->setMinimumSize(QSize(0, 19));
        onlineStateButton->setMaximumSize(QSize(16777215, 16777215));
        onlineStateButton->setFont(font1);
        onlineStateButton->setFocusPolicy(Qt::NoFocus);
        onlineStateButton->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border: none;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icoImage/networking_light.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QStringLiteral(":/icoImage/networking.png"), QSize(), QIcon::Disabled, QIcon::Off);
        onlineStateButton->setIcon(icon3);
        onlineStateButton->setIconSize(QSize(35, 32));
        onlineStateButton->setFlat(true);

        horizontalLayout_7->addWidget(onlineStateButton);

        lessWeightButton = new QPushButton(skintWidget);
        lessWeightButton->setObjectName(QStringLiteral("lessWeightButton"));
        sizePolicy1.setHeightForWidth(lessWeightButton->sizePolicy().hasHeightForWidth());
        lessWeightButton->setSizePolicy(sizePolicy1);
        lessWeightButton->setMinimumSize(QSize(0, 19));
        lessWeightButton->setMaximumSize(QSize(16777215, 16777215));
        lessWeightButton->setFont(font1);
        lessWeightButton->setFocusPolicy(Qt::NoFocus);
        lessWeightButton->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border: none;"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icoImage/underload_light.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QStringLiteral(":/icoImage/underload.png"), QSize(), QIcon::Disabled, QIcon::Off);
        lessWeightButton->setIcon(icon4);
        lessWeightButton->setIconSize(QSize(35, 32));
        lessWeightButton->setFlat(true);

        horizontalLayout_7->addWidget(lessWeightButton);

        zeroButton = new QPushButton(skintWidget);
        zeroButton->setObjectName(QStringLiteral("zeroButton"));
        sizePolicy1.setHeightForWidth(zeroButton->sizePolicy().hasHeightForWidth());
        zeroButton->setSizePolicy(sizePolicy1);
        zeroButton->setMinimumSize(QSize(0, 19));
        zeroButton->setMaximumSize(QSize(16777215, 16777215));
        zeroButton->setFont(font1);
        zeroButton->setFocusPolicy(Qt::NoFocus);
        zeroButton->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border: none;"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icoImage/zero_light.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QStringLiteral(":/icoImage/zero.png"), QSize(), QIcon::Disabled, QIcon::Off);
        zeroButton->setIcon(icon5);
        zeroButton->setIconSize(QSize(35, 32));
        zeroButton->setFlat(true);

        horizontalLayout_7->addWidget(zeroButton);

        horizontalSpacer = new QSpacerItem(25, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 4, -1, -1);
        shopLabel = new QLabel(skintWidget);
        shopLabel->setObjectName(QStringLiteral("shopLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(shopLabel->sizePolicy().hasHeightForWidth());
        shopLabel->setSizePolicy(sizePolicy2);
        shopLabel->setMinimumSize(QSize(0, 15));
        shopLabel->setMaximumSize(QSize(16777215, 16777215));
        shopLabel->setFont(font1);
        shopLabel->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        shopLabel->setLineWidth(1);

        horizontalLayout_4->addWidget(shopLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        storeLabel = new QLabel(skintWidget);
        storeLabel->setObjectName(QStringLiteral("storeLabel"));
        sizePolicy2.setHeightForWidth(storeLabel->sizePolicy().hasHeightForWidth());
        storeLabel->setSizePolicy(sizePolicy2);
        storeLabel->setMinimumSize(QSize(0, 15));
        storeLabel->setMaximumSize(QSize(16777215, 16777215));
        storeLabel->setFont(font1);
        storeLabel->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(119, 119, 119);"));

        horizontalLayout_4->addWidget(storeLabel);

        storeNameLabel = new QLabel(skintWidget);
        storeNameLabel->setObjectName(QStringLiteral("storeNameLabel"));
        sizePolicy2.setHeightForWidth(storeNameLabel->sizePolicy().hasHeightForWidth());
        storeNameLabel->setSizePolicy(sizePolicy2);
        storeNameLabel->setMinimumSize(QSize(0, 15));
        storeNameLabel->setMaximumSize(QSize(16777215, 16777215));
        storeNameLabel->setFont(font1);
        storeNameLabel->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(119, 119, 119);"));

        horizontalLayout_4->addWidget(storeNameLabel);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        posLabel = new QLabel(skintWidget);
        posLabel->setObjectName(QStringLiteral("posLabel"));
        sizePolicy2.setHeightForWidth(posLabel->sizePolicy().hasHeightForWidth());
        posLabel->setSizePolicy(sizePolicy2);
        posLabel->setMinimumSize(QSize(0, 15));
        posLabel->setMaximumSize(QSize(16777215, 16777215));
        posLabel->setFont(font1);
        posLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(119, 119, 119);"));

        horizontalLayout->addWidget(posLabel);

        posIDLabel = new QLabel(skintWidget);
        posIDLabel->setObjectName(QStringLiteral("posIDLabel"));
        sizePolicy2.setHeightForWidth(posIDLabel->sizePolicy().hasHeightForWidth());
        posIDLabel->setSizePolicy(sizePolicy2);
        posIDLabel->setMinimumSize(QSize(0, 15));
        posIDLabel->setMaximumSize(QSize(16777215, 16777215));
        posIDLabel->setFont(font1);
        posIDLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(119, 119, 119);"));

        horizontalLayout->addWidget(posIDLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        cashierLabel = new QLabel(skintWidget);
        cashierLabel->setObjectName(QStringLiteral("cashierLabel"));
        sizePolicy2.setHeightForWidth(cashierLabel->sizePolicy().hasHeightForWidth());
        cashierLabel->setSizePolicy(sizePolicy2);
        cashierLabel->setMinimumSize(QSize(0, 15));
        cashierLabel->setMaximumSize(QSize(16777215, 16777215));
        cashierLabel->setFont(font1);
        cashierLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(119, 119, 119);"));

        horizontalLayout->addWidget(cashierLabel);

        cashierNameLabel = new QLabel(skintWidget);
        cashierNameLabel->setObjectName(QStringLiteral("cashierNameLabel"));
        sizePolicy2.setHeightForWidth(cashierNameLabel->sizePolicy().hasHeightForWidth());
        cashierNameLabel->setSizePolicy(sizePolicy2);
        cashierNameLabel->setMinimumSize(QSize(0, 15));
        cashierNameLabel->setMaximumSize(QSize(16777215, 16777215));
        cashierNameLabel->setFont(font1);
        cashierNameLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(119, 119, 119);"));

        horizontalLayout->addWidget(cashierNameLabel);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_7->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(9, 48, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        backButton = new QPushButton(skintWidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy3);
        backButton->setMinimumSize(QSize(65, 39));
        backButton->setMaximumSize(QSize(16777215, 16777215));
        backButton->setFocusPolicy(Qt::NoFocus);
        backButton->setStyleSheet(QLatin1String("QPushButton#backButton {\n"
"	border-image: url(:/shareImages/btn_back_normal.png);\n"
"}\n"
"\n"
"QPushButton#backButton:pressed {\n"
"	border-image: url(:/shareImages/btn_back_press.png);\n"
"}"));

        horizontalLayout_7->addWidget(backButton);


        horizontalLayout_5->addWidget(skintWidget);


        retranslateUi(TitleBarLabel);

        QMetaObject::connectSlotsByName(TitleBarLabel);
    } // setupUi

    void retranslateUi(QWidget *TitleBarLabel)
    {
        TitleBarLabel->setWindowTitle(QApplication::translate("TitleBarLabel", "TitleBarLabel", Q_NULLPTR));
        logoLabel->setText(QString());
        stableButton->setText(QApplication::translate("TitleBarLabel", "\347\250\263\345\256\232", Q_NULLPTR));
        overWeightButton->setText(QApplication::translate("TitleBarLabel", "\350\277\207\350\275\275", Q_NULLPTR));
        memberButton->setText(QApplication::translate("TitleBarLabel", "\344\274\232\345\221\230", Q_NULLPTR));
        onlineStateButton->setText(QApplication::translate("TitleBarLabel", "\350\201\224\347\275\221", Q_NULLPTR));
        lessWeightButton->setText(QApplication::translate("TitleBarLabel", "\346\254\240\350\275\275", Q_NULLPTR));
        zeroButton->setText(QApplication::translate("TitleBarLabel", "\351\233\266\344\275\215", Q_NULLPTR));
        shopLabel->setText(QApplication::translate("TitleBarLabel", "xxx\345\272\204\345\233\255\345\272\227\351\223\272", Q_NULLPTR));
        storeLabel->setText(QApplication::translate("TitleBarLabel", "\351\227\250\345\272\227\357\274\232", Q_NULLPTR));
        storeNameLabel->setText(QApplication::translate("TitleBarLabel", "\350\245\277\346\271\226\345\272\227", Q_NULLPTR));
        posLabel->setText(QApplication::translate("TitleBarLabel", "\346\254\276\346\234\272\357\274\232", Q_NULLPTR));
        posIDLabel->setText(QApplication::translate("TitleBarLabel", "093834", Q_NULLPTR));
        cashierLabel->setText(QApplication::translate("TitleBarLabel", "\346\224\266\351\223\266\345\221\230\357\274\232", Q_NULLPTR));
        cashierNameLabel->setText(QApplication::translate("TitleBarLabel", "xxxx", Q_NULLPTR));
        backButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TitleBarLabel: public Ui_TitleBarLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEBARLABEL_H
