#ifndef SHAPE_H
#define SHAPE_H

#include<QPainter>
#include<QPen>
#include<QBrush>
#include<QFont>
#include<vector>
#include<cmath>

class Shape
{
public:

    enum class shapeType {nullShape, Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text};

    Shape(QPaintDevice* device = nullptr, int shapeId = -1, shapeType shape = shapeType::nullShape);

    virtual ~Shape() {}

    void setShape(shapeType shape);
    void setPen(QString color, int width, QString penStyle, QString capStyle, QString joinStyle);
    void setBrush(QString color, QString brushStyle);

    shapeType getShape() const;
    const QPen& getPen() const;
    const QBrush& getBrush() const;

    virtual void draw(const int x, const int y) = 0;
    //virtual void move() = 0;
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual void setDefault() = 0;

    bool operator<(const Shape &other){
        return (this->shapeId < other.shapeId);
    }

    bool operator=(const Shape &other){
        return (this->shapeId == other.shapeId);
    }

protected:
    QPainter& getPainter();
    int shapeId;

private:
    QPainter painter; //QPainter object to draw with
    shapeType shape;
    QPen pen;
    QBrush brush;
};

class Line : public Shape {
    QPoint start;
    QPoint end;
public:
    Line(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, shapeType::Line} { }
    ~Line() override {}
    void setDefault() override;
    void draw(const int x, const int y) override;
    void setPoints(const int startX, const int startY, const int endX, const int endY);
    double area() override;
    double perimeter() override;
};

class Polyline : public Shape {
    QVector<QPoint> points;
public:
    Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, shapeType::Polyline} {}
    ~Polyline() override {}
    void setDefault() override;
    void draw(const int x, const int y) override;
    void setPoints(const QVector<QPoint> points);
    double area() override;
    double perimeter() override;
};

class Polygon : public Shape {
    QVector<QPoint> points;
public:
    Polygon(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, shapeType::Line} {}
    ~Polygon() override {}
    void setDefault() override;
    void draw(const int x, const int y) override;
    void setPoints(const QVector<QPoint> points);
    double area() override;
    double perimeter() override;
};

class Rectangle : public Shape {
    QRect rectangle;
public:
    Rectangle(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, shapeType::Rectangle} {}
    ~Rectangle() override {}
    void setDefault() override;
    void draw(const int x, const int y) override;
    void setRectangle(const int x, const int y, const int length, const int width);
    double area() override;
    double perimeter() override;
};

class Square : public Shape {
    QRect rectangle;
public:
    Square(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, shapeType::Square} {}
    ~Square() override {}
    void setDefault() override;
    void draw(const int x, const int y) override;
    void setSquare(const int x, const int y, const int length);
    double area() override;
    double perimeter() override;
};

class Ellipse : public Shape {
    QRect rectangle;
public:
    Ellipse(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, shapeType::Ellipse} {}
    ~Ellipse() override {}
    void setDefault() override;
    void draw(const int x, const int y) override;
    void setEllipse(const int x, const int y, const int majorAxis, const int minorAxis);
    double area() override;
    double perimeter() override;
};

class Circle : public Shape {
    QRect rectangle;
public:
    Circle(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, shapeType::Ellipse} {}
    ~Circle() override {}
    void setDefault() override;
    void setCircle(const int x, const int y, const int radius);
    void draw(const int x, const int y) override;
    double area() override;
    double perimeter() override;
};

class Text : public Shape {
    QRect rectangle;
    QString textString;
    QString textColor;
    Qt::AlignmentFlag textFlag;
    int textPointSize;
    QFont font;
public:
    Text(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, shapeType::Text} {}
    ~Text() override {}
    void setDefault() override;
    void setBoundingBox(const int x, const int y, const int length, const int width);
    void setText(const QString& textString);
    void setTextColor(QString color);
    void setTextFlags(QString flag);
    void setFont(const QString& textFontFamily, QString style, QString weight, const int textSize);
    void draw(const int x, const int y) override;
    double area() override;
    double perimeter() override;
};

Qt::PenStyle stringToPen(QString string);
Qt::PenCapStyle stringToCap(QString string);
Qt::PenJoinStyle stringToJoin(QString string);
Qt::BrushStyle stringToBrush(QString string);
QFont::Style stringToStyle(QString string);
QFont::Weight stringToWeight(QString string);
Qt::AlignmentFlag stringToTextFlag(QString string);

#endif // SHAPE_H
