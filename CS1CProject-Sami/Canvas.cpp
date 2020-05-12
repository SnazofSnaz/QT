#include "Canvas.h"

Canvas::Canvas(QWidget *parent)
        : QWidget(parent)
{
    antialiased = false;
    transformed = false;
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
QString Canvas::getCombo(QString c)
{

}
void Canvas::drawCompleteLine()
{
    QVector<int>lineInts(4);
    lineInts= c_controller->readLine();
    Line testline(this, 1);
    testline.setPoints(lineInts[0],lineInts[1],lineInts[2],lineInts[3]);
    QVector<QString>LineEnums(7);
    LineEnums=c_controller->readLineEnums();
    testline.setPen(LineEnums[0],LineEnums[1].toInt(),LineEnums[2],LineEnums[3],LineEnums[4]);
    testline.draw(0,0);

    double area = testline.area();
    double perimeter = testline.perimeter();
    c_controller->updatePermandArea(area,perimeter,1);
}
void Canvas::drawCompletePolyline()
{
    QVector<QPoint>polyPoints(4);
    polyPoints = c_controller->readPolylineDimen();
    Polyline testPolyLine(this, 2);
    testPolyLine.setPoints(polyPoints);
    QVector<QString>polyLineEnums(7);
    polyLineEnums=c_controller->readPolylineEnums();
    testPolyLine.setPen(polyLineEnums[0],polyLineEnums[1].toInt(),polyLineEnums[2],polyLineEnums[3],polyLineEnums[4]);
    testPolyLine.draw(10,10);

    double area = testPolyLine.area();
    double perimeter = testPolyLine.perimeter();
    c_controller->updatePermandArea(area,perimeter,2);
}
void Canvas::drawCompletePolygon()
{
    QVector<QPoint>polyPoints(4);
    polyPoints = c_controller->readPolygonDimen();
    Polygon testPolygon(this, 3);
    testPolygon.setPoints(polyPoints);
    QVector<QString>polygonEnums(7);
    polygonEnums=c_controller->readPolygonEnums();
    testPolygon.setPen(polygonEnums[0],polygonEnums[1].toInt(),polygonEnums[2],polygonEnums[3],polygonEnums[4]);
    qDebug() << polygonEnums[0] << polygonEnums[1] << polygonEnums[2]<< polygonEnums[3]<< polygonEnums[4]<< polygonEnums[5]<< polygonEnums[6] << endl;
    testPolygon.setBrush(polygonEnums[5],polygonEnums[6]);
    testPolygon.draw(10,10);

    double area = testPolygon.area();
    double perimeter = testPolygon.perimeter();
    c_controller->updatePermandArea(area,perimeter,3);
}
void Canvas::drawCompleteRectangle()
{
    QVector<int>rectInts(4);
    rectInts= c_controller->readRectangle();
    Rectangle testRectangle(this, 4);
    testRectangle.setRectangle(rectInts[0],rectInts[1],rectInts[2],rectInts[3]);
    QVector<QString>rectEnums(7);
    rectEnums=c_controller->readSquareEnums();
    testRectangle.setPen(rectEnums[0],rectEnums[1].toInt(),rectEnums[2],rectEnums[3],rectEnums[4]);
    testRectangle.setBrush(rectEnums[5],rectEnums[6]);
    testRectangle.draw(5,5);

    double area = testRectangle.area();
    double perimeter = testRectangle.perimeter();
    c_controller->updatePermandArea(area,perimeter,4);
}
void Canvas::drawCompleteSquare()
{
    QVector<int>squareInts(4);
    squareInts= c_controller->readSquare();
    Square testSquare(this, 5);
    testSquare.setSquare(squareInts[0],squareInts[1],squareInts[2]);
    QVector<QString>SquareEnums(7);
    SquareEnums=c_controller->readSquareEnums();
    testSquare.setPen(SquareEnums[0],SquareEnums[1].toInt(),SquareEnums[2],SquareEnums[3],SquareEnums[4]);
    testSquare.setBrush(SquareEnums[5],SquareEnums[6]);
    testSquare.draw(0,0);

    double area = testSquare.area();
    double perimeter = testSquare.perimeter();
    c_controller->updatePermandArea(area,perimeter,5);
}
void Canvas::drawCompleteEllipse()
{
    QVector<int>ellipseInts(4);
    ellipseInts= c_controller->readEllipse();
    Ellipse testEllipse(this, 6);
    testEllipse.setEllipse(ellipseInts[0],ellipseInts[1],ellipseInts[2],ellipseInts[3]);
    QVector<QString>ellipseEnums(7);
    ellipseEnums=c_controller->readSquareEnums();
    testEllipse.setPen(ellipseEnums[0],ellipseEnums[1].toInt(),ellipseEnums[2],ellipseEnums[3],ellipseEnums[4]);
    testEllipse.setBrush(ellipseEnums[5],ellipseEnums[6]);
    testEllipse.draw(0,0);

    double area = testEllipse.area();
    double perimeter = testEllipse.perimeter();
    c_controller->updatePermandArea(area,perimeter,6);
}
void Canvas::drawCompleteCircle()
{
    QVector<int>circleInts(4);
    circleInts= c_controller->readCircle();
    Circle testCircle(this, 7);
    testCircle.setCircle(circleInts[0],circleInts[1],circleInts[2]);
    QVector<QString>circleEnums(7);
    circleEnums=c_controller->readCircleEnums();
    testCircle.setPen(circleEnums[0],circleEnums[1].toInt(),circleEnums[2],circleEnums[3],circleEnums[4]);
    testCircle.setBrush(circleEnums[5],circleEnums[6]);
    testCircle.draw(0,0);

    double area = testCircle.area();
    double perimeter = testCircle.perimeter();
    c_controller->updatePermandArea(area,perimeter,7);
}
void Canvas::paintEvent(QPaintEvent * /* event */)
{
    drawCompleteLine();
    drawCompletePolyline();
    drawCompletePolygon();
    drawCompleteRectangle();
    drawCompleteSquare();
    drawCompleteEllipse();
    drawCompleteCircle();
}
QSize Canvas::minimumSizeHint() const
{
    return QSize(100, 100);
}
QSize Canvas::sizeHint() const
{
    return QSize(400, 200);
}

