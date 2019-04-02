/********************************************************************************
** Form generated from reading UI file 'BCSAddDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSADDDLG_H
#define UI_BCSADDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitleBarWidget.h"
#include "WndDigitalKeyboard.h"

QT_BEGIN_NAMESPACE

class Ui_BCSAddDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QLabel *label;
    QLabel *bcsCodeLabel;
    QFrame *frame;
    QLabel *label_21;
    QLabel *label_17;
    QLabel *label_19;
    QLineEdit *IPLineEdit;
    QPushButton *pushFrom;
    QComboBox *typeComboBox;
    QComboBox *goodsGroupComboBox;
    WndDigitalKeyboard *DigitalKeyWnd;

    void setupUi(QDialog *BCSAddDlg)
    {
        if (BCSAddDlg->objectName().isEmpty())
            BCSAddDlg->setObjectName(QStringLiteral("BCSAddDlg"));
        BCSAddDlg->resize(654, 384);
        verticalLayout = new QVBoxLayout(BCSAddDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(BCSAddDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 38));
        titleWidget->setMaximumSize(QSize(16777215, 38));

        verticalLayout->addWidget(titleWidget);

        horizontalWidget = new QWidget(BCSAddDlg);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setStyleSheet(QLatin1String("QWidget#horizontalWidget{\n"
"	background-color:#505050;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_2->setSpacing(28);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 20, 20, 20);
        widget_2 = new QWidget(horizontalWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(280, 306));
        widget_2->setMaximumSize(QSize(280, 306));
        widget_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
""));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(280, 56));
        widget_5->setMaximumSize(QSize(280, 56));
        widget_5->setStyleSheet(QLatin1String("background-color: rgb(250, 250, 250);\n"
""));
        label = new QLabel(widget_5);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 66, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral(""));
        bcsCodeLabel = new QLabel(widget_5);
        bcsCodeLabel->setObjectName(QStringLiteral("bcsCodeLabel"));
        bcsCodeLabel->setGeometry(QRect(100, 20, 101, 16));
        bcsCodeLabel->setFont(font);
        bcsCodeLabel->setStyleSheet(QStringLiteral(""));

        verticalLayout_3->addWidget(widget_5);

        frame = new QFrame(widget_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(280, 250));
        frame->setMaximumSize(QSize(280, 250));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_21 = new QLabel(frame);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 110, 100, 30));
        label_21->setMinimumSize(QSize(100, 0));
        label_21->setMaximumSize(QSize(100, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label_21->setFont(font1);
        label_21->setStyleSheet(QStringLiteral(""));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(50, 30, 62, 30));
        label_17->setMaximumSize(QSize(100, 16777215));
        label_17->setFont(font1);
        label_17->setStyleSheet(QStringLiteral(""));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_19 = new QLabel(frame);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(60, 70, 52, 30));
        label_19->setMaximumSize(QSize(100, 16777215));
        label_19->setFont(font1);
        label_19->setStyleSheet(QStringLiteral(""));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        IPLineEdit = new QLineEdit(frame);
        IPLineEdit->setObjectName(QStringLiteral("IPLineEdit"));
        IPLineEdit->setGeometry(QRect(120, 70, 146, 30));
        IPLineEdit->setMinimumSize(QSize(146, 30));
        IPLineEdit->setMaximumSize(QSize(146, 30));
        IPLineEdit->setFont(font);
        IPLineEdit->setStyleSheet(QLatin1String("border-width:1px;\n"
"border-color: #ed9a6e;\n"
"border-style:solid;\n"
"background-color: rgb(246, 246, 246);\n"
""));
        pushFrom = new QPushButton(frame);
        pushFrom->setObjectName(QStringLiteral("pushFrom"));
        pushFrom->setGeometry(QRect(20, 180, 243, 42));
        pushFrom->setMinimumSize(QSize(243, 42));
        pushFrom->setMaximumSize(QSize(243, 42));
        QFont font2;
        pushFrom->setFont(font2);
        pushFrom->setFocusPolicy(Qt::NoFocus);
        pushFrom->setStyleSheet(QLatin1String("QPushButton#pushFrom{\n"
" 	color:#FFFFFF;\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"QPushButton#pushFrom:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}"));
        typeComboBox = new QComboBox(frame);
        typeComboBox->setObjectName(QStringLiteral("typeComboBox"));
        typeComboBox->setGeometry(QRect(120, 30, 146, 30));
        typeComboBox->setMinimumSize(QSize(146, 30));
        typeComboBox->setMaximumSize(QSize(146, 30));
        typeComboBox->setFont(font);
        typeComboBox->setStyleSheet(QLatin1String("color:black;\n"
"background-color: rgb(246, 246, 246);\n"
"QComboBox QAbstractItemView::item{\n"
"	min-height:30px;\n"
"	height:30px;\n"
"	background-color: rgb(246, 246, 246);\n"
"};\n"
"QComboBox{\n"
"	border-width:1px;\n"
"	border-color: #ed9a6e;\n"
"	border-style:solid;\n"
"	background-color: rgb(246, 246, 246);\n"
"}\n"
""));
        goodsGroupComboBox = new QComboBox(frame);
        goodsGroupComboBox->setObjectName(QStringLiteral("goodsGroupComboBox"));
        goodsGroupComboBox->setGeometry(QRect(120, 110, 146, 30));
        goodsGroupComboBox->setMinimumSize(QSize(146, 0));
        goodsGroupComboBox->setMaximumSize(QSize(146, 30));
        goodsGroupComboBox->setFont(font);
        goodsGroupComboBox->setStyleSheet(QLatin1String("color:black;\n"
"background-color: rgb(246, 246, 246);\n"
"QComboBox QAbstractItemView::item{\n"
"	min-height:30px;\n"
"	height:30px;\n"
"	background-color: rgb(246, 246, 246);\n"
"};\n"
"QComboBox{\n"
"	border-width:1px;\n"
"	border-color: #ed9a6e;\n"
"	border-style:solid;\n"
"	background-color: rgb(246, 246, 246);\n"
"}\n"
""));

        verticalLayout_3->addWidget(frame);


        horizontalLayout_2->addWidget(widget_2);

        DigitalKeyWnd = new WndDigitalKeyboard(horizontalWidget);
        DigitalKeyWnd->setObjectName(QStringLiteral("DigitalKeyWnd"));
        DigitalKeyWnd->setMinimumSize(QSize(303, 303));

        horizontalLayout_2->addWidget(DigitalKeyWnd);


        verticalLayout->addWidget(horizontalWidget);


        retranslateUi(BCSAddDlg);

        QMetaObject::connectSlotsByName(BCSAddDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSAddDlg)
    {
        BCSAddDlg->setWindowTitle(QApplication::translate("BCSAddDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSAddDlg", "\346\235\241\347\240\201\347\247\244\347\274\226\345\217\267:", Q_NULLPTR));
        bcsCodeLabel->setText(QApplication::translate("BCSAddDlg", "001", Q_NULLPTR));
        label_21->setText(QApplication::translate("BCSAddDlg", "\345\205\263\350\201\224\345\225\206\345\223\201\347\273\204\357\274\232", Q_NULLPTR));
        label_17->setText(QApplication::translate("BCSAddDlg", "\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        label_19->setText(QApplication::translate("BCSAddDlg", "IP\357\274\232", Q_NULLPTR));
        pushFrom->setText(QApplication::translate("BCSAddDlg", "\344\277\235\345\255\230", Q_NULLPTR));
        typeComboBox->clear();
        typeComboBox->insertItems(0, QStringList()
         << QApplication::translate("BCSAddDlg", "RL00", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class BCSAddDlg: public Ui_BCSAddDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSADDDLG_H
