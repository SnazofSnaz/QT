/********************************************************************************
** Form generated from reading UI file 'contactus.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTUS_H
#define UI_CONTACTUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ContactUs
{
public:
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *ContactUs)
    {
        if (ContactUs->objectName().isEmpty())
            ContactUs->setObjectName(QString::fromUtf8("ContactUs"));
        ContactUs->resize(541, 562);
        label_2 = new QLabel(ContactUs);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 150, 521, 381));
        label = new QLabel(ContactUs);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, -10, 341, 201));
        label->setLineWidth(0);
        label->setMidLineWidth(0);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(ContactUs);

        QMetaObject::connectSlotsByName(ContactUs);
    } // setupUi

    void retranslateUi(QDialog *ContactUs)
    {
        ContactUs->setWindowTitle(QCoreApplication::translate("ContactUs", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("ContactUs", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Phone:</span></p><p align=\"center\"><span style=\" font-size:14pt;\">916-553-5175</span></p><p align=\"center\"><span style=\" font-size:14pt;\">Email:</span></p><p align=\"center\"><span style=\" font-size:14pt;\">conact@OnTheFly.net</span></p><p align=\"center\"><span style=\" font-size:14pt;\">Address:</span></p><p align=\"center\"><span style=\" font-size:14pt;\">2468 Highland View Drive, Sacramento, CA, 95814</span></p><p align=\"center\"><span style=\" font-size:14pt;\">Hours of Operation:</span></p><p align=\"center\"><span style=\" font-size:14pt;\">Monday: 8AM- 6PM</span></p><p align=\"center\"><span style=\" font-size:14pt;\">Tuesday: 8AM- 6PM</span></p><p align=\"center\"><span style=\" font-size:14pt;\">Wednesday: 8AM- 6PM</span></p><p align=\"center\"><span style=\" font-size:14pt;\">Thurdsday 8AM- 6PM</span></p><p align=\"center\"><span style=\" font-size:14pt;\">Friday: 8AM- 6PM</span></p><p align=\"center\"><span style=\" "
                        "font-size:14pt;\">Closed Saturday and Sunday</span></p><p align=\"center\"><span style=\" font-size:14pt;\"><br/></span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("ContactUs", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactUs: public Ui_ContactUs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTUS_H
