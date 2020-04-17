#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int page = 0;

private slots:
    void on_guestButton_clicked();
    void changetoGuestLandingPage();

    void on_LoginButton_clicked();
    void changeToAdmin();

    void on_clearButton_clicked();

    void on_guestReturn_clicked();
    void changeToMenu();

    void on_adminReturn_clicked();

protected:
    void keyPressEvent(QKeyEvent* pe);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
