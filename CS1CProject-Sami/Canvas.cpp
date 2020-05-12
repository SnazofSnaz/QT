#include "Canvas.h"

Canvas::Canvas(QWidget *parent)
        : QWidget(parent)
{
    antialiased = false;
    transformed = false;
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
void Canvas::paintEvent(QPaintEvent * /* event */)
{

}
QSize Canvas::minimumSizeHint() const
{
    return QSize(100, 100);
}
QSize Canvas::sizeHint() const
{
    return QSize(400, 200);
}

