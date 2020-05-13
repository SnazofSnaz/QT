#include "Canvas.h"

Canvas::Canvas(QWidget *parent)
        : QWidget(parent)
{
    antialiased = false;
    transformed = false;
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
void Canvas::setShape(int s)
{
    myInt = s;
    update();

}
void Canvas::drawCompleteLine(bool drawn)
{
     Line testline(this, 1);
    if(drawn == true)
    {
        QVector<int>lineInts(4);
        lineInts= c_controller->readLine();
        testline.setPoints(lineInts[0],lineInts[1],lineInts[2],lineInts[3]);
        QVector<QString>LineEnums(7);
        LineEnums=c_controller->readLineEnums();
        testline.setPen(LineEnums[0],LineEnums[1].toInt(),LineEnums[2],LineEnums[3],LineEnums[4]);
        testline.draw(0,0);

        double area = testline.area();
        double perimeter = testline.perimeter();
        c_controller->updatePermandArea(area,perimeter,1);
    }
    else
    {
        testline.setPen("white",0,"","","");
        testline.setBrush("","");
        testline.draw(0,0);
    }


    //repaint();
}
void Canvas::drawCompletePolyline(bool drawn)
{
    Polyline testPolyLine(this, 2);

    if(drawn == true)
    {
    QVector<QPoint>polyPoints(4);
    polyPoints = c_controller->readPolylineDimen();
    testPolyLine.setPoints(polyPoints);
    QVector<QString>polyLineEnums(7);
    polyLineEnums=c_controller->readPolylineEnums();
    testPolyLine.setPen(polyLineEnums[0],polyLineEnums[1].toInt(),polyLineEnums[2],polyLineEnums[3],polyLineEnums[4]);
    testPolyLine.draw(10,10);

    double area = testPolyLine.area();
    double perimeter = testPolyLine.perimeter();
    c_controller->updatePermandArea(area,perimeter,2);
    }
    else
    {
        testPolyLine.setDefault();
        testPolyLine.setPen("white",0,"","","");
        testPolyLine.setBrush("","");
        testPolyLine.draw(0,0);
    }
}
void Canvas::drawCompletePolygon(bool drawn)
{
    Polygon testPolygon(this, 3);
    if(drawn == true)
    {
    QVector<QPoint>polyPoints(4);
    polyPoints = c_controller->readPolygonDimen();
    testPolygon.setPoints(polyPoints);
    QVector<QString>polygonEnums(7);
    polygonEnums=c_controller->readPolygonEnums();
    testPolygon.setPen(polygonEnums[0],polygonEnums[1].toInt(),polygonEnums[2],polygonEnums[3],polygonEnums[4]);
    testPolygon.setBrush(polygonEnums[5],polygonEnums[6]);
    testPolygon.draw(10,10);

    double area = testPolygon.area();
    double perimeter = testPolygon.perimeter();
    c_controller->updatePermandArea(area,perimeter,3);
    }
    else
    {
        testPolygon.setDefault();
        testPolygon.setPen("white",0,"","","");
        testPolygon.setBrush("","");
        testPolygon.draw(0,0);
    }

}
void Canvas::drawCompleteRectangle(bool drawn)
{
    Rectangle testRectangle(this, 4);
    if(drawn == true)
    {
    QVector<int>rectInts(4);
    rectInts= c_controller->readRectangle();
    testRectangle.setRectangle(rectInts[0],rectInts[1],rectInts[2],rectInts[3]);
    QVector<QString>rectEnums(7);
    rectEnums=c_controller->readRectangleEnums();
    testRectangle.setPen(rectEnums[0],rectEnums[1].toInt(),rectEnums[2],rectEnums[3],rectEnums[4]);
    testRectangle.setBrush(rectEnums[5],rectEnums[6]);
    testRectangle.draw(5,5);

    double area = testRectangle.area();
    double perimeter = testRectangle.perimeter();
    c_controller->updatePermandArea(area,perimeter,4);
    }
    else
    {
        testRectangle.setPen("white",0,"","","");
        testRectangle.setBrush("","");
        testRectangle.draw(0,0);
    }
}
void Canvas::drawCompleteSquare(bool drawn)
{
    Square testSquare(this, 5);
    if(drawn == true)
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
    else
    {
        testSquare.setPen("white",0,"","","");
        testSquare.setBrush("","");
        testSquare.draw(0,0);
    }
}
void Canvas::drawCompleteEllipse(bool drawn)
{

    Ellipse testEllipse(this, 6);
    if(drawn == true)
    {
    QVector<int>ellipseInts(4);
    ellipseInts= c_controller->readEllipse();
    testEllipse.setEllipse(ellipseInts[0],ellipseInts[1],ellipseInts[2],ellipseInts[3]);
    QVector<QString>ellipseEnums(7);
    ellipseEnums=c_controller->readEllipseEnums();
    testEllipse.setPen(ellipseEnums[0],ellipseEnums[1].toInt(),ellipseEnums[2],ellipseEnums[3],ellipseEnums[4]);
    testEllipse.setBrush(ellipseEnums[5],ellipseEnums[6]);
    testEllipse.draw(0,0);

    double area = testEllipse.area();
    double perimeter = testEllipse.perimeter();
    c_controller->updatePermandArea(area,perimeter,6);
    }
    else
    {
        testEllipse.setPen("white",0,"","","");
        testEllipse.setBrush("","");
        testEllipse.draw(0,0);
    }
}
void Canvas::drawCompleteCircle(bool drawn)
{
    Circle testCircle(this, 7);
    if(drawn == true)
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
    else
    {
        testCircle.setPen("white",0,"","","");
        testCircle.setBrush("","");
        testCircle.draw(0,0);
    }
}

void Canvas::renderCompleteText(bool drawn)
{
    Text testText(this, 8);
    if(drawn == true)
    {
    QVector<int>textInts(4);
    textInts= c_controller->readText();
    testText.setBoundingBox(textInts[0],textInts[1],textInts[2],textInts[3]);
    QVector<QString>textEnums(7);
    textEnums=c_controller->readTextEnums();
    testText.setTextColor(textEnums[1]);
    testText.setText(textEnums[0]);
    testText.setTextFlags(textEnums[2]);
    testText.setFont(textEnums[4],textEnums[5],textEnums[6],textEnums[3].toInt());
    testText.draw(0,0);
    }
    else
    {
        testText.setText("");
        testText.setPen("white",0,"","","");
        testText.draw(0,0);
    }
}
void Canvas::renderallObjects(bool d)
{
    if(d == true)
    {
        drawCompleteLine(true);
        drawCompleteCircle(true);
        drawCompleteSquare(true);
        drawCompleteEllipse(true);
        drawCompletePolygon(true);
        drawCompletePolyline(true);
        drawCompleteRectangle(true);
        renderCompleteText(true);
    }
}
void Canvas::paintEvent(QPaintEvent * /* event */)
{
 //   qDebug() << "qpaint event called" <<myInt;
    static QPoint offset{target.size().width()/2, target.size().height()/2};
    QPainter painter(this);
//    qDebug() << isDrawn[6];
    if (antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);
    update();

        drawCompleteLine(isDrawn[0]);
        drawCompletePolyline(isDrawn[1]);
        drawCompletePolygon(isDrawn[2]);
        drawCompleteSquare(isDrawn[3]);
        drawCompleteRectangle(isDrawn[4]);
        drawCompleteEllipse(isDrawn[5]);
        drawCompleteCircle(isDrawn[6]);
        renderCompleteText(isDrawn[7]);
        renderallObjects(isDrawn[8]);

    update();
   // painter.restore();
}
QSize Canvas::minimumSizeHint() const
{
    return QSize(100, 100);
}
QSize Canvas::sizeHint() const
{
    return QSize(400, 200);
}
void Canvas::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}


