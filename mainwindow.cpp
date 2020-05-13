#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contactus.h"
#include "testimonials.h"
#include "controller.h"
#include "vector.h"
#include "shape.h"
#include "Canvas.h"
#include "globals.h"

#include <QMessageBox>
#include <QPixmap>
#include <QApplication>


const int IdRole = Qt::UserRole;

MainWindow::MainWindow(controller *controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
     m_controller(controller)
{
    canvas = new Canvas;
    ui->setupUi(this);

   ui->shapeCombo->addItem(tr("Line"), Canvas::line);
   ui->shapeCombo->addItem(tr("Polyline"), Canvas::polyline);
   ui->shapeCombo->addItem(tr("Polygon"), Canvas::polygon);
   ui->shapeCombo->addItem(tr("Square"), Canvas::square);
   ui->shapeCombo->addItem(tr("Rectangle"), Canvas::rect);
   ui->shapeCombo->addItem(tr("Ellipse"), Canvas::ellipse);
   ui->shapeCombo->addItem(tr("Circle"), Canvas::circle);
   ui->shapeCombo->addItem(tr("Text"), Canvas::text);
   ui->shapeCombo->addItem(tr("Render All"), Canvas::all);


   QPixmap pix("/Users/littlejimmyfirl/logo4.png");
   int w = ui->label5->width();
   int h = ui->label5->height();

   ui->label5->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

   QFile file(QDir::homePath() + "/testimonials.txt");
      if(!file.exists())
      {
          qDebug() << file.fileName() << " does not exist";
      }

      connect(ui->shapeCombo, QOverload<int>::of(&QComboBox::activated),
              this, &MainWindow::shapeChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_guestButton_clicked()
{
    changetoGuestLandingPage();
    ui->loginType->setText("Guest User");
}

void MainWindow::changetoGuestLandingPage()
{
    ui->stackedWidget->setCurrentWidget(ui->landingPAge);
    setWindowTitle(tr("Drawing Page"));
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
     ui->loginType->setText("Admin");
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
    double perimeterS;
    double areaS;
    QSqlQuery qry;
    shapeDraw = ui->shapeCombo->currentText();

        if(shapeDraw == "Line")
        {
            Line myline(this,1);
            perimeterS = myline.perimeter();
            areaS = myline.area();

            ui->perimeter->setText(QString::number(perimeterS));
            ui->area->setText(QString::number(areaS));
        }
        else if(shapeDraw == "Polygon")
        {
            qry.prepare("select * from shape where type = 'Polygon'");
            if (qry.exec())
            {
                while(qry.next())
                {
                    perimeterS = qry.value(17).toDouble();
                    areaS = qry.value(18).toDouble();
                }
            }
            ui->perimeter->setText(QString::number(perimeterS));
            ui->area->setText(QString::number(areaS));

        }
        else if(shapeDraw == "Polyline")
        {
            qry.prepare("select * from shape where type = 'Polyline'");
            if (qry.exec())
            {
                while(qry.next())
                {
                    perimeterS = qry.value(17).toDouble();
                    areaS = qry.value(18).toDouble();
                }
            }
            ui->perimeter->setText(QString::number(perimeterS));
            ui->area->setText(QString::number(areaS));
        }
        else if(shapeDraw == "Square")
        {
            qry.prepare("select * from shape where type = 'Square'");
            if (qry.exec())
            {
                while(qry.next())
                {
                    perimeterS = qry.value(17).toDouble();
                    areaS = qry.value(18).toDouble();
                }
            }
            ui->perimeter->setText(QString::number(perimeterS));
            ui->area->setText(QString::number(areaS));
        }
        else if(shapeDraw == "Rectangle")
        {
            qry.prepare("select * from shape where type = 'Rectangle'");
            if (qry.exec())
            {
                while(qry.next())
                {
                    perimeterS = qry.value(17).toDouble();
                    areaS = qry.value(18).toDouble();
                }
            }
            ui->perimeter->setText(QString::number(perimeterS));
            ui->area->setText(QString::number(areaS));
        }
        else if(shapeDraw == "Circle")
        {
            qry.prepare("select * from shape where type = 'Circle'");
            if (qry.exec())
            {
                while(qry.next())
                {
                    perimeterS = qry.value(17).toDouble();
                    areaS = qry.value(18).toDouble();
                }
            }
            ui->perimeter->setText(QString::number(perimeterS));
            ui->area->setText(QString::number(areaS));
        }
        else if(shapeDraw == "Ellipse")
        {
            qry.prepare("select * from shape where type = 'Ellipse'");
            if (qry.exec())
            {
                while(qry.next())
                {
                    perimeterS = qry.value(17).toDouble();
                    areaS = qry.value(18).toDouble();
                }
            }
            ui->perimeter->setText(QString::number(perimeterS));
            ui->area->setText(QString::number(areaS));
        }
}
void MainWindow::shapeChanged()
{
    myInt = (ui->shapeCombo->itemData(
            ui->shapeCombo->currentIndex(), IdRole).toInt());
    canvas->setShape(myInt);
}

void MainWindow::on_circRender_clicked()
{
    QString shapeDraw;
    QString login;
    shapeDraw = ui->shapeCombo->currentText();
    login = ui->loginType->text();
    if(login == "Admin")
    {

        if(shapeDraw == "Line")
        {
            myInt = 0;
            isDrawn[0] = true;
            canvas->setShape(myInt);
        }
        else if(shapeDraw == "Polygon")
        {
            myInt = 2;
            isDrawn[2] = true;
            canvas->setShape(myInt);
        }
        else if(shapeDraw == "Polyline")
        {
            myInt = 1;
            isDrawn[1] = true;
            canvas->setShape(myInt);
        }
        else if(shapeDraw == "Square")
        {
            myInt = 3;
            isDrawn[3] = true;
            canvas->setShape(myInt);
        }
        else if(shapeDraw == "Rectangle")
        {
            myInt = 4;
            isDrawn[4] = true;
            canvas->setShape(myInt);
        }
        else if(shapeDraw == "Circle")
        {
            myInt = 6;
            isDrawn[6] = true;
            canvas->setShape(myInt);
        }
        else if(shapeDraw == "Ellipse")
        {
            myInt = 5;
            isDrawn[5] = true;
            canvas->setShape(myInt);
        }
        else if(shapeDraw == "Text")
        {
            myInt = 7;
            isDrawn[7] = true;
            canvas->setShape(myInt);
        }
        else if(shapeDraw == "Render All")
        {
            myInt = 8;
            isDrawn[8] = true;
            canvas->setShape(myInt);
        }
    }
    else
        QMessageBox::warning(this,"Non-Admin","Adding shapes is an admin only function");
}

void MainWindow::on_cirDelete_clicked()
{
        QString login;
        QString shapeDraw;
        shapeDraw = ui->shapeCombo->currentText();
        login = ui->loginType->text();
        if(login == "Admin")
        {

            if(shapeDraw == "Line")
            {
                myInt = 0;
                isDrawn[0] = false;
                canvas->setShape(myInt);
            }
            else if(shapeDraw == "Polygon")
            {
                myInt = 2;
                isDrawn[2] = false;
                canvas->setShape(myInt);
            }
            else if(shapeDraw == "Polyline")
            {
                myInt = 1;
                isDrawn[1] = false;
                canvas->setShape(myInt);
            }
            else if(shapeDraw == "Square")
            {
                myInt = 3;
                isDrawn[3] = false;
                canvas->setShape(myInt);
            }
            else if(shapeDraw == "Rectangle")
            {
                myInt = 4;
                isDrawn[4] = false;
                canvas->setShape(myInt);
            }
            else if(shapeDraw == "Circle")
            {
                myInt = 6;
                isDrawn[6] = false;
                canvas->setShape(myInt);
            }
            else if(shapeDraw == "Ellipse")
            {
                myInt = 5;
                isDrawn[5] = false;
                canvas->setShape(myInt);
            }
            else if(shapeDraw == "Text")
            {
                myInt = 7;
                isDrawn[7] = false;
                canvas->setShape(myInt);
            }
            else if(shapeDraw == "Render All")
            {
                myInt = 8;
                isDrawn[8] = false;
                canvas->setShape(myInt);
            }

        }
        else
            QMessageBox::warning(this,"Non-Admin","Deleting shapes is an admin only function");
}



