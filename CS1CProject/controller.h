#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QtSql>
#include <QList>
#include <QMap>
#include <QFile>
#include <QFileDialog>
#include <QStringList>


class controller : public QObject
{
public:
    explicit controller(QObject *parent = nullptr);
    void createTable();
    void createTextTable();
    bool readShapesFile();
    void createShape(int id, QString type, int dimenOne, int dimenTwo, int dimenThree, int dimenFour, int dimenFive, int dimenSix, int dimenSeven,
                     int dimenEight, QString color, int width, QString style, QString capStyle, QString joinStyle,
                     QString brishColor, QString brushStyle);

    void createText(int id, QString type, int dimenOne, int dimenTwo, int dimenThree, int dimenFour, int dimenFive, int dimenSix, int dimenSeven,
                               int dimenEight,QString textString, QString color, QString textAlignment, int pointSize,
                               QString fontFamily, QString fontStyle, QString fontWeight);
private:
    QSqlDatabase      m_database;
};

#endif // CONTROLLER_H
