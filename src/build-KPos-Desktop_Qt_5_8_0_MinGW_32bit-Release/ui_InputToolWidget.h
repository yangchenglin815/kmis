/********************************************************************************
** Form generated from reading UI file 'InputToolWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTTOOLWIDGET_H
#define UI_INPUTTOOLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputToolWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *topWgt;
    QVBoxLayout *verticalLayout_2;
    QWidget *inputWgt;
    QHBoxLayout *horizontalLayout_7;
    QLabel *titleLabel;
    QLabel *inputLabel;
    QPushButton *upPageBtn;
    QPushButton *downPageBtn;
    QWidget *inputItemWgt;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lblCh0;
    QLabel *lblCh1;
    QLabel *lblCh2;
    QLabel *lblCh3;
    QLabel *lblCh4;
    QLabel *lblCh5;
    QLabel *lblCh6;
    QLabel *lblCh7;
    QLabel *lblCh8;
    QLabel *lblCh9;
    QWidget *skinWidget;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *qButton;
    QPushButton *wButton;
    QPushButton *eButton;
    QPushButton *rButton;
    QPushButton *tButton;
    QPushButton *yButton;
    QPushButton *uButton;
    QPushButton *iButton;
    QPushButton *oButton;
    QPushButton *pButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *decorateLeftButton;
    QPushButton *aButton;
    QPushButton *jButton;
    QPushButton *fButton;
    QPushButton *kButton;
    QPushButton *dButton;
    QPushButton *hButton;
    QPushButton *sButton;
    QPushButton *gButton;
    QPushButton *lButton;
    QPushButton *decorateRightButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *upperWordButton;
    QPushButton *zButton;
    QPushButton *xButton;
    QPushButton *cButton;
    QPushButton *vButton;
    QPushButton *bButton;
    QPushButton *nButton;
    QPushButton *mButton;
    QPushButton *deleteWordButton;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *changeInputMethodButton;
    QPushButton *confirmButton;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QPushButton *num1Button;
    QPushButton *num2Button;
    QPushButton *num3Button;
    QPushButton *num4Button;
    QPushButton *num5Button;
    QPushButton *num6Button;
    QPushButton *num7Button;
    QPushButton *num8Button;
    QPushButton *num9Button;
    QPushButton *dotButton;
    QPushButton *num0Button;
    QPushButton *deleteWord2Button;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *InputToolWidget)
    {
        if (InputToolWidget->objectName().isEmpty())
            InputToolWidget->setObjectName(QStringLiteral("InputToolWidget"));
        InputToolWidget->resize(708, 345);
        InputToolWidget->setMaximumSize(QSize(16777215, 16777215));
        InputToolWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(InputToolWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        topWgt = new QWidget(InputToolWidget);
        topWgt->setObjectName(QStringLiteral("topWgt"));
        topWgt->setStyleSheet(QLatin1String("#topWgt{\n"
"   border-image: url(:/keyboardImage/keyboardBackground.png);\n"
"}\n"
"QLabel{\n"
"font:15px;\n"
"color:#ffffff;\n"
"}\n"
"\n"
"QPushButton{\n"
"   border:none;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(topWgt);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        inputWgt = new QWidget(topWgt);
        inputWgt->setObjectName(QStringLiteral("inputWgt"));
        inputWgt->setStyleSheet(QStringLiteral(""));
        horizontalLayout_7 = new QHBoxLayout(inputWgt);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        titleLabel = new QLabel(inputWgt);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setMinimumSize(QSize(91, 0));
        titleLabel->setMaximumSize(QSize(91, 16777215));

        horizontalLayout_7->addWidget(titleLabel);

        inputLabel = new QLabel(inputWgt);
        inputLabel->setObjectName(QStringLiteral("inputLabel"));

        horizontalLayout_7->addWidget(inputLabel);

        upPageBtn = new QPushButton(inputWgt);
        upPageBtn->setObjectName(QStringLiteral("upPageBtn"));
        upPageBtn->setMinimumSize(QSize(30, 30));
        upPageBtn->setMaximumSize(QSize(30, 30));
        upPageBtn->setStyleSheet(QLatin1String("#upPageBtn{\n"
"   image:url(:/keyboardImage/upPage.png);\n"
"}"));

        horizontalLayout_7->addWidget(upPageBtn);

        downPageBtn = new QPushButton(inputWgt);
        downPageBtn->setObjectName(QStringLiteral("downPageBtn"));
        downPageBtn->setMinimumSize(QSize(30, 30));
        downPageBtn->setMaximumSize(QSize(30, 30));
        downPageBtn->setStyleSheet(QLatin1String("#downPageBtn{\n"
"    image:url(:/keyboardImage/downPage.png);\n"
"}"));

        horizontalLayout_7->addWidget(downPageBtn);


        verticalLayout_2->addWidget(inputWgt);

        inputItemWgt = new QWidget(topWgt);
        inputItemWgt->setObjectName(QStringLiteral("inputItemWgt"));
        inputItemWgt->setStyleSheet(QStringLiteral(""));
        horizontalLayout_6 = new QHBoxLayout(inputItemWgt);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        lblCh0 = new QLabel(inputItemWgt);
        lblCh0->setObjectName(QStringLiteral("lblCh0"));

        horizontalLayout_6->addWidget(lblCh0);

        lblCh1 = new QLabel(inputItemWgt);
        lblCh1->setObjectName(QStringLiteral("lblCh1"));

        horizontalLayout_6->addWidget(lblCh1);

        lblCh2 = new QLabel(inputItemWgt);
        lblCh2->setObjectName(QStringLiteral("lblCh2"));

        horizontalLayout_6->addWidget(lblCh2);

        lblCh3 = new QLabel(inputItemWgt);
        lblCh3->setObjectName(QStringLiteral("lblCh3"));

        horizontalLayout_6->addWidget(lblCh3);

        lblCh4 = new QLabel(inputItemWgt);
        lblCh4->setObjectName(QStringLiteral("lblCh4"));

        horizontalLayout_6->addWidget(lblCh4);

        lblCh5 = new QLabel(inputItemWgt);
        lblCh5->setObjectName(QStringLiteral("lblCh5"));

        horizontalLayout_6->addWidget(lblCh5);

        lblCh6 = new QLabel(inputItemWgt);
        lblCh6->setObjectName(QStringLiteral("lblCh6"));

        horizontalLayout_6->addWidget(lblCh6);

        lblCh7 = new QLabel(inputItemWgt);
        lblCh7->setObjectName(QStringLiteral("lblCh7"));

        horizontalLayout_6->addWidget(lblCh7);

        lblCh8 = new QLabel(inputItemWgt);
        lblCh8->setObjectName(QStringLiteral("lblCh8"));

        horizontalLayout_6->addWidget(lblCh8);

        lblCh9 = new QLabel(inputItemWgt);
        lblCh9->setObjectName(QStringLiteral("lblCh9"));

        horizontalLayout_6->addWidget(lblCh9);


        verticalLayout_2->addWidget(inputItemWgt);


        verticalLayout_3->addWidget(topWgt);

        skinWidget = new QWidget(InputToolWidget);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setMinimumSize(QSize(0, 226));
        skinWidget->setMaximumSize(QSize(16777215, 226));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget\n"
"{\n"
"border-image: url(:/keyboardImage/keyboardBackground.png);\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(skinWidget);
        horizontalLayout_5->setSpacing(20);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 6, -1, 12);
        widget = new QWidget(skinWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        qButton = new QPushButton(widget);
        qButton->setObjectName(QStringLiteral("qButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qButton->sizePolicy().hasHeightForWidth());
        qButton->setSizePolicy(sizePolicy);
        qButton->setMinimumSize(QSize(50, 50));
        qButton->setMaximumSize(QSize(50, 50));
        qButton->setFocusPolicy(Qt::NoFocus);
        qButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout->addWidget(qButton);

        wButton = new QPushButton(widget);
        wButton->setObjectName(QStringLiteral("wButton"));
        sizePolicy.setHeightForWidth(wButton->sizePolicy().hasHeightForWidth());
        wButton->setSizePolicy(sizePolicy);
        wButton->setMinimumSize(QSize(50, 50));
        wButton->setMaximumSize(QSize(50, 50));
        wButton->setFocusPolicy(Qt::NoFocus);
        wButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout->addWidget(wButton);

        eButton = new QPushButton(widget);
        eButton->setObjectName(QStringLiteral("eButton"));
        sizePolicy.setHeightForWidth(eButton->sizePolicy().hasHeightForWidth());
        eButton->setSizePolicy(sizePolicy);
        eButton->setMinimumSize(QSize(50, 50));
        eButton->setMaximumSize(QSize(50, 50));
        eButton->setFocusPolicy(Qt::NoFocus);
        eButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout->addWidget(eButton);

        rButton = new QPushButton(widget);
        rButton->setObjectName(QStringLiteral("rButton"));
        sizePolicy.setHeightForWidth(rButton->sizePolicy().hasHeightForWidth());
        rButton->setSizePolicy(sizePolicy);
        rButton->setMinimumSize(QSize(50, 50));
        rButton->setMaximumSize(QSize(50, 50));
        rButton->setFocusPolicy(Qt::NoFocus);
        rButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout->addWidget(rButton);

        tButton = new QPushButton(widget);
        tButton->setObjectName(QStringLiteral("tButton"));
        sizePolicy.setHeightForWidth(tButton->sizePolicy().hasHeightForWidth());
        tButton->setSizePolicy(sizePolicy);
        tButton->setMinimumSize(QSize(50, 50));
        tButton->setMaximumSize(QSize(50, 50));
        tButton->setFocusPolicy(Qt::NoFocus);
        tButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout->addWidget(tButton);

        yButton = new QPushButton(widget);
        yButton->setObjectName(QStringLiteral("yButton"));
        sizePolicy.setHeightForWidth(yButton->sizePolicy().hasHeightForWidth());
        yButton->setSizePolicy(sizePolicy);
        yButton->setMinimumSize(QSize(50, 50));
        yButton->setMaximumSize(QSize(50, 50));
        yButton->setFocusPolicy(Qt::NoFocus);
        yButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout->addWidget(yButton);

        uButton = new QPushButton(widget);
        uButton->setObjectName(QStringLiteral("uButton"));
        sizePolicy.setHeightForWidth(uButton->sizePolicy().hasHeightForWidth());
        uButton->setSizePolicy(sizePolicy);
        uButton->setMinimumSize(QSize(50, 50));
        uButton->setMaximumSize(QSize(50, 50));
        uButton->setFocusPolicy(Qt::NoFocus);
        uButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout->addWidget(uButton);

        iButton = new QPushButton(widget);
        iButton->setObjectName(QStringLiteral("iButton"));
        sizePolicy.setHeightForWidth(iButton->sizePolicy().hasHeightForWidth());
        iButton->setSizePolicy(sizePolicy);
        iButton->setMinimumSize(QSize(50, 50));
        iButton->setMaximumSize(QSize(50, 50));
        iButton->setFocusPolicy(Qt::NoFocus);
        iButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout->addWidget(iButton);

        oButton = new QPushButton(widget);
        oButton->setObjectName(QStringLiteral("oButton"));
        sizePolicy.setHeightForWidth(oButton->sizePolicy().hasHeightForWidth());
        oButton->setSizePolicy(sizePolicy);
        oButton->setMinimumSize(QSize(50, 50));
        oButton->setMaximumSize(QSize(50, 50));
        oButton->setFocusPolicy(Qt::NoFocus);
        oButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout->addWidget(oButton);

        pButton = new QPushButton(widget);
        pButton->setObjectName(QStringLiteral("pButton"));
        sizePolicy.setHeightForWidth(pButton->sizePolicy().hasHeightForWidth());
        pButton->setSizePolicy(sizePolicy);
        pButton->setMinimumSize(QSize(50, 50));
        pButton->setMaximumSize(QSize(50, 50));
        pButton->setFocusPolicy(Qt::NoFocus);
        pButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout->addWidget(pButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        decorateLeftButton = new QPushButton(widget);
        decorateLeftButton->setObjectName(QStringLiteral("decorateLeftButton"));
        decorateLeftButton->setMinimumSize(QSize(25, 50));
        decorateLeftButton->setMaximumSize(QSize(25, 50));
        decorateLeftButton->setFocusPolicy(Qt::NoFocus);
        decorateLeftButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_2->addWidget(decorateLeftButton);

        aButton = new QPushButton(widget);
        aButton->setObjectName(QStringLiteral("aButton"));
        sizePolicy.setHeightForWidth(aButton->sizePolicy().hasHeightForWidth());
        aButton->setSizePolicy(sizePolicy);
        aButton->setMinimumSize(QSize(50, 50));
        aButton->setMaximumSize(QSize(50, 50));
        aButton->setFocusPolicy(Qt::NoFocus);
        aButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_2->addWidget(aButton);

        jButton = new QPushButton(widget);
        jButton->setObjectName(QStringLiteral("jButton"));
        sizePolicy.setHeightForWidth(jButton->sizePolicy().hasHeightForWidth());
        jButton->setSizePolicy(sizePolicy);
        jButton->setMinimumSize(QSize(50, 50));
        jButton->setMaximumSize(QSize(50, 50));
        jButton->setFocusPolicy(Qt::NoFocus);
        jButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_2->addWidget(jButton);

        fButton = new QPushButton(widget);
        fButton->setObjectName(QStringLiteral("fButton"));
        sizePolicy.setHeightForWidth(fButton->sizePolicy().hasHeightForWidth());
        fButton->setSizePolicy(sizePolicy);
        fButton->setMinimumSize(QSize(50, 50));
        fButton->setMaximumSize(QSize(50, 50));
        fButton->setFocusPolicy(Qt::NoFocus);
        fButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_2->addWidget(fButton);

        kButton = new QPushButton(widget);
        kButton->setObjectName(QStringLiteral("kButton"));
        sizePolicy.setHeightForWidth(kButton->sizePolicy().hasHeightForWidth());
        kButton->setSizePolicy(sizePolicy);
        kButton->setMinimumSize(QSize(50, 50));
        kButton->setMaximumSize(QSize(50, 50));
        kButton->setFocusPolicy(Qt::NoFocus);
        kButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_2->addWidget(kButton);

        dButton = new QPushButton(widget);
        dButton->setObjectName(QStringLiteral("dButton"));
        sizePolicy.setHeightForWidth(dButton->sizePolicy().hasHeightForWidth());
        dButton->setSizePolicy(sizePolicy);
        dButton->setMinimumSize(QSize(50, 50));
        dButton->setMaximumSize(QSize(50, 50));
        dButton->setFocusPolicy(Qt::NoFocus);
        dButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_2->addWidget(dButton);

        hButton = new QPushButton(widget);
        hButton->setObjectName(QStringLiteral("hButton"));
        sizePolicy.setHeightForWidth(hButton->sizePolicy().hasHeightForWidth());
        hButton->setSizePolicy(sizePolicy);
        hButton->setMinimumSize(QSize(50, 50));
        hButton->setMaximumSize(QSize(50, 50));
        hButton->setFocusPolicy(Qt::NoFocus);
        hButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_2->addWidget(hButton);

        sButton = new QPushButton(widget);
        sButton->setObjectName(QStringLiteral("sButton"));
        sizePolicy.setHeightForWidth(sButton->sizePolicy().hasHeightForWidth());
        sButton->setSizePolicy(sizePolicy);
        sButton->setMinimumSize(QSize(50, 50));
        sButton->setMaximumSize(QSize(50, 50));
        sButton->setFocusPolicy(Qt::NoFocus);
        sButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_2->addWidget(sButton);

        gButton = new QPushButton(widget);
        gButton->setObjectName(QStringLiteral("gButton"));
        sizePolicy.setHeightForWidth(gButton->sizePolicy().hasHeightForWidth());
        gButton->setSizePolicy(sizePolicy);
        gButton->setMinimumSize(QSize(50, 50));
        gButton->setMaximumSize(QSize(50, 50));
        gButton->setFocusPolicy(Qt::NoFocus);
        gButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_2->addWidget(gButton);

        lButton = new QPushButton(widget);
        lButton->setObjectName(QStringLiteral("lButton"));
        sizePolicy.setHeightForWidth(lButton->sizePolicy().hasHeightForWidth());
        lButton->setSizePolicy(sizePolicy);
        lButton->setMinimumSize(QSize(50, 50));
        lButton->setMaximumSize(QSize(50, 50));
        lButton->setFocusPolicy(Qt::NoFocus);
        lButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_2->addWidget(lButton);

        decorateRightButton = new QPushButton(widget);
        decorateRightButton->setObjectName(QStringLiteral("decorateRightButton"));
        decorateRightButton->setMinimumSize(QSize(25, 50));
        decorateRightButton->setMaximumSize(QSize(25, 50));
        decorateRightButton->setFocusPolicy(Qt::NoFocus);
        decorateRightButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_2->addWidget(decorateRightButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        upperWordButton = new QPushButton(widget);
        upperWordButton->setObjectName(QStringLiteral("upperWordButton"));
        upperWordButton->setMinimumSize(QSize(75, 50));
        upperWordButton->setFocusPolicy(Qt::NoFocus);
        upperWordButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_3->addWidget(upperWordButton);

        zButton = new QPushButton(widget);
        zButton->setObjectName(QStringLiteral("zButton"));
        sizePolicy.setHeightForWidth(zButton->sizePolicy().hasHeightForWidth());
        zButton->setSizePolicy(sizePolicy);
        zButton->setMinimumSize(QSize(50, 50));
        zButton->setMaximumSize(QSize(50, 50));
        zButton->setFocusPolicy(Qt::NoFocus);
        zButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_3->addWidget(zButton);

        xButton = new QPushButton(widget);
        xButton->setObjectName(QStringLiteral("xButton"));
        sizePolicy.setHeightForWidth(xButton->sizePolicy().hasHeightForWidth());
        xButton->setSizePolicy(sizePolicy);
        xButton->setMinimumSize(QSize(50, 50));
        xButton->setMaximumSize(QSize(50, 50));
        xButton->setFocusPolicy(Qt::NoFocus);
        xButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_3->addWidget(xButton);

        cButton = new QPushButton(widget);
        cButton->setObjectName(QStringLiteral("cButton"));
        sizePolicy.setHeightForWidth(cButton->sizePolicy().hasHeightForWidth());
        cButton->setSizePolicy(sizePolicy);
        cButton->setMinimumSize(QSize(50, 50));
        cButton->setMaximumSize(QSize(50, 50));
        cButton->setFocusPolicy(Qt::NoFocus);
        cButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_3->addWidget(cButton);

        vButton = new QPushButton(widget);
        vButton->setObjectName(QStringLiteral("vButton"));
        sizePolicy.setHeightForWidth(vButton->sizePolicy().hasHeightForWidth());
        vButton->setSizePolicy(sizePolicy);
        vButton->setMinimumSize(QSize(50, 50));
        vButton->setMaximumSize(QSize(50, 50));
        vButton->setFocusPolicy(Qt::NoFocus);
        vButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_3->addWidget(vButton);

        bButton = new QPushButton(widget);
        bButton->setObjectName(QStringLiteral("bButton"));
        sizePolicy.setHeightForWidth(bButton->sizePolicy().hasHeightForWidth());
        bButton->setSizePolicy(sizePolicy);
        bButton->setMinimumSize(QSize(50, 50));
        bButton->setMaximumSize(QSize(50, 50));
        bButton->setFocusPolicy(Qt::NoFocus);
        bButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_3->addWidget(bButton);

        nButton = new QPushButton(widget);
        nButton->setObjectName(QStringLiteral("nButton"));
        sizePolicy.setHeightForWidth(nButton->sizePolicy().hasHeightForWidth());
        nButton->setSizePolicy(sizePolicy);
        nButton->setMinimumSize(QSize(50, 50));
        nButton->setMaximumSize(QSize(50, 50));
        nButton->setFocusPolicy(Qt::NoFocus);
        nButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_3->addWidget(nButton);

        mButton = new QPushButton(widget);
        mButton->setObjectName(QStringLiteral("mButton"));
        sizePolicy.setHeightForWidth(mButton->sizePolicy().hasHeightForWidth());
        mButton->setSizePolicy(sizePolicy);
        mButton->setMinimumSize(QSize(50, 50));
        mButton->setMaximumSize(QSize(50, 50));
        mButton->setFocusPolicy(Qt::NoFocus);
        mButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        horizontalLayout_3->addWidget(mButton);

        deleteWordButton = new QPushButton(widget);
        deleteWordButton->setObjectName(QStringLiteral("deleteWordButton"));
        deleteWordButton->setMinimumSize(QSize(75, 50));
        deleteWordButton->setFocusPolicy(Qt::NoFocus);
        deleteWordButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/digitalKeyboardImage/delete.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/delete_pressed.png);\n"
"}"));

        horizontalLayout_3->addWidget(deleteWordButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        changeInputMethodButton = new QPushButton(widget);
        changeInputMethodButton->setObjectName(QStringLiteral("changeInputMethodButton"));
        sizePolicy.setHeightForWidth(changeInputMethodButton->sizePolicy().hasHeightForWidth());
        changeInputMethodButton->setSizePolicy(sizePolicy);
        changeInputMethodButton->setMinimumSize(QSize(50, 50));
        changeInputMethodButton->setMaximumSize(QSize(50, 16777215));
        changeInputMethodButton->setFocusPolicy(Qt::NoFocus);
        changeInputMethodButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/digitalKeyboardImage/clear.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/clear_pressed.png);\n"
"}"));

        horizontalLayout_4->addWidget(changeInputMethodButton);

        confirmButton = new QPushButton(widget);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        sizePolicy.setHeightForWidth(confirmButton->sizePolicy().hasHeightForWidth());
        confirmButton->setSizePolicy(sizePolicy);
        confirmButton->setMinimumSize(QSize(0, 50));
        confirmButton->setMaximumSize(QSize(16777215, 50));
        confirmButton->setFocusPolicy(Qt::NoFocus);
        confirmButton->setStyleSheet(QLatin1String("QPushButton{\n"
"color:#ffffff;\n"
"font-size:16px;\n"
"border-image: url(:/loginImage/commonButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/loginImage/commonButtonPressed.png);\n"
"}"));

        horizontalLayout_4->addWidget(confirmButton);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addWidget(widget);

        widget_2 = new QWidget(skinWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 0));
        widget_2->setFocusPolicy(Qt::NoFocus);
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        num1Button = new QPushButton(widget_2);
        num1Button->setObjectName(QStringLiteral("num1Button"));
        sizePolicy.setHeightForWidth(num1Button->sizePolicy().hasHeightForWidth());
        num1Button->setSizePolicy(sizePolicy);
        num1Button->setMinimumSize(QSize(50, 50));
        num1Button->setMaximumSize(QSize(50, 50));
        num1Button->setFocusPolicy(Qt::NoFocus);
        num1Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num1Button, 0, 0, 1, 1);

        num2Button = new QPushButton(widget_2);
        num2Button->setObjectName(QStringLiteral("num2Button"));
        sizePolicy.setHeightForWidth(num2Button->sizePolicy().hasHeightForWidth());
        num2Button->setSizePolicy(sizePolicy);
        num2Button->setMinimumSize(QSize(50, 50));
        num2Button->setMaximumSize(QSize(50, 50));
        num2Button->setFocusPolicy(Qt::NoFocus);
        num2Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num2Button, 0, 1, 1, 1);

        num3Button = new QPushButton(widget_2);
        num3Button->setObjectName(QStringLiteral("num3Button"));
        sizePolicy.setHeightForWidth(num3Button->sizePolicy().hasHeightForWidth());
        num3Button->setSizePolicy(sizePolicy);
        num3Button->setMinimumSize(QSize(50, 50));
        num3Button->setMaximumSize(QSize(50, 50));
        num3Button->setFocusPolicy(Qt::NoFocus);
        num3Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num3Button, 0, 2, 1, 1);

        num4Button = new QPushButton(widget_2);
        num4Button->setObjectName(QStringLiteral("num4Button"));
        sizePolicy.setHeightForWidth(num4Button->sizePolicy().hasHeightForWidth());
        num4Button->setSizePolicy(sizePolicy);
        num4Button->setMinimumSize(QSize(50, 50));
        num4Button->setMaximumSize(QSize(50, 50));
        num4Button->setFocusPolicy(Qt::NoFocus);
        num4Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num4Button, 1, 0, 1, 1);

        num5Button = new QPushButton(widget_2);
        num5Button->setObjectName(QStringLiteral("num5Button"));
        sizePolicy.setHeightForWidth(num5Button->sizePolicy().hasHeightForWidth());
        num5Button->setSizePolicy(sizePolicy);
        num5Button->setMinimumSize(QSize(50, 50));
        num5Button->setMaximumSize(QSize(50, 50));
        num5Button->setFocusPolicy(Qt::NoFocus);
        num5Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num5Button, 1, 1, 1, 1);

        num6Button = new QPushButton(widget_2);
        num6Button->setObjectName(QStringLiteral("num6Button"));
        sizePolicy.setHeightForWidth(num6Button->sizePolicy().hasHeightForWidth());
        num6Button->setSizePolicy(sizePolicy);
        num6Button->setMinimumSize(QSize(50, 50));
        num6Button->setMaximumSize(QSize(50, 50));
        num6Button->setFocusPolicy(Qt::NoFocus);
        num6Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num6Button, 1, 2, 1, 1);

        num7Button = new QPushButton(widget_2);
        num7Button->setObjectName(QStringLiteral("num7Button"));
        sizePolicy.setHeightForWidth(num7Button->sizePolicy().hasHeightForWidth());
        num7Button->setSizePolicy(sizePolicy);
        num7Button->setMinimumSize(QSize(50, 50));
        num7Button->setMaximumSize(QSize(50, 50));
        num7Button->setFocusPolicy(Qt::NoFocus);
        num7Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num7Button, 2, 0, 1, 1);

        num8Button = new QPushButton(widget_2);
        num8Button->setObjectName(QStringLiteral("num8Button"));
        sizePolicy.setHeightForWidth(num8Button->sizePolicy().hasHeightForWidth());
        num8Button->setSizePolicy(sizePolicy);
        num8Button->setMinimumSize(QSize(50, 50));
        num8Button->setMaximumSize(QSize(50, 50));
        num8Button->setFocusPolicy(Qt::NoFocus);
        num8Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num8Button, 2, 1, 1, 1);

        num9Button = new QPushButton(widget_2);
        num9Button->setObjectName(QStringLiteral("num9Button"));
        sizePolicy.setHeightForWidth(num9Button->sizePolicy().hasHeightForWidth());
        num9Button->setSizePolicy(sizePolicy);
        num9Button->setMinimumSize(QSize(50, 50));
        num9Button->setMaximumSize(QSize(50, 50));
        num9Button->setFocusPolicy(Qt::NoFocus);
        num9Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num9Button, 2, 2, 1, 1);

        dotButton = new QPushButton(widget_2);
        dotButton->setObjectName(QStringLiteral("dotButton"));
        sizePolicy.setHeightForWidth(dotButton->sizePolicy().hasHeightForWidth());
        dotButton->setSizePolicy(sizePolicy);
        dotButton->setMinimumSize(QSize(50, 50));
        dotButton->setMaximumSize(QSize(50, 50));
        dotButton->setFocusPolicy(Qt::NoFocus);
        dotButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(dotButton, 3, 0, 1, 1);

        num0Button = new QPushButton(widget_2);
        num0Button->setObjectName(QStringLiteral("num0Button"));
        sizePolicy.setHeightForWidth(num0Button->sizePolicy().hasHeightForWidth());
        num0Button->setSizePolicy(sizePolicy);
        num0Button->setMinimumSize(QSize(50, 50));
        num0Button->setMaximumSize(QSize(50, 50));
        num0Button->setFocusPolicy(Qt::NoFocus);
        num0Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	font-size:20px;\n"
"	border-image: url(:/digitalKeyboardImage/numberKey.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num0Button, 3, 1, 1, 1);

        deleteWord2Button = new QPushButton(widget_2);
        deleteWord2Button->setObjectName(QStringLiteral("deleteWord2Button"));
        sizePolicy.setHeightForWidth(deleteWord2Button->sizePolicy().hasHeightForWidth());
        deleteWord2Button->setSizePolicy(sizePolicy);
        deleteWord2Button->setMinimumSize(QSize(50, 50));
        deleteWord2Button->setMaximumSize(QSize(50, 50));
        deleteWord2Button->setFocusPolicy(Qt::NoFocus);
        deleteWord2Button->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/digitalKeyboardImage/delete.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/digitalKeyboardImage/delete_pressed.png);\n"
"}"));

        gridLayout->addWidget(deleteWord2Button, 3, 2, 1, 1);


        horizontalLayout_5->addWidget(widget_2);


        verticalLayout_3->addWidget(skinWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(InputToolWidget);

        QMetaObject::connectSlotsByName(InputToolWidget);
    } // setupUi

    void retranslateUi(QWidget *InputToolWidget)
    {
        InputToolWidget->setWindowTitle(QApplication::translate("InputToolWidget", "Form", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("InputToolWidget", "\344\270\255\346\226\207\350\276\223\345\205\245\346\263\225", Q_NULLPTR));
        inputLabel->setText(QString());
        upPageBtn->setText(QString());
        downPageBtn->setText(QString());
        lblCh0->setText(QString());
        lblCh1->setText(QString());
        lblCh2->setText(QString());
        lblCh3->setText(QString());
        lblCh4->setText(QString());
        lblCh5->setText(QString());
        lblCh6->setText(QString());
        lblCh7->setText(QString());
        lblCh8->setText(QString());
        lblCh9->setText(QString());
        qButton->setText(QApplication::translate("InputToolWidget", "Q", Q_NULLPTR));
        wButton->setText(QApplication::translate("InputToolWidget", "W", Q_NULLPTR));
        eButton->setText(QApplication::translate("InputToolWidget", "E", Q_NULLPTR));
        rButton->setText(QApplication::translate("InputToolWidget", "R", Q_NULLPTR));
        tButton->setText(QApplication::translate("InputToolWidget", "T", Q_NULLPTR));
        yButton->setText(QApplication::translate("InputToolWidget", "Y", Q_NULLPTR));
        uButton->setText(QApplication::translate("InputToolWidget", "U", Q_NULLPTR));
        iButton->setText(QApplication::translate("InputToolWidget", "I", Q_NULLPTR));
        oButton->setText(QApplication::translate("InputToolWidget", "O", Q_NULLPTR));
        pButton->setText(QApplication::translate("InputToolWidget", "P", Q_NULLPTR));
        decorateLeftButton->setText(QString());
        aButton->setText(QApplication::translate("InputToolWidget", "A", Q_NULLPTR));
        jButton->setText(QApplication::translate("InputToolWidget", "J", Q_NULLPTR));
        fButton->setText(QApplication::translate("InputToolWidget", "F", Q_NULLPTR));
        kButton->setText(QApplication::translate("InputToolWidget", "K", Q_NULLPTR));
        dButton->setText(QApplication::translate("InputToolWidget", "D", Q_NULLPTR));
        hButton->setText(QApplication::translate("InputToolWidget", "H", Q_NULLPTR));
        sButton->setText(QApplication::translate("InputToolWidget", "S", Q_NULLPTR));
        gButton->setText(QApplication::translate("InputToolWidget", "G", Q_NULLPTR));
        lButton->setText(QApplication::translate("InputToolWidget", "L", Q_NULLPTR));
        decorateRightButton->setText(QString());
        upperWordButton->setText(QApplication::translate("InputToolWidget", "\350\213\261\346\226\207", Q_NULLPTR));
        zButton->setText(QApplication::translate("InputToolWidget", "Z", Q_NULLPTR));
        xButton->setText(QApplication::translate("InputToolWidget", "X", Q_NULLPTR));
        cButton->setText(QApplication::translate("InputToolWidget", "C", Q_NULLPTR));
        vButton->setText(QApplication::translate("InputToolWidget", "V", Q_NULLPTR));
        bButton->setText(QApplication::translate("InputToolWidget", "B", Q_NULLPTR));
        nButton->setText(QApplication::translate("InputToolWidget", "N", Q_NULLPTR));
        mButton->setText(QApplication::translate("InputToolWidget", "M", Q_NULLPTR));
        deleteWordButton->setText(QString());
        changeInputMethodButton->setText(QString());
        confirmButton->setText(QApplication::translate("InputToolWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        num1Button->setText(QApplication::translate("InputToolWidget", "1", Q_NULLPTR));
        num2Button->setText(QApplication::translate("InputToolWidget", "2", Q_NULLPTR));
        num3Button->setText(QApplication::translate("InputToolWidget", "3", Q_NULLPTR));
        num4Button->setText(QApplication::translate("InputToolWidget", "4", Q_NULLPTR));
        num5Button->setText(QApplication::translate("InputToolWidget", "5", Q_NULLPTR));
        num6Button->setText(QApplication::translate("InputToolWidget", "6", Q_NULLPTR));
        num7Button->setText(QApplication::translate("InputToolWidget", "7", Q_NULLPTR));
        num8Button->setText(QApplication::translate("InputToolWidget", "8", Q_NULLPTR));
        num9Button->setText(QApplication::translate("InputToolWidget", "9", Q_NULLPTR));
        dotButton->setText(QApplication::translate("InputToolWidget", ".", Q_NULLPTR));
        num0Button->setText(QApplication::translate("InputToolWidget", "0", Q_NULLPTR));
        deleteWord2Button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InputToolWidget: public Ui_InputToolWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTTOOLWIDGET_H
