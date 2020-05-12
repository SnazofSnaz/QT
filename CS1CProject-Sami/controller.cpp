#include "controller.h"

/**
 * @brief controller::controller
 * @param parent
 */

controller::controller(QObject *parent) : QObject(parent)
{
    // Connecting to database
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QDir::homePath() + "/OnTheFly.db";
    m_database.setDatabaseName(path);
    if(!m_database.open())
    {
        qDebug() << "problem opening database" << endl;
    }
    createTable();
    createTextTable();
    readShapesFile();
}
/**
 * @brief controller::createTable
 */
void controller::createTable()
{
    QSqlQuery qry;

    // About creating the shape table
    QString createShapeTable =
    "create table IF NOT EXISTS shape(                            "
    "id                  integer        primary key,                      "
    "type                varchar(50)    not null,                         "
    "dimenOne            integer        not null,                         "
    "dimenTwo            integer        not null,                         "
    "dimenThree          integer        not null,                         "
    "dimenFour           integer        not null,                         "
    "dimenFive           integer        not null,                         "
    "dimenSix            integer        not null,                         "
    "dimenSeven          integer        not null,                         "
    "dimenEight          integer        not null,                         "
    "color               varchar(50)    not null,                         "
    "width               integer        not null,                         "
    "style               varchar(50)    not null,                         "
    "capStyle            varchar(50)    not null,                         "
    "joinStyle           varchar(50)    not null,                         "
    "brushColor          varchar(50)    not null,                         "
    "brushStyle          varchar(50)    not null                         "
    ");                                                            ";
    if(!qry.exec(createShapeTable))
    {
        qDebug() << "error creating Shape table" << endl;
    }
}
void controller::createTextTable()
{
    QSqlQuery qry;

    // About creating the Text table
    QString createTextTable =
    "create table IF NOT EXISTS text(                            "
    "id                  integer        primary key,                      "
    "type                varchar(50)    not null,                         "
    "dimenOne            integer        not null,                         "
    "dimenTwo            integer        not null,                         "
    "dimenThree          integer        not null,                         "
    "dimenFour           integer        not null,                         "
    "dimenFive           integer        not null,                         "
    "dimenSix            integer        not null,                         "
    "dimenSeven          integer        not null,                         "
    "dimenEight          integer        not null,                         "
    "textString          varchar(50)    not null,                         "
    "color               varchar(50)    not null,                         "
    "alignment           varchar(50)    not null,                         "
    "pointSize           integer        not null,                         "
    "fontFamily          varchar(50)    not null,                         "
    "fontStyle           varchar(50)    not null,                         "
    "fontWeight          varchar(50)    not null                         "
    ");                                                            ";
    if(!qry.exec(createTextTable))
    {
        qDebug() << "error creating text table" << endl;
    }
}
bool controller::readShapesFile()
{
    QFile file(QDir::homePath() + "/shapes.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    QTextStream in(&file);
    while (!in.atEnd())
    {
        int shapeId = in.readLine().toInt();
        QString shapeType = in.readLine();

        if(shapeType == "Text")
        {
            QString dimenRead = in.readLine();
            QStringList shapeDimen = dimenRead.split(',');
            int dimenOne = shapeDimen[0].toInt();
            int dimenTwo = shapeDimen[1].toInt();
            int dimenThree = shapeDimen[2].toInt();
            int dimenFour = shapeDimen[3].toInt();
            int dimenFive = shapeDimen[4].toInt();
            int dimenSix = shapeDimen[5].toInt();
            int dimenSeven = shapeDimen[6].toInt();
            int dimenEight = shapeDimen[7].toInt();
            QString textString = in.readLine();
            QString textColor = in.readLine();
            QString textAlignment = in.readLine();
            int textPointSize = in.readLine().toInt();
            QString textPointFamily = in.readLine();
            QString textFontStyle = in.readLine();
            QString textFontWeight = in.readLine();

            createText( shapeId,
                         shapeType,
                         dimenOne,
                         dimenTwo,
                         dimenThree,
                         dimenFour,
                         dimenFive,
                         dimenSix,
                         dimenSeven,
                         dimenEight,
                         textString,
                         textColor,
                         textAlignment,
                         textPointSize,
                         textPointFamily,
                         textFontStyle,
                         textFontWeight);
        }

        else
        {
            QString dimenRead = in.readLine();
            QStringList shapeDimen = dimenRead.split(',');
            int dimenOne = shapeDimen[0].toInt();
            int dimenTwo = shapeDimen[1].toInt();
            int dimenThree = shapeDimen[2].toInt();
            int dimenFour = shapeDimen[3].toInt();
            int dimenFive = shapeDimen[4].toInt();
            int dimenSix = shapeDimen[5].toInt();
            int dimenSeven = shapeDimen[6].toInt();
            int dimenEight = shapeDimen[7].toInt();
            QString shapeColor = in.readLine();
            int shapeWidth = in.readLine().toInt();
            QString shapeStyle = in.readLine();
            QString shapeCapStyle = in.readLine();
            QString shapejoinStyle = in.readLine();
            QString shapeBrushColor = in.readLine();
            QString shapeBrushStyle = in.readLine();



            createShape( shapeId,
                         shapeType,
                         dimenOne,
                         dimenTwo,
                         dimenThree,
                         dimenFour,
                         dimenFive,
                         dimenSix,
                         dimenSeven,
                         dimenEight,
                         shapeColor,
                         shapeWidth,
                         shapeStyle,
                         shapeCapStyle,
                         shapejoinStyle,
                         shapeBrushColor,
                         shapeBrushStyle);
        }

    }

    return true;
}
void controller::createText(int id, QString type, int dimenOne, int dimenTwo, int dimenThree, int dimenFour, int dimenFive, int dimenSix, int dimenSeven,
                           int dimenEight,QString textString, QString color, QString textAlignment, int pointSize,
                           QString fontFamily, QString fontStyle, QString fontWeight)
{
    // Step 1
    // Creating an entry into database
    QSqlQuery qry;
    qry.prepare("insert into text   (        "
                "id,                         "
                "type,                       "
                "dimenOne,                   "
                "dimenTwo,                   "
                "dimenThree,                 "
                "dimenFour,                  "
                "dimenFive,                  "
                "dimenSix,                   "
                "dimenSeven,                 "
                "dimenEight,                 "
                "textString,                 "
                "color,                      "
                "alignment,                  "
                "pointSize,                  "
                "fontFamily,                 "
                "fontStyle,                  "
                "fontWeight)                 "
                "values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);        "
                );
    qry.addBindValue(id);
    qry.addBindValue(type);
    qry.addBindValue(dimenOne);
    qry.addBindValue(dimenTwo);
    qry.addBindValue(dimenThree);
    qry.addBindValue(dimenFour);
    qry.addBindValue(dimenFive);
    qry.addBindValue(dimenSix);
    qry.addBindValue(dimenSeven);
    qry.addBindValue(dimenEight);
    qry.addBindValue(textString);
    qry.addBindValue(color);
    qry.addBindValue(textAlignment);
    qry.addBindValue(pointSize);
    qry.addBindValue(fontFamily);
    qry.addBindValue(fontStyle);
    qry.addBindValue(fontWeight);

    if(!qry.exec())
    {
         qDebug() << "Error adding shape" << endl;
    }
    qry.clear();
}

void controller::createShape(int id, QString type, int dimenOne, int dimenTwo, int dimenThree, int dimenFour, int dimenFive, int dimenSix, int dimenSeven,
                 int dimenEight, QString color, int width, QString style, QString capStyle, QString joinStyle,
                 QString brushColor, QString brushStyle)
{
    // Step 1
    // Creating an entry into database
    QSqlQuery qry;
    qry.prepare("insert into shape   (       "
                "id,                         "
                "type,                       "
                "dimenOne,                   "
                "dimenTwo,                   "
                "dimenThree,                 "
                "dimenFour,                  "
                "dimenFive,                  "
                "dimenSix,                   "
                "dimenSeven,                 "
                "dimenEight,                 "
                "color,                      "
                "width,                      "
                "style,                      "
                "capStyle,                   "
                "joinStyle,                  "
                "brushColor,                 "
                "brushStyle)                 "
                "values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);        "
                );
    qry.addBindValue(id);
    qry.addBindValue(type);
    qry.addBindValue(dimenOne);
    qry.addBindValue(dimenTwo);
    qry.addBindValue(dimenThree);
    qry.addBindValue(dimenFour);
    qry.addBindValue(dimenFive);
    qry.addBindValue(dimenSix);
    qry.addBindValue(dimenSeven);
    qry.addBindValue(dimenEight);
    qry.addBindValue(color);
    qry.addBindValue(width);
    qry.addBindValue(style);
    qry.addBindValue(capStyle);
    qry.addBindValue(joinStyle);
    qry.addBindValue(brushColor);
    qry.addBindValue(brushStyle);

    if(!qry.exec())
    {
         qDebug() << "Error adding shape" << endl;
    }
    qry.clear();
}

QVector<QPoint> controller::readPolygonDimen()
{
    QSqlQuery qry;
    int dimenOne;
    int dimenTwo;
    int dimenThree;
    int dimenFour;
    int dimenFive;
    int dimenSix;
    int dimenSeven;
    int dimenEight;

    qry.prepare("select * from shape where type = 'Polygon'");
    if(qry.exec())
    {
        while(qry.next())
        {
            dimenOne = qry.value(2).toInt();
            dimenTwo = qry.value(3).toInt();
            dimenThree = qry.value(4).toInt();
            dimenFour = qry.value(5).toInt();
            dimenFive = qry.value(6).toInt();
            dimenSix = qry.value(7).toInt();
            dimenSeven = qry.value(8).toInt();
            dimenEight = qry.value(9).toInt();

            qDebug() << dimenOne << dimenEight << endl;

        }
    }

    else if(!qry.exec())
    {
         qDebug() << "Error reading polygon dimensions" << endl;
    }
    qry.clear();


    QPoint pOne(dimenOne, dimenTwo);
    QPoint pTwo(dimenThree, dimenFour);
    QPoint pThree(dimenFive, dimenSix);
    QPoint pFour (dimenSeven, dimenEight);

    QVector<QPoint>points(4);
    points[0] = pOne;
    points[1] = pTwo;
    points[2] = pThree;
    points[3] = pFour;

    return points;
}

QVector<QString> controller::readPolygonEnums()
{
    QSqlQuery qry;

    QString color;
    QString width;
    QString style;
    QString capStyle;
    QString joinStyle;
    QString brushColor;
    QString brushStyle;

    qry.prepare("select * from shape where type = 'Polygon'");
    if (qry.exec())
    {
        while(qry.next())
        {
            color = qry.value(10).toString();
            width = qry.value(11).toString();
            style = qry.value(12).toString();
            capStyle = qry.value(13).toString();
            joinStyle = qry.value(14).toString();
            brushColor = qry.value(15).toString();
            brushStyle = qry.value(16).toString();

            qDebug() << color << brushStyle << endl;
        }
    }
    else if(!qry.exec())
    {
         qDebug() << "Error reading Polygon Enums" << endl;
    }

    qry.clear();

     QVector<QString> polygonEnums(7);
     polygonEnums[0] = color;
     polygonEnums[1] = width;
     polygonEnums[2] = style;
     polygonEnums[3] = capStyle;
     polygonEnums[4] = joinStyle;
     polygonEnums[5] = brushColor;
     polygonEnums[6] = brushStyle;

     return polygonEnums;
}

QVector<QPoint> controller::readPolylineDimen()
{
    QSqlQuery qry;
    int dimenOne;
    int dimenTwo;
    int dimenThree;
    int dimenFour;
    int dimenFive;
    int dimenSix;
    int dimenSeven;
    int dimenEight;

    qry.prepare("select * from shape where type = 'Polyline'");
    if(qry.exec())
    {
        while(qry.next())
        {
            dimenOne = qry.value(2).toInt();
            dimenTwo = qry.value(3).toInt();
            dimenThree = qry.value(4).toInt();
            dimenFour = qry.value(5).toInt();
            dimenFive = qry.value(6).toInt();
            dimenSix = qry.value(7).toInt();
            dimenSeven = qry.value(8).toInt();
            dimenEight = qry.value(9).toInt();

            qDebug() << dimenOne << dimenEight << endl;


        }
    }

    else if(!qry.exec())
    {
         qDebug() << "Error reading polyline dimensions" << endl;
    }
    qry.clear();

    QPoint pOne(dimenOne, dimenTwo);
    QPoint pTwo(dimenThree, dimenFour);
    QPoint pThree(dimenFive, dimenSix);
    QPoint pFour (dimenSeven, dimenEight);

    QVector<QPoint>points(4);
    points[0] = pOne;
    points[1] = pTwo;
    points[2] = pThree;
    points[3] = pFour;

    return points;
}

QVector<QString> controller::readPolylineEnums()
{
    QSqlQuery qry;

    QString color;
    QString width;
    QString style;
    QString capStyle;
    QString joinStyle;
    QString brushColor;
    QString brushStyle;

    qry.prepare("select * from shape where type = 'Polyline'");
    if (qry.exec())
    {
        while(qry.next())
        {
            color = qry.value(10).toString();
            width = qry.value(11).toString();
            style = qry.value(12).toString();
            capStyle = qry.value(13).toString();
            joinStyle = qry.value(14).toString();
            brushColor = qry.value(15).toString();
            brushStyle = qry.value(16).toString();

            qDebug() << color << brushStyle << endl;
        }
    }
    else if(!qry.exec())
    {
         qDebug() << "Error reading Polyline Enums" << endl;
    }

    qry.clear();

     QVector<QString> polylinenEnums(7);
     polylinenEnums[0] = color;
     polylinenEnums[1] = width;
     polylinenEnums[2] = style;
     polylinenEnums[3] = capStyle;
     polylinenEnums[4] = joinStyle;
     polylinenEnums[5] = brushColor;
     polylinenEnums[6] = brushStyle;

     return polylinenEnums;
}
QVector<int> controller::readLine()
{
    QSqlQuery qry;
    int dimenOne;
    int dimenTwo;
    int dimenThree;
    int dimenFour;

    qry.prepare("select * from shape where type = 'Line'");
    if (qry.exec())
    {
        while(qry.next())
        {
            dimenOne = qry.value(2).toInt();
            dimenTwo = qry.value(3).toInt();
            dimenThree = qry.value(4).toInt();
            dimenFour = qry.value(5).toInt();

            qDebug() << dimenOne << dimenFour << endl;
        }
    }
    else if(!qry.exec())
    {
         qDebug() << "Error reading Line dimensions" << endl;
    }
    qry.clear();
    QVector<int> linePoints(4);
    linePoints[0] = dimenOne;
    linePoints[1]= dimenTwo;
    linePoints[2]=dimenThree;
    linePoints[3]=dimenFour;

    return linePoints;
}

QVector<QString> controller::readLineEnums()
{
    QSqlQuery qry;

    QString color;
    QString width;
    QString style;
    QString capStyle;
    QString joinStyle;
    QString brushColor;
    QString brushStyle;

    qry.prepare("select * from shape where type = 'Line'");
    if (qry.exec())
    {
        while(qry.next())
        {
            color = qry.value(10).toString();
            width = qry.value(11).toString();
            style = qry.value(12).toString();
            capStyle = qry.value(13).toString();
            joinStyle = qry.value(14).toString();
            brushColor = qry.value(15).toString();
            brushStyle = qry.value(16).toString();

            qDebug() << color << brushStyle << endl;
        }
    }
    else if(!qry.exec())
    {
         qDebug() << "Error reading Line Enums" << endl;
    }

    qry.clear();

     QVector<QString> lineEnums(7);
     lineEnums[0] = color;
     lineEnums[1] = width;
     lineEnums[2] = style;
     lineEnums[3] = capStyle;
     lineEnums[4] = joinStyle;
     lineEnums[5] = brushColor;
     lineEnums[6] = brushStyle;

     return lineEnums;
}

QVector<int> controller::readRectangle()
{
    QSqlQuery qry;
    int dimenOne;
    int dimenTwo;
    int dimenThree;
    int dimenFour;

    qry.prepare("select * from shape where type = 'Rectangle'");
    if (qry.exec())
    {
        while(qry.next())
        {
            dimenOne = qry.value(2).toInt();
            dimenTwo = qry.value(3).toInt();
            dimenThree = qry.value(4).toInt();
            dimenFour = qry.value(5).toInt();

            qDebug() << dimenOne << dimenFour << endl;
        }
    }
    else if(!qry.exec())
    {
         qDebug() << "Error reading Rectangle dimensions" << endl;
    }
    qry.clear();
    QVector<int> rectanglePoints(4);
    rectanglePoints[0] = dimenOne;
    rectanglePoints[1]= dimenTwo;
    rectanglePoints[2]=dimenThree;
    rectanglePoints[3]=dimenFour;

    return rectanglePoints;
}

QVector<QString> controller::readRectangleEnums()
{
    QSqlQuery qry;

    QString color;
    QString width;
    QString style;
    QString capStyle;
    QString joinStyle;
    QString brushColor;
    QString brushStyle;

    qry.prepare("select * from shape where type = 'Rectangle'");
    if (qry.exec())
    {
        while(qry.next())
        {
            color = qry.value(10).toString();
            width = qry.value(11).toString();
            style = qry.value(12).toString();
            capStyle = qry.value(13).toString();
            joinStyle = qry.value(14).toString();
            brushColor = qry.value(15).toString();
            brushStyle = qry.value(16).toString();

            qDebug() << color << brushStyle << endl;
        }
    }
    else if(!qry.exec())
    {
         qDebug() << "Error reading Rectangle Enums" << endl;
    }

    qry.clear();

     QVector<QString> rectangleEnums(7);
     rectangleEnums[0] = color;
     rectangleEnums[1] = width;
     rectangleEnums[2] = style;
     rectangleEnums[3] = capStyle;
     rectangleEnums[4] = joinStyle;
     rectangleEnums[5] = brushColor;
     rectangleEnums[6] = brushStyle;

     return rectangleEnums;
}

QVector<int> controller::readSquare()
{
    QSqlQuery qry;
    int dimenOne;
    int dimenTwo;
    int dimenThree;

    qry.prepare("select * from shape where type = 'Square'");
    if (qry.exec())
    {
        while(qry.next())
        {
            dimenOne = qry.value(2).toInt();
            dimenTwo = qry.value(3).toInt();
            dimenThree = qry.value(4).toInt();

            qDebug() << dimenOne << dimenThree << endl;
        }
    }
    else if(!qry.exec())
    {
         qDebug() << "Error reading Square dimensions" << endl;
    }
    qry.clear();
    QVector<int> squarePoints(4);
    squarePoints[0] = dimenOne;
    squarePoints[1]= dimenTwo;
    squarePoints[2]=dimenThree;

    return squarePoints;
}

QVector<QString> controller::readSquareEnums()
{
    QSqlQuery qry;

    QString color;
    QString width;
    QString style;
    QString capStyle;
    QString joinStyle;
    QString brushColor;
    QString brushStyle;

    qry.prepare("select * from shape where type = 'Square'");
    if (qry.exec())
    {
        while(qry.next())
        {
            color = qry.value(10).toString();
            width = qry.value(11).toString();
            style = qry.value(12).toString();
            capStyle = qry.value(13).toString();
            joinStyle = qry.value(14).toString();
            brushColor = qry.value(15).toString();
            brushStyle = qry.value(16).toString();

            qDebug() << color << brushStyle << endl;
        }
    }
    else if(!qry.exec())
    {
         qDebug() << "Error reading Square Enums" << endl;
    }

    qry.clear();

     QVector<QString> squareEnums(7);
     squareEnums[0] = color;
     squareEnums[1] = width;
     squareEnums[2] = style;
     squareEnums[3] = capStyle;
     squareEnums[4] = joinStyle;
     squareEnums[5] = brushColor;
     squareEnums[6] = brushStyle;

     return squareEnums;
}
