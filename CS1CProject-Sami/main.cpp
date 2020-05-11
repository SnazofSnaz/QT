#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    controller controller;
    MainWindow w(&controller);
    w.show();
    return a.exec();
}
