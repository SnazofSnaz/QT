#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   QPixmap pix("/Users/littlejimmyfirl/Logo.png");
   int w = ui->label5->width();
   int h = ui->label5->height();

   ui->label5->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
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
    ui->stackedWidget->setCurrentWidget(ui->GuestLandingPage);
    page++;
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
     changeToAdmin();
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
