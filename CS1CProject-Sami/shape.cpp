#include "shape.h"

// SHAPE ------------------------------------------------------

Shape::Shape(QPaintDevice* device, int shapeId, shapeType shape) : painter{device}, shapeId{shapeId}, shape{shape} {
    pen.setStyle(Qt::NoPen);
    brush.setStyle(Qt::NoBrush);
}

void Shape::setShape(shapeType shape){
    this->shape = shape;
}

void Shape::setPen(QString color, int width, QString penStyle, QString capStyle, QString joinStyle){
    pen.setColor(color);
    pen.setWidth(width);
    pen.setStyle(stringToPen(penStyle));
    pen.setCapStyle(stringToCap(capStyle));
    pen.setJoinStyle(stringToJoin(joinStyle));
}

void Shape::setBrush(QString color, QString brushStyle){
    brush.setColor(color);
    brush.setStyle(stringToBrush(brushStyle));
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

void Line::setDefault(){
    start = QPoint(0, 0);
    end = QPoint(0, 0);
}

void Line::setPoints(const int startX, const int startY, const int endX, const int endY){
    start = QPoint(startX, startY);
    end = QPoint(endX, endY);
}

void Line::draw(const int x, const int y){
    getPainter().setPen(getPen());
    getPainter().setBrush(getBrush());
    getPainter().save();
    getPainter().translate(x, y);
    getPainter().drawLine(start, end);
    getPainter().restore();
    getPainter().drawText(start.x(), start.y(), QString("ID: " + QString::number(shapeId)));
}

double Line::area(){
    return 0;
}

double Line::perimeter(){
    return 0;
}

// POLYLINE ---------------------------------------------------

void Polyline::setDefault(){
    points.push_back(QPoint(0,0));
}

void Polyline::setPoints(const QVector<QPoint> points){
    this->points = points;
}

void Polyline::draw(const int x, const int y){
    getPainter().setPen(getPen());
    getPainter().setBrush(getBrush());
    getPainter().save();
    getPainter().translate(x, y);
    getPainter().drawPolyline(&points.first(), points.size());
    getPainter().restore();
    getPainter().drawText(points[0].x(), points[0].y()+50, QString("ID: " + QString::number(shapeId)));
}

double Polyline::area(){
    return 0;
}

double Polyline::perimeter(){
    return 0;
}

// POLYGON ----------------------------------------------------

void Polygon::setDefault(){
    points.push_back(QPoint(0,0));
}

void Polygon::setPoints(const QVector<QPoint> points){
    this->points = points;
}

void Polygon::draw(const int x, const int y){
    getPainter().setPen(getPen());
    getPainter().setBrush(getBrush());
    getPainter().save();
    getPainter().translate(x, y);
    getPainter().drawConvexPolygon(&points.first(),points.size());
    getPainter().restore();
    getPainter().drawText(points[0].x(), points[0].y()+50, QString("ID: " + QString::number(shapeId)));
}

double Polygon::area(){
    double sum = 0;
    for(int i = 0; i <= points.size()-1; i++){
        if(i == points.size()-1){
            sum += (points[i].x() * points[0].y()) - (points[0].x() * points[i].y());
            break;
        }
        sum += (points[i].x() * points[i+1].y()) - (points[i+1].x() * points[i].y());
    }
    return (sum/2);
}

double Polygon::perimeter(){
    double sum = 0;
    for(int i = 0; i <= points.size()-1; i++){
        if(i == points.size()-1){
            sum += sqrt(pow(points[i].x() - points[0].x(), 2) + pow(points[i].y() - points[0].y(), 2));
            break;
        }
        sum += sqrt(pow(points[i].x() - points[i+1].x(), 2) + pow(points[i].y() - points[i+1].y(), 2));
    }
    return sum;
}

// RECTANGLE --------------------------------------------------------
void Rectangle::setDefault(){
    rectangle.setRect(0, 0, 0, 0);
}

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
    getPainter().drawText(rectangle.x(), rectangle.y() + 10, QString("ID: " + QString::number(shapeId)));
}

double Rectangle::area(){
    return rectangle.width() * rectangle.height();
}

double Rectangle::perimeter(){
    return (2 * rectangle.width()) + (2 * rectangle.height());
}

// SQUARE -----------------------------------------------------------
void Square::setDefault(){
    rectangle.setRect(0, 0, 0, 0);
}

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
    getPainter().drawText(rectangle.x(), rectangle.y() + 10, QString("ID: " + QString::number(shapeId)));
}

double Square::area(){
    return pow(rectangle.width(), 2);
}

double Square::perimeter(){
    return 4 * rectangle.width();
}

// ELLIPSE ----------------------------------------------------------
void Ellipse::setDefault(){
    rectangle.setRect(0, 0, 0, 0);
}

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
    getPainter().drawText(rectangle.x(), rectangle.y() + 10, QString("ID: " + QString::number(shapeId)));
}

double Ellipse::area(){
   return M_PI * ((rectangle.width()/2) * (rectangle.height()/2));
}

double Ellipse::perimeter(){
    return 2 * M_PI * sqrt((pow(rectangle.width()/2, 2) + pow(rectangle.height()/2, 2)) / 2);
}

// CIRCLE ------------------------------------------------------------
void Circle::setDefault(){
    rectangle.setRect(0, 0, 0, 0);
}

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
    getPainter().drawText(rectangle.x(), rectangle.y() + 10, QString("ID: " + QString::number(shapeId)));
}

double Circle::area(){
    return M_PI * pow(rectangle.width()/2, 2);
}

double Circle::perimeter(){
    return 2 * (M_PI * rectangle.width()/2);
}

// TEXT ----------------------------------------------------------------
void Text::setDefault(){
    rectangle.setRect(0, 0, 0, 0);
    textString = " ";
}

void Text::setBoundingBox(const int x, const int y, const int length, const int width){
    rectangle.setRect(x, y, length, width);
}

void Text::setText(const QString& textString){
    this->textString = textString;
}

void Text::setTextColor(QString color){
    this->textColor = color;
}

void Text::setTextFlags(QString flag){
    this->textFlag = stringToTextFlag(flag);
}

void Text::setFont(const QString &textFontFamily, QString style, QString weight, int textSize){
    font.setFamily(textFontFamily);
    font.setStyle(stringToStyle(style));
    font.setWeight(stringToWeight(weight));
    font.setPointSize(textSize);
}

void Text::draw(const int x, const int y){
    getPainter().setPen(textColor);
    getPainter().save();
    getPainter().translate(x, y);
    getPainter().drawText(rectangle, textFlag, textString);
    getPainter().restore();
    getPainter().drawText(rectangle.x(), rectangle.y() + 10, QString("ID: " + QString::number(shapeId)));
}

double Text::area(){
    return 0;
}

double Text::perimeter(){
    return 0;
}

//HELPER FUNC ---------------------------------------------------
Qt::PenStyle stringToPen(QString string){
    if(string == "SolidLine")
        return Qt::SolidLine;
    else if(string == "DashLine")
        return Qt::DashLine;
    else if(string == "DotLine")
        return Qt::DotLine;
    else if(string == "DashDotLine")
        return Qt::DashDotLine;
    else if(string == "DashDotDotLine")
        return Qt::DashDotDotLine;
    else if(string == "CustomDashLine")
        return Qt::CustomDashLine;
    else
        return Qt::NoPen;
}

Qt::PenCapStyle stringToCap(QString string){
    if(string == "FlatCap")
        return Qt::FlatCap;
    else if(string == "SquareCap")
        return Qt::SquareCap;
    else
        return Qt::RoundCap;
}

Qt::PenJoinStyle stringToJoin(QString string){
    if(string == "MiterJoin")
        return Qt::MiterJoin;
    else if(string == "BevelJoin")
        return Qt::BevelJoin;
    else
        return Qt::RoundJoin;
}

Qt::BrushStyle stringToBrush(QString string){
    if(string == "SolidPattern")
        return Qt::SolidPattern;
    else if(string == "HorPattern")
        return Qt::HorPattern;
    else if(string == "VerPattern")
        return Qt::VerPattern;
    else
        return Qt::NoBrush;
}

QFont::Style stringToStyle(QString string){
    if(string == "StyleNormal")
        return QFont::StyleNormal;
    else if(string == "StyleItalic")
        return QFont::StyleItalic;
    else
        return QFont::StyleOblique;
}

QFont::Weight stringToWeight(QString string){
    if(string == "Thin")
        return QFont::Thin;
    else if(string == "Light")
        return QFont::Light;
    else if(string == "Normal")
        return QFont::Normal;
    else
        return QFont::Bold;
}

Qt::AlignmentFlag stringToTextFlag(QString string){
    if(string == "AlignLeft")
        return Qt::AlignLeft;
    else if(string == "AlignRight")
        return Qt::AlignRight;
    else if(string == "AlignTop")
        return Qt::AlignTop;
    else if(string == "AlignBottom")
        return Qt::AlignBottom;
    else
        return Qt::AlignCenter;
}
