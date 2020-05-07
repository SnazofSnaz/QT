#include "contactus.h"
#include "ui_contactus.h"
#include <QPixmap>
#include <QMessageBox>

ContactUs::ContactUs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUs)
{
    ui->setupUi(this);
    QPixmap pix("/Users/littlejimmyfirl/logo.png");
    int w = ui->label->width();
    int h = ui->label->height();

    ui->label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

ContactUs::~ContactUs()
{
    delete ui;
}

void ContactUs::on_sendMessage_clicked()
{
    QFile file(QDir::homePath() + "/contactUs.txt");
    if(!file.exists())
    {
        qDebug() << file.fileName() << " does not exist";
    }
    QString contactName;
    QString contactEmail;
    QString contactMessage;
    QTextStream out(&file);
    if(file.open(QIODevice::Append | QIODevice::WriteOnly | QIODevice::Text))
    {
        contactName = ui->contactName->text();
        contactEmail = ui->contactEmail->text();
        contactMessage = ui->contactMessage->toPlainText();
        out << "Contact's Name: " << contactName << endl;
        out << "Contact's Email: " << contactEmail << endl;
        out << "Contact's Message: " << contactMessage << endl << endl;
    }

    file.close();

    QMessageBox::information(this, "Contact Us", "Message Has Been Sucsessfully Submitted! We will respond to you shortly!");
    hide();
}
