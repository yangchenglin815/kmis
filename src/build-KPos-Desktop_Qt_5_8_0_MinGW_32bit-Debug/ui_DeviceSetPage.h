/********************************************************************************
** Form generated from reading UI file 'DeviceSetPage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICESETPAGE_H
#define UI_DEVICESETPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceSetPage
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_1;
    QHBoxLayout *horizontalLayout_1;
    QLabel *label;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *typeButton1;
    QRadioButton *typeButton2;
    QLabel *label_9;
    QComboBox *comboBox;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_12;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QLabel *label_10;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *isPrintButton_1;
    QRadioButton *isPrintButton_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_10;
    QRadioButton *modeButton_1;
    QRadioButton *modeButton_2;
    QRadioButton *modeButton_3;
    QRadioButton *modeButton_4;
    QRadioButton *modeButton_5;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QLabel *label_11;
    QComboBox *comboBox_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QListView *networkImpList;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QListWidget *localImpList;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QComboBox *comboBox_5;
    QLabel *label_12;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_11;
    QComboBox *comboBox_6;
    QPushButton *pushButton_2;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QComboBox *pricingScaleType;
    QLabel *label_13;
    QComboBox *pricingScalePort;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *DeviceSetPage)
    {
        if (DeviceSetPage->objectName().isEmpty())
            DeviceSetPage->setObjectName(QStringLiteral("DeviceSetPage"));
        DeviceSetPage->resize(605, 501);
        DeviceSetPage->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(DeviceSetPage);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalWidget = new QWidget(DeviceSetPage);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        verticalWidget->setStyleSheet(QLatin1String("background-color:#ffffff;\n"
""));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_1 = new QWidget(verticalWidget);
        widget_1->setObjectName(QStringLiteral("widget_1"));
        widget_1->setMinimumSize(QSize(0, 45));
        horizontalLayout_1 = new QHBoxLayout(widget_1);
        horizontalLayout_1->setObjectName(QStringLiteral("horizontalLayout_1"));
        horizontalLayout_1->setContentsMargins(-1, 0, -1, 0);
        label = new QLabel(widget_1);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout_1->addWidget(label);

        groupBox = new QGroupBox(widget_1);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral("border-style:solid 0px #000"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        typeButton1 = new QRadioButton(groupBox);
        typeButton1->setObjectName(QStringLiteral("typeButton1"));
        typeButton1->setFont(font);

        horizontalLayout->addWidget(typeButton1);

        typeButton2 = new QRadioButton(groupBox);
        typeButton2->setObjectName(QStringLiteral("typeButton2"));
        typeButton2->setFont(font);

        horizontalLayout->addWidget(typeButton2);


        horizontalLayout_1->addWidget(groupBox);

        label_9 = new QLabel(widget_1);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        horizontalLayout_1->addWidget(label_9);

        comboBox = new QComboBox(widget_1);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(0, 30));
        comboBox->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));

        horizontalLayout_1->addWidget(comboBox);

        horizontalLayout_1->setStretch(0, 80);
        horizontalLayout_1->setStretch(1, 180);
        horizontalLayout_1->setStretch(2, 80);
        horizontalLayout_1->setStretch(3, 180);

        verticalLayout->addWidget(widget_1);

        widget_2 = new QWidget(verticalWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 45));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        groupBox_5 = new QGroupBox(widget_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setStyleSheet(QLatin1String("QGroupBox#groupBox_5{\n"
"	border-style:solid 0px #000\n"
"}"));
        horizontalLayout_12 = new QHBoxLayout(groupBox_5);
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        comboBox_2 = new QComboBox(groupBox_5);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(0, 30));
        comboBox_2->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));

        horizontalLayout_12->addWidget(comboBox_2);

        pushButton = new QPushButton(groupBox_5);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QLatin1String("QPushButton#pushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/setImage/add_category_normal.png);\n"
"}\n"
"\n"
"QPushButton#pushButton:pressed {\n"
"	border-image: url(:/setImage/add_category_press.png);\n"
"}"));

        horizontalLayout_12->addWidget(pushButton);

        horizontalLayout_12->setStretch(0, 120);
        horizontalLayout_12->setStretch(1, 60);

        horizontalLayout_2->addWidget(groupBox_5);

        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        horizontalLayout_2->addWidget(label_10);

        groupBox_2 = new QGroupBox(widget_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QStringLiteral("border-style:solid 0px #000"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_2);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        isPrintButton_1 = new QRadioButton(groupBox_2);
        isPrintButton_1->setObjectName(QStringLiteral("isPrintButton_1"));
        isPrintButton_1->setFont(font);

        horizontalLayout_9->addWidget(isPrintButton_1);

        isPrintButton_2 = new QRadioButton(groupBox_2);
        isPrintButton_2->setObjectName(QStringLiteral("isPrintButton_2"));
        isPrintButton_2->setFont(font);

        horizontalLayout_9->addWidget(isPrintButton_2);


        horizontalLayout_2->addWidget(groupBox_2);

        horizontalLayout_2->setStretch(0, 80);
        horizontalLayout_2->setStretch(1, 180);
        horizontalLayout_2->setStretch(2, 80);
        horizontalLayout_2->setStretch(3, 180);

        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(verticalWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 35));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(87, 0));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        groupBox_3 = new QGroupBox(widget_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setStyleSheet(QStringLiteral("border-style:solid 0px #000"));
        horizontalLayout_10 = new QHBoxLayout(groupBox_3);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        modeButton_1 = new QRadioButton(groupBox_3);
        modeButton_1->setObjectName(QStringLiteral("modeButton_1"));

        horizontalLayout_10->addWidget(modeButton_1);

        modeButton_2 = new QRadioButton(groupBox_3);
        modeButton_2->setObjectName(QStringLiteral("modeButton_2"));

        horizontalLayout_10->addWidget(modeButton_2);

        modeButton_3 = new QRadioButton(groupBox_3);
        modeButton_3->setObjectName(QStringLiteral("modeButton_3"));

        horizontalLayout_10->addWidget(modeButton_3);

        modeButton_4 = new QRadioButton(groupBox_3);
        modeButton_4->setObjectName(QStringLiteral("modeButton_4"));

        horizontalLayout_10->addWidget(modeButton_4);

        modeButton_5 = new QRadioButton(groupBox_3);
        modeButton_5->setObjectName(QStringLiteral("modeButton_5"));

        horizontalLayout_10->addWidget(modeButton_5);


        horizontalLayout_4->addWidget(groupBox_3);

        horizontalLayout_4->setStretch(0, 80);
        horizontalLayout_4->setStretch(1, 470);

        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(verticalWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 35));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(87, 0));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        comboBox_3 = new QComboBox(widget_4);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setMinimumSize(QSize(0, 30));
        comboBox_3->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));

        horizontalLayout_3->addWidget(comboBox_3);

        label_11 = new QLabel(widget_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(87, 0));
        label_11->setFont(font);

        horizontalLayout_3->addWidget(label_11);

        comboBox_4 = new QComboBox(widget_4);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setMinimumSize(QSize(0, 30));
        comboBox_4->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));

        horizontalLayout_3->addWidget(comboBox_4);

        horizontalLayout_3->setStretch(0, 60);
        horizontalLayout_3->setStretch(1, 180);
        horizontalLayout_3->setStretch(2, 60);
        horizontalLayout_3->setStretch(3, 180);

        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(verticalWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(0, 62));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, 0);
        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        networkImpList = new QListView(widget_5);
        networkImpList->setObjectName(QStringLiteral("networkImpList"));
        networkImpList->setMaximumSize(QSize(16777215, 62));

        horizontalLayout_5->addWidget(networkImpList);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(verticalWidget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(0, 62));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 0, -1, 0);
        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_6->addWidget(label_6);

        localImpList = new QListWidget(widget_6);
        localImpList->setObjectName(QStringLiteral("localImpList"));
        localImpList->setMaximumSize(QSize(16777215, 62));

        horizontalLayout_6->addWidget(localImpList);


        verticalLayout->addWidget(widget_6);

        widget_7 = new QWidget(verticalWidget);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setMinimumSize(QSize(0, 45));
        horizontalLayout_7 = new QHBoxLayout(widget_7);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 0, -1, 0);
        label_7 = new QLabel(widget_7);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        horizontalLayout_7->addWidget(label_7);

        comboBox_5 = new QComboBox(widget_7);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setMinimumSize(QSize(0, 30));
        QFont font1;
        comboBox_5->setFont(font1);
        comboBox_5->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));

        horizontalLayout_7->addWidget(comboBox_5);

        label_12 = new QLabel(widget_7);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);

        horizontalLayout_7->addWidget(label_12);

        groupBox_4 = new QGroupBox(widget_7);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setStyleSheet(QLatin1String("QGroupBox#groupBox_4{\n"
"	border-style:solid 0px #000\n"
"}"));
        horizontalLayout_11 = new QHBoxLayout(groupBox_4);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        comboBox_6 = new QComboBox(groupBox_4);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));
        comboBox_6->setMinimumSize(QSize(0, 30));
        comboBox_6->setFont(font1);
        comboBox_6->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));

        horizontalLayout_11->addWidget(comboBox_6);

        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 30));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton#pushButton_2 {\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/setImage/add_category_normal.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_2:pressed {\n"
"	border-image: url(:/setImage/add_category_press.png);\n"
"}"));

        horizontalLayout_11->addWidget(pushButton_2);

        horizontalLayout_11->setStretch(0, 120);
        horizontalLayout_11->setStretch(1, 60);

        horizontalLayout_7->addWidget(groupBox_4);

        horizontalLayout_7->setStretch(0, 80);
        horizontalLayout_7->setStretch(1, 180);
        horizontalLayout_7->setStretch(2, 80);
        horizontalLayout_7->setStretch(3, 180);

        verticalLayout->addWidget(widget_7);

        widget_8 = new QWidget(verticalWidget);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(0, 45));
        horizontalLayout_8 = new QHBoxLayout(widget_8);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(widget_8);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout_8->addWidget(label_8);

        pricingScaleType = new QComboBox(widget_8);
        pricingScaleType->setObjectName(QStringLiteral("pricingScaleType"));
        pricingScaleType->setMinimumSize(QSize(0, 30));
        pricingScaleType->setFont(font1);
        pricingScaleType->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));

        horizontalLayout_8->addWidget(pricingScaleType);

        label_13 = new QLabel(widget_8);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        horizontalLayout_8->addWidget(label_13);

        pricingScalePort = new QComboBox(widget_8);
        pricingScalePort->setObjectName(QStringLiteral("pricingScalePort"));
        pricingScalePort->setMinimumSize(QSize(0, 30));
        pricingScalePort->setFont(font1);
        pricingScalePort->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));

        horizontalLayout_8->addWidget(pricingScalePort);

        horizontalLayout_8->setStretch(0, 80);
        horizontalLayout_8->setStretch(1, 180);
        horizontalLayout_8->setStretch(2, 80);
        horizontalLayout_8->setStretch(3, 180);

        verticalLayout->addWidget(widget_8);

        verticalSpacer = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addWidget(verticalWidget);


        retranslateUi(DeviceSetPage);

        QMetaObject::connectSlotsByName(DeviceSetPage);
    } // setupUi

    void retranslateUi(QWidget *DeviceSetPage)
    {
        DeviceSetPage->setWindowTitle(QApplication::translate("DeviceSetPage", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("DeviceSetPage", "\344\270\273\346\234\272\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        groupBox->setTitle(QString());
        typeButton1->setText(QApplication::translate("DeviceSetPage", "PC\344\270\200\344\275\223\347\247\244", Q_NULLPTR));
        typeButton2->setText(QApplication::translate("DeviceSetPage", "\347\273\204\350\243\205\346\230\276\347\244\272\345\231\250", Q_NULLPTR));
        label_9->setText(QApplication::translate("DeviceSetPage", "\344\270\273\346\234\272\345\236\213\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("DeviceSetPage", "\346\211\223\345\215\260\346\234\272\345\236\213\345\217\267\357\274\232", Q_NULLPTR));
        groupBox_5->setTitle(QString());
        pushButton->setText(QApplication::translate("DeviceSetPage", "\346\265\213\350\257\225", Q_NULLPTR));
        label_10->setText(QApplication::translate("DeviceSetPage", "\346\230\257\345\220\246\346\211\223\345\215\260:", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        isPrintButton_1->setText(QApplication::translate("DeviceSetPage", "\346\230\257", Q_NULLPTR));
        isPrintButton_2->setText(QApplication::translate("DeviceSetPage", "\345\220\246", Q_NULLPTR));
        label_4->setText(QApplication::translate("DeviceSetPage", "\345\256\242\346\230\276\345\236\213\345\217\267\357\274\232", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        modeButton_1->setText(QApplication::translate("DeviceSetPage", "\346\227\240\345\256\242\346\230\276\350\256\276\345\244\207", Q_NULLPTR));
        modeButton_2->setText(QApplication::translate("DeviceSetPage", "\346\225\260\345\255\227\345\256\242\346\230\276", Q_NULLPTR));
        modeButton_3->setText(QApplication::translate("DeviceSetPage", "\350\213\261\346\226\207\345\256\242\346\230\276", Q_NULLPTR));
        modeButton_4->setText(QApplication::translate("DeviceSetPage", "\344\270\255\346\226\207\345\256\242\346\230\276", Q_NULLPTR));
        modeButton_5->setText(QApplication::translate("DeviceSetPage", "\345\275\251\345\261\217\345\256\242\346\230\276", Q_NULLPTR));
        label_3->setText(QApplication::translate("DeviceSetPage", "\345\256\242\346\230\276\347\261\273\345\236\213\357\274\232 ", Q_NULLPTR));
        label_11->setText(QApplication::translate("DeviceSetPage", "\345\256\242\346\230\276\347\253\257\345\217\243\357\274\232 ", Q_NULLPTR));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("DeviceSetPage", "com1", Q_NULLPTR)
         << QApplication::translate("DeviceSetPage", "com2", Q_NULLPTR)
         << QApplication::translate("DeviceSetPage", "com3", Q_NULLPTR)
         << QApplication::translate("DeviceSetPage", "com4", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("DeviceSetPage", "\346\200\273\351\203\250\344\270\212\344\274\240\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("DeviceSetPage", "\346\234\254\345\234\260\344\270\212\344\274\240\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("DeviceSetPage", "\350\257\273\345\215\241\345\231\250\345\236\213\345\217\267\357\274\232", Q_NULLPTR));
        label_12->setText(QApplication::translate("DeviceSetPage", "\350\257\273\345\215\241\345\231\250\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        groupBox_4->setTitle(QString());
        pushButton_2->setText(QApplication::translate("DeviceSetPage", "\346\265\213\350\257\225", Q_NULLPTR));
        label_8->setText(QApplication::translate("DeviceSetPage", "\347\224\265\345\255\220\347\247\244\345\236\213\345\217\267\357\274\232", Q_NULLPTR));
        pricingScaleType->clear();
        pricingScaleType->insertItems(0, QStringList()
         << QApplication::translate("DeviceSetPage", "\345\244\247\345\215\216", Q_NULLPTR)
         << QApplication::translate("DeviceSetPage", "\345\207\257\345\243\253", Q_NULLPTR)
         << QApplication::translate("DeviceSetPage", "\345\257\272\345\262\227", Q_NULLPTR)
         << QApplication::translate("DeviceSetPage", "\350\277\252\345\256\235", Q_NULLPTR)
         << QApplication::translate("DeviceSetPage", "\346\211\230\345\210\251\345\244\232", Q_NULLPTR)
        );
        label_13->setText(QApplication::translate("DeviceSetPage", "\347\224\265\345\255\220\347\247\244\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        pricingScalePort->clear();
        pricingScalePort->insertItems(0, QStringList()
         << QApplication::translate("DeviceSetPage", "com1", Q_NULLPTR)
         << QApplication::translate("DeviceSetPage", "com2", Q_NULLPTR)
         << QApplication::translate("DeviceSetPage", "com3", Q_NULLPTR)
         << QApplication::translate("DeviceSetPage", "com4", Q_NULLPTR)
         << QApplication::translate("DeviceSetPage", "com5", Q_NULLPTR)
         << QApplication::translate("DeviceSetPage", "com6", Q_NULLPTR)
         << QApplication::translate("DeviceSetPage", "com7", Q_NULLPTR)
         << QApplication::translate("DeviceSetPage", "com8", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class DeviceSetPage: public Ui_DeviceSetPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICESETPAGE_H
