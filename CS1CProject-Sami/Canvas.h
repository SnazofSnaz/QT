#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include "shape.h"
#include "vector.h"

class Canvas : public QWidget
{
        Q_OBJECT
public:
    Canvas(QWidget *parent = 0);
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;
private:

    bool antialiased;
    bool transformed;
    const QImage target;
    int selected;
};
#endif // CANVAS_H
