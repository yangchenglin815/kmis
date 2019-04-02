/********************************************************************************
** Form generated from reading UI file 'OddChangeDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ODDCHANGEDLG_H
#define UI_ODDCHANGEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>

QT_BEGIN_NAMESPACE

class Ui_OddChangeDlg
{
public:
    QGridLayout *gridLayout;
    TitleBarWidget *titleWidget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QLabel *id_lab_received;
    QLabel *receivedValueLable;
    QLabel *id_lab_fact;
    QLabel *factValueLabel;
    QLabel *id_lab_odd_change;
    QLabel *oddChangeValueLabel;
    QFrame *line;

    void setupUi(QDialog *OddChangeDlg)
    {
        if (OddChangeDlg->objectName().isEmpty())
            OddChangeDlg->setObjectName(QStringLiteral("OddChangeDlg"));
        OddChangeDlg->resize(372, 225);
        gridLayout = new QGridLayout(OddChangeDlg);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(OddChangeDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 40));
        titleWidget->setMaximumSize(QSize(16777215, 40));

        gridLayout->addWidget(titleWidget, 0, 0, 1, 1);

        widget_2 = new QWidget(OddChangeDlg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QLatin1String("QWidget#widget_2 {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(16, 12, 16, 16);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(340, 157));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        id_lab_received = new QLabel(widget_3);
        id_lab_received->setObjectName(QStringLiteral("id_lab_received"));
        id_lab_received->setGeometry(QRect(10, 15, 80, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        id_lab_received->setFont(font);
        id_lab_received->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color: rgb(51, 51, 51);"));
        id_lab_received->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        receivedValueLable = new QLabel(widget_3);
        receivedValueLable->setObjectName(QStringLiteral("receivedValueLable"));
        receivedValueLable->setGeometry(QRect(186, 14, 130, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        receivedValueLable->setFont(font1);
        receivedValueLable->setStyleSheet(QString::fromUtf8("font:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:18px;\n"
"color: rgb(51, 51, 51);"));
        receivedValueLable->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        id_lab_fact = new QLabel(widget_3);
        id_lab_fact->setObjectName(QStringLiteral("id_lab_fact"));
        id_lab_fact->setGeometry(QRect(10, 46, 80, 30));
        id_lab_fact->setFont(font);
        id_lab_fact->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color: rgb(51, 51, 51);"));
        id_lab_fact->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        factValueLabel = new QLabel(widget_3);
        factValueLabel->setObjectName(QStringLiteral("factValueLabel"));
        factValueLabel->setGeometry(QRect(186, 44, 130, 30));
        factValueLabel->setFont(font1);
        factValueLabel->setStyleSheet(QString::fromUtf8("font:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:18px;\n"
"color: rgb(51, 51, 51);"));
        factValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        id_lab_odd_change = new QLabel(widget_3);
        id_lab_odd_change->setObjectName(QStringLiteral("id_lab_odd_change"));
        id_lab_odd_change->setGeometry(QRect(10, 109, 80, 30));
        id_lab_odd_change->setFont(font);
        id_lab_odd_change->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:14px;\n"
"color: rgb(51, 51, 51);"));
        id_lab_odd_change->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        oddChangeValueLabel = new QLabel(widget_3);
        oddChangeValueLabel->setObjectName(QStringLiteral("oddChangeValueLabel"));
        oddChangeValueLabel->setGeometry(QRect(186, 109, 130, 30));
        oddChangeValueLabel->setFont(font1);
        oddChangeValueLabel->setStyleSheet(QString::fromUtf8("font:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(234, 136, 82);\n"
"font-size:22px;"));
        oddChangeValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line = new QFrame(widget_3);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 90, 3470, 2));
        line->setMinimumSize(QSize(340, 2));
        line->setMaximumSize(QSize(16777215, 2));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(widget_3);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);


        retranslateUi(OddChangeDlg);

        QMetaObject::connectSlotsByName(OddChangeDlg);
    } // setupUi

    void retranslateUi(QDialog *OddChangeDlg)
    {
        OddChangeDlg->setWindowTitle(QApplication::translate("OddChangeDlg", "OddChangeDlg", Q_NULLPTR));
        id_lab_received->setText(QApplication::translate("OddChangeDlg", "\345\276\205\346\224\266\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        receivedValueLable->setText(QApplication::translate("OddChangeDlg", "\357\277\24537.02", Q_NULLPTR));
        id_lab_fact->setText(QApplication::translate("OddChangeDlg", "\345\256\236\346\224\266\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        factValueLabel->setText(QApplication::translate("OddChangeDlg", "\357\277\24510.00", Q_NULLPTR));
        id_lab_odd_change->setText(QApplication::translate("OddChangeDlg", "\346\211\276\351\233\266\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        oddChangeValueLabel->setText(QApplication::translate("OddChangeDlg", "\357\277\24527.02", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OddChangeDlg: public Ui_OddChangeDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ODDCHANGEDLG_H
