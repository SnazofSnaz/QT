/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *LoginPage;
    QGroupBox *groupBox;
    QLineEdit *usernameLine;
    QLineEdit *passwordLine;
    QLabel *username;
    QLabel *password;
    QPushButton *clearButton;
    QPushButton *LoginButton;
    QPushButton *guestButton;
    QLabel *label5;
    QPushButton *ContactUs;
    QWidget *AdminLandingPage;
    QLabel *label_4;
    QPushButton *adminReturn;
    QWidget *landingPAge;
    QLabel *label_3;
    QPushButton *guestReturn;
    QPushButton *writeTest;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 0, 781, 581));
        LoginPage = new QWidget();
        LoginPage->setObjectName(QString::fromUtf8("LoginPage"));
        groupBox = new QGroupBox(LoginPage);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(150, 250, 481, 241));
        usernameLine = new QLineEdit(groupBox);
        usernameLine->setObjectName(QString::fromUtf8("usernameLine"));
        usernameLine->setGeometry(QRect(170, 70, 281, 31));
        passwordLine = new QLineEdit(groupBox);
        passwordLine->setObjectName(QString::fromUtf8("passwordLine"));
        passwordLine->setGeometry(QRect(170, 120, 281, 31));
        passwordLine->setEchoMode(QLineEdit::Password);
        username = new QLabel(groupBox);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(30, 70, 131, 31));
        password = new QLabel(groupBox);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(30, 120, 131, 31));
        clearButton = new QPushButton(groupBox);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(270, 160, 141, 32));
        LoginButton = new QPushButton(groupBox);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));
        LoginButton->setGeometry(QRect(70, 160, 141, 32));
        guestButton = new QPushButton(groupBox);
        guestButton->setObjectName(QString::fromUtf8("guestButton"));
        guestButton->setGeometry(QRect(70, 200, 341, 32));
        label5 = new QLabel(LoginPage);
        label5->setObjectName(QString::fromUtf8("label5"));
        label5->setGeometry(QRect(210, 0, 421, 291));
        ContactUs = new QPushButton(LoginPage);
        ContactUs->setObjectName(QString::fromUtf8("ContactUs"));
        ContactUs->setGeometry(QRect(660, 520, 112, 32));
        stackedWidget->addWidget(LoginPage);
        AdminLandingPage = new QWidget();
        AdminLandingPage->setObjectName(QString::fromUtf8("AdminLandingPage"));
        label_4 = new QLabel(AdminLandingPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(210, 110, 391, 51));
        adminReturn = new QPushButton(AdminLandingPage);
        adminReturn->setObjectName(QString::fromUtf8("adminReturn"));
        adminReturn->setGeometry(QRect(300, 170, 191, 32));
        stackedWidget->addWidget(AdminLandingPage);
        landingPAge = new QWidget();
        landingPAge->setObjectName(QString::fromUtf8("landingPAge"));
        label_3 = new QLabel(landingPAge);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 90, 391, 51));
        guestReturn = new QPushButton(landingPAge);
        guestReturn->setObjectName(QString::fromUtf8("guestReturn"));
        guestReturn->setGeometry(QRect(290, 140, 191, 32));
        writeTest = new QPushButton(landingPAge);
        writeTest->setObjectName(QString::fromUtf8("writeTest"));
        writeTest->setGeometry(QRect(601, 510, 171, 32));
        stackedWidget->addWidget(landingPAge);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Login", nullptr));
        username->setText(QCoreApplication::translate("MainWindow", "Login Username:", nullptr));
        password->setText(QCoreApplication::translate("MainWindow", "Login Password:", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        LoginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        guestButton->setText(QCoreApplication::translate("MainWindow", "Continue as Guest", nullptr));
        label5->setText(QString());
        ContactUs->setText(QCoreApplication::translate("MainWindow", "Contact Us", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:24pt;\">THIS IS THE ADMIN LANDING PAGE</span></p></body></html>", nullptr));
        adminReturn->setText(QCoreApplication::translate("MainWindow", "Return to Main Menu", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:24pt;\">THIS IS THE  LANDING PAGE</span></p></body></html>", nullptr));
        guestReturn->setText(QCoreApplication::translate("MainWindow", "Return to Main Menu", nullptr));
        writeTest->setText(QCoreApplication::translate("MainWindow", "Write a Testimonial!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
