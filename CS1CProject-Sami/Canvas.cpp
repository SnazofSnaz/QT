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

