#include "Canvas.h"

void Canvas::setSelected(int i)
{
    selected =i;
    update();
}

void Canvas::paintEvent(QPaintEvent */* event*/)
{
    static QPoint offset{target.size().width()/2, target.size().height()/2};
    if(shapes && shapes->size())
    {
        for(const Shape* shape : *shapes)
        {
            shape->draw(this);
        }
    }
    if(selected >= 0 && selected < shapes->size())
    {
        Shape* s=(*shapes)[selected];
        QPainter paint{this};
        QPen outline;
        outline.setStyle(Qt::DotLine);
        paint.setPen(outline);
        paint.drawRect(s->getRect()marginsAdded(QMargins{2,2,2,2}));
        paint.drawImage(s->getPos() - offset, target);
    }
}

void Canvas::mousePressEvent(QMouseEvent* event)
{
    if(event->button() & Qt::LeftButton)
    {
        dynamic_cast<MainWindow*>(Window())->onCanvasClick(event->x(), event->y());
    }
}
