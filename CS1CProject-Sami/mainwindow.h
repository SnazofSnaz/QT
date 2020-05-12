#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QPainter>
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
#include "controller.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class Canvas;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(controller *controller, QWidget *parent = nullptr);
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

    void on_ContactUs_clicked();

    void on_writeTest_clicked();

    void on_shapeCombo_currentIndexChanged(const QString &arg1);

    void shapeChanged();

    void on_circRender_clicked();

    void on_cirDelete_clicked();

protected:
    void keyPressEvent(QKeyEvent* pe);

private:
    Canvas *canvas;
    Ui::MainWindow *ui;
    controller *m_controller;
};
#endif // MAINWINDOW_H
