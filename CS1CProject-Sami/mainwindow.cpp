#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contactus.h"
#include "testimonials.h"
#include "controller.h"
#include "vector.h"
#include "Canvas.h"

#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(controller *controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
     m_controller(controller)
{
    ui->setupUi(this);
   QPixmap pix("/Users/littlejimmyfirl/logo4.png");
   int w = ui->label5->width();
   int h = ui->label5->height();

   ui->label5->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

   QFile file(QDir::homePath() + "/testimonials.txt");
      if(!file.exists())
      {
          qDebug() << file.fileName() << " does not exist";
      }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_guestButton_clicked()
{
    changetoGuestLandingPage();
}

void MainWindow::changetoGuestLandingPage()
{
    ui->stackedWidget->setCurrentWidget(ui->landingPAge);
    if(page > 0)
    {
        ui->loginType->setText("Admin");
    }
    else
        ui->loginType->setText("Guest User");
}

void MainWindow::keyPressEvent(QKeyEvent* pe)
{
    if(page == 0)
    {
        if(pe->key()== Qt::Key_Return) on_LoginButton_clicked();
    }
}
void MainWindow::on_LoginButton_clicked()
{
    QString username = ui->usernameLine ->text();
    QString password = ui->passwordLine->text();

    if(username == "admin" && password == "admin")
    {
     QMessageBox::information(this, "Login", "Username and password is correct");
     changetoGuestLandingPage();
     page++;
     this->ui->usernameLine->setText("");
     this->ui->passwordLine->setText("");
    }
    else
    {
        QMessageBox::warning(this,"Login","Username and password is not correct");
        this->ui->usernameLine->setText("");
        this->ui->passwordLine->setText("");
    }
}

void MainWindow::changeToAdmin()
{
    ui->stackedWidget->setCurrentWidget(ui->AdminLandingPage);
    page++;
}

void MainWindow::on_clearButton_clicked()
{
    this->ui->usernameLine->setText("");
    this->ui->passwordLine->setText("");
}

void MainWindow::on_guestReturn_clicked()
{
    changeToMenu();
}

void MainWindow::changeToMenu()
{
    ui->stackedWidget->setCurrentWidget(ui->LoginPage);
    page--;
}

void MainWindow::on_adminReturn_clicked()
{
    changeToMenu();
}


void MainWindow::on_ContactUs_clicked()
{
    ContactUs contact;
    contact.setModal(true);
    contact.exec();

}

void MainWindow::on_writeTest_clicked()
{
    Testimonials test;
    test.setModal(true);
    test.exec();
}


void MainWindow::on_shapeCombo_currentIndexChanged(const QString &arg1)
{
    QString shapeDraw;
    shapeDraw = ui->shapeCombo->currentText();
}
