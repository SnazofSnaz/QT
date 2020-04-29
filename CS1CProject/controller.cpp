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
