#include "testimonials.h"
#include "ui_testimonials.h"
#include <QMessageBox>

Testimonials::Testimonials(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Testimonials)
{
    ui->setupUi(this);
}

Testimonials::~Testimonials()
{
    delete ui;
}

void Testimonials::on_submitTest_clicked()
{
    QFile file(QDir::homePath() + "/testimonials.txt");
    if(!file.exists())
    {
        qDebug() << file.fileName() << " does not exist";
    }
    QString testimonial;
    QTextStream out(&file);
    if(file.open(QIODevice::Append | QIODevice::WriteOnly | QIODevice::Text))
    {
        testimonial = ui->writtenTest->toPlainText();
        out << testimonial << endl << endl;
    }

    file.close();

    QMessageBox::information(this, "Testimonial", "Testimonial Has Been Sucsessfully Submitted! Thank you for your Feedback!");
    hide();
}
