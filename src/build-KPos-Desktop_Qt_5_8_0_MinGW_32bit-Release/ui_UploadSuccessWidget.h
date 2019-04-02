/********************************************************************************
** Form generated from reading UI file 'UploadSuccessWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADSUCCESSWIDGET_H
#define UI_UPLOADSUCCESSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadSuccessWidget
{
public:
    QLabel *uploadedSuccessLabel;
    QLabel *conextLabel;
    QLabel *label_3;

    void setupUi(QWidget *UploadSuccessWidget)
    {
        if (UploadSuccessWidget->objectName().isEmpty())
            UploadSuccessWidget->setObjectName(QStringLiteral("UploadSuccessWidget"));
        UploadSuccessWidget->resize(418, 428);
        UploadSuccessWidget->setStyleSheet(QLatin1String("QWidget#UploadSuccessWidget {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        uploadedSuccessLabel = new QLabel(UploadSuccessWidget);
        uploadedSuccessLabel->setObjectName(QStringLiteral("uploadedSuccessLabel"));
        uploadedSuccessLabel->setGeometry(QRect(110, 248, 200, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        uploadedSuccessLabel->setFont(font);
        uploadedSuccessLabel->setAlignment(Qt::AlignCenter);
        conextLabel = new QLabel(UploadSuccessWidget);
        conextLabel->setObjectName(QStringLiteral("conextLabel"));
        conextLabel->setGeometry(QRect(110, 290, 200, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        conextLabel->setFont(font1);
        conextLabel->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(UploadSuccessWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(172, 122, 81, 81));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/shareImages/upload_success.png);"));

        retranslateUi(UploadSuccessWidget);

        QMetaObject::connectSlotsByName(UploadSuccessWidget);
    } // setupUi

    void retranslateUi(QWidget *UploadSuccessWidget)
    {
        UploadSuccessWidget->setWindowTitle(QApplication::translate("UploadSuccessWidget", "UploadSuccessWidget", Q_NULLPTR));
        uploadedSuccessLabel->setText(QApplication::translate("UploadSuccessWidget", "\345\267\262\344\270\212\344\274\240\346\210\220\345\212\237", Q_NULLPTR));
        conextLabel->setText(QApplication::translate("UploadSuccessWidget", "\350\257\267\350\200\220\345\277\203\347\255\211\345\276\205\347\256\241\347\220\206\345\221\230\345\256\241\346\240\270", Q_NULLPTR));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UploadSuccessWidget: public Ui_UploadSuccessWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADSUCCESSWIDGET_H
