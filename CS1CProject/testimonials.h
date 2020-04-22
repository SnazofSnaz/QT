#ifndef TESTIMONIALS_H
#define TESTIMONIALS_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QFileInfo>
#include <QKeyEvent>
#include <QDate>
#include <QInputDialog>
namespace Ui {
class Testimonials;
}

class Testimonials : public QDialog
{
    Q_OBJECT

public:
    explicit Testimonials(QWidget *parent = nullptr);
    ~Testimonials();

private slots:
    void on_submitTest_clicked();

private:
    Ui::Testimonials *ui;
};

#endif // TESTIMONIALS_H
