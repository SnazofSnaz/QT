#ifndef CONTACTUS_H
#define CONTACTUS_H

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
class ContactUs;
}

class ContactUs : public QDialog
{
    Q_OBJECT

public:
    explicit ContactUs(QWidget *parent = nullptr);
    ~ContactUs();

private slots:
    void on_sendMessage_clicked();

private:
    Ui::ContactUs *ui;
};

#endif // CONTACTUS_H
