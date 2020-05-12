#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include "shape.h"
#include "vector.h"
#include "controller.h"

class Canvas : public QWidget
{
        Q_OBJECT
public:
    Canvas(QWidget *parent = 0);
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void drawCompleteLine();
    void drawCompletePolyline();
    void drawCompletePolygon();
    void drawCompleteSquare();
    void drawCompleteRectangle();
    void drawCompleteEllipse();
    void drawCompleteCircle();
    QString getCombo(QString c);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QString combo;
    bool antialiased;
    bool transformed;
    const QImage target;
    int selected;
    controller *c_controller;
};
#endif // CANVAS_H
