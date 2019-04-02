/********************************************************************************
** Form generated from reading UI file 'TipsDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIPSDLG_H
#define UI_TIPSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TipsDlg
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *titleWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *titleLabel;
    QPushButton *deleteBtn;
    QLabel *contextLabel;

    void setupUi(QWidget *TipsDlg)
    {
        if (TipsDlg->objectName().isEmpty())
            TipsDlg->setObjectName(QStringLiteral("TipsDlg"));
        TipsDlg->resize(370, 211);
        TipsDlg->setMinimumSize(QSize(370, 211));
        TipsDlg->setStyleSheet(QLatin1String("QWidget#TipsDlg {\n"
"        border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        verticalLayout = new QVBoxLayout(TipsDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new QWidget(TipsDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 42));
        titleWidget->setMaximumSize(QSize(16777215, 42));
        titleWidget->setStyleSheet(QLatin1String("QWidget#titleWidget {\n"
"        border-image: url(:/shareImages/title_bar.png);\n"
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
"        font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"        font-size:16px;\n"
"        color: rgb(255, 255, 255);\n"
"        border-width: 0px;\n"
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
"        border-image: url(:/shareImages/close.png);\n"
"}\n"
"\n"
"QPushButton#deleteBtn:pressed {\n"
"        border-image: url(:/shareImages/close_press.png);\n"
"}"));

        horizontalLayout_2->addWidget(deleteBtn);


        verticalLayout->addWidget(titleWidget);

        contextLabel = new QLabel(TipsDlg);
        contextLabel->setObjectName(QStringLiteral("contextLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(contextLabel->sizePolicy().hasHeightForWidth());
        contextLabel->setSizePolicy(sizePolicy);
        contextLabel->setMinimumSize(QSize(320, 0));
        contextLabel->setMaximumSize(QSize(320, 16777215));
        contextLabel->setFont(font);
        contextLabel->setLayoutDirection(Qt::LeftToRight);
        contextLabel->setAutoFillBackground(false);
        contextLabel->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"font-size:16px;"));
        contextLabel->setAlignment(Qt::AlignCenter);
        contextLabel->setWordWrap(true);
        contextLabel->setIndent(0);

        verticalLayout->addWidget(contextLabel, 0, Qt::AlignHCenter);


        retranslateUi(TipsDlg);

        QMetaObject::connectSlotsByName(TipsDlg);
    } // setupUi

    void retranslateUi(QWidget *TipsDlg)
    {
        TipsDlg->setWindowTitle(QApplication::translate("TipsDlg", "TipsDlg", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("TipsDlg", "\346\217\220\347\244\272", Q_NULLPTR));
        deleteBtn->setText(QString());
        contextLabel->setText(QApplication::translate("TipsDlg", "\346\234\215\345\212\241\345\231\250\346\255\243\345\234\250\350\277\233\350\241\214\346\223\215\344\275\234\357\274\214\350\257\267\350\200\220\345\277\203\347\255\211\345\200\231...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TipsDlg: public Ui_TipsDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIPSDLG_H
