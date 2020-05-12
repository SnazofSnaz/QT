/********************************************************************************
** Form generated from reading UI file 'testimonials.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTIMONIALS_H
#define UI_TESTIMONIALS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Testimonials
{
public:
    QLabel *label;
    QPushButton *submitTest;
    QPlainTextEdit *writtenTest;

    void setupUi(QDialog *Testimonials)
    {
        if (Testimonials->objectName().isEmpty())
            Testimonials->setObjectName(QString::fromUtf8("Testimonials"));
        Testimonials->resize(564, 375);
        label = new QLabel(Testimonials);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 541, 51));
        submitTest = new QPushButton(Testimonials);
        submitTest->setObjectName(QString::fromUtf8("submitTest"));
        submitTest->setGeometry(QRect(0, 340, 561, 32));
        writtenTest = new QPlainTextEdit(Testimonials);
        writtenTest->setObjectName(QString::fromUtf8("writtenTest"));
        writtenTest->setGeometry(QRect(10, 60, 541, 261));

        retranslateUi(Testimonials);

        QMetaObject::connectSlotsByName(Testimonials);
    } // setupUi

    void retranslateUi(QDialog *Testimonials)
    {
        Testimonials->setWindowTitle(QCoreApplication::translate("Testimonials", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Testimonials", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Write a Testimonial Describing your Experience with OnTheFly Shape Illustrator!</span></p></body></html>", nullptr));
        submitTest->setText(QCoreApplication::translate("Testimonials", "Submit Your Testimonial!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Testimonials: public Ui_Testimonials {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTIMONIALS_H
