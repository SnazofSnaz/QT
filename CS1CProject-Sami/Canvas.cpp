#include "Canvas.h"

Canvas::Canvas(QWidget *parent)
        : QWidget(parent)
{
    antialiased = false;
    transformed = false;
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
void Canvas::drawCompleteLine()
{
    QVector<int>lineInts(4);
    lineInts= c_controller->readLine();
    Line testline(this, 1);
    testline.setPoints(lineInts[0],lineInts[1],lineInts[2],lineInts[3]);
    testline.setPen(Qt::black,20,Qt::SolidLine,Qt::SquareCap,Qt::MiterJoin);
    testline.draw(0,0);


}
void Canvas::paintEvent(QPaintEvent * /* event */)
{
    drawCompleteLine();
}
QSize Canvas::minimumSizeHint() const
{
    return QSize(100, 100);
}
QSize Canvas::sizeHint() const
{
    return QSize(400, 200);
}

