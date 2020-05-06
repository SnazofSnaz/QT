#include "shape.h"

// SHAPE ------------------------------------------------------

void Shape::setShape(shapeType shape){
    this->shape = shape;
}

void Shape::setPen(Qt::GlobalColor color, int width, Qt::PenStyle penStyle, Qt::PenCapStyle capStyle, Qt::PenJoinStyle joinStyle){
    pen.setColor(color);
    pen.setWidth(width);
    pen.setStyle(penStyle);
    pen.setCapStyle(capStyle);
    pen.setJoinStyle(joinStyle);
}

void Shape::setBrush(Qt::GlobalColor color, Qt::BrushStyle brushStyle){
    brush.setColor(color);
    brush.setStyle(brushStyle);
}

QPainter& Shape::getPainter(){
    return painter;
}

Shape::shapeType Shape::getShape() const{
    return shape;
}

const QPen& Shape::getPen() const{
    return pen;
}

const QBrush& Shape::getBrush() const{
    return brush;
}

// LINE  ------------------------------------------------------

void Line::setPoints(const QPoint &start, const QPoint &end){
    this->start = start;
    this->end = end;
}

void Line::draw(const int x, const int y){
    getPainter().setPen(getPen());
    getPainter().setBrush(getBrush());
    getPainter().save();
    getPainter().translate(x, y);
    getPainter().drawLine(start, end);
    getPainter().restore();
}

// POLYLINE ---------------------------------------------------

void Polyline::setPoints(const QList<QPoint> points){
    this->points = points;
}

void Polyline::draw(const int x, const int y){
    getPainter().setPen(getPen());
    getPainter().setBrush(getBrush());
    getPainter().save();
    getPainter().translate(x, y);
    getPainter().drawPolyline(&points.first(), points.size());
    getPainter().restore();
}

// POLYGON ----------------------------------------------------

void Polygon::setPolygon(const QList<QPoint> points){
    for(QPoint point : points){
        poly << point;
    }
}

void Polygon::draw(const int x, const int y){
    getPainter().setPen(getPen());
    getPainter().setBrush(getBrush());
    getPainter().save();
    getPainter().translate(x, y);
    getPainter().drawPolygon(poly);
    getPainter().restore();
}

double Polygon::area(){
    double sum = 0;
    for(int i = 0; i <= poly.size()-1; i++){
        if(i == poly.size()-1){
            sum += (poly[i].x() * poly[0].y()) - (poly[0].x() * poly[i].y());
            break;
        }
        sum += (poly[i].x() * poly[i+1].y()) - (poly[i+1].x() * poly[i].y());
    }
    return (sum/2);
}

double Polygon::perimeter(){
    double sum = 0;
    for(int i = 0; i <= poly.size()-1; i++){
        if(i == poly.size()-1){
            sum += sqrt(pow(poly[i].x() - poly[0].x(), 2) + pow(poly[i].y() - poly[0].y(), 2));
            break;
        }
        sum += sqrt(pow(poly[i].x() - poly[i+1].x(), 2) + pow(poly[i].y() - poly[i+1].y(), 2));
    }
    return sum;
}

// RECTANGLE --------------------------------------------------------

void Rectangle::setRectangle(const int x, const int y, int length, int width){
    rectangle.setRect(x, y, length, width);
}

void Rectangle::draw(const int x, const int y){
    getPainter().setPen(getPen());
    getPainter().setBrush(getBrush());
    getPainter().save();
    getPainter().translate(x, y);
    getPainter().drawRect(rectangle);
    getPainter().restore();
}

double Rectangle::area(){
    return rectangle.width() * rectangle.height();
}

double Rectangle::perimeter(){
    return (2 * rectangle.width()) + (2 * rectangle.height());
}

// SQUARE -----------------------------------------------------------

void Square::setSquare(const int x, const int y, int length){
    rectangle.setRect(x, y, length, length);
}

void Square::draw(const int x, const int y){
    getPainter().setPen(getPen());
    getPainter().setBrush(getBrush());
    getPainter().save();
    getPainter().translate(x, y);
    getPainter().drawRect(rectangle);
    getPainter().restore();
}

double Square::area(){
    return pow(rectangle.width(), 2);
}

double Square::perimeter(){
    return 4 * rectangle.width();
}

// ELLIPSE ----------------------------------------------------------

void Ellipse::setEllipse(const int x, const int y, int majorAxis, int minorAxis){
    rectangle.setRect(x, y, majorAxis * 2, minorAxis * 2);
}

void Ellipse::draw(const int x, const int y){
    getPainter().setPen(getPen());
    getPainter().setBrush(getBrush());
    getPainter().save();
    getPainter().translate(x, y);
    getPainter().drawEllipse(rectangle);
    getPainter().restore();
}

double Ellipse::area(){
   return M_PI * ((rectangle.width()/2) * (rectangle.height()/2));
}

double Ellipse::perimeter(){
    return 2 * M_PI * sqrt((pow(rectangle.width()/2, 2) + pow(rectangle.height()/2, 2)) / 2);
}

// CIRCLE ------------------------------------------------------------

void Circle::setCircle(const int x, const int y, int radius){
    rectangle.setRect(x, y, radius*2, radius*2);
}

void Circle::draw(const int x, const int y){
    getPainter().setPen(getPen());
    getPainter().setBrush(getBrush());
    getPainter().save();
    getPainter().translate(x, y);
    getPainter().drawEllipse(rectangle);
    getPainter().restore();
}

double Circle::area(){
    return M_PI * pow(rectangle.width()/2, 2);
}

double Circle::perimeter(){
    return 2 * (M_PI * rectangle.width()/2);
}

//-----------------------------------------------------------------------
