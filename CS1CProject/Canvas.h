#ifndef CANVAS_H
#define CANVAS_H

#include "Storage.h"
#include <QWidget>
#include "shape.h"

class Canvas : public QWidget
{
        Q_OBJECT
public:
    explicit Canvas(QWidget *parent =nullptr);

    void set_storage(const vector_t* vec);

signals:

public slots:
    void setSelected(int);

protected:
    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

private:
    const vector_t* shapes;
    const QImage target;
    int selected;
};
#endif // CANVAS_H
