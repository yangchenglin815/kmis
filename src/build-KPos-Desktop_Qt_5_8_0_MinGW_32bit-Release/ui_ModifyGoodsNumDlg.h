/********************************************************************************
** Form generated from reading UI file 'ModifyGoodsNumDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYGOODSNUMDLG_H
#define UI_MODIFYGOODSNUMDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>
#include <WndDigitalKeyboard.h>

QT_BEGIN_NAMESPACE

class Ui_ModifyGoodsNumDlg
{
public:
    QGridLayout *gridLayout_3;
    TitleBarWidget *titleBarWidget;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QWidget *widget_4;
    QWidget *widget_5;
    QLabel *goodsNameLabel;
    QLabel *goodsNameValueLabel;
    QLabel *oldNumLabel;
    QLabel *oldNumValueLabel;
    QWidget *widget_6;
    QLabel *newNumLabel;
    QLineEdit *newNumEdit;
    QPushButton *commitButton;
    QLabel *newAmountLabel;
    QLineEdit *newAmountEdit;
    QFrame *line;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    WndDigitalKeyboard *DigitalKeyWnd;

    void setupUi(QDialog *ModifyGoodsNumDlg)
    {
        if (ModifyGoodsNumDlg->objectName().isEmpty())
            ModifyGoodsNumDlg->setObjectName(QStringLiteral("ModifyGoodsNumDlg"));
        ModifyGoodsNumDlg->resize(646, 380);
        ModifyGoodsNumDlg->setMinimumSize(QSize(646, 380));
        ModifyGoodsNumDlg->setStyleSheet(QLatin1String("QWidget#ModifyGoodsNumDlg {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        gridLayout_3 = new QGridLayout(ModifyGoodsNumDlg);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        titleBarWidget = new TitleBarWidget(ModifyGoodsNumDlg);
        titleBarWidget->setObjectName(QStringLiteral("titleBarWidget"));
        titleBarWidget->setMinimumSize(QSize(0, 40));
        titleBarWidget->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(titleBarWidget, 0, 0, 1, 3);

        widget_2 = new QWidget(ModifyGoodsNumDlg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(315, 340));
        widget_2->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(14, 12, 13, 24);
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(284, 305));
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(0, 0, 291, 91));
        widget_5->setMinimumSize(QSize(284, 87));
        widget_5->setStyleSheet(QStringLiteral("background-color: rgb(250, 250, 250);"));
        goodsNameLabel = new QLabel(widget_5);
        goodsNameLabel->setObjectName(QStringLiteral("goodsNameLabel"));
        goodsNameLabel->setGeometry(QRect(16, 23, 70, 16));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(goodsNameLabel->sizePolicy().hasHeightForWidth());
        goodsNameLabel->setSizePolicy(sizePolicy);
        QFont font;
        goodsNameLabel->setFont(font);
        goodsNameLabel->setLayoutDirection(Qt::LeftToRight);
        goodsNameLabel->setStyleSheet(QLatin1String("QLabel#goodsNameLabel {\n"
"	font-size: 14px;\n"
"	color: rgb(51, 51, 51);\n"
"}"));
        goodsNameLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        goodsNameValueLabel = new QLabel(widget_5);
        goodsNameValueLabel->setObjectName(QStringLiteral("goodsNameValueLabel"));
        goodsNameValueLabel->setGeometry(QRect(90, 20, 150, 20));
        goodsNameValueLabel->setFont(font);
        goodsNameValueLabel->setStyleSheet(QLatin1String("QLabel#goodsNameValueLabel {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"}\n"
""));
        oldNumLabel = new QLabel(widget_5);
        oldNumLabel->setObjectName(QStringLiteral("oldNumLabel"));
        oldNumLabel->setGeometry(QRect(16, 52, 70, 16));
        oldNumLabel->setFont(font);
        oldNumLabel->setStyleSheet(QLatin1String("QLabel#oldNumLabel {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"}\n"
""));
        oldNumLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        oldNumValueLabel = new QLabel(widget_5);
        oldNumValueLabel->setObjectName(QStringLiteral("oldNumValueLabel"));
        oldNumValueLabel->setGeometry(QRect(80, 50, 150, 20));
        oldNumValueLabel->setFont(font);
        oldNumValueLabel->setStyleSheet(QLatin1String("QLabel#oldNumValueLabel {\n"
"	font-size:16px;\n"
"	color: rgb(51, 51, 51);\n"
"}\n"
""));
        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(0, 90, 291, 218));
        widget_6->setMinimumSize(QSize(284, 218));
        widget_6->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        newNumLabel = new QLabel(widget_6);
        newNumLabel->setObjectName(QStringLiteral("newNumLabel"));
        newNumLabel->setGeometry(QRect(20, 21, 61, 31));
        newNumLabel->setFont(font);
        newNumLabel->setStyleSheet(QLatin1String("QLabel#newNumLabel {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"}\n"
""));
        newNumLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        newNumEdit = new QLineEdit(widget_6);
        newNumEdit->setObjectName(QStringLiteral("newNumEdit"));
        newNumEdit->setGeometry(QRect(80, 21, 181, 31));
        newNumEdit->setMinimumSize(QSize(90, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        newNumEdit->setFont(font1);
        newNumEdit->setStyleSheet(QLatin1String("QLabel#newNumEdit {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"	padding-left:10px;\n"
"}\n"
""));
        commitButton = new QPushButton(widget_6);
        commitButton->setObjectName(QStringLiteral("commitButton"));
        commitButton->setGeometry(QRect(19, 156, 245, 43));
        commitButton->setMinimumSize(QSize(245, 43));
        commitButton->setFont(font);
        commitButton->setFocusPolicy(Qt::NoFocus);
        commitButton->setStyleSheet(QLatin1String("QPushButton#commitButton {\n"
"	color: rgb(255, 255, 255);\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#commitButton:pressed {\n"
"	border-image:url(:/shareImages/sure_press.png)\n"
"}\n"
""));
        newAmountLabel = new QLabel(widget_6);
        newAmountLabel->setObjectName(QStringLiteral("newAmountLabel"));
        newAmountLabel->setGeometry(QRect(20, 80, 61, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        newAmountLabel->setFont(font2);
        newAmountLabel->setStyleSheet(QLatin1String("QLabel#newAmount {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"}\n"
""));
        newAmountLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        newAmountEdit = new QLineEdit(widget_6);
        newAmountEdit->setObjectName(QStringLiteral("newAmountEdit"));
        newAmountEdit->setEnabled(false);
        newAmountEdit->setGeometry(QRect(80, 80, 181, 31));
        newAmountEdit->setMinimumSize(QSize(90, 31));
        newAmountEdit->setFont(font1);
        newAmountEdit->setStyleSheet(QLatin1String("QLabel#newAmountEdit {\n"
"	font-size:14px;\n"
"	color: rgb(51, 51, 51);\n"
"	padding-left:10px;\n"
"}\n"
""));

        gridLayout->addWidget(widget_4, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget_2, 1, 0, 1, 1);

        line = new QFrame(ModifyGoodsNumDlg);
        line->setObjectName(QStringLiteral("line"));
        line->setMinimumSize(QSize(2, 340));
        line->setMaximumSize(QSize(2, 16777215));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 1, 1, 1, 1);

        widget_3 = new QWidget(ModifyGoodsNumDlg);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(325, 340));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(14, 12, 12, 24);
        DigitalKeyWnd = new WndDigitalKeyboard(widget_3);
        DigitalKeyWnd->setObjectName(QStringLiteral("DigitalKeyWnd"));
        DigitalKeyWnd->setMinimumSize(QSize(303, 303));

        gridLayout_2->addWidget(DigitalKeyWnd, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget_3, 1, 2, 1, 1);


        retranslateUi(ModifyGoodsNumDlg);

        QMetaObject::connectSlotsByName(ModifyGoodsNumDlg);
    } // setupUi

    void retranslateUi(QDialog *ModifyGoodsNumDlg)
    {
        ModifyGoodsNumDlg->setWindowTitle(QApplication::translate("ModifyGoodsNumDlg", "ModifyGoodsNumDlg", Q_NULLPTR));
        goodsNameLabel->setText(QApplication::translate("ModifyGoodsNumDlg", "\345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        goodsNameValueLabel->setText(QApplication::translate("ModifyGoodsNumDlg", "\346\227\240\347\261\275\345\244\247\350\245\277\347\223\234", Q_NULLPTR));
        oldNumLabel->setText(QApplication::translate("ModifyGoodsNumDlg", "\345\216\237\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        oldNumValueLabel->setText(QApplication::translate("ModifyGoodsNumDlg", "1", Q_NULLPTR));
        newNumLabel->setText(QApplication::translate("ModifyGoodsNumDlg", "\347\216\260\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        commitButton->setText(QApplication::translate("ModifyGoodsNumDlg", "\346\217\220\344\272\244", Q_NULLPTR));
        newAmountLabel->setText(QApplication::translate("ModifyGoodsNumDlg", "\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModifyGoodsNumDlg: public Ui_ModifyGoodsNumDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYGOODSNUMDLG_H
