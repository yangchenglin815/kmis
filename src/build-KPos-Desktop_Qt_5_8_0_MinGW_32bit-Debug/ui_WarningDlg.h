/********************************************************************************
** Form generated from reading UI file 'WarningDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNINGDLG_H
#define UI_WARNINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WarningDlg
{
public:
    QGridLayout *gridLayout;
    QWidget *titleWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *titleLabel;
    QPushButton *deleteBtn;
    QLabel *contextLabel;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *sureBtn;

    void setupUi(QDialog *WarningDlg)
    {
        if (WarningDlg->objectName().isEmpty())
            WarningDlg->setObjectName(QStringLiteral("WarningDlg"));
        WarningDlg->resize(370, 231);
        WarningDlg->setMinimumSize(QSize(370, 231));
        WarningDlg->setStyleSheet(QLatin1String("QWidget#WarningDlg {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        gridLayout = new QGridLayout(WarningDlg);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new QWidget(WarningDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 42));
        titleWidget->setMaximumSize(QSize(16777215, 42));
        titleWidget->setStyleSheet(QLatin1String("QWidget#titleWidget {\n"
"	border-image: url(:/shareImages/title_bar.png);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(titleWidget);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 5, 5, 5);
        titleLabel = new QLabel(titleWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setMinimumSize(QSize(0, 30));
        titleLabel->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("QLabel#titleLabel {\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:16px;\n"
"	color: rgb(255, 255, 255);\n"
"	border-width: 0px;\n"
"}"));
        titleLabel->setFrameShape(QFrame::NoFrame);
        titleLabel->setFrameShadow(QFrame::Plain);
        titleLabel->setLineWidth(1);

        horizontalLayout_2->addWidget(titleLabel);

        deleteBtn = new QPushButton(titleWidget);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        deleteBtn->setMinimumSize(QSize(33, 33));
        deleteBtn->setMaximumSize(QSize(33, 33));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        deleteBtn->setFont(font1);
        deleteBtn->setFocusPolicy(Qt::NoFocus);
        deleteBtn->setStyleSheet(QLatin1String("QPushButton#deleteBtn {\n"
"	border-image: url(:/shareImages/close.png);\n"
"}\n"
"\n"
"QPushButton#deleteBtn:pressed {\n"
"	border-image: url(:/shareImages/close_press.png);\n"
"}"));

        horizontalLayout_2->addWidget(deleteBtn);


        gridLayout->addWidget(titleWidget, 0, 0, 1, 1);

        contextLabel = new QLabel(WarningDlg);
        contextLabel->setObjectName(QStringLiteral("contextLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(contextLabel->sizePolicy().hasHeightForWidth());
        contextLabel->setSizePolicy(sizePolicy);
        contextLabel->setFont(font);
        contextLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font-size:16px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        contextLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(contextLabel, 1, 0, 1, 1);

        bottomWidget = new QWidget(WarningDlg);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 62));
        bottomWidget->setMaximumSize(QSize(16777215, 62));
        horizontalLayout = new QHBoxLayout(bottomWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sureBtn = new QPushButton(bottomWidget);
        sureBtn->setObjectName(QStringLiteral("sureBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sureBtn->sizePolicy().hasHeightForWidth());
        sureBtn->setSizePolicy(sizePolicy1);
        sureBtn->setMinimumSize(QSize(152, 42));
        sureBtn->setMaximumSize(QSize(152, 42));
        sureBtn->setFont(font);
        sureBtn->setFocusPolicy(Qt::NoFocus);
        sureBtn->setStyleSheet(QString::fromUtf8("QPushButton#sureBtn {\n"
"	color: rgb(255, 255, 255);\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#sureBtn:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}"));

        horizontalLayout->addWidget(sureBtn);


        gridLayout->addWidget(bottomWidget, 2, 0, 1, 1);


        retranslateUi(WarningDlg);

        QMetaObject::connectSlotsByName(WarningDlg);
    } // setupUi

    void retranslateUi(QDialog *WarningDlg)
    {
        WarningDlg->setWindowTitle(QApplication::translate("WarningDlg", "WarningDlg", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("WarningDlg", "\347\216\260\351\207\221", Q_NULLPTR));
        deleteBtn->setText(QString());
        contextLabel->setText(QApplication::translate("WarningDlg", "\346\230\257\345\220\246\347\241\256\350\256\244\346\224\257\344\273\230?", Q_NULLPTR));
        sureBtn->setText(QApplication::translate("WarningDlg", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WarningDlg: public Ui_WarningDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNINGDLG_H
