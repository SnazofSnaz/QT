#include "contactus.h"
#include "ui_contactus.h"
#include <QPixmap>

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
