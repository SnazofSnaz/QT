#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include "shape.h"
#include "vector.h"
#include "controller.h"
#include "globals.h"


class Canvas : public QWidget
{
        Q_OBJECT
public:

    enum Shapes {line, polyline, polygon, rect, square, ellipse, circle, text, all};


    Canvas(QWidget *parent = nullptr);
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void drawCompleteLine(bool d);
    void drawCompletePolyline(bool d);
    void drawCompletePolygon(bool d);
    void drawCompleteSquare(bool d);
    void drawCompleteRectangle(bool d);
    void drawCompleteEllipse(bool d);
    void drawCompleteCircle(bool d);
    void renderCompleteText(bool d);
    void renderallObjects(bool d);
    int myType;


public slots:
    void setShape(int MyShape);
    void setAntialiased(bool antialiased);


protected:
    void paintEvent(QPaintEvent *event) override;

private:

    Shapes myShape;
    QString combo;
    bool antialiased;
    bool transformed;
    const QImage target;
    int selected;
    controller *c_controller;
};
#endif // CANVAS_H
